/* String matching with Finite Automata

Understanding this algorithm is extremely important to
understand the KMP algorithm.

We will use 1-based index.

P = Pattern string of length m
T = Text string of length n
ε = empty string
P and T is constructed from Σ

Main idea:

- Before iterating through T, we are at state 0, meaning
that we are processing ε string.

- When we read to a character T[i] in T, we are processing
T[1..i] string, we want to know the maximum number k
such that:
P[1..k] is a suffix of T[1..i].

    - k is our new state, it means that from an old state,
    we process character T[i] to move to new state.

    - It's easy to see that if k = m, we find an occurrence
    of P in T.

In case k ≠ m (k < m), we are at the new state k, and we
have P[1..k] is suffix of T[1..i]. The question here is
why don't we move to some random state k' < k such that
P[1..k'] is suffix of T[1..i]? Why it has to be the maximum
k? I don't know the answer yet, maybe it just works.

So now when we are about to process the next character T[i+1],
we will find our next maximum k_next such that:
P[1..k_next] is suffix of T[1..i+1]
<=>
P[1..k_next] is suffix of T[1..i]T[i+1]
<=>
P[1..k_next] is suffix of P[1..k]T[i+1]

Wow, this tells us that to process every character T[i] in
T, it's enough to determine the next state by constructing
a string-matching automata on P (That is, from an internal
state k of P, we input some character in Σ (T[i]), and output
the next state k_next).

Definition of string-matching automata on the string pattern P:
- State set: Q(0,1..m):
    - Start state is 0 (processed ε)
    - Accepted state is m (processed P[1..m] = P)
- Transition function 𝛿 lets us know the state transition
for the current state k and receive a character c:
𝛿(k, c) = maximum k_next
          such that P[1..k_next] is suffix of P[1..k]c

Let assume we already built the string-matching automata on P,
the pseudo code of the matching process:

// Θ(n)
FINITE-AUTOMATION-MATCHER(T, 𝛿, m=P.length)
    n = T.length
    k = 0
    for i = 1 to n
        k = 𝛿(k, T[i])
        if k == m
            P occurs in T at i - m + 1

The process of constructing the automata on P is
straight-forward:
 
// O(m^3|Σ|) 
COMPUTE-TRANSITION-FUNCTION(P, Σ)
    m = P.length
    for k = 0 to m
        for each character c in Σ
            k_next = min(m, q + 1)
            while P[..k_next] IS NOT suffix of P[..k]c
                k_next--
            𝛿(k, c) = k_next

The improved version of this is in KMP algorithm.

Follow up problems:
- Construct the automata for 2 pattern P and P' that
determines the occurrences of either of them.
- Given a pattern P containing gap characters, build
a automata that can find all occurrences of P in T
in O(n).

*/