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
	std::vector<int> a = {1, 2, 3};
	std::vector<int> b = {4, 5, 6};
	std::vector<int> c = {7, 8, 9};

	auto zipped   = lk::zip(a, b, c);
	auto unzipped = lk::unzip(zipped);

	fmt::print("{}\n{}, {}\n", zipped, std::get<0>(unzipped), std::get<1>(unzipped));
}
