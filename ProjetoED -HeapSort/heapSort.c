#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <time.h>


typedef struct {
    int heap_size;
    int cap;
    int *arr;
}heap;

heap* initHeap(int cap) {
    heap *h = malloc(sizeof(heap));
    h->heap_size = 0;
    h->cap = cap;
    h->arr = malloc(h->cap*sizeof(int));
    return h;
}

int left(int i) {
    return (i << 1);
}

int right(int i) {
    return ((i << 1) | 1);
}

int parent(int i) {
    return (i >> 1);
}

void minHeapify(heap *h, int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if ((l < h->heap_size) && (h->arr[l] <= h->arr[smallest])) {
        smallest =  l;
    }
    if ((r < h->heap_size) && (h->arr[r] <= h->arr[smallest]))  {
        smallest = r;
    }
    if (smallest != i) {
        int tmp = h->arr[smallest];
        h->arr[smallest] = h->arr[i];
        h->arr[i] = tmp;
        minHeapify(h, i); 
    }

}

void heapSort(heap *h) { 
    // Build heap (rearrange array) 
    for (int i = ((h->heap_size / 2) - 1); i > 1; i--) 
        minHeapify(h, i); 
  
    // One by one extract an element from heap 
    for (int i = (h->heap_size-1); i >= 0; i--) 
    { 
        // Move current root to end 
        int tmp = h->arr[0];
        h->arr[0] = h->arr[i];
        h->arr[i] = tmp;
        minHeapify(h, 0); 
    } 
}

void insertHeap(heap *h, int i) {
  if (h->heap_size == h->cap) return;
    h->arr[h->heap_size++] = i;
    minHeapify(h, i); 
}

void buildHeap(heap *h, int *arr) {
    int t = (sizeof(arr)/sizeof(int));
    int i;
    for (i = t - 1; i > 1; i--) {
        insertHeap(h ,arr[i]);
    }
}


int main() {
    heap *h = initHeap(20);
    insertHeap(h, 9);
    insertHeap(h, 2);
    insertHeap(h, 3);
    insertHeap(h, 4);
    insertHeap(h, 5);
    insertHeap(h, 6);
    insertHeap(h, 7);
    insertHeap(h, 8);
    insertHeap(h, 9);
    insertHeap(h, 34);
    insertHeap(h, 12);
    insertHeap(h, 14);
    insertHeap(h, 18);
    insertHeap(h, 10);
    insertHeap(h, 100);
    insertHeap(h, 188);
    insertHeap(h, 54);
    insertHeap(h, 32);
    insertHeap(h, 73);
    heapSort(h);

   
    int i;
    for (i = 0; i < h->heap_size; i++) {
      printf("%d\n", h->arr[i]);
    } 

    return 0;
}