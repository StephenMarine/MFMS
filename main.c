/* =========================================================
   main.c
   Municipal Financial Management System - main coordinator.

   This file only contains main() and displayMainMenu().
   All module logic lives in the corresponding modules:

     - employees.c / employees.h
     - budget.c    / budget.h
     - suppliers.c / suppliers.h
     - assets.c    / assets.h
     - reports.c   / reports.h
     - utilities.c / utilities.h
   ========================================================= */

#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"
#include "utilities.h"

/* ---------------------------------------------------------
   displayMainMenu
   --------------------------------------------------------- */
void displayMainMenu(void)
{
    printf("\n");
    printf("========================================\n");
    printf("  MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("----------------------------------------\n");
    printf("Enter your choice: ");
}

/* ---------------------------------------------------------
   main
   --------------------------------------------------------- */
int main(void)
{
    int choice = 0;

    do
    {
        displayMainMenu();
        choice = readInt("");

        switch (choice)
        {
            case 1: employeeMenu(); break;
            case 2: budgetMenu();   break;
            case 3: supplierMenu(); break;
            case 4: assetMenu();    break;
            case 5: reportsMenu();  break;
            case 6: printf("\nGoodbye. Exiting MFMS.\n"); break;
            default: printf("\nInvalid choice. Please enter 1-6.\n");
        }

    } while (choice != 6);

    return 0;
}