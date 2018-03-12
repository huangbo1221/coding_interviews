#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define datatype int

struct TreeNode
{
	datatype value;
	TreeNode *left;
	TreeNode *right;
	TreeNode(datatype x) {
		value = x;
		left = NULL;
		right = NULL;
	}
};

class List {
public:
	List() { root = NULL; }
	void insert(datatype x);//���뺯��
	TreeNode* getHeadPointer();//ȡ��ͷָ��
	void preOrderTraverse(TreeNode * node);//ǰ�����
	void inOrderTraverse(TreeNode * node);//�������
	void postOrderTraverse(TreeNode * node);//�������
	bool deleteNode(datatype key);//ɾ��ĳ��Ԫ��
	void Mirror(TreeNode *pRoot);//�������ľ���
	bool isSubTree(TreeNode* pRoot1, TreeNode* pRoot2);//�ж��Ƿ��Ǹö�����������
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2);//�ж������ӽṹ
	vector<datatype> PrintFromTopToBottom(TreeNode* root);//�������
	int treeDepth(TreeNode *root);//�������
	//����һ�Ŷ�������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����·����
	//��Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
	void findSubPath(TreeNode *root, datatype total_sum,vector<vector<datatype>> &res, vector<datatype> &tmp);//
	bool judgePostOrder(vector<datatype> array, int index1, int index2);//�ж�һ�������Ƿ���ĳ���������ĺ����������
private:
	TreeNode * root;
};

void List::insert(datatype x)
{
	if (root == NULL)
		root = new TreeNode(x);
	else
	{
		TreeNode *p = root;
		TreeNode *q = NULL;
		bool flag = true;
		while(p)
		{
			if (x < p->value)
			{
				q = p;
				p = p->left;
				flag = true;
			}
			else {
				q = p;
				p = p->right;
				flag = false;
			}
		}
		if (flag)
			q->left = new TreeNode(x);
		else
			q->right = new TreeNode(x);
	}
}

TreeNode* List::getHeadPointer() {
	return root;
}

void List::preOrderTraverse(TreeNode * node) {
	if (node == NULL)
		return;
	cout << node->value << ' ';
	preOrderTraverse(node->left);
	preOrderTraverse(node->right);
}

void List::inOrderTraverse(TreeNode * node) {
	if (node == NULL) {
		return;
	}
	inOrderTraverse(node->left);
	cout << node->value << ' ';
	inOrderTraverse(node->right);
}

void List::postOrderTraverse(TreeNode * node) {
	if (node == NULL)
		return;
	postOrderTraverse(node->left);
	postOrderTraverse(node->right);
	cout << node->value << ' ';
}

bool List::deleteNode(datatype key) {
	if (root == NULL)
	{
		cout << "����Ϊ��!" << endl;
		exit;
	}
	TreeNode *p = root;
	TreeNode *q = NULL;
	bool flag = true;//������־Ҫɾ���Ľڵ���q���ҽڵ㻹����ڵ�
	while (p)
	{
		if (p->value == key)
			break;
		else if (p->value > key)
		{
			q = p;
			p = p->left;
			flag = true;
		}
		else
		{
			q = p;
			p = p->right;
			flag = false;
		}
	}
	if (p)
	{
		if (p->right == NULL && p->left == NULL && flag)
		{
			q->left = NULL;
			delete(p);
		}
		else if (p->right == NULL && p->left == NULL && !flag) {
			q->right = NULL;
			delete(p);
		}
		else if (p->right == NULL && p->left)
		{
			if (flag)
			{
				q->left = p->left;
				delete(p);
			}
			else {
				q->right = p->left;
				delete(p);
			}
		}
		else if (p->right && p->left == NULL)
		{
			if (flag)
			{
				q->left = p->right;
				delete(p);
			}
			else {
				q->right = p->right;
				delete(p);
			}
		}
		else {
			TreeNode *tmp = NULL;//����ָ��Ҫɾ���Ľڵ�
			TreeNode *tmp2 = p->right;
			TreeNode *tmp3 = p;//ɾ���ڵ��ָ��ýڵ��ָ��Ҫ��ֵΪNULL��������������tmp3����ɾ���ڵ�ĸ��ڵ�
			int index = 0;
			while (tmp2)
			{
				index++;
				if (index > 1) {
					tmp3 = tmp;
					tmp = tmp2;
					tmp2 = tmp2->left;
				}
				else{
					tmp = tmp2;
					tmp2 = tmp2->left;
				}
				
			}
			if (index > 1) {
				p->value = tmp->value;
				delete(tmp);
				tmp3->left = NULL;
			}
			else
			{
				p->value = tmp->value;
				delete(tmp);
				tmp3->right = NULL;
			}
		}
		return true;
	}
	else {
		cout << "�����ڸýڵ㣡" << endl;
		return false;
	}
}

