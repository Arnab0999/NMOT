#include<stdio.h>
#include<stdlib.h>
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int findMax(int n,int* arr)
{
    int max=0,i;
    for(i=0;i<n;i++)
    {
        if(max < *(arr+i))
        {
            max=*(arr+i);
        }
    }
    return max;
}
int* findRowDiff(int m,int n,int arr[n][m])
{
    unsigned int *result;
    result = (int*)malloc(n*sizeof(int));
    int i,j;
    int min1=999,min2=999;
    for( i = 0; i < n; i++)
    {
        min1=min2=999;
        for( j = 0; j < m; j++)
        {
            if(arr[i][j]<min1)
            {
                min2=min1;
                min1=arr[i][j];
            }
            else if(arr[i][j]<min2&&arr[i][j]!=min1)
            {
                min2=arr[i][j];
            }

        }
        *(result+i)=(min2-min1);
    }
    return result;
}
int* findColumnDiff(int m,int n,int arr[n][m])
{
    int i,j,min1,min2;
    int * result = (int*)malloc(m*sizeof(int));
    for(i=0;i<m;i++)
    {
        min1=min2=999;
        for(j=0;j<n;j++)
        {
            if(arr[j][i]<min1)
            {
                min2=min1;
                min1=arr[j][i];
            }
            else if(arr[j][i]<min2&&arr[j][i]!=min1)
            {
                min2=arr[j][i];
            }
        }
        *(result+i)=(min2-min1);
    }
    return result;
}
void print(int m,int n,int supply[n],int demand[m],int *coldiff,int *rowdiff,int arr[n][m])
{
    int i,j;
    for( i = 1; i <= m; i++)
    {
        printf("\tD%d",i);
    }
    printf("\tSupply\tRowPenalty");
    printf("\n--------------------------------------------------------------------------");
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("S%d\t",i+1);
        for(j=0;j<m;j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("%d\t%d\n",supply[i],*(rowdiff+i));
    }
    printf("\nDemand\t");
    for(i=0;i<m;i++)
    {
        printf("%d\t",demand[i]);
    }
    printf("\nColPen\t");
    for(i=0;i<m;i++)
    {
        printf("%d\t",*(coldiff+i));
    }
    printf("\n");
}
int VAM(int m,int n,int supply[n],int demand[m],int arr[n][m])
{
    int flag=0,i,j;
    int z=0,max1,max2,maxim,min=999;
    int *coldiff=(int*)malloc(m*sizeof(int));
    int *rowdiff=(int*)malloc(n*sizeof(int));
    while(flag<1)
    {
        coldiff=findColumnDiff(m,n,arr);
        rowdiff=findRowDiff(m,n,arr);
        print(m,n,supply,demand,coldiff,rowdiff,arr);
        max1=findMax(m,coldiff);
        max2=findMax(n,rowdiff);
        maxim=max(max1,max2);
        if(maxim==max1)
        {
            for(i=0;i<m;i++)
            {
                if(max1 == *(coldiff+i))
                    break;
            }
            for(j=0;j<n;j++)
            {
                if(min>arr[j][i])
                {
                    min=arr[j][i];
                }
            }
            for(j=0;j<n;j++)
            {
                if(min==arr[j][i])
                    break;
            }
            if(demand[i]>supply[j]&&supply[j]!=0)
            {
                if(arr[j][i]==1111)
                {
                    z+=0;
                }
                else
                {
                    demand[i]=demand[i]-supply[j];
                    z+=supply[j]*arr[j][i];
                    supply[j]=0;
                }  
            }
            else if(demand[i]!=0)
            {
                if(arr[j][i]==1111)
                {
                    z+=0;
                }
                else
                {
                    supply[j]-=demand[i];
                    z+=demand[i]*arr[j][i];
                    demand[i]=0;
                }
            }
            for(j=0;j<n;j++)
            {
                arr[j][i]=1111;
            }
        }
        if(maxim==max2)
        {
            for(i=0;i<n;i++)
            {
                if(max2 == *(rowdiff+i))
                    break;
            }
            for(j=0;j<m;j++)
            {
                if(min>arr[i][j])
                {
                    min=arr[i][j];
                }
            }
            for(j=0;j<m;j++)
            {
                if(min==arr[i][j])
                    break;
            }
            if(demand[j]>supply[i]&&supply[i]!=0)
            {
                if(arr[i][j]==0)
                {
                    z+=0;
                }
                else
                {
                    demand[j]=demand[j]-supply[i];
                    z+=supply[i]*arr[i][j];
                    supply[i]=0;
                }
            }
            else if(demand[j]!=0)
            {
                if(arr[i][j]==1111)
                {
                    z+=0;
                }
                else
                {
                    supply[i]-=demand[j];
                    z+=demand[j]*arr[i][j];
                    demand[j]=0;   
                }
            }
            for(j=0;j<m;j++)
            {
                arr[i][j]=1111;
            }
        }
       
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(arr[i][j]!=1111)
                {
                    flag=0;
                    break;
                }
                else
                {
                    flag=1;
                }
            }
            if(flag==0)
                break;

        }
    }
    return z;
}
int main()
{
    int m,n;
    printf("Enter the demands and supply numbers:");
    scanf("%d%d",&m,&n);
    int mainArray[n][m];
    int supply[n];
    int demand[m];
    int i;
    for( i = 1; i <= m; i++)
    {
        printf("\tD%d",i);
    }
    printf("\n---------------------------------");
    printf("\n");
    int j;
    for( i = 0; i < n; i++)
    {
        printf("S%d\t",i+1);
        for( j = 0; j < m; j++)
        {
            scanf("%d",&mainArray[i][j]);
        }
    }
    printf("\nEnter Supplys:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&supply[i]);
    }
    printf("\nEnter Demands:");
    for(i=0;i<m;i++)
    {
        scanf("%d",&demand[i]);
    }
    int z=VAM(m,n,supply,demand,mainArray);
    printf("\nMinimum Z = %d",z);
    return 0;
}
