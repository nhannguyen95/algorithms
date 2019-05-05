## SQL Database (relational)
- Some databases: **MySQL, PostgreSQL, SQLite, MariaDB**.
- Common to vertially scale, but it's challenging and time-consuming for horizontal scale.
- Good support for joins.
- Explicit schema: shema-on-write.
- ACID compliant.
- Best suited for complex queries.
- Not suited for hierarchical data storage.
- Prefer to use when:
  - You need to ensure ACID compliance (e-commerce, financial applications).
  - Your application data uses many-to-many relationships.
  - Your application data is structured and unchanging => cost effort for adding new features.

## NoSQL Database (Key-Value, Document, Wide-Column, Graph, etc.)
> Motivations for this approach include:
> - simplicity of design.
> - simpler "horizontal" scaling to clusters of machines (which is a problem for relational databases).
> - and finer control over availability.
> - when all the other components of our application are fast and seamless, NoSQL databases prevent data from being the bottleneck.

- Some databases:
  - Key-Value: **Redis, DynamoDB** (no complex data,no complex queries).
  - Document: **CouchDB, MongoDB**.
- Higher capability of (horizontal) scaling than SQL Databases.
- Poor support for joins, lack of ability to perform ad-hoc joins across tables.
  > Can reduce the needs of joins by denormalizing, but then the application code needs to do additional work.
- Implicit schema: schema-on-read. Items in collections don't all have the same structure.
- Sacrifice ACID for performance and scalability.
- Not so good for complex queries.
- Best suited for hierarchical data storage.
- Prefer to use when:
  - Your application data has little to no/ever-changing structure and experiences massive growth.
  - Your application data has a document-like structure (tree of one-to-many relationships).
  - You want to make the most use of cloud computing and storage (for horizontal scalability).
