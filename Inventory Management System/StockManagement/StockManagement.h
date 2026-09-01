#pragma once

#ifdef STOCKMANAGEMENT_EXPORTS
#define STOCKMANAGEMENT_API __declspec(dllexport)
#else
#define STOCKMANAGEMENT_API __declspec(dllimport)
#endif

extern "C"
{
    STOCKMANAGEMENT_API int AddStock(
        int currentQuantity,
        int amount
    );

    STOCKMANAGEMENT_API int RemoveStock(
        int currentQuantity,
        int amount
    );
}