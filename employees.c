

#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "utilities.h"

static int    employeeIDs[MAX_EMPLOYEES];
static char   employeeNames[MAX_EMPLOYEES][50];
static char   employeeDepts[MAX_EMPLOYEES][50];
static double employeeBasic[MAX_EMPLOYEES];
static double employeeHousing[MAX_EMPLOYEES];
static double employeeTransport[MAX_EMPLOYEES];
static int    employeeCount = 0;


double calculateSalary(double basic, double housing, double transport)
{
    return basic + housing + transport;
}

void employeeMenu(void)
{
    int choice = 0;

    do
    {
        printf("\n--- EMPLOYEE MANAGEMENT ---\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Back to Main Menu\n");
        printf("Enter choice: ");
        choice = readInt("");

        switch (choice)
        {
            case 1: addEmployee();      break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee();   break;
            case 4: printf("\nReturning to main menu...\n"); break;
            default: printf("\nInvalid choice.\n");
        }
    } while (choice != 4);
}

void addEmployee(void)
{
    if (employeeCount >= MAX_EMPLOYEES)
    {
        printf("\nEmployee limit reached.\n");
        return;
    }

    printf("\n--- ADD EMPLOYEE ---\n");

    employeeIDs[employeeCount] = readInt("Enter employee ID: ");

    readLine("Enter full name: ",  employeeNames[employeeCount], 50);
    readLine("Enter department: ", employeeDepts[employeeCount], 50);

    employeeBasic[employeeCount]     = readPositiveDouble("Enter basic salary: ");
    employeeHousing[employeeCount]   = readPositiveDouble("Enter housing allowance: ");
    employeeTransport[employeeCount] = readPositiveDouble("Enter transport allowance: ");

    employeeCount++;

    printf("\nEmployee added successfully.\n");
}

void displayEmployees(void)
{
    if (employeeCount == 0)
    {
        printf("\nNo employees have been added yet.\n");
        return;
    }

    printf("\n--- ALL EMPLOYEES ---\n");
    printf("%-6s %-20s %-15s %12s\n", "ID", "Name", "Department", "Gross Salary");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < employeeCount; i++)
    {
        double gross = calculateSalary(employeeBasic[i],
                                       employeeHousing[i],
                                       employeeTransport[i]);

        printf("%-6d %-20s %-15s %12.2f\n",
               employeeIDs[i], employeeNames[i], employeeDepts[i], gross);
    }
}

void searchEmployee(void)
{
    int searchID;
    int found = 0;

    if (employeeCount == 0)
    {
        printf("\nNo employees have been added yet.\n");
        return;
    }

    searchID = readInt("Enter employee ID to search: ");

    for (int i = 0; i < employeeCount; i++)
    {
        if (employeeIDs[i] == searchID)
        {
            double gross = calculateSalary(employeeBasic[i],
                                           employeeHousing[i],
                                           employeeTransport[i]);

            printf("\n--- EMPLOYEE FOUND ---\n");
            printf("ID:            %d\n", employeeIDs[i]);
            printf("Name:          %s\n", employeeNames[i]);
            printf("Department:    %s\n", employeeDepts[i]);
            printf("Basic Salary:  %.2f\n", employeeBasic[i]);
            printf("Housing:       %.2f\n", employeeHousing[i]);
            printf("Transport:     %.2f\n", employeeTransport[i]);
            printf("Gross Salary:  %.2f\n", gross);

            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nNo employee found with ID %d.\n", searchID);
}

void employeeReport(void)
{
    if (employeeCount == 0)
    {
        printf("\nNo employee data available.\n");
        return;
    }

    double total = 0.0;
    double highest = calculateSalary(employeeBasic[0],
                                     employeeHousing[0],
                                     employeeTransport[0]);
    double lowest = highest;

    for (int i = 0; i < employeeCount; i++)
    {
        double gross = calculateSalary(employeeBasic[i],
                                       employeeHousing[i],
                                       employeeTransport[i]);
        total += gross;
        if (gross > highest) highest = gross;
        if (gross < lowest)  lowest  = gross;
    }

    printf("\n========== EMPLOYEE REPORT ==========\n");
    printf("Total Employees:  %d\n", employeeCount);
    printf("Average Salary:   %.2f\n", total / employeeCount);
    printf("Highest Salary:   %.2f\n", highest);
    printf("Lowest Salary:    %.2f\n", lowest);
    printf("=====================================\n");
}
