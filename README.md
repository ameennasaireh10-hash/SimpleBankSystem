# Simple Bank System

This is a **C++ console-based banking system** project.  
It allows you to create, manage, and delete bank accounts interactively through commands.

---

## ✨ Features
- ✅ Create a new account (ID, Name, Initial Balance)
- ✅ Deposit money to an existing account
- ✅ Withdraw money from an existing account
- ✅ Search for an account by ID
- ✅ Print all accounts with their names and numbers
- ✅ Delete an account by ID

---

## 🖥️ How to Compile and Run

### Compile:
```bash
g++ BankSystem.cpp -o BankSystem

./BankSystem

Enter Command : create
Enter Account ID : 101
Enter Account Name : Ameen
Enter Initial Balance : 500

Enter Command : deposit
Enter Account ID : 101
Enter Amount To Deposit : 200
Your balance after depostie is 700

Enter Command : print
#1 101 --> ameen

Enter Command : withdraw
Enter Account ID : 101
Enter Amount To Withdraw : 300
Your balance after withdraw is 400

Enter Command : delete
Enter Account ID : 101
Account 101 Deleted Successfully...!

Enter Command : exit

SimpleBankSystem/
├── BankSystem.cpp   # Main source code
├── README.md        # Project documentation (this file)
