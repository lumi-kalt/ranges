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
	auto a = std::vector{1, 2, 3};
	auto b = std::vector{4, 5, 6};
	auto c = std::vector{7, 8, 9};

	fmt::print("{}\n", lk::zip(a, b, c));
}
