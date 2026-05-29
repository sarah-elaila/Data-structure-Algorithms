#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
    int h;

    node(int item)
    {
        data = item;
        left = right = NULL;
        h = 0;
    }
};

class BST
{
public:
    node *root;

    BST()
    {
        root = NULL;
    }
};

int update_height(node* r);
int balance_factor(node* r);
node* rotate_right(node* p);
node* rotate_left(node* c);

node* insert_AVL(node* r, int item)
{
    if (r == NULL)
    {
        node* new_node = new node(item);
        r = new_node;
    }
    else if (item < r->data)
    {
        r->left = insert_AVL(r->left, item);
    }
    else if (item > r->data)
    {
        r->right = insert_AVL(r->right, item);
    }

    if (balance_factor(r) == 2)
    {
        if (balance_factor(r->left) == -1)
            r->left = rotate_left(r->left);

        r = rotate_right(r);
    }

    if (balance_factor(r) == -2)
    {
        if (balance_factor(r->right) == 1)
            r->right = rotate_right(r->right);

        r = rotate_left(r);
    }

    return r;
}

int balance_factor(node* r)
{
    if (r == NULL)
        return 0;

    return update_height(r->left) - update_height(r->right);
}

int update_height(node* r)
{
    int left_subtree, right_subtree;

    if (r == NULL)
        return -1;
    else
    {
        left_subtree = update_height(r->left);
        right_subtree = update_height(r->right);
        return max(left_subtree, right_subtree) + 1;
    }
}

node* rotate_right(node* p)
{
    node* c = p->left;
    node* t = c->right;

    c->right = p;
    p->left = t;

    p->h = max(update_height(p->left), update_height(p->right)) + 1;
    c->h = max(update_height(c->left), update_height(c->right)) + 1;

    return c;
}

node* rotate_left(node* c)
{
    node* p = c->right;
    node* t = p->left;

    p->left = c;
    c->right = t;

    c->h = max(update_height(c->left), update_height(c->right)) + 1;
    p->h = max(update_height(p->left), update_height(p->right)) + 1;

    return p;
}

void printTree(node* r)
{
    if (r == NULL)
        return;
    cout << r->data << " ";
    printTree(r->left);
    printTree(r->right);
    
}

int main()
{
    BST tree;

    tree.root = insert_AVL(tree.root, 10);
    tree.root = insert_AVL(tree.root, 20);
    tree.root = insert_AVL(tree.root, 30);
    tree.root = insert_AVL(tree.root, 40);
    tree.root = insert_AVL(tree.root, 50);

    cout << "AVL Tree: ";
    printTree(tree.root);

    return 0;
}