## Usecases

**Usecase**: A transaction fails. 

Actual behavior: try catch the error, display the error for client.

Expected behavior: Errors will inevitably happen, but many software developers prefer to think only about the happy path rather than the intricacies of error handling. For example, popular object-relational mapping (ORM) frameworks such as Rails’s ActiveRecord and Django don’t retry aborted transactions—the error usually results in an exception bubbling up the stack, so any user input is thrown away and the user gets an error message. **This is a shame, because the whole point of aborts is to enable safe retries**.

Retrying an aborted transaction is a simple and effective error handling mechanism, it is not perfect:
- Only worth retrying the transaction after transient errors (due to deadlocks, isolation violation, temporary network interruption, failover).
- If the transaction actually succeeded, but server failed to acknowledge with client (due to network), transaction could be performed twice => unless there is an application-level deduplication logic.
- If the transaction failed due to overload, retrying makes the problem worse => limit number of retries, use exponential backoff, etc.

**Usecase**: A transaction has the side effect which is to send the email. Retrying the transaction if it failes could trigger the email sending action twice.

Solution: Might want to make sure the transaction + email sending either commit or abort together => 2-phase commit can help.



