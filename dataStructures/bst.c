#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// For non recursive in order traversal: {
struct stack
{
    struct node *data;
    struct stack *next;
};

struct stack *top = NULL;

int isEmpty(struct stack *top)
{
    if (top == NULL)
        return 1;
    else
        return 0;
}

int isFull(struct stack *top)
{
    struct stack *p = (struct stack *)malloc(sizeof(struct stack));
    if (p == NULL)
        return 1;
    else
        return 0;
}

struct stack *push(struct stack *top, struct node *T)
{
    if (isFull(top))
        printf("Stack Overflow\n");
    else
    {
        struct stack *n = (struct stack *)malloc(sizeof(struct stack));
        n->data = T;
        n->next = top;
        top = n;
        return top;
    }
}

struct node *pop(struct stack **top)
{
    if (isEmpty(*top))
        printf("Stack underflow\n");
    else
    {
        struct stack *n = *top;
        *top = (*top)->next;
        struct node *T = n->data;
        free(n);
        return T;
    }
}
void inOrderIter(struct node *root)
{
    struct node *T = root;
    while (T != NULL)
    {
        top = push(top, T);
        T = T->left;
    }
    while (!isEmpty(top))
    {
        T = pop(&top);
        printf("%d ", T->data);
        T = T->right;
        while (T != NULL)
        {
            top = push(top, T);
            T = T->left;
        }
    }
}
//}

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
            return 0;
        if (prev != NULL && root->data <= prev->data)
            return 0;
        prev = root;
        return isBST(root->right);
    }
    else
        return 1;
}

struct node *search(struct node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (key == root->data)
        return root;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

struct node *searchIter(struct node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("can't insert %d : already present in bst", key);
            return;
        }
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    struct node *new = createNode(key);
    if (key < prev->data)
        prev->left = new;
    else
        prev->right = new;
}

struct node *inOrderPredecessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
        root = root->right;
    return root;
}

struct node *deleteNode(struct node *root, int value)
{
    struct node *iPre;
    if (root == NULL)
        return NULL;

    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    if (value < root->data)
        root->left = deleteNode(root->left, value);

    else if (value > root->data)
        root->right = deleteNode(root->right, value);

    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}

int main()
{
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);

    //   5
    //  / \
    //  3  6
    // / \
    // 1  4

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    inOrder(p);
    printf("<-inorder of loaded bst");

    int s;
    while (1)
    {
        printf("\n1.in order 2.bst or not 3.search recursive 4.search iterative 5.insert 6.delete 7.in order iterative 8.exit\n");
        printf("\nchoose: ");
        scanf("%d", &s);
        switch (s)
        {
        case 1:
            inOrder(p);
            printf("<-Inorder\n");
            break;
        case 2:
            if (isBST(p))
                printf("It's a bst\n");
            else
                printf("It's not a bst\n");
            break;
        case 3:
            printf("Which element to search: ");
            scanf("%d", &s);
            struct node *sr = search(p, s);
            if (sr != NULL)
                printf("found: %d", sr->data);
            else
                printf("Element not found\n");
            break;
        case 4:
            printf("Which element to search: ");
            scanf("%d", &s);
            struct node *si = searchIter(p, s);
            if (si != NULL)
                printf("found by iterative method: %d", si->data);
            else
                printf("Element not found\n");
            break;
        case 5:
            inOrder(p);
            printf("<-Current Inorder\n");
            printf("Which element to insert: ");
            scanf("%d", &s);
            insert(p, s);
            inOrder(p);
            printf("<-Inorder after Insertion\n");
            break;
        case 6:
            inOrder(p);
            printf("<-Current Inorder\n");
            printf("Which element to delete: ");
            scanf("%d", &s);
            deleteNode(p, s);
            inOrder(p);
            printf("<-Inorder after deletion\n");
            break;
        case 7:
            inOrderIter(p);
            printf("<-Non recursive Inorder\n");
            break;
        case 8:
            return 0;
        }
    }
    return 0;
}
