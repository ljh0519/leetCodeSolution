#ifndef __NUMBER7_HPP__
#define __NUMBER7_HPP__

#include <algorithm>
#include "solution.hpp"
// 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

// 示例:

// 输入: [-2,1,-3,4,-1,2,1,-5,4]
// 输出: 6
// 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
// 进阶:

// 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。


class SolutionNumber7 : public Solution{
public:	
	~SolutionNumber7() {}

    virtual void solution() override {   
        
        // input_ = {-2,1,-3,4,-1,2,1,-5,4};   //  6
        // input_ = {1,-2};   //  1
        // input_ = {-10,-2, -8, -9};   //  1

		timer_.calc([this]() -> void* {
			out_ = maxSubArray(input_);
            return nullptr;
		});
    }

    virtual void dump() override {
        std::cout << "input : ";
        for(int i = 0; i < input_.size(); ++i) {
            if(0 == i) {
                std::cout << input_[i];
            } else {
                std::cout << ", " << input_[i];
            }
        }
        std::cout << std::endl;
        std::cout << "out : " << out_ << std::endl;
        timer_.dump();
    }


    //16ms      13.4MB
    // int maxSubArray(std::vector<int>& nums) {
    //     if(nums.empty()) {
    //         return 0;
    //     }

    //     std::vector<int> maxs(nums);
    //     size_t size = nums.size();
    //     int max = nums[0];
    //     for(int i = 1; i < size; ++i) {
    //         maxs[i] = std::max(maxs[i-1] + nums[i], nums[i]);
    //         max = std::max(max, maxs[i]);
    //     }

    //     return max;
    // }

    int maxSubArray(std::vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }

        std::vector<int> maxs(nums);
        return maxSubArrRecursion(nums, maxs, 1, nums.size()-1);
    }

    //
    int maxSubArrRecursion(std::vector<int>& nums, std::vector<int>& maxs, int l, int r) {
        if(l == r) {
            maxs[l] = std::max(nums[l] + maxs[l-1], nums[l]);
            return std::max(maxs[l], maxs[l-1]);
        }
        int m = (l + r) >> 1;

        int maxl = maxSubArrRecursion(nums, maxs, l, m);
        int maxr = maxSubArrRecursion(nums, maxs, m+1, r);

        return std::max(maxl, maxr);
    }

private:
    int out_;
    std::vector<int> input_;
};



#endif //__NUMBER7_HPP__