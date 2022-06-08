# Range Algorithms

Toy implementations of some C++23 algorithms for ranges.
Currently requires GCC, as Clang's support for views is lacking.
May also work in MSVC.

To compile, run

```bash
mkdir build
cd build
cmake -D CMAKE_CXX_COMPILER=g++ .. && make -j
./ranges
```

\
\

So far, I have implemented:

- fold                - Applies *f* with an accumulator and the current element, for each element in the range.
  - fold_left         - Folds from the first element to the last.
  - fold_right        - Folds from the last element to the first.
  - product           - Multiply all items in the range (requires operator\*).
  - sum               - Sum up all items in the range (requires operator+).
  - min               - Returns the min item in the range.
  - max               - Returns the max item in the range.
  - operator|         - Consume a range, returning the accumulator.

- zip_with            - Applies *f* with each range's element at the current index, returning a new range.
- adjacent            - Returns the range adjacent by N elements.

- view helpers
  - odd_iota          - Generates a range of only odd numbers  [1, +∞)
  - even_iota         - Generates a range of only even numbers [2, +∞)

\
\
@ Lumi Kalt, 2022
