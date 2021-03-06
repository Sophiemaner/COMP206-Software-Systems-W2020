//Author: Joseph Vybihal
//Git Repository: https://github.com/Ridwan2606/COMP206-Software-Systems-W2020

#include<stdio.h>
#include<stdlib.h>

struct BANK_ACCOUNT {
	char type; // 'S'=savings, 'C'=checking
	double balance;

	union ACCOUNT_SPECIFIC {
		double charge; // for withdrawal from savings accounts
		int credit_score; //for checking account
	} specific;
};


int main(int argc, char *argv[]) {

	struct BANK_ACCOUNT accounts[100];

	int nextSpot = 0;
	int newAccounts;

	printf("How many accounts are being created:"); 
	scanf("%d", &newAccounts);
	
	for (int i =0; i < newAccounts; i++) {

		printf("What is the type of the account ('C'/'S') ");
		
		scanf(" %c", &accounts[nextSpot].type);
		printf("How much money does the account hold: ");
		
		scanf("%lf", &accounts[nextSpot].balance);
		
		if (accounts[nextSpot].type == 'C') {
			printf("What is the account credit score: ");
			scanf(" %d", &accounts[nextSpot].specific.credit_score);
		} else if (accounts[nextSpot].type == 'S') {
			printf("What is the charge on the account: ");
			scanf("%lf", &accounts[nextSpot].specific.charge);
		}
		nextSpot++;
		printf(" - Account Created - \n");
	}
	
	printf(" --- Displaying Accounts --- \n");

	for(int j = 0; j < nextSpot; j++) {
		printf("Account #%d of type %c holding: %.2f $", j, accounts[j].type, accounts[j].balance);
		if (accounts[j].type == 'C') {
			printf(" with a credit score of %d \n", accounts[j].specific.credit_score);
		} else if (accounts[j].type == 'S') {
			printf(" with a charge of %.2f $ \n", accounts[j].specific.charge);
		}
	}


	return 0;
}

