/* Javis's march algorithm

The idea is simple, like Graham'scan algorithm, we start
with the left-most minimum y-coordinator point p0.

Then the next point p1 of the convex hull is the minimum
polar angle point with respect to p0.

Similarly, the next point p2 of the convex hull is the
minimum polar angle point with respect to p1.

To find one point of the convex hull (h points in total),
we iterative through n points of the polygon to find
the minimum polar angle point.

So running time is O(nh)

*/
