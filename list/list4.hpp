#ifndef __LIST4_HPP__
#define __LIST4_HPP__

#include "solution.hpp"
#include "listCreater.hpp"
// 反转一个单链表。

// 示例:

// 输入: 1->2->3->4->5->NULL
// 输出: 5->4->3->2->1->NULL
// 进阶:
// 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

class SolutionList4 : public Solution{
public:	
	~SolutionList4() {
		if(list_) {
			ListCreater::free(&list_);
		}
	}

    virtual void solution() override {
		// list_ = ListCreater::generateNewList({1});	//nullptr
		// list_ = ListCreater::generateNewList({1});	//1
		// list_ = ListCreater::generateNewList({1,2,3,4});	//2,1,4,3
		// list_ = ListCreater::generateNewList({1,2,3,4,5});	//3,2,1,4,5
		list_ = ListCreater::generateNewList({2,5,3,4,6,2,2});	//5,2,4,3,2,6,2     3,5,2,2,6,4,2

		list_ = (ListNode*)timer_.calc([this]() -> void* {
			return reverseList(list_);
		});
    }

    virtual void dump() override {
		ListCreater::dump(list_);
        timer_.dump();
    }

    // 从头回转
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }

        ListNode* pre = nullptr;
        ListNode* now = head;
        ListNode* next = head;
        do {
            next = next->next;
            now->next = pre;
            pre = now;
            now = next;
        } while(now);

        return pre;
    }

    // 强者之路！！！
    // ListNode* reverseList(ListNode* head) {
    //     ListNode *p;
    //     for(p=nullptr; head;) {
    //         swap(p,head->next);
    //         swap(head,p);
    //     }
    //     return p;
    // }
    // void swap(ListNode*& a, ListNode*& b) {
    //     ListNode* tmp = a;
    //     a = b;
    //     b = tmp;
    // }


    // 递归
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* rfirst = head;
    //     for(;nullptr != rfirst && nullptr != rfirst->next; rfirst = rfirst->next);

    //     ListNode* pnode = reverse(head);
    //     if(pnode) {
    //         pnode->next = nullptr;
    //     }

    //     return rfirst;
    // }

    // ListNode* reverse(ListNode* node) {
    //     if(!node) {
    //         return nullptr;
    //     }

    //     ListNode* pnode = reverse(node->next);
    //     if(pnode) {
    //         pnode->next = node;
    //     }
    //     return node;
    // }
private:
	ListNode* list_ = nullptr;
};



#endif //__LIST4_HPP__