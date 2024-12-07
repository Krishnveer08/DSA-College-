#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} node;

typedef struct dll {
    node* head;
    node* tail;
} dll;

dll* create_list() {
    dll* list = (dll*)malloc(sizeof(dll));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

node* create_node(int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void insert_front(dll* list, int data) {
    node* new_node = create_node(data);
    if (list->head == NULL) {
        list->head = list->tail = new_node;
    } else {
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
    }
    printf("Inserted %d at front\n", data);
}

void insert_end(dll* list, int data) {
    node* new_node = create_node(data);
    if (list->tail == NULL) {
        list->head = list->tail = new_node;
    } else {
        new_node->prev = list->tail;
        list->tail->next = new_node;
        list->tail = new_node;
    }
    printf("Inserted %d at end\n", data);
}

void delete_front(dll* list) {
    if (list->head == NULL) return;
    node* temp = list->head;
    if (list->head == list->tail) {
        list->head = list->tail = NULL;
    } else {
        list->head = list->head->next;
        list->head->prev = NULL;
    }
    printf("Deleted %d from front\n", temp->data);
    free(temp);
}

void delete_end(dll* list) {
    if (list->tail == NULL) return;
    node* temp = list->tail;
    if (list->head == list->tail) {
        list->head = list->tail = NULL;
    } else {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    }
    printf("Deleted %d from end\n", temp->data);
    free(temp);
}

int search(dll* list, int key) {
    node* current = list->head;
    while (current) {
        if (current->data == key) return 1;
        current = current->next;
    }
    return 0;
}

void display_forward(dll* list) {
    node* current = list->head;
    printf("List in forward direction: ");
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void display_reverse(dll* list) {
    node* current = list->tail;
    printf("List in reverse direction: ");
    while (current) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

int main() {
    dll* list = create_list();

    insert_front(list, 2);
    insert_end(list, 3);
    insert_front(list, 1);
    insert_end(list, 4);
    display_forward(list);
    display_reverse(list);

    delete_front(list);
    delete_end(list);
    display_forward(list);
    display_reverse(list);

    if (search(list, 3))
        printf("Found 3 in the list\n");
    else
        printf("3 not found in the list\n");

    if (search(list, 5))
        printf("Found 5 in the list\n");
    else
        printf("5 not found in the list\n");

    return 0;
}