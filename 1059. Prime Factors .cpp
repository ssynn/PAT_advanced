#include"stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<string>
#include<string.h>
#include<list>
#include<stack>
#include<set>
using namespace std;

inline bool PrimeNum(list<int> &s, int n)
{
	if (n < 4)
		return 1;
	list<int>::iterator it;
	it = s.begin();
	while (it!=s.end())
	{
		if (n%*it == 0)
			return 0;
		it++;
	}
	return 1;
}

int FindNextPrime(list<int> &s,int now)
{
	if (now == 2)
	{
		s.push_back(3);
		return 3;
	}
	now += 2;
	while (!PrimeNum(s,now))
		now += 2;
	s.push_back(now);
	return now;

}

struct Node
{
	int num,cnt;
};

int main()
{
	int k = 2,n,i=0,s;
	list<int>prime;
	Node temp = { 0,0 };
	vector<Node>ans;
	ans.push_back(temp);
	prime.push_back(2);
	cin >> n;
	if (n < 3)
	{
		cout << n << '=' << n;
		return 0;
	}
	s = n;
	while (n!=1)
	{
		if (n%k==0)
		{
			n /= k;
			if (ans[i].num == k)
				ans[i].cnt++;
			else
			{
				temp.num = k;
				temp.cnt=1;
				ans.push_back(temp);
				i++;
			}
		}
		else
			k = FindNextPrime(prime, k);
		//cout << k<<' '<<n<<endl;
	}
	cout <<s<<'=' << ans[1].num;
	if (ans[1].cnt>1)
		cout << '^' << ans[1].cnt;
	for (int i = 2; i < ans.size(); i++)
	{
		cout <<'*'<< ans[i].num;
		if (ans[i].cnt>1)
			cout << '^' << ans[i].cnt;

	}
	system("pause");
	return 0;
}
