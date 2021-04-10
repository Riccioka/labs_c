#include <stdio.h>
#include <limits.h>

int main ()
{
	int max = -1;
	int min = INT_MAX;
	int n;
	if (scanf("%d", &n) != 1)
		return -1;
	if (n <= 0)
		return -1;
	int safe = n;
	while (safe > 0)
	{
		if (safe % 10 > max)
			max = safe % 10;
		if (safe % 10 < min)
			min = safe % 10;
		safe /= 10;
	}
	int res = max - min;
	printf("%d", res);
	return 0;
}
