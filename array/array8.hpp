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
        input1_ = {-1,2,1,-4}, target_ = 1;      

		timer_.calc([this]() -> void* {
			output_ = threeSumClosest(input1_, target_);
            return nullptr;
		});
    }

    virtual void dump() override {
        std::cout << "input : ";
        std::cout << vec2Str(input1_) << std::endl;
        std::cout << "target : " << target_ << std::endl;
        std::cout << "output : " << output_ << std::endl;
        timer_.dump();
    }

    //172ms     20MB
    int threeSumClosest(std::vector<int>& nums, int target) {
        if(nums.size() < 3){
            return 0; 
        }

        int sumClosest = nums[0] + nums[1] + nums[2];
        int dt = distance(target - nums[0] + nums[1] + nums[2]);
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int i = size - 1; i >= 2 ; --i) {
            if(i < size - 1 && nums[i] == nums[i+1]) {
                continue;
            }

            int m = 0, n = i - 1, mtarget = target - nums[i];
            while(m < n) {
                if(m > 0 && nums[m] == nums[m - 1]) {
                    ++m;
                    continue;
                } else if ( n < i - 1 && nums[n] == nums[n + 1]) {
                    --n;
                    continue;
                }

                int ndt = (mtarget - nums[m] - nums[n]);
                if(ndt == dt) {
                    return nums[m] + nums[n] + nums[i];
                } else if(ndt < dt) {
                    sumClosest = nums[m] + nums[n] + nums[i];
                    dt = ndt;
                    ++m;
                    --n;
                } else if (ndt > dt) {
                    if(nums[m] > nums[n]) {
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
    std::vector<int> input1_;
    int target_;
    int output_;
};



#endif //__ARRAY8_HPP__