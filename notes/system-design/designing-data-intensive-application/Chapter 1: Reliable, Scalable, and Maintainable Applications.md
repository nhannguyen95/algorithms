**Reliability**
The system should continue to work correctly (performing the correct function at the desired level of performance) even in the face of adversity (hardware or soft‐ ware faults, and even human error).

**Scalability**
As the system grows (in data volume, traffic volume, or complexity), there should be reasonable ways of dealing with that growth

**Maintainability**
Over time, many different people will work on the system (engineering and oper‐ ations, both maintaining current behavior and adapting the system to new use cases).

---

What it means for something to be reliable or unreliable?
- Performs the function that the user expected.
- Tolerate the user making mistakes or using the software in unexpected ways.
- Its performance is good enough for the required use case, under the expected load and data volume.
- The system prevents any unauthorized access and abuse.
=> Continuing to work correctly, even when things go wrong.

It is impossible to reduce the probability of a fault to zero; therefore it is usually best to design fault-tolerance mechanisms that prevent faults from causing failures.

---

Load parameters (load factors) can be (depends on the architecture of your system):
- Requests per second (to a webserver).
- The ratio of reads to writes in a database.
- The number of simultaneously active users in a chat room.
- The hit rate on a cache.

---

**Twitter timeline problem**:
- According to data published in November 2012:
  - New tweets (write): 4.6k requests/sec on average, > 12k requests/sec at peak.
  - User can view tweets posted by the people they follow (read): 300k requests/sec.
- Two ways of implementing:
  - A user posts a new tweet, this tweet is insearted to a global collection of tweets (write). When a user requests their home timeline, find all tweets posted by users that he follows, and merge and sort them by time.
  > Downside: the load of home timeline queries is huge!. writes << reads.
  - Having a cache for each user's home timeline (like a mailbox). When a user posts a tweet, insert this tweet to the home timeline caches of all of his followers (write). The request to home (read) is now cheap, because its result has been computed ahead of time.
  > Downside: Posting a tweet now requires a lot of extra work. On avarage, a tweet is sent to about 75 followers, so 4.6 tweets/sec become 4.6 * 75 = 345k writes/sec to homeline caches. Not mention to the fact that the number of followers per user varies widely, and some users have over 30 million followers. This means 1 new tweets may result in 30M writes to homeline!
 - Twitter is now moving to a hybrid of both approaches. Less follower: use 1st approach, many followers: use 2nd approach (the result is merged with the homeline cache).
 - The distribution of followers per user is a key load parameter for discussing scalability, since it determines the _fan-out_ load.
 
---

When you increase a load parameter:
- How is the performance of the system affected if you keep the system resource unchanged?
- To keep the performance unchanged, how much do you need to increase the resources?

---

**Latency**: the duration that a request is waiting to be handled (to be processed by the server).

**Response time**: what the clients see, actual time to process the request + network delays + queueing delays etc.

Response time can vary a lot even if you issue the same request, so think of it as a distribution of values rather than a single one.

