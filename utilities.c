#include <stdio.h>
#include <string.h>
#include "utilities.h"
  --------------------------------------------------------- */
int readInt(const char *prompt)
{
    int value, result;
    char buffer[100];

    while (1)
    {
        if (prompt[0] != '\0')
            printf("%s", prompt);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
            continue;

        result = sscanf(buffer, "%d", &value);

        if (result == 1)
            return value;

        printf("Invalid number. Please try again.\n");
    }
}
double readPositiveDouble(const char *prompt)
{
    double value;
    int result;
    char buffer[100];

    while (1)
    {
        if (prompt[0] != '\0')
            printf("%s", prompt);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
            continue;

        result = sscanf(buffer, "%lf", &value);

        if (result != 1)
        {
            printf("Invalid number. Please try again.\n");
            continue;
        }

        if (value < 0)
        {
            printf("Value cannot be negative. Please try again.\n");
            continue;
        }

        return value;
    }
}
void readLine(const char *prompt, char *dest, int size)
{
    while (1)
    {
        if (prompt[0] != '\0')
            printf("%s", prompt);

        if (fgets(dest, size, stdin) == NULL)
            continue;

        dest[strcspn(dest, "\n")] = '\0';

        if (dest[0] == '\0')
        {
            printf("Input cannot be empty. Please try again.\n");
            continue;
        }

        return;
    }
}
