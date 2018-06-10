#include "stdafx.h"
#include<string.h>
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<iomanip>
#include<stdio.h>
#include<sstream>
using namespace std;
vector<int>prefectScore(6,0);										//记录每道题总分

struct Score
{
	int num,passNum,totalScore,rank;
	bool flag;
	vector<int>score;
	Score(int n) :score(n, -1) { num = passNum = flag = 0; totalScore = -1; };
	void set(int n, int pro, int s); 
	bool operator<(const Score &a)
	{
		if (totalScore != a.totalScore)
			return totalScore > a.totalScore;
		else if (passNum != a.passNum)
			return passNum > a.passNum;
		else
			return num < a.num;
	}
};
void Score::set(int n, int pro, int s)
{ 
	num = n; 
	if (s >= 0)
		flag = 1;
	if (totalScore < 0)
		totalScore = 0;
	if (score[pro - 1] < 0)
		score[pro - 1] = 0;
	if (score[pro-1]!=prefectScore[pro]&&score[pro - 1] < s)	//更新分数
	{
		if(s==prefectScore[pro])
			passNum++;
		totalScore -= score[pro - 1];
		totalScore += s;
		score[pro - 1] = s;
	}
};


int main()
{
	int n, m, k,num,problem,score,last=1;
	cin >> n >> k >> m;

	vector<Score>stuMes(n + 1, k);
	for (int i = 0; i < k; i++)
		cin >> prefectScore[i+1];

	for (int i = 0; i < m; i++)
	{
		cin >> num >> problem >> score;
		stuMes[num].set(num, problem, score);
	}

	sort(stuMes.begin(), stuMes.end());

	stuMes[0].rank = 1;
	for (int i = 1; i <= n; i++)
	{
		if (stuMes[i - 1].totalScore == stuMes[i].totalScore)
			stuMes[i].rank = stuMes[i - 1].rank;
		else
		{
			stuMes[i].rank = i+1;
		}
	}


	/*输出结果*/
	for (auto &i : stuMes)
	{
		if (!i.flag)
			break;
		printf("%d %05d %d", i.rank,i.num, i.totalScore);
		for (auto &x : i.score)
			if (x >= 0)
				printf(" %d", x);
			else
				printf(" -");
		//cout << ' '<<i.passNum;
		printf("\n");
	}
	
	
	system("pause");
	return 0;
}

