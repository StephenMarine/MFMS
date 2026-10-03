/* =========================================================
   budget.c
   Budget module implementation.
   ========================================================= */

#include <stdio.h>
#include <string.h>
#include "budget.h"
#include "utilities.h"

/* ---------------------------------------------------------
   Private data
   --------------------------------------------------------- */
static char   budgetDepts[MAX_BUDGETS][50];
static double budgetAllocated[MAX_BUDGETS];
static double budgetSpent[MAX_BUDGETS];
static int    budgetCount = 0;

/* ---------------------------------------------------------
   calculateRemaining
   --------------------------------------------------------- */
double calculateRemaining(double allocated, double spent)
{
    return allocated - spent;
}

/* ---------------------------------------------------------
   budgetMenu
   --------------------------------------------------------- */
void budgetMenu(void)
{
    int choice = 0;

    do
    {
        printf("\n--- BUDGET MANAGEMENT ---\n");
        printf("1. Add Department Budget\n");
        printf("2. Display All Budgets\n");
        printf("3. Back to Main Menu\n");
        printf("Enter choice: ");
        choice = readInt("");

        switch (choice)
        {
            case 1: addBudget();      break;
            case 2: displayBudgets(); break;
            case 3: printf("\nReturning to main menu...\n"); break;
            default: printf("\nInvalid choice.\n");
        }
    } while (choice != 3);
}

/* ---------------------------------------------------------
   addBudget
   --------------------------------------------------------- */
void addBudget(void)
{
    if (budgetCount >= MAX_BUDGETS)
    {
        printf("\nBudget limit reached.\n");
        return;
    }

    printf("\n--- ADD BUDGET ---\n");

    readLine("Enter department name: ", budgetDepts[budgetCount], 50);

    budgetAllocated[budgetCount] = readPositiveDouble("Enter allocated budget: ");
    budgetSpent[budgetCount]     = readPositiveDouble("Enter expenditure: ");

    budgetCount++;

    printf("\nBudget recorded successfully.\n");
}

/* ---------------------------------------------------------
   displayBudgets
   --------------------------------------------------------- */
void displayBudgets(void)
{
    if (budgetCount == 0)
    {
        printf("\nNo budgets have been added yet.\n");
        return;
    }

    printf("\n--- ALL DEPARTMENT BUDGETS ---\n");
    printf("%-15s %12s %12s %12s   %s\n",
           "Department", "Allocated", "Spent", "Remaining", "Status");
    printf("------------------------------------------------------------------\n");

    for (int i = 0; i < budgetCount; i++)
    {
        double remaining = calculateRemaining(budgetAllocated[i],
                                              budgetSpent[i]);
        const char *status = (remaining < 0) ? "OVER BUDGET" : "WITHIN BUDGET";

        printf("%-15s %12.2f %12.2f %12.2f   %s\n",
               budgetDepts[i], budgetAllocated[i], budgetSpent[i],
               remaining, status);
    }
}

/* ---------------------------------------------------------
   budgetReport
   --------------------------------------------------------- */
void budgetReport(void)
{
    if (budgetCount == 0)
    {
        printf("\nNo budget data available.\n");
        return;
    }

    double totalAllocated = 0.0;
    double totalSpent     = 0.0;

    for (int i = 0; i < budgetCount; i++)
    {
        totalAllocated += budgetAllocated[i];
        totalSpent     += budgetSpent[i];
    }

    printf("\n========== BUDGET REPORT ==========\n");
    printf("Total Allocated:  %.2f\n", totalAllocated);
    printf("Total Spent:      %.2f\n", totalSpent);
    printf("Remaining:        %.2f\n", totalAllocated - totalSpent);

    printf("\nDepartments exceeding budget:\n");
    int anyOver = 0;
    for (int i = 0; i < budgetCount; i++)
    {
        if (budgetSpent[i] > budgetAllocated[i])
        {
            printf("  - %s (over by %.2f)\n",
                   budgetDepts[i], budgetSpent[i] - budgetAllocated[i]);
            anyOver = 1;
        }
    }
    if (!anyOver) printf("  None\n");
    printf("===================================\n");
}
