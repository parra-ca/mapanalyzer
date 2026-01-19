**Hybrid Square Matrix Transposition:** Starts transposing a square matrix of side size `MAT_SIZE` recursively until the sub-matrices reaches a minimum size `MIN_SIZE`. At that point, the sub-matrices are transposed using a naive algorithm (swapping `M[i,j]` and `M[j,i]`).

``` shell
./sqtr-hybrid <MAT_SIZE> <MIN_SIZE>
```

# Legend
The green line shows the size of the data structure (the main matrix in this case).
The cyan and red lines indicate the cumulative main memory access, and represent read and write operations respectively.

Horizontal access lines show that the memory operations (X axis) are resolved in cache, while high slopes show heavy main memory access.

# Interpretation
This example shows the Cumulative Main Memory Access (CMMA) metric of the hybrid transposition of an 80x80 matrix, where the threshold to switch to naive transposition (`MIN_SIZE`) ranges in [`1` (fully recursive), `5`, `10`, `20`, `40`, `80` (fully naive)].

A "too small" threshold sub-matrix increments the number of memory accesses (X axis). These operations, however, stay in cache. In this particular example, the total read and write accesses to Main Memory remain roughly below 1500 each.
When the minimum sub-matrix does not fit in cache anymore, the number of Main Memory accesses drastically increases (`MIN_SIZE >= 40`). The fully naive case reaching more than double the number of main memory accesses.


[See the Plots](https://parra-ca.github.io/mapanalyzer/index.html#sqtranspose)
