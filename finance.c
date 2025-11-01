#include <stdio.h>
#include <string.h>
#include "finance.h"
// Add a new record to the record list
void addRecord(Record records[], int *count, const char *desc, double amount) {
    if (*count >= MAX_RECORDS) {
        printf("Record list is full!\n");
        return;
    }
    // Copy description and amount to the next available record slot
    strcpy(records[*count].name, desc);
    records[*count].amount = amount;
    (*count)++;
}
// Generate a text summary of all records and their total balance
void showSummary(Record records[], int count, char *output, int output_size) {
    double total = 0.0;
    char buffer[1024] = "";
    strcpy(buffer, "----- Weekly Summary -----\n");
    for (int i = 0; i < count; i++) {
        char line[128];
        sprintf(line, "%d. %s: %.2f\n", i + 1, records[i].name, records[i].amount);
        strcat(buffer, line);
        total += records[i].amount;
    }
    sprintf(buffer + strlen(buffer), "\nNet balance: %.2f\n", total);
    // Copy summary to output buffer with safety limit
    strncpy(output, buffer, output_size - 1);
    output[output_size - 1] = '\0';
}