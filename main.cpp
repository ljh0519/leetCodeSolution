

#include "listUtil.hpp"
#include "solution.hpp"

int main(int argc, char* argv[]) {
    if(argc > 2) {
        return 0;
    }

	Solution* su = Solution::create(argv[1]);
    if(!su) {
        std::cout << "input error : " << argv[1] << std::endl;
        return 0;
    }

	su->solution();

    Solution::free(&su);

	return 0;
}