
# **Supermarket Billing System**

This is a simple **Command Line Interface (CLI)** supermarket billing system developed in **C language**. It enables users to manage billing processes efficiently, calculate discounts, and store saved bills for future reference.

---

## **Features**
- **Billing System**:
  - Input product codes and quantities to generate bills.
  - Automatically calculate the total price and apply discounts.
- **Discount System**:
  - 5% discount for purchases of 5-9 items.
  - 10% discount for purchases of 10 or more items.
- **Saved Bills**:
  - Generate and save bills with a unique name based on the current date and time.
  - Retrieve and display previously saved bills.
- **Price List Display**:
  - Reads and displays a product price list from a file.
- **File Management**:
  - Stores bills in the `Bill Database` directory for organized record-keeping.

---

## **How to Use**
1. **Run the Program**:
   - Compile the code using a C compiler like GCC:
     ```bash
     gcc CST-Team-40.c -o supermarket
     ```
   - Execute the program:
     ```bash
     ./supermarket
     ```

2. **Menu Options**:
   - **Billing**:
     - Enter product codes and quantities to generate a bill.
     - Discounts will be automatically applied based on the number of items purchased.
   - **Saved Bills**:
     - View a list of saved bills and read the details of any selected bill.
   - **Exit**:
     - Exit the application.

3. **File Management**:
   - Bills are saved in the `Bill Database` directory with a unique name based on the current date and time.
   - The product price list is read from `priceList.txt`.

## **How to Add Products**
1. Update the product names and prices in the `priceList.txt` file.
2. Modify the arrays `itemName` and `unitPrice` in the `billing` function if not using a dynamic product loader.

