#include <iostream>
#include <ranges>
#include <numeric>
#include <functional>

#include "lk/ranges.hpp"
#include <fmt/ranges.h>

using namespace std::ranges;
using namespace std::views;

auto main()
-> int {
	auto v = views::iota(1, 1000);

	fmt::print("{}", lk::max(v));
}
