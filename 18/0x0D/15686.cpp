//https://www.acmicpc.net/problem/15686
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int n, m, r, c, ans = 0x7f7f7f7f;
int map[50][50];
vector<pair<int, int> > chic;
vector<pair<int, int> > house;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				house.push_back(make_pair(i, j));
			if (map[i][j] == 2)
				chic.push_back(make_pair(i, j));
		}
	}
	vector<int> brute(chic.size(), 1);
	fill(brute.begin(), brute.begin() + chic.size() - m, 0);
	do
	{
		int dist = 0;
		for (int i = 0; i < house.size(); i++)
		{
			int tmp = 0x7f7f7f7f;
			for (int j = 0; j < chic.size(); j++)
			{
				if (brute[j] == 0)
					continue;
				tmp = min(tmp, abs(chic[j].first - house[i].first) + abs(chic[j].second - house[i].second));
			}
			dist += tmp;
		}
		ans = min(ans, dist);
	} while (next_permutation(brute.begin(), brute.end()));
	cout << ans;
}
