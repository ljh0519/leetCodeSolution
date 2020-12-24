#ifndef __LIST6_HPP__
#define __LIST6_HPP__

#include "solution.hpp"

// 19. 删除链表的倒数第N个节点

// 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

// 示例：

// 给定一个链表: 1->2->3->4->6, 和 n = 2.

// 当删除了倒数第二个节点后，链表变为 1->2->3->6.
// 说明：

// 给定的 n 保证是有效的。

// 进阶：

// 你能尝试使用一趟扫描实现吗？

class SolutionList6 : public Solution{
public:	
	~SolutionList6() {
        if(out_) {
            ListNode::free(&out_);
        }
        if(input2_) {
            ListNode::free(&input2_);
        }
    }

    virtual void solution() override {   

        // input1_ = {1,2,3,4,5}, n_ = 2;
        // input1_ = {1,2,3}, n_ = 4;
        input1_ = {1,2,3,4,5}, n_ = 4;
        // input1_ = {1,2,3,4,5}, n_ = 2;

        input2_ = ListNode::Create(input1_);


    }

   void test(std::vector<int>& expect) {
        dumpInput();

		timer_.calc([this]() -> void* {
			out_ = removeNthFromEnd(input2_, n_);
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
        std::cout << "intput1 : " << vec2Str(input1_) << std::endl;
        std::cout << "n : " << n_ << std::endl;
    }

    virtual void dumpOutput() override {
        std::cout << "output : ";
        ListNode::dump(out_);
        timer_.dump();
        std::cout << "###################################################" << std::endl;
    }

    //8ms       10.9MB
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head){
            return nullptr;
        }

        ListNode*pre = head, *next = head;
        for(; next->next && n--; next = next->next) ;
        if(!next->next) {
            ListNode* tmp = head;
            if(0 == n) {
                tmp = head->next;
                head->next = head->next->next;
            } else {
                head = head->next;
            }
            delete tmp;
            tmp = nullptr;
            return head;
        }

        for(; next->next ; pre = pre->next, next = next->next) ;
 
        if(pre && pre->next) {
            ListNode* tmp = pre->next;
            pre->next = pre->next->next;
            delete tmp;
            tmp = nullptr;
        }

        return head;
    }

private:
    ListNode* out_ = nullptr;
    int n_ = 0;
    std::vector<int> input1_;
    ListNode* input2_ = nullptr;
};



#endif //__LIST6_HPP__