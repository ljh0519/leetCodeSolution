
#ifndef __NUMBER8_HPP__
#define __NUMBER8_HPP__

#include <algorithm>
#include "solution.hpp"

// 292. Nim 游戏

// 你和你的朋友，两个人一起玩 Nim 游戏：

// 桌子上有一堆石头。
// 你们轮流进行自己的回合，你作为先手。
// 每一回合，轮到的人拿掉 1 - 3 块石头。
// 拿掉最后一块石头的人就是获胜者。
// 假设你们每一步都是最优解。请编写一个函数，来判断你是否可以在给定石头数量为 n 的情况下赢得游戏。如果可以赢，返回 true；否则，返回 false 。

//  

// 示例 1：

// 输入：n = 4
// 输出：false 
// 解释：如果堆中有 4 块石头，那么你永远不会赢得比赛；
//      因为无论你拿走 1 块、2 块 还是 3 块石头，最后一块石头总是会被你的朋友拿走。
// 示例 2：

// 输入：n = 1
// 输出：true
// 示例 3：

// 输入：n = 2
// 输出：true
//  

// 提示：

// 1 <= n <= 231 - 1



class SolutionNumber8 : public Solution{
public:	
	~SolutionNumber8() {}

    virtual void solution() override {   
        
        input_ = 6;  //false

		timer_.calc([this]() -> void* {
			out_ = canWinNim(input_);
            return nullptr;
		});
    }

    virtual void dump() override {
        std::cout << "input : " << input_ << std::endl;
        std::cout << "out : " << out_ << std::endl;
        timer_.dump();
    }


    //当石子是4的倍数时，先手总是输（只要对手将一回合拿掉的石子保持4，那么剩余石子永远是4的倍数），当石子被4除后余1~3，先手总赢
    bool canWinNim(int n) {
        return n%4 > 0;
    }

private:
    bool out_;
    int input_;
};



#endif //__NUMBER8_HPP__