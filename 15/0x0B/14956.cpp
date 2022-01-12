// 문제
// In Programming Land, there are several pathways called Philosopher’s Walks for philosophers to have a rest. A Philosopher’s Walk is a pathway in a square-shaped region with plenty of woods. The woods are helpful for philosophers to think, but they planted so densely like a maze that they lost their ways in the maze of woods of a Philosopher’s Walk.

// Fortunately, the structures of all Philosopher’s Walks are similar; the structure of a Philosopher’s Walk is designed and constructed according to the same rule in a 2k meter square. The rule for designing the pathway is to take a right-turn in 90 degrees after every 1-meter step when k is 1, and the bigger one for which the integer k is greater than 1 is built up using four sub-pathways with k - 1 in a fractal style. Figure F.1 shows three Philosopher’s Walks for which k is 1, 2, and 3. The Philosopher’s Walk W2 consists of four W1 structures with the lower-left and the lower-right ones are 90 degree rotated clockwise and counter-clockwise, respectively; the upper ones have the same structure with W1. The same is true for any Wk for which the integer k is greater than 1. This rule has been devised by a mathematical philosopher David Hilbert (1862 – 1943), and the resulting pathway is usually called a HILBERT CURVE named after him. He once talked about a space filling method using this kind of curve to fill up a square with 2k sides, and every Philosophers’ Walk is designed according to this method.

// (a) W1	(b) W2	(c) W3
// Figure F.1. Three Philosopher's Walks with size (a) 21 = 2, (b) 22 = 4, and (c) 23 = 8, repectively.

// Tae-Cheon is in charge of the rescue of the philosophers lost in Philosopher’s Walks using a hot air balloon. Fortunately, every lost philosopher can report Tae-Cheon the number of meter steps he has taken, and Tae-Cheon knows the length of a side of the square of the Philosopher’s Walk. He has to identify the location of the lost philosopher, the (x,y) coordinates assuming that the Philosopher’s Walk is placed in the 1st quadrant of a Cartesian plain with one meter unit length. Assume that the coordinate of the lower-left corner block is (1,1). The entrance of a Philosopher’s Walk is always at (1,1) and the exit is always (n,1) where n is the length of a side. Also assume that the philosopher have walked one meter step when he is in the entrance, and that he always go forward to the exit without back steps.

// For example, if the number of meter-steps taken by a lost philosopher in the Philosopher’s Walk in W2 in Figure F.1(b) is 10, your program should report (3,4).

// Your mission is to write a program to help Tae-Cheon by making a program reporting the location of the lost philosopher given the number of meter-steps he has taken and the length of a side of the square of the Philosopher’s Walk. Hurry! A philosopher urgently needs your help.

// 입력
// Your program is to read from standard input. The input consists of a single line containing two positive integers, n and m, representing the length of a side of the square of the Philosopher’s Walk and the number of meter-steps taken by the lost philosopher, respectively, where n = 2k and m ≤ 22k for an integer k satisfying 0 < k ≤ 15.

// 출력
// Your program is to write to standard output. The single output line should contain two integers, x and y, separated by a space, where (x,y) is the location of the lost philosopher in the given Philosopher’s Walk.
#include <iostream>
using namespace std;

pair<int, int> solve(int n, int k)
{
	if (n == 2)
	{
		switch (k)
		{
			case 1:
				return (make_pair(1, 1));
			case 2:
				return (make_pair(1, 2));
			case 3:
				return (make_pair(2, 2));
			case 4:
				return (make_pair(2, 1));
		}
	}
	n /= 2;
	if (k <= n * n)
	{
		pair<int, int> first = solve(n, k);
		return (make_pair(first.second, first.first));
	}
	else if (k <= 2 * n * n)
	{
		pair<int, int> second = solve(n, k - n * n);
		return (make_pair(second.first, second.second + n));
	}
	else if (k <= 3 * n * n)
	{
		pair<int, int> third = solve(n, k - 2 * n * n);
		return (make_pair(third.first + n, third.second + n));
	}
	else
	{
		pair<int, int> fourth = solve(n, k - 3 * n * n);
		return (make_pair(-fourth.second + 2 * n + 1, -fourth.first + n + 1));
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	pair<int, int> ans = solve(n, k);
	cout << ans.first << ' ' << ans.second;
}
