/*  Floyd algorithm for finding all pairs shortest paths.

The algorithm is tested at:
http://vn.spoj.com/problems/FLOYD/

We assume for now that the graph may contain negative-weight
edges, but not negative-weight cycles.

DP idea/Optimal substructure: sub paths of a shortest path
are also shortest paths.

Let denote c_ij(k) = weight of shortest path from i to j
whose intermediate vertices are drawn from {1,..,k}.

Case 1: i --> k not in intermediate vertices --> j
c_ij(k) = c_ij(k-1) (1)

Case 2: i --> k in intermediate vertices --> j
c_ij(k) = c_ik(k-1) + c_kj(k-1) (k-1 since k is already used) (2)

So: c_ij(k) = min ( (1), (2) )

Result: c_ij(n)

Init: c_ij(0) = weight matrix W

We don't need to use temp matrix in the for loops since
we can prove that c_ij(k) never steps on c_i'j'(k)
(with (i', j') is iterated before (i, j)).

Time complexity: O(V^3)

--------------------------------------------------------

So now assume the graph G may contain negative-weight
cycles.

Problem: Using Floyd(-Warshall) algorithm to detect the
presence of negative-weight cycles.

Initially, C[i, i] = 0 indicates that we just discover
only 1 obvious path to go from i to i, that is i --> i,
and the weight of that path is 0.

At the termination of Floyd algorithm, C[i, i] is the
minimum weight of the cycle start and end at i.

So if we have some vertice i such that C[i, i] < 0, we
detect a negative-weight cycle.

*/

#include <iostream>
#include <vector>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define pb push_back
#define sz(a) int(a.size())

typedef long long ll;

const int N = 105;
const ll oo = 1e18;
int n, m, k, trace[N][N];
ll c[N][N];

void tracefnc(int u, int v, vector<int> & path) {
    if (u != v) tracefnc(u, trace[u][v], path);
    path.pb(v);
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;

    // floyd init
    FOR(i,1,n) FOR(j,1,n) c[i][j] = oo;
    FOR(i,1,n) c[i][i] = 0;
    FOR(i,1,n) FOR(j,1,n) trace[i][j] = i;

    // edges
    FOR(i,1,m) {
        int u, v;
        cin >> u >> v >> c[u][v];
        c[v][u] = c[u][v];
    }

    // floyd
    FOR(k,1,n)
    FOR(i,1,n)
    FOR(j,1,n)
    if (c[i][k] + c[k][j] < c[i][j]) {
        c[i][j] = c[i][k] + c[k][j];
        trace[i][j] = trace[k][j];
    }

    FOR(i,1,n)
    FOR(j,1,n)
    if (c[i][j] == oo) trace[i][j] = -1;

    // solve queries
    while(k--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) cout << c[u][v];
        else {
            if (trace[u][v] == -1) { cout << -1; continue; }

            vector<int> path;
            tracefnc(u, v, path);

            cout << sz(path);
            REP(i,sz(path)) cout << ' ' << path[i];
        }
        if (k) cout << '\n';
    }

    return 0;
}