#include <stdio.h>
#include <stdlib.h>

int top = -1;
int value;

struct Stack
{
    int data;
    struct Stack *next;
};

struct Stack *head = NULL;

struct Stack *createStack(int value)
{
    struct Stack *newStackElement = (struct Stack *)malloc(sizeof(struct Stack));
    newStackElement->data = value;
    newStackElement->next = NULL;
    return newStackElement;
}

int size()
{
    int count = 0;
    struct Stack *temp = head;
    while (temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

int isEmpty()
{
    return top == NULL;
}

// int isFull()
// {
//     return top == NULL;
// }

int inputValue()
{
    int data;
    printf("Enter The Value To Insert :- ");
    scanf("%d", &data);
    return data;
}

void push()
{
    struct Stack *newStackElement = createStack(inputValue());
    if (isEmpty())
    {
        top = newStackElement;
        printf("New Stack Is Successfully Added In the Stack....");
        return;
    }

    struct Stack *temp = top;
    while (temp != NULL)
    {
        temp = temp->next;
    }
    temp->next = newStackElement;
    printf("New Stack Is Successfully Added In the Stack....");
    return;
}

void pop()
{
    if (isEmpty())
    {
        printf("Nothing To Pop Because The Stack Is Already Empty....");
        return;
    }

    struct Stack *temp = top;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    printf("%d From Stack Is Successfully Popped Out From the Stack....");
    temp = NULL;
    return;
}

int peek()
{
    struct Stack *temp = top;
    while (temp != NULL)
    {
        temp = temp->next;
    }
    return temp->data;
}

void displayStack()
{
    if (isEmpty())
    {
        printf("Stack Is Underflow....\n");
        return;
    }

    struct Stack *temp = top;
    printf("\n Current Stack Is :- ");
    while (temp != NULL)
    {
        printf("%d => ", temp);
        temp = temp->next;
    }
    printf("NULL");
}

int main()
{
    int choice;

    do
    {
        printf("0. To Exit\n");
        printf("1. Display Stack\n");
        printf("2. Push In Stack\n");
        printf("3. Pop From Stack\n");
        printf("4. Peek From Stack\n");
        printf("5. Size Of Stack\n");
        printf("\nEnter Your Choice :- ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("\Program Is Successfully Exited....\n");
            break;

        case 1:
            displayStack();
            break;

        case 2:
            push();
            break;

        case 3:
            pop();
            break;

        case 4:
            printf("The Top Element Of The Stack Is :- %d.",peek());
            break;

        case 5:
            printf("Current Size Of The Stack Is :- %d.",size());
            break;

        default:
            printf("\nWrong Choice....\n");
            break;
        }
    } while (choice != 0);

    return 0;
}