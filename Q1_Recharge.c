/* Lab 08 - Question 1: Prepaid Mobile Recharge */
#include <stdio.h>

void printMenu(void)
{
    printf("\n=========== MOBILE RECHARGE ===========\n");
    printf("1. Rs. 100\n2. Rs. 200\n3. Rs. 500\n4. Rs. 1000\n");
    printf("=======================================\n");
}

int getPackNumber(void)
{
    int p;
    do {
        printf("Enter pack number (1-4): ");
        scanf("%d", &p);
        if (p < 1 || p > 4) printf("Invalid pack! Try again.\n");
    } while (p < 1 || p > 4);
    return p;
}

long long getMobileNumber(void)
{
    long long m;
    /* A number like 03001234567 loses its leading zero when stored as a
       number, so 10 or 11 digits are accepted and printed with a leading 0. */
    do {
        printf("Enter mobile number (11 digits): ");
        scanf("%lld", &m);
        if (m < 1000000000LL || m > 99999999999LL)
            printf("Invalid number! Try again.\n");
    } while (m < 1000000000LL || m > 99999999999LL);
    return m;
}

int getPackAmount(int pack)
{
    int amount;
    switch (pack)
    {
        case 1: amount = 100;  break;
        case 2: amount = 200;  break;
        case 3: amount = 500;  break;
        case 4: amount = 1000; break;
        default: amount = 0;
    }
    return amount;
}

double addTax(double amount)
{
    return amount + amount * 0.15;   /* amount with 15% tax */
}

double getBonus(double amount)
{
    if (amount >= 500)
        return amount * 0.10;
    return 0;
}

void printSlip(long long mobile, double amount, double tax, double totalBalance)
{
    printf("\n------------ RECHARGE SLIP ------------\n");
    printf("Mobile Number  : %011lld\n", mobile);
    printf("Pack Amount    : Rs. %.2f\n", amount);
    printf("Tax (15%%)      : Rs. %.2f\n", tax);
    printf("Total Balance  : Rs. %.2f (amount + bonus)\n", totalBalance);
    printf("---------------------------------------\n");
}

int main(void)
{
    double totalSpent = 0;
    int i;

    for (i = 1; i <= 3; i++)
    {
        printf("\n*** Recharge %d of 3 ***", i);
        printMenu();
        int pack = getPackNumber();
        long long mobile = getMobileNumber();

        double amount = getPackAmount(pack);
        double amountWithTax = addTax(amount);
        double tax = amountWithTax - amount;
        double bonus = getBonus(amount);
        double totalBalance = amount + bonus;

        printSlip(mobile, amount, tax, totalBalance);
        totalSpent += amountWithTax;     /* user pays amount + tax */
    }

    printf("\nTotal money spent: Rs. %.2f\n", totalSpent);
    return 0;
}
