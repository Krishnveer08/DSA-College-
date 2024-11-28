#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coef;
    int powOfX;
    int powOfY;
    struct Node *next;
} Node;

Node *createNode(int coef, int powOfX, int powOfY)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->coef = coef;
    newNode->powOfX = powOfX;
    newNode->powOfY = powOfY;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node **head, int coef, int powOfX, int powOfY)
{
    Node *newNode = createNode(coef, powOfX, powOfY);
    newNode->next = *head;
    *head = newNode;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->coef > 0 && temp != head)
        {
            printf(" + ");
        }
        printf("%dx^%dy^%d", temp->coef, temp->powOfX, temp->powOfY);
        temp = temp->next;
    }
    printf("\n");
}

Node *add(Node *poly1, Node *poly2)
{
    Node *result = NULL;
    Node *p1 = poly1;
    Node *p2 = poly2;

    while (p1 != NULL || p2 != NULL)
    {
        if (p1 == NULL)
        {
            insertNode(&result, p2->coef, p2->powOfX, p2->powOfY);
            p2 = p2->next;
        }
        else if (p2 == NULL)
        {
            insertNode(&result, p1->coef, p1->powOfX, p1->powOfY);
            p1 = p1->next;
        }
        else if (p1->powOfX == p2->powOfX && p1->powOfY == p2->powOfY)
        {
            int sum = p1->coef + p2->coef;
            if (sum != 0)
            {
                insertNode(&result, sum, p1->powOfX, p1->powOfY);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->powOfX > p2->powOfX || (p1->powOfX == p2->powOfX && p1->powOfY > p2->powOfY))
        {
            insertNode(&result, p1->coef, p1->powOfX, p1->powOfY);
            p1 = p1->next;
        }
        else
        {
            insertNode(&result, p2->coef, p2->powOfX, p2->powOfY);
            p2 = p2->next;
        }
    }
    return result;
}

void freePolynomial(Node *head)
{
    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    Node *poly1 = NULL;
    insertNode(&poly1, -5, 3, 2);
    insertNode(&poly1, 4, 2, 1);
    insertNode(&poly1, 3, 1, 2);

    Node *poly2 = NULL;
    insertNode(&poly2, 2, 2, 2);
    insertNode(&poly2, 6, 1, 1);
    insertNode(&poly2, 3, 2, 1);

    printf("Polynomial 1:\n");
    display(poly1);

    printf("Polynomial 2:\n");
    display(poly2);

    Node *result = add(poly1, poly2);

    printf("Sum of Polynomials:\n");
    display(result);

    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}
