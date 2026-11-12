/* Lab 08 - Question 8: Grocery Stock Manager (Dynamic Array)
   C uses malloc() / free() in place of C++ new / delete[].
   Pointer-to-pointer (int **a) lets a function replace the array. */
#include <stdio.h>
#include <stdlib.h>

void display(int *a, int n)
{
    int i;
    if (n == 0) { printf("Stock is empty.\n"); return; }
    printf("\nPosition : Stock\n");
    for (i = 0; i < n; i++)
        printf("   %d     : %d\n", i + 1, *(a + i));
}

void report(int *a, int n)
{
    int i, total = 0, minPos = 0;
    if (n == 0) { printf("Total stock: 0 (no items)\n"); return; }
    for (i = 0; i < n; i++)
    {
        total += *(a + i);
        if (*(a + i) < *(a + minPos)) minPos = i;
    }
    printf("Total stock: %d\n", total);
    printf("Lowest stock: item at position %d with %d units\n",
           minPos + 1, *(a + minPos));
}

void updateStock(int *a, int n)
{
    int pos, val;
    if (n == 0) { printf("No items to update.\n"); return; }
    printf("Enter position (1-%d): ", n);
    scanf("%d", &pos);
    if (pos < 1 || pos > n) { printf("Invalid position!\n"); return; }
    printf("Enter new stock value: ");
    scanf("%d", &val);
    if (val < 0) { printf("Stock cannot be negative!\n"); return; }
    *(a + pos - 1) = val;
    report(a, n);
}

void insertItem(int **a, int *n)
{
    int i, pos, val;
    printf("Enter position to insert (1-%d): ", *n + 1);
    scanf("%d", &pos);
    if (pos < 1 || pos > *n + 1) { printf("Invalid position!\n"); return; }
    printf("Enter stock value of the new item: ");
    scanf("%d", &val);
    if (val < 0) { printf("Stock cannot be negative!\n"); return; }

    int *b = (int *)malloc((*n + 1) * sizeof(int));
    if (b == NULL) { printf("Memory allocation failed!\n"); return; }
    for (i = 0; i < pos - 1; i++) *(b + i) = *(*a + i);
    *(b + pos - 1) = val;
    for (i = pos - 1; i < *n; i++) *(b + i + 1) = *(*a + i);

    free(*a);
    *a = b;
    (*n)++;
    report(*a, *n);
}

void deleteItem(int **a, int *n)
{
    int i, j, pos;
    if (*n == 0) { printf("No items to delete.\n"); return; }
    printf("Enter position to delete (1-%d): ", *n);
    scanf("%d", &pos);
    if (pos < 1 || pos > *n) { printf("Invalid position!\n"); return; }

    int *b = NULL;
    if (*n - 1 > 0)
    {
        b = (int *)malloc((*n - 1) * sizeof(int));
        if (b == NULL) { printf("Memory allocation failed!\n"); return; }
        for (i = 0, j = 0; i < *n; i++)
            if (i != pos - 1) *(b + j++) = *(*a + i);
    }

    free(*a);
    *a = b;
    (*n)--;
    report(*a, *n);
}

void sortStock(int *a, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (*(a + j) > *(a + j + 1))
            {
                int t = *(a + j);
                *(a + j) = *(a + j + 1);
                *(a + j + 1) = t;
            }
    printf("Stock sorted in ascending order.\n");
    display(a, n);
    report(a, n);
}

int main(void)
{
    int n, i;
    do {
        printf("Enter starting number of items (3-8): ");
        scanf("%d", &n);
        if (n < 3 || n > 8) printf("Invalid size!\n");
    } while (n < 3 || n > 8);

    int *stock = (int *)malloc(n * sizeof(int));
    if (stock == NULL) { printf("Memory allocation failed!\n"); return 1; }

    for (i = 0; i < n; i++)
    {
        do {
            printf("Enter stock of item %d: ", i + 1);
            scanf("%d", stock + i);
            if (*(stock + i) < 0) printf("Stock cannot be negative!\n");
        } while (*(stock + i) < 0);
    }
    report(stock, n);

    int choice;
    do {
        printf("\n====== GROCERY STOCK MENU ======\n"
               "1. Display stock\n2. Update stock of one item\n"
               "3. Insert a new item\n4. Delete an item\n"
               "5. Sort stock\n6. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: display(stock, n); report(stock, n); break;
            case 2: updateStock(stock, n); break;
            case 3: insertItem(&stock, &n); break;
            case 4: deleteItem(&stock, &n); break;
            case 5: sortStock(stock, n); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);

    free(stock);
    stock = NULL;
    printf("Memory released. Goodbye!\n");
    return 0;
}
