#include "Account.h"
#include<stdio.h>

int main() {
account_t a1 = create(1, 1000);
account_t a2 = create(2, 2000);
account_t a3 = create(3, 5000);
account_t a4 = create(4, 1200);
account_t a5 = create(0, 10);
account_t a6 = create(0, 0);
account_t a7= create(7, 0);
account_t a8 = create(8, 10000);
account_t a9 = create(9, 500.5);
account_t a10 = create(10, 3500);

printf("result_a1: %d \n", deposit(a1, 300));
printf("balance_a1: %f \n", getBalance(a1));

printf("result_a7: %d \n", withdraw(a7, 300));

printf("result_a5: %d \n" , deposit(a5, 500));
printf("result_a5b: %d \n", withdraw(a5, 500));

printf("result_a4: %d \n", deposit(a4, 5000));
}
