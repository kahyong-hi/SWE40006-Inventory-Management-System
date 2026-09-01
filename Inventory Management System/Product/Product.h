#pragma once

#ifdef PRODUCT_EXPORTS
#define PRODUCT_API __declspec(dllexport)
#else
#define PRODUCT_API __declspec(dllimport)
#endif

extern "C"
{
    PRODUCT_API double CalculateProductValue(double price, int quantity);
}