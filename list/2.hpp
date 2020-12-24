#ifndef __LIST2_HPP__
#define __LIST2_HPP__

#include "solution.hpp"

//交换链表相邻节点
// 1 -> 2 -> 3 -> 4
// 2 -> 1 -> 4 -> 3
//note : 交换节点，而不是只交换其值
class SolutionList2 : public Solution{
public:	
	~SolutionList2() {
		if(list_) {
			ListNode::free(&list_);
		}
	}

    virtual void solution() override {
		X_SOLUTION_TEST({}, list_ = ListNode::Create({1,2,3,4}));	//2,1,4,3
		// list_ = ListNode::Create({2,5,3,4,6,2,2});	//5,2,4,3,2,6,2


    }

    void test(std::vector<int>&& expect) {
        dumpInput();

		timer_.calc([this]() -> void* {
			list_ = swapPairs(list_);
			return nullptr;
		});

		dumpInput();
        dumpOutput();
        // if(expect != output_) {
        //     std::cout << "expect != output"  << std::endl;
        //     std::cout << "failed test!." << std::endl;
        //     exit(0);
        // }
    }

    virtual void dumpInput() override {
		ListNode::dump(list_);
    }

    virtual void dumpOutput() override {
        timer_.dump();
        std::cout << "###################################################" << std::endl;
    }

	// //4ms     7.8MB
	// ListNode* swapPairs(ListNode* head) {
    //     if(!head) {
    //         return nullptr;
    //     }

    //     ListNode* first = head;
    //     ListNode* pre = nullptr;`
    //     for(auto now = head, next = head->next; nullptr != now && nullptr != next; ) {
    //         ListNode* next2 = next->next;
    //         if(!pre) {
    //             first = next;
    //         } else {
    //             pre->next = next;
    //         }
	// 		pre = now;
    //         now->next = next2;
    //         next->next = now;
    //         if(!next2) {
    //             break;
    //         }           
    //         now = next2;
    //         next = next2->next;
    //     }
    //     return first;
	// }


	ListNode* swapPairs(ListNode* head) {
        if(!head) {
            return nullptr;
        }

		ListNode* first = new ListNode();
		first->next = head;

		ListNode* p1 = first;
		ListNode* p2 = nullptr;
		for(; nullptr != p1->next && nullptr != p1->next->next; ) {
			p2 = p1->next->next->next;
			p1->next->next->next = p1->next;
			p1->next = p1->next->next;
			p1->next->next->next = p2;
			p1 = p1->next->next;
		}
		
		if(first) {
			delete first;
			first = first->next;
		}
		return first; 
	}
private:
	ListNode* list_ = nullptr;
};


#endif //__LIST2_HPP__