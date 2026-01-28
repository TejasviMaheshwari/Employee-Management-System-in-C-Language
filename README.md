# Employee-Management-System-in-C-Language
A C-based Employee System for managing persistent data through binary files. Capabilities include auto-generation of ID, modification of records, two-tier Recycle Bin for recovery, and multi-parameter search by ID, City, or Dept. Great for showing BCA-level file I/O skills.
# Employee Information System 🏢

A robust command-line application built in C to manage employee records efficiently using file handling. This project was developed as part of my BCA coursework to demonstrate CRUD operations and data persistence.

## 🚀 Features
- **Add Employee**: Create new records with unique auto-generated IDs.
- **Show Records**: Display all stored employees in a formatted table.
- **Modify Details**: Update specific fields like Name, Department, City, or Salary.
- **Delete System**: Supports **Temporary Delete** (moves to Recycle Bin) and **Permanent Delete**.
- **Recycle Bin**: Recover accidentally deleted records or view "deleted" history.
- **Search Functionality**: Quickly find employees by **ID**, **Department**, or **City**.

## 🛠️ Technical Stack
- **Language**: C
- **Concepts**: Structs, File Handling (`fopen`, `fwrite`, `fread`), Binary Files (`.bin`).
- **Compiler**: GCC (MinGW)

## 📂 File Structure
- `EID.bin`: Main database file.
- `EID_REC.bin`: Storage for the Recycle Bin.
- `EMPLOYEEproject.c`: Source code.

## ⚙️ How to Run
1. Clone the repository:
   ```bash
   git clone https://github.com/TejasviMaheshwari/Employee-Management-System-in-C-Language.git
