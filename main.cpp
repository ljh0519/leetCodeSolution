

#include "src/listCreater.hpp"
#include "solution.hpp"

int main(int argc, char* argv[]) {
    if(argc > 2) {
        return 0;
    }

	Solution* su = Solution::create(argv[1]);
    if(!su) {
        return 0;
    }

	su->solution();
    su->dump();

    Solution::free(&su);

	return 0;
}