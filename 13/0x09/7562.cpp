// 문제
// 체스판 위에 한 나이트가 놓여져 있다. 나이트가 한 번에 이동할 수 있는 칸은 아래 그림에 나와있다. 나이트가 이동하려고 하는 칸이 주어진다. 나이트는 몇 번 움직이면 이 칸으로 이동할 수 있을까?



// 입력
// 입력의 첫째 줄에는 테스트 케이스의 개수가 주어진다.

// 각 테스트 케이스는 세 줄로 이루어져 있다. 첫째 줄에는 체스판의 한 변의 길이 l(4 ≤ l ≤ 300)이 주어진다. 체스판의 크기는 l × l이다. 체스판의 각 칸은 두 수의 쌍 {0, ..., l-1} × {0, ..., l-1}로 나타낼 수 있다. 둘째 줄과 셋째 줄에는 나이트가 현재 있는 칸, 나이트가 이동하려고 하는 칸이 주어진다.

// 출력
// 각 테스트 케이스마다 나이트가 최소 몇 번만에 이동할 수 있는지 출력한다.
#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int board[300][300];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie();
	int n;
	cin >> n;
	int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	while (n--)
	{
		int l, x, y;
		cin >> l;
		queue<pair<int, int> > q;
		for (int i = 0; i < l; i++)
			fill(board[i], board[i] + l, -1);
		cin >> x >> y;
		q.push(make_pair(x, y));
		board[x][y] = 0;
		cin >> x >> y;
		while (board[x][y] == -1)
		{
			pair<int, int> now = q.front();
			q.pop();
			for (int d = 0; d < 8; d++)
			{
				int nx = now.first + dx[d];
				int ny = now.second + dy[d];
				if (nx < 0 || nx >= l || ny < 0 || ny >= l)
					continue;
				if (board[nx][ny] >= 0)
					continue;
				board[nx][ny] = board[now.first][now.second] + 1;
				q.push(make_pair(nx, ny));
			}
		}
		cout << board[x][y] << '\n';
	}
}
