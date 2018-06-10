#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<list>
#include<queue>
#include<map>
#include<set>
using namespace std;

struct Node
{
	int data,height;
	Node *left, *right;
	Node()
	{
		left = right = NULL;
		height = 0;
	}

};

class AVLRree
{
public:

	AVLRree()
	{
		root = NULL;
	}

	int get_height(Node *p)
	{
		if (p == NULL)
			return 0;
		return max(get_height(p->left), get_height(p->right)) + 1;
	}

	int get_height()
	{
		return get_height(root);
	}

	Node* LL(Node *p)
	{
		Node *temp = p->left;
		p->left = temp->right;
		temp->right = p;
		p->height = get_height();
		temp->height = get_height();
		return temp;
	}

	Node* RR(Node *p)
	{
		Node *temp = p->right;
		p->right = temp->left;
		temp->left = p;
		p->height = get_height();
		temp->height = get_height();
		return temp;
	}

	Node *LR(Node *p)
	{
		p->left=RR(p->left);
		return LL(p);
	}

	Node* RL(Node *p)
	{
		p->right = LL(p->right);
		return RR(p);
	}

	bool if_balance(Node *p)
	{
		int cnt = get_height(p->left) - get_height(p->right);
		cnt = abs(cnt);
		if (cnt >= 2)
			return 0;
		else
			return 1;
	}

	Node* insert(int a,Node *p)
	{
		
		if (p == NULL)
		{
			p = new Node;
			p->height = 0;
			p->data = a;
		}
		else if (a < p->data)
		{
			p->left = insert(a, p->left);
			if (!if_balance(p))
			{
				if (a < p->left->data)
					p = LL(p);
				else
					p = LR(p);
			}

		}
		else
		{
			p->right = insert(a, p->right);
			if (!if_balance(p))
			{
				if (a > p->right->data)
					p = RR(p);
				else
					p = RL(p);
			}
		}
		return p;
	}

	Node *root;
};

int main()
{
	int n;
	AVLRree val;
	cin >> n;
	while (n--)
	{
		int temp;
		cin >> temp;
		val.root = val.insert(temp, val.root);
	}
	cout << val.root->data;
	system("pause");
	return 0;
}
