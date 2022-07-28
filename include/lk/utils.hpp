#pragma once

#include <functional>

// :)

#define fn auto


namespace lk {

// Returns an index sequence of the tuple's size.
template<typename T>
using tuple_index_sequence = std::make_index_sequence<std::tuple_size_v<T>>;


// Returns true if at least one of the arguments is in the range.
template <std::input_iterator I,
          std::sentinel_for<I> S>
[[nodiscard]] constexpr
fn any_in(I first, S last, auto &&...args) -> bool {
    bool res = false;

    for ( ; first != last ; first++ )
        res |= ((*first == args) || ...);

    return res;
}

template <std::ranges::input_range R>
[[nodiscard]] constexpr
fn any_in(R &&rng, auto &&...args) -> bool {
    return any_in(std::cbegin(rng),
                  std::cend(rng),
                  args...);
}

// Returns true if all elements in the range equal one of the arguments.
template <std::input_iterator I,
          std::sentinel_for<I> S>
[[nodiscard]] constexpr
fn only_in(I first, S last, auto &&...args) -> bool {
    bool res = true;

    for ( ; first != last ; first++ )
        res &= ((*first == args) || ...);

    return res;
}

template <std::ranges::input_range R>
[[nodiscard]] constexpr
fn only_in(R &&rng, auto &&...args) -> bool {
    return only_in(std::cbegin(rng),
                   std::cend(rng),
                   args...);
}

}
