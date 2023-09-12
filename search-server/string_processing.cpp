#include "string_processing.h"
 
std::vector<std::string_view> SplitIntoWords(std::string_view text) {
    std::vector<std::string_view> words;
    std::string_view word(text);
    
        word.remove_prefix(std::min(word.find_first_not_of(' '), word.size()));
    const int64_t pos_end = word.npos;
    while (!word.empty()) {
        int64_t space = word.find(' ');
        std::string_view temp;
        words.push_back(space == pos_end ? temp = word.substr(0, pos_end) : temp = word.substr(0, space));
        word.remove_prefix(std::min(word.find_first_not_of(' ', space), word.size()));
    }
    return words;
}