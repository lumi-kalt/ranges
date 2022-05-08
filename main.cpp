#include <iostream>
#include <ranges>

#include "lk/ranges.hpp"
#include <fmt/ranges.h>

using namespace std::ranges;
using namespace std::views;

auto main()
-> int {
	auto v = views::iota(5)
		   | views::take(10);

	fmt::print("{}", lk::fold_left(v, 1, std::plus<int>{}));
}