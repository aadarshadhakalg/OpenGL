//
// Created by aadarshadhakalg on 5/9/23.
//
#include <Utilities.hpp>

std::string convertToString(std::vector<char> a)
{
    int i;
    std::string s = "";
    for (auto i = a.begin(); i != a.end(); ++i)
        s = s + " " + *i + ", ";

    return s;
}