#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

struct Node
{
    int data;
    struct Node *next;
};

struct List
{
    struct Node *pHead;
};

typedef struct Node* Position;

#endif // LIST_H_INCLUDED
