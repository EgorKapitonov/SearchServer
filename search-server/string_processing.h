#pragma once
 
#include <vector>
#include <string>
#include <set>
#include <iostream>
 
std::vector<std::string_view> SplitIntoWords(std::string_view text);
 
template <typename StringContainer>
std::set<std::string, std::less<>> MakeUniqueNonEmptyStrings(const StringContainer& strings) {
    std::set<std::string, std::less<>> non_empty_strings;
    std::string str_save;
    for (auto str : strings) {
        str_save = str;
        if (!str_save.empty()) {
            non_empty_strings.insert(str_save);
        }
    }
    return non_empty_strings;
}