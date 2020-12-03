#include "solution.hpp"

#include "../list/list1.hpp"
#include "../list/list2.hpp"
#include "../list/list3.hpp"
#include "../list/list4.hpp"
#include "../list/list5.hpp"

#include "../array/array1.hpp"
#include "../array/array2.hpp"
#include "../array/array3.hpp"
#include "../array/array5.hpp"
#include "../array/array6.hpp"
#include "../array/***array7.hpp"

#include "../str/str1.hpp"
#include "../str/str2.hpp"
#include "../str/str3.hpp"
#include "../str/str4.hpp"
#include "../str/str5.hpp"
#include "../str/***str6.hpp"

#include "../number/number1.hpp"
#include "../number/number2.hpp"
#include "../number/number3.hpp"
#include "../number/number4.hpp"
#include "../number/number5.hpp"
#include "../number/number6.hpp"
#include "../number/number7.hpp"


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
    } else if ("array5" == type) {
        return new SolutionArray5();
    } else if ("array6" == type) {
        return new SolutionArray6();
    } else if ("array7" == type) {
        return new SolutionArray7();
    } else if ("str1" == type) {
        return new SolutionStr1();
    } else if ("str2" == type) {
        return new SolutionStr2();
    } else if ("str3" == type) {
        return new SolutionStr3();
    } else if ("str4" == type) {
        return new SolutionStr4();
    } else if ("str5" == type) {
        return new SolutionStr5();
    } else if ("str6" == type) {
        return new SolutionStr6();
    } else if ("number1" == type) {
        return new SolutionNumber1();
    } else if ("number2" == type) {
        return new SolutionNumber2();
    } else if ("number3" == type) {
        return new SolutionNumber3();
    } else if ("number4" == type) {
        return new SolutionNumber4();
    } else if ("number5" == type) {
        return new SolutionNumber5();
    } else if ("number6" == type) {
        return new SolutionNumber6();
    } else if ("number7" == type) {
        return new SolutionNumber7();
    }

    return nullptr;
}


void Solution::free(Solution** obj) {
    if(obj) {
        delete *obj;
        *obj = nullptr;
    }
}