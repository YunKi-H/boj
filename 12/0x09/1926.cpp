// 문제
// 어떤 큰 도화지에 그림이 그려져 있을 때, 그 그림의 개수와, 그 그림 중 넓이가 가장 넓은 것의 넓이를 출력하여라. 단, 그림이라는 것은 1로 연결된 것을 한 그림이라고 정의하자. 가로나 세로로 연결된 것은 연결이 된 것이고 대각선으로 연결이 된 것은 떨어진 그림이다. 그림의 넓이란 그림에 포함된 1의 개수이다.

// 입력
// 첫째 줄에 도화지의 세로 크기 n(1 ≤ n ≤ 500)과 가로 크기 m(1 ≤ m ≤ 500)이 차례로 주어진다. 두 번째 줄부터 n+1 줄 까지 그림의 정보가 주어진다. (단 그림의 정보는 0과 1이 공백을 두고 주어지며, 0은 색칠이 안된 부분, 1은 색칠이 된 부분을 의미한다)

// 출력
// 첫째 줄에는 그림의 개수, 둘째 줄에는 그 중 가장 넓은 그림의 넓이를 출력하여라. 단, 그림이 하나도 없는 경우에는 가장 넓은 그림의 넓이는 0이다.
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int board[501][501];
bool check[501][501];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie();
	int n, m, res = 0, cnt = 0;
	cin >> n >> m;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	queue<pair<int, int> > q;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!board[i][j] || check[i][j])
				continue;
			cnt++;
			check[i][j] = 1;
			q.push(make_pair(i, j));
			int area = 0;
			while (!q.empty())
			{
				area++;
				pair<int, int> now = q.front();
				q.pop();
				for (int d = 0; d < 4; d++)
				{
					int nx = now.first + dx[d];
					int ny = now.second + dy[d];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						continue;
					if (check[nx][ny] || board[nx][ny] != 1)
						continue;
					check[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
			res = max(res, area);
		}
	}
	cout << cnt << '\n' << res;
}
