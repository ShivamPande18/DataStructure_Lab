#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int machineNumber;
    int timeLeft;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(int machineNumber) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->machineNumber = machineNumber;
    newNode->timeLeft = 0;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void enqueue(Node* head, int machineNumber) {
    Node* newNode = createNode(machineNumber);

    if (head == NULL) {
        head = newNode;
        (head)->next = head;
        (head)->prev = head;
    } else {
        Node* last = (head)->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        (head)->prev = newNode;
    }

    printf("Washing machine %d added to the queue.\n", machineNumber);
}

void displayQueue(Node* head) {
    if (head == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    Node* current = head;
    do {
        printf("Washing machine %d - Time left: %d minutes\n", current->machineNumber, current->timeLeft);
        current = current->next;
    } while (current != head);
}

void simulateTime(Node* head, int minutes) {
    if (head == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    Node* current = head;
    do {
        if (current->timeLeft > 0) {
            current->timeLeft -= minutes;
            if (current->timeLeft <= 0) {
                printf("Washing machine %d is now available for the next person.\n", current->machineNumber);
            }
        }
        current = current->next;
    } while (current != head);
}

void bookMachine(Node* head, int machineNumber, int timeToBook) {
    if (head == NULL) {
        printf("Queue is empty. Cannot book the machine.\n");
        return;
    }

    Node* current = *head;
    do {
        if (current->machineNumber == machineNumber) {
            if (current->timeLeft == 0) {
                current->timeLeft = timeToBook;
                printf("Washing machine %d booked for %d minutes.\n", machineNumber, timeToBook);
            } else {
                printf("Washing machine %d is already booked. Try again later.\n", machineNumber);
            }
            return;
        }
        current = current->next;
    } while (current != *head);

    printf("Washing machine %d not found in the queue.\n", machineNumber);
}

void dequeue(Node* head) {
    if (head == NULL) {
        printf("Queue is empty. Nothing to dequeue.\n");
        return;
    }

    Node* first = *head;
    Node* last = first->prev;

    if (first == last) {
        free(first);
        head = NULL;
    } else {
        head = first->next;
        last->next = *head;
        (head)->prev = last;
        free(first);
    }

    printf("Washing machine %d removed from the queue.\n", first->machineNumber);
}

void freeList(Node* head) {
    if (head == NULL) {
        return;
    }

    Node* current = *head;
    Node* temp;

    do {
        temp = current;
        current = current->next;
        free(temp);
    } while (current != *head);

    *head = NULL;
}

int main() {
    struct Node* head = NULL;

    enqueue(head, 1);
    enqueue(head, 2);
    enqueue(head, 3);

    displayQueue(head);

    bookMachine(head, 2, 30);
    bookMachine(head, 1, 20);

    displayQueue(head);

    simulateTime(head, 15);

    displayQueue(head);

    dequeue(head);

    displayQueue(head);

    freeList(head);

    return 0;
}
