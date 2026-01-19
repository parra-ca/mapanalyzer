**Matrix Convolution:** Convolution of  large matrix of size `MAT_SIZE` x `MAT_SIZE`, with a small kernel of size `KER_SIZE` x `KER_SIZE`.

``` shell
./convolution <MAT_SIZE> <KER_SIZE>
```

# Legend
Alias Density (AD) shows where and when cache aliasing occurs. Each horizontal rectangle describes one cache-set in the cache; this is the **where**. The degree of load that a cache-set experiences at a given time is denoted by the darkness of the horizontal rectangle at that point of time; this is the **when**.

A plot where all horizontal rectangles are transparent (white) denotes an execution where all sets had the exact same load at all times.

The two numbers at the right show the intensity of aliasing that such set experienced, and the proportion of aliasing that it got during the execution. The second number must add to 100% across all sets. The first number ideally is 0%.

For a thorough explanation, check chapter 3, section 5 of [Claudio Parra's doctoral thesis](https://escholarship.org/uc/item/8402z970).

# Interpretation
Consider a matrix convolution where a 3x3 kernel slides across an input matrix of size NxN.
If the matrix width is equal to (or close to) the cache size divided by its associativity, the cache will experience aliasing during each read of the input matrix.

This example illustrates the aliasing of such a convolution for matrices of sizes ranging from N=13 to N=20, on a C=32 bytes cache with S=4 sets, blocks of B=4 bytes, and associativity A=2 (2-way).

As the size of the input matrix approaches C/A = 16, memory requests become strongly concentrated in "bursts" to a single set rather than evenly distributed across all four sets.

[See the Plots](https://parra-ca.github.io/mapanalyzer/index.html#04_convolution)
