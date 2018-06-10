#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<stdio.h>
#include<list>
#include<stack>
#include<queue>
using namespace std;

int preOrder[31], inOrder[31];

struct TreeNode
{
	int num;
	TreeNode *leftChild, *rightChild;
};

int FindRoot(int r, int start,int end)
{
	int i = start;
	while (i<=end&&inOrder[i] != r)
		i++;
	//cout << i << ' ';
	return i;
}

TreeNode* CreateTree(int pStart, int pEnd, int iStart, int iEnd)
{
	TreeNode *p = new TreeNode;
	int root = preOrder[pStart],rootIn,leftSize,rightSize;
	
	p->num = root;

	rootIn = FindRoot(root, iStart,iEnd);

	leftSize = rootIn - iStart;
	rightSize = iEnd - rootIn;

	if (leftSize>0)
		p->leftChild = CreateTree(pStart + 1, pStart + leftSize , iStart, rootIn - 1);
	else
		p->leftChild = NULL;

	if (rightSize>0)
		p->rightChild = CreateTree(pStart + leftSize+1, pEnd, rootIn + 1, iEnd);
	else
		p->rightChild = NULL;
	return p;

}

void PostOrder(TreeNode *p)
{
	if (!p)
		return;
	PostOrder(p->leftChild);
	PostOrder(p->rightChild);
	cout << p->num<<' ';
}

int main()
{
	int n,k,temp,j=0,q=0;
	char operate[5];
	cin >> n;
	k = 2 * n;
	stack<int>Po;
	for (int i = 0; i < k; i++)
	{
		cin >> operate; 
		if (operate[1] == 'u')
		{
			cin >> temp;
			preOrder[j] = temp;
			Po.push(temp);
			j++;
		}
		else
		{
			inOrder[q] = Po.top();
			Po.pop();
			q++;
		}
	}

	TreeNode *root = CreateTree(0, n - 1, 0, n - 1);

	PostOrder(root->leftChild);
	PostOrder(root->rightChild);
	cout << root->num;
	system("pause");
    return 0;
}

