/* String Alignment (Edit Distance) problem

Use 1-based for intuition.

We define a set (here is 3) of edit operations that
we can perform on a string:
- Insertion: insert an arbitrary character to the string.
- Deletion: delete a character from the string.
- Substitution: replace a character in the string with another characther.

The Edit Distance states that given 2 strings A and B, find the
minimum number of edit operations to transform A to B.
(Intertion can be interpreted as Deletion)

Let say n = len(A), m = len(B).

We solve this problem using DP.

Let define DP[i][j] = minimum number of operations to transform
A[1..i] to B[1..j].
Result will be: DP[n][m].
- Base case:
    DP[0][j] = j (delete all characters in B[1..j])
    DP[i][0] = i (delete all characters in A[1..i])
- Recurrence relation:
  if (A[i] == A[j])
    DP[i][j] = DP[i-1][j-1]
  else:
    DP[i][j] = min( DP[i-1][j-1] + 1,  (replace A[i] with B[j] or vice versa)
                    DP[i-1][j] + 1,    (delete A[i])
                    DP[i][j-1] + 1,    (delete B[j])

*/