void List::Mirror(TreeNode *pRoot) {
	if (pRoot == NULL)
		return;
	else {
		TreeNode *tmp = pRoot->left;
		pRoot->right = pRoot->left;
		pRoot->left = tmp;
		Mirror(pRoot->left);
		Mirror(pRoot->right);
	}
}

bool List::isSubTree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot2 == NULL)
		return true;
	if (pRoot1 == NULL)
		return false;
	if (pRoot1->value == pRoot2->value)
		return isSubTree(pRoot1->left, pRoot2->left) && isSubTree(pRoot1->right, pRoot2->right);
	else {
		return false;
	}
}

bool List::HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
	if (!pRoot1 || !pRoot2)
		return false;
	return isSubTree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
}

int List::treeDepth(TreeNode *root) {
	if (root == NULL)
		return 0;
	return max(treeDepth(root->left) + 1, treeDepth(root->right) + 1);
}

vector<datatype> List::PrintFromTopToBottom(TreeNode* root) {
	vector<datatype> res;
	if (!root)
		return res;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		TreeNode *tmp = q.front();
		q.pop();
		if (!tmp) {
			continue;
		}
		q.push(tmp->left);
		q.push(tmp->right);
		res.push_back(tmp->value);
	}
	return res;
}

void List::findSubPath(TreeNode *root, datatype total_sum, vector<vector<datatype>> &res, vector<datatype> &tmp) {
	if (root == NULL)
		return;
	tmp.push_back(root->value);
	if (total_sum == root->value && !root->left && !root->right)
		res.push_back(tmp);
	else {
		if (root->left)
			findSubPath(root->left, total_sum - root->value,res,tmp);
		if (root->right)
			findSubPath(root->right, total_sum - root->value,res,tmp);
	}
	tmp.pop_back();
}

bool List::judgePostOrder(vector<datatype> array, int index1, int index2) {
	int length = array.size();
	if (length == 0 || index1 < 0 || index2 >length - 1 || index1 > index2)
		return false;
	if (index1 == index2)
		return true;
	int i = index2,j;
	while (i >= 0 && array[i] >= array[index2])
		--i;
	j = i;
	while (i >= 0 && array[i] < array[index2])
		--i;
	if (i < 0)
		return judgePostOrder(array,index1,j) && judgePostOrder(array,j+1,index2);
	else
		return false;
}

//int main()
//{
//	List L = List();
//	vector<datatype> res = { 3,2,3,4,5 };
//	bool r = L.judgePostOrder(res, 0, 4);
//	L.insert(62);
//	L.insert(88);
//	L.insert(58);
//	L.insert(47);
//	L.insert(35);
//	L.insert(73);
//	L.insert(51);
//	L.insert(99);
//	L.insert(37);
//	L.insert(93);
//	TreeNode * head = L.getHeadPointer();
//	vector<vector<datatype>> res;
//	vector<datatype> tmp;
//	L.findSubPath(head, 239, res, tmp);
//	L.preOrderTraverse(head);
//	cout << endl;
//	L.inOrderTraverse(head);
//	cout << endl;
//	L.postOrderTraverse(head);
//	cout << endl;
//	L.deleteNode(100);
//	L.inOrderTraverse(head);
//	cout << endl;
//	return 0;
//}
//
