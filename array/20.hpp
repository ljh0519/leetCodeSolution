
#ifndef __ARRAY20_HPP__
#define __ARRAY20_HPP__

#include <memory.h>
#include <algorithm>
#include "solution.hpp"

// 42. 接雨水

// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

//  

// 示例 1：

// [图片] https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/rainwatertrap.png

// 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
// 输出：6
// 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 

// 示例 2：
// 输入：height = [4,2,0,3,2,5]
// 输出：9
//  

// 提示：

// n == height.length
// 0 <= n <= 3 * 104
// 0 <= height[i] <= 105




class SolutionArray20 : public Solution{
public:	
	~SolutionArray20() {}

    virtual void solution() override {   

        X_SOLUTION_TEST(6, input_ = {0,1,0,2,1,0,1,3,2,1,2,1});
        X_SOLUTION_TEST(83, input_ = {6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3});
        X_SOLUTION_TEST(9, input_ = {1,1,0,2,2,3,1,0,1,3,3,3,2,1,2,2,2,1});
        X_SOLUTION_TEST(9, input_ = {4,2,0,3,2,5});
        X_SOLUTION_TEST(1, input_ = {5,4,1,2});
        X_SOLUTION_TEST(34, input_ = {8,0,8,1,0,9,6,0,7,2,5});
     
    }

    void test(int expect) {
        dumpInput();

		timer_.calc([this]() -> void* {
			output_ = trap(input_);
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
        std::cout << "output : " << output_ << std::endl;
        timer_.dump();
        std::cout << "###################################################" << std::endl;
    }

    //12ms
	int trap(std::vector<int>& height) {
		int n = height.size();
		// left[i]表示i左边的最大值，right[i]表示i右边的最大值
		std::vector<int> left(n), right(n);
		for (int i = 1; i < n; i++) {
			left[i] = std::max(left[i - 1], height[i - 1]);
		}
		for (int i = n - 2; i >= 0; i--) {
			right[i] = std::max(right[i + 1], height[i + 1]);
		}
		int water = 0;
		for (int i = 0; i < n; i++) {
			int level = std::min(left[i], right[i]);
			water += std::max(0, level - height[i]);
		}
		return water;
	}

    //12ms
    // int trap(std::vector<int>& height) {
    //     if(height.size() < 3) return 0;
    //     int area = 0;
    //     int left = 0, right = height.size() - 1;
    //     int left_max = height[left], right_max = height[right];

    //     while( left <= right) {
    //         if(left_max <= right_max) {
    //             if(left_max > height[left]) {
    //                 area += left_max - height[left];
    //             } else {
    //                 left_max = height[left];
    //             }

    //             ++left;
    //         } else {
    //             if(right_max > height[right]) {
    //                 area += right_max - height[right];
    //             } else {
    //                 right_max = height[right];
    //             }

    //             --right;
    //         }
    //     }

    //     return area;
    // }

private:
    std::vector<int> input_;
    int     output_;
};



#endif //__ARRAY20_HPP__