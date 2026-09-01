#include "pch.h"
#include "Inventory.h"

int AddStock(int currentQuantity, int amount)
{
    return currentQuantity + amount;
}

int RemoveStock(int currentQuantity, int amount)
{
    return currentQuantity - amount;
}