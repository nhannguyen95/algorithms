import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.NoSuchElementException;

import static java.util.Collections.swap;

class PQueue<T> {

    private Comparator<T> comparator;
    private List<T> elements;

    public PQueue(Comparator<T> comparator) {
        this.comparator = comparator;
        this.elements = new ArrayList<>();
    }

    private int parent(int i) {
        return (i - 1) >> 1;
    }

    private int left(int i) {
        return (i << 1) + 1;
    }

    private int right(int i) {
        return (i << 1) + 2;
    }

    private void siftUp(int i) {
        while(i > 0) {
            int p = parent(i);
            if (comparator.compare(elements.get(p), elements.get(i)) > 0) {
                swap(elements, p, i);
                i = p;
            } else {
                return;
            }
        }
    }

    private void siftDown(int i) {
        int pi = -1;
        while(pi != i) {
            int minId = i;
            pi = i;

            int l = left(i);
            if (l < size() && comparator.compare(elements.get(minId), elements.get(l)) > 0) {
                minId = l;
            }

            int r = right(i);
            if (r < size() && comparator.compare(elements.get(minId), elements.get(r)) > 0) {
                minId = r;
            }

            if (minId != i) {
                swap(elements, i, minId);
                i = minId;
            }
        }
    }

    public int size() {
        return this.elements.size();
    }

    public void add(T element) {
        this.elements.add(element);
        siftUp(size() - 1);
    }

    public T element() {
        if (this.elements.isEmpty()) {
            throw new NoSuchElementException();
        }
        return this.elements.get(0);
    }

    public T remove() {
        if (this.elements.isEmpty()) {
            throw new NoSuchElementException();
        }

        T element = element();
        swap(elements, 0, size() - 1);
        this.elements.remove(size() - 1);
        siftDown(0);

        return element;
    }
}

public class Main {
    public static void main(String[] args) {
        PQueue<Integer> minQueue = new PQueue<>((i, j) -> i - j);
        minQueue.add(4);
        minQueue.add(3);
        minQueue.add(2);
        minQueue.add(3);
        minQueue.add(1);
        minQueue.add(5);
        minQueue.add(10);
        minQueue.add(100);
        while(minQueue.size() > 0) {
            System.out.print(minQueue.remove() + " ");
        }

        System.out.println();

        PQueue<Integer> maxQueue = new PQueue<>((i, j) -> j - i);
        maxQueue.add(4);
        maxQueue.add(3);
        maxQueue.add(2);
        maxQueue.add(3);
        maxQueue.add(1);
        maxQueue.add(5);
        maxQueue.add(10);
        maxQueue.add(100);
        while(maxQueue.size() > 0) {
            System.out.print(maxQueue.remove() + " ");
        }
    }
}