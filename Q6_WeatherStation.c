/* Lab 08 - Question 6: Weather Station (Dynamic Array)
   C uses malloc() / free() in place of C++ new / delete[]. */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, i;
    do {
        printf("How many days of temperature to store (1-10)? ");
        scanf("%d", &n);
        if (n < 1 || n > 10) printf("Invalid! Enter 1 to 10.\n");
    } while (n < 1 || n > 10);

    double *temp = (double *)malloc(n * sizeof(double));
    if (temp == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    /* Read temperatures (-10 to 55 only) */
    for (i = 0; i < n; i++)
    {
        do {
            printf("Enter temperature for Day %d (-10 to 55): ", i + 1);
            scanf("%lf", temp + i);
            if (*(temp + i) < -10 || *(temp + i) > 55)
                printf("Out of range! Try again.\n");
        } while (*(temp + i) < -10 || *(temp + i) > 55);
    }

    /* Print with addresses */
    printf("\n");
    for (i = 0; i < n; i++)
        printf("Day %d: %.1f at address %p\n", i + 1, *(temp + i), (void *)(temp + i));

    /* Hottest and coldest using a moving pointer */
    double *ptr = temp;
    double hottest = *ptr, coldest = *ptr;
    int hotter40 = 0;
    for (i = 0; i < n; i++, ptr++)
    {
        if (*ptr > hottest) hottest = *ptr;
        if (*ptr < coldest) coldest = *ptr;
        if (*ptr > 40) hotter40++;
    }

    printf("\nHottest temperature : %.1f\n", hottest);
    printf("Coldest temperature : %.1f\n", coldest);
    printf("Days hotter than 40 : %d\n", hotter40);

    /* Release memory */
    free(temp);
    temp = NULL;
    printf("\nMemory has been released successfully (temp = NULL).\n");
    return 0;
}
