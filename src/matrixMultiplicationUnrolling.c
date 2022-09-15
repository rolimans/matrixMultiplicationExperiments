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
            for (int k = 0; k < SIZE; k += 10) {
                C[i * SIZE + j] += A[i * SIZE + k] * B[k * SIZE + j];
                C[i * SIZE + j] += A[i * SIZE + k + 1] * B[(k + 1) * SIZE + j];
                C[i * SIZE + j] += A[i * SIZE + k + 2] * B[(k + 2) * SIZE + j];
                C[i * SIZE + j] += A[i * SIZE + k + 3] * B[(k + 3) * SIZE + j];
                C[i * SIZE + j] += A[i * SIZE + k + 4] * B[(k + 4) * SIZE + j];
                C[i * SIZE + j] += A[i * SIZE + k + 5] * B[(k + 5) * SIZE + j];
                C[i * SIZE + j] += A[i * SIZE + k + 6] * B[(k + 6) * SIZE + j];
                C[i * SIZE + j] += A[i * SIZE + k + 7] * B[(k + 7) * SIZE + j];
                C[i * SIZE + j] += A[i * SIZE + k + 8] * B[(k + 8) * SIZE + j];
                C[i * SIZE + j] += A[i * SIZE + k + 9] * B[(k + 9) * SIZE + j];
            }
        }
    }

    free(A);
    free(B);
    free(C);

    return 0;
}