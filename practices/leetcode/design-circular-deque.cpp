// Solution 1
class MyCircularDeque {
private:
    int currentSize;
    int size;
    int * arr;
    int head;
    
    int adjust(int i) {
        return (i + size) % size;
    }
    
    int dec(int i) {
        return adjust(i - 1);
    }
    
    int inc(int i) {
        return adjust(i + 1);
    }
    
    int getTail() {
        return adjust(head + currentSize - 1);
    }
    
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        currentSize = 0;
        size = k;
        head = 0;
        arr = new int[k];
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) return false;
        head = dec(head);
        arr[head] = value;
        currentSize++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) return false;
        int tail = getTail();
        tail = inc(tail);
        arr[tail] = value;
        currentSize++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) return false;
        head = inc(head);
        currentSize--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) return false;
        currentSize--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) return -1;
        return arr[head];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) return -1;
        return arr[getTail()];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return currentSize == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size == currentSize;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * bool param_1 = obj.insertFront(value);
 * bool param_2 = obj.insertLast(value);
 * bool param_3 = obj.deleteFront();
 * bool param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * bool param_7 = obj.isEmpty();
 * bool param_8 = obj.isFull();
 */
