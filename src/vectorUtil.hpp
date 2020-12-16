#ifndef __VECTOR_UTIL_HPP__
#define __VECTOR_UTIL_HPP__

#include <vector>
#include <ostream>


inline
std::string vec2Str(const std::vector<int>& vec, const std::string& delimiter = ", ") {
    std::string tmp = "[";
    for(int i = 0; i < vec.size(); ++i) {
        if(0 != i) {
            tmp += delimiter;
        }
        tmp += std::to_string(vec[i]);
    }
    tmp.push_back(']');
    return tmp;
}

inline
std::string vec2Str(const std::vector<std::string>& vec, const std::string& delimiter = ", ") {
    std::string tmp = "[";
    for(int i = 0; i < vec.size(); ++i) {
        if(0 != i) {
            tmp += delimiter;
        }
        tmp += vec[i];
    }
    tmp.push_back(']');
    return tmp;
}

inline
std::string vec2Str(const std::vector<char>& vec, const std::string& delimiter = ", ") {
    std::string tmp = "[";
    for(int i = 0; i < vec.size(); ++i) {
        if(0 != i) {
            tmp += delimiter;
        }
        tmp += vec[i];
    }
    tmp.push_back(']');
    return tmp;
}










#endif //__VECTOR_UTIL_HPP__