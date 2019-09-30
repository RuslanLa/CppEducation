#include <string_view>


//Assumeyou have a method isSubstringwhich checks if one word is a substring of another.
// Given two strings, sl and s2, write code to check if s2 is a rotation of sl
// using only one call to isSubstring (e.g.,"waterbottle" is a rotation of"erbottlewat").

bool IsSubstring(std::string_view first, std::string_view second) {
    return first.find(second) != std::string_view::npos;
}

bool IsRotation(std::string_view first, std::string_view second) {
    std::string double_first {first};
    double_first+=first;
    return IsSubstring(double_first, second);
}