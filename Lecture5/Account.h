#pragma once
#include <stdint.h>

typedef enum {
	OK = 1
	, OVER_MAX_CREDIT_LIMIT
	, ACCOUNT_NOT_INSTANTIATED
} account_status_t;

typedef struct account* account_t;

typedef struct account {
	int accountNo;
	double creditLimit;
	double balance;
} account;

account_t create(int accountNo, double creditLimit);
void destroy(account_t self);
account_status_t withdraw(account_t self, double amount);
account_status_t deposit(account_t self, double amount);
double getBalance(account_t self);
double getCreditLimit(account_t self);
int getAccountNo(account_t self);