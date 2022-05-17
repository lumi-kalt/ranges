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
	int v = views::iota(1, 999)
		   | lk::fold(1, std::plus{});

	fmt::print("{}", v);
}
