#include<iostream>
#include<vector>
using namespace std;

#define datatype int
struct node
{
	datatype value;
	struct node* next;
	node(datatype data){
		value = data;
		next = NULL;
	}
};

class List {
public:
	List();
	void addNode(datatype data);//���ӽ��
	node* getHead();//ȡ��ͷָ��
	int getListLength();//ȡ������ĳ���
	void printListTopToTail();//��ͷ��β��ӡ����
	void printListTailToTop();//��β��ͷ��ӡ����
	void deleteNode(datatype data);//ɾ����㣬ֻɾ�����ȳ��ֵ���һ�����
private:
	node * head;
	int length;
};

List::List() {
	length = 0;
	head = NULL;
}

void List::addNode(datatype data) {
	if (head) {
		node *p = head;
		while (p->next) {
			p = p->next;
		}
		p->next = new node(data);
		++length;
	}
	else
		head = new node(data);
}

node* List::getHead() {
	return head;
}

int List::getListLength() {
	return length;
}

void List::printListTopToTail() {
	if (!head)
		cout << "List is empty!" << endl;
	node *p = head;
	while (p)
	{
		cout << p->value << " ";
		p = p->next;
	}
	cout << endl;
}

void List::printListTailToTop() {
	vector<datatype> vec;
	node *p = head;
	while (p) {
		vec.push_back(p->value);
		p = p->next;
	}
	int length = vec.size();
	for (int i = length - 1; i > -1; --i) {
		cout << vec[i] << " ";
	}
	cout << endl;
}


void List::deleteNode(datatype data) {
	if (!head)
		cout << "List is empty!" << endl;
	node* p = head;
	node* q = head;
	if (head->value == data) {
		head = p->next;
		delete q;
		--length;
		return;
	}
	p = p->next;
	while (p) {
		if (p->value == data) {
			q->next = p->next;
			delete p;
			--length;
			return;
		}
		p = p->next;
		q = q->next;
	}
}

int main() {
	List L;
	L.addNode(5);
	L.addNode(12);
	L.addNode(4);
	L.addNode(0);
	L.addNode(6);
	L.addNode(3);
	L.addNode(3);
	L.printListTopToTail();
	L.printListTailToTop();
	L.deleteNode(3);
	L.printListTopToTail();
	L.deleteNode(5);
	L.printListTopToTail();
	return 0;
}