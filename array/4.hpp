#ifndef __ARRAY4_HPP__
#define __ARRAY4_HPP__

#include <cmath>
#include "solution.hpp"

// 18. 四数之和

// 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

// 注意：

// 答案中不可以包含重复的四元组。

// 示例：

// 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

// 满足要求的四元组集合为：
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]

class SolutionArray4 : public Solution{
public:	
	~SolutionArray4() {}

    virtual void solution() override {   
        X_SOLUTION_TEST(std::vector<std::vector<int>>({{-1,  0, 0, 1},{-2, -1, 1, 2},{-2,  0, 0, 2}}), input_ = {1, 0, -1, 0, -2, 2}, target_ = 0);      
        // input_ = {1, 0, -1}, target_ = 0;      
        // input_ = {7,1}, target_ = 6;      


    }

    void test(std::vector<std::vector<int>>&& expect) {
        dumpInput();

		timer_.calc([this]() -> void* {
			output_ = fourSum(input_, target_);
            return nullptr;
		});

        dumpOutput();
        if(expect != output_) {
            // std::cout << "expect != output : " << expect << " != " << output_ << std::endl;
            std::cout << "failed test!." << std::endl;
            exit(0);
        }
    }

    virtual void dumpInput() override {
        std::cout << "input : " << vec2Str(input_) << std::endl;
        std::cout << "target : " << target_ << std::endl;
    }

    virtual void dumpOutput() override {
        std::cout << "output : " << std::endl;
        for(auto& vec : output_) {
            std::cout << vec2Str(vec) << std::endl;
        }
        timer_.dump();
        std::cout << "###################################################" << std::endl;
    }

    //128ms     13.1MB
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> out ;
        if(4 > nums.size()) {
            return out;
        }

        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int i = 0; i < size - 3; ++i) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < size - 2; ++j) {
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int m = j+1, n = size - 1, sub_target = target - nums[i] - nums[j];
                while(m < n) {
                    if(m > j+1 && nums[m] == nums[m-1]) {
                        ++m;
                        continue;
                    } else if(n < size - 1 && nums[n] == nums[n+1]) {
                        --n;
                        continue;
                    }

                    if(nums[m] + nums[n] == sub_target) {
                        out.emplace_back(std::vector<int>({nums[i], nums[j], nums[m], nums[n]}));
                        ++m,--n;
                    } else if(nums[m] + nums[n] > sub_target) {
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
    int target_;
    std::vector<std::vector<int>> output_;
};



#endif //__ARRAY4_HPP__