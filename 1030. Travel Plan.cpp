//#include "stdafx.h"
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<vector>
#include<limits.h>
#include<list>
using namespace std;
int i = 1,minDistance=INT_MAX,result;

struct Road
{
	int distance, cost;
};
vector<list<int>>path;
vector<Road>info;
void DFS(vector<vector<Road>> &map, vector<bool> &visited, list<int> &path1, int start, int end, const int &n,int distance=0,int cost=0)
{
	if (start == end)											//����Ŀ�ĵ�,��¼·��
	{
		if(distance<=minDistance)								//·�̸�С�ż�¼
		{

			minDistance = distance;
			Road temp;
			temp.cost = cost;
			temp.distance = distance;
			path.push_back(path1);								//��·��ѹ�붯̬����
			info.push_back(temp);								//����Ӧ����Ϣ����info����
			result = info.size() - 1;
			path1.clear();										//���path1�������¼�¼
			
		}
		return;
	}
	if (distance > minDistance)									//��֦
		return;

	for (int i = 0; i<n; i++)									//���������ڵ�����Ľ��
	{
		if (visited[i] == 0 && map[start][i].distance)
		{
			visited[i] = 1;
			path1.push_back(i);
			DFS(map, visited, path1, i, end, n,distance+map[start][i].distance,cost+map[start][i].cost);
			visited[i] = 0;

		}
	}

}
//int _tmain(int argc, _TCHAR* argv[])
int main()
{
	int n, m, s, d, x, y;
	cin >> n >> m >> s >> d;
	Road a = { 0,0 };
	vector<vector<Road>>map(n, vector<Road>(n, a));
	list<int>::iterator it;
	vector<bool>visited(n,0);
	list<int>path1;
	

	for (int i = 0; i<m; i++)
	{
		cin >> x >> y;
		cin >> map[x][y].distance >> map[x][y].cost;
		map[y][x] = map[x][y];
	}
	visited[s] = 1;
	DFS(map,visited,path1,s,d,n);

	//cout << result <<' '<< minDistance<<endl;

	for (int i = 0; i < path.size(); i++)
	{
		if (info[i].distance == minDistance)
		{
			if (info[i].cost < info[result].cost)
				result = i;
		}
	}
	

	cout << s<<' ';
	it = path[result].begin();
	while (it != path[result].end())
	{
		cout << *it << " ";
		it++;
	}
	cout <<info[result].distance<<' '<< info[result].cost;

	system("pause");
	return 0;
}
/*




printf("�����ƶ��������:\n");

ofstream outfile;
outfile.open("result2.txt",ios::out);

Hanoi(n,x,y,z,outfile);
outfile.close();
*/
