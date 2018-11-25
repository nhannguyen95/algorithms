/* 

The most important intuition of swpeeping technique is
the sweeping-line status:
- The status of the sweeping-line at X lets us know
all segments that intersect with X. Why this is important?
Because if 2 segments A and B both intersect with X, 
they maybe in some sense have some relationship. For 
example in this problem, if 2 segments A and B intersect,
there must be exists some sweeping-line X that both
A and B intersect.
- Through the iteration, we can extract all pairs of segment
that are "consecutive" if they appear in some spweeping-line.
This is showed in the code:
    - If we are at sweeping-line whose X = left point of
    some segment, we check 2 segments that are consecutive
    with it: above or below with it in the status.
    - If we are at sweeping-line whose X = right point of
    somw segment, we check 2 segments that are consecutive
    with each other: above AND below.

Notice that this algorithm just checks whether or not there
is an intersection between 2 segments, it can't print out
all intersections. Consider this example:

   \
`   \
  `  \
-------------
     ` \
       `\
         `
          \ `

Suppose 3 segments `, \, - have the same left point,
at the first sweeping-line, the total order is:
\
`
-

And we can detect intersection of ` and -, \ and `.

So one intersection is left out is between \ and -.

The problem comes at the second sweeping-line, when
we pop out the segment \ first, this means every intersection
with the popped segment that haven't been discovered
so far will never be discovered.

The intuition to understand this maybe because the algorithm
only consider consecutive segments.

This algorithms works even when 3 or more segments intersect
at the same point.

This algorithms works even when there exist verticle segments
(we treat left point as bottom point and right point as top point)

The data structure for storing the sweeping-line status can be
a balanced binary search tree. In C/C++ we can use set/map,
refer to the code here, it's pretty concise:
https://sites.google.com/site/indy256/algo_cpp/find_segments_intersection

*/ 
