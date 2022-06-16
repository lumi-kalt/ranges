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
	std::vector<std::pair<int, int>> v = {{1, 2}, {3, 4}};
	auto [a, b] = lk::unzip(v);


	fmt::print("{}, {}\n", a, b);
}
