
#ifndef __ARRAY19_HPP__
#define __ARRAY19_HPP__

#include <memory.h>
#include <algorithm>
#include "solution.hpp"

// 41. 缺失的第一个正数

// 给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。

//  

// 示例 1:
// 输入: [1,2,0]
// 输出: 3

// 示例 2:
// 输入: [3,4,-1,1]
// 输出: 2

// 示例 3:
// 输入: [7,8,9,11,12]
// 输出: 1

// 提示：

// 你的算法的时间复杂度应为O(n)，并且只能使用常数级别的额外空间。





class SolutionArray19 : public Solution{
public:	
	~SolutionArray19() {}

    virtual void solution() override {   
        
        input_ = {1,2,0};
        // input_ = {3,4,-1,1};
        // input_ = {7,8,9,11,12};
        // input_ = {1,1};
        // input_ = {0,2,2,1,1};
     

		timer_.calc([this]() -> void* {
			output_ = firstMissingPositive(input_);
            return nullptr;
		});
    }

    virtual void dump() override {
        std::cout << "input : " << vec2Str(input_) << std::endl;
        std::cout << "output : " << output_ << std::endl;
        timer_.dump();
    }

    //
    int firstMissingPositive(std::vector<int>& nums) {
        if(nums.empty()) return 1;

        int size = nums.size();
        int candidates = 1;
        for(int i = 0; i < size; ++i) {
            if(nums[i] != i+1 
            && 0 < nums[i] 
            && nums[i] <= size
            && nums[nums[i]-1] != nums[i] ) {

                int tmp = nums[i];
                int tmpIndex = nums[i]-1;
                nums[i] = nums[tmpIndex];
                nums[tmpIndex] = tmp;
                --i;
            }
        }

        for(int i = 0; i < size; ++i) {
            if(nums[i] == candidates) {
                ++candidates;
            }
        }

        return candidates;
    }

private:
    std::vector<int> input_;
    int     output_;
};



#endif //__ARRAY19_HPP__