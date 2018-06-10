#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<list>
#include<stdio.h>
using namespace std;
struct Node
{
	int data;
	Node *leftChild,*rightChild;
};

void Insert(Node *k,int i)
{
	//cout << i;
	
	if (i < k->data&&k->leftChild == NULL)
	{
		Node *p = new Node;
		p->leftChild = NULL;
		p->rightChild = NULL;
		p->data = i;
		k->leftChild = p;
	}
	else if (i >= k->data&&k->rightChild == NULL)
	{
		Node *p = new Node;
		p->leftChild = NULL;
		p->rightChild = NULL;
		p->data = i;
		k->rightChild = p;
	}
		
	else if (i < k->data)
		Insert(k->leftChild, i);
	else
		Insert(k->rightChild, i);
}

void PostOrder(Node *p)
{
	if (p == NULL)
		return;
	PostOrder(p->leftChild);
	PostOrder(p->rightChild);
	cout << p->data << ' ';
}

void Perorder(Node *p, vector<int> &ans)
{
	if (p == NULL)
		return;
	ans.push_back(p->data);
	Perorder(p->leftChild,ans);
	Perorder(p->rightChild, ans);
}

void Reverse(Node *p)
{
	Node *t;
	if (p == NULL)
		return;
	Reverse(p->leftChild);
	Reverse(p->rightChild);
	t = p->leftChild;
	p->leftChild = p->rightChild;
	p->rightChild = t;

}
int main()
{
	int n;
	cin >> n;
	vector<int>origin(n),ans;
	vector<int>::iterator head, last;
	Node *Tree;
	for (int i = 0; i < n; i++)
		cin >> origin[i];
	Tree = new Node;
	Tree->data = origin[0];
	Tree->leftChild = NULL;
	Tree->rightChild = NULL;
	for (int i = 1; i < n; i++)
		Insert(Tree, origin[i]);

	Perorder(Tree, ans);
	if(ans==origin)
	{
		cout << "YES" << endl;
		PostOrder(Tree->leftChild);
		PostOrder(Tree->rightChild);
		cout << Tree->data;
		return 0;
	}
	ans.clear();
	Reverse(Tree);
	Perorder(Tree, ans);
	if (ans == origin)
	{
		cout << "YES" << endl;
		PostOrder(Tree->leftChild);
		PostOrder(Tree->rightChild);
		cout << Tree->data;
	}
	else
		cout << "NO";

	system("pause");
	return 0;
}
