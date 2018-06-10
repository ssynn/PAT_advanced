#include<iostream>
#include<queue>
#include<vector>
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
vector<int>ans;
int n,flag=1;
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

	void level_visit()
	{
		queue<Node*>r;
		r.push(root);
		ans.push_back(root->data);
		while (!r.empty())
		{
			Node *t = r.front();
			if (t->left)
			{
				r.push(t->left);
				ans.push_back(t->left->data);
			}
			else
			{
				if (ans.size() != n)
					flag = 0;
			}
			if (t->right)
			{
				r.push(t->right);
				ans.push_back(t->right->data);
			}
			else
			{
				if (ans.size() != n)
					flag = 0;
			}
			r.pop();
		}
	}

	Node *root;
};

int main()
{

	AVLRree val;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin >> temp;
		val.root = val.insert(temp, val.root);
	}

	val.level_visit();

	cout << val.root->data;
	for (int i = 1; i < ans.size(); i++)
		cout <<' '<< ans[i];
	cout << endl;
	if (flag)
		cout << "YES";
	else
		cout << "NO";
	system("pause");
	return 0;
}
