// 문제
// <그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 철수는 이 지도를 가지고 연결된 집의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.

// 입력
// 첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

// 출력
// 첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.
#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

string board[25];
int vis[25][25];
vector<int> ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, cnt = 0;
	cin >> n;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	for (int i = 0; i < n; i++)
		cin >> board[i];
	queue<pair<int, int> > q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == '0' || vis[i][j])
				continue;
			cnt++;
			vis[i][j] = 1;
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
					if (nx < 0 || nx >= n || ny < 0 || ny >= n)
						continue;
					if (board[nx][ny] == '0' || vis[nx][ny])
						continue;
					vis[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
			ans.push_back(area);
		}
	}
	cout << cnt << '\n';
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
}
