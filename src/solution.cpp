#include "solution.hpp"

#include "../list/list1.hpp"
#include "../list/list2.hpp"
#include "../list/list3.hpp"




Solution* Solution::create(const std::string& type) {
    if("list1" == type) {
        return new SolutionList1();
    } else if ("list2" == type) {
        return new SolutionList2();
    } else if ("list3" == type) {
        return new SolutionList3();
    }

    return nullptr;
}


void Solution::free(Solution** obj) {
    if(obj) {
        delete *obj;
        *obj = nullptr;
    }
}