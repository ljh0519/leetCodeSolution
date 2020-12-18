
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
        
        // input_ = {0,1,0,2,1,0,1,3,2,1,2,1};      //6
        // input_ = {1,1,0,2,2,3,1,0,1,3,3,3,2,1,2,2,2,1}; //6
        input_ = {4,2,0,3,2,5}; //9
     

		timer_.calc([this]() -> void* {
			output_ = trap(input_);
            return nullptr;
		});
    }

    virtual void dump() override {
        std::cout << "input : " << vec2Str(input_) << std::endl;
        std::cout << "output : " << output_ << std::endl;
        timer_.dump();
    }

    //
    int trap(std::vector<int>& height) {
        int size = height.size(); 
        if(size < 3) return 0;

        int area = 0;
        int leftTurnPoint = 0, rightTurnPoint = size - 1;

        // if(1 < size && height[0] > height[1]) {
        //     leftTurnPoint = 0;
        // }
        // for(int i = 1; i+1 < size; ++i) {
        //     if(height[i] > height[i+1] && height[i-1] < height[i]) {    //找到拐点
        //         if(-1 == leftTurnPoint)  leftTurnPoint = i;
        //         else if (-1 == rightTurnPoint)   rightTurnPoint = i;
        //     } else if(-1 == leftTurnPoint && height[i] > height[i+1] && height[i-1] == height[i]) {
        //         leftTurnPoint = i;
        //     } else if(-1 == rightTurnPoint && height[i] == height[i+1] && height[i-1] < height[i]) {
        //         rightTurnPoint = i;
        //     }
        //     if(-1 != leftTurnPoint && -1 != rightTurnPoint) {
        //         area += calcTrapArea(height, leftTurnPoint, rightTurnPoint);
        //         leftTurnPoint = rightTurnPoint;
        //         rightTurnPoint = -1;
        //     }
        // }

        if constexpr (std::is_integral<int>::value) {

        } else {
            
        }

        return area;
    }

private:
    int trapRecu(std::vector<int>& height, int left, int right) {
        
        int sub_left = left;
        int sub_right = right;
        int left_max = height[left];
        int right_max = height[right]; 
        for(left++, right--; left < right; ++left) {
            if(left_max < height[left])
        }
    }
    int calcTrapArea(std::vector<int>& height, int left, int right) {

        int area = 0;
        int sub_high = height[left] > height[right] ? height[right] : height[left];
        for(++left; left < right ; ++left) {
            if(height[left] < sub_high) {
                area += sub_high - height[left];
            }
        }

        return area;
    }
 
private:
    std::vector<int> input_;
    int     output_;
};



#endif //__ARRAY20_HPP__