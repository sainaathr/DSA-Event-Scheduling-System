#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Event {
    int id;
    int start;
    int end;
    int priority;
    struct Event* next;
};

struct Event* head = NULL;

// Check time conflict
int checkConflict(int start, int end) {
    struct Event* temp = head;
    while (temp != NULL) {
        if ((start < temp->end) && (end > temp->start)) {
            return 1; // Conflict
        }
        temp = temp->next;
    }
    return 0; // No conflict
}

// Add event
void addEvent() {
    struct Event* newEvent = (struct Event*)malloc(sizeof(struct Event));

    printf("Enter Event ID: ");
    scanf("%d", &newEvent->id);

    printf("Enter Start Time: ");
    scanf("%d", &newEvent->start);

    printf("Enter End Time: ");
    scanf("%d", &newEvent->end);

    printf("Enter Priority (1-High, 2-Medium, 3-Low): ");
    scanf("%d", &newEvent->priority);

    if (checkConflict(newEvent->start, newEvent->end)) {
        printf("❌ Time Conflict Detected! Event Not Added.\n");
        free(newEvent);
        return;
    }

    newEvent->next = head;
    head = newEvent;

    printf("✅ Event Added Successfully.\n");
}

// Display events
void displayEvents() {
    struct Event* temp = head;

    if (temp == NULL) {
        printf("No events scheduled.\n");
        return;
    }

    printf("\nScheduled Events:\n");
    while (temp != NULL) {
        printf("ID: %d | Start: %d | End: %d | Priority: %d\n",
               temp->id, temp->start, temp->end, temp->priority);
        temp = temp->next;
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Event Scheduling System ---\n");
        printf("1. Add Event\n");
        printf("2. Display Events\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEvent(); break;
            case 2: displayEvents(); break;
            case 3: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
