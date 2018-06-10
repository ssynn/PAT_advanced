
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<iomanip>
#include<queue>
#include<map>
#include<list>
using namespace std;
struct Testees
{
	long long num;
	int  score, r[3];
};
bool cmp(Testees a,Testees b)
{
	if (a.score != b.score)
		return a.score > b.score;
	else
		return a.num < b.num;
}
void Range(vector<Testees> &a,int num,int k)
{
	int i=0, last=-1;
	for (int j = 0; j < num; j++)
	{
		if (a[j].score == last)
			a[j].r[k] = i;
		else
		{
			i = j + 1;
			a[j].r[k] = i;
			last = a[j].score;
		}
	}
}
int main()
{
	int n, k, sum = 0;
	vector<Testees>ans;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		sum += k;
		vector<Testees>temp(k);
		for (int j = 0; j < k; j++)
		{
			cin >> temp[j].num >> temp[j].score;
			temp[j].r[1] = i + 1;
		}

		sort(temp.begin(), temp.end(), cmp);
		Range(temp, k,2);
		ans.insert(ans.end(),temp.begin(),temp.end());
	}

	sort(ans.begin(), ans.end(),cmp);
	Range(ans, sum,0);
	cout << sum<<endl;
	for (int i = 0; i < sum; i++)
		cout <<setfill('0')<<setw(13)<< ans[i].num  << ' ' << ans[i].r[0] << ' ' << ans[i].r[1] << ' ' << ans[i].r[2] << endl;

	system("pause");
	return 0;
}