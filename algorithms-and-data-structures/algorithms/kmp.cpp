/* KMP algorithm for string matching

We will use the figure 32.10 in CLRS, 3rd, p.1004.

We use 1-based index.

Denote:
P[..i] = P[1..i]

In 32.10 (a), we have already matched q = 5 characters
in P, but have a mismatch at P[6] with T[s+6].

In naive matching, we just ignore the information of
these 5 matched characters and increase our counter
by 1.

In KMP, this information is useful. Currently we
have T[s..s+5] = P[..5]. We want to find maximum k < q
such that P[..k] is a suffix of T[s..s+5].
And increase the counter so that P[..k] align with T
like in 32.10 (b). In this case k = 3. (*)

What do we gain from doing this? 2 things:
- The counter is not increased naively any longer (>= 1).
- The more important one: we now can continue comparing
P to T from P[k+1], not neccessary from P[1]. Since P[..k]
is suffix of T[..s+5], we know for sure that P[..k] match
T already, no need to compare them again. That utilizes
the information from 5 prevous mismatches.

Back to (*), we need to find maximum k < q such that:
P[..k] is a suffix of T[s..s+5]
Since T[s..s+5] = P[..q], this is equivalent to:
Finding maximum k < q such that:
P[..k] is a suffix of P[..q]

This tells us that to find P in any text T, it's sufficient
to find this information on P, we defind the Prefix
Function for pattern P:
π[q] = max(k) | k < q, P[..k] is suffix of P[..q]

And the procedure for finding π is straight-forward:

// O(m) in time
COMPUTE-PREFIX-FUNCTION(P)
    m = P.length
    π[1] = 0
    k = 0  // π[previous q]
    for q = 2 to m
        while k > 0 and P[k+1] ≠ P[q]
            k = π[k]
        if P[k+1] == P[q]
            k = k + 1
        π[q] = k
    return π

And the PSEUDO code for matching:

// O(n) in time
KMP-MATCHER(T, P)
    n = T.length
    m = P.length
    π = COMPUTE-PREFIX-FUNCTION(P)
    q = 0  // Number of characters matched
    for i = 1 to n  // Scan T from left to right
        while p > 0 and P[q+1] ≠ T[i]
            q = π[q]  // next character does not match
        if P[q+1] == T[i]
            q = q + 1
        if q == m
            P occurs in T at T[i - m + 1]
            q = π[q]


Running time analysis: CLRS, 3rd, p.1006, 1007.

*/