// https://www.acmicpc.net/problem/14500
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, ans;
int map[505][505];
//ㅡ
int b1(int x, int y)
{
	int sum = 0;
	for (int i = 0; i < 4; i++)
		sum += map[x][y + i];
	return sum;
}
//ㅣ
int b2(int x, int y)
{
	int sum = 0;
	for (int i = 0; i < 4; i++)
		sum += map[x + i][y];
	return sum;
}
//ㅁ
int b3(int x, int y)
{
	int sum = 0;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			sum += map[x + i][y + j];
	return sum;
}
//ㅜ
int b4(int x, int y)
{
	int sum = 0;
	sum += map[x][y] + map[x][y + 1];
	sum += map[x + 1][y + 1] + map[x][y + 2];
	return sum;
}
//ㅓ
int b5(int x, int y)
{
	int sum = 0;
	sum += map[x][y + 1] + map[x + 1][y];
	sum += map[x + 1][y + 1] + map[x + 2][y + 1];
	return sum;
}
//ㅗ
int b6(int x, int y)
{
	int sum = 0;
	sum += map[x][y + 1] + map[x + 1][y];
	sum += map[x + 1][y + 1] + map[x + 1][y + 2];
	return sum;
}
//ㅏ
int b7(int x, int y)
{
	int sum = 0;
	sum += map[x][y] + map[x + 1][y];
	sum += map[x + 1][y + 1] + map[x + 2][y];
	return sum;
}
//z
int b8(int x, int y)
{
	int sum = 0;
	sum += map[x][y] + map[x][y + 1];
	sum += map[x + 1][y + 1] + map[x + 1][y + 2];
	return sum;
}
//z->90
int b9(int x, int y)
{
	int sum = 0;
	sum += map[x][y] + map[x + 1][y];
	sum += map[x + 1][y + 1] + map[x + 2][y + 1];
	return sum;
}
//z->180
int b10(int x, int y)
{
	int sum = 0;
	sum += map[x][y + 1] + map[x][y + 2];
	sum += map[x + 1][y] + map[x + 1][y + 1];
	return sum;
}
//z->270
int b11(int x, int y)
{
	int sum = 0;
	sum += map[x][y + 1] + map[x + 1][y];
	sum += map[x + 1][y + 1] + map[x + 2][y];
	return sum;
}

int b12(int x, int y)
{
	int sum = 0;
	sum += map[x][y] + map[x][y + 1];
	sum += map[x + 1][y];
	sum += map[x + 2][y];
	return sum;
}

int b13(int x, int y)
{
	int sum = 0;
	sum +=					map[x][y + 1];
	sum +=					map[x + 1][y + 1];
	sum += map[x + 2][y] + map[x + 2][y + 1];
	return sum;
}

int b14(int x, int y)
{
	int sum = 0;
	sum += map[x][y];
	sum += map[x + 1][y];
	sum += map[x + 2][y] + map[x + 2][y + 1];
	return sum;
}

int b15(int x, int y)
{
	int sum = 0;
	sum += map[x][y] + map[x][y + 1];
	sum +=				map[x + 1][y + 1];
	sum +=				map[x + 2][y + 1];
	return sum;
}

int b16(int x, int y)
{
	int sum = 0;
	sum += map[x][y] + map[x][y + 1] + map[x][y + 2];
	sum += 							map[x + 1][y + 2];
	return sum;
}

int b17(int x, int y)
{
	int sum = 0;
	sum += map[x][y];
	sum += map[x + 1][y] + map[x + 1][y + 1] + map[x + 1][y + 2];
	return sum;
}

int b18(int x, int y)
{
	int sum = 0;
	sum += map[x][y] + map[x][y + 1] + map[x][y + 2];
	sum += map[x + 1][y];
	return sum;
}

int b19(int x, int y)
{
	int sum = 0;
	sum += 										map[x][y + 2];
	sum += map[x + 1][y] + map[x + 1][y + 1] + map[x + 1][y + 2];
	return sum;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			ans = max(ans, b1(i, j));
			ans = max(ans, b2(i, j));
			ans = max(ans, b3(i, j));
			ans = max(ans, b4(i, j));
			ans = max(ans, b5(i, j));
			ans = max(ans, b6(i, j));
			ans = max(ans, b7(i, j));
			ans = max(ans, b8(i, j));
			ans = max(ans, b9(i, j));
			ans = max(ans, b10(i, j));
			ans = max(ans, b11(i, j));
			ans = max(ans, b12(i, j));
			ans = max(ans, b13(i, j));
			ans = max(ans, b14(i, j));
			ans = max(ans, b15(i, j));
			ans = max(ans, b16(i, j));
			ans = max(ans, b17(i, j));
			ans = max(ans, b18(i, j));
			ans = max(ans, b19(i, j));
		}
	}
	cout << ans;
}
