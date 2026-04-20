#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Book
{
private:
    string title;
    string author;
    float rating;
    bool availability;
    string language;
    string publisher;
    string genre;
    int year;

public:
    Book() {}
    Book(string t, string a, float r, bool avail, string lang, string pub, string g, int y)
        : title(t), author(a), rating(r), availability(avail), language(lang), publisher(pub), genre(g), year(y) {}

    void addBook()
    {
        cout << "Enter Book Title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter Author Name: ";
        getline(cin, author);
        cout << "Enter Rating: ";
        cin >> rating;
        cout << "Is the book available? (1 for Yes, 0 for No): ";
        cin >> availability;
        cout << "Enter Language: ";
        cin.ignore();
        getline(cin, language);
        cout << "Enter Publisher: ";
        getline(cin, publisher);
        cout << "Enter Genre: ";
        getline(cin, genre);
        cout << "Enter Year of Publish: ";
        cin >> year;
        saveBook();
    }

    void saveBook()
    {
        ofstream fout("books.dat", ios::app);
        fout << title << endl;
        fout << author << endl;
        fout << rating << endl;
        fout << availability << endl;
        fout << language << endl;
        fout << publisher << endl;
        fout << genre << endl;
        fout << year << endl;
        fout.close();
        cout << "Book added successfully!\n";
    }

    void displayBook()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Rating: " << rating << endl;
        cout << "Availability: " << (availability ? "Available" : "Not Available") << endl;
        cout << "Language: " << language << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Genre: " << genre << endl;
        cout << "Year: " << year << endl;
    }

    string getTitle()
    {
        return title;
    }

    string getAuthor()
    {
        return author;
    }

    float getRating()
    {
        return rating;
    }

    bool getAvailability()
    {
        return availability;
    }

    string getLanguage()
    {
        return language;
    }

    string getPublisher()
    {
        return publisher;
    }

    string getGenre()
    {
        return genre;
    }

    int getYear()
    {
        return year;
    }

    bool checkAvailability()
    {
        return availability;
    }

    void updateBook()
    {
        cout << "Update Book Details:\n";
        addBook();
    }
};

class Customer
{
private:
    string name;
    string address;
    string identity;
    string libraryCard;
    string phoneNumber;
    int pagesIssued;

public:
    Customer() {}
    Customer(string n, string addr, string id, string card, string phone, int pages)
        : name(n), address(addr), identity(id), libraryCard(card), phoneNumber(phone), pagesIssued(pages) {}

    void addCustomer()
    {
        cout << "Enter Customer Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Address: ";
        getline(cin, address);
        cout << "Enter Identity Document: ";
        getline(cin, identity);
        cout << "Enter Library Card Number: ";
        getline(cin, libraryCard);
        cout << "Enter Phone Number: ";
        getline(cin, phoneNumber);
        cout << "Enter Number of Pages Issued: ";
        cin >> pagesIssued;
        saveCustomer();
    }

    void saveCustomer()
    {
        ofstream fout("customers.dat", ios::app);
        fout << name << endl;
        fout << address << endl;
        fout << identity << endl;
        fout << libraryCard << endl;
        fout << phoneNumber << endl;
        fout << pagesIssued << endl;
        fout.close();
        cout << "Customer details added successfully!\n";
    }

    void updateCustomer()
    {
        cout << "Enter New Title for Customer: ";
        cin.ignore();
        getline(cin, name);
        saveCustomer();
    }

    void displayCustomer()
    {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Identity: " << identity << endl;
        cout << "Library Card: " << libraryCard << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Pages Issued: " << pagesIssued << endl;
    }

    string getName()
    {
        return name;
    }

    string getAddress()
    {
        return address;
    }

    string getIdentity()
    {
        return identity;
    }

    string getLibraryCard()
    {
        return libraryCard;
    }

    string getPhoneNumber()
    {
        return phoneNumber;
    }

    int getPagesIssued()
    {
       return pagesIssued;
    }
};

class Library
{
private:
    vector<Book> books;
    vector<Customer> customers;

public:
    void addBook()
    {
        Book newBook;
        newBook.addBook();
        books.push_back(newBook);
    }

