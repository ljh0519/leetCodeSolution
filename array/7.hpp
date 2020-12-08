#ifndef __ARRAY7_HPP__
#define __ARRAY7_HPP__

#include "solution.hpp"

// 15. 三数之和
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
        // input_ = {-1, 0, 1, 2, -1, -4};       //
        // input_ = {0, 0, 0, 0};       //
        input_ = {-4, -3, -2, -1, -1, 0, 0, 1, 2, 3, 4};       //[[-4,0,4],[-4,1,3],[-3,-1,4],[-3,0,3],[-3,1,2],[-2,-1,3],[-2,0,2],[-1,-1,2],[-1,0,1]]

		timer_.calc([this]() -> void* {
			output_ = threeSum(input_);
            return nullptr;
		});
    }

    virtual void dump() override {
        std::cout << "input : ";
        std::cout << vec2Str(input_) << std::endl;
        std::cout << "output : " << std::endl;
        for(int i = 0 ; i < output_.size(); ++i) {
		    std::cout << "    " << vec2Str(output_[i]) << std::endl;
        }
        timer_.dump();
    }

    //172ms     20MB
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> out;
        if(nums.size() < 3){
            return out;
        }

        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int i = size - 1; i >= 2 ; --i) {
            if(i < size - 1 && nums[i] == nums[i+1]) {
                continue;
            }

            int m = 0, n = i - 1, target = 0 - nums[i];
            while(m < n) {
                if(m > 0 && nums[m] == nums[m - 1]) {
                    ++m;
                    continue;
                } else if ( n < i - 1 && nums[n] == nums[n + 1]) {
                    --n;
                    continue;
                }
                int sum = nums[m] + nums[n];
                if(sum  == target) {
                    out.emplace_back(std::vector<int>({ nums[m], nums[n], nums[i]}));
                    ++m;
                    --n;
                } else if (sum > target) {
                    if(nums[m] > nums[n]) {
                        ++m;
                    } else {
                        --n;
                    }
                } else if (sum < target) {
                    if(nums[m] > nums[n]) {
                        --n;
                    } else {
                        ++m;
                    }
                }
            }
        }
        return out;
    }

private:
    std::vector<int> input_;
    std::vector<std::vector<int>> output_;
};



#endif //__ARRAY7_HPP__