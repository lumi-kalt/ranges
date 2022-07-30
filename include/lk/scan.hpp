#pragma once

#include <ranges>
#include <numeric>

namespace lk {

template<std::input_iterator I,
         std::sentinel_for<I> S,
         typename O,
         typename F,
         typename Init = std::iter_reference_t<I>>
requires std::invocable<F&, Init, std::iter_reference_t<I>>
constexpr
auto scan(I first, S last, O out, Init init, F f)
-> decltype(auto) {
    while (first != last) {
        init = std::invoke(f, std::move(init), *first);
        *out++ = init;
        ++first;
	}
}

template<std::ranges::input_range R,
         typename F,
         typename Init = std::ranges::range_reference_t<R>,
         typename O = std::remove_reference_t<R>>
[[nodiscard]] constexpr
auto scan_left(R&& r, Init init, F&& f) {
    scan(std::ranges::begin(r),
         std::ranges::end(r),
         std::ranges::begin(r),
         std::move(init),
         std::forward<F>(f));

    return std::move(r);
}

template<std::ranges::input_range R,
         typename F,
         typename O = std::remove_reference_t<R>>
[[nodiscard]] constexpr
auto scan_left_first(R r, F&& f)
-> decltype(auto) {
    scan(std::begin(r)[1],
         std::end(r),
         std::begin(r)[1],
         0,
         std::forward<F>(f));

    return std::move(r);
}

}
