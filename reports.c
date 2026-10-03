/* =========================================================
   reports.c
   Reports module implementation.
   Calls report functions exposed by other modules.
   ========================================================= */

#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "utilities.h"

/* ---------------------------------------------------------
   reportsMenu
   --------------------------------------------------------- */
void reportsMenu(void)
{
    int choice = 0;

    do
    {
        printf("\n--- REPORTS ---\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Back to Main Menu\n");
        printf("Enter choice: ");
        choice = readInt("");

        switch (choice)
        {
            case 1: employeeReport(); break;
            case 2: budgetReport();   break;
            case 3: supplierReport(); break;
            case 4: assetReport();    break;
            case 5: printf("\nReturning to main menu...\n"); break;
            default: printf("\nInvalid choice.\n");
        }
    } while (choice != 5);
}
