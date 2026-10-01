#ifndef EMPLOYEES_H
#define EMPLOYEES_H

/* =========================================================
   employees.h
   Employee module: add, display, search, salary, report.
   ========================================================= */

#define MAX_EMPLOYEES 100

void   employeeMenu(void);
void   addEmployee(void);
void   displayEmployees(void);
void   searchEmployee(void);
void   employeeReport(void);
double calculateSalary(double basic, double housing, double transport);

#endif
