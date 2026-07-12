# 🏥 Hospital Management System (C++)

A console-based **Hospital Management System** developed in **C++** as a 2nd Semester Programming Fundamentals project. The system helps manage hospital operations such as patient records, doctor information, appointments, billing, room allocation, and staff management using file handling.

## 📌 Project Overview

The Hospital Management System is a menu-driven application that digitizes basic hospital operations. It stores data in text files and provides an easy-to-use interface for managing hospital records.

## ✨ Features

### 🔐 Login & Registration
- Secure user login and registration
- Username validation
- Password validation (minimum 8 characters)
- Credentials stored in `admin.txt`

### 👨‍⚕️ Patient Management
- Add new patients
- View patient records
- Search patients
- Update patient information
- Delete patient records

### 🩺 Doctor Management
- Add doctor records
- View doctors
- Search doctors by details

### 🤝 Doctor Assignment
- Automatically assigns doctors based on patient disease and doctor specialty.

### 📅 Appointment Management
- Book appointments
- Prevent appointment time conflicts
- Store appointment records

### 💳 Billing System
- Generate patient bills
- Calculate consultation, room, and test charges
- Save billing history

### 🏥 Room Management
- Assign hospital rooms
- Release occupied rooms
- Track room availability

### 👥 Staff Management
- Add staff members
- View staff records
- Search staff by name or role

### 📊 Daily Reports
- Number of patients
- Appointment summary
- Billing summary
- Room allocation report

---

## 🛠 Technologies Used

- **Language:** C++
- **Concepts:**
  - File Handling
  - Functions
  - Character Arrays
  - Conditional Statements
  - Loops
  - Menu-Driven Programming
  - Pointers

---

## 📂 Project Structure

```
Hospital-Management-System/
│
├── main.cpp
├── admin.txt
├── patients.txt
├── doctors.txt
├── appointments.txt
├── bills.txt
├── rooms.txt
├── staff.txt
└── README.md
```

---

## 📁 Files Used

| File | Purpose |
|------|---------|
| admin.txt | Login credentials |
| patients.txt | Patient records |
| doctors.txt | Doctor information |
| appointments.txt | Appointment details |
| bills.txt | Billing records |
| rooms.txt | Room assignments |
| staff.txt | Staff information |

---

## 🚀 How to Run

1. Clone the repository

```bash
git clone https://github.com/your-username/Hospital-Management-System.git
```

2. Open the project in any C++ IDE (Code::Blocks, Dev-C++, Visual Studio, etc.)

3. Compile the project

4. Run the executable

---

## 🎯 Learning Outcomes

This project helped us understand:

- File Handling in C++
- Modular Programming
- Menu-Driven Applications
- Data Management using Text Files
- Problem Solving and Logical Programming

---

## ⚠ Limitations

- Console-based interface
- Uses text files instead of a database
- Single-user environment
- No graphical user interface

---

## 🔮 Future Improvements

- Add a Graphical User Interface (GUI)
- Database integration (MySQL/SQLite)
- Multiple user roles (Admin, Doctor, Receptionist)
- Patient history management
- Online appointment booking
- Improved security and authentication

---

## 👨‍💻 Team Members

- **Muhammad Shavaiz Jamil** (L1F24BSCS0147)
- **Talha Usman** (L1F24BSCS0238)

---

## 📜 License

This project was developed for educational purposes as part of the **Programming Fundamentals** course at the **University of Central Punjab (UCP)**.
