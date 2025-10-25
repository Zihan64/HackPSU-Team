#ifndef FINANCE_H
#define FINANCE_H
#define MAX_RECORDS 50   // 50 max records each week
typedef struct {
    char name[50];   
    double amount;   // Positive = income Negative = Expense
} Record;
void addRecord(Record records[], int *count);
void showSummary(Record records[], int count);
#endif