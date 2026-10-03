# MFMS
PAP521S Project A – Municipal Financial Management System
=======
# Municipal Financial Management System (MFMS)

## Course
PAP521S – Programming in Practice

## Project
Project A – Foundation System

## Programming Language
ANSI C (C99)

## Development Environment
Visual Studio Code + GCC

## Description
The Municipal Financial Management System (MFMS) is a
menu-driven C application designed to provide basic
municipal financial management functionality.

## System Modules

- Employee Management
- Budget Management
- Supplier Management
- Asset Management
- Reports

## Group Members

| Student | Student Number | Responsibility |
|---|---|---|
| Stephen | 223101605 | Integration, Validation, Testing and Documentation |
| Ismael | 224057626 | Employee Management |
| Lovemore | 226073831 | Budget Management |
| Absalom | 221124675 | Supplier Management |
| Namupala | 225019388 | Asset Management and Utilities |
| Ileka | 224036998 | Reports |

## Compilation

The project will be compiled using GCC.

```bash
gcc -std=c99 -Wall -Wextra -pedantic main.c employees.c budget.c suppliers.c assets.c reports.c utilities.c -o mfms