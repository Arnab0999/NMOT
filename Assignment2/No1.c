#include<stdio.h>
#include<stdlib.h>
int getinteger(char array[],int index)
{
    int num,count=0;
    while(array[index]>=47&&array[index]<=57)
    {
        if(count==0)
        {
            num=array[index]-'0';
            count=1;
        }
        else
        {
            num=(array[index]-'0')*count+num;
        }
        count=count*10;
        index--;
    }
    if(array[index]==45)
    {
        num=-num;
    }
    return num;
}
int * checkequation(char arr[],int c)
{
    int *matrix=(int*)malloc(sizeof(int));
    int i,count=0;
    for(i=0;arr[i]!='\0';i++)
    {
        if(arr[i]>=97&&arr[i]<=122)
        {
            if(i==0)
            {
                *(matrix+i)=1;
            }
            else if(arr[i-1]==43||arr[i-1]==45)
            {
                if(arr[i-1]==45)
                {
                    *(matrix+count)=-1;
                }
                else
                    *(matrix+count)=1;
            }
            else
            {
                *(matrix+count)=getinteger(arr,i-1);
            }
            count++;
        }
    }
    *(matrix+count)=getinteger(arr,c-1);
    return matrix;
}
int main()
{
    int i,c=0;
    char mat[100];
    scanf("%s",mat);
    for(i=0;mat[i]!='\0';i++)
    {
        c++;
    }
    int *equation;
    equation=checkequation(mat,c);
    c=0;
    for(i=0;*(equation+i)!='\0';i++)
    {
        c++;
    }
    int matrix[c-1][c-1], aR[c-1],x[c-1];
	for(i=0;i<c-1;i++)
	{
        matrix[0][i]=*(equation+i);
        aR[0]=*(equation+i+1);
    }
    int j;
    int sze=0,k;
    for(i=1;i<c-1;i++)
    {
        scanf("%s",mat);
        for(k=0;mat[k]!='\0';k++)
        {
            sze++;
        }
        equation=checkequation(mat,sze);
        for(j=0;j<c-1;j++)
        {
            matrix[i][j]=*(equation+j);
        }
        aR[i]=*(equation+c-1);
    }
	printf("Printing --\n");
	for(i=0;i<c-1;i++){
		for(j=0;j<c-1;j++){
			printf("%d ",matrix[i][j]);
		}
		if(i == (c-1)/2 ){
			printf("= %d",aR[i]);
		}
		else printf("  %d",aR[i]);
		printf("\n");
	}
    printf("Enter Initial values : ");
    for (i = 0; i < c-1; i++) {
        scanf("%d", &x[i]);
    }
    printf("iter\tX1\t\t\tX2\t\t\t X3\n");
	for (i = 0; i < 10; ++i){
        x[0] = (aR[0] - (matrix[0][1]*x[1]) - (matrix[0][2] * x[2]) )/matrix[0][0];
		x[1] = (aR[1] - (matrix[1][0]*x[0]) - (matrix[1][2] * x[2]) )/matrix[1][1];
		x[2] = (aR[2] - (matrix[2][0]*x[0]) - (matrix[2][1] * x[1]) )/matrix[2][2];

        printf("%d\t%d\t\t%d\t\t%d\n",i+1,x[0],x[1],x[2]);
	}

    return 0;
}
