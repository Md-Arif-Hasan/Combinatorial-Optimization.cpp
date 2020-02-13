#include<stdio.h>
int main()
{
	unsigned long long int n,s,d=0,i;

	scanf("%llu %llu",&n,&s);
	d=s/n;
	for(i=1;i<=s;i++)
	{
		if(n*i==s)
		{
			printf("%llu",d);
			return 0;
		}
	}
	printf("%llu",d+1);
	return 0;
}
