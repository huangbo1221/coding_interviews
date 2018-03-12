#include<iostream>
using namespace std;

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};

class Solution {
public:
	Solution();
	void insertNode(int x);
	ListNode *getHeadPointer();
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2);
	ListNode * FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL)
			return NULL;
		ListNode *p = pListHead;
		int length = 0;
		while (p)
		{
			length++;
			p = p->next;
		}
		if (k > length)
			return NULL;
		int index = 1;
		p = pListHead;
		while (index < length - k + 1)
		{
			p = p->next;
			index++;
		}
		return p;
	}

	ListNode* ReverseList(ListNode* pHead) {//反转链表
		if (pHead == NULL)
			return NULL;
		else if (pHead && pHead->next == NULL)
			return pHead;
		else {
			ListNode *p = pHead->next, *q = pHead, *tmp = p->next;;
			while(tmp)
			{
				if (q == pHead)
					q->next = NULL;
				p->next = q;
				q = p;
				p = tmp;
				tmp = tmp->next;

			}
			if (q == pHead)
				q->next = NULL;
			p->next = q;
			return p;
		}
	}
private:
	ListNode * root;
};


Solution::Solution() {
	root = NULL;
}

void Solution::insertNode(int x) {
	if (root == NULL)
		root = new ListNode(x);
	else {
		ListNode *p = root;
		while (p->next)
			p = p->next;
		p->next = new ListNode(x);
	}
}

ListNode* Solution::getHeadPointer() {
	return root;
}

ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {//链表的融合
	if (pHead1 == NULL)
		return pHead2;
	if (pHead2 == NULL)
		return pHead1;
	if (pHead1->val <= pHead2->val){
		pHead1->next = Merge(pHead1->next, pHead2);
		return pHead1;
	}
	else {
		pHead2->next = Merge(pHead1, pHead2->next);
		return pHead2;
	}
}

//int main()
//{
//	Solution s;
//	s.insertNode(3);
//	s.insertNode(1);
//	s.insertNode(4);
//	s.insertNode(7);
//	s.insertNode(0);
//	s.insertNode(2);
//	s.insertNode(9);
//	ListNode *head = s.getHeadPointer();
//	ListNode *p = s.ReverseList(head);
//	return 0;
//}