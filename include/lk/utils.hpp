#pragma once

#include <functional>


namespace lk {

template<typename T>
[[nodiscard]] constexpr
auto min(T&& t)
-> T {
    return std::forward<T>(t);
}

template<typename T, typename ...Args>
[[nodiscard]] constexpr
auto min(T&& t, Args&& ...args)
-> T {
    return std::min(std::forward<T>(t), min(std::forward<Args>(args)...));
}

}
