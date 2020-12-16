
#ifndef __ARRAY13_HPP__
#define __ARRAY13_HPP__

#include "solution.hpp"

// 35. 搜索插入位置

// 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

// 你可以假设数组中无重复元素。

// 示例 1:
// 输入: [1,3,5,6], 5
// 输出: 2

// 示例 2:
// 输入: [1,3,5,6], 2
// 输出: 1

// 示例 3:
// 输入: [1,3,5,6], 7
// 输出: 4

// 示例 4:
// 输入: [1,3,5,6], 0
// 输出: 0




class SolutionArray13 : public Solution{
public:	
	~SolutionArray13() {}

    virtual void solution() override {   
        // input_ = {5,7,8,10}, target_ = 8;      
        // input_ = {1,3,5,6}, target_ = 5;      
        // input_ = {1,3,5,6}, target_ = 2;      
        // input_ = {1,3,5,6}, target_ = 7;      
        // input_ = {1,3,5,6}, target_ = 0;      
        // input_ = {1,3,5,6}, target_ = 6;      

		timer_.calc([this]() -> void* {
			output_ = searchInsert(input_, target_);
            return nullptr;
		});
    }

    virtual void dump() override {
        std::cout << "input : " << vec2Str(input_) << std::endl;
        std::cout << "target : " << target_ << std::endl;
        std::cout << "output : " << output_ << std::endl;
        timer_.dump();
    }

    int searchInsert(std::vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        else if (target < nums[0]) return 0;
        else if (target > nums.back()) return nums.size();

        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    std::vector<int> input_;
    int     target_;
    int     output_;
};



#endif //__ARRAY13_HPP__