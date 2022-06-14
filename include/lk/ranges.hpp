#pragma once

#include <ranges>
#include <functional>

#include <lk/utils.hpp>

namespace lk
{

template<std::ranges::random_access_range R1,
         std::ranges::random_access_range R2>
requires std::ranges::sized_range<R1> && std::ranges::sized_range<R2>
[[nodiscard]] constexpr
auto zip(R1&& r1, R2&& r2)
-> decltype(auto) {
    return std::views::iota(0uz, std::min(std::ranges::size(r1), std::ranges::size(r2)))
        | std::views::transform([&](auto i) {
            return std::pair{ std::ranges::begin(r1)[i],
                              std::ranges::begin(r2)[i] };
        });
}

template<std::ranges::random_access_range ...R>
requires (std::ranges::sized_range<R> && ...)
[[nodiscard]] constexpr
auto zip(R&& ...r)
-> decltype(auto) {
    return std::views::iota(0uz, std::min({std::ranges::size(r) ...}))
         | std::views::transform(
           [...r = std::views::all(std::forward<R>(r))] (std::size_t i) mutable
           -> decltype(auto) {
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
    return lk::zip(std::views::all(std::forward<R>(r))...)
         | std::views::transform(
           [f = std::forward<F>(f)] (std::tuple<std::ranges::range_reference_t<R> ...>&& t) mutable
           -> decltype(auto) {
               return std::apply(std::forward<F>(f), std::move(t));
           });
}

template<std::ranges::random_access_range R>
requires std::ranges::sized_range<R>
[[nodiscard]] constexpr
auto unzip(R&& r)
-> decltype(auto) {
    const std::size_t size = std::ranges::size(r);

    return std::tuple{
        std::views::iota(0uz, size)
      | std::views::transform(
        [r = std::views::all(std::forward<R>(r))] (std::size_t i) mutable
        -> decltype(auto) {
            return std::get<0>(std::ranges::begin(r)[i]);
        }),

        std::views::iota(0uz, size)
      | std::views::transform(
        [r = std::views::all(std::forward<R>(r))] (std::size_t i) mutable
        -> decltype(auto) {
            return std::get<1>(std::ranges::begin(r)[i]);
        })};
}

template<std::size_t N,
         std::ranges::random_access_range R>
requires std::ranges::sized_range<R>
[[nodiscard]] constexpr
auto adjacent(R&& r)
-> decltype(auto) {
    const std::size_t size = std::ranges::size(r);

    return std::views::iota(N, std::max(size, N))
         | std::views::transform(
           [r = std::views::all(std::forward<R>(r))]
           (std::size_t i) mutable
           -> decltype(auto) {
               return r[i];
           });
}
}
