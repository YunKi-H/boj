#include <iostream>
using namespace std;

int	main(void)
{
	int	t, a, b, c;

	c = 0;
	cin >> t;
	while (c++ < t)
	{
		cin >> a >> b;
		cout << "Case #" << c << ": " << a << " + " << b << " = " << a + b << "\n";
	}
	return (0);
}
