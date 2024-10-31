#include <stdio.h>
#include <stdlib.h>

void login();
void showBalance();
void deposit();
void withdraw();

int main() {
    int choice;

    printf("Welcome to the ATM System!\n");
    login();  // Call the login function

    do {
        printf("\n--- ATM Menu ---\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Cash\n");
        printf("3. Withdraw Cash\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: showBalance(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: printf("Thank you for using the ATM.\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void login() {
    int pin, attempts = 3;
    int correctPin = 1234;

    while (attempts > 0) {
        printf("Enter your PIN: ");
        scanf("%d", &pin);

        if (pin == correctPin) {
            printf("Login successful!\n");
            return;
        } else {
            attempts--;
            printf("Incorrect PIN. You have %d attempts left.\n", attempts);
        }
    }

    printf("Too many failed attempts. Exiting program.\n");
    exit(0);
}

float balance = 1000.0;

void showBalance() {
    printf("Current balance: $%.2f\n", balance);
}

void deposit() {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount > 0) {
        balance += amount;
        printf("Deposit successful. New balance: $%.2f\n", balance);
    } else {
        printf("Invalid amount.\n");
    }
}

void withdraw() {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        printf("Withdrawal successful. New balance: $%.2f\n", balance);
    } else if (amount > balance) {
        printf("Insufficient funds.\n");
    } else {
        printf("Invalid amount.\n");
    }
}
