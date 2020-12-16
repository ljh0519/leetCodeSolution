
#ifndef __ARRAY11_HPP__
#define __ARRAY11_HPP__

#include "solution.hpp"

// 33. 搜索旋转排序数组

// 给你一个整数数组 nums ，和一个整数 target 。

// 该整数数组原本是按升序排列，但输入时在预先未知的某个点上进行了旋转。（例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] ）。

// 请你在数组中搜索 target ，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

//  
// 示例 1：

// 输入：nums = [4,5,6,7,0,1,2], target = 0
// 输出：4

// 示例 2：

// 输入：nums = [4,5,6,7,0,1,2], target = 3
// 输出：-1

// 示例 3：

// 输入：nums = [1], target = 0
// 输出：-1
//  

// 提示：

// 1 <= nums.length <= 5000
// -10^4 <= nums[i] <= 10^4
// nums 中的每个值都 独一无二
// nums 肯定会在某个点上旋转
// -10^4 <= target <= 10^4








//这个题想表达的意思是：
// 一个数组做了旋转，在旋转后的数组中找到target，存在返回target索引，不存在返回-1。

class SolutionArray11 : public Solution{
public:	
	~SolutionArray11() {}

    virtual void solution() override {   
        // input_ = {1}, target_ = 2;      
        // input_ = {1,3}, target_ = 3;      
        // input_ = {3,1}, target_ = 1;      
        // input_ = {1,2,3}, target_ = 2;      
        // input_ = {1,3,5}, target_ = 1;      
        // input_ = {4,5,6,7,0,1,2}, target_ = 0;      
        // input_ = {5,6,7,0,1,2,4}, target_ = 4;      

		timer_.calc([this]() -> void* {
			output_ = search(input_, target_);
            return nullptr;
		});
    }

    virtual void dump() override {
        std::cout << "input : " << vec2Str(input_) << std::endl;
        std::cout << "output : " << output_ << std::endl;
        timer_.dump();
    }

    int search(std::vector<int>& nums, int target) {
        if(nums.empty()) return -1;

        int broke = nums[0];
        int left = 0;
        int right = nums.size()-1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                if(broke <= target) {
                    if(broke <= nums[mid]) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                } else {
                    if(broke <= nums[mid]) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
            } else if (nums[mid] < target) {
                if(broke <= target) {
                    if(broke <= nums[mid]) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                } else {
                    if(broke <= nums[mid]) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
            }
        }

        return -1;
    }

private:
    std::vector<int> input_;
    int     target_;
    int output_;
};



#endif //__ARRAY11_HPP__