"""
This is a python implementation of a Heap(Mostly Max Heap)
"""
import math


class Heap:
    def __init__(self, arr=[]):
        self._heap = arr
        self._heap_size = len(arr)
    
    def parent(self, i):
        """
        Find the Parent node of i.
        """
        return math.floor(i / 2)
    
    def left(self, i):
        """
        Find the left child node index.
        """
        return 2*i + 1
    
    def right(self, i):
        """
        Find the left child node index.
        """
        return 2*i + 2

    def heap(self):
        return self._heap

    def size(self):
        return self._heap_size
    
    def print_heap(self):
        print(self._heap)
    
    def max_heapify(self, i):
        """
        Make the heap follow the max heap guidelines. - O(lgn)
        """
        # print(i)
        left_node = self.left(i)
        right_node = self.right(i)
        largest = i
        # print(i, left_node, right_node, flush=True)

        # print(self._heap)
        # print(left_node, i, flush=True)
        if left_node < self._heap_size and self._heap[largest] < self._heap[left_node]:
            # print(self._heap[left_node], self._heap[i])
            largest = left_node

        if right_node < self._heap_size and self._heap[largest] < self._heap[right_node]:
            largest = right_node
        
        if largest != i:
            self._heap[i], self._heap[largest] = self._heap[largest], self._heap[i]
            self.max_heapify(largest)

    def build_max_heap(self):
        """
        Build the max heap from heap - O(n).
        """
        self._heap_size = len(self._heap)
        
        for i in range(math.floor(self._heap_size / 2), -1, -1):
            self.max_heapify(i)
    
    def heap_sort(self):
        """
        Sort the heap in O(nlgn) by building the max heap on the go.
        """
        tmp_size = self._heap_size
        self.build_max_heap()
        for i in range(len(self._heap) - 1, -1, -1):
            self._heap[0], self._heap[i] = self._heap[i], self._heap[0]
            self._heap_size -= 1
            self.max_heapify(0)
        self._heap_size = tmp_size


if __name__ == "__main__":
    test = [4, 1, 3, 2, 16, 9, 10, 14, 8, 7]

    test_heap = Heap(test)
    # test_heap.build_max_heap()
    test_heap.heap_sort()
    print(test)


