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
	const auto v = {1, 2, 3};

	fmt::print("any_in({{1, 2, 3}}, 1, 2) = {}\n", lk::any_in(v, 1, 2));
}
