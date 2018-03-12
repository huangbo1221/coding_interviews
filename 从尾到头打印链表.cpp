#include<iostream>
#include<vector>
#include<stack>
using namespace std;

typedef struct node {
	int val;
	struct node* next;
	node(int x) {
		val = x;
		next = NULL;
	}
}Node;

class Solution {
public:
	vector<int> printListFromTailToHead(Node* head) {
		vector<int> vec;
		Node* p = head;
		while(p != NULL)
		{
			vec.push_back(p->val);
			p = p->next;
		}
		reverse(vec.begin(), vec.end());
		return vec;
	}
};


//int main()
//{
//	//vector<int> vec = { 1,2,3 };
//	//vec.push_back(4);
//	//reverse(vec.begin(), vec.end());
//	vector<int> a;
//	for (int i = 0; i < 4; ++i)
//		a.push_back(i);
//	cout << a.size() << endl;
//	return 0;
//}