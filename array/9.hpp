#ifndef __ARRAY9_HPP__
#define __ARRAY9_HPP__

#include <cmath>
#include "solution.hpp"

// 121. 买卖股票的最佳时机

// 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

// 如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。

// 注意：你不能在买入股票前卖出股票。

//  

// 示例 1:

// 输入: [7,1,5,3,6,4]
// 输出: 5
// 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
//      注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
// 示例 2:

// 输入: [7,6,4,3,1]
// 输出: 0
// 解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。



class SolutionArray9 : public Solution{
public:	
	~SolutionArray9() {}

    virtual void solution() override {   
        X_SOLUTION_TEST(5, input_ = {7,1,5,3,6,4});
        X_SOLUTION_TEST(0, input_ = {7,6,4,3,1});
        // input_ = {7,1};      

    }

    void test(int expect) {
        dumpInput();

		timer_.calc([this]() -> void* {
			output_ = maxProfit(input_);
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
    }

    virtual void dumpOutput() override {
        std::cout << "output : " << output_ << std::endl;
        timer_.dump();
        std::cout << "###################################################" << std::endl;
    }

    int maxProfit(std::vector<int>& prices) {
        if(prices.empty()) {
            return 0;
        }

        int size = prices.size();
        int max = 0;
        std::vector<int> stack;
        stack.emplace_back(prices[0]);
        for(int i = 1; i < size; ++i) {
            while(stack.back() >= prices[i] && !stack.empty()) {
                stack.pop_back();
            }
            if(stack.empty() || stack.back() < prices[i]) {
                stack.emplace_back(prices[i]);
                max = std::max(max, prices[i] - stack[0]);
            }
        }

        return max;
    }
private:
    std::vector<int> input_;
    int output_;
};



#endif //__ARRAY9_HPP__