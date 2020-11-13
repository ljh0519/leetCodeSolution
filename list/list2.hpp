#ifndef __LIST2_HPP__
#define __LIST2_HPP__

#include "listCreater.hpp"
#include "solution.hpp"

//交换链表相邻节点
// 1 -> 2 -> 3 -> 4
// 2 -> 1 -> 4 -> 3
//note : 交换节点，而不是只交换其值
class SolutionList2 : public Solution{
public:
    virtual void solution() override {
		list_ = ListCreater::generateNewList({1,2,3,4});

		list_ = (ListNode*)timer_.calc([this]() -> void* {
			return swapPairs(list_);
		});
    }

    virtual void dump() override {
		ListCreater::dump(list_);
        timer_.dump();
    }
    
	ListNode* swapPairs(ListNode* head) {
        if(!head) {
            return nullptr;
        }

        ListNode* first = head;
        ListNode* pre = nullptr;
        for(auto now = head, next = head->next; nullptr != now && nullptr != next; ) {
            ListNode* next2 = next->next;
            if(!pre) {
                pre = now;
                first = next;
            } else {
                pre->next = next;
            }
            now->next = next2;
            next->next = now;
            if(!next2) {
                break;
            }           
            now = next2;
            next = next2->next;
        }
        return first;
	}
private:
	ListNode* list_ = nullptr;
};


#endif //__LIST2_HPP__