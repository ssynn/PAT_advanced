#include<iostream>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int n,m,s,cnt=0,maxS=0,k;
vector<int>temp;
vector<vector<int>>ans;


int MyPow(int a, int b)
{
	int x = 1;
	while (b--)
		x *= a;
	return x;
}

void DFS(int p,int sum,int num)
{
	//cout << p << ' ' << sum << ' ' << num <<' '<<cnt<< endl;
	if (sum == n)
	{
		if (cnt == m)
		{
			if (num > maxS)
			{
				ans.clear();
				maxS = num;
				ans .push_back(temp);
			}
			else if (num == maxS)
				ans.push_back(temp);
		}
			
		return;
	}
	if (sum >= n || cnt >= m)
		return;

	for (int i = p; i >0; i--)						//从大到小遍历会快不少
	{
		cnt++;
		temp.push_back(i);
		DFS(i, sum + MyPow(i, s), num + i);
		temp.pop_back();
		cnt--;
	}

 }

int main() 
{
	cin >> n >> m >> s;
	k = pow(n, 1.0 / s);
	DFS(k, 0, 0);

	if(ans.size())
	{
		auto i = max_element(ans.begin(), ans.end());
		cout << n << " = ";
	
		auto j = (*i).begin();
		cout << *j << '^'<<s;
		j++;
		for (; j != (*i).end(); j++)
			printf(" + %d^%d", *j, s);
	}
	else
	{
		cout << "Impossible";
	}
	
	system("pause");
	return 0;
}