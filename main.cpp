#include <iostream>
#include <ranges>
#include <numeric>
#include <functional>

#include "lk/lk.hpp"
#include <fmt/ranges.h>

using namespace std::ranges;
using namespace std::views;

auto main()
-> int {
	auto a = std::array{ 1, 2, 3, 4, 5 };
	auto b = std::array{ 6, 7, 8, 9, 10 };
	auto c = std::array{ 11, 12, 13, 14, 15 };
	auto d = std::array{ 16, 17, 18, 19, 20 };

	fmt::print("{}\n", lk::scan_left(
		lk::zip(a, b, c, d), 0,
		[](auto&& acc, auto&& tuple) {
			auto f = [] (auto&& ...args) {
				return (args + ...);
			};
			return acc + std::apply(f, tuple);
		}));
}
