#pragma once

#include <ranges>
#include <functional>

namespace lk {

namespace internal {
	class evens_iter {
		std::size_t n = 2;

	public:
		using value_type = std::size_t;
		using difference_type = std::ptrdiff_t;
		using iterator_category = std::forward_iterator_tag;

		[[nodiscard]] const 
		std::size_t& operator*() const
		{
			return n;
		}

		evens_iter& operator++()
		{
			n += 2;
			return *this;
		}

		evens_iter operator++(int)
		{
			auto prev = *this;
			n += 2;
			return prev;
		}

		bool operator==(const evens_iter&) const = default;
	};

	class odds_iter {
		std::size_t n = 1;

	public:
		using value_type = std::size_t;
		using difference_type = std::ptrdiff_t;
		using iterator_category = std::forward_iterator_tag;

		[[nodiscard]] const 
		std::size_t& operator*() const
		{
			return n;
		}

		odds_iter& operator++()
		{
			n += 2;
			return *this;
		}

		odds_iter operator++(int)
		{
			auto prev = *this;
			n += 2;
			return prev;
		}

		bool operator==(const odds_iter&) const = default;
	};
}

using namespace internal;

/* UTILS */



/* UTILS */

/* HELPER VIEWS */

inline constexpr
auto iota_evens = std::ranges::subrange<evens_iter, std::unreachable_sentinel_t>{};

inline constexpr
auto iota_odds = std::ranges::subrange<odds_iter, std::unreachable_sentinel_t>{};

/* HELPER VIEWS */
}