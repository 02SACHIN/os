#include<stdio.h>
#define nl printf("\n")
typedef struct
{
	int id;
	int btm;
} process;

int main()
{
	process tmp,p[10];
	int n,i,j,tbt,btm;

	printf("Enter no. of processes : ");	scanf("%d",&n);
	nl;

	i=0,tbt=0;
	while(i<n)
	{
		nl;
		printf("For process %d",i+1);
		nl;
		printf("Enter burst time : ");		scanf("%d",&btm);
		
		tbt+=btm;

		p[i].id=i+1;
		p[i].btm=btm;
		
		i++;		
	}

        
	i=0,j=0;
	while(i<n)
	{
		while(j<n)
		{
			if(p[i].btm > p[j].btm)
			{
				tmp=p[i];
				p[i]=p[j];
				p[j]=tmp;
			}
			j++;
		}
		j=i+1;
		i++;
	}

	i=0,j=0;
	while(i<tbt)
	{	
		printf("\nTime\t\tProcess");
		nl;
		while(j<n)
		{
			if(p[j].btm==0)
			j++;
			else
			{
				printf("%d\t\t\t%d",i+1,p[j].id);
				nl;
				i++;
				p[j].btm--;
			}
		}		

	}
	return 0;
}
