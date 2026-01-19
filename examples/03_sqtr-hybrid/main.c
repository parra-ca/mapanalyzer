#include <stdio.h>
#include <stdlib.h>
#include <maptracer.h>

typedef unsigned char uchar;
void printM(uchar *matrix, size_t n, char *msg){
    if(msg[0] != '\0')
        printf("%s:\n", msg);
    uchar (*mat)[n] = (uchar (*)[n])matrix;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf(" %3d",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return;
}

void transpose_naive(uchar *matrix, int n){
    uchar (*mat)[n] = (uchar (*)[n])matrix;
    uchar temp;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
    return;
}

static inline void swapchar(uchar *A, uchar *B){
    uchar tmp = *A;
    *A = *B;
    *B = tmp;
}

void exchange(uchar *M, size_t n,    // matrix
              size_t iA, size_t jA, // submatrix A
              size_t iB, size_t jB, // submatrix B
              size_t si){           // submatrix sizes
    uchar (*mat)[n] = (uchar (*)[n])M;
    for(size_t i=0; i<si; i++){
        for(size_t j=0; j<si; j++){
            swapchar(&mat[iA+i][jA+j], &mat[iB+i][jB+j]);
        }
    }
}


void tr_submat_direct(uchar *M, size_t n,  //matrix, matrix size
                      size_t I, size_t J, // submatrix coordinates (row,col)
                      size_t si){         // submatrix size
    uchar (*mat)[n] = (uchar (*)[n])M;
    for(size_t i=0; i<si; i++)
        for(size_t j=i+1; j<si; j++)
            swapchar(&mat[I+i][J+j], &mat[I+j][J+i]);
}

size_t size_threshold = 3;

void tr_rec(uchar *M, size_t n,  //matrix, matrix size
            size_t i, size_t j, // submatrix coordinates (row,col)
            size_t si){         // submatrix size
      if(si > size_threshold){// recursion
        size_t h = si / 2; // half rounded down
        size_t H = si - h; // half rounded up
        // | X|
        // |X |
         exchange(M, n, i, j+H, i+H, j, h);
        // | T|
        // |  |
         tr_rec(M, n, i, j+H, h);
        // |  |
        // |T |
         tr_rec(M, n, i+H, j, h);
        // |T |
        // |  |
         tr_rec(M, n, i, j, H);
        // |  |
        // | T|
         tr_rec(M, n, i+h, j+h, H);
        return;
    }

    // base case: direct transposition
     tr_submat_direct(M, n, i, j, si);
 }

void transpose_recur(uchar *matrix, size_t n){
    tr_rec(matrix, n, 0, 0, n);
}


void populateM(uchar *matrix, size_t n){
    uchar (*mat)[n] = (uchar (*)[n])matrix;
    uchar val = 0;
    for(size_t i=0; i<n; i++){
        for(size_t j=0; j<n; j++){
            mat[i][j] = val++;
        }
    }
    return;
}

void checkTransp(uchar *matrix, size_t n){
    uchar (*mat)[n] = (uchar (*)[n])matrix;
    uchar val = 0;
    for(size_t j=0; j<n; j++){
        for(size_t i=0; i<n; i++){
            if(mat[i][j] != val){
                printf("Error: mat[%lu][%lu] != %d\n", j, i, val);
                exit(1);
            }
            val++;
        }
    }
    return;
}

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("USAGE:\n    %s <matrix_size> <threshold>", argv[0]);
        exit(1);
    }
    size_t size = strtol(argv[1], NULL, 10);
    size_threshold = strtol(argv[2], NULL, 10);

    mt_select_next_block();
    uchar *mat = (uchar*)malloc(size*size*sizeof(uchar));
    populateM(mat, size);

    mt_start_tracing();
    transpose_recur(mat, size);
    mt_stop_tracing();

    checkTransp(mat, size);

    free(mat);
    return 0;
}
