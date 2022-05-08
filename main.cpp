#include <iostream>
#include <ranges>
#include <numeric>

//#include "lk/ranges.hpp"
//#include <fmt/ranges.h>

using namespace std::ranges;
using namespace std::views;

auto main()
-> int {
	auto v = views::iota(5, 10);

	return std::accumulate(v.begin(), v.end(), 0);
	//return lk::fold_right(v, 1, [](int a, int b) { return a + b; });
}