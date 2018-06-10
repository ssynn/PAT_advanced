#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

bool flag = 0;
vector<int>pre, in;

void Create(int p1, int p2, int i1, int i2)
{
	//cout << p1 << ' ' << p2 << endl;
	if (flag)
		return;
	if (p1 > p2)
		return;
	int leftSize = 0;
	for(int i=i1;i<=i2;i++)
		if (pre[p1] == in[i])
		{
			leftSize = i-i1;
			break;
		}
	Create(p1 + 1, p1 + leftSize, i1, i1+leftSize - 1);
	Create(p1 + leftSize + 1, p2,i1+leftSize+1, i2);
	if (!flag)
	{
		cout << pre[p1];
		flag = 1;
	}

}

int main()
{
	int n;
	cin >> n;
	pre.resize(n);
	in.resize(n);
	for (auto &i : pre)cin >> i;
	for (auto &i : in)cin >> i;
	Create(0, n - 1, 0, n - 1);
	system("pause");
	return 0;
}
