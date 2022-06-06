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
	auto v = views::iota(1, 1000);
	auto w = views::iota(5, 10);

	fmt::print("{}", lk::zip_with(v, w, [](int a, int b) { return a + b; }, [](int i) { return i * i; }));
}
