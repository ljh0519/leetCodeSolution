#ifndef __ARRAY9_HPP__
#define __ARRAY9_HPP__

#include <cmath>
#include "solution.hpp"

// 16. 最接近的三数之和

// 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

//  

// 示例：

// 输入：nums = [-1,2,1,-4], target = 1
// 输出：2
// 解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
//  

// 提示：

// 3 <= nums.length <= 10^3
// -10^3 <= nums[i] <= 10^3
// -10^4 <= target <= 10^4


class SolutionArray9 : public Solution{
public:	
	~SolutionArray9() {}

    virtual void solution() override {   
        // input_ = {7,1,5,3,6,4};      
        // input_ = {7,1};      

		timer_.calc([this]() -> void* {
			output_ = maxProfit(input_);
            return nullptr;
		});
    }

    virtual void dump() override {
        std::cout << "input : ";
        std::cout << vec2Str(input_) << std::endl;
        std::cout << "output : " << output_ << std::endl;
        timer_.dump();
    }

    int maxProfit(std::vector<int>& prices) {
        if(prices.empty()) {
            return 0;
        }

        int size = prices.size();
        int max = 0;
        std::vector<int> stack;
        stack.emplace_back(prices[0]);
        for(int i = 1; i < size; ++i) {
            while(stack.back() >= prices[i] && !stack.empty()) {
                stack.pop_back();
            }
            if(stack.empty() || stack.back() < prices[i]) {
                stack.emplace_back(prices[i]);
                max = std::max(max, prices[i] - stack[0]);
            }
        }

        return max;
    }
private:
    std::vector<int> input_;
    int output_;
};



#endif //__ARRAY9_HPP__