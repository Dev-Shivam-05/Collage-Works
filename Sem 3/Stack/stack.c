#include <stdio.h>
#define size 5

int stack[size];
int top = -1;

int isEmpty()
{
    return top == -1;
}

int isFull()
{
    return top == size - 1;
}

void push(int element)
{
    if (isFull())
    {
        printf("The Stack Is Full You Can't Push into it....\n");
        return;
    }
    stack[++top] = element;
}

int peek()
{
    return stack[top];
}

int pop()
{
    if (isEmpty())
    {
        printf("The Stack Is Empty Nothing To Pop From it....\n");
        return 0;
    }
    return stack[top--];
}

void DisplayStack()
{
    if (isEmpty())
    {
        printf("The Stack Is Empty Nothing To Display....\n");
        return;
    }
    int i;
    printf("Current Stack Is :- ");
    for (i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
}

int main()
{
    int choice, element, pop_element;
    do
    {
        printf("\n==============================\n");
        printf("0. To Exit the Program.\n");
        printf("1. Push Element.\n");
        printf("2. Pop Element.\n");
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
            getchar(); // Waits for user to press Enter
            break;

        case 1:
            printf("Enter A Element to Push :- ");
            scanf("%d", &element);
            push(element);
            break;

        case 2:
            pop_element = pop();
            printf("The Pop Element Is :- %d", pop_element);
            break;

        case 3:
            printf("The Peek Element In The Stack Is  :- %d", peek());
            break;

        case 4:
            DisplayStack();
            break;

        default:
            printf("Wrong Choice Please Enter Your Choice Again....");
            break;
        }
        // printf("==============================\n");
    } while (choice != 0);

    return 0;
}