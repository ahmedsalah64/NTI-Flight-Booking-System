#include <stdio.h>
#include <string.h>

#define MAX_CLIENTS 10

typedef struct {
    char name[50];
    char ID[20];
    char seatNumber[10];
    char clientClass[20];  // Added field for client's class
} Client;

Client clients[MAX_CLIENTS];
int clientCount = 0;

void NEW_CLIENT() {
    if (clientCount >= MAX_CLIENTS) {
        printf("Client list is full.\n");
        return;
    }

    printf("Enter client name: ");
    scanf("%49s", clients[clientCount].name);
    printf("Enter client ID: ");
    scanf("%19s", clients[clientCount].ID);
    printf("Enter seat number: ");
    scanf("%9s", clients[clientCount].seatNumber);
    printf("Enter client class (Economy/Business/First Class): ");
    scanf("%19s", clients[clientCount].clientClass);

    clientCount++;
    printf("New client added.\n");
}

void DELETE_CLIENT() {
    char ID[20];
    printf("Enter client ID to delete: ");
    scanf("%19s", ID);

    for (int i = 0; i < clientCount; i++) {
        if (strcmp(clients[i].ID, ID) == 0) {
            for (int j = i; j < clientCount - 1; j++) {
                clients[j] = clients[j + 1];
            }
            clientCount--;
            printf("Client deleted.\n");
            return;
        }
    }

    printf("Client not found.\n");
}

void CLIENT_LIST() {
    printf("List of Clients:\n");
    for (int i = 0; i < clientCount; i++) {
        printf("Name: %s, ID: %s\n", clients[i].name, clients[i].ID);
    }
}

void CLIENT_EDIT() {
    char ID[20];
    printf("Enter client ID to edit: ");
    scanf("%19s", ID);

    for (int i = 0; i < clientCount; i++) {
        if (strcmp(clients[i].ID, ID) == 0) {
            printf("Enter new name: ");
            scanf("%49s", clients[i].name);
            printf("Client information updated.\n");
            return;
        }
    }

    printf("Client not found.\n");
}

void FREE_SEATS() {
    int totalSeats = 50;  // Assuming a total of 50 seats for simplicity
    int freeSeats = totalSeats - clientCount;
    printf("Number of free seats: %d\n", freeSeats);
}

void CLASS_LIST() {
    printf("Clients by Class:\n");

    const char *classes[] = {"Economy", "Business", "First Class"};
    for (int c = 0; c < 3; c++) {
        printf("\n%s Class:\n", classes[c]);
        for (int i = 0; i < clientCount; i++) {
            if (strcmp(clients[i].clientClass, classes[c]) == 0) {
                printf("Name: %s, ID: %s, Seat: %s\n", clients[i].name, clients[i].ID, clients[i].seatNumber);
            }
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nFlight Booking System\n");
        printf("1. Add New Client\n");
        printf("2. Delete Client\n");
        printf("3. Client List\n");
        printf("4. Edit Client\n");
        printf("5. Free Seats\n");
        printf("6. Class List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                NEW_CLIENT();
                break;
            case 2:
                DELETE_CLIENT();
                break;
            case 3:
                CLIENT_LIST();
                break;
            case 4:
                CLIENT_EDIT();
                break;
            case 5:
                FREE_SEATS();
                break;
            case 6:
                CLASS_LIST();
                break;
            case 7:
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
