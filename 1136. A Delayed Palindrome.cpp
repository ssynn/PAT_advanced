#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string Add(string a, string b)
{
	int len = a.size();
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	a.push_back('0');
	for(int i=0;i<len;i++)
	{
		a[i] += (b[i] - '0');
		if (a[i] > '9')
		{
			a[i] -= 10;
			a[i + 1]++;
		}
	}
	if (a.back() == '0')
		a.pop_back();
	reverse(a.begin(), a.end());
	return a;
}

bool If(string &a)
{
	string b = a;
	reverse(b.begin(), b.end());
	return a == b;
}

int main()
{
	int cnt = 0,flag=0;
	string val;
	cin >> val;
	
	for(;cnt<10;cnt++)
	{
		if (If(val))
		{
			flag = 1;
			break;
		}
		string temp;
		temp = val;
		reverse(temp.begin(), temp.end());
		cout << val << " + " << temp << " = ";
		val = Add(val, temp);
		cout << val<<endl;
		
	}

	if (flag)
		cout << val << " is a palindromic number.";
	else
		cout << "Not found in 10 iterations.";
	

	system("pause");
	return 0;
}