    void displayBooks()
    {
        ifstream fin("books.dat");
        if (!fin)
        {
            cout << "No books available!\n";
            return;
        }
        string title, author, language, publisher, genre;
        float rating;
        bool availability;
        int year;
        while (getline(fin, title))
        {
            getline(fin, author);
            fin >> rating >> availability;
            fin.ignore();
            getline(fin, language);
            getline(fin, publisher);
            getline(fin, genre);
            fin >> year;
            fin.ignore();

            Book b(title, author, rating, availability, language, publisher, genre, year);
            b.displayBook();
            cout << "---------------------\n";
        }
        fin.close();
    }

    void addCustomer()
    {
        Customer newCustomer;
        newCustomer.addCustomer();
        customers.push_back(newCustomer);
    }

    void displayCustomers()
    {
        ifstream fin("customers.dat");
        if (!fin)
        {
            cout << "No customers available!\n";
            return;
        }
        string name, address, identity, libraryCard, phoneNumber;
        int pagesIssued;
        while (getline(fin, name))
        {
            getline(fin, address);
            getline(fin, identity);
            getline(fin, libraryCard);
            getline(fin, phoneNumber);
            fin >> pagesIssued;
            fin.ignore();

            Customer c(name, address, identity, libraryCard, phoneNumber, pagesIssued);
            c.displayCustomer();
            cout << "---------------------\n";
        }
        fin.close();
    }

    void removeBook()
    {
        string titleToRemove;
        cout << "Enter the title of the book to remove: ";
        cin.ignore();
        getline(cin, titleToRemove);

        vector<Book> tempBooks;
        bool found = false;
        ifstream fin("books.dat");
        if (!fin)
        {
            cout << "No books available!\n";
            return;
        }
        string title, author, language, publisher, genre;
        float rating;
        bool availability;
        int year;
        while (getline(fin, title))
        {
            getline(fin, author);
            fin >> rating >> availability;
            fin.ignore();
            getline(fin, language);
            getline(fin, publisher);
            getline(fin, genre);
            fin >> year;
            fin.ignore();

            if (title != titleToRemove)
            {
                Book b(title, author, rating, availability, language, publisher, genre, year);
                tempBooks.push_back(b);
            }
            else
            {
                found = true;
            }
        }
        fin.close();

        if (found)
        {
            ofstream fout("books.dat");
            for (auto &b : tempBooks)
            {
                fout << b.getTitle() << endl;
                fout << author << endl;
                fout << rating << endl;
                fout << availability << endl;
                fout << language << endl;
                fout << publisher << endl;
                fout << genre << endl;
                fout << year << endl;
            }
            fout.close();
            cout << "Book removed successfully!\n";
        }
        else
        {
            cout << "Book not found!\n";
        }
    }

    void updateBookByTitle()
    {
        string titleToUpdate;
        cout << "Enter the title of the book to update: ";
        cin.ignore();
        getline(cin, titleToUpdate);

        vector<Book> tempBooks;
        bool found = false;

        ifstream fin("books.dat");
        if (!fin)
        {
            cout << "No books available!\n";
            return;
        }

        string title, author, language, publisher, genre;
        float rating;
        bool availability;
        int year;

        // Read books from the file
        while (getline(fin, title))
        {
            getline(fin, author);
            fin >> rating >> availability;
            fin.ignore();
            getline(fin, language);
            getline(fin, publisher);
            getline(fin, genre);
            fin >> year;
            fin.ignore();

            if (title == titleToUpdate)
            {
               
                Book updatedBook;
                updatedBook.updateBook(); 
                tempBooks.push_back(updatedBook);
                found = true;
            }
            else
            {
                
                Book b(title, author, rating, availability, language, publisher, genre, year);
                tempBooks.push_back(b);
            }
        }
        fin.close();

        if (found)
        {
            ofstream fout("books.dat"); // Rewrite the file with the updated list
            for (auto &b : tempBooks)
            {
                fout << b.getTitle() << endl;
                fout << b.getAuthor() << endl;
                fout << b.getRating() << endl;
                fout << b.getAvailability() << endl;
                fout << b.getLanguage() << endl;
                fout << b.getPublisher() << endl;
                fout << b.getGenre() << endl;
                fout << b.getYear() << endl;
            }
            fout.close();
            cout << "Book details updated successfully!\n";
        }
        else
        {
            cout << "Book not found!\n";
        }
    }

