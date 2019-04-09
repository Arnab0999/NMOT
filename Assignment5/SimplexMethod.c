#include <stdio.h>
#define INFINITY 999
#define M 6
void minimum(float *arr,int *arrminpos, int n)
{
  int i;
  float arrmin;
  arrmin=arr[0];
  *arrminpos=0;
  for(i=0;i<n;i++)
    if(arr[i]<arrmin)
    {
      arrmin=arr[i];
      *arrminpos=i;
    }
    printf("\n%d\n",*arrminpos);
}
void displayframe(float c[M])
{
  printf("\t\tc[j]\t");
  printf("%g\t%g\t%g\t%g\t%g\t%g\n",c[0],c[1],c[2],c[3],c[4],c[5]);
  printf("\nc[B]\tB\tb\ta1\ta2\ta3\ta4\ta5\ta6\n");
}
void display (int N,float c[N],float b[N],float a[N][M],int basic[N])
{
  int i,j;
  displayframe(c);
  for(i=0;i<N;i++)
  {
    printf("\n%.4g\tX%d\t%.4g\t",c[basic[i]],basic[i]+1,b[i]);
    for(j=0;j<M;j++)
      printf("%.4g\t",a[i][j]);
    printf("\n");
  }
}
void calctemp(int N,float *temp,float a[N][M],float c[M],int basic[N])
{
  int i,j;
  for(i=0;i<M;i++)
  {
    temp[i]=0;
    for(j=0;j<N;j++)
      temp[i]=temp[i]+c[basic[j]]*a[j][i];
    temp[i]=temp[i]-c[i];
  }
}


void main()
{
  int N;
  printf("Enter the number of variables:");
  scanf("%d",&N);
  float a[N][M];
  float b[M];
  float c[M]={5,4,3,0,0,0};

  float temp[M]={0,0,0,0,0,0};

  int tempminpos;
  float miniratio[N];
  int miniratiominpos;
  float key;
  int gooutcol;
  float z;
  float x[M];
  int i,j;
  int basic[N];
  int nonbasic[N];
  int flag=0;

  for(i=0;i<N;i++)
  {
    basic[i]=(i+N);
    nonbasic[i]=i;
  }
  printf("\nMax z = c1x1 + c2x2 + c3x3\n");
  printf("\na11x1 + a12x2 + a13x3 <= b1\n");
  printf("\na21x1 + a22x2 + a23x3 <= b2\n");
  printf("\na31x1 + a31x2 + a32x3 <= b3\n");
  printf("\nEnter values of ci's\n");

  for(i=0;i<N;i++)
  {
    printf("\nEnter c[%d]\t",i+1);
    scanf("%f",&c[i]);
  }
  printf("\nEnter values of ai's\n");
  for(i=0;i<N;i++)
  {
    for(j=0;j<N;j++)
    {
      printf("\nEnter a[%d][%d]\t",i+1,j+1);
      scanf("%f",&a[i][j]);
    }
  }
  printf("\nEnter values of bi's\n");
  for(i=0;i<N;i++)
  {
    printf("\nEnter b[%d]\t",i+1);
    scanf("%f",&b[i]);
  }
  while(flag==0)
  {
    z=0;
    calctemp(N,temp,a,c,basic);
    printf("\n");



    minimum(temp,&tempminpos,M);
    display(N,c,b,a,basic);
    printf("\nZj-Cj\t\t\t");
    for(i=0;i<M;i++)
      printf("%.4g\t",temp[i]);
    printf("\n\n");
    for(i=0;i<N;i++)
    {
      x[basic[i]]=b[i];
      x[nonbasic[i]]=0;
      printf("x[%d]=%g\n",basic[i]+1,b[i]);
    }
    for(i=0;i<N;i++)
      z=z+c[i]*x[i];
    printf("Max(z) = %g",z);



    for(i=0;i<N;i++)
    {
      if(a[i][tempminpos]==0)
      {
        miniratio[i]=INFINITY;
        continue;
      }
      if(a[i][tempminpos]<0)
      {
        miniratio[i]=INFINITY;
        continue;
      }
      miniratio[i]=b[i]/a[i][tempminpos];
    }
    minimum(miniratio,&miniratiominpos,N);
    for(i=0;i<N;i++)
      if(miniratiominpos==i)
        gooutcol=basic[i];
    printf("\nComing in variable = X%d\t",tempminpos+1);
    printf("Going out variable = X%d\n",gooutcol+1);



    basic[miniratiominpos]=tempminpos;
    nonbasic[tempminpos]=gooutcol;


    key=a[miniratiominpos][tempminpos];
    b[miniratiominpos]=b[miniratiominpos]/key;
    for(i=0;i<M;i++)
      a[miniratiominpos][i]=a[miniratiominpos][i]/key;
    for(i=0;i<N;i++)
    {
      if(miniratiominpos==i)
        continue;
      key=a[i][tempminpos];
      for(j=0;j<M;j++)
      {
        a[i][j]=a[i][j]-a[miniratiominpos][j]*key;
      }
      b[i]=b[i]-b[miniratiominpos]*key;
    }
    for(i=0;i<M;i++)
    {
      flag=1;
      if(temp[i]<0)
      {
        flag=0;
        break;
      }
    }
  }
  printf("\nPress any key to exit...\n");

}
