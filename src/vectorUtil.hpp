#ifndef __VECTOR_UTIL_HPP__
#define __VECTOR_UTIL_HPP__

#include <vector>
#include <ostream>


inline
std::string vec2Str(const std::vector<int>& vec) {
    std::string tmp = "[";
    for(int i = 0; i < vec.size(); ++i) {
        if(0 != i) {
            tmp += ", ";
        }
        tmp += std::to_string(vec[i]);
    }
    tmp.push_back(']');
    return tmp;
}









#endif //__VECTOR_UTIL_HPP__