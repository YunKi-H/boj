//https://www.acmicpc.net/problem/14891
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

deque<int> gear[6];
int d[5];
int k;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	char c;
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> c;
			gear[i].push_back(c - '0');
		}
		getchar();
	}
	cin >> k;
	while (k--)
	{
		int a, b;
		cin >> a >> b;
		d[a] = b;
		if (a == 1)
		{
			if (gear[1][2] == gear[2][6])
				d[2] = 0;
			else
				d[2] = -d[1];
			if (gear[2][2] == gear[3][6])
				d[3] = 0;
			else
				d[3] = -d[2];
			if (gear[3][2] == gear[4][6])
				d[4] = 0;
			else
				d[4] = -d[3];
		}
		if (a == 2)
		{
			if (gear[1][2] == gear[2][6])
				d[1] = 0;
			else
				d[1] = -d[2];
			if (gear[3][6] == gear[2][2])
				d[3] = 0;
			else
				d[3] = -d[2];
			if (gear[4][6] == gear[3][2])
				d[4] = 0;
			else
				d[4] = -d[3];
		}
		if (a == 3)
		{
			if (gear[2][2] == gear[3][6])
				d[2] = 0;
			else
				d[2] = -d[3];
			if (gear[1][2] == gear[2][6])
				d[1] = 0;
			else
				d[1] = -d[2];
			if (gear[3][2] == gear[4][6])
				d[4] = 0;
			else
				d[4] = -d[3];
		}
		if (a == 4)
		{
			if (gear[3][2] == gear[4][6])
				d[3] = 0;
			else
				d[3] = -d[4];
			if (gear[2][2] == gear[3][6])
				d[2] = 0;
			else
				d[2] = -d[3];
			if (gear[1][2] == gear[2][6])
				d[1] = 0;
			else
				d[1] = -d[2];
		}
		for (int i = 1; i <= 4; i++)
		{
			if (d[i] == 1)
			{
				int tmp = gear[i].back();
				gear[i].pop_back();
				gear[i].push_front(tmp);
			}
			if (d[i] == -1)
			{
				int tmp = gear[i].front();
				gear[i].pop_front();
				gear[i].push_back(tmp);
			}
		}
	}
	cout << gear[1][0] + gear[2][0] * 2 + gear[3][0] * 4 + gear[4][0] * 8;
}
