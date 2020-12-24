#ifndef __ARRAY8_HPP__
#define __ARRAY8_HPP__

#include "solution.hpp"

// 16. 最接近的三数之和

// 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

//  

// 示例：

// 输入：nums = [-1,2,1,-4], target = 1
// 输出：2
// 解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
//  

// 提示：

// 3 <= nums.length <= 10^3
// -10^3 <= nums[i] <= 10^3
// -10^4 <= target <= 10^4


class SolutionArray8 : public Solution{
public:	
	~SolutionArray8() {}

    virtual void solution() override {
        // input1_ = {-1, 0, 1, 2, -1, -4};       //
        // input1_ = {0, 0, 0, 0};       //
        X_SOLUTION_TEST(0, input_ = {0,-4,1,-5}, target_ = 0);      
        X_SOLUTION_TEST(0, input_ = {-1,2,1,-4}, target_ = 1);      


    }

    void test(int expect) {
        dumpInput();

		timer_.calc([this]() -> void* {
			output_ = threeSumClosest(input_, target_);
            return nullptr;
		});

        dumpOutput();
        if(expect != output_) {
            std::cout << "expect != output : " << expect << " != " << output_ << std::endl;
            std::cout << "failed test!." << std::endl;
            exit(0);
        }
    }

    virtual void dumpInput() override {
        std::cout << "input : " << vec2Str(input_) << std::endl;
        std::cout << "target : " << target_ << std::endl;
    }

    virtual void dumpOutput() override {
        std::cout << "output : " << output_ << std::endl;
        timer_.dump();
        std::cout << "###################################################" << std::endl;
    }

    //16ms      10.1MB
    int threeSumClosest(std::vector<int>& nums, int target) {
        if(nums.size() < 3){
            return 0; 
        }

        std::sort(nums.begin(), nums.end());
        int sumClosest = nums[0] + nums[1] + nums[2];
        int dt = distance(target - sumClosest);
        int size = nums.size();
        for(int i = size - 1; i >= 2 ; --i) {
            if(i < size - 1 && nums[i] == nums[i+1]) {
                continue;
            }

            int m = 0, n = i - 1;
            while(m < n) {
                if(m > 0 && nums[m] == nums[m - 1]) {
                    ++m;
                    continue;
                } else if ( n < i - 1 && nums[n] == nums[n + 1]) {
                    --n;
                    continue;
                }

                int diff = target - nums[i] - nums[m] - nums[n];
                int ndt = distance(diff);
                if(0 == ndt) {
                    return nums[m] + nums[n] + nums[i];
                } else if(ndt < dt) {
                    sumClosest = nums[m] + nums[n] + nums[i];
                    dt = ndt;
                }

                if (ndt >= dt) {
                    if(diff > 0) {
                        ++m;
                    } else {
                        --n;
                    }
                }
            }
        }
        return sumClosest;
    }

    inline 
    int distance(int a) {
        return a > 0 ? a : -a; 
    }

private:
    std::vector<int> input_;
    int target_;
    int output_;
};



#endif //__ARRAY8_HPP__