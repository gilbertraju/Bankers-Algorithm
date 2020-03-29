#include<stdio.h>

int main()
{
	int n,a[15],max[15][15],need[15][15],
	all[15][15],avail[15],seq[15],com[15][15];
	int r,count=0,i=0,j=0,process=-1;
	printf("\n Enter the number of processes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a[i]=0;
		printf("\n Number of Resources: ");
		scanf("%d",&r);
		printf("\n Maximum resources: ");
		for(i=0;i<n;i++)
		{
			printf("\n For P[%d]: ",i+1);
			for(j=0;j<r;j++)
			{
				scanf("%d",&max[i][j]);
			}
		}
		printf("\n Allocation: ");
		for(i=0;i<n;i++)
		{
			printf("\n P[%d]: ",i+1);
			for(j=0;j<r;j++)
			{
				scanf("%d",&all[i][j]);
			}
		}
		printf("\n Available Resources: ");
		for(i=0;i<r;i++)
		{
			scanf("%d",&avail[i]);
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<r;j++)
			{
				need[i][j]=max[i][j]-all[i][j];
			}
		}
		
		do
		{
			process=-1;	
			printf("\n\n Process\tAllocation\tMaximum\n");
			for(i=0;i<n;i++)
			{
				printf("P[%d]\t\t",i+1);
				for(j=0;j<r;j++)
				{
					printf("%d\t\t",all[i][j]);
					printf("%d\n",max[i][j]);
				}
			}

		

			for(i=0;i<n;i++)
			{
				if(com[i]==0)
				{
					process=i;
					for(j=0;j<r;j++)
					{
						if(avail[j]<need[i][j])
						{
							process=-1;
							break;
						}
					}
				}
				if(process!=-1)
				break;
			}
			if(process!=-1)
			{
				printf("P[%d] runs successfully",process+1);
				seq[i]=process+1;
				count++;
				for(j=0;j<r;j++)
				{
					avail[j]=avail[j]+all[process][j];
					all[process][j]=0;
					max[process][j]=0;
					com[process][j]=1;
				}
			}
		}
		while(count!=n && process!=-1);
		if(count==n)
		{
			printf("\n The system is in a safe state");
		}
		else
			printf("\n The system is in deadlock");
	}
}

