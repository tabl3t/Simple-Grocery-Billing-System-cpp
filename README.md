# Grocery-Store-Billing-System-C++
A lightweight, console-based Grocery Management Application built using C++. This system allows users to manage a digital shopping cart by adding, viewing, and deleting items, as well as generating a final receipt. It utilizes Object-Oriented Programming (OOP) principles and File Handling to ensure data persists even after the program is closed.

# Features
Persistent Storage: Uses file handling (additem.txt) to save your cart data.
Item Management:
Add Item: Input item names, Unique IDs (UID), prices, and quantities.
View Cart: Display all currently stored items in a readable format.
Delete Item: Remove specific items using their UID with a confirmation prompt to prevent accidental deletion.
Billing System: Automatically calculates the total for each item and generates a Grand Total for the entire cart.
User-Friendly Interface: Uses conio.h for screen pausing, making the console navigation smoother.

# Technologies Used
Language: C++
Paradigms: Object-Oriented Programming (OOP)
Header Files:
<fstream>: For file reading and writing.
<iostream>: For standard input/output.
<conio.h>: For keyboard interaction (getch()).
<string>: For handling item names.

# How to Run
Clone the Repository:
git clone https://github.com/YourUsername/Grocery-Billing-System.git
Compile the Code: Use any C++ compiler (like G++).
g++ -o GrocerySystem main.cpp
Execute the Program:
./GrocerySystem

# Screenshots
<img width="2180" height="1500" alt="1" src="https://github.com/user-attachments/assets/d10cd9aa-fa22-4537-b6d1-40aa3e39dd04" />
<img width="2180" height="1500" alt="2" src="https://github.com/user-attachments/assets/de494ce1-389e-4269-8b32-3f2a9eee9051" />
<img width="2180" height="1500" alt="4" src="https://github.com/user-attachments/assets/56e66120-9945-4cfc-ba24-f9af56b8c0ea" />


# File Structure
main.cpp: Contains the complete source code.
additem.txt: The database file where item records are stored (automatically created).
temp.txt: A temporary file used during the item deletion process.

# Future Improvements
[ ] Add a Search function to find items by name.
[ ] Implement a Login System for admin/user access.
[ ] Add Stock Management to track inventory levels.
[ ] Use std::setw for better table formatting in the bill section.

# Contributing
Contributions, issues, and feature requests are welcome! Feel free to check the issues page.

