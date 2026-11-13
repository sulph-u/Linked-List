#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int nodeid;
    struct Node *next, *prev;
};

struct Node *createnode(int nid)
{
    struct Node *p = malloc(sizeof(struct Node));

    
    p->nodeid = nid;
    p->next = NULL;
    p->prev = NULL;

    return p;
}


int SingleDigit(int n)
{
    if (n < 0) n = -n; 

    while (n >= 10)
    {
        int sum = 0;

        while (n > 0)
        {
            sum =sum+( n % 10);
            n = n/10;
        }

        n = sum;
    }

    return n;
}


void insertmiddle(struct Node **start,struct Node **end, int ins)
{
    struct Node *newnode = createnode(ins);
    struct Node *p = *start;

    if (*start == NULL)
    {
        *start = newnode;
        *end = newnode;
        return;
    }

    
    if (ins < (*start)->nodeid)
    {
        newnode->next = *start;
        (*start)->prev = newnode;
        *start = newnode;
        return;
    }

   
    if (ins >= (*end)->nodeid)
    {
        newnode->prev = *end;
        (*end)->next = newnode;
        *end = newnode;
        return;
    }

    
    while (p->next != NULL)
    {
        if (ins < p->next->nodeid)
        {
            newnode->next = p->next;
            newnode->prev = p;

            p->next->prev = newnode;
            p->next = newnode;

            return;
        }

        p = p->next;
    }
}

void forwardtraverse(struct Node *p)
{
    printf("\nSorted numbers: ");

    while (p != NULL)
    {
        printf("%d ", p->nodeid);
        p = p->next;
    }

    printf("\n");
}

int main(void)
{

    

    struct Node *start = NULL;
    struct Node *end = NULL;

    int num, result;

    printf("Enter numbers (-999 to stop):\n");

    while (1)
    {
        scanf("%d", &num);

        if (num == -999)
            break;

        result = SingleDigit(num);

        printf("SingleDigit of %d = %d\n",
               num, result);

        insertmiddle(&start, &end, result);

        forwardtraverse(start);
    }

    return 0;
}