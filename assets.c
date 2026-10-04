#include <stdio.h>
#include <string.h>
#include "assets.h"
#include "utilities.h"

static int    assetIDs[MAX_ASSETS];
static char   assetNames[MAX_ASSETS][50];
static char   assetTypes[MAX_ASSETS][50];
static double assetValues[MAX_ASSETS];
static char   assetDepts[MAX_ASSETS][50];
static char   assetConditions[MAX_ASSETS][20];
static int    assetCount = 0;

double calculateTotalAssetValue(void)
{
    double total = 0.0;
    for (int i = 0; i < assetCount; i++)
        total += assetValues[i];
    return total;
}

void assetMenu(void)
{
    int choice = 0;

    do
    {
        printf("\n--- ASSET MANAGEMENT ---\n");
        printf("1. Add Asset\n");
        printf("2. Display All Assets\n");
        printf("3. Search Asset by Name\n");
        printf("4. Show Total Asset Value\n");
        printf("5. Back to Main Menu\n");
        printf("Enter choice: ");
        choice = readInt("");

        switch (choice)
        {
            case 1: addAsset();      break;
            case 2: displayAssets(); break;
            case 3: searchAsset();   break;
            case 4:
                printf("\nTotal value of all assets: %.2f\n",
                       calculateTotalAssetValue());
                break;
            case 5: printf("\nReturning to main menu...\n"); break;
            default: printf("\nInvalid choice.\n");
        }
    } while (choice != 5);
}

void addAsset(void)
{
    if (assetCount >= MAX_ASSETS)
    {
        printf("\nAsset limit reached.\n");
        return;
    }

    printf("\n--- ADD ASSET ---\n");

    assetIDs[assetCount] = readInt("Enter asset ID: ");

    readLine("Enter asset name: ", assetNames[assetCount], 50);
    readLine("Enter asset type: ", assetTypes[assetCount], 50);

    assetValues[assetCount] = readPositiveDouble("Enter purchase value: ");

    readLine("Enter department: ", assetDepts[assetCount], 50);
    readLine("Enter condition: ",  assetConditions[assetCount], 20);

    assetCount++;

    printf("\nAsset added successfully.\n");
}

void displayAssets(void)
{
    if (assetCount == 0)
    {
        printf("\nNo assets have been added yet.\n");
        return;
    }

    printf("\n--- ALL ASSETS ---\n");
    printf("%-6s %-20s %-15s %12s %-15s %-10s\n",
           "ID", "Name", "Type", "Value", "Department", "Condition");
    printf("--------------------------------------------------------------------------------------\n");

    for (int i = 0; i < assetCount; i++)
    {
        printf("%-6d %-20s %-15s %12.2f %-15s %-10s\n",
               assetIDs[i], assetNames[i], assetTypes[i],
               assetValues[i], assetDepts[i], assetConditions[i]);
    }

    printf("\nTotal asset value: %.2f\n", calculateTotalAssetValue());
}

void searchAsset(void)
{
    char searchName[50];
    int found = 0;

    if (assetCount == 0)
    {
        printf("\nNo assets have been added yet.\n");
        return;
    }

    readLine("Enter asset name to search: ", searchName, 50);

    for (int i = 0; i < assetCount; i++)
    {
        if (strcmp(assetNames[i], searchName) == 0)
        {
            printf("\n--- ASSET FOUND ---\n");
            printf("ID:          %d\n", assetIDs[i]);
            printf("Name:        %s\n", assetNames[i]);
            printf("Type:        %s\n", assetTypes[i]);
            printf("Value:       %.2f\n", assetValues[i]);
            printf("Department:  %s\n", assetDepts[i]);
            printf("Condition:   %s\n", assetConditions[i]);

            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nNo asset found with name \"%s\".\n", searchName);
}

void assetReport(void)
{
    if (assetCount == 0)
    {
        printf("\nNo asset data available.\n");
        return;
    }

    printf("\n========== ASSET REPORT ==========\n");
    printf("Total Assets:      %d\n", assetCount);
    printf("Total Asset Value: %.2f\n\n", calculateTotalAssetValue());

    printf("%-6s %-20s %-15s %12s %-15s %-10s\n",
           "ID", "Name", "Type", "Value", "Department", "Condition");
    printf("--------------------------------------------------------------------------------------\n");

    for (int i = 0; i < assetCount; i++)
    {
        printf("%-6d %-20s %-15s %12.2f %-15s %-10s\n",
               assetIDs[i], assetNames[i], assetTypes[i],
               assetValues[i], assetDepts[i], assetConditions[i]);
    }
    printf("==================================\n");
}
