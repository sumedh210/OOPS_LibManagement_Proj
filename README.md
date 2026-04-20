# 📚 Library Management System

A console-based Library Management System built in **C++** using core **Object-Oriented Programming** principles. Designed to manage books and customers in a library environment with persistent file-based storage.

---

## 🛠️ Tech Stack

- **Language:** C++
- **Concepts:** OOP (Encapsulation, Abstraction, Class Composition)
- **Storage:** File I/O using C++ file streams (`fstream`)
- **Data Structures:** Vectors, Strings

---

## ✨ Features

### Book Management
- Add new books with full metadata (title, author, genre, publisher, language, year, rating)
- View all books in the library
- Update book details by title
- Remove books from the library
- Check availability of a book by title

### Customer Management
- Register new customers with identity and library card details
- View all registered customers
- Update customer records by name

### Library Operations
- Late fee calculation based on number of days overdue
- Persistent data storage — all records saved to `.dat` files and retained across sessions

---

## 🏗️ System Design

The system is built around three core classes:

| Class | Responsibility |
|-------|---------------|
| `Book` | Encapsulates all book attributes and operations |
| `Customer` | Manages customer identity and borrowing details |
| `Library` | Orchestrates book and customer management, file I/O, and business logic |

---

## 🚀 How to Run

### Prerequisites
- G++ compiler (GCC)

### Compile
```bash
g++ -o library OOps_proj.cpp
```

### Run
```bash
./library
```

### Menu Options
```
1. Add a Book
2. View All Books
3. Manage Late Fees
4. Remove a Book
5. Add Customer Details
6. View All Customers
7. Update Book Details by Title
8. Check Availability of a Book by Title
9. Update Customer Details by Name
0. Exit
```

---

## 📁 Data Storage

Records are persisted in two flat files:
- `books.dat` — stores all book records
- `customers.dat` — stores all customer records

Data is retained across program sessions automatically.

---

## 📖 Sample Usage

```
Library Admin Menu:
1. Add a Book
Choose an option: 1

Enter Book Title: The Pragmatic Programmer
Enter Author Name: David Thomas
Enter Rating: 4.8
Is the book available? (1 for Yes, 0 for No): 1
Enter Language: English
Enter Publisher: Addison-Wesley
Enter Genre: Technology
Enter Year of Publish: 1999

Book added successfully!
```

---

## 🎓 About

Built as a 2nd year academic project at **IIIT Nagpur** to demonstrate Object-Oriented Programming concepts in C++ including encapsulation, abstraction, and class composition.

---

## 👨‍💻 Author

**Sumedh Lohekar**  
B.Tech CSE (AI/ML) — IIIT Nagpur  
[GitHub](https://github.com/your-github)
