// 문제
// 지훈이는 미로에서 일을 한다. 지훈이를 미로에서 탈출하도록 도와주자!

// 미로에서의 지훈이의 위치와 불이 붙은 위치를 감안해서 지훈이가 불에 타기전에 탈출할 수 있는지의 여부, 그리고 얼마나 빨리 탈출할 수 있는지를 결정해야한다.

// 지훈이와 불은 매 분마다 한칸씩 수평또는 수직으로(비스듬하게 이동하지 않는다)  이동한다.

// 불은 각 지점에서 네 방향으로 확산된다.

// 지훈이는 미로의 가장자리에 접한 공간에서 탈출할 수 있다.

// 지훈이와 불은 벽이 있는 공간은 통과하지 못한다.

// 입력
// 입력의 첫째 줄에는 공백으로 구분된 두 정수 R과 C가 주어진다. 단, 1 ≤ R, C ≤ 1000 이다. R은 미로 행의 개수, C는 열의 개수이다.

// 다음 입력으로 R줄동안 각각의 미로 행이 주어진다.

//  각각의 문자들은 다음을 뜻한다.

// #: 벽
// .: 지나갈 수 있는 공간
// J: 지훈이의 미로에서의 초기위치 (지나갈 수 있는 공간)
// F: 불이 난 공간
// J는 입력에서 하나만 주어진다.

// 출력
// 지훈이가 불이 도달하기 전에 미로를 탈출 할 수 없는 경우 IMPOSSIBLE 을 출력한다.

// 지훈이가 미로를 탈출할 수 있는 경우에는 가장 빠른 탈출시간을 출력한다.
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

string board[1000];
int fire[1000][1000];
int human[1000][1000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int r, c;
	cin >> r >> c;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	for (int i = 0; i < r; i++)
	{
		fill(fire[i], fire[i] + c, -1);
		fill(human[i], human[i] + c, -1);
	}
	for (int i = 0; i < r; i++)
		cin >> board[i];
	queue<pair<int, int> > q1;
	queue<pair<int, int> > q2;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (board[i][j] == 'F')
			{
				q1.push(make_pair(i, j));
				fire[i][j] = 0;
			}
			if (board[i][j] == 'J')
			{
				q2.push(make_pair(i, j));
				human[i][j] = 0;
			}
		}
	}
	while (!q1.empty())
	{
		pair<int, int> now = q1.front();
		q1.pop();
		for (int d = 0; d < 4; d++)
		{
			int nx = now.first + dx[d];
			int ny = now.second + dy[d];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c)
				continue;
			if (fire[nx][ny] >= 0 || board[nx][ny] == '#')
				continue;
			fire[nx][ny] = fire[now.first][now.second] + 1;
			q1.push(make_pair(nx, ny));
		}
	}
	while (!q2.empty())
	{
		pair<int, int> now = q2.front();
		q2.pop();
		for (int d = 0; d < 4; d++)
		{
			int nx = now.first + dx[d];
			int ny = now.second + dy[d];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c)
			{
				cout << human[now.first][now.second] + 1;
				return (0);
			}
			if (human[nx][ny] >= 0 || board[nx][ny] == '#')
				continue;
			if (fire[nx][ny] != -1 && fire[nx][ny] <= human[now.first][now.second] + 1)
				continue;
			human[nx][ny] = human[now.first][now.second] + 1;
			q2.push(make_pair(nx, ny));
		}
	}
	cout << "IMPOSSIBLE";
}
