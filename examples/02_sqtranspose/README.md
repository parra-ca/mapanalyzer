**Square Matrix Transposition:** Transpose a square matrix using a "naive" or "recursive" approach.

- The naive approach simply exchanges `M[i,j]` and `M[j,i]`.
- The recursive algorithm exchanges the top-right with the bottom-left quarters of the matrix and in the same manner, transpose each quarter.

``` shell
./sqtranspose <matrix_side_size> {"n", "r"}
```

# Legend
The Space Locality Degree (SLD) plot shows how close together **in space** are the memory accesses across the entire **execution time** of the program.

The Time Locality Degree (TLD) plot shows how close together **in time** are the memory accesses across the entire **execution space** of the program.

The Cache Miss Ratio (CMR) is the proportion of memory accesses that result in cache misses.

# Interpretation
**SLD:** In the naive case it is quite low: accesses are scattered all across the memory region. It does get better as the algorithm naturally narrows its access to a progressively smaller region, however, the average SLD is 0.54. On the other hand, the recursive implementation shows a relatively consistent SLD, averaging 0.83.

**TLD:** Both algorithms show similar average TLD, although the recursive implementation has less deviation.

**CMR:** The recursive implementation shows about half of the cache miss ratio exhibited by the naive counterpart.


[See the Plots](https://parra-ca.github.io/mapanalyzer/index.html#sqtranspose)
