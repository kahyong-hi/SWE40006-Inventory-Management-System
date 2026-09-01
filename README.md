# SWE40006-Inventory-Management-System

Inventory Management System deployment project for SWE40006 Software Deployment and Evolution.

## Project Structure

The project consists of:

- Inventory Management System - Main C++ application
- InventoryValueCalculator.dll - Calculates product inventory value
- StockManagement.dll - Handles stock-in and stock-out operations
- WiX Installer - Packages the application and DLL dependencies into an MSI installer

## Requirements

- Windows
- Visual Studio 2022
- Desktop Development with C++
- WiX Toolset v3.14

## Build Instructions

### 1. Build the C++ Application

1. Open `Inventory Management System/Inventory Management System.slnx`.
2. Build the solution.
3. The following files will be generated in `x64/Debug`:
   - Inventory Management System.exe
   - Product.dll
   - Inventory.dll

### 2. Build the WiX Installer

1. Open `Inventory Management Installer/Inventory Management Installer.slnx`.
2. Build the WiX installer project.
3. The MSI installer will be generated in the `bin/Debug` directory.

## Deployment

The WiX installer deploys:

- Inventory Management System.exe
- InventoryValueCalculator.dll
- StockManagement.dll

The application was successfully built, installed and tested on Windows.
