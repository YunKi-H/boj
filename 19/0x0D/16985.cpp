// https://www.acmicpc.net/problem/16985
#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int map[5][5][5];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int ans;

void turn(int floor)
{
	int tmp[5][5];

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			tmp[i][j] = map[floor][i][j];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			map[floor][i][j] = tmp[4 - j][i];
}

void solve(int floor)
{
	if (floor >= 5)
		return;
	for (int i = 0; i < 4; i++)
	{
		solve(floor + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				cin >> map[i][j][k];
}
