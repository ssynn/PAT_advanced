#include"stdafx.h"
#include<iostream>
#include<string>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int personNum = 0;
vector<string>nameList;
struct Node
{
	int n, weight;
	string name;
	Node *next;
};
struct Data
{
	int pointNum, weight, head;
	string name;
};
struct Point
{
	int a, b, weight;
};
struct Road
{
	int length;
	bool flag;
};
void DFS(vector<vector<int>> &G, int i, Data &date, vector<bool> &V, vector<int> &weight, vector<vector<bool>> &VG)
{
	//cout << i << ' ';
	V[i] = 1;
	date.pointNum++;

	for (int j = 1; j <= personNum; j++)
	{
		weight[i] += G[i][j];														//求每个点的权重
		if (V[j] == 0 && G[i][j])														//如果未访问则访问
		{
			date.weight += G[i][j];
			VG[i][j] = 1;
			VG[j][i] = 1;
			DFS(G, j, date, V, weight, VG);
		}
		else if (G[i][j] && VG[i][j] == 0)															//如果两点存在路径但不访问则如临时队列		
		{
			date.weight += G[i][j];
			VG[i][j] = 1;
			VG[j][i] = 1;
		}
	}
	if (weight[i]>weight[date.head])												//本节点与已经找到最大节点权重比较
		date.head = i;
}

void display(vector<vector<int>> &a)
{
	cout << endl << '\t';
	for (int i = 0; i < a[0].size() - 1; i++)
		cout << nameList[i] << '\t';
	cout << endl;
	for (int i = 1; i < a[0].size(); i++)
	{
		cout << nameList[i - 1] << '\t';
		for (int j = 1; j < a[0].size(); j++)
			cout << a[i][j] << '\t';
		cout << endl;
	}
}
bool cmp(Data a, Data b)
{
	return a.name < b.name;
}
int main()
{
	map<string, int>namePoint;
	int n, k, weight;
	string name1, name2;
	cin >> n >> k;

	vector<Point>ss;

	//vector<Node>Graph(1);															//存放邻接表												
	for (int i = 0; i<n; i++)														//输入姓名并建立邻接表
	{
		cin >> name1 >> name2 >> weight;
		Point k;
		if (namePoint[name1] == 0)													//将每一个名字映射为一个整数
		{
			personNum++;
			namePoint[name1] = personNum;											//统计人数并给每个人编号
			nameList.push_back(name1);
		}
		if (namePoint[name2] == 0)													//同上
		{
			personNum++;
			namePoint[name2] = personNum;
			nameList.push_back(name2);
		}

		k.a = namePoint[name1];
		k.b = namePoint[name2];
		k.weight = weight;
		ss.push_back(k);
	}
	/*
		for (int i = 0; i <n; i++)
		cout << ss[i].a << ' ' << ss[i].b << ' ' << ss[i].weight << endl;
	*/



	Road empty = { 0,0 };
	vector<vector<int>>G(personNum + 1, vector<int>(personNum + 1, 0));
	vector<vector<bool>>VG(personNum + 1, vector<bool>(personNum + 1, 0));
	for (int i = 0; i < n; i++)											//建立二维邻接表存入路权
	{
		G[ss[i].a][ss[i].b] += ss[i].weight;
		G[ss[i].b][ss[i].a] += ss[i].weight;
	}
	//display(G);



	vector<bool>visited(personNum + 1, 0);										//存放节点访问信息
	vector<int>weightPoint(personNum + 1, 0);										//存放节点权重信息
	vector<Data>data;															//存放最大连通子图信息
	for (int i = 1; i <= personNum; i++)
	{
		if (visited[i] == 0)
		{
			visited[i] = 1;
			Data result = { 0,0,i };
			DFS(G, i, result, visited, weightPoint, VG);
			result.name = nameList[result.head - 1];
			//cout << endl << result.head << ' ' << result.weight << ' ' << result.pointNum << endl;
			if (result.weight>k && result.pointNum>2)
				data.push_back(result);											//将找到合法的最大连通子图信息存入data数组
		}
	}
/*
	for (int i = 1; i <= personNum; i++)
		cout << nameList[i - 1] << ' ' << weightPoint[i] << endl;
*/



	sort(data.begin(), data.end(), cmp);
	cout << data.size() << endl;
	if (data.size())
		for (int i = 0; i<data.size(); i++)
			cout << nameList[data[i].head - 1] << ' ' << data[i].pointNum << endl;

	system("pause");
	return 0;
}


/*


*/


//二维邻接表存点
/*
Node *res;
if (namePoint[name1] == 0)													//将每一个名字映射为一个整数
{
personNum++;
namePoint[name1] = personNum;											//统计人数并给每个人编号
Node temp;
temp.name = name1;
temp.next = NULL;
temp.n = personNum;
Graph.push_back(temp);													//有新人发现则Graph长度加一
}


if (namePoint[name2] == 0)													//同上
{
personNum++;
namePoint[name2] = personNum;
Node temp;
temp.name = name2;
temp.next = NULL;
temp.n = personNum;
Graph.push_back(temp);
}

res = FindNode(Graph[namePoint[name1]], namePoint[name2]);					//查找结点是否已经存在
if (res)
{
res->weight += weight;
}
else
{
Node *a = new Node, *b = new Node;										//建立边节点
a->name = name1;														//输入边节点信息
a->n = namePoint[name1];
a->next = Graph[namePoint[name2]].next;
a->weight = weight;
Graph[namePoint[name2]].next = a;										//将边节点插入邻接表

b->name = name2;														//同上
b->n = namePoint[name2];
b->next = Graph[namePoint[name1]].next;
b->weight = weight;
Graph[namePoint[name1]].next = b;
}


Node* FindNode(const Node &t,int i)
{
Node *p = t.next;
while (p)
{
if (p->n == i)
return p;
}
return NULL;
}
*/