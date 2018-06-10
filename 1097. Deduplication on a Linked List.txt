#include"stdafx.h"
#include<iostream>
#include<queue>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<iomanip>
using namespace std;
struct Node
{
	int add, key,nextKey;
	Node(int a, int b, int c) :add(a), key(b), nextKey(c) {  };
	Node() {};
};
struct Node2
{
	int add, key;
	Node2(int a, int b) :add(a), key(b) {  };
};

int main()
{
	int begin, n,add,key,next;
	Node temp;
	map<int, Node>val;
	vector<Node>ans,ans2;
	bool absKey[10005] = {};
	cin >> begin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> add >> key >> next;
		//absKey[abs(key)] = 1;
		val[add] = Node(add, key, next);
	}
	
	while (begin != -1)
	{
		temp= val[begin];
		if (absKey[abs(temp.key)] == 0)
		{
			absKey[abs(temp.key)] = 1;
			ans.push_back(temp);
		}
		else
			ans2.push_back(temp);
		begin = temp.nextKey;
	}

	int len1 = ans.size() - 1, len2 = ans2.size() - 1;
	//cout << len1 << ' ' << len2 << endl;
	for (int i = 0; i < len1; i++)
		cout <<setfill('0')<<setw(5)
		<< ans[i].add << ' '
		<< ans[i].key << ' '
		<< setfill('0') << setw(5)
		<< ans[i + 1].add << endl;
	if(len1>=0)
	cout << setfill('0') << setw(5) 
		<< ans[len1].add << ' '
		<< ans[len1].key <<' '<<-1<<endl;

	for (int i = 0; i < len2; i++)
		cout << setfill('0') << setw(5) 
		<< ans2[i].add << ' '
		<< ans2[i].key << ' '
		<< setfill('0') << setw(5)
		<< ans2[i + 1].add << endl;
	if(len2>=0)
	cout << setfill('0') << setw(5) 
		<< ans2[len2].add << ' '
		<< ans2[len2].key <<' '<< -1;


	system("pause");
	return 0;
}