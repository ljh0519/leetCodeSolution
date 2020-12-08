#ifndef __LIST3_HPP__
#define __LIST3_HPP__

#include "solution.hpp"
// 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
// 认真审题，是反转链表！！！！按k个链表为区间，反转链表
// k 是一个正整数，它的值小于或等于链表的长度。
// 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

// 示例：

// 给你这个链表：1->2->3->4->5
// 当 k = 2 时，应当返回: 2->1->4->3->5
// 当 k = 3 时，应当返回: 3->2->1->4->5
// 当 k = 4 时，应当返回: 4->3->2->1->5
// 说明：
// 你的算法只能使用常数的额外空间。
// 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

class SolutionList3 : public Solution{
public:	
	~SolutionList3() {
		if(list_) {
			ListNode::free(&list_);
		}
	}

    virtual void solution() override {
		// list_ = ListNode::Create({1,2});	//2,1,4,3
        int k = 3;
		// list_ = ListNode::Create({1,2,3});	//3,2,1
		// list_ = ListNode::Create({1,2,3,4});	//3,2,1,4
		// list_ = ListNode::Create({1,2,3,4,5});	//3,2,1,4,5
		// list_ = ListNode::Create({1,2,3,4,5,6});	//3,5,2,2,6,4,2

		list_ = (ListNode*)timer_.calc([this, k]() -> void* {
			return reverseKGroup(list_, k);
		});
    }

    virtual void dump() override {
		ListNode::dump(list_);
        timer_.dump();
    }
    
	// 非递归
    ListNode* reverseKGroup(ListNode* head, int k) {
		if(!head || !head->next) {
			return head;
		}

		ListNode* pre_tail = nullptr;
		ListNode* new_head = nullptr;
		ListNode* first = nullptr;
		ListNode* p1 = head;
		ListNode* p2 = head;
		ListNode* p3 = head;
		while(p3 && p3->next) {
			int n = k;
			p3 = p3->next;
			for(; --n && nullptr != p2 && nullptr != p3; p2 = p2->next, p3 = p3->next) ;
			if(0 != n ) break;
			new_head = reverse(p3, p2, p1);
			if(!first) {
				first = new_head;
			} else {
				pre_tail->next = new_head;
			}
			pre_tail = p1;
			p1 = p3;
			p2 = p3;
		}

		return first;
    }




	// 递归
    // ListNode* reverseKGroup(ListNode* head, int k) {
	// 	if(!head || !head->next) {
	// 		return head;
	// 	}

	// 	return recursion(head, head, head, k);
    // }

	// ListNode* recursion(ListNode* p3, ListNode* p1, ListNode* p2, int k) {
	// 	if(!p1 || !p1->next) {
	// 		return p1;
	// 	}

	// 	int n = k;
	// 	p3 = p3->next;
	// 	for(; --n && nullptr != p2 && nullptr != p3; p2 = p2->next, p3 = p3->next) ;
	// 	if(0 != n ) return p1;

	// 	ListNode* new_head = recursion(p3, p3, p3, k);
	// 	return reverse(new_head, p2, p1);
	// }

	ListNode* reverse(ListNode* tail, ListNode* end, ListNode* head) {
		if(!head || !head->next) {
			return head;
		}

        ListNode* pre = tail;
        ListNode* now = head;
        ListNode* next = head;
        do {
            next = next->next;
            now->next = pre;
            pre = now;
            now = next;
        } while(next && pre != end);

        return pre;
	}
private:
	ListNode* list_ = nullptr;
};



#endif //__LIST3_HPP__