#include <stdio.h>

int readArr(int* arr) {
    for (int i = 0; i < 10; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            return 0;
        }
    }
    if (getchar() != '\n') {
        return 0;
    }
    return 1;
}

void bubbleSort(int* arr) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArr(int* arr) {
    for (int i = 0; i < 10; i++) {
        if (i == 9) {
            printf("%d", arr[i]);
        } else {
            printf("%d ", arr[i]);
        }
    }
}

int main() {
    int arr[10];
    if (readArr(arr)) {
        bubbleSort(arr);
        printArr(arr);
    } else {
        printf("n/a");
    }
}