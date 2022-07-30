#pragma once

#include <ranges>
#include <numeric>

namespace lk {

template<std::input_iterator I,
         std::sentinel_for<I> S,
         typename F,
         typename Init = std::iter_reference_t<I>>
requires std::invocable<F&, Init, std::iter_reference_t<I>>
[[nodiscard]] constexpr
auto scan(I first, S last, Init init, F f)
-> decltype(auto) {
    std::partial_sum(first, last, &init);
}

}
