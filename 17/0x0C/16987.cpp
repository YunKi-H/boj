// 문제
// 원래 프로그래머의 기본 소양은 팔굽혀펴기를 단 한 개도 할 수 없는 것이라고 하지만 인범이는 3대 500을 넘기는 몇 안되는 프로그래머 중 한 명이다. 인범이는 BOJ에서 틀린 제출을 할 때마다 턱걸이를 5회 하는 기적의 운동 루틴을 통해 뇌와 근육을 동시에 단련한다. 근육을 단련할 때 식단이 정말로 중요하다는 것을 아는 인범이는 탄수화물이 많은 밥이나 빵 따위의 아침 식사를 대신해 단백질이 많은 계란찜을 해먹는다. 계란찜을 먹기 위해서는 계란을 깨야 하는데, 인범이는 힘이 너무 넘치는 나머지 부엌의 대리석을 이용해 계란을 깨면 늘 껍데기가 산산조각나 뒷처리가 너무 어렵게 되곤 한다. 어떻게 하면 계란을 조심스럽게 깰 수 있을까 고민하던 인범이에게 유현이는 굉장히 좋은 해결책을 알려주었다. 바로 계란으로 계란을 치는 것이다. 계란끼리 부딪쳐보니 껍데기가 아주 예쁘게 갈라지는 것을 발견한 인범이는 앞으로 계란으로 계란을 쳐서 식사 준비를 해야겠다고 생각했다. 유현이는 더 나아가 식사 준비를 할 때에도 두뇌를 단련할 수 있는 좋은 퍼즐을 인범이에게 알려주었다.

// 문제를 소개하기 전, 계란으로 계란을 치게 될 경우 어떤 일이 벌어지는지를 먼저 이해하고 가자. 각 계란에는 내구도와 무게가 정해져있다. 계란으로 계란을 치게 되면 각 계란의 내구도는 상대 계란의 무게만큼 깎이게 된다. 그리고 내구도가 0 이하가 되는 순간 계란은 깨지게 된다. 예를 들어 계란 1의 내구도가 7, 무게가 5이고 계란 2의 내구도가 3, 무게가 4라고 해보자. 계란 1으로 계란 2를 치게 되면 계란 1의 내구도는 4만큼 감소해 3이 되고 계란 2의 내구도는 5만큼 감소해 -2가 된다. 충돌 결과 계란 1은 아직 깨지지 않았고 계란 2는 깨졌다.

// 유현이가 인범이에게 알려준 퍼즐은 일렬로 놓여있는 계란에 대해 왼쪽부터 차례로 들어서 한 번씩만 다른 계란을 쳐 최대한 많은 계란을 깨는 문제였다. 구체적으로 계란을 치는 과정을 설명하면 아래와 같다.

// 가장 왼쪽의 계란을 든다.
// 손에 들고 있는 계란으로 깨지지 않은 다른 계란 중에서 하나를 친다. 단, 손에 든 계란이 깨졌거나 깨지지 않은 다른 계란이 없으면 치지 않고 넘어간다. 이후 손에 든 계란을 원래 자리에 내려놓고 3번 과정을 진행한다.
// 가장 최근에 든 계란의 한 칸 오른쪽 계란을 손에 들고 2번 과정을 다시 진행한다. 단, 가장 최근에 든 계란이 가장 오른쪽에 위치한 계란일 경우 계란을 치는 과정을 종료한다.
// 이 과정을 통해 최대한 많은 계란을 깨는 것이 앞으로 인범이가 매일 아침마다 풀게 될 퍼즐이다. 그리고 유현이는 인범이가 찾은 답이 정답이 맞는지 확인해주려고 한다. 일렬로 놓인 계란들의 내구도와 무게가 차례대로 주어졌을 때 최대 몇 개의 계란을 깰 수 있는지 알아맞춰보자.

// 입력
// 첫째 줄에 계란의 수를 나타내는 N(1 ≤ N ≤ 8)가 주어진다. 그 다음 N개의 줄에는 계란의 내구도와 무게에 대한 정보가 주어진다. i+1번째 줄에는 왼쪽에서 i번째에 위치한 계란의 내구도 Si(1 ≤ Si ≤ 300)와 무게 Wi(1 ≤ Wi ≤ 300)가 한 칸의 빈칸을 사이에 두고 주어진다.

// 출력
// 첫째 줄에 인범이가 깰 수 있는 계란의 최대 개수를 출력한다.
#include <iostream>
#include <algorithm>
using namespace std;

int n, cnt, ans;
int s[9];
int w[9];

void solve(int k)
{
	if (k == n)
	{
		ans = max(ans, cnt);
		return;
	}
	if (s[k] <= 0 || cnt == n - 1)
	{
		solve (k + 1);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (i == k || s[i] <= 0)
			continue;
		s[k] -= w[i];
		s[i] -= w[k];
		if (s[k] <= 0)
			cnt++;
		if (s[i] <= 0)
			cnt++;
		solve(k + 1);
		if (s[k] <= 0)
			cnt--;
		if (s[i] <= 0)
			cnt--;
		s[k] += w[i];
		s[i] += w[k];
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i] >> w[i];
	solve(0);
	cout << ans;
}
