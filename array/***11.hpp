
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




class SolutionArray11 : public Solution{
public:	
	~SolutionArray11() {}

    virtual void solution() override {   
        input_ = {3,2,1}, target_ = 0;      
        input_ = {3,2,1}, target_ = 0;      
        input_ = {3,2,1}, target_ = 0;      

		timer_.calc([this]() -> void* {
			output_ = search(input_, target_);
            return nullptr;
		});
    }

    virtual void dump() override {
        std::cout << "input : " << vec2Str(input_) << std::endl;
        timer_.dump();
    }

    int search(std::vector<int>& nums, int target) {
        return 0;
    }

private:
    std::vector<int> input_;
    int     target_;
    int output_;
};



#endif //__ARRAY11_HPP__