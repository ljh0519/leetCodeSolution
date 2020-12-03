#ifndef __ARRAY7_HPP__
#define __ARRAY7_HPP__

#include "solution.hpp"
// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

// 注意：答案中不可以包含重复的三元组。

//  

// 示例：

// 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

// 满足要求的三元组集合为：
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]


class SolutionArray7 : public Solution{
public:	
	~SolutionArray7() {}

    virtual void solution() override {
        input_ = {-1, 0, 1, 2, -1, -4};       //

		timer_.calc([&]() -> void* {
			output_ = threeSum(input_);
            return nullptr;
		});
    }

    virtual void dump() override {
        std::cout << "input : ";
        std::cout << vec2Str(input_) << std::endl;
        std::cout << "output : " << std::endl;
        for(int i = 0 ; i < output_.size(); ++i) {
		    std::cout << vec2Str(output_[i]) << std::endl;
        }
        timer_.dump();
    }

    //
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {

        for(int i = nums.size() - 1; i >= 0 ; --i) {
            
        }
    }

    std::vector<int> twoSum(std::vector<int>& nums, int sum, int i) {

    }

private:
    std::vector<int> input_;
    std::vector<std::vector<int>> output_;
};



#endif //__ARRAY7_HPP__