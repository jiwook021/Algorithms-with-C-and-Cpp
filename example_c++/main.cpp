// #include <stdio.h>
// #include <stdlib.h>

// typedef struct {
//     int* data;
//     int size;
//     int capacity;
// } PriorityQueue;

// // Utility functions
// int parent(int i) { return (i - 1) / 2; }
// int left(int i) { return 2 * i + 1; }
// int right(int i) { return 2 * i + 2; }

// void siftUp(PriorityQueue* pq, int i) {
//     while (i > 0 && pq->data[parent(i)] < pq->data[i]) {
//         int temp = pq->data[i];
//         pq->data[i] = pq->data[parent(i)];
//         pq->data[parent(i)] = temp;
//         i = parent(i);
//     }
// }

// void siftDown(PriorityQueue* pq, int i) {
//     int maxIndex = i;
//     int l = left(i);
//     if (l < pq->size && pq->data[l] > pq->data[maxIndex]) {
//         maxIndex = l;
//     }
//     int r = right(i);
//     if (r < pq->size && pq->data[r] > pq->data[maxIndex]) {
//         maxIndex = r;
//     }
//     if (i != maxIndex) {
//         int temp = pq->data[i];
//         pq->data[i] = pq->data[maxIndex];
//         pq->data[maxIndex] = temp;
//         siftDown(pq, maxIndex);
//     }
// }

// PriorityQueue* createPriorityQueue(int initialCapacity) {
//     PriorityQueue* pq = (PriorityQueue*) malloc(sizeof(PriorityQueue));
//     pq->data = (int*) malloc(initialCapacity * sizeof(int));
//     pq->size = 0;
//     pq->capacity = initialCapacity;
//     return pq;
// }

// void push(PriorityQueue* pq, int value) {
//     if (pq->size == pq->capacity) {
//         pq->capacity *= 2;
//         pq->data = (int*) realloc(pq->data, pq->capacity * sizeof(int));
//     }
//     pq->data[pq->size] = value;
//     siftUp(pq, pq->size);
//     pq->size++;
// }

// int pop(PriorityQueue* pq) {
//     if (pq->size == 0) {
//         fprintf(stderr, "Priority queue is empty\n");
//         exit(EXIT_FAILURE);
//     }
//     int result = pq->data[0];
//     pq->size--;
//     pq->data[0] = pq->data[pq->size];
//     siftDown(pq, 0);
//     return result;
// }

// int top(PriorityQueue* pq) {
//     if (pq->size == 0) {
//         fprintf(stderr, "Priority queue is empty\n");
//         exit(EXIT_FAILURE);
//     }
//     return pq->data[0];
// }

// int isEmpty(PriorityQueue* pq) {
//     return pq->size == 0;
// }

// void freePriorityQueue(PriorityQueue* pq) {
//     free(pq->data);
//     free(pq);
// }

// int main() {
//     PriorityQueue* pq = createPriorityQueue(4);

//     push(pq, 3);
//     push(pq, 5);
//     push(pq, 1);
//     push(pq, 4);

//     while (!isEmpty(pq)) {
//         printf("%d ", pop(pq));
//     }

//     freePriorityQueue(pq);

//     return 0;
// }
class ImmutableInt {
private:
    const int value;

public:
    ImmutableInt(int val) : value(val) {}

    ImmutableInt add(int x) const {
        return ImmutableInt(value + x);
    }

    int getValue() const {
        return value;
    }
};

int main()
{// 사용 예시
ImmutableInt obj(10);
ImmutableInt newObj = obj.add(5);
}   