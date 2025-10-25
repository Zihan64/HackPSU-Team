#include <stdio.h>
#include "finance.h"
int main() {
    Record records[MAX_RECORDS];
    int count = 0;
    int choice;
    while (1) {
        printf("Weekly Finance Tracker\n");
        printf("1. Add record\n");
        printf("2. Show summary\n");
        printf("3. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);
        if (choice == 1)
            addRecord(records, &count);
        else if (choice == 2)
            showSummary(records, count);
        else if (choice == 3)
            break;
        else
            printf("Invalid option. Try again.\n");
    }

    printf("Goodbye!\n");
    return 0;
}