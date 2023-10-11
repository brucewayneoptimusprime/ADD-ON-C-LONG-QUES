#include <stdio.h>
#include <string.h>

// Structure to represent a book's information
struct Book {
    char title[100];
    char author[100];
    char isbn[13];
    int year;
    int copies_available;
};

// Array of structures to store information for multiple books (size 20)
struct Book catalog[20];
int catalogSize = 0; // Variable to keep track of the number of books in the catalog

// Function to add a new book to the catalog
void addBook() {
    if (catalogSize < 20) {
        struct Book newBook;

        printf("Enter book title: ");
        scanf("%s", newBook.title);
        printf("Enter author: ");
        scanf("%s", newBook.author);
        printf("Enter ISBN: ");
        scanf("%s", newBook.isbn);
        printf("Enter publication year: ");
        scanf("%d", &newBook.year);
        newBook.copies_available = 1; // When adding a new book, initially one copy is available.

        catalog[catalogSize] = newBook;
        catalogSize++;

        printf("Book added to the catalog.\n");
    } else {
        printf("Catalog is full. Cannot add more books.\n");
    }
}

// Function to display the information of all books in the catalog
void displayBooks() {
    if (catalogSize == 0) {
        printf("Catalog is empty.\n");
    } else {
        printf("Catalog Contents:\n");
        for (int i = 0; i < catalogSize; i++) {
            printf("Title: %s\n", catalog[i].title);
            printf("Author: %s\n", catalog[i].author);
            printf("ISBN: %s\n", catalog[i].isbn);
            printf("Publication Year: %d\n", catalog[i].year);
            printf("Copies Available: %d\n", catalog[i].copies_available);
            printf("\n");
        }
    }
}

// Function to search for a book by ISBN and display its details
void searchByISBN() {
    char searchISBN[13];
    int found = 0;

    printf("Enter ISBN to search: ");
    scanf("%s", searchISBN);

    for (int i = 0; i < catalogSize; i++) {
        if (strcmp(searchISBN, catalog[i].isbn) == 0) {
            printf("Book found:\n");
            printf("Title: %s\n", catalog[i].title);
            printf("Author: %s\n", catalog[i].author);
            printf("Publication Year: %d\n", catalog[i].year);
            printf("Copies Available: %d\n", catalog[i].copies_available);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book with ISBN %s not found in the catalog.\n", searchISBN);
    }
}

// Function to check out a book
void checkOutBook() {
    char searchISBN[13];

    printf("Enter ISBN to check out: ");
    scanf("%s", searchISBN);

    for (int i = 0; i < catalogSize; i++) {
        if (strcmp(searchISBN, catalog[i].isbn) == 0) {
            if (catalog[i].copies_available > 0) {
                catalog[i].copies_available--;
                printf("Book with ISBN %s checked out successfully.\n", searchISBN);
            } else {
                printf("No copies of the book with ISBN %s are available for checkout.\n", searchISBN);
            }
            return;
        }
    }

    printf("Book with ISBN %s not found in the catalog.\n", searchISBN);
}

// Function to check in a book
void checkInBook() {
    char searchISBN[13];

    printf("Enter ISBN to check in: ");
    scanf("%s", searchISBN);

    for (int i = 0; i < catalogSize; i++) {
        if (strcmp(searchISBN, catalog[i].isbn) == 0) {
            catalog[i].copies_available++;
            printf("Book with ISBN %s checked in successfully.\n", searchISBN);
            return;
        }
    }

    printf("Book with ISBN %s not found in the catalog.\n", searchISBN);
}

int main() {
    int choice;

    do {
        printf("\nLibrary Catalog Menu:\n");
        printf("1. Add a book\n");
        printf("2. Display all books\n");
        printf("3. Search by ISBN\n");
        printf("4. Check out a book\n");
        printf("5. Check in a book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchByISBN();
                break;
            case 4:
                checkOutBook();
                break;
            case 5:
                checkInBook();
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
