#pragma once

#ifdef INVENTORYVALUECALCULATOR_EXPORTS
#define INVENTORYVALUECALCULATOR_API __declspec(dllexport)
#else
#define INVENTORYVALUECALCULATOR_API __declspec(dllimport)
#endif

extern "C"
{
    INVENTORYVALUECALCULATOR_API double CalculateInventoryValue(
        double price,
        int quantity
    );
}