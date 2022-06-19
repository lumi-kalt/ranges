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
	int a;
	std::string b;

	fmt::print("{}\n{}\n", a, b);
}