    void
    checkAvailabilityByTitle()
    {
        string titleToCheck;
        cout << "Enter the title of the book: ";
        cin.ignore();
        getline(cin, titleToCheck);
        bool found = false;
        ifstream fin("books.dat");
        if (!fin)
        {
            cout << "No books available!\n";
            return;
        }
        string title, author, language, publisher, genre;
        float rating;
        bool availability;
        int year;
        while (getline(fin, title))
        {
            getline(fin, author);
            fin >> rating >> availability;
            fin.ignore();
            getline(fin, language);
            getline(fin, publisher);
            getline(fin, genre);
            fin >> year;
            fin.ignore();

            if (title == titleToCheck)
            {
                cout << "The book \"" << title << "\" is " << (availability ? "available." : "not available.") << endl;
                found = true;
                break;
            }
        }
        fin.close();

        if (!found)
        {
            cout << "Book not found!\n";
        }
    }

    void manageLateFees()
    {
        string libraryCard;
        int daysLate;
        cout << "Enter Library Card Number: ";
        cin.ignore();
        getline(cin, libraryCard);
        cout << "Enter number of days late: ";
        cin >> daysLate;

        const float lateFeePerDay = 4.50; // Example fee
        float totalFee = lateFeePerDay * (daysLate-7);
        cout << "Total late fee for card " << libraryCard << ": Rupees " << totalFee << endl;
    }

    void updateCustomerTitleByName()
{
    string customerName;
    cout << "Enter the customer's name to update: ";
    cin.ignore();
    getline(cin, customerName);

    vector<Customer> tempCustomers;
    bool found = false;

    ifstream fin("customers.dat");
    if (!fin)
    {
        cout << "No customers available!\n";
        return;
    }

    string name, address, identity, libraryCard, phoneNumber;
    int pagesIssued;

    // Read customers from the file
    while (getline(fin, name))
    {
        getline(fin, address);
        getline(fin, identity);
        getline(fin, libraryCard);
        getline(fin, phoneNumber);
        fin >> pagesIssued;
        fin.ignore(); 

        if (name == customerName)
        {
            
            cout << "Updating customer details for " << name << ":\n";
            Customer updatedCustomer;
            updatedCustomer.addCustomer();  // Get new details from the user
            tempCustomers.push_back(updatedCustomer); 
            found = true;
        }
        else
        {
           
            Customer c(name, address, identity, libraryCard, phoneNumber, pagesIssued);
            tempCustomers.push_back(c);
          }
    }
    fin.close();

    
    if (found)
    {
        ofstream fout("customers.dat");
        for ( auto &c : tempCustomers)
        {
            fout << c.getName() << endl;
            fout << c.getAddress() << endl;
            fout << c.getIdentity() << endl;
            fout << c.getLibraryCard() << endl;
            fout << c.getPhoneNumber() << endl;
            fout << c.getPagesIssued() << endl;
        }
        fout.close();
        cout << "Customer details updated successfully!\n";
    }
    else
    {
        cout << "Customer not found!\n";
    }
}

};

void displayMenu()
{
    cout << "\nLibrary Admin Menu:\n";
    cout << "1. Add a Book\n";
    cout << "2. View All Books\n";
    cout << "3. Manage Late Fees\n";
    cout << "4. Remove a Book\n";
    cout << "5. Add Customer Details\n";
    cout << "6. View All Customers\n";
    cout << "7. Update Book Details by Title\n";
    cout << "8. Check Availability of a Book by Title\n";
    cout << "9. Update Customer Title by Name\n";
    cout << "0. Exit\n";
}

int main()
{
    Library library;
    int choice;

    do
    {
        displayMenu();
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            library.addBook();
            break;
        case 2:
            library.displayBooks();
            break;
        case 3:
            library.manageLateFees();
            break;
        case 4:
            library.removeBook();
            break;
        case 5:
            library.addCustomer();
            break;
        case 6:
            library.displayCustomers();
            break;
        case 7:
            library.updateBookByTitle();
            break;
        case 8:
            library.checkAvailabilityByTitle();
            break;
        case 9:
            library.updateCustomerTitleByName();
            break;
        case 0:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}