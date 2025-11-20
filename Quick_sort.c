#include<stdio.h>
void QS(int arr[],int low,int high)
{
	int i,j,pi,temp;
	
	if(low<high)
	{
		pi=low;
		i=low;
		j=high;
		while(i<j)
		{
		   while(arr[i]<=arr[pi] && i<high)
		   i++;
		   while(arr[j]>arr[pi])
		   j--;
		   if(i<j)
		   {
		   	temp=arr[i];
		   	arr[i]=arr[j];
		   	arr[j]=temp;
		   	
			   }	
		}
		temp=arr[pi];
		arr[pi]=arr[j];
		arr[j]=temp;
		
		QS(arr,low,j-1);
		QS(arr,j+1,high);
	}
}
int main()
{
	int i,n,arr[30];
	printf("Enter the size of array\n");
	scanf("%d",&n);
	printf("Enter %d elements\n",n);
	for(i=0;i<n;i++)
	{		
		scanf("%d",&arr[i]);
	}
	
	QS(arr,0,n-1);
	printf("The sorted elements are:\n");		
	
	for(i=0;i<n;i++)
	{			
		printf("%d ",arr[i]);
	}
	
	
	return 0;
}







