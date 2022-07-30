#include <iostream>
#include <ranges>
#include <numeric>
#include <functional>
#include <string>
#include <vector>

#include <fmt/ranges.h>
#include "lk/lk.hpp"

namespace stdr = std::ranges;
namespace stdv = std::views;

fn main()
-> int {
	std::vector<int> v {1, 2, 3, 4, 5};
	std::vector<int> w;

	fmt::print("{}\n", lk::scan_left(v, 0, std::plus{}));
}
