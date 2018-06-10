#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

int main()
{ 
	int n;
	vector<bool>ans;

	char val[2][4] = { "NO","YES" };
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		
		int k,temp;
		bool flag = 1;
		cin >> k;
		vector<bool>line(k * 2 + 1, 0), cow(k + 1, 0);
		map<int, bool>line2;

		for(int j=1;j<=k;j++)
		{
			cin >> temp;
			if (cow[temp])
				flag = 0;
			if (line[temp + j])
				flag = 0;
			if (line2[temp - j])
				flag = 0;
			cow[temp] = 1;
			line[temp + j] = 1;
			line2[temp - j] = 1;
		}
		ans.push_back(flag);
	}
	for (int i=0;i<ans.size();i++)
		cout << val[ans[i]] << endl;

	system("pause");
	return 0;
}