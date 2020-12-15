#ifndef __LIST_CREATER_HPP__
#define __LIST_CREATER_HPP__

#include "../list/1.hpp"
#include "../list/2.hpp"
#include "../list/3.hpp"
#include "../list/4.hpp"
#include "../list/5.hpp"
#include "../list/6.hpp"
#include "../list/7.hpp"


namespace XList {
    Solution* create(int type) {
        switch(type) {
            case 1 : return new SolutionList1();
            case 2 : return new SolutionList2();
            case 3 : return new SolutionList3();
            case 4 : return new SolutionList4();
            case 5 : return new SolutionList5();
            case 6 : return new SolutionList6();
            case 7 : return new SolutionList7();
            
            default: return nullptr;
        }

        return nullptr;
    }
}



#endif //__LIST_CREATER_HPP__