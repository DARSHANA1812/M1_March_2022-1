#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<process.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

///< This is a the cost matrix array storing cost of moving product from source to warehouse
int c[10][10];
///< s is the no.of sources where as d is the no.of warehouses
int s1[10],d1[10],s[10],d[10];

// sum1 stores sum of supply and sum2 stores sum of demands ,both of which must be same
int m,n,i,j,sum1,sum2;


/**
 * This is the main function
 * 
*/
int main(int argc, char *argv[])
 {
 // clrscr();
  // North West corner method 
  int m = 3 ;
  int n=4 ;
  int c[][4] = {{19,30,50,10},{70,30,40,60},{40,8,70,20}};  ;
  int sup[] = {7,9,18};
  int dem[] = {5,8,7,14};

  //input for supply
 
    int sum1=0;
 for(j=0;j<m;j++)
    {
      s[j] = sup[j];
      s1[j]=s[j];
      sum1=sum1+s1[j];
    }
  // printf("supply=> %d ",sum1);

  //input for demand
  //printf("\n ENTER THE DEMAND ARRAY \n");
 int sum2=0;
 for(j=0;j<n;j++)
    {
       d[j] = dem[j];
       d1[j]=d[j];
       sum2=sum2+d1[j];
    }
    // printf("demand=> %d",sum2);

   //-------------> Logic to calculate minimum cost
  if(sum1!=sum2)
  {
   printf("problem is unbalanced");
   exit(0);
  }
     // exit;
  i=0;j=0;
  int sum=0;
  start:
      if(i==m&&j==n)
      goto end;
      else if (s[i]==d[j])
      {
      	 sum=sum+(c[i][j]*s[i]);
      	 i++;j++;
      }
      else if(s[i]<d[j])
      {
    	 d[j]=d[j]-s[i];
    	 sum=sum+(c[i][j]*s[i]);
        i++;
      }
      else if(s[i]>d[j])
      {
     s[i]=s[i]-d[j];
     sum=sum+(c[i][j]*d[j]);
     j++;
      }
      goto start;
  end:

   // clrscr();
    printf("\n-------------- ---------------------------------\n");
    printf("|        | \n");
    for(i=0;i<m;i++)
    {
    printf("| ");
    for(j=0;j<n;j++)
    {
      printf("%d ",c[i][j]);
    }
    printf("|  ",s1[i]);
    printf("\n|    |");
    printf("\n|    |\n");
    }
    printf(" ------------------------------------------------\n");
    for(i=0;i<n;i++)
    {
      printf("%d ",d1[i]);
    }
    printf("\n  THE MINIMUM TRANSPORTATION COST = %d ",sum);
    printf(" units");
    getch();

}

