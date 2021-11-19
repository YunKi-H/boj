#include <iostream>
using namespace std;

int	year[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int	main(void)
{
	int	m;
	int	d;
	int	day;

	cin >> m >> d;
	day = 0;
	while (m-- > 1)
		day += year[m - 1];
	day += d;
	if (day % 7 == 0)
		cout << "SUN";
	else if (day % 7 == 1)
		cout << "MON";
	else if (day % 7 == 2)
		cout << "TUE";
	else if (day % 7 == 3)
		cout << "WED";
	else if (day % 7 == 4)
		cout << "THU";
	else if (day % 7 == 5)
		cout << "FRI";
	else
		cout << "SAT";
	return (0);
}
