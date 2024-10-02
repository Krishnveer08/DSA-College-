// // Q.  Represent a 2-variable polynomial using array. Use this representation to implement the addition of polynomials. 







// // #include<stdio.h>

// // struct Node
// // {
// //     int coeff;
// //     int exp;
// //     struct Node* next;
// // };

// // struct Node* createHeaderNode(){
// //     struct Node * header=(struct Node*)malloc(sizeof(struct Node));
    
    
// //     if(!header){
// //         printf("Not Defined");
// //     }
// //     header->coeff=0;
// //     header->exp=-1;
// //     header->next=NULL;
    







// //     void addPolynomial(struct Node* p1, struct Node* p2){
// //         struct Node* temp1=p1->next;
// //         struct Node* temp2=p2->next;
// //         struct Node* result=createHeaderNode();
// //     }
// // }

// // int main(){
// //     struct Node* p1=createHeaderNode();
// //     struct Node* p2=createHeaderNode();
    
// //     printf("\nFOR POLYNOMIAL 1:");
// //     insert(p1,4,3);
// //     insert(p1,3,2);
// //     insert(p1,2,1);
// //     insert(p1,4,0);



// //     printf("\nFOR POLYNOMIAL 2:");
// //     insert(p1,4,3);
// //     insert(p1,3,2);
// //     insert(p1,2,1);
// //     insert(p1,4,0);
// // }







// #include<stdio.h>
// #include<stdlib.h>

// // Define the structure for a node representing a term in the polynomial
// struct Node {
//     int coeff;     // Coefficient of the term
//     int exp;       // Exponent of the term
//     struct Node* next;  // Pointer to the next node (term)
// };

// // Function to create a header node for a polynomial
// struct Node* createHeaderNode() {
//     struct Node* header = (struct Node*)malloc(sizeof(struct Node));
//     if (!header) {
//         printf("Memory allocation failed!\n");
//         return NULL;
//     }
//     header->coeff = 0;
//     header->exp = -1;
//     header->next = NULL;
//     return header;
// }

// // Function to insert a term into the polynomial
// void insert(struct Node* header, int coeff, int exp) {
//     struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
//     temp->coeff = coeff;
//     temp->exp = exp;
//     temp->next = NULL;

//     // Find the correct position to insert the term in decreasing order of exponents
//     struct Node* current = header;
//     while (current->next != NULL && current->next->exp > exp) {
//         current = current->next;
//     }
    
//     // If the term with the same exponent already exists, add the coefficients
//     if (current->next != NULL && current->next->exp == exp) {
//         current->next->coeff += coeff;
//     } else {
//         // Insert the new term
//         temp->next = current->next;
//         current->next = temp;
//     }
// }

// // Function to add two polynomials
// struct Node* addPolynomial(struct Node* p1, struct Node* p2) {
//     struct Node* result = createHeaderNode();
//     struct Node* temp1 = p1->next;  // Pointer to traverse the first polynomial
//     struct Node* temp2 = p2->next;  // Pointer to traverse the second polynomial

//     // Traverse both polynomials and add the corresponding terms
//     while (temp1 != NULL && temp2 != NULL) {
//         if (temp1->exp == temp2->exp) {
//             insert(result, temp1->coeff + temp2->coeff, temp1->exp);
//             temp1 = temp1->next;
//             temp2 = temp2->next;
//         } else if (temp1->exp > temp2->exp) {
//             insert(result, temp1->coeff, temp1->exp);
//             temp1 = temp1->next;
//         } else {
//             insert(result, temp2->coeff, temp2->exp);
//             temp2 = temp2->next;
//         }
//     }

//     // If there are remaining terms in the first polynomial
//     while (temp1 != NULL) {
//         insert(result, temp1->coeff, temp1->exp);
//         temp1 = temp1->next;
//     }

//     // If there are remaining terms in the second polynomial
//     while (temp2 != NULL) {
//         insert(result, temp2->coeff, temp2->exp);
//         temp2 = temp2->next;
//     }

//     return result;
// }

// // Function to print a polynomial
// void printPolynomial(struct Node* poly) {
//     struct Node* temp = poly->next; // Skip the header node
//     if (temp == NULL) {
//         printf("0\n");
//         return;
//     }

//     while (temp != NULL) {
//         printf("%d*x^%d", temp->coeff, temp->exp);
//         temp = temp->next;
//         if (temp != NULL) {
//             printf(" + ");
//         }
//     }
//     printf("\n");
// }

// int main() {
//     // Create two polynomials
//     struct Node* p1 = createHeaderNode();
//     struct Node* p2 = createHeaderNode();

//     // Add terms to polynomial 1 (4*x^3 + 3*x^2 + 2*x^1 + 4*x^0)
//     printf("\nFOR POLYNOMIAL 1:\n");
//     insert(p1, 4, 3);
//     insert(p1, 3, 2);
//     insert(p1, 2, 1);
//     insert(p1, 4, 0);
//     printPolynomial(p1);

//     // Add terms to polynomial 2 (4*x^3 + 3*x^2 + 2*x^1 + 4*x^0)
//     printf("\nFOR POLYNOMIAL 2:\n");
//     insert(p2, 4, 3);
//     insert(p2, 3, 2);
//     insert(p2, 2, 1);
//     insert(p2, 4, 0);
//     printPolynomial(p2);

//     // Add the two polynomials
//     struct Node* sum = addPolynomial(p1, p2);

//     // Print the result
//     printf("\nSum of Polynomial 1 and Polynomial 2:\n");
//     printPolynomial(sum);

//     // Free memory (for simplicity, freeing not shown here)
    
//     return 0;
// }
