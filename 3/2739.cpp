#include <iostream>
using namespace std;

int	main(void)
{
	int	i;
	int	j;

	cin >> i;
	j = 0;
	while (j++ < 9)
		printf("%d * %d = %d\n", i, j, i * j);
	return (0);
}
