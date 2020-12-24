#ifndef __ARRAY5_HPP__
#define __ARRAY5_HPP__

#include "solution.hpp"
// 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

// 说明：你不能倾斜容器。

// 示例 1：

// 输入：[1,8,6,2,5,4,8,3,7]
// 输出：49 
// 解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
// 示例 2：

// 输入：height = [1,1]
// 输出：1
// 示例 3：

// 输入：height = [4,3,2,1,4]
// 输出：16
// 示例 4：

// 输入：height = [1,2,1]
// 输出：2
//  

// 提示：

// n = height.length
// 2 <= n <= 3 * 104
// 0 <= height[i] <= 3 * 104



class SolutionArray5 : public Solution{
public:	
	~SolutionArray5() {}

    virtual void solution() override {
        X_SOLUTION_TEST(49, input_ = {1,8,6,2,5,4,8,3,7});       //49

    }

    void test(int expect) {
        dumpInput();

		timer_.calc([&]() -> void* {
			out_ = maxArea(input_);
            return nullptr;
		});

        dumpOutput();
        if(expect != out_) {
            std::cout << "expect != output : " << expect << " != " << out_ << std::endl;
            std::cout << "failed test!." << std::endl;
            exit(0);
        }
    }

    virtual void dumpInput() override {
        std::cout << "input : " << vec2Str(input_) << std::endl;
    }

    virtual void dumpOutput() override {
		std::cout << "out = " << out_ << std::endl;
        timer_.dump();
        std::cout << "###################################################" << std::endl;
    }

    //44ms      17.8MB
    int maxArea(std::vector<int>& height) {
        if(2 == height.size()) {
            return height[0] > height[1] ? height[1] : height[0];
        }

        int i = 0, j = height.size() - 1;
        int pre_l = height[i];
        int pre_r = height[j];
        int max = 0;
        while(i < j) {
            if(pre_l > height[i]) {
                ++i;
                continue;
            } else if(pre_r > height[j]){
                --j;
                continue;
            }

            int area = 0;
            if(height[i] > height[j]) {
                pre_r = height[j];
                area = height[j] * (j - i);
                --j;
            } else {
                pre_l = height[i];
                area = height[i] * (j - i);
                ++i;
            }
            if(max < area) max = area;
        }
        return max;
    }

private:
    std::vector<int> input_;
    int out_;
};



#endif //__ARRAY5_HPP__