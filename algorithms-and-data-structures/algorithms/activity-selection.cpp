/* Activity Selection problem:

Problem statement:
Given a list of n activities with starting time and
ending time s[i], f[i].
Find a maximum-size subset of mutually compatible
activities.

Solution: Greedy
We select an activity (1) that has the earliest ending
time.
Then select the (2) activity which is disjoint with (1)
and has the earliest ending time.
And so on.
We can preprocessing by sorting n activities in increasing
f[i] order.

Proof the Correctness: Cut and Paste technique
Consider nonempty subproblem Sk, let am is the activity
in Sk with earliest ending time. Prove that am is included
in some maximum-size subset of mutually compatible
activities of Sk.

Let Ak be the maximum-size subset of mutually compatible
activitis of Sk and aj is the activity in Ak with earliest
ending time:
- If aj = am, we done.
- If aj # am, we consider the subset Ak - {aj}, am is the
activity in Sk with earliest ending time, we have f[am]
<= f[aj] => we can add am safely into Ak - {aj} such that
am is disjoint with activities in Ak - {aj}. am is now
included in the new optimal subset.

Illustration: Figure 16.1, CLRS 3rd p.420.

Follow up: now we assign each activity with a value v[i],
the goal now is to find a set of disjoint activities
that has the maximum total of values of its activities.
=> Dynamic programming

*/