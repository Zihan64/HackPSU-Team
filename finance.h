#ifndef FINANCE_H
#define FINANCE_H
#define MAX_RECORDS 50   // Maximum number of records per week
// struct to store each financial record
typedef struct {
    char name[50];// Description of the record
    double amount; // positive = income, negative = expense
} Record;
// Add a new record to the array
void addRecord(Record records[], int *count, const char *desc, double amount);
// Generate a summary of all records as a formatted string
void showSummary(Record records[], int count, char *output, int output_size);
#endif