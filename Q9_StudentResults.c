/* Lab 08 - Question 9: Student Results
   C has no reference parameters (int &x). The same effect is done by passing
   the address of a variable (int *x) and changing it with *x. */
#include <stdio.h>
#include <string.h>

void readMarks(int *m1, int *m2, int *m3)
{
    int *m[3];
    int i;
    m[0] = m1; m[1] = m2; m[2] = m3;
    for (i = 0; i < 3; i++)
    {
        do {
            printf("  Enter marks of subject %d (0-100): ", i + 1);
            scanf("%d", m[i]);
            if (*m[i] < 0 || *m[i] > 100) printf("  Invalid marks!\n");
        } while (*m[i] < 0 || *m[i] > 100);
    }
}

void calculateStats(int m1, int m2, int m3, int *total, double *average,
                    int *highest, int *lowest)
{
    *total = m1 + m2 + m3;
    *average = *total / 3.0;
    *highest = m1;
    if (m2 > *highest) *highest = m2;
    if (m3 > *highest) *highest = m3;
    *lowest = m1;
    if (m2 < *lowest) *lowest = m2;
    if (m3 < *lowest) *lowest = m3;
}

void swapMarks(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* Sorts the 3 marks from highest to lowest using swapMarks */
void sortMarks(int *a, int *b, int *c)
{
    if (*a < *b) swapMarks(a, b);
    if (*b < *c) swapMarks(b, c);
    if (*a < *b) swapMarks(a, b);
}

/* Pass mark is 40; grace of up to 5 marks, only for marks 35-39 */
void addGraceMarks(int *mark, int grace)
{
    if (*mark >= 35 && *mark <= 39)
    {
        if (grace > 5) grace = 5;
        *mark += grace;
        if (*mark > 40) *mark = 40;   /* only enough to pass */
    }
}

void findGrade(double avg, char *grade, char *remarks)
{
    if (avg >= 80)      { *grade = 'A'; strcpy(remarks, "Excellent"); }
    else if (avg >= 60) { *grade = 'B'; strcpy(remarks, "Good"); }
    else                { *grade = 'C'; strcpy(remarks, "Needs Improvement"); }
}

void incrementByValue(int x)      { x++; }
void incrementByReference(int *x) { (*x)++; }

int main(void)
{
    const int N = 5;
    int total[5], highest[5], lowest[5];
    double average[5];
    char grade[5];
    char remarks[5][20];
    int i;

    for (i = 0; i < N; i++)
    {
        int m1, m2, m3;
        printf("\nStudent %d:\n", i + 1);
        readMarks(&m1, &m2, &m3);

        addGraceMarks(&m1, 5);
        addGraceMarks(&m2, 5);
        addGraceMarks(&m3, 5);

        sortMarks(&m1, &m2, &m3);   /* highest to lowest */
        printf("  Marks (high to low, after grace): %d %d %d\n", m1, m2, m3);

        calculateStats(m1, m2, m3, &total[i], &average[i], &highest[i], &lowest[i]);
        findGrade(average[i], &grade[i], remarks[i]);
    }

    printf("\n=========================== RESULT TABLE ===========================\n");
    printf("%-10s%-8s%-10s%-8s%-8s%-8s%s\n",
           "Student", "Total", "Average", "High", "Low", "Grade", "Remarks");
    printf("--------------------------------------------------------------------\n");
    for (i = 0; i < N; i++)
        printf("%-10d%-8d%-10.2f%-8d%-8d%-8c%s\n",
               i + 1, total[i], average[i], highest[i], lowest[i], grade[i], remarks[i]);

    /* Pass by value vs pass by address (reference) demo */
    int num = 10;
    incrementByValue(num);
    printf("\nAfter incrementByValue     : %d\n", num);
    incrementByReference(&num);
    printf("After incrementByReference : %d\n", num);
    /* Why different: incrementByValue changes only a COPY of num, so the original stays 10.
       incrementByReference receives the address of num, so it changes the original to 11. */
    return 0;
}
