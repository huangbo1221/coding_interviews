#include<iostream>
#include<vector>
using namespace std;


//题目描述
//输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假
//设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入
//前序遍历序列{ 1,2,4,7,3,5,6,8 }和中序遍历序列{ 4,7,2,1,5,3,8,6 }，
//则重建二叉树并返回。


typedef int datatype ;
struct TreeNode
{
	datatype val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(datatype x) {
		val = x;
		left = NULL;
		right = NULL;
	}
};

TreeNode* reConstructBinaryTree(vector<datatype> pre, vector<datatype> vin) {
	int vin_len = vin.size();
	if (vin_len == 0)
		return NULL;
	vector<datatype> pre_left, vin_left, pre_right, vin_right;
	TreeNode* root = new TreeNode(pre[0]);
	int index = 0;
	for (int i = 0; i < vin_len; ++i)
	{
		if (pre[0] == vin[i])
		{
			index = i;
			break;
		}
		else
		{
			pre_left.push_back(pre[i+1]);
			vin_left.push_back(vin[i]);
		}
	}
	for (int j = index + 1; j < vin_len; ++j)
	{
		pre_right.push_back(pre[j]);
		vin_right.push_back(vin[j]);
	}
	root->left = reConstructBinaryTree(pre_left, vin_left);
	root->right = reConstructBinaryTree(pre_right, vin_right);
	return root;
}