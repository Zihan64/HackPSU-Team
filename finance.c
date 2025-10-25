#include <stdio.h>
#include "finance.h"
void addRecord(Record records[], int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Record list is full!\n");
        return;
    }
    printf("Enter description: ");
    scanf(" %[^\n]", records[*count].name);
    printf("Enter amount (positive=income, negative=expense): ");
    scanf("%lf", &records[*count].amount);

    (*count)++;
    printf("Record added!\n\n");
}
// Sum
void showSummary(Record records[], int count) {
    double total = 0;
    printf("\n----- Weekly Summary -----\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s: %.2f\n", i + 1, records[i].name, records[i].amount);
        total += records[i].amount;
    }
    printf("---------------------------\n");
    printf("Net balance this week: %.2f\n\n", total);
}