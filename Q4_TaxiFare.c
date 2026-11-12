/* Lab 08 - Question 4: Taxi Fare Calculator */
#include <stdio.h>

void printRules(void)
{
    printf("\n============== TAXI FARE ==============\n");
    printf("Base fare            : Rs. 150\n");
    printf("First 10 km          : Rs. 60 per km\n");
    printf("After 10 km          : Rs. 45 per km\n");
    printf("Waiting              : first 5 min free, then Rs. 10/min\n");
    printf("Night (10pm - 6am)   : +25%%\n");
    printf("=======================================\n");
}

double getDistance(void)
{
    double d;
    do {
        printf("Enter distance in km (>0 to 200): ");
        scanf("%lf", &d);
        if (d <= 0 || d > 200) printf("Invalid distance!\n");
    } while (d <= 0 || d > 200);
    return d;
}

int getWaitingTime(void)
{
    int w;
    do {
        printf("Enter waiting time in minutes (0-120): ");
        scanf("%d", &w);
        if (w < 0 || w > 120) printf("Invalid waiting time!\n");
    } while (w < 0 || w > 120);
    return w;
}

int getHour(void)
{
    int h;
    do {
        printf("Enter hour of the trip (0-23): ");
        scanf("%d", &h);
        if (h < 0 || h > 23) printf("Invalid hour!\n");
    } while (h < 0 || h > 23);
    return h;
}

double getDistanceCharge(double distance)
{
    double charge = 150;                 /* base fare */
    if (distance <= 10)
        charge += distance * 60;
    else
        charge += 10 * 60 + (distance - 10) * 45;
    return charge;
}

double getWaitingCharge(int minutes)
{
    if (minutes <= 5) return 0;
    return (minutes - 5) * 10;
}

double addNightCharge(double fare, int hour)
{
    if (hour >= 22 || hour < 6)
        return fare + fare * 0.25;
    return fare;
}

void printReceipt(double distance, int waiting, double finalFare)
{
    printf("\n------------ TRIP RECEIPT ------------\n");
    printf("Distance      : %.2f km\n", distance);
    printf("Waiting Time  : %d min\n", waiting);
    printf("Final Fare    : Rs. %.2f\n", finalFare);
    printf("--------------------------------------\n");
}

int main(void)
{
    double totalEarnings = 0, highestFare = 0;
    int i;
    printRules();

    for (i = 1; i <= 3; i++)
    {
        printf("\n*** Trip %d of 3 ***\n", i);
        double distance = getDistance();
        int waiting = getWaitingTime();
        int hour = getHour();

        double fare = getDistanceCharge(distance) + getWaitingCharge(waiting);
        fare = addNightCharge(fare, hour);

        printReceipt(distance, waiting, fare);
        totalEarnings += fare;
        if (fare > highestFare) highestFare = fare;
    }

    printf("\nTotal earnings     : Rs. %.2f\n", totalEarnings);
    printf("Highest fare today : Rs. %.2f\n", highestFare);
    return 0;
}
