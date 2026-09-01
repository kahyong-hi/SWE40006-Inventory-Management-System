#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

#include "../Product/Product.h"
#include "../Inventory/Inventory.h"

using namespace std;

struct Product
{
    string id;
    string name;
    string category;
    double price = 0.0;
    int quantity = 0;
};

void clearInvalidInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void displayProduct(const Product& product)
{
    double inventoryValue =
        CalculateProductValue(product.price, product.quantity);

    cout << "Product ID: " << product.id << endl;
    cout << "Product Name: " << product.name << endl;
    cout << "Category: " << product.category << endl;

    cout << "Price: RM"
        << fixed << setprecision(2)
        << product.price << endl;

    cout << "Quantity: "
        << product.quantity << endl;

    cout << "Inventory Value: RM"
        << fixed << setprecision(2)
        << inventoryValue << endl;
}

void viewProducts(const vector<Product>& products)
{
    cout << endl;
    cout << "========== ALL PRODUCTS ==========" << endl;

    if (products.empty())
    {
        cout << "No products available." << endl;
        return;
    }

    for (const Product& product : products)
    {
        cout << endl;
        displayProduct(product);
        cout << "----------------------------------" << endl;
    }
}

void addProduct(vector<Product>& products)
{
    Product product;

    cout << endl;
    cout << "========== ADD PRODUCT ==========" << endl;

    cout << "Enter Product ID: ";
    cin >> product.id;

    for (const Product& p : products)
    {
        if (p.id == product.id)
        {
            cout << "Product ID already exists." << endl;
            return;
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Product Name: ";
    getline(cin, product.name);

    cout << "Enter Category: ";
    getline(cin, product.category);

    cout << "Enter Price: RM";

    if (!(cin >> product.price))
    {
        clearInvalidInput();
        cout << "Invalid price. Please enter a number." << endl;
        return;
    }

    cout << "Enter Quantity: ";

    if (!(cin >> product.quantity))
    {
        clearInvalidInput();
        cout << "Invalid quantity. Please enter a number." << endl;
        return;
    }

    if (product.price < 0 || product.quantity < 0)
    {
        cout << "Invalid price or quantity." << endl;
        return;
    }

    products.push_back(product);

    cout << "Product added successfully." << endl;
}

void updateProduct(vector<Product>& products)
{
    string id;

    cout << endl;
    cout << "========== UPDATE PRODUCT ==========" << endl;

    cout << "Enter Product ID: ";
    cin >> id;

    for (Product& product : products)
    {
        if (product.id == id)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter new Product Name: ";
            getline(cin, product.name);

            cout << "Enter new Category: ";
            getline(cin, product.category);

            cout << "Enter new Price: RM";

            if (!(cin >> product.price))
            {
                clearInvalidInput();
                cout << "Invalid price. Please enter a number." << endl;
                return;
            }

            cout << "Enter new Quantity: ";

            if (!(cin >> product.quantity))
            {
                clearInvalidInput();
                cout << "Invalid quantity. Please enter a number." << endl;
                return;
            }

            if (product.price < 0 || product.quantity < 0)
            {
                cout << "Invalid price or quantity." << endl;
                return;
            }

            cout << "Product updated successfully." << endl;
            return;
        }
    }

    cout << "Product not found." << endl;
}

void deleteProduct(vector<Product>& products)
{
    string id;

    cout << endl;
    cout << "========== DELETE PRODUCT ==========" << endl;

    cout << "Enter Product ID: ";
    cin >> id;

    for (auto it = products.begin(); it != products.end(); ++it)
    {
        if (it->id == id)
        {
            products.erase(it);

            cout << "Product deleted successfully." << endl;
            return;
        }
    }

    cout << "Product not found." << endl;
}

void stockIn(vector<Product>& products)
{
    string id;
    int amount;

    cout << endl;
    cout << "========== STOCK IN ==========" << endl;

    cout << "Enter Product ID: ";
    cin >> id;

    for (Product& product : products)
    {
        if (product.id == id)
        {
            cout << "Current Quantity: "
                << product.quantity << endl;

            cout << "Enter quantity to add: ";

            if (!(cin >> amount))
            {
                clearInvalidInput();
                cout << "Invalid quantity. Please enter a number." << endl;
                return;
            }

            if (amount <= 0)
            {
                cout << "Invalid quantity." << endl;
                return;
            }

            product.quantity =
                AddStock(product.quantity, amount);

            cout << "Stock In successful." << endl;
            cout << "New Quantity: "
                << product.quantity << endl;

            return;
        }
    }

    cout << "Product not found." << endl;
}

void stockOut(vector<Product>& products)
{
    string id;
    int amount;

    cout << endl;
    cout << "========== STOCK OUT ==========" << endl;

    cout << "Enter Product ID: ";
    cin >> id;

    for (Product& product : products)
    {
        if (product.id == id)
        {
            cout << "Current Quantity: "
                << product.quantity << endl;

            cout << "Enter quantity to remove: ";

            if (!(cin >> amount))
            {
                clearInvalidInput();
                cout << "Invalid quantity. Please enter a number." << endl;
                return;
            }

            if (amount <= 0)
            {
                cout << "Invalid quantity." << endl;
                return;
            }

            if (amount > product.quantity)
            {
                cout << "Insufficient stock." << endl;
                return;
            }

            product.quantity =
                RemoveStock(product.quantity, amount);

            cout << "Stock Out successful." << endl;
            cout << "New Quantity: "
                << product.quantity << endl;

            return;
        }
    }

    cout << "Product not found." << endl;
}

int main()
{
    vector<Product> products =
    {
        {
            "P001",
            "Wireless Mouse",
            "Electronics",
            59.90,
            10
        }
    };

    int choice = 0;

    do
    {
        cout << endl;
        cout << "================================" << endl;
        cout << "    INVENTORY MANAGEMENT SYSTEM" << endl;
        cout << "================================" << endl;

        cout << endl;
        cout << "1. Add Product" << endl;
        cout << "2. View Products" << endl;
        cout << "3. Update Product" << endl;
        cout << "4. Delete Product" << endl;
        cout << "5. Stock In" << endl;
        cout << "6. Stock Out" << endl;
        cout << "7. Exit" << endl;

        cout << endl;
        cout << "Enter choice: ";

        if (!(cin >> choice))
        {
            clearInvalidInput();

            cout << endl;
            cout << "Invalid input. Please enter a number from 1-7."
                << endl;

            choice = 0;
            continue;
        }

        switch (choice)
        {
        case 1:
            addProduct(products);
            break;

        case 2:
            viewProducts(products);
            break;

        case 3:
            updateProduct(products);
            break;

        case 4:
            deleteProduct(products);
            break;

        case 5:
            stockIn(products);
            break;

        case 6:
            stockOut(products);
            break;

        case 7:
            cout << endl;
            cout << "Thank you for using Inventory Management System."
                << endl;
            break;

        default:
            cout << endl;
            cout << "Invalid choice. Please enter 1-7."
                << endl;
        }

    } while (choice != 7);

    return 0;
}