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
		if (ch == 'P')				//ͳ��p�ĸ���
			++p;
		else if (ch == 'A')			//ͳ��PA�ĸ���
			c += p;
		else if (ch == 'T')			//ͳ��PAT�ĸ���
			cnt = (cnt + c) % MOD;
	}
	cout << cnt;
	return 0;
}