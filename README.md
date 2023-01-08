# Range Algorithms

Toy implementations of some C++23 (and beyound :rocket:) algorithms for ranges. \
Currently requires GCC, as Clang's support for views is lacking. [Does it work yet?] \
May also work in MSVC.

## Algorithms

### Folds

- fold                - Applies *f* with an accumulator and the current element, for each element in the range.
- fold_left         - Folds from the first element to the last.
- fold_right        - Folds from the last element to the first.
- product           - Multiply all items in the range (requires *operator\**).
- sum               - Sum up all items in the range (requires *operator+*).
- min               - Returns the min item in the range.
- max               - Returns the max item in the range.
- operator|         - Consume a range, returning the accumulator.

### Zips

- zip                 - Creates a range of tuples with each range's element at the current index.
- zip_with          - Applies *f* with each range's element at the current index, returning a new range.
- unzip               - Creates a tuple of the ranges of tuples/pairs passed into it
- adjacent            - Returns the range adjacent by N elements.

### Utilities

- any_in              - Returns true if any of the arguments in in the range
- only_in             - Returns true if the arguments are the only elements in the range
- all_in              - Returns true if all of the arguments are in the range

---
@ Lumi Kalt, 2022
