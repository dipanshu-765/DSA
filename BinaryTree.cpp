#include <stdio.h>
#include "Queue.h"

//Creating Binary Tree and Preorder, postorder, inorder tree traversals

struct Node *root=NULL;

void treeCreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    printf("Enter root value\n");
    scanf("%d", &x);
    root=(struct Node *)malloc(sizeof(struct Node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q, root);

    while(!isEmpty(q))
    {
        p=dequeue(&q);
        printf("enter left child of %d\n", p->data);
        scanf("%d", &x);
        if(x!=-1)
        {
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q, t);
        }
        printf("enter right child of %d\n", p->data);
        scanf("%d", &x);
        if(x!=-1)
        {
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q, t);
        }
    }
}

void preorder(struct Node *p)
{
    if(p)
    {
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void postorder(struct Node *p)
{
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    }
}

void inorder(struct Node *p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}

int main()
{
    treeCreate();
    printf("Pre Order traversal: ");
    preorder(root);
    printf("\nIn Order traversal: ");
    inorder(root);
    printf("\nPost Order traversal: ");
    postorder(root);
    return 0;
}
