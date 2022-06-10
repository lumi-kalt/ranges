#pragma once

#include <ranges>
#include <functional>

#include <lk/utils.hpp>

namespace lk
{
template<std::ranges::random_access_range ...R>
requires (std::ranges::sized_range<R> && ...)
[[nodiscard]] constexpr
auto zip(R&& ...r)
-> decltype(auto) {
    return std::views::iota((std::size_t)0, std::min({std::ranges::size(r) ...}))
         | std::views::transform(
           [...r = std::views::all(std::forward<R>(r))] (std::size_t i) mutable {
               return std::tuple<std::ranges::range_reference_t<R> const& ...>
                      { std::ranges::begin(r)[i] ... };
           });
}

template<typename F,
         std::ranges::random_access_range ...R>
requires std::invocable<F&, std::ranges::range_reference_t<R> ...>
      && (std::ranges::sized_range<R> && ...)
[[nodiscard]] constexpr
auto zip_with(F&& f, R&& ...r)
-> decltype(auto) {
    return lk::zip(std::forward<R>(r)...)
         | std::views::transform(
           [f = std::forward<F>(f)] (std::tuple<std::ranges::range_reference_t<R> ...>&& t) mutable {
               return std::apply(std::forward<F>(f), std::move(t));
           });
}

template<std::size_t N,
         std::ranges::random_access_range R>
requires std::ranges::sized_range<R>
[[nodiscard]] constexpr
auto adjacent(R&& r)
-> decltype(auto) {
    const std::size_t size = std::ranges::size(r);

    return std::views::iota(N, size < N ? N : size)
         | std::views::transform(
           [r = std::views::all(std::forward<R>(r))]
           (std::size_t i) mutable {
               return r[i];
           });
}
}
