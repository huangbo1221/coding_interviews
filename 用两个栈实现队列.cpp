#include<iostream>
#include<stack>
using namespace std;

//#define datatype int

template<typename T>
class MyQueue {
public:
	void appendTail(T value);
	void deleteHead();
private:
	stack<T> stack1;
	stack<T> stack2;//当做队列
};

template<typename T>
void MyQueue<T>::appendTail(T value) {
	if (stack2.size() == 0) {
		stack2.push(value);
		return;
	}
	while (!stack2.empty()) {
		stack1.push(stack2.top());
		stack2.pop();
	}
	stack1.push(value);
	while (!stack1.empty()) {
		stack2.push(stack1.top());
		stack1.pop();
	}
}

template<typename T>
void MyQueue<T>::deleteHead() {
	if (stack2.empty())
		return;
	else
		stack2.pop();
}

//int main() {
//	MyQueue<int> que;
//	que.appendTail(5);
//	que.appendTail(55);
//	que.appendTail(3);
//	que.appendTail(0);
//	que.appendTail(10);
//	return 0;
//}