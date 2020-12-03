#ifndef __SOLUTIION_HPP__
#define __SOLUTIION_HPP__

#include <string>
#include "listUtil.hpp"
#include "treeUtil.hpp"
#include "vectorUtil.hpp"
#include "timer.hpp"

class Solution {
public:
    virtual void solution() = 0;

    virtual void dump() = 0;

    static
    Solution* create(const std::string& type);

    static
    void free(Solution** obj);
protected:
    Timer timer_;
};







#endif //__SOLUTIION_HPP__