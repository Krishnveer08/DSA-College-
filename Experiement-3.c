// Experiment 3: Implement Stack using Array: Bookstack Management System



#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    char title[50];
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int top; 
} BookStack;

void initializeStack(BookStack* stack) {
    stack->top = -1;
}

int isFull(BookStack* stack) {
    return stack->top == MAX_BOOKS - 1;
}

int isEmpty(BookStack* stack) {
    return stack->top == -1;
}

void addBook(BookStack* stack, const char* title) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot add more books.\n");
        return;
    }
    stack->top++;
    strcpy(stack->books[stack->top].title, title);
    printf("Book '%s' added to the stack.\n", title);
}

void removeBook(BookStack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. No books to remove.\n");
        return;
    }
    printf("Book '%s' removed from the stack.\n", stack->books[stack->top].title);
    stack->top--;
}

void viewMostRecentBook(BookStack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. No books to view.\n");
        return;
    }
    printf("Most recent book: '%s'\n", stack->books[stack->top].title);
}

void displayAllBooks(BookStack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. No books to display.\n");
        return;
    }
    printf("Books in the stack:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d. %s\n", i + 1, stack->books[i].title);
    }
}

int main() {
    BookStack stack;
    initializeStack(&stack);

    int choice;
    char title[50];

    do {
        printf("\nWelcome to the Bookstack Management System!\n");
        printf("1. Add a book\n");
        printf("2. Remove the most recent book\n");
        printf("3. View the most recent book\n");
        printf("4. Display all books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter the title of the book: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character
                addBook(&stack, title);
                break;
            case 2:
                removeBook(&stack);
                break;
            case 3:
                viewMostRecentBook(&stack);
                break;
            case 4:
                displayAllBooks(&stack);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}