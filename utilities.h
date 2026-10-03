#ifndef UTILITIES_H
#define UTILITIES_H

/* =========================================================
   utilities.h
   Input helper functions used by all MFMS modules.
   ========================================================= */

int    readInt(const char *prompt);
double readPositiveDouble(const char *prompt);
void   readLine(const char *prompt, char *dest, int size);

#endif
