#include <stdio.h>
int main() {
    double costPrice = 0.0, sellPrice = 0.0, quantity = 0.0;
    double totalCost = 0.0, totalSales = 0.0, profitOrLoss = 0.0, profitPercentage = 0.0;

    double *ptrCost = &costPrice;
    double *ptrSell = &sellPrice;
    double *ptrQty = &quantity;
    double *ptrTotalCost = &totalCost;
    double *ptrTotalSales = &totalSales;
    double *ptrProfitLoss = &profitOrLoss;
    double *ptrProfitPercentage = &profitPercentage;
    double *ptrLarger = NULL;

    printf("Enter cost price per unit: ");
    scanf("%lf", ptrCost);

    printf("Enter selling price per unit: ");
    scanf("%lf", ptrSell);

    printf("Enter quantity sold: ");
    scanf("%lf", ptrQty);
    *ptrTotalCost = (*ptrCost) * (*ptrQty);
    *ptrTotalSales = (*ptrSell) * (*ptrQty);
    *ptrProfitLoss = (*ptrTotalSales) - (*ptrTotalCost);

    printf("\n--- Result --- \n");
    if (*ptrProfitLoss > 0) {
        printf("Profit\n");
    } else if (*ptrProfitLoss < 0) {
        printf("Loss\n");
    } else {
        printf("No profit no loss\n");
    }

    if (*ptrTotalCost > 0) {
        *ptrProfitPercentage = (*ptrProfitLoss / *ptrTotalCost) * 100.0;
    } else {
        *ptrProfitPercentage = 0.0;
    }
    printf("Profit/Loss Percentage: %.2f%%\n", *ptrProfitPercentage);

    if (*ptrCost > *ptrSell) {
        ptrLarger = ptrCost;
        printf("ptrLarger points to: Cost Price (Value: %.2f)\n", *ptrLarger);
    } else if (*ptrSell > *ptrCost) {
        ptrLarger = ptrSell;
        printf("ptrLarger points to: Selling Price (Value: %.2f)\n", *ptrLarger);
    } else {
        ptrLarger = ptrCost;
        printf("Cost Price and Selling Price are equal (Value: %.2f)\n", *ptrLarger);
    }

    printf("\n---------------------------------------------------------------\n");
    printf("%-25s  %-15s  %-20s\n", "Entity Name", "Data Type", "Memory Address");
    printf("---------------------------------------------------------------\n");
    printf("%-25s  %-15s  %p\n", "costPrice", "double", (void*)&costPrice);
    printf("%-25s  %-15s  %p\n", "sellPrice", "double", (void*)&sellPrice);
    printf("%-25s  %-15s  %p\n", "quantity", "double", (void*)&quantity);
    printf("%-25s  %-15s  %p\n", "totalCost", "double", (void*)&totalCost);
    printf("%-25s  %-15s  %p\n", "totalSales", "double", (void*)&totalSales);
    printf("%-25s  %-15s  %p\n", "profitOrLoss", "double", (void*)&profitOrLoss);
    printf("%-25s  %-15s  %p\n", "profitPercentage", "double", (void*)&profitPercentage);
    printf("%-25s  %-15s  %p\n", "ptrCost", "double*", (void*)&ptrCost);
    printf("%-25s  %-15s  %p\n", "ptrSell", "double*", (void*)&ptrSell);
    printf("%-25s  %-15s  %p\n", "ptrQty", "double*", (void*)&ptrQty);
    printf("%-25s  %-15s  %p\n", "ptrTotalCost", "double*", (void*)&ptrTotalCost);
    printf("%-25s  %-15s  %p\n", "ptrTotalSales", "double*", (void*)&ptrTotalSales);
    printf("%-25s  %-15s  %p\n", "ptrProfitLoss", "double*", (void*)&ptrProfitLoss);
    printf("%-25s  %-15s  %p\n", "ptrProfitPercentage", "double*", (void*)&ptrProfitPercentage);
    printf("%-25s  %-15s  %p\n", "ptrLarger", "double*", (void*)&ptrLarger);
}