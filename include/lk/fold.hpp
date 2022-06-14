#pragma once

#include <ranges>
#include <functional>

namespace lk {
/* FOLDS */

template<std::input_iterator I,
        std::sentinel_for<I> S,
        typename F,
        std::movable Init = std::iter_value_t<I>>
requires std::invocable<F&, Init, std::iter_reference_t<I>>
[[nodiscard]] constexpr
auto fold(I first, S last, Init init, F f)
-> Init {
    while ( first != last ) {
        init = std::invoke(f, std::move(init), *first);
        ++first;
    }

    return init;
}


template<std::ranges::input_range R,
         typename F,
         std::movable Init = std::ranges::range_value_t<R>>
[[nodiscard]] constexpr
auto fold_left(R&& rng, Init init, F f)
-> Init {
    return fold(std::ranges::begin(rng),
                std::ranges::end(rng),
                std::move(init),
                std::move(f));
}

template<std::ranges::input_range R,
         typename F,
         typename Ret = std::ranges::range_value_t<R>>
[[nodiscard]] constexpr
auto fold_left_first(R&& rng, F f)
-> Ret {
    return fold(std::next(std::ranges::begin(rng)),
                std::ranges::end(rng),
                *std::ranges::begin(rng),
                std::move(f));
}

template<std::ranges::input_range R,
         typename F,
         std::movable Init = std::ranges::range_value_t<R>>
[[nodiscard]] constexpr
auto fold_right(R&& rng, Init init, F f)
-> Init {
    return fold(std::ranges::rbegin(rng),
                std::ranges::rend(rng),
                std::move(init),
                std::move(f));
}

template<std::ranges::input_range R,
         typename F,
         typename Ret = std::ranges::range_value_t<R>>
[[nodiscard]] constexpr
auto fold_right_last(R&& rng, F f)
-> Ret {
    return fold(std::next(std::ranges::rbegin(rng)),
                std::ranges::rend(rng),
                *std::ranges::rbegin(rng),
                std::move(f));
}

template<std::ranges::input_range R,
         typename Ret = std::ranges::range_value_t<R>>
[[nodiscard]] constexpr
auto product(R&& rng)
-> Ret {
    return fold_left_first(rng,
                           std::move(std::multiplies{}));
}

template<std::ranges::input_range R,
         typename Ret = std::ranges::range_value_t<R>>
[[nodiscard]] constexpr
auto sum(R&& rng)
-> Ret {
    return fold_left_first(rng,
                           std::move(std::plus{}));
}



template<typename I, typename F>
class fold_t {
public:
    I&& init;
    F&& f;
};

template<typename I, typename F>
constexpr
auto fold(I&& init, F&& f)
-> fold_t<I, F> {
    return fold_t{
        std::forward<I>(init),
        std::forward<F>(f)
    };
}

template<std::ranges::input_range R,
         typename F,
         std::movable I>
constexpr
decltype(auto) operator|(R&& r, fold_t<I, F> _fold) {
    return fold(std::ranges::begin(r),
                std::ranges::end(r),
                _fold.init,
                _fold.f);
}

template<std::ranges::input_range R,
         typename Ret = std::ranges::range_value_t<R>>
[[nodiscard]] constexpr
auto max(R&& rng)
-> Ret {
    return fold_left_first(rng,
                           [] (auto&& a, auto&& b) {
                               return std::max(std::move(a), std::move(b));
                           });
}

template<std::ranges::input_range R,
         typename Ret = std::ranges::range_value_t<R>>
[[nodiscard]] constexpr
auto min(R&& rng)
-> Ret {
    return fold_left_first(rng,
                           [] (auto&& a, auto&& b) {
                               return std::min(std::move(a), std::move(b));
                           });
}

/* FOLDS */
}
