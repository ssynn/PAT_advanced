#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Node
{
	int data;
	bool color;
	Node *left, *right;
	Node()
	{
		left = right = NULL;
		color = 0;
	}
};

class RBTree
{
public:
	RBTree() 
	{
		bNum = -1;
		root = NULL;
	}

	Node* insert(Node *p,int a)
	{
		if (p == NULL)
		{
			p = new Node;
			p->data = abs(a);
			if (a > 0)
				p->color = 1;
		}
		else
		{
			if (p->data <= abs(a))
				p->right = insert(p->right, a);
			else
				p->left = insert(p->left, a);
		}
		return p;
	}

	void black_num(bool &flag,Node *p,int num)
	{
		if (p == NULL)
		{
			if (bNum == -1)
				bNum = num;

			if (num != bNum)
				flag = 0;
			return;
		}

		if (p->color == 0)
		{
			if (p->left)
				if (p->left->color == 0)
					flag = 0;
			if (p->right)
				if (p->right->color == 0)
					flag = 0;
		}

		black_num(flag, p->left, num + p->color);
		black_num(flag, p->right, num + p->color);
	}



	bool if_rb()
	{
		bool flag = 1;
		if (root->color == 0)
			return 0;

		black_num(flag, root, 0);


		return flag;
	}

	Node *root;
	int bNum;
};

int main()
{
	int n, m,val;
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		RBTree a;
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> val;
			a.root = a.insert(a.root, val);
		}
		if (a.if_rb())
			cout << "Yes\n";
		else
			cout << "No\n";
	}
		
	system("pause");
	return 0;
}
