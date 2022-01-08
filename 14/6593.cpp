// 문제
// 당신은 상범 빌딩에 갇히고 말았다. 여기서 탈출하는 가장 빠른 길은 무엇일까? 상범 빌딩은 각 변의 길이가 1인 정육면체(단위 정육면체)로 이루어져있다. 각 정육면체는 금으로 이루어져 있어 지나갈 수 없거나, 비어있어서 지나갈 수 있게 되어있다. 당신은 각 칸에서 인접한 6개의 칸(동,서,남,북,상,하)으로 1분의 시간을 들여 이동할 수 있다. 즉, 대각선으로 이동하는 것은 불가능하다. 그리고 상범 빌딩의 바깥면도 모두 금으로 막혀있어 출구를 통해서만 탈출할 수 있다.

// 당신은 상범 빌딩을 탈출할 수 있을까? 만약 그렇다면 얼마나 걸릴까?

// 입력
// 입력은 여러 개의 테스트 케이스로 이루어지며, 각 테스트 케이스는 세 개의 정수 L, R, C로 시작한다. L(1 ≤ L ≤ 30)은 상범 빌딩의 층 수이다. R(1 ≤ R ≤ 30)과 C(1 ≤ C ≤ 30)는 상범 빌딩의 한 층의 행과 열의 개수를 나타낸다.

// 그 다음 각 줄이 C개의 문자로 이루어진 R개의 행이 L번 주어진다. 각 문자는 상범 빌딩의 한 칸을 나타낸다. 금으로 막혀있어 지나갈 수 없는 칸은 '#'으로 표현되고, 비어있는 칸은 '.'으로 표현된다. 당신의 시작 지점은 'S'로 표현되고, 탈출할 수 있는 출구는 'E'로 표현된다. 각 층 사이에는 빈 줄이 있으며, 입력의 끝은 L, R, C가 모두 0으로 표현된다. 시작 지점과 출구는 항상 하나만 있다.

// 출력
// 각 빌딩에 대해 한 줄씩 답을 출력한다. 만약 당신이 탈출할 수 있다면 다음과 같이 출력한다.

// Escaped in x minute(s).
// 여기서 x는 상범 빌딩을 탈출하는 데에 필요한 최단 시간이다.

// 만일 탈출이 불가능하다면, 다음과 같이 출력한다.

// Trapped!
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int dx[6] = {1, 0, 0, -1, 0, 0};
	int dy[6] = {0, 1, 0, 0, -1, 0};
	int dz[6] = {0, 0, 1, 0, 0, -1};
	while (1)
	{
		int l, r, c, escape = 0;
		char space;
		queue<pair<int, pair<int, int> > > q;
		cin >> l >> r >> c;
		if (!l && !r && !c)
			break;
		string board[30][30];
		int vis[30][30][30];
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < r; j++)
				cin >> board[i][j];
		}
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < r; j++)
			{
				for (int k = 0; k < c; k++)
				{
					if (board[i][j][k] == 'S')
					{
						q.push(make_pair(i, make_pair(j, k)));
						vis[i][j][k] = 0;
					}
					else
						vis[i][j][k] = -1;
				}
			}
		}
		while (!q.empty())
		{
			if (escape)
				break;
			pair<int, pair<int, int> > now = q.front();
			q.pop();
			for (int d = 0; d < 6; d++)
			{
				int nx = now.second.second + dx[d];
				int ny = now.second.first + dy[d];
				int nz = now.first + dz[d];
				if (nx < 0 || nx >= c || ny < 0 || ny >= r || nz < 0 || nz >= l)
					continue;
				if (board[nz][ny][nx] == '#' || vis[nz][ny][nx] != -1)
					continue;
				if (board[nz][ny][nx] == 'E')
				{
					cout << "Escaped in " << vis[now.first][now.second.first][now.second.second] + 1 << " minute(s)." << "\n";
					escape = 1;
					break;
				}
				vis[nz][ny][nx] = vis[now.first][now.second.first][now.second.second] + 1;
				q.push(make_pair(nz, make_pair(ny, nx)));
			}
		}
		if (!escape)
			cout << "Trapped!" << "\n";
	}
}
