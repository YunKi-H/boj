// https://www.acmicpc.net/problem/14499
#include <iostream>
using namespace std;

int n, m, x, y, k;
int map[20][20];
int dice[7];

void roll(int news)
{
	int tmp;
	switch (news)
	{
	case 1:
		tmp = dice[6];
		dice[6] = dice[3];
		dice[3] = dice[1];
		dice[1] = dice[4];
		dice[4] = tmp;
		break;
	case 2:
		tmp = dice[6];
		dice[6] = dice[4];
		dice[4] = dice[1];
		dice[1] = dice[3];
		dice[3] = tmp;
		break;
	case 3:
		tmp = dice[6];
		dice[6] = dice[2];
		dice[2] = dice[1];
		dice[1] = dice[5];
		dice[5] = tmp;
		break;
	case 4:
		tmp = dice[6];
		dice[6] = dice[5];
		dice[5] = dice[1];
		dice[1] = dice[2];
		dice[2] = tmp;
		break;
	}
}

void move(int news)
{
	int nx = x;
	int ny = y;
	if (news == 1)
		ny++;
	if (news == 2)
		ny--;
	if (news == 3)
		nx--;
	if (news == 4)
		nx++;
	if (nx < 0 || nx >= n || ny < 0 || ny >= m)
		return;
	x = nx;
	y = ny;
	roll(news);
	if (map[x][y] == 0)
		map[x][y] = dice[6];
	else
	{
		dice[6] = map[x][y];
		map[x][y] = 0;
	}
	cout << dice[1] << '\n';
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	int input = 0;
	while (k--)
	{
		cin >> input;
		move(input);
	}
}
