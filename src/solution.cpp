#include "solution.hpp"

#include "../list/list1.hpp"
#include "../list/list2.hpp"
#include "../list/list3.hpp"
#include "../list/list4.hpp"
#include "../list/list5.hpp"

#include "../array/array1.hpp"
#include "../array/array2.hpp"
#include "../array/array3.hpp"

#include "../str/str1.hpp"
#include "../str/str2.hpp"

#include "../number/number1.hpp"
#include "../number/number2.hpp"
#include "../number/number3.hpp"
#include "../number/number4.hpp"


Solution* Solution::create(const std::string& type) {
    if("list1" == type) {
        return new SolutionList1();
    } else if ("list2" == type) {
        return new SolutionList2();
    } else if ("list3" == type) {
        return new SolutionList3();
    } else if ("list4" == type) {
        return new SolutionList4();
    } else if ("list5" == type) {
        return new SolutionList5();
    } else if ("array1" == type) {
        return new SolutionArray1();
    } else if ("array2" == type) {
        return new SolutionArray2();
    } else if ("array3" == type) {
        return new SolutionArray3();
    } else if ("str1" == type) {
        return new SolutionStr1();
    } else if ("str2" == type) {
        return new SolutionStr2();
    } else if ("number1" == type) {
        return new SolutionNumber1();
    } else if ("number2" == type) {
        return new SolutionNumber2();
    } else if ("number3" == type) {
        return new SolutionNumber3();
    } else if ("number4" == type) {
        return new SolutionNumber4();
    }

    return nullptr;
}


void Solution::free(Solution** obj) {
    if(obj) {
        delete *obj;
        *obj = nullptr;
    }
}