#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
using namespace std;

struct Node
{
	int data,level;
	Node *left, *right;
};

void Insert(Node *p, int a)
{
	Node *c = new Node,*s,*q;
	c->left = NULL;
	c->right = NULL;
	c->data = a;
	s = p;
	q = s;
	while (s)
	{
		q = s;
		if (s->data < a)
			s = s->right;
		else
			s = s->left;
	}

	c->level = q->level+1;
	if (a <= q->data)
		q->left = c;
	else
		q->right = c;
}
int main()
{
	int n, temp;
	vector<int>ans;
	cin >> n;
	cin >> temp;
	Node *head = new Node;
	head->data = temp;
	head->left = NULL;
	head->right = NULL;
	head->level = 0;

	for (int i = 1; i < n; i++)
	{
		cin >> temp;
		Insert(head, temp);
	}
	
	queue< Node* >level;
	level.push(head);
	while (!level.empty())
	{
		if (level.front()->left)
			level.push(level.front()->left);
		if (level.front()->right)
			level.push(level.front()->right);
		ans.push_back(level.front()->level);
		level.pop();
	}
	sort(ans.begin(), ans.end());
	int n1=count(ans.begin(), ans.end(), ans[n - 1]);
	int n2 = count(ans.begin(), ans.end(), ans[n - 1] - 1);
	cout << n1 << " + " << n2 << " = " << n1 + n2;
	system("pause");
	return 0;
}
