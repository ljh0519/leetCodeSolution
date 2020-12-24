#ifndef __LIST7_HPP__
#define __LIST7_HPP__

#include "solution.hpp"

// 21. 合并两个有序链表

// 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

//  

// 示例：

// 输入：1->2->4, 1->3->4
// 输出：1->1->2->3->4->4


class SolutionList7 : public Solution{
public:	
	~SolutionList7() {
        if(out_) {
            ListNode::free(&out_);
        }
        if(input1_) {
            ListNode::free(&input1_);
        }
        if(input2_) {
            ListNode::free(&input2_);
        }
    }

    virtual void solution() override {   

        // input11_ = {1,2,4}, input22_ = {1,3,4};
        // input11_ = {1,2,3,4,5}, input22_ = {};
        // input11_ = {1,2,3,4,5}, input22_ = {};
        // input11_ = {1,2,3,4,5}, input22_ = {};

        X_SOLUTION_TEST(std::vector<int>({}), input1_ = ListNode::Create(input11_), input2_ = ListNode::Create(input22_));

    }

   void test(std::vector<int>&& expect) {
        dumpInput();

		timer_.calc([this]() -> void* {
			out_ = mergeTwoLists(input1_, input2_);
            return nullptr;
		});

        dumpOutput();
        // if(expect != output_) {
        //     std::cout << "expect != output"  << std::endl;
        //     std::cout << "failed test!." << std::endl;
        //     exit(0);
        // }
		if(out_) {
			ListNode::free(&out_);
		}
    }

    virtual void dumpInput() override {
        std::cout << "intput1 : " << vec2Str(input11_) << std::endl;
        std::cout << "intput2 : " << vec2Str(input22_) << std::endl;
    }

    virtual void dumpOutput() override {
		std::cout << "output : ";
		ListNode::dump(out_);
        timer_.dump();
        std::cout << "###################################################" << std::endl;
    }

    //12ms      15MB
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) {
            return l2;
        } else if (!l2) {
            return l1;
        }

        ListNode first;
        ListNode* node = l1;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                if(!first.next) {
                    first.next = node = l1;
                    l1 = l1->next;
                    continue;
                }
                node->next = l1;
                l1 = l1->next;
            } else {
                if(!first.next) {
                    first.next = node = l2;
                    l2 = l2->next;
                    continue;
                }
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }

        if(!l1) {
            node->next = l2;
        } else if (!l2) {
            node->next = l1;
        }

        return first.next;
    }

private:
    ListNode* out_ = nullptr;
    std::vector<int> input11_;
    std::vector<int> input22_;
    ListNode* input1_ = nullptr;
    ListNode* input2_ = nullptr;
};



#endif //__LIST7_HPP__