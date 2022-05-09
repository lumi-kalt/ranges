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
	auto v = views::iota(1, 1000)
		   | views::filter([](auto&& i) {
			    auto v = lk::sum(lk::iota_odds | views::take(i));
				return v == i * i;
			 });

	fmt::print("{}\n", fmt::format("{}", v) == fmt::format("{}", views::iota(1, 1000)));
}
