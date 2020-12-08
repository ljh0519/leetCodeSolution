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

            default: return nullptr;
        }

        return nullptr;
    }
}



#endif //__ARRAY_CREATER_HPP__