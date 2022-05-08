#include <iostream>
#include <ranges>
#include <numeric>

#include "lk/ranges.hpp"
#include <fmt/ranges.h>

using namespace std::ranges;
using namespace std::views;

auto main()
-> int {
	auto v = views::iota(1, 10);

	fmt::print("{}", lk::fold_right_first(v, std::plus<int>{}));
}