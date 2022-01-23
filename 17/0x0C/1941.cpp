// 문제
// 총 25명의 여학생들로 이루어진 여학생반은 5×5의 정사각형 격자 형태로 자리가 배치되었고, 얼마 지나지 않아 이다솜과 임도연이라는 두 학생이 두각을 나타내며 다른 학생들을 휘어잡기 시작했다. 곧 모든 여학생이 ‘이다솜파’와 ‘임도연파’의 두 파로 갈라지게 되었으며, 얼마 지나지 않아 ‘임도연파’가 세력을 확장시키며 ‘이다솜파’를 위협하기 시작했다.

// 위기의식을 느낀 ‘이다솜파’의 학생들은 과감히 현재의 체제를 포기하고, ‘소문난 칠공주’를 결성하는 것이 유일한 생존 수단임을 깨달았다. ‘소문난 칠공주’는 다음과 같은 규칙을 만족해야 한다.

// 이름이 이름인 만큼, 7명의 여학생들로 구성되어야 한다.
// 강한 결속력을 위해, 7명의 자리는 서로 가로나 세로로 반드시 인접해 있어야 한다.
// 화합과 번영을 위해, 반드시 ‘이다솜파’의 학생들로만 구성될 필요는 없다.
// 그러나 생존을 위해, ‘이다솜파’가 반드시 우위를 점해야 한다. 따라서 7명의 학생 중 ‘이다솜파’의 학생이 적어도 4명 이상은 반드시 포함되어 있어야 한다.
// 여학생반의 자리 배치도가 주어졌을 때, ‘소문난 칠공주’를 결성할 수 있는 모든 경우의 수를 구하는 프로그램을 작성하시오.

// 입력
// 'S'(이다‘솜’파의 학생을 나타냄) 또는 'Y'(임도‘연’파의 학생을 나타냄)을 값으로 갖는 5*5 행렬이 공백 없이 첫째 줄부터 다섯 줄에 걸쳐 주어진다.

// 출력
// 첫째 줄에 ‘소문난 칠공주’를 결성할 수 있는 모든 경우의 수를 출력한다.

// #include <iostream>
// #include <algorithm>
// using namespace std;

// int ans;
// string input[5];
// int vis[5][5];

// void solve(int x, int y, int total, int s)
// {
// 	if (x < 0 || x >= 5 || y < 0 || y >= 5 || vis[x][y])
// 		return;
// 	if (total == 7)
// 	{
// 		if (s >= 4)
// 		{
// 			ans++;
// 			for (int i = 0; i < 5; i++)
// 				cout << input[i] << '\n';
// 		}
// 		return;
// 	}
// 	vis[x][y] = 1;
// 	if (input[x][y] == 'Y')
// 	{
// 		input[x][y] = 'y';
// 		solve(x - 1, y, total + 1, s);
// 		solve(x, y - 1, total + 1, s);
// 		solve(x + 1, y, total + 1, s);
// 		solve(x, y + 1, total + 1, s);
// 		input[x][y] = 'Y';
// 	}
// 	if (input[x][y] == 'S')
// 	{
// 		input[x][y] = 's';
// 		solve(x - 1, y, total + 1, s + 1);
// 		solve(x, y - 1, total + 1, s + 1);
// 		solve(x + 1, y, total + 1, s + 1);
// 		solve(x, y + 1, total + 1, s + 1);
// 		input[x][y] = 'S';
// 	}
// 	vis[x][y] = 0;
// }

// int main()
// {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);
// 	for (int i = 0; i < 5; i++)
// 		cin >> input[i];
// 	for(int i = 0; i < 5; i++)
// 	{
// 		for (int j = 0; j < 5; j++)
// 		{
// 			solve(i, j, 0, 0);
// 		}
// 	}
// 	cout << ans;
// }

#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int cmb[25];
string input[5];
int ans;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 5; i++)
		cin >> input[i];
	for (int i = 7; i < 25; i++)
		cmb[i] = 1;
	do
	{
		queue<pair<int, int> > q;
		int s = 0, adj = 0;
		int isp[5][5] = {};
		int vis[5][5] = {};
		for (int i = 0; i < 25; i++)
		{
			if (!cmb[i])
			{
				int x = i / 5;
				int y = i % 5;
				isp[x][y] = 1;
				if (q.empty())
				{
					q.push(make_pair(x, y));
					vis[x][y] = 1;
				}
			}
		}
		while (!q.empty())
		{
			pair<int, int> now = q.front();
			q.pop();
			adj++;
			if (input[now.first][now.second] == 'S')
				s++;
			for (int d = 0; d < 4; d++)
			{
				int nx = now.first + dx[d];
				int ny = now.second + dy[d];
				if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
					continue;
				if (vis[nx][ny] || !isp[nx][ny])
					continue;
				q.push(make_pair(nx, ny));
				vis[nx][ny] = 1;
			}
		}
		if (adj >= 7 && s >= 4)
			ans++;
	}
	while (next_permutation(cmb, cmb + 25));
	cout << ans;
}
