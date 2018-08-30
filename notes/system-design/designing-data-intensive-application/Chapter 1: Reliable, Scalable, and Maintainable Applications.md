**Reliability**
The system should continue to work correctly (performing the correct function at the desired level of performance) even in the face of adversity (hardware or soft‐ ware faults, and even human error).

**Scalability**
As the system grows (in data volume, traffic volume, or complexity), there should be reasonable ways of dealing with that growth

**Maintainability**
Over time, many different people will work on the system (engineering and oper‐ ations, both maintaining current behavior and adapting the system to new use cases).

What it means for something to be reliable or unreliable?
- Performs the function that the user expected.
- Tolerate the user making mistakes or using the software in unexpected ways.
- Its performance is good enough for the required use case, under the expected load and data volume.
- The system prevents any unauthorized access and abuse.
=> Continuing to work correctly, even when things go wrong.

It is impossible to reduce the probability of a fault to zero; therefore it is usually best to design fault-tolerance mechanisms that prevent faults from causing failures.

Load parameters (load factors) can be (depends on the architecture of your system):
- Requests per second (to a webserver).
- The ratio of reads to writes in a database.
- The number of simultaneously active users in a chat room.
- The hit rate on a cache.

**Twitter timeline problem**:
- According to data published in November 2012:
  - New tweets: 4.6k/sec on average, > 12k/sec at peak.
  - User can view tweets posted by the people they follow: 300k requests/sec.
- Two ways of implementing:
  - d
