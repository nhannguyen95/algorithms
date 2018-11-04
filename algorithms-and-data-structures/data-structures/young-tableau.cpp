/* Young Tableau

  Note: Insert or Delete operations don't maintain
  the tableau's completeness (or balance) property.
*/

// ----------------INCLUDE-----------------

#include <iostream>
#include <vector>
#include <climits>
#include <initializer_list>
#include <algorithm>
using namespace std;

// -------------YOUNG TABLEAU--------------

class YoungTableau {
private:
  vector<vector<int>> A;

  int nrows() const { return A.size(); }

  int ncols() const { return A[0].size(); }

  bool valid(int i, int j) const {
    return (0 <= i && i < nrows()) &&
           (0 <= j && j < ncols());
  }

public:
  YoungTableau(int rows, int cols) {
    A.assign(rows, vector<int>());
    for(int i = 0; i < rows; i++)
      A[i].assign(cols, INT_MAX);
  }

  void init(initializer_list<int> l) {
    // Remove old elements
    for(int i = 0; i < nrows(); i++)
      fill(A[i].begin(), A[i].end(), INT_MAX);

    // Insert new elements
    for(int key : l) {
      insert(key);
      cout << *this;
    }
  }

  int get(int i, int j, int defaultMin = 1) const {
    if (!valid(i, j))
      return defaultMin? INT_MIN : INT_MAX;
    return A[i][j];
  }

  void set(int i, int j, int key) {
    if (!valid(i, j)) return;
    A[i][j] = key;
  }

  // SiftUp: O(m+n)
  void insert(int key) {
    if (isFull()) return;
    int i = nrows() - 1;
    int j = ncols() - 1;
    set(i, j, key);
    while((get(i-1,j) > get(i,j)) ||
          (get(i,j-1) > get(i,j))) {
      if (get(i-1,j) > get(i,j-1) /* && i > 0 */) {
        swap(A[i][j], A[i-1][j]);
        i--;
      } else {
        swap(A[i][j], A[i][j-1]);
        j--;
      }
    }
  }

  // SiftDown: O(n+m)
  int extractMin() {
    int mn = get(0, 0);
    int i = 0;
    int j = 0;
    while(get(i+1,j,0) != INT_MAX ||
          get(i,j+1,0) != INT_MAX) {
      if (get(i+1,j,0) < get(i,j+1,0)) {
        swap(A[i+1][j], A[i][j]);
        i++;
      } else {
        swap(A[i][j+1], A[i][j]);
        j++;
      }
    }
    set(i, j, INT_MAX);
    return mn;
  }

  // O(m+n)
  bool search(const int key) const {
    // We can start at bottom left or
    // top right to utilize binary search

    // Start at bottom left:
    int i = nrows() - 1;
    int j = 0;
    while(j < ncols() && i >= 0) {
      if (A[i][j] == key) return true;
      else if (A[i][j] < key) j++;
      else i--;
    }
    return false;
  }

  friend ostream& operator<<(ostream & os, const YoungTableau & t)  {
    for(int i = 0; i < t.nrows(); i++) {
      for(int j = 0; j < t.ncols(); j++) {
        int v = t.get(i,j);
        if (v == INT_MAX) cout << " oo";
        else if (v == INT_MIN) cout << "-oo";
        else os << v;
        os << ' ';
      }
      os << '\n';
    }
    os << '\n';
    return os;
  }

  bool isFull() {
    return A.back().back() != INT_MAX;
  }

  bool isEmpty() {
    return A[0][0] == INT_MAX;
  }
};

// ----------------------------------------

int main() {
  // 3 rows, 4 columns
  YoungTableau tableau(3, 4);

  // Init
  tableau.init({12,10,8,7,5,5,4,2,2,1});

  // Test search for key
  cout << tableau.search(12) << '\n';  // should be true
  cout << tableau.search(13) << '\n';  // should be false

  // Test extract min
  // Should be 1 2 2 4 5 5 7 8 10 12
  while(!tableau.isEmpty())
    cout << tableau.extractMin() << ' ';

  return 0;
}
