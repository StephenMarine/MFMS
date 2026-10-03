#ifndef ASSETS_H
#define ASSETS_H

/* =========================================================
   assets.h
   Asset module: add, display, search, total, report.
   ========================================================= */

#define MAX_ASSETS 50

void   assetMenu(void);
void   addAsset(void);
void   displayAssets(void);
void   searchAsset(void);
void   assetReport(void);
double calculateTotalAssetValue(void);

#endif
