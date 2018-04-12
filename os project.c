#include<stdio.h>
int main()
{
int i,n,p[10]={1,2,3,4,5,6,7,8,9,10},min,k=1,btime=0;
int b[10],temp,j,a[10],wt[10],tt[10],ta=0,sum=0;
float wavg=0,tavg=0,tsum=0,wsum=0;
printf("*********Shortest Job First Scheduling*********\n");
printf("\nEnter the No of processes :");
scanf("%d",&n);
 
for(i=0;i<n;i++)
{
	printf("Enter the arrival time of %d process :",i+1);
	scanf(" %d",&a[i]);	
	printf("Enter the burst time of %d process :",i+1);
	scanf(" %d",&b[i]);
}
 
 
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		if(a[i]<a[j])
		{
			temp=p[j];
			p[j]=p[i];
			p[i]=temp;
			temp=a[j];
			a[j]=a[i];
			a[i]=temp;
			temp=b[j];
			b[j]=b[i];
			b[i]=temp;
		}
	}
}
 
for(j=0;j<n;j++)
{
	btime=btime+b[j];
	min=b[k];
	for(i=k;i<n;i++)
	{
		if (btime>=a[i] && b[i]<min)
		{
			temp=p[k];
			p[k]=p[i];
			p[i]=temp;
			temp=a[k];
			a[k]=a[i];
			a[i]=temp;
			temp=b[k];
			b[k]=b[i];
			b[i]=temp;
		}
	}
	k++;
}

wt[0]=0;
for(i=1;i<n;i++)
{
	sum=sum+b[i-1];
	wt[i]=sum-a[i];
	wsum=wsum+wt[i];
}
 
wavg=(wsum/n);
for(i=0;i<n;i++)
{
	ta=ta+b[i];
	tt[i]=ta-a[i];
	tsum=tsum+tt[i];
}
 
tavg=(tsum/n);
 
printf("------------------------------------------------------------");
printf("\n RESULT:");
printf("\nProcess\t\t Burst\t\t Arrival\t\t Waiting\t\t Turn-around" );
for(i=0;i<n;i++)
{
printf("\n p%d\t\t %d\t\t %d\t\t\t %d\t\t\t\t%d",p[i],b[i],a[i],wt[i],tt[i]);
}
 
printf("\n\nAVERAGE WAITING TIME : %f",wavg);
printf("\nAVERAGE TURN AROUND TIME : %f",tavg);
return 0;
}

