#include <iostream>
using namespace std;

int	main(void)
{
	int	n;
	int	k;
	int	min;
	int	max;

	cin >> n;
	cin >> min;
	max = min;
	while (n > 1)
	{
		cin >> k;
		if (min > k)
			min = k;
		if (max < k)
			max = k;
		n--;
	}
	printf("%d %d", min, max);
	return (0);
}
