#ifndef __SOLUTIION_HPP__
#define __SOLUTIION_HPP__

#include <string>
#include "listUtil.hpp"
#include "treeUtil.hpp"
#include "vectorUtil.hpp"
#include "timer.hpp"

#define X_SOLUTION_TEST(expect, ...) (__VA_ARGS__), test(expect); 


static void test() {

}

class Solution {
public:
    virtual ~Solution() {};

    virtual void solution() = 0;

    virtual void dumpInput() = 0;

    virtual void dumpOutput() = 0;

    static
    Solution* create(const std::string& type);

    static
    void free(Solution** obj);
protected:
    Timer timer_;
};







#endif //__SOLUTIION_HPP__