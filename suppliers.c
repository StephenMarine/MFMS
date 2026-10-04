#include <stdio.h>
#include <string.h>
#include "suppliers.h"
#include "utilities.h"


static int  supplierIDs[MAX_SUPPLIERS];
static char supplierNames[MAX_SUPPLIERS][50];
static char supplierEmails[MAX_SUPPLIERS][50];
static char supplierPhones[MAX_SUPPLIERS][20];
static char supplierTowns[MAX_SUPPLIERS][50];
static int  supplierCount = 0;


void supplierMenu(void)
{
    int choice = 0;

    do
    {
        printf("\n--- SUPPLIER MANAGEMENT ---\n");
        printf("1. Add Supplier\n");
        printf("2. Display All Suppliers\n");
        printf("3. Search Supplier by Name\n");
        printf("4. Back to Main Menu\n");
        printf("Enter choice: ");
        choice = readInt("");

        switch (choice)
        {
            case 1: addSupplier();      break;
            case 2: displaySuppliers(); break;
            case 3: searchSupplier();   break;
            case 4: printf("\nReturning to main menu...\n"); break;
            default: printf("\nInvalid choice.\n");
        }
    } while (choice != 4);
}


void addSupplier(void)
{
    if (supplierCount >= MAX_SUPPLIERS)
    {
        printf("\nSupplier limit reached.\n");
        return;
    }

    printf("\n--- ADD SUPPLIER ---\n");

    supplierIDs[supplierCount] = readInt("Enter supplier ID: ");

    readLine("Enter supplier name: ", supplierNames[supplierCount], 50);
    readLine("Enter email: ",         supplierEmails[supplierCount], 50);
    readLine("Enter telephone: ",     supplierPhones[supplierCount], 20);
    readLine("Enter town/location: ", supplierTowns[supplierCount], 50);

    supplierCount++;

    printf("\nSupplier added successfully.\n");
}


void displaySuppliers(void)
{
    if (supplierCount == 0)
    {
        printf("\nNo suppliers have been added yet.\n");
        return;
    }

    printf("\n--- ALL SUPPLIERS ---\n");
    printf("%-6s %-22s %-25s %-15s %-15s\n",
           "ID", "Name", "Email", "Phone", "Town");
    printf("----------------------------------------------------------------------------------------\n");

    for (int i = 0; i < supplierCount; i++)
    {
        printf("%-6d %-22s %-25s %-15s %-15s\n",
               supplierIDs[i], supplierNames[i], supplierEmails[i],
               supplierPhones[i], supplierTowns[i]);

        /* Week 7 requirement: use strlen() */
        printf("       (name length: %d characters)\n",
               (int) strlen(supplierNames[i]));
    }
}


void searchSupplier(void)
{
    char searchName[50];
    int found = 0;

    if (supplierCount == 0)
    {
        printf("\nNo suppliers have been added yet.\n");
        return;
    }

    readLine("Enter supplier name to search: ", searchName, 50);

    for (int i = 0; i < supplierCount; i++)
    {
       
        if (strcmp(supplierNames[i], searchName) == 0)
        {
            char description[200];

            
            strcpy(description, supplierNames[i]);

            
            strcat(description, " operates in ");
            strcat(description, supplierTowns[i]);

            printf("\n--- SUPPLIER FOUND ---\n");
            printf("ID:       %d\n", supplierIDs[i]);
            printf("Name:     %s\n", supplierNames[i]);
            printf("Email:    %s\n", supplierEmails[i]);
            printf("Phone:    %s\n", supplierPhones[i]);
            printf("Town:     %s\n", supplierTowns[i]);
            printf("Summary:  %s\n", description);

            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nNo supplier found with name \"%s\".\n", searchName);
}


void supplierReport(void)
{
    if (supplierCount == 0)
    {
        printf("\nNo supplier data available.\n");
        return;
    }

    printf("\n========== SUPPLIER REPORT ==========\n");
    printf("Total Suppliers:  %d\n\n", supplierCount);

    printf("%-6s %-22s %-25s %-15s %-15s\n",
           "ID", "Name", "Email", "Phone", "Town");
    printf("----------------------------------------------------------------------------------------\n");

    for (int i = 0; i < supplierCount; i++)
    {
        printf("%-6d %-22s %-25s %-15s %-15s\n",
               supplierIDs[i], supplierNames[i], supplierEmails[i],
               supplierPhones[i], supplierTowns[i]);
    }
    printf("=====================================\n");
}
