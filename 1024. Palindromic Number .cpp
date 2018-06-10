
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<iomanip>
#include<queue>
#include<map>
#include<list>
using namespace std;

string Add(string s, string rev)
{
	string res = "";
	int k = s.size();
	int sum, carry = 0;
	int i;
	for (i = k - 1; i >= 0; i--)
	{
		sum = s[i] + rev[i] - '0' - '0' + carry;
		res.insert(res.begin(), sum % 10 + '0');
		carry = sum / 10;
	}
	if (carry)res.insert(res.begin(), carry + '0');
	return res;
}

bool JudgePalindromicNumber(string a)
{
	string b = a;
	reverse(a.begin(), a.end());
	if (a == b)
		return 1;
	else
		return 0;
}
int main()
{
	string a,b,temp;
	int n,i;	
	cin >> a>>n;
	for (i = 1; i <= n; i++)
	{
		b = a;
		reverse(b.begin(), b.end());
		temp = Add(a, b);
		a = temp;
		if (JudgePalindromicNumber(temp))
		{
			i++;
			break;
		}
	}
	i--;
	cout << temp << endl << i;
	system("pause");
	return 0;
}