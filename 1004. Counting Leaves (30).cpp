
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;
int Level[102] = { 0 }, maxLevel = 0;
struct Child
{
	int self;
	Child *next;
};
struct Node
{
	int num;
	Child *next;
};
void DFS(Node *Tree,int lastLevel,int father)
{
	if (Tree[father].num == 0)
	{
		//cout << father <<' '<< lastLevel << endl;
		Level[lastLevel+1]++;
		if ((lastLevel + 1) > maxLevel)
			maxLevel = lastLevel + 1;
		return;
	}
	else
	{
		Child *p = Tree[father].next;
		while (p!= NULL)
		{
			DFS(Tree,lastLevel+1,p->self);
			p = p->next;
		}
	}
}
int main()
{
	Node Tree[102];
	int n, m, nodeNum, childNum;
	cin >> n >> m;
	for (int i = 0; i < 100; i++)
	{
		Tree[i].next = NULL;
		Tree[i].num = 0;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> nodeNum >> childNum;
		Tree[nodeNum].num = childNum;
		Child *head,*temp = new Child,*p;
		head = temp;
		temp->next = NULL;
		for (int j = 0; j < childNum; j++)
		{
			p = new Child;
			temp->next = p;
			cin >> p->self;
			p->next = NULL;
			temp = p;
		}
		Tree[nodeNum].next = head->next;
	}
	//cout << Tree[1].num;
	DFS(Tree,0,1);
	if (maxLevel > 1)
		cout << 0;
	else
		cout << 1;
	for (int i = 2; i <= maxLevel; i++)
		cout <<' '<< Level[i] ;
	system("pause");
	return 0;
}




