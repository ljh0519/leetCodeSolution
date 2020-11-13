#ifndef __LIST3_HPP__
#define __LIST3_HPP__

#include "solution.hpp"
#include "listCreater.hpp"
// 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

// k 是一个正整数，它的值小于或等于链表的长度。

// 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

// 示例：

// 给你这个链表：1->2->3->4->5

// 当 k = 2 时，应当返回: 2->1->4->3->5

// 当 k = 3 时，应当返回: 3->2->1->4->5

//  

// 说明：

// 你的算法只能使用常数的额外空间。
// 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

class SolutionList3 : public Solution{
public:	
	~SolutionList3() {
		if(list_) {
			ListCreater::free(&list_);
		}
	}

    virtual void solution() override {
		list_ = ListCreater::generateNewList({1,2,3,4,5});	//2,1,4,3
        int k = 2;
		// list_ = ListCreater::generateNewList({2,5,3,4,6,2,2});	//5,2,4,3,2,6,2

		list_ = (ListNode*)timer_.calc([this, k]() -> void* {
			return reverseKGroup(list_, k);
		});
    }

    virtual void dump() override {
		ListCreater::dump(list_);
        timer_.dump();
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* first = new ListNode();
        first->next = head;
        ListNode* p11 = first;          //第一个要翻转节点的前一个节点
        ListNode* p12 = p11->next;      //第一个被反转的节点
        ListNode* p21 = p11;            //第二个要翻转节点的前一个节点
        ListNode* p22 = p12;            //第二个被反转的节点

        while(p11 && p12) {
            int n = k - 1;
            for(; n-- && p21 && p22; p21 = p21->next, p22 = p22->next) ;
            if(-1 != n || !p21 || !p22) {
                break;
            }
            ListNode* p3 = p12->next;
            p12->next = p22->next;
            p22->next = p3;
            p11->next = p22;
            p21->next = p12;
            p11 = p12;
            p12 = p11->next;
            p21 = p11;
            p22 = p12;
        }

        if(first) {
            ListNode* tmp = first->next;
            delete first;
            first = first->next;
        }
        return first;
    }
private:
	ListNode* list_ = nullptr;
};



#endif //__LIST3_HPP__