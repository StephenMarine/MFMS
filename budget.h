#ifndef BUDGET_H
#define BUDGET_H
#define MAX_BUDGETS 50

void   budgetMenu(void);
void   addBudget(void);
void   displayBudgets(void);
void   budgetReport(void);
double calculateRemaining(double allocated, double spent);

#endif
