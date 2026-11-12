/* Lab 08 - Question 5: Stationery Shop Profit/Loss using Pointers */
#include <stdio.h>

int main(void)
{
    /* Step 1: variables */
    double costPrice, sellPrice, quantity;

    /* Step 2: pointers, input through pointers only */
    double *pCost = &costPrice;
    double *pSell = &sellPrice;
    double *pQty  = &quantity;

    do {
        printf("Enter cost price per item: ");
        scanf("%lf", pCost);
    } while (*pCost < 0);
    do {
        printf("Enter selling price per item: ");
        scanf("%lf", pSell);
    } while (*pSell < 0);
    do {
        printf("Enter quantity sold: ");
        scanf("%lf", pQty);
    } while (*pQty < 0);

    /* Step 3: results stored and calculated through pointers */
    double totalCost, totalSales, profit;
    double *pTotalCost  = &totalCost;
    double *pTotalSales = &totalSales;
    double *pProfit     = &profit;

    *pTotalCost  = *pCost * *pQty;
    *pTotalSales = *pSell * *pQty;
    *pProfit     = *pTotalSales - *pTotalCost;

    printf("\nTotal Cost  : Rs. %.2f\n", *pTotalCost);
    printf("Total Sales : Rs. %.2f\n", *pTotalSales);

    /* Step 4: decision structure */
    if (*pProfit > 0)
        printf("Result      : Profit of Rs. %.2f\n", *pProfit);
    else if (*pProfit < 0)
        printf("Result      : Loss of Rs. %.2f\n", -(*pProfit));
    else
        printf("Result      : No profit no loss\n");

    /* Step 5: profit percentage */
    double percent = 0;
    double *pPercent = &percent;
    if (*pTotalCost != 0)
        *pPercent = (*pProfit / *pTotalCost) * 100;
    printf("Profit %%    : %.2f%%\n", *pPercent);

    /* Step 6: pointer to the larger price */
    double *pLarger = (*pCost > *pSell) ? pCost : pSell;
    printf("\nLarger price: %s = %.2f\n",
           (*pCost > *pSell) ? "costPrice" : "sellPrice", *pLarger);

    /* Step 7: address table */
    printf("\n------------------- ADDRESS TABLE -------------------\n");
    printf("%-14s %-20s %s\n", "Name", "Address", "Points to");
    printf("%-14s %-20p %s\n", "costPrice",   (void *)&costPrice,   "-");
    printf("%-14s %-20p %s\n", "sellPrice",   (void *)&sellPrice,   "-");
    printf("%-14s %-20p %s\n", "quantity",    (void *)&quantity,    "-");
    printf("%-14s %-20p %s\n", "totalCost",   (void *)&totalCost,   "-");
    printf("%-14s %-20p %s\n", "totalSales",  (void *)&totalSales,  "-");
    printf("%-14s %-20p %s\n", "profit",      (void *)&profit,      "-");
    printf("%-14s %-20p %s\n", "percent",     (void *)&percent,     "-");
    printf("%-14s %-20p %p\n", "pCost",       (void *)&pCost,       (void *)pCost);
    printf("%-14s %-20p %p\n", "pSell",       (void *)&pSell,       (void *)pSell);
    printf("%-14s %-20p %p\n", "pQty",        (void *)&pQty,        (void *)pQty);
    printf("%-14s %-20p %p\n", "pTotalCost",  (void *)&pTotalCost,  (void *)pTotalCost);
    printf("%-14s %-20p %p\n", "pTotalSales", (void *)&pTotalSales, (void *)pTotalSales);
    printf("%-14s %-20p %p\n", "pProfit",     (void *)&pProfit,     (void *)pProfit);
    printf("%-14s %-20p %p\n", "pPercent",    (void *)&pPercent,    (void *)pPercent);
    printf("%-14s %-20p %p\n", "pLarger",     (void *)&pLarger,     (void *)pLarger);
    return 0;
}
