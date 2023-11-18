#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100  // define maximum size for the array
typedef struct {
    int data[MAX_SIZE];
    int size;
} PriorityQueue;

// Utility functions
int parent(int i) { return (i - 1) / 2; }
int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }

void siftUp(PriorityQueue* pq, int i) {
    while (i > 0 && pq->data[parent(i)] < pq->data[i]) {
        int temp = pq->data[i];
        pq->data[i] = pq->data[parent(i)];
        pq->data[parent(i)] = temp;
        i = parent(i);
    }
}

void siftDown(PriorityQueue* pq, int i) {
    int maxIndex = i;
    int l = left(i);
    if (l < pq->size && pq->data[l] > pq->data[maxIndex]) {
        maxIndex = l;
    }
    int r = right(i);
    if (r < pq->size && pq->data[r] > pq->data[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        int temp = pq->data[i];
        pq->data[i] = pq->data[maxIndex];
        pq->data[maxIndex] = temp;
        siftDown(pq, maxIndex);
    }
}

void initializePriorityQueue(PriorityQueue* pq) {
    pq->size = 0;
}

void push(PriorityQueue* pq, int value) {
    if (pq->size == MAX_SIZE) {
        fprintf(stderr, "Priority queue is full\n");
        exit(EXIT_FAILURE);
    }
    pq->data[pq->size] = value;
    siftUp(pq, pq->size);
    pq->size++;
}

int pop(PriorityQueue* pq) {
    if (pq->size == 0) {
        fprintf(stderr, "Priority queue is empty\n");
        exit(EXIT_FAILURE);
    }
    int result = pq->data[0];
    pq->size--;
    pq->data[0] = pq->data[pq->size];
    siftDown(pq, 0);
    return result;
}

int top(PriorityQueue* pq) {
    if (pq->size == 0) {
        fprintf(stderr, "Priority queue is empty\n");
        exit(EXIT_FAILURE);
    }
    return pq->data[0];
}

int isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

int main() {
    PriorityQueue pq;
    initializePriorityQueue(&pq);
    push(&pq, 3);
    push(&pq, 5);
    push(&pq, 1);
    push(&pq, 4);
    while (!isEmpty(&pq)) {
        printf("%d ", pop(&pq));
    }
    return 0;
}