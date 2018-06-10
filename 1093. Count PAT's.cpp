#include<string>
#include<iostream>
using namespace std;
const long long  MOD=1000000007;
int main()
{
	int p=0, a=0, c=0;
	string val;
	long long cnt = 0;
	cin >> val;
	for(auto &ch:val)
	{
		if (ch == 'P')				//统计p的个数
			++p;
		else if (ch == 'A')			//统计PA的个数
			c += p;
		else if (ch == 'T')			//统计PAT的个数
			cnt = (cnt + c) % MOD;
	}
	cout << cnt;
	return 0;
}