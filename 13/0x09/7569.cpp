// 문제
// 철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다. 토마토는 아래의 그림과 같이 격자모양 상자의 칸에 하나씩 넣은 다음, 상자들을 수직으로 쌓아 올려서 창고에 보관한다.



// 창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다. 보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다. 하나의 토마토에 인접한 곳은 위, 아래, 왼쪽, 오른쪽, 앞, 뒤 여섯 방향에 있는 토마토를 의미한다. 대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다. 철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지 그 최소 일수를 알고 싶어 한다.

// 토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.

// 입력
// 첫 줄에는 상자의 크기를 나타내는 두 정수 M,N과 쌓아올려지는 상자의 수를 나타내는 H가 주어진다. M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수를 나타낸다. 단, 2 ≤ M ≤ 100, 2 ≤ N ≤ 100, 1 ≤ H ≤ 100 이다. 둘째 줄부터는 가장 밑의 상자부터 가장 위의 상자까지에 저장된 토마토들의 정보가 주어진다. 즉, 둘째 줄부터 N개의 줄에는 하나의 상자에 담긴 토마토의 정보가 주어진다. 각 줄에는 상자 가로줄에 들어있는 토마토들의 상태가 M개의 정수로 주어진다. 정수 1은 익은 토마토, 정수 0 은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다. 이러한 N개의 줄이 H번 반복하여 주어진다.

// 토마토가 하나 이상 있는 경우만 입력으로 주어진다.

// 출력
// 여러분은 토마토가 모두 익을 때까지 최소 며칠이 걸리는지를 계산해서 출력해야 한다. 만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int board[100][100][100];
int check[100][100][100];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int M, N, H;
	cin >> M >> N >> H;
	queue<pair<int, pair<int, int> > > q;
	int dx[6] = {1, 0, 0, -1, 0, 0};
	int dy[6] = {0, 1, 0, 0, -1, 0};
	int dh[6] = {0, 0, 1, 0, 0, -1};
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> board[i][j][k];
				if (board[i][j][k] == 1)
					q.push(make_pair(i, make_pair(j, k)));
				if (board[i][j][k] == 0)
					check[i][j][k] = -1;
			}
		}
	}
	while (!q.empty())
	{
		pair<int, pair<int, int> > now = q.front();
		q.pop();
		for (int d = 0; d < 6; d++)
		{
			int nx = now.second.first + dx[d];
			int ny = now.second.second + dy[d];
			int nh = now.first + dh[d];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || nh < 0 || nh >= H)
				continue;
			if (check[nh][nx][ny] >= 0)
				continue;
			check[nh][nx][ny] = check[now.first][now.second.first][now.second.second] + 1;
			q.push(make_pair(nh, make_pair(nx, ny)));
		}
	}
	int res = 0;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (check[i][j][k] == -1)
				{
					cout << -1;
					return (0);
				}
				res = max(res, check[i][j][k]);
			}
		}
	}
	cout << res;
}
