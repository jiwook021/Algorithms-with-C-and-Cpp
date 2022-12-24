#include <stdio.h>

static void hanoi(int n, char from, char by, char to);

static void hanoi(int n, char from, char by, char to)
{
	if (n == 1)
	{
		printf("%d Disk move from %c to %c\n ", n, from, to);
		return;
	}
	else
	{
		hanoi(n - 1, from, to, by);
		printf("%d Disk move from %c to %c\n ", n, from, to);
		hanoi(n - 1, by, from, to);
	}
}

int main()
{
	hanoi(2, 'a', 'b', 'c');
}