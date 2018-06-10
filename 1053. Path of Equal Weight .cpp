#include"stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<string>
#include<list>
using namespace std;
bool cmp(list<int> &a, list<int> &b)
{
	if (a == b)
		return 0;
	list<int>::iterator it1,it2;
	it1 = a.begin(), it2 = b.begin();
	//cout << *it1 << ' ' << *it2 << endl;
	while (it1!=a.end()&&it2!=b.end()&&*it1 == *it2)
	{
		it1++;
		it2++;
	}

	if (it1 != a.end() && it2 != b.end())
		return *it1 > *it2;
	else if (it1 == a.end() && it2 != b.end())
		return 0;
	else
		return 1;
}
int main()
{
	int n, k, weight,id,childNum,child,pathNum=0;
	cin >>n>> k>>weight;
	vector<int>tree(n,-1),nodeWeight(n,0);					//记录父节点，和点权
	vector<list<int>>path(n - k);							//记录路径
	vector<bool>non_leaf(n,1);								//记录每个结点是否是叶节点
	for (int i = 0; i < n; i++)
		scanf_s("%d", &nodeWeight[i]);

	for (int i = 0; i < k; i++)
	{
		scanf_s("%d%d", &id, &childNum);
		non_leaf[id] = 0;
		for (int i = 0; i < childNum; i++)
		{
			scanf_s("%d", &child);
			tree[child] = id;
			
		}
	}
	for(int i=0;i<n;i++)
		if(tree[i]>=0)
		nodeWeight[i] += nodeWeight[tree[i]];				//记录总点权
	
	if (n == 1)
		if (nodeWeight[0] == weight)
		{
			cout << weight;
			return 0;
		}
	
	

//	for (int i = 0; i < n; i++)
		//cout << nodeWeight[i] << endl;
	for (int i = n - 1; i >= 0; i--)
	{
		if (nodeWeight[i] == weight&&non_leaf[i])
		{
			int p=tree[i],last=weight;
			while (p != -1)									//记录路径
			{

				path[pathNum].push_front(last-nodeWeight[p]);
				last = nodeWeight[p];
				p = tree[p];
			}
			pathNum++;
		}
	}
	list<int>::iterator it;

		sort(path.begin(), path.begin()+pathNum , cmp);
	for (int i = 0; i < pathNum; i++)
	{
		it = path[i].begin();
		printf("%d", nodeWeight[0]);
		for (; it != path[i].end(); it++)
			printf(" %d", *it);
		printf("\n");
	}

	system("pause");
	return 0;
}
