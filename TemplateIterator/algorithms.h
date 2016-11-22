#pragma once
#include <iostream>

template <typename Container>
void print( Container &container)
{
    for (auto value : container)
        std::cout << value << " ";
}

template <typename Iterator>
auto min_value(const Iterator &begin, const Iterator &end)
{
    auto min = *begin;
    auto it = begin;
    for (++it; it != end; ++it)
        if (min > *it)
            min = *it;
    return min;
}

template <typename Container>
auto min_value( Container &container)
{
    return min_value(container.begin(), container.end());
}
