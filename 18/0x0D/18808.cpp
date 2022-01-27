//https://www.acmicpc.net/problem/18808
#include <iostream>
using namespace std;

int n, m, k, r, c, ans;
int map[40][40];
int stk[10][10];

void turn()
{
	int tmp[10][10];

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			tmp[i][j] = stk[i][j];
	for (int i = 0; i < c; i++)
		for (int j = 0; j < r; j++)
			stk[i][j] = tmp[r - 1 - j][i];
	int temp = r;
	r = c;
	c = temp;
}

int isvalid(int x, int y)
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (map[x + i][y + j] && stk[i][j])
				return 0;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (stk[i][j] == 1)
				map[x + i][y + j] = 1;
	return 1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	while (k--)
	{
		cin >> r >> c;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				cin >> stk[i][j];
		for (int t = 0; t < 4; t++)
		{
			int valid = 0;
			for (int i = 0; i <= n - r; i++)
			{
				if (valid)
					break;
				for (int j = 0; j <= m - c; j++)
				{
					if (isvalid(i, j))
					{
						valid = 1;
						break;
					}
				}
			}
			if (valid)
				break;
			turn();
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j])
				ans++;
	cout << ans;
}
