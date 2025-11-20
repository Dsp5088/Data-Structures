#include<stdio.h>
void radixsort(int arr[],int n)
{
	int big,nod=0,steps,count[10],i,j,k,bucket[10][n],loc,div=1;
	
	int max=arr[0];
	for(i=1;i<n;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	
	big=max;
	while(big>0)
	{
		nod++;
		big=big/10;
	}
	
	for(steps=1;steps<=nod;steps++)
	{
		for(j=0;j<10;j++)
		{
			count[j]=0;
		}
		
		for(i=0;i<n;i++)
		{
			loc=(arr[i]/div)%10;
			bucket[loc][count[loc]++]=arr[i];
		}
		k=0;
		
		for(j=0;j<10;j++)
		{
			for(i=0;i<count[j];i++)
			{
				arr[k]=bucket[j][i];
				k++;
			}
		}
		div=div*10;
	}
}
 int main()
 {
 	int i,n;
 	printf("Enter the size of the arr:\n");
 	scanf("%d",&n);
 	int arr[n];
 	printf("Enter the %d elements:\n",n);
 	for(i=0;i<n;i++)
 	{
 		scanf("%d",&arr[i]);
	 }
	radixsort(arr,n);
	printf("After sorted the elements:\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
 }
