#pragma once

#include <functional>


namespace lk {

// Returns an index sequence of the tuple's size.
template<typename T>
using tuple_index_sequence = std::make_index_sequence<std::tuple_size_v<T>>;

}
