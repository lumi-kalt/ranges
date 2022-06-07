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
	constexpr auto v = views::iota(1, 1000);
	constexpr auto w = views::iota(5, 10);

	fmt::print("{}\n{}\n{}\n",
			   lk::adjacent<1>(w),
			   lk::adjacent<2>(w),
			   lk::adjacent<3>(w));
}
