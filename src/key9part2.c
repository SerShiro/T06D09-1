#include <stdio.h>

#define LEN 100

int input(int *buff);
void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *resultLength);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *resultLength);
void outputSum(int *resultSum, int resultLengthSum);
void outputSub(int *resultSum, int resultLengthSum);

int main() {
    int buff1[LEN], buff2[LEN], len1 = input(buff1), len2 = input(buff2), resultSum[LEN], resultSub[LEN],
                                resultLengthSum, resultLengthSub;
    if (!(len1 && len2)) {
        printf("n/a");
        return 0;
    }
    sum(buff1, len1, buff2, len2, resultSum, &resultLengthSum);
    sub(buff1, len1, buff2, len2, resultSub, &resultLengthSub);
}

int input(int *buffer) {
    int i = 0;
    float num;
    while (i < LEN) {
        if (scanf("%f", &num) == 1 && num >= 0 && num <= 9 && num == (float)((int)num)) {
            buffer[i] = (int)num;
            i++;
            if (getchar() == '\n') {
                break;
            }
        } else {
            return 0;
        }
    }
    return i;
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *resultLength) {
    int shift = 0;
    int i, j;
    if (len1 >= len2) {
        i = len1 - 1;
        j = len2 - 1;
    } else {
        i = len2 - 1;
        j = len1 - 1;
    }
    while (i >= 0) {
        if (j < 0) {
            result[i + 1] = buff1[i] + shift;
        } else {
            result[i + 1] = buff1[i] + buff2[j] + shift;
        }
        shift = 0;
        if (result[i + 1] > 9) {
            shift = 1;
            result[i + 1] %= 10;
        }
        i--;
        j--;
    }
    if (shift != 0) {
        result[i + 1] = shift;
    }
    *resultLength = len1 + 1;
    outputSum(result, *resultLength);
}

void outputSum(int *resultSum, int resultLengthSum) {
    int zeroInStart = 1;
    for (int i = 0; i < resultLengthSum; i++) {
        if (zeroInStart && resultSum[i] == 0) {
            continue;
        } else {
            zeroInStart = 0;
        }
        printf("%d ", resultSum[i]);
    }
    printf("\n");
}

void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *resultLength) {
    int shift = 0;
    int i, j;
    if (len1 >= len2) {
        i = len1 - 1;
        j = len2 - 1;
        while (i >= 0) {
            if (j < 0) {
                result[i] = buff1[i] - shift;
            } else {
                result[i] = buff1[i] - buff2[j] - shift;
            }
            shift = 0;
            if (result[i] < 0) {
                shift = 1;
                result[i] += 10;
            }
            i--;
            j--;
        }
        *resultLength = len1;
        if (shift != 0) {
            printf("n/a");
        } else {
            outputSub(result, *resultLength);
        }
    } else {
        printf("n/a");
    }
}

void outputSub(int *resultSum, int resultLengthSum) {
    int zeroInStart = 1;
    for (int i = 0; i < resultLengthSum; i++) {
        if (zeroInStart && resultSum[i] == 0) {
            continue;
        } else {
            zeroInStart = 0;
        }
        if (i == resultLengthSum - 1) {
            printf("%d", resultSum[i]);
        } else {
            printf("%d ", resultSum[i]);
        }
    }
}