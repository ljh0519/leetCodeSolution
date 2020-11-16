#include "solution.hpp"

#include "../list/list1.hpp"
#include "../list/list2.hpp"
#include "../list/list3.hpp"
#include "../list/list4.hpp"

#include "../array/array1.hpp"
#include "../array/array2.hpp"

#include "../str/str1.hpp"

#include "../number/number1.hpp"


Solution* Solution::create(const std::string& type) {
    if("list1" == type) {
        return new SolutionList1();
    } else if ("list2" == type) {
        return new SolutionList2();
    } else if ("list3" == type) {
        return new SolutionList3();
    } else if ("list4" == type) {
        return new SolutionList4();
    } else if ("array1" == type) {
        return new SolutionArray1();
    } else if ("array2" == type) {
        return new SolutionArray2();
    } else if ("str1" == type) {
        return new SolutionStr1();
    } else if ("number1" == type) {
        return new SolutionNumber1();
    }

    return nullptr;
}


void Solution::free(Solution** obj) {
    if(obj) {
        delete *obj;
        *obj = nullptr;
    }
}