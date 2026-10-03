#ifndef BUDGET_H
#define BUDGET_H

/* =========================================================
   budget.h
   Budget module: add, display, report.
   ========================================================= */

#define MAX_BUDGETS 50

void   budgetMenu(void);
void   addBudget(void);
void   displayBudgets(void);
void   budgetReport(void);
double calculateRemaining(double allocated, double spent);

#endif
