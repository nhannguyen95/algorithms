## Data encoding formats

**rolling upgrade**: deploying new code to a few nodes first, if it's running smoothly then gradually integrating to all the nodes.

Programs work with data in at least 2 different formats:
- In memory: data is kept in objects, structs, lists, arrays, hash tables, etc.
- Self-contained sequence of bytes: to write data to a file or to send over the network.

Transition from in-memory to sequence of bytes: **encoding** or **serialization**, the opposite transition is called **decoding**/**deserialization**.

Many programming languages come with built-in support for encoding/decoding:
- Java has `java.io.Serializable`.
- Ruby has `Marshal`.
- Python has `Pickle`.
- etc.

Although convenient, problems with language-specific formats:
- Your program is tied to a particular programming language, since reading data in another language is very difficult.
- Security problem: an arbitrary byte sequence can be decoded into an arbitrary classes.
- Some has bad performance (regarding CPU time for encode/decode process).

The solution is to use standardized encodings that can be read and written by many languages: JSON, XML, CSV. They have some problems too:
- Lots of ambiguity around the encoding: cannot distinguish numbers and strings, integers and floating-point numbers.
- JSON and XML don't have good support for binary strings, work around: encoding the binary data as text using Base64. That works but hacky and cause the increase in data size (by 33%).
- They do not imply data schema, so the encoding/decoding logic is usually hard coded in the application.

Despite these flaws, JSON, XML and CSV are good enough for many purpose. As long as people agree on what the schema/format is.

**Apache Thrift** (Facebook) and **Protocol Buffers** (protobuf) are binary encoding libraries. They require a schema for any data that is encoded. They also come with a code generation tool that takes a schema definition and produces classes that implement the schema in various programming language. Both works by avoiding encoding the field names directly into the byte sequence, but encode the id that is associated of each field (or tag number, that is specified in the schema) instead.

Data schema inevitably need to change over time (**schema evolution**, including adding/removing/updating fields, changing datatype of field). Thrift and Protobuf can handle changes while keeping backward and forward compability.

**Avro** is another binary encoding format and was started in 2009 as a subproject of Hadoop. Avro also uses a schema to specify the structure of data being encoded. The schema has no tag number for each field (like Thrift and Protocol), and the byte sequence simply consists of values concatenated together (even with no specification on data type). This means that byte sequence can only be decoded correctly if the code reading the data is using the _exact same order_ as the code that wrote the data. Question: how does Avro support schema evolution?

When the application wants to encode some data (to write it to a file or to send over network), it uses whatever version of the schema it knows about (the schema may be compiled into the applicaton), this is known as **writer's schema**.

In the opposite, when the application wants to encode the data, it is expecting the data to be in some schema, known as **reader's schema**.

The key idea with Avro is that the writer's schema and the reader's schema don't have to be the same, they only need to be compatible. When the data is decoded, the Avro library resolves the differenes by looking at the writer's schema and the reader's schema side by side and translating the data from the writer's schema into the reader's schema. The Avro specification defines exactly how the resolution works.

Many data systems also implement some kind of proprietary binary encoding for their data. For example, most relational databases have a network protocol over which you can send queries to the database and get back responses. Those protocols are generally specific to a particular database, and the database vendor provides a driver (e.g., using the ODBC or JDBC APIs) that decodes responses from the data‐ base’s network protocol into in-memory data structures.

So, we can see that although textual data formats such as JSON, XML, and CSV are widespread, binary encodings based on schemas are also a viable option.

## Dataflow models

There are many ways data can flow from one process to another:
- Via databases
- Via service calls (REST, RPC)
- Via asynchronous message passing

**Via databases**

The process that write to the database encodes the data, the process that read from the database decodes it.

You can think of storing something in the database as sending a message to your future self.

It's common for several different processes to be accessing a database at the same time, some can run new code, some can run old code (for example in a rolling update). Developers might need to be aware of this and sometimes need to take care at application level.

For database evolution, rewriting (or **migrating**) data into a new schema is certainly possible.

**Via services: REST and RPC**

The most common arrangement of processes' communication over a network is have 2 roles: clients and servers.

Enterprise JavaBeans, Java's RMI, DCOM, CORBA are based on the idea a remote procedure call (RPC). RPC model tries to make a request to a remote network service look the same as calling a function or method in your programming language, within the same process. RPC is fundementally flawed since a local function call is predictable (either succeed for fails) while a net work request is not, also it takes longer time to execute; also due to parameter serialization for non-primitive data type, etc.

Despite those problems, RPC isn't going away. Various RPC frameworks have been built on top of all the mentioned encodings, e.g. Thrift and Avro come with RPC support included, etc.

Custom RPC protocols with a binary encoding format can achieve better performance than something generic like JSON over REST. however, RESTful APIs have other significant advantanges:
- good for experimentation and coding (just use curl or web browser, no extra software installation).
- supported by all main-stream languages and platforms.
- vast ecosystem of tools available.

That's the reason REST seems to be the predominant style for public APIs.

There is no agreement on how API versioning should work. For RESTful APIs, common approaches are to use a version number in the URL or in the HTTP Accept header.

**Message-Passing Dataflow**

_Asynchronous message-passing_ is one of ways encoded data flows from one process to another, which is somewhere between RPC and databases:
- RPC: client's request (message) is delivered to another process with low latency.
- Databases: messages are not sent via a direct-network connection, but via an intermediary called message broker, which stores the messages temporarily.

Advantages of using a message broker:
- it acts as a buffer if the receiver is unavailable or overloaded.
- automatically redeliver the message if the receiver is crashed.
- decouple sender and receiver.
- allows one message to be sent to multiple receivers.

Message broker examples: RabbitMQ, Apache Kafka.


