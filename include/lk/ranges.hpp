#pragma once

#include <ranges>
#include <functional>

namespace lk
{
template<std::ranges::random_access_range R1,
         std::ranges::random_access_range R2,
         typename F>
requires std::invocable<F&, std::ranges::range_reference_t<R1>, std::ranges::range_reference_t<R2>>
      && std::ranges::sized_range<R1>
      && std::ranges::sized_range<R2>
[[nodiscard]] constexpr
auto zip_with(R1&& r1, R2&& r2, F&& f)
-> decltype(auto) {
    std::size_t size =
        std::min<std::size_t>(std::ranges::size(r1),
                              std::ranges::size(r2));

    auto r = std::views::iota((std::size_t)0, size)
           | std::views::transform(
             [f = std::move(f),
              r1 = std::views::all(std::forward<R1>(r1)),
              r2 = std::views::all(std::forward<R2>(r2))]
             (std::size_t i) mutable {
                 return std::invoke(f, r1[i], r2[i]);
             });

    return r;
}

template<std::size_t N,
         std::ranges::random_access_range R>
requires std::ranges::sized_range<R>
[[nodiscard]] constexpr
auto adjacent(R&& r)
-> decltype(auto) {
    if ( std::ranges::size(r) < N ) {
        return std::views::empty<std::ranges::range_value_t<R>>;
    }

    return std::views::iota((std::size_t)N, std::ranges::size(r))
         | std::views::transform(
           [r = std::views::all(std::forward<R>(r))]
           (std::size_t i) mutable {
               return r[i];
           });
}
}
