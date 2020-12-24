
#ifndef __ARRAY17_HPP__
#define __ARRAY17_HPP__

#include "memory.h"
#include "solution.hpp"

// 448. 找到所有数组中消失的数字

// 给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。

// 找到所有在 [1, n] 范围之间没有出现在数组中的数字。

// 您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。

// 示例:

// 输入:
// [4,3,2,7,8,2,3,1]

// 输出:
// [5,6]





class SolutionArray17 : public Solution{
public:	
	~SolutionArray17() {}

    virtual void solution() override {   
        X_SOLUTION_TEST(std::vector<int>({5,6}), input_ = {4,3,2,7,8,2,3,1});
        X_SOLUTION_TEST(std::vector<int>({1,2,8}), input_ = {5,4,6,7,9,3,10,9,5,6});

    }

    void test(std::vector<int>&& expect) {
        dumpInput();

		timer_.calc([this]() -> void* {
			output_ = findDisappearedNumbers(input_);
            return nullptr;
		});

        dumpOutput();
        if(expect != output_) {
            std::cout << "expect != output"  << std::endl;
            std::cout << "failed test!." << std::endl;
            exit(0);
        }
    }

    virtual void dumpInput() override {
        std::cout << "input : " << vec2Str(input_) << std::endl;
    }

    virtual void dumpOutput() override {
        std::cout << "output : " << vec2Str(output_) << std::endl;
        timer_.dump();
        std::cout << "###################################################" << std::endl;
    }

    //
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        std::vector<int> out;
        if(nums.empty()) return out;

        int size = nums.size();
        out.assign(size, 1);
        for(int i = 0; i < size; ++i) {
            if(out[nums[i] - 1]) {
                out[nums[i] - 1] = 0;
            }
        }
        int index = 0;
        for(int i = 1; i < size && index < size;) {
            if(out[index]) {
                out[index] = index+1;
                ++index;
                i = index;
            } else  {
                if(out[i]) {
                    out[i] = 0;
                    out[index] = i+1;
                    ++index;
                }
                ++i;
            }
        }
        out.erase(out.begin() + index, out.end());
        return out;
    }


private:
    std::vector<int> input_;
    std::vector<int> output_;
};



#endif //__ARRAY17_HPP__