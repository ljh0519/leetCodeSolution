#ifndef __STR_CREATER_HPP__
#define __STR_CREATER_HPP__

#include "../str/1.hpp"
#include "../str/2.hpp"
#include "../str/3.hpp"
#include "../str/4.hpp"
#include "../str/5.hpp"
#include "../str/***6.hpp"
#include "../str/7.hpp"
#include "../str/8.hpp"
#include "../str/9.hpp"
#include "../str/***10.hpp"
#include "../str/11.hpp"
#include "../str/12.hpp"


namespace XStr {
    Solution* create(int type) {
        switch(type) {
            case 1 : return new SolutionStr1();
            case 2 : return new SolutionStr2();
            case 3 : return new SolutionStr3();
            case 4 : return new SolutionStr4();
            case 5 : return new SolutionStr5();
            case 6 : return new SolutionStr6();
            case 7 : return new SolutionStr7();
            case 8 : return new SolutionStr8();
            case 9 : return new SolutionStr9();
            case 10 : return new SolutionStr10();
            case 11 : return new SolutionStr11();
            case 12 : return new SolutionStr12();
            
            default: return nullptr;
        }

        return nullptr;
    }
}



#endif //__STR_CREATER_HPP__