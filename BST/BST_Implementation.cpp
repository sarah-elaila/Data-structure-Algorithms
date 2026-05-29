#include <iostream>
#include <queue>
using namespace std;

class Node
 {
    public:
        int data;
        Node *left, *right;
    Node (int item)
    {
        data = item;
        left = right = NULL;
    }
};


Node *insert_BST(int item, Node*r)
{
    if (r == NULL)
    {
        Node* new_node = new Node(item);
        r = new_node;
    }
    else if (item < r->data)
    {
        r->left = insert_BST(item, r->left);
    }
    else if (item > r->data)
    {
        r->right = insert_BST(item, r->right);
    }
    return r;
}

class BST
{

    public:
    Node *root;
    BST()
    {
        root = NULL;
    }
    void insertion_BST(int item)
    {
        root = insert_BST(item, root);
    }

};
void inorder(Node* r)
{
    if (r == NULL)
    {
        return;
    }
    
    inorder(r->left);
    cout << r->data << " ";
    inorder(r->right);
    
}

void preorder(Node *r)
{
    if (r == NULL)
    {
        return ;
    }
    cout << r->data << " ";
    preorder(r->left);
    preorder(r->right);
}

void postorder(Node *r)
{
    if (r == NULL)
    {
        return ;
    }
    
    postorder(r->left);
    postorder(r->right);
    cout << r->data << " ";
}

void BFS_BST(Node* r)
{
    if (r== NULL)
        return;
    queue <Node*> q;
    q.push(r);
    while(!q.empty())
    {
        Node*current = q.front();
        if (current -> left != NULL)
        {
            q.push(current -> left);
        }
        if (current -> right != NULL)
        {
            q.push(current -> right);
        }
        cout << current->data <<" ";
        q.pop();
    }
    cout << endl;
}

Node *search_BST(int key, Node*r)
{
    if (r==NULL)
    {
        return NULL;
    }
    else if(r->data == key)
    {
        return r;
    }
    else if (r->data > key)

    {
        return search_BST(key, r->left);
    }
    else if(r->data < key)
    {
        return search_BST(key, r->right);
    }
      return NULL;
}

Node *findMin (Node* r)
{
    if (r == NULL)
    {
        return NULL;
    }
    else if (r->left == NULL)
    {
        return r;
    }
    else
    {
        return findMin (r->left);
    }
}

Node* delete_BST(int x, Node* r)
{
    Node* temp;
    if (r == NULL)
    {
        return NULL;
    }
    else if (x < r->data)
    {
        r->left = delete_BST(x, r->left);
    }
    else if (x >  r->data)
    {
        r->right = delete_BST(x, r->right);
    }
    else
    {
        if (r->left == NULL && r->right == NULL)
        {
            temp = r;
            delete temp;
            r = NULL;
        }
       else if (r->left != NULL && r->right == NULL)
        {
            temp = r;
            r = r->left;
            delete temp;
        }
       else if (r->left == NULL && r->right != NULL)
        {
            temp = r;
            r = r->right;
            delete temp;
        }
        else
        {
            Node *minim = findMin(r->right);
            r->data = minim->data;
            r->right = delete_BST(minim->data, r->right);

        }
        

    }
    return r;

}






int main()
{
    BST tree;

    tree.insertion_BST(5);
    tree.insertion_BST(6);
    tree.root = insert_BST(7, tree.root);
    tree.root = insert_BST(9, tree.root);
    tree.root = insert_BST(10, tree.root);
    tree.root = insert_BST(11, tree.root);
    tree.root = insert_BST(1, tree.root);

    cout << "BST Inorder Traversal: ";
    inorder(tree.root);
    cout << endl;

    Node* MINI = findMin (tree.root);
    cout << MINI->data;

    tree.root = delete_BST(11, tree.root);

    cout << "BST Inorder Traversal: ";
    inorder(tree.root);
    cout << endl;

     BFS_BST(tree.root);
    return 0;
}