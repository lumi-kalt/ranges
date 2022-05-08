#include <ranges>
#include <numeric>
#include <iostream>

using namespace std::views;
using namespace std::ranges;

auto main()
-> int {
	auto v = std::ranges::views::iota(1, 10);
	std::cout << std::accumulate(v.begin(), v.end(), 0);
}
