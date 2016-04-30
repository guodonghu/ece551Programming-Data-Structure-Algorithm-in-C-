#include<stdio.h>
#include<stdlib.h>
double calculate_balance (double regular_change,
		       double rate_of_returns,
		       double account) {
  return account * (1 + rate_of_returns) + regular_change;
}
struct retireinfo {
    int months;
    double regular_change;
    double rate_of_returns;
  };
typedef struct retireinfo retire_info;

void retirement (int startAge, 
		 double initial,
		 retire_info working, 
		 retire_info retired) {
  int i;
  double working_account = initial;
  for (i = startAge; i < startAge + working.months; i++ ) {
    printf("Age %3d month %2d you have $%.2lf\n", i/12, i%12, working_account);
    working_account = calculate_balance(working.regular_change, working.rate_of_returns,working_account);
      }
  int j;
  double retired_account = working_account;
  
  for (j = startAge + working.months; j < startAge + working.months + retired.months; j++ ) {
    printf("Age %3d month %2d you have $%.2lf\n", j/12, j%12, retired_account);
    retired_account = calculate_balance(retired.regular_change, retired.rate_of_returns, retired_account);
  }
      }


int main(void) {
  int startage = 327;
  double initial_savings =21345;
  retire_info working;
  retire_info retired;
  working.months = 489;
  working.regular_change =1000;
  working.rate_of_returns = 0.045/12;
  retired.months = 384;
  retired.regular_change = -4000;
  retired.rate_of_returns = 0.01/12;
  retirement (startage, initial_savings, working, retired);
  return EXIT_SUCCESS;
}
