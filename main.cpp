#include <iostream>
#include <ranges>
#include <numeric>
#include <functional>
#include <string>
#include <vector>

#include "lk/lk.hpp"
#include <fmt/ranges.h>

using namespace std::ranges;
using namespace std::views;

auto main()
-> int {
	const auto v = {1, 2, 3};

	fmt::print("any_in({{1, 2, 3}}, 1, 2) = {}\n", lk::any_in(v, 1, 2));
}
