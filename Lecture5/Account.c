#include "Account.h"
#include <stdlib.h>

static int accountNo;
static double creditLimit;
static double balance;

account_t create(int accountNo, double creditLimit) {
	account_t newAccount = calloc(sizeof(account), 1);

	if (NULL == newAccount) {
		return NULL;
	}

	newAccount->accountNo = accountNo;
	newAccount->creditLimit = creditLimit;
	newAccount->balance = 0;

	return newAccount;
}

void destroy(account_t self) {
	if (NULL != self) {
		free(self);
	}
}

account_status_t withdraw(account_t self, double amount) {
	double tmp = getBalance(self) - amount;
	if (getAccountNo(self) > 0) {
		if (tmp >= 0) {
			self->balance = tmp;
			return OK;
		}
		else return OVER_MAX_CREDIT_LIMIT;
	}
	else return ACCOUNT_NOT_INSTANTIATED;

}

account_status_t deposit(account_t self, double amount) {
	double tmp = getBalance(self) + amount;
	if (getAccountNo(self) > 0) {
		if (tmp > getCreditLimit(self)) {
			return OVER_MAX_CREDIT_LIMIT;
		}
		else {
			self->balance = tmp;
			return OK;
		}
	}
	else return ACCOUNT_NOT_INSTANTIATED;
}

double getBalance(account_t self) {
	return self->balance;
}

double getCreditLimit(account_t self) {
	return self->creditLimit;
}

int getAccountNo(account_t self) {
	return self->accountNo;
}