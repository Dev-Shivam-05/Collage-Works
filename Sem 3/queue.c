#include <stdio.h>
#define size 5

int queue[size];
int front = -1;
int rear = -1;

int isEmpty()
{
    return rear == -1 && front == -1;
}

int isFull()
{
    return rear == size - 1;
}

void enqueue(int element)
{
    if (isFull())
    {
        printf("The Queue Is Full You Can't Enqueue New Elements into it....\n");
        return;
    }
    if (isEmpty())
    {
        front++;
    }
    queue[++rear] = element;
}

int peek()
{
    return queue[front];
}

int dequeue()
{
    if (isEmpty())
    {
        printf("The Queue Is Empty Nothing To Dequeue From it....\n");
        return 0;
    }
    int i;
    for (i = front - 1; i <= rear; i++)
    {
        queue[i-1] = queue[i];
    }
}

void Displayqueue()
{
    if (isEmpty())
    {
        printf("The Queue Is Empty Nothing To Display....\n");
        return;
    }
    int i;
    printf("Current Queue Is :- ");
    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
}

int main()
{
    int choice, element, pop_element;
    do
    {
        printf("\n==============================\n");
        printf("0. To Exit the Program.\n");
        printf("1. Enqueue Element.\n");
        printf("2. Dequeue Element.\n");
        printf("3. Peek Element.\n");
        printf("4. Display Element.\n");
        printf("\n==============================\n");
        printf("Enter Your Choice :- ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("Program Is Successfully Executed....\n");
            printf("Thanks For Coming, Have A Good Day....\n");
            printf("Press Enter To Exit....");
            getchar();
            break;

        case 1:
            printf("Enter A Element to Push :- ");
            scanf("%d", &element);
            enqueue(element);
            break;

        case 2:
            pop_element = dequeue();
            printf("The Pop Element Is :- %d", pop_element);
            break;

        case 3:
            printf("The Peek Element In The Queue Is  :- %d", peek());
            break;

        case 4:
            Displayqueue();
            break;

        default:
            printf("Wrong Choice Please Enter Your Choice Again....");
            break;
        }
        // printf("==============================\n");
    } while (choice != 0);

    return 0;
}