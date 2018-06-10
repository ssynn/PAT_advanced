#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct Node
{
	int data, cnt;
	Node(int a, int b) {
		data = a;
		cnt = b;
	}


	bool operator<(Node &a)
	{
		if (cnt != a.cnt)
			return cnt > a.cnt;
		else
			return data < a.data;
	}
};

bool operator==(const Node &a,const Node &b)
{
	return (b.data == a.data&&b.cnt == a.cnt);
}


class QList
{
public:
	QList(int n, int k):list(),map(n + 1, 0)
	{
		maxSize = k;
	}

	void Insert(int a)
	{
		map[a]++;

		for(auto &i:list)
			if (i.data==a)
			{
				i.cnt++;
				sort(list.begin(), list.end());
				return;
			}
		Node temp = Node(a, map[a]);
		list.push_back(temp);
		sort(list.begin(), list.end());
		
		if(list.size() > maxSize)
			list.pop_back();
	}


	void Display()
	{
		for (int i = 0; i < list.size(); i++)
			cout << ' ' << list[i].data;
		cout << endl;
	}

	vector<int>map;
	vector<Node>list;
	int maxSize;
};

int main()
{
	int n, k,t;
	cin >> n >> k;
	QList val = QList(n,k);
	cin >> t;
	val.Insert(t);

	while (--n)
	{
		cin >> t;
		cout << t << ':';
		val.Display();
		val.Insert(t);
	}

	system("pause");
	return 0;
}
