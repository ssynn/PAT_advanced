
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<iomanip>
#include<queue>
using namespace std;

struct message
{
	string a, b;
	int flag;
};
int main()
{
	
	int n,k=0;
	cin >> n;
	vector<message>dat(n);
	for (int i = 0; i < n; i++)
	{
		int flag = 0;
		cin >> dat[i].a >> dat[i].b;
		for (int j = 0; j < dat[i].b.length(); j++)
		{

			if (dat[i].b[j] == '1')
			{
				dat[i].flag = 1;
				dat[i].b[j] = '@';
				flag = 1;
			}
			if (dat[i].b[j] == 'l')
			{
				flag = 1;
				dat[i].b[j] = 'L';
				dat[i].flag = 1;

			}
			if (dat[i].b[j] == '0')
			{
				flag = 1;
				dat[i].b[j] = '%';
				dat[i].flag = 1;

			}
			if (dat[i].b[j] == 'O')
			{
				flag = 1;
				dat[i].b[j] = 'o';
				dat[i].flag = 1;
			}
		}
		if (flag)
			k++;
	}

	if (k >0)
	{
		cout << k << endl;
		for (int i = 0; i < n; i++)
			if(dat[i].flag)
				cout << dat[i].a << ' ' << dat[i].b << endl;
	}
	else
	{
		cout << "There ";
		if (n == 1)
			cout << "is " << n << " account and no account is modified";
		else
			cout << "are " << n << " accounts and no account is modified";
		
	}

	system("pause");
	return 0;
}