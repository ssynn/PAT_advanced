#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<string>
#include<map>
#include<queue>
#include<list>
using namespace std;

vector<int>post, inOrder;
//对每一层进行排序

struct Node
{
	int data,level;
	Node *left, *right;
};

int Find(int begin, int end, int n)
{
	while (begin <= end)
	{
		if (inOrder[begin] == n)
			return begin;
		begin++;
	}
	return -1;
}

Node* Create(int pBegin,int pEnd,int iBegin,int iEnd,int level)
{
	Node *root = new Node;
	root->data = post[pEnd];
	root->left = NULL;
	root->right = NULL;
	root->level = level;

	if (pBegin == pEnd)
		return root;

	int rootP = Find(iBegin, iEnd, post[pEnd]);
	int rightSize = iEnd - rootP;
	if(rightSize)
		root->right = Create(pEnd - rightSize, pEnd - 1, rootP + 1, iEnd,level+1);

	int leftSize = rootP - iBegin;
	if (leftSize)
		root->left = Create(pBegin, pBegin + leftSize - 1, iBegin, rootP - 1,level+1);

	return root;
}
struct Mes
{
	int level, num,data;
	Mes(int a, int b,int c) :level(a), num(b),data(c) {};
	bool operator<(Mes& a)
	{
		if (level != a.level)
			return level < a.level;
		if (level % 2)
			return num < a.num;
		else
			return num > a.num;
	}
};

int main()
{
	int n, cnt = 0;
	cin >> n;
	post.resize(n);
	inOrder.resize(n);
	for (auto &i : inOrder) cin >> i;
	for (auto &i : post) cin >> i;

	Node *root = Create(0, n - 1, 0, n - 1,0);

	vector<Mes>ans;

	queue<Node*>visit;
	visit.push(root);
	while (!visit.empty())
	{
		Node *head = visit.front();
		ans.push_back(Mes(head->level,cnt,head->data));
		if (head->left)
			visit.push(head->left);
		if (head->right)
			visit.push(head->right);
		visit.pop();
		cnt++;
	}
	
	sort(ans.begin(), ans.end());
	cout << ans[0].data;
	for (int i=1;i<n;i++)
		cout << ' ' << ans[i].data;
	
	system("pause");
	return 0;
}




//不建树
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

vector<int>post, inOrder;

int cnt = 0;
struct Mes
{
	int level, num, data;
	Mes(int a, int b, int c) :level(a), num(b), data(c) {};
	bool operator<(Mes& a)
	{
		if (level != a.level)
			return level < a.level;
		if (level % 2)
			return num < a.num;
		else
			return num > a.num;
	}
};
vector<Mes>ans;

void Create(int pBegin,int pEnd,int iBegin,int iEnd,int level)
{
	cnt++;
	ans.push_back(Mes(level,cnt,post[pEnd]));
	
	if (pBegin == pEnd)
		return;

	int rootP = iBegin;
	while (inOrder[rootP] != post[pEnd])
		rootP++;

	int leftSize = rootP - iBegin;
	if (leftSize)
		 Create(pBegin, pBegin + leftSize - 1, iBegin, rootP - 1,level+1);

	int rightSize = iEnd - rootP;
	if(rightSize)
		 Create(pEnd - rightSize, pEnd - 1, rootP + 1, iEnd,level+1);
}

int main()
{
	int n, cnt = 0;
	cin >> n;
	post.resize(n);
	inOrder.resize(n);
	for (auto &i : inOrder) cin >> i;
	for (auto &i : post) cin >> i;

	Create(0, n - 1, 0, n - 1,0);

	sort(ans.begin(), ans.end());
	cout << ans[0].data;
	for (int i=1;i<n;i++)
		cout << ' ' << ans[i].data;
	
	system("pause");
	return 0;
}