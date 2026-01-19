**Bubble Sort:** Sort a list of numbers using the bubblesort algorithm.

``` shell
./bubblesort <list_size> [rand_seed]
```

If `list_size` is 6, then the array is filled exactly with the values `{1, 6, 3, 2, 4, 5}`.

# Legend
Light red squares represent write access to a particular byte (vertical axis) at a particular time (horizontal axis). Dark red squares are read accesses (atomic read-and-write accesses are registered as write).

Given that this array is of integers (4 bytes each), the rectangles seen are actually 4 squares.

# Interpretation
In the first pass, the algorithm carries the second element (6) and bubble it up until the end. In the second pass, it moves the 3 one position to the right. In the third pass, the algorithm only reads checking that the array is in order.

[See the Plots](https://parra-ca.github.io/mapanalyzer/index.html#01_bubblesort)
