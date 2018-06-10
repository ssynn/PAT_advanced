#include"stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<string>
#include<string.h>
#include<list>
using namespace std;
int level = 2000,n, m;;
struct Node
{
	int data, i,l;
};

void Range1(list<Node> &orig, list<Node>::iterator &head,list<Node>::iterator &back,list<Node> &ans)	
{
	if (head == back)
	{
		ans.push_back(*head);
		return;
	}
	list<Node>temp;
	//cout << 555;
	list<Node>::iterator max,p,last,t;
	
	last = back;
	last++;
	p=max = head;
	int i = 0,cnt=0;
	while (p!=last)
	{
		cnt = 0;
		
		while (p!=last&&cnt < m)
		{
			if (p->data > max->data)
				max = p;
			p++;
			cnt++;
		}
		max->l--;
		i++;
		temp.push_back(*max);
		orig.erase(max);
		max = p;
	}
	t = temp.end();
	t--;
	max = temp.begin();
	Range1(temp,max,t,ans);
	ans.insert(ans.end(), orig.begin(),orig.end());

}
int main()
{
	int k;
	list<Node>ans;
	list<Node>origin;
	Node temp;

	cin >> n >> m;
	vector<Node>val(n);
	vector<int>rangeList(n);

	for (int i = 0; i < n; i++)
	{
		cin >> val[i].data;
		val[i].l = level;
	}

	for (int i=0;i<n;i++)
	{
		cin >> k;
		temp = val[k];
		temp.i = k;
		origin.push_back(temp);
	}
	list<Node>::iterator it,p;
	it = origin.end();
	it--;
	p = origin.begin();
	Range1(origin, p, it,ans);

	it = ans.begin();
	int i,last=-1,cnt=0;
	while (it != ans.end())
	{
		if (last == it->l)
		{
			rangeList[it->i] = i;
		}
		else
		{
			i = cnt+1;
			rangeList[it->i] = i;
			last = it->l;
		}
		//cout << it->data << ' ' << it->i << ' ' << it->l << endl;
		it++;
		cnt++;
	}

	for (int i = 0; i < n-1; i++)
		cout << rangeList[i] << ' ';
	cout << rangeList[n - 1];
	system("pause");
	return 0;
}
