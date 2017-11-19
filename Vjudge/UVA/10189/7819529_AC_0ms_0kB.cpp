#include<cstdio>
#include<cstring>

int a[120][120];

int main(void)
{
	int n, m, count = 1, i, j,ii,jj;
	while (scanf("%d%d", &n, &m),n)
	{
	    getchar();
		if (count > 1) putchar('\n');
		char ch;
		memset(a,0,sizeof(a));
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				scanf("%c", &ch);
				if (ch == '*')
				{
					a[i][j] = 11;///小技巧
					for (ii = i - 1; ii <= i + 1; ii++)
						for (jj = j - 1; jj <= j + 1; jj++)
							a[ii][jj]++;
				}
			}
			getchar();
		}
		printf("Field #%d:\n", count);
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				if (a[i][j] > 10) putchar('*');
				else printf("%d", a[i][j]);
			}
			putchar('\n');
		}
		count++;
	}
	return 0;
}
