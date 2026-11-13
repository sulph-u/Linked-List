#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int nodeid;
    struct Node *next;
    struct Node *prev;
};

// Create a new node
struct Node *createnode(int nid)
{
    struct Node *p;

    p = (struct Node *) malloc(sizeof(struct Node));

    if (p == NULL)
    {
        printf("Memory allocation failed!");
        exit(1);
    }

    p->nodeid = nid;
    p->next = NULL;
    p->prev = NULL;

    return p;
}

// Calculate repeated digit sum
int digitSum(int n)
{
    n = abs(n);

    while (n >= 10)
    {
        int sum = 0;

        while (n > 0)
        {
            sum = sum + (n % 10);
            n = n / 10;
        }

        n = sum;
    }

    return n;
}

// Forward traversal
void forwardtraverse(struct Node *p)
{
    printf("\nForward traversal: ");

    while (p != NULL)
    {
        printf("%d ", p->nodeid);
        p = p->next;
    }

    printf("\n");
}

// Display digit sums
void displaySum(struct Node *p)
{
    printf("Digit sums: ");

    while (p != NULL)
    {
        printf("%d ", digitSum(p->nodeid));
        p = p->next;
    }

    printf("\n");
}

// Backward traversal
void backwardtraverse(struct Node *p)
{
    printf("Backward traversal: ");

    while (p != NULL)
    {
        printf("%d ", p->nodeid);
        p = p->prev;
    }

    printf("\n");
}

// Insert node according to digit sum
void insertSorted(struct Node **start,struct Node **end, int ins)
{
    struct Node *newnode;
    struct Node *p;
    int sum;

    newnode = createnode(ins);
    p = *start;

    sum = digitSum(ins);

    // First node
    if (*start == NULL)
    {
        *start = newnode;
        *end = newnode;
        return;
    }

    // Insert at beginning
    if (sum < digitSum((*start)->nodeid))
    {
        newnode->next = *start;
        (*start)->prev = newnode;
        *start = newnode;
        return;
    }


    while (p->next != NULL &&digitSum(p->next->nodeid) <= sum)
    {
        p = p->next;
    }

    // Insert after p
    newnode->next = p->next;
    newnode->prev = p;

    if (p->next != NULL)
    {
        p->next->prev = newnode;
    }
    else
    {
        *end = newnode;
    }

    p->next = newnode;
}

// Main function
int main()
{
    struct Node *start;
    struct Node *end;

    int ins;

    start = NULL;
    end = NULL;

    printf("Enter numbers (-999 to stop):\n");

    while (1)
    {
        scanf("%d", &ins);

        if (ins == -999)
        {
            break;
        }

        insertSorted(&start, &end, ins);

        forwardtraverse(start);
        displaySum(start);
    }

    printf("\n\n");

    forwardtraverse(start);
    displaySum(start);
    backwardtraverse(end);

    return 0;
}