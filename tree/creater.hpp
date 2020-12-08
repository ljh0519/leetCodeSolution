#ifndef __TREE_CREATER_HPP__
#define __TREE_CREATER_HPP__

#include "../tree/1.hpp"
#include "../tree/2.hpp"


namespace XTree {
    Solution* create(int type) {
        switch(type) {
            case 1 : return new SolutionTree1();
            case 2 : return new SolutionTree2();
            
            default: return nullptr;
        }

        return nullptr;
    }
}



#endif //__TREE_CREATER_HPP__