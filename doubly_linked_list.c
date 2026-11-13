#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int nodeid;
    struct Node * next, * prev;
    
};

struct Node * createnode (int nid)
{
    struct Node *p = (struct Node *) malloc (sizeof (struct Node));
    p->nodeid = nid;
    p->next = NULL;
    p->prev = NULL;
    return p;
};

void forwardtraverse (struct Node *p)
{
    printf ("\n forward traversal: ");
    while (p != NULL)
    {
        printf (" %d ", p->nodeid);
        p = p->next;
    }
    printf ("\n");
}

void backwardtraverse (struct Node *p)
{
    printf ("\n backward traversal: ");
    while (p != NULL)
    {
        printf (" %d ", p->nodeid);
        p = p->prev;
    }
}

void insertmiddle (struct Node *p, int ins)
{
    struct Node * q = createnode(ins);
    // struct Node * q;

    while (p != NULL)
    {
        if (ins >= p->nodeid && ins <= p->next->nodeid)
        {
            // q = p->next;
            // p->next = newnode;
            // newnode->prev = p;
            // newnode->next = q;
            // q->prev = newnode;

            /*
            newnode->next = p->next;
            p->next->prev = newnode;
            newnode->prev = p;
            p->next = newnode;
            */
            q->next = p->next;
            q->prev = p->next->prev;
            p->next = q;
            p->next->prev = q;
            break;
        }
        p = p->next;
    }
}

void main (void)
{
    struct Node *start, *p, *current, *end;
    start = NULL;
    int nid;

    //-999 will terminate the input flow.
    /*
    while (1)
    {
        scanf ("%d", &nid);
        if (nid == -999) break;
        p = createnode (nid);

        if (start == NULL) { start = p; current = p; }
        else { current->next = p; p->prev = current; current = p; }
    }
    end = current;
    */
    int ins;
    while (1)
    {
        scanf ("%d", &ins);
        if (ins == -999) break;

        if (start == NULL)
        {
            p = createnode (ins);
            start = p;
            end = p;
            forwardtraverse (start);
            continue;
        }

        if (ins < start->nodeid)
        {
            p = createnode (ins);
            p->next = start;
            start->prev = p;
            start = p;
        }
        else if (ins > end->nodeid)
        {
            p = createnode (ins);
            end->next = p;
            p->prev = end;
            end = p;
        }
        else
        {
            insertmiddle(start, ins);
        }

        forwardtraverse (start);
    }
}


// gcc doubly_linked_list.c; ./a