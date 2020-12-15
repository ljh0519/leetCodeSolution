#ifndef __NUMBER_CREATER_HPP__
#define __NUMBER_CREATER_HPP__

#include "../number/1.hpp"
#include "../number/2.hpp"
#include "../number/3.hpp"
#include "../number/4.hpp"
#include "../number/5.hpp"
#include "../number/6.hpp"
#include "../number/7.hpp"
#include "../number/8.hpp"


namespace XNumber {
    Solution* create(int type) {
        switch(type) {
            case 1 : return new SolutionNumber1();
            case 2 : return new SolutionNumber2();
            case 3 : return new SolutionNumber3();
            case 4 : return new SolutionNumber4();
            case 5 : return new SolutionNumber5();
            case 6 : return new SolutionNumber6();
            case 7 : return new SolutionNumber7();
            case 8 : return new SolutionNumber8();
            
            default: return nullptr;
        }

        return nullptr;
    }
}



#endif //__NUMBER_CREATER_HPP__