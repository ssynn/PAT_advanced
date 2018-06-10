#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
using namespace std;


//考验并查集的熟练使用
struct Node
{
	int father, num, area, people, min;
	double aveNum, sumArea;
	bool visited;
	Node() {
		father = -1;
		num = 0;
		area = 0;
		people = 1;
		visited = 0;
		min = 10000000;
	}
};
vector<Node>map(10000,Node());

int FindF(int f)
{
	int p = f;
	if (f == -1)
		return -1;
	while (map[f].father != -1)
		f = map[f].father;
	
	return f;
}
void Union(int a, int b)
{
	if (a == -1 || b == -1)
		return;
	a = FindF(a);
	b = FindF(b);
	if (a != b)
		map[b].father = a;
}

bool cmp(Node &a,Node &b)
{
	if (a.sumArea != b.sumArea)
		return a.sumArea > b.sumArea;
	else
		return a.min < b.min;
}
int main()
{
	int n, name, father, mother, child;
	vector<int>nameList;
	vector<Node>ans;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int mf, k;
		cin >> name >> father >> mother >> k;
		if(father!=-1)
			map[father].min=father;
		if (mother != -1)
			map[mother].min = mother;
		mf = FindF(name);

		while (k--)
		{
			cin >> child;
			child = FindF(child);
			map[child].min = child;
			Union(mf, child);
		}

		Union(mf, father);
		Union(mf, mother);

		cin>>map[name].num;
		cin >> map[name].area;
		map[name].min = name;
		nameList.push_back(name);
	}
	for (int i = 0; i < 10000; i++)							//统计每个集合的信息
	{
		int f = i;
		f = FindF(f);
		if (f != i)
		{
			map[f].people++;
			map[f].area += map[i].area;
			map[f].num += map[i].num;
			if (map[i].min < map[f].min)
			{
				map[f].min = map[i].min;
			}
		}
	}
	for (auto &x : nameList)									//记录集合根结点
	{
		if (map[x].father == -1)
		{
			map[x].aveNum = 1.0*map[x].num / map[x].people;
			map[x].sumArea = 1.0*map[x].area / map[x].people;
			ans.push_back(map[x]);
			
		}
	}

	sort(ans.begin(), ans.end(),cmp);
	cout << ans.size() << endl;
	for (auto &i : ans)
	{
		cout <<setfill('0')<<setw(4)<< i.min << ' '
			<< i.people << ' '
			<< fixed << setprecision(3)
			<< i.aveNum<<' '
			<< fixed << setprecision(3)
			<< i.sumArea << endl;
	}
	
	system("pause");
	return 0;
}
/*

for (int i = 0; i < 10000; i++)								//统计人数,房子面积，房子数量
{
if (!map[i].visited)
{
int people = 0, sum = 0, f,min=i,num=0;
f = i;
while (map[f].visited == 0 && map[f].father != -1)
{
if (f < min)
min = f;

map[f].visited = 1;
num += map[f].num;
sum += map[f].area;
people += map[f].people;
f = map[f].father;
}
f = FindF(f);
map[f].num += num;
map[f].people += people;
map[f].area += sum;
if (map[f].min > min)
map[f], min = min;
}
}

cout << endl;
for (auto &i : nameList)
{
cout <<i<<' '<< map[i].father << ' ' << map[i].min << ' ' << map[i].people << ' ' << map[i].num << endl;
}


*/