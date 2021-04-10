#include <stdio.h>

int read_arr(int * a[100], int n)
{
	for (int i = 0; i < n; i++)
		if (scanf("%d", &a[i]) != 1)
			return -1;
	return 0;
}

void write_arr(int * a[100], int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", a[i]);
}

int main ()
{
	setbuf(stdout, NULL);
	int n;
	int a[100];
	int k = 0;
		
	if (scanf("%d", &n) != 1)
		return -1;
	
	if (n < 1 || n > 100) // || read_arr(a[100], n))
		return -1;
	
	for (int i = 0; i < n; i++)
		if (scanf("%d", &a[i]) != 1)
			return -1;
	
	for (int i = 0; i < n - 1 - k; i++)
	{
		if (a[i] >= a[i + 1])
			for (int j = i; j = n - 1 - k; j++)
			{
				a[j] = a[j + 1];
				k += 1;
			}
	}
			
	for (int i = 0; i < n - k; i++)
		printf("%d ", a[i]);
	
	//write_arr(a[100], n - k);
	return 0;
}
