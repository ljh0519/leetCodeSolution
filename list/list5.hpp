#ifndef __LIST5_HPP__
#define __LIST5_HPP__

#include "solution.hpp"
#include "math.h"
// 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

// 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

// 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

// 示例：

// 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
// 输出：7 -> 0 -> 8
// 原因：342 + 465 = 807

class SolutionList5 : public Solution{
public:	
	~SolutionList5() {
        if(out_) {
            ListNode::free(&out_);
        }
        if(tmp_) {
            ListNode::free(&tmp_);
        }
    }

    virtual void solution() override {    //取值范围 [−2^31,  2^31 − 1] = [-2147483648, 2147483647]
        ListNode* l1 = nullptr;
        ListNode* l2 = nullptr;

        // l1= ListNode::Create({1,5,3}),l2=ListNode::Create({4,5,6}); // 1005 5,0,0,1
        // l1= ListNode::Create({2,4,3}),l2=ListNode::Create({5,6,4}); // 807 7,0,8
        // l1= ListNode::Create({9,2,2,3,3,7,2,0,3,6,8,5,4,7,7,5,8,0,7}),l2=ListNode::Create({4}); // 3,3,2,3,3,7,2,0,3,6,8,5,4,7,7,5,8,0,7
        l1= ListNode::Create({9,9,9,9}),l2=ListNode::Create({9,9,9});
        // l1= ListNode::Create({1,5,3}),l2=ListNode::Create({4,5,6});

		timer_.calc([this, l1, l2]() -> void* {
			out_ = addTwoNumbers(l1, l2);
            return nullptr;
		});
    }

    virtual void dump() override {
        ListNode::dump(out_);
        timer_.dump();
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tmp_ = new ListNode;
        ListNode* node = tmp_;
        bool addDigit = false;
        while(nullptr != l1 || nullptr != l2) {
            char sum = addDigit ? 1 : 0;
            if(nullptr != l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(nullptr != l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            addDigit = sum > 9 ? (sum -= 10, true): false;
            node->next = new ListNode;
            node->next->val = sum;
            node = node->next;
        }

        if(addDigit) {
            node->next = new ListNode;
            node->next->val = 1;
        }

        return tmp_->next;
    }
private:
    ListNode* out_;
    ListNode* tmp_;
};



#endif //__LIST5_HPP__