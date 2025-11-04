#include <stdio.h>
#include <stdlib.h>

// gonna ask sir to explain this
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int isEmpty()
{
    return head == NULL;
}

int size()
{
    if (isEmpty())
    {
        printf("Link List Is Empty.");
        return 0;
    }

    int length = 0;
    struct Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        length++;
    }

    return length;
}

void insertAtBeginning(int value)
{
    struct Node *newNode = createNode(value);
    newNode->next = head;
    head = newNode;
    printf("\nInserted %d at beginning.\n", value);
}

void insertAtEnd(int value)
{
    struct Node *newNode = createNode(value);

    if (isEmpty())
    {
        newNode->next = head;
        head = newNode;
        // printf("\nInserted %d at end.\n", value);
        // return;
    }

    struct Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("\nInserted %d at end.\n", value);
}

void insertAtPosition(int value, int position)
{
    if (position > size() || position < 0)
    {
        printf("Position out of range.\n");
        return;
    }

    if (position == 0)
    {
        insertAtBeginning(value);
        return;
    }

    struct Node *newNode = createNode(value);
    struct Node *temp = head;

    int i = 0;
    while (i < position)
    {
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("\nInserted %d at position %d.\n", value, position);
}

void deleteFromBeginning()
{
    if (isEmpty())
    {
        printf("Link List Is Already Empty.");
        return;
    }

    struct Node *deletedNOde = head;
    // Process opf deleting 1st Node
    head = head->next;
    free(deletedNOde);
}

void deleteAtEnd()
{
    if (isEmpty())
    {
        printf("Link List Is Already Empty.");
        return;
    }

    struct Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    struct Node *deletedNOde = temp->next->next;
    // Process opf deleting The Last Node
    temp->next = NULL;
    free(deletedNOde);
}

void deleteAtPosition(int value, int position)
{
    if (position > size() || position < 0)
    {
        printf("Position out of range.\n");
        return;
    }

    if (position == 0)
    {
        deleteFromBeginning();
        return;
    }

    struct Node *temp = head;
    int i = 0;
    while (i < position)
    {
        temp = temp->next;
        i++;
    }
    struct Node *deletedNOde = head;
    temp->next = temp->next->next;
    printf("\Deleted %d at position %d.\n", deletedNOde, position);
    free(deletedNOde);
}

void DisplayLinkList()
{
    struct Node *temp = head;

    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("\n Current Linked List :- ");
    while (temp != NULL)
    {
        printf("%d, -> ", temp->data);
        temp = temp->next;
    }
    printf("Null\n");
}

int main()
{
    int choice;
    int value;
    int position;
    int sizeofList;

    do
    {
        printf("1. Display Link List.\n");
        printf("2. Insert At Front In Link List.\n");
        printf("3. Insert At End In Link List.\n");
        printf("4. Insert At Any Position In Link List.\n");
        printf("5. Check the Size Link List.\n");
        printf("0. Exit The Program.\n");
        printf("Enter Your Choice :- ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("Program Is Successfully Exited....\n");
            break;

        case 1:
            DisplayLinkList();
            break;

        case 2:
            printf("Enter A Value To Insert :- ");
            scanf("%d", &value);
            insertAtBeginning(value);
            break;

        case 3:
            printf("Enter A Value To Insert :- ");
            scanf("%d", &value);
            insertAtEnd(value);
            break;

        case 4:
            printf("Enter A Value To Insert :- ");
            scanf("%d", &value);
            DisplayLinkList();
            printf("Enter A Position To Insert At :- ");
            scanf("%d", &position);
            insertAtPosition(value, position);
            break;

        case 5:
            sizeofList = size();
            printf("Current Size of Link List Is :- %d", sizeofList);
            break;
        default:
            printf("\nWrong Choice.\n");
            break;
        }
    } while (choice != 0);

    return 0;
}