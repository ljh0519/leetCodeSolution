
#ifndef __ARRAY10_HPP__
#define __ARRAY10_HPP__

#include <cmath>
#include "solution.hpp"

// 31. 下一个排列

// 实现获取 下一个排列 的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

// 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

// 必须 原地 修改，只允许使用额外常数空间。

//  

// 示例 1：

// 输入：nums = [1,2,3]
// 输出：[1,3,2]
// 示例 2：

// 输入：nums = [3,2,1]
// 输出：[1,2,3]
// 示例 3：

// 输入：nums = [1,1,5]
// 输出：[1,5,1]
// 示例 4：

// 输入：nums = [1]
// 输出：[1]
//  

// 提示：

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 100



class SolutionArray10 : public Solution{
public:	
	~SolutionArray10() {}

    virtual void solution() override {   
        input_ = {3,2,1};      
        // input_ = {9,2,6,5,2,0};      
        input_ = {2,3,1,3,3};  //[2,3,3,1,3]
        // input_ = {7,1};      

		timer_.calc([this]() -> void* {
			nextPermutation(input_);
            return nullptr;
		});
    }

    virtual void dump() override {
        std::cout << "input : " << vec2Str(input_) << std::endl;
        timer_.dump();
    }

    void nextPermutation(std::vector<int>& nums) {
        if(nums.empty()) return ;

        int left = findLeftSwitchPoint(nums);
        if(-1 != left) {
            int right = findRightSwitchPoint(nums, left);
            if(-1 == right) {
                return ;
            }

            swap(&nums[left], &nums[right]);
        }

        reverseVec(nums, left+1);
    }

private:
    int findLeftSwitchPoint(std::vector<int>& nums) {
        for(int i = nums.size() - 2; i >= 0; --i) {
            if(nums[i] < nums[i+1]) {
                return i;
            }
        }
        return -1;
    }

    int findRightSwitchPoint(std::vector<int>& nums, int pos) {
        if(nums.size() <= pos + 1) {
            return -1;
        }

        int min = nums[pos];
        int out = pos + 1;
        for(size_t i = pos + 1; i < nums.size(); ++i) {
            if(nums[i] <= nums[out] && nums[i] > min) {
                out = i;
            }
        }

        return out;
    }

    void reverseVec(std::vector<int>& nums, int pos) {
        int j = nums.size() - 1;
        for(;pos < j; ++pos, --j) {
            swap(&nums[pos], &nums[j]);
        }
    }

    void swap(int*a, int*b) {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
private:
    std::vector<int> input_;
};



#endif //__ARRAY10_HPP__