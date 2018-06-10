#include"stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<string>
#include<string.h>
#include<list>
using namespace std;
//排好序扫描就行了
struct Node
{
	char name[9];
	int age, worth;
};
bool cmp(Node &a,Node &b)
{
	return a.age < b.age;
}

bool cmp2(Node &a, Node &b)
{
	if (a.worth != b.worth)
		return a.worth > b.worth;
	else if (a.age != b.age)
		return a.age < b.age;
	int i = strcmp(a.name, b.name);
	if (i < 0)
		return 1;
	else
		return 0;
}
int main()
{
	int n, k,Amin,Amax,qNum,i,j,p,q,cnt,maxAge;
	cin >> n >> k;
	vector<int>ageMap(201, -1);
	vector<Node>val(n);
	//vector<vector<Node>>res(k);
	vector<int>queryNum(k);
	Node temp;
	for (i = 0; i < n; i++)
		scanf_s("%s%d%d", val[i].name,9, &(val[i].age), &(val[i].worth));
	
	sort(val.begin(), val.end(), cmp2);
	for (i = 0; i < k; i++)															//找到位置
	{
		cnt = 0;
		scanf_s("%d%d%d", &qNum, &Amin, &Amax);
		printf("Case #%d:\n", i + 1);
		
		for(int i=0;i<n;i++)
			if (val[i].age >= Amin&&val[i].age <= Amax)
			{
				printf("%s %d %d\n", val[i].name, val[i].age, val[i].worth);
				cnt++;
				if (cnt >= qNum)
					break;
			}	
			if(!cnt)
				printf("None\n");
	

	}


		
	system("pause");
	return 0;
}
//搞得天花乱坠的又慢又复杂
/*
找位置法
for (i = 0; i < k; i++)															//找到位置
{
scanf_s("%d%d%d", &qNum, &Amin, &Amax);
for (j = Amin; ageMap[j] < 0&&j<=200; j++);
if (j <= Amax)
p = ageMap[j];
else
{
ans[i].p = ans[i].q = -1;
continue;
}
for (j = Amax; ageMap[i] < 0; j--);
int t = j;
p = ageMap[j];
cnt = 0;
while (val[p + cnt].age == t)
cnt++;
cnt--;
p += cnt;
sort(val.begin() + p, val.begin() + q, cmp2);

if ((q - p) <= (qNum - 1))
ans[i].p = p, ans[i].q = q;
else
{
ans[i].p = p;
ans[i].q = p + qNum;
}


}
*/