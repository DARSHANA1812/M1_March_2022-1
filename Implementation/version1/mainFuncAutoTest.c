#include "../Unity/unity.h"
#include "../Unity/unity.c"

extern void manual_test_cal(int m1,int n1,int cost[][n1],int sup[],int dem[]);
extern int cal(int m1,int n1,int cost[][n1],int sup[],int dem[]) ;

 //int row = 0 ; // for getting error
  int row =3;
  int col=4 ;
  int co[][4] = {{19,30,50,10},{70,30,40,60},{40,8,70,20}};  ;
  int su[] = {7,9,18};
  int de[] = {5,8,7,14};

void setUp(void)
{
}

void tearDown(void)
{
}

void automated_test_cal()
{
  TEST_ASSERT_EQUAL(1015, cal(row,col,co,su,de));
        
}


void automated_test_cal_overflow()
{
    TEST_ASSERT_EQUAL(0, cal(INT_MAX, col,co,su,de));
    //TEST_ASSERT_EQUAL(0, cal(row, col,co,su,de));
}

void automated_test_cal_underflow()
{
    TEST_ASSERT_EQUAL(0, cal(INT_MIN,col,co,su,de));
}

int main(void)
{
 
  
  //getdata();
   
    manual_test_cal(row,col,co,su,de);
   
    UnityBegin(NULL);

    RUN_TEST(automated_test_cal);
    RUN_TEST(automated_test_cal_overflow);
    RUN_TEST(automated_test_cal_underflow);

    return (UnityEnd());
}

