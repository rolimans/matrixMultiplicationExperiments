#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    const int SIZE = argc > 1 ? atoi(argv[1]) : 1000;

    int *A = (int *)malloc(SIZE * SIZE * sizeof(int));
    int *B = (int *)malloc(SIZE * SIZE * sizeof(int));
    int *C = (int *)calloc(SIZE * SIZE, sizeof(int));

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            A[i * SIZE + j] = 1;
            B[i * SIZE + j] = 1;
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                C[i * SIZE + j] += A[i * SIZE + k] * B[k * SIZE + j];
            }
        }
    }

    free(A);
    free(B);
    free(C);

    return 0;
}