#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

#define EPS 10e-9
#define PI acos(-1.0)

double DEG_to_RAD(double d) { return d * PI / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / PI; }

/* -------------- DATA STRUCTURES -------------- */

// Use `point_i` whenever possible
struct point_i {
  int x, y;
  point_i() { x = y = 0; }
  point_i(int _x, int _y) : x(_x), y(_y) {}
};

// Only use `point` if more precision is needed
struct point {
  double x, y;
  point() { x = y = 0.0; }
  point(double _x, double _y) : x(_x), y(_y) {}
  bool operator < (point other) const {  // useful for sorting
    if (fabs(x - other.x) > EPS)  // if x != other.x
      return x < other.x;
    return y < other.y;
  }
  bool operator == (point other) const {
    return fabs(x - other.x) < EPS && fabs(y - other.y) < EPS;
  }
};

struct line {
  double a, b, c;  // ax + by + c = 0
};

struct vec {
  double x, y;
  vec(double _x, double _y) : x(_x), y(_y) {}
};

/* -------------- OPERATIONS -------------- */

// Euclid distance
double dist(point p1, point p2) {
  return hypot(p1.x - p2.x, p1.y - p2.y);
}

// Rotate p by theta degrees CCW w.r.t origin (0, 0)
// (x, y) = x(1, 0) + y(0, 1)
// (1, 0) rotated by theta -> (cos theta, sin theta)
// (0, 1) rotated by theta -> (-sin theta, cos theta)
// so x(1, 0) + y(0, 1) rotated by theta
// -> (xcos(theta) - ysin(theta), xsin(theta) + ycos(theta))
// (x, y)^T rotated by theta = R * (x, y)^T
// R = cos(theta)  -sin(theta)
//     sin(theta)   cos(theta)
point rotate(point p, double theta) {
  double rad = DEG_to_RAD(theta);
  return point(p.x * cos(rad) - p.y * sin(rad),
               p.x * sin(rad) + p.y * cos(rad));
}

// The answer is store in `l`
void pointsToLine(point p1, point p2, line & l) {
  if (fabs(p1.x - p2.x) < EPS) {
    l.a = 1.0; l.b = 0.0; l.c = -p1.x;
  } else {
    l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
    l.b = 1.0;   // IMPORTANT: we fix the value of b to 1.0, so that all triplets (a, b, c)
                 // that represent the same line are normalize to only 1 triplet (a, 1, c)
    l.c = -(double)(l.a * p1.x) - p1.y;
  }
}

// No need to check ratio a1 / a2 = b1 / b2 since b is normalized to 1.0
bool areParallel(line l1, line l2) {
  return (fabs(l1.a - l2.a) < EPS && fabs(l1.b - l2.b) < EPS);
}

bool areSame(line l1, line l2) {
  return areParallel(l1, l2) && fabs(l1.c - l2.c) < EPS;
}

// Returns true (+ intersection point) if 2 lines are intersect
bool areIntersect(line l1, line l2, point & p) {
  if (areParallel(l1, l2)) return false;
  p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
  if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
  else                  p.y = -(l2.a * p.x + l2.c);
  return true;
}

vec toVec(point a, point b) {
  return vec(b.x - a.x, b.y - a.y);
}

vec scale(vec v, double s) {
  return vec(v.x * s, v.y * s);
}

point translate(point p, vec v) {
  return point(p.x + v.x, p.y + v.y);
}

// Dot product: tích vô hướng
double dot(vec a, vec b) {
  return a.x * b.x + a.y * b.y;
}

// Return ||v||^2
double norm_sq(vec v) {
  return v.x * v.x + v.y * v.y;
}

// Returns the distance from p to the line defined by
// two points a & b (a & b must be different).
// The closest point is stored in the 4-th parameter.
double distToLine(point p, point a, point b, point & c) {
  vec ap = toVec(a, p);
  vec ab = toVec(a, b);
  double k = dot(ab, ap) / norm_sq(ab);
  c = translate(p, scale(ab, k));
  return dist(p, c);
}

// Returns the distance from p to the line segment ab.
double distToLineSegment(point p, point a, point b, point & c) {
  vec ap = toVec(a, p);
  vec ab = toVec(a, b);
  double k = dot(ab, ap) / norm_sq(ab);
  if (k < 0.0) {
    c = point(a.x, a.y);
    return dist(p, a);
  }
  if (k > 1.0) {
    c = point(b.x, b.y);
    return dist(p, b);
  }
  return distToLine(p, a, b, c);
}

// Return angle aob in rad.
// (using dot product formula)
double angle(point a, point o, point b) {
  vec oa = toVec(o, a);
  vec ob = toVec(o, b);
  return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

// Cross product: tích có hướng
double cross(vec a, vec b) {
  return a.x * b.y - b.x * a.y;
}

// Returns true if point r is on the left side of line pq.
bool ccw(point p, point q, point r) {
  return cross(toVec(p, q), toVec(p, r)) > 0;
}

// Returns true if a is counter clockwise from b
bool ccw(vec a, vec b) {
  return cross(a, b) < 0;
}

// Returns:
// - 0: r is collinear with line pq
// - 1: r is on the left of pq
// - -1: r is on the right of pq
int direction(point p, point q, point r) {
  double c = cross(toVec(p, q), toVec(p, r));
  return fabs(c) < EPS ? 0 : c > 0 ? 1 : -1;
}

bool onSegment(point p, point q, point r) {
  return (min(p.x, q.x) <= r.x && r.x <= max(p.x, q.x)) &&
         (min(p.y, q.y) <= r.y && r.y <= max(p.y, q.y));
}

// Returns true if 2 segments intersect
bool areSegmentIntersect(point p1, point p2, point p3, point p4) {
  int d1 = direction(p3, p4, p1);
  int d2 = direction(p3, p4, p2);
  int d3 = direction(p1, p2, p3);
  int d4 = direction(p1, p2, p4);
  if ((d1 * d2 < 0) && (d3 * d4 < 0))
    return true;
  if (d1 == 0 && onSegment(p3, p4, p1))  // p1 is on segment p3p4
    return true;
  if (d2 == 0 && onSegment(p3, p4, p2))
    return true;
  if (d3 == 0 && onSegment(p1, p2, p3))
    return true;
  if (d4 == 0 && onSegment(p1, p2, p4))
    return true;
  return false;
}

// Returns true if point r is on the same line as the line pq.
bool collinear(point p, point q, point r) {
  return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

int insideCircle(point_i p, point_i c, int r) { // all integer version
  int dx = p.x - c.x, dy = p.y - c.y;
  int Euc = dx * dx + dy * dy, rSq = r * r;
  return Euc < rSq ? 0 : Euc == rSq ? 1 : 2;  // inside/boder/outside
}

// Convention of Polygon representation: P.back() == P[0]
bool isConvex(const vector<point> & P) {
  int sz = (int)P.size();
  if (sz <= 3) return false;
  bool isLeft = ccw(P[0], P[1], P[2]);
  for(int i = 1; i < sz-1; i++) {
    if (ccw(P[i], P[i+1], P[(i+2) == sz ? 1 : i+2]) != isLeft)
      return false;  // P is concave
  }
  return true;  // P is convex
}

// Returns convex hull of P
// Graham's scan algorithm

point pivot(0, 0);
bool angleCmp(point a, point b) {
  if (collinear(pivot, a, b))
    return dist(pivot, a) < dist(pivot, b);
  double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
  double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
  return atan2(d1y, d1x) < atan2(d2y, d2x);
}

vector<point> CH(vector<point> P) {
  int n = (int)P.size();
  if (n <= 3) {
    if (!(P[0] == P[n-1])) P.push_back(P[0]);  // just make sure..
    return P;  // corner case: P is the CH itself.
  }

  // First, find P0 = point with lowest Y and if tie: rightmost X
  int P0 = 0;
  for(int i = 1; i < n; i++)
    if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
      P0 = i;

  point temp = P[P0]; P[0] = P[P0]; P[P0] = temp;  // swap P[0] with P[P0]

  // Second, sort points by polar angle w.r.t pivot P0
  pivot = P[0];
  sort(++P.begin(), P.end(), angleCmp);

  // Third, the ccw test
  vector<point> S;
  S.push_back(P[n-1]);  // The point with largest polar angle w.r.t P[0] is also in CH,
  S.push_back(P[0]);    // we push it first to make S[0] = S.back()
  S.push_back(P[1]);
  int i = 2;
  while(i < n) {
    int j = (int)S.size() - 1;
    if (ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]);
    else S.pop_back();
  }
  return S;
}

int main() {
  
  return 0;
}
