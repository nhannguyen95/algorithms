## Problems
- [Find median in a stream](https://leetcode.com/problems/find-median-from-data-stream)
- K-way merge: merge k sorted lists of total n elements into 1 sorted list in O(nlgk)

## Theory

_Note: For simplicity, we use binary max heap for analytics without saying explicitly, min-heap is very similar. And of course the heap tree is always a complete one._

### Sift Up and Sift Down in Heap Implementation

There are 2 important helper functions in heap implementation that one needs to be extremely well aware of (and be careful as well):

  - `siftUp(e)`: Float up the element `e` by comparing its key value to parent in order to maintain heap property.

  - `siftDown(e)`: Float down the element `e` by comparing its key value to children in order to maintain heap property.

By superficially observing, we see that both `siftDown` and `siftUp` have the same time complexity `O(h) = O(lgn)`, and that is true.

But the important thing is if we apply these functions for _every element in the heap_, then `siftDown` is more optimal than `siftUp`, why?:

  - In `siftDown(e)`, the worst case happens when `e` is the root of the heap, and there's only 1 root.

  - In `siftUp(e)`, the worst case happens when `e` is the leaf node, and guess what? there are n/2 leaf nodes!

This affects the time complexity of building max heap function that is about to be mentioned below:

### Sift Up and Sift Down in Building Max Heap

Let's say we are implementing a binary max heap using an array from an array of n input elements.

One approach to build the max heap from these n elements is to insert the n elements one by one into the initially empty heap using `siftUp`:

```
for e in n elements:
  maxHeap.insert(e)  // insert uses siftUp
```

_Why won't we use `siftDown` for inserting? Because the ideal position in a heap tree to insert a new element is at the extreme right position (to maintain the completeness of the tree, not the root). Since this position is at the bottom of the tree, we need to float it up using `siftUp`._

The running time of this is:

```
T(n) = 0*1  insert 1st element, tree height is now is 0, so takes O(1)
     + 1*2  insert next 2 elements, tree height is 1, takes 2*O(1)
     + 2*4  insert next 4 elements, tree height is 2, takes 4*O(2)
     + ...
     + h*n/2  insert the last (n/2) leaf elements, tree height is h = logn
So:
T(n) = sum[h=0..logn]h*2^h = O(nlogn)  # Prove it yourself
```

But there's a faster method: place n elements into the heap tree in arbitrary position, then starting from leaf nodes, call `siftDown` on each element:


```
// Copy n elements to the heap tree, don't care about heap property for now
maxHeap.array = n elements

for i = maxHeap.array.size() / 2 downto 1:
  maxHeap.siftDown(i)
```

The running time of this is:

```
T(n) = n/2*0  insert n/2 leaf nodes at height 0 takes O(1)
     + n/4*1  insert n/4 nodes at height 1 takes n/4*O(1)
     + ...
     + 1*h    insert 1 root node at height h takes O(h)
So:
T(n) = sum[h=0..logn]h*n/2^(h+1) = Θ(n)  # Prove it yourself

At first sight, one could easily derive an asymptotic upper bound of T(n) is O(nlogn)
```

So the latter method is optimal.

### Applying Sift Up and Sift Down

#### Heapsort

In the Heapsort's implementation [here](../algorithms/heap-sort.cpp), the `maxHeapify` function is the `siftDown` one, and it builds the max heap using the 2nd approach, thus takes O(n) time comlexity.

#### Binary Heap implementation

In the Binary Heap implementation [here](binary-heap.cpp):
  - `increaseKey` method behaves like `siftUp`.
  - `heapify` behaves like `siftDown`.

The `siftUp` approach is used to construct the `MaxHeap`, but it can be changed to the `siftDown` approach easily.
