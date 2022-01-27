//https://www.acmicpc.net/problem/12100
#include <iostream>
#include <algorithm>
using namespace std;

int map1[21][21];
int map2[21][21];
int n, ans;

void turn()
{
	int tmp[21][21];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tmp[i][j] = map2[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			map2[i][j] = tmp[n - 1 - j][i];
}

void tilt(int dir)
{
	while (dir--)
		turn();
	for (int i = 0; i < n; i++)
	{
		int tilted[21] = {};
		int idx = 0;
		for (int j = 0; j < n; j++)
		{
			if (!map2[i][j])
				continue;
			if (!tilted[idx])
				tilted[idx] = map2[i][j];
			else if (tilted[idx] == map2[i][j])
				tilted[idx++] *= 2;
			else
				tilted[++idx] = map2[i][j];
		}
		for (int j = 0; j < n; j++)
			map2[i][j] = tilted[j];
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map1[i][j];
	for (int tmp = 0; tmp < 1024; tmp++)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				map2[i][j] = map1[i][j];
		int brute = tmp;
		for (int i = 0; i < 5; i++)
		{
			int dir = brute % 4;
			brute /= 4;
			tilt(dir);
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				ans = max(ans, map2[i][j]);
	}
	cout << ans;
}
