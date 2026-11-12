/* Lab 08 - Question 2: Hospital Final Bill */
#include <stdio.h>

void printRates(void)
{
    printf("\n========== CITY CARE HOSPITAL ==========\n");
    printf("Room Charges:\n");
    printf("1. General Ward  - Rs. 1500/day\n");
    printf("2. Semi-Private  - Rs. 3500/day\n");
    printf("3. Private       - Rs. 6000/day\n");
    printf("========================================\n");
}

int getRoomType(void)
{
    int t;
    do {
        printf("Enter room type (1-3): ");
        scanf("%d", &t);
        if (t < 1 || t > 3) printf("Invalid room type!\n");
    } while (t < 1 || t > 3);
    return t;
}

int getDays(void)
{
    int d;
    do {
        printf("Enter number of days stayed (1-30): ");
        scanf("%d", &d);
        if (d < 1 || d > 30) printf("Invalid number of days!\n");
    } while (d < 1 || d > 30);
    return d;
}

const char *getRoomName(int type)
{
    switch (type)
    {
        case 1: return "General Ward";
        case 2: return "Semi-Private";
        default: return "Private";
    }
}

double getRoomCharges(int type, int days)
{
    int rate;
    switch (type)
    {
        case 1: rate = 1500; break;
        case 2: rate = 3500; break;
        default: rate = 6000;
    }
    return rate * days;
}

double getMedicineCharge(void)
{
    double bill;
    do {
        printf("Enter medicine bill: ");
        scanf("%lf", &bill);
        if (bill < 0) printf("Bill cannot be negative!\n");
    } while (bill < 0);
    return bill + bill * 0.05;      /* 5% service charge */
}

double applyDiscount(double total, int days)
{
    if (days >= 7)
        return total - total * 0.08;   /* 8% off */
    return total;
}

void printBill(const char *roomName, int days, double roomCharges,
               double medicineCharges, double finalAmount)
{
    printf("\n------------- FINAL BILL -------------\n");
    printf("Room Type         : %s\n", roomName);
    printf("Days Stayed       : %d\n", days);
    printf("Room Charges      : Rs. %.2f\n", roomCharges);
    printf("Medicine Charges  : Rs. %.2f\n", medicineCharges);
    printf("Final Amount      : Rs. %.2f\n", finalAmount);
    printf("--------------------------------------\n");
}

int main(void)
{
    printRates();
    int type = getRoomType();
    int days = getDays();

    double roomCharges = getRoomCharges(type, days);
    double medicineCharges = getMedicineCharge();
    double finalAmount = applyDiscount(roomCharges + medicineCharges, days);

    char senior;
    printf("Is the patient a senior citizen? (y/n): ");
    scanf(" %c", &senior);
    if (senior == 'y' || senior == 'Y')
    {
        finalAmount -= 1000;
        if (finalAmount < 0) finalAmount = 0;   /* bill never below 0 */
    }

    printBill(getRoomName(type), days, roomCharges, medicineCharges, finalAmount);
    return 0;
}
