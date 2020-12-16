
#ifndef __ARRAY12_HPP__
#define __ARRAY12_HPP__

#include "solution.hpp"

// 34. 在排序数组中查找元素的第一个和最后一个位置

// 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

// 如果数组中不存在目标值 target，返回 [-1, -1]。

// 进阶：

// 你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
//  

// 示例 1：

// 输入：nums = [5,7,7,8,8,10], target = 8
// 输出：[3,4]
// 示例 2：

// 输入：nums = [5,7,7,8,8,10], target = 6
// 输出：[-1,-1]
// 示例 3：

// 输入：nums = [], target = 0
// 输出：[-1,-1]
//  

// 提示：

// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109
// nums 是一个非递减数组
// -109 <= target <= 109



class SolutionArray12 : public Solution{
public:	
	~SolutionArray12() {}

    virtual void solution() override {   
        // input_ = {5,7,7,8,8,10}, target_ = 8;      
        // input_ = {5,7,7,8,8,10}, target_ = 6;       
        // input_ = {}, target_ = 2;      
        // input_ = {1,3,5}, target_ = 1;         

		timer_.calc([this]() -> void* {
			output_ = searchRange(input_, target_);
            return nullptr;
		});
    }

    virtual void dump() override {
        std::cout << "input : " << vec2Str(input_) << std::endl;
        std::cout << "target : " << target_ << std::endl;
        std::cout << "output : " << vec2Str(output_) << std::endl;
        timer_.dump();
    }

    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        std::vector<int> range = {-1,-1};
        if(nums.empty()) {
            return range;
        }

        int size = nums.size();
        for(size_t i = 0; i < size; ++i) {
            if(nums[i] == target) {
                if(-1 == range[0]) {
                    range[0] = i;
                }
                range[1] = i;
            } else if (nums[i] > target) {
                break;
            }
        }
        return range;
    }

private:
    std::vector<int> input_;
    int     target_;
    std::vector<int> output_;
};



#endif //__ARRAY12_HPP__