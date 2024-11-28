
#include <stdio.h>
#include <stdlib.h>

// Structure definition for a node in the linked list
struct Node {
    int coeff;      // Coefficient of the term
    int exp;        // Exponent of the term
    struct Node* next;  // Pointer to the next node
};

// Function to create a header node
struct Node* createHeaderNode() {
    struct Node* header = (struct Node*)malloc(sizeof(struct Node));
    if (!header) {
        printf("Memory allocation failed\n");
        exit(1);  // Exit if memory allocation fails
    }
    header->coeff = 0;
    header->exp = -1;
    header->next = NULL;
    return header;  // Return the created header node
}

// Function to insert a new node in the polynomial linked list
void insert(struct Node* header, int coeff, int exp) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->coeff = coeff;
    newnode->exp = exp;
    newnode->next = NULL;

    // Insert the node into the list in decreasing order of exponent
    struct Node* temp = header;
    while (temp->next != NULL && temp->next->exp > exp) {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
// Function to display the polynomial linked list
void display(struct Node* header) {
    struct Node* temp = header->next;  // Skip header node
    if (temp == NULL) {
        printf("0\n");
        return;
    }

    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}
// Function to add two polynomials represented by linked lists
void addPolynomial(struct Node* p1, struct Node* p2) {
    struct Node* temp1 = p1->next;  // Skip header node for p1
    struct Node* temp2 = p2->next;  // Skip header node for p2
    struct Node* result = createHeaderNode();  // Create a new header node for the result polynomial

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->exp > temp2->exp) {
            insert(result, temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        } else if (temp2->exp > temp1->exp) {
            insert(result, temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        } else {  // When exponents are equal, add the coefficients
            int sumCoeff = temp1->coeff + temp2->coeff;
            if (sumCoeff != 0) {
                insert(result, sumCoeff, temp1->exp);
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    // Insert remaining terms from polynomial p1 (if any)
    while (temp1 != NULL) {
        insert(result, temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }

    // Insert remaining terms from polynomial p2 (if any)
    while (temp2 != NULL) {
        insert(result, temp2->coeff, temp2->exp);
        temp2 = temp2->next;
    }

    // Display the result
    printf("Resultant Polynomial: ");
    display(result);
}



int main() {
    struct Node* p1 = createHeaderNode();  // Create header for polynomial 1
    struct Node* p2 = createHeaderNode();  // Create header for polynomial 2

    // Insert terms into polynomial 1: 4x^3 + 3x^2 + 2x^1
    insert(p1, 4, 3);
    insert(p1, 3, 2);
    insert(p1, 2, 1);

    // Insert terms into polynomial 2: 3x^4 + 5x^2 + 6x^1
    insert(p2, 3, 4);
    insert(p2, 5, 2);
    insert(p2, 6, 1);

    printf("Polynomial 1: ");
    display(p1);

    printf("Polynomial 2: ");
    display(p2);

    // Add the two polynomials and display the result
    addPolynomial(p1, p2);

    return 0;

}