#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
} typedef Node;

struct List
{
    struct Node *start; // starting point of node
} typedef List;

void insert_begin(List *L, int element)
{
    Node *new_node = (Node *)malloc(sizeof(Node)); // Allocate memeory for new node

    new_node->data = element; // stroring data part into a new node

    new_node->link = L->start; // setting the link of new node to that current node

    L->start = new_node; // update the start
}

void display(List L)
{
    if (L.start == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    Node *ptr = L.start; // ptr pointing to start and tranversing the list
    printf("Linked List Element : ");
    while (ptr != NULL)// if we use ptr->link != NULL the last node will not be display
    {
        printf("%d ", ptr->data); // printing the data element of node
        ptr = ptr->link;          // jump to link node
    }
    printf("\n");
    return;
}

int delete_begin(List *L)
{
    if (L->start == NULL)
    {
        printf("List is empty\n");
        return -1;
    }
    Node *save;
    int rv;

    save = L->start; // save the node that we have to delete

    L->start = L->start->link; // update the start  

    rv = save->data;
    free(save);
    return rv;
}

void insert_end(List *L, int element)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = element;
    new_node->link = NULL;

    // check whether list id empty or not
    if (L->start == NULL)
        L->start = new_node; // so our node will be the first node
    else
    {
        Node *ptr = L->start;
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = new_node;

    }
    return;
}

int delete_end(List *L)
{
    Node *save, *ptr;
    int rv;
    if (L->start == NULL)
    {
        printf("List is empty\n");
        return -1;
    }
    else if (L->start->link == NULL) // IF LIST CONTAIN ONLY ONE ELEMENT
    {
        save = L->start;
        rv = save->data;
        L->start = NULL;
        free(save);
        return rv;
    }

    ptr = L->start;
    while (ptr->link->link != NULL)
    {
        ptr = ptr->link;
    }
    save = ptr->link;
    rv = save->data;
    ptr->link = NULL;
    free(save);
    return rv;
}

int count(List L)
{
    int n = 0;
    Node *ptr = L.start;
    while (ptr != NULL)
    {
        n++;
        ptr = ptr->link;
    }
    return n;
}

void insert_at_loc(List *L, int loc, int element)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = element;
    new_node->link = NULL;
    Node *ptr = L->start;
    int n = count(*L);
    // int rv;

    if (n <= loc)
    {
        printf("List contain only %d elemrnts so we have to append at the end of the list\n", n);
        insert_end(L, element);
        return;
    }
    for (int i = 0; i < loc - 1; i++)
    {
        ptr = ptr->link;
    }
    new_node->link = ptr->link;
    ptr->link = new_node;
}

void reverse_list(List *L)
{
    int n = count(*L);
    Node *current = L->start;
    Node *prev = NULL;
    Node *next = NULL;

    if (current == NULL)
    {
        printf("List is empty\n");
        return;
    }

    // ref:- https://www.geeksforgeeks.org/reverse-a-linked-list/
    // for better explanation

    while (current != NULL)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    L->start = prev;
}

void main()
{
    List L;
    L.start = NULL; 

    while(1)
    {
        printf("Enter your choice as number\n1.Display the list\n2.Insert the first node\n3.Delete the first Node\n4.Insert at the last\n5.Delete the last node\n6.Count No. of Node\n7.Reverse the List\n8.Insert at location\n9.Exit\n");
        int n, temp;
        int t;
        scanf("%d", &n);

        switch(n)
        {
            case 1:
                display(L);
                printf("\n");
                break;
            
            case 2:
                printf("Enter Insert Element : ");
                scanf("%d", &temp);
                insert_begin(&L, temp);
                display(L);
                printf("\n");
                break;
            
            case 3:
                temp = delete_begin(&L);
                printf("After delete first node returns : %d\n", temp);
                display(L);
                printf("\n");
                break;
            
            case 4:
                printf("Enter Insert Element : ");
                scanf("%d", &temp);
                insert_end(&L, temp);
                display(L);
                printf("\n");
                break;
            
            case 5:
                temp = delete_end(&L);
                printf("After delete last node returns : %d\n", temp);
                display(L);
                printf("\n");
                break;
            
            case 6:
                temp = count(L);
                printf("Count No. of Nodes : %d\n", temp);
                printf("\n");
                break;
            
            case 7:
                reverse_list(&L);
                display(L);
                printf("\n");
                break;
            
            case 8:
                printf("Enter Location : ");
                scanf("%d", &t);
                printf("Enter Insert Element : ");
                scanf("%d", &temp);
                insert_at_loc(&L, t, temp);
                display(L);
                printf("\n");
                break;
            
            case 9:
                exit(0);
            
            default:
                printf("Wrong choice please give correct Choice\n");
                printf("\n");
        }   
    }
}
