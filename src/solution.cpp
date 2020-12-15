#include "solution.hpp"

#include "../array/creater.hpp"

#include "../list/creater.hpp"

#include "../str/creater.hpp"

#include "../number/creater.hpp"

#include "../tree/creater.hpp"


Solution* Solution::create(const std::string& type) {
    std::string prefix;
    int index = 0;
    {
        auto search = type.find('-');
        if(search == std::string::npos) {
            return nullptr;
        }
        prefix = type.substr(0, search);
        index = atoi(type.substr(search+1, type.size() - search - 1).c_str());

    }
    if(prefix.empty() || 0 == index) {
        return nullptr;
    }

    if("list" == prefix) {
        return XList::create(index);
    } else if ("array" == prefix) {
        return XArray::create(index);
    } else if ("number" == prefix) {
        return XNumber::create(index);
    } else if ("str" == prefix) {
        return XStr::create(index);
    } else if ("tree" == prefix) {
        return XTree::create(index);
    }

    return nullptr;
}


void Solution::free(Solution** obj) {
    if(obj) {
        delete *obj;
        *obj = nullptr;
    }
}