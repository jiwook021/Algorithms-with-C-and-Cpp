#include <stdio.h>
#include <stdbool.h>

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void dutchNationalFlag(int arr[], int size) {
    int low = 0, mid = 0, high = size - 1;

    while (mid <= high) {
        switch (arr[mid]) {
            // 빨강(0)의 경우
            case 0:
                swap(&arr[low++], &arr[mid++]);
                break;
            // 흰색(1)의 경우
            case 1:
                mid++;
                break;
            // 파랑(2)의 경우
            case 2:
                swap(&arr[mid], &arr[high--]);
                break;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}



void incrementInteger(int* arr, int size) {
    for (int i = size - 1; i >= 0; --i) {
        if (arr[i] < 9) {
            arr[i]++;
            return;
        } else {
            arr[i] = 0;
        }
    }
    // 모든 자릿수가 9인 경우 (예: 999), 배열 크기를 1 늘리고 맨 앞을 1로 설정
    arr[0] = 1;
    arr = realloc(arr, (size + 1) * sizeof(int));
    arr[size] = 0;
}

void incrementArbInteger() {
    int size = 3;
    int* number = (int*)malloc(size * sizeof(int));
    number[0] = 1;
    number[1] = 2;
    number[2] = 9;

    incrementInteger(number, size);

    for (int i = 0; i < size; i++) {
        printf("%d", number[i]);
    }
    printf("\n");

    free(number);
    return 0;
}


int main() {
    // int arr[] = {2, 0, 1, 2, 1, 0};
    // int size = sizeof(arr) / sizeof(arr[0]);

    // dutchNationalFlag(arr, size);
    // printf("정렬된 배열: ");
    // printArray(arr, size);

    incrementArbInteger();
    return 0;
}
