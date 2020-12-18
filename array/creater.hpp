#ifndef __ARRAY_CREATER_HPP__
#define __ARRAY_CREATER_HPP__

#include "../array/1.hpp"
#include "../array/2.hpp"
#include "../array/3.hpp"
#include "../array/4.hpp"
#include "../array/5.hpp"
#include "../array/6.hpp"
#include "../array/7.hpp"
#include "../array/8.hpp"
#include "../array/9.hpp"
#include "../array/10.hpp"
#include "../array/11.hpp"
#include "../array/12.hpp"
#include "../array/13.hpp"
#include "../array/14.hpp"
#include "../array/15.hpp"
#include "../array/16.hpp"
#include "../array/17.hpp"
#include "../array/18.hpp"
#include "../array/19.hpp"
#include "../array/20.hpp"


namespace XArray {
    Solution* create(int type) {
        switch(type) {
            case 1 : return new SolutionArray1();
            case 2 : return new SolutionArray2();
            case 3 : return new SolutionArray3();
            case 4 : return new SolutionArray4();
            case 5 : return new SolutionArray5();
            case 6 : return new SolutionArray6();
            case 7 : return new SolutionArray7();
            case 8 : return new SolutionArray8();
            case 9 : return new SolutionArray9();
            case 10 : return new SolutionArray10();
            case 11 : return new SolutionArray11();
            case 12 : return new SolutionArray12();
            case 13 : return new SolutionArray13();
            case 14 : return new SolutionArray14();
            case 15 : return new SolutionArray15();
            case 16 : return new SolutionArray16();
            case 17 : return new SolutionArray17();
            case 18 : return new SolutionArray18();
            case 19 : return new SolutionArray19();
            case 20 : return new SolutionArray20();

            default: return nullptr;
        }

        return nullptr;
    }
}



#endif //__ARRAY_CREATER_HPP__