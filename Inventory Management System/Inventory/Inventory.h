#pragma once

#ifdef INVENTORY_EXPORTS
#define INVENTORY_API __declspec(dllexport)
#else
#define INVENTORY_API __declspec(dllimport)
#endif

extern "C"
{
    INVENTORY_API int AddStock(int currentQuantity, int amount);
    INVENTORY_API int RemoveStock(int currentQuantity, int amount);
}