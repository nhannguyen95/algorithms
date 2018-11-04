/* Graham'scan algorithm

This algorithm should be really easy to understand
by looking at the pseudo code and the illustrative
figure 33.7 at CLRS, 3rd, p.1031 and p.1032, 1033.

The main idea is to sort by polar angle in counterclockwise
order around the left-most minimum y-cordinate point,
and then having a stack S maintain the point in the
convex hull.

Notice (this notice may be useful to understand javis's
march algorithm):
- The lowest polar angle w.r.t. p0 and furthest from p0 
is in the convex hull.
- The highest polar angle w.r.t. p0 and furthest from p0
is in the convex hull.
This is proved easily using Proof by contradiction.

*/