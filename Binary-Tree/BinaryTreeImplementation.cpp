#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;

    void populate(Node*& node) {
        bool left, right;

        cout << "Do you want to enter left of " << node->value << " (1/0): ";
        cin >> left;

        if (left) {
            cout << "Enter the value of the left of " << node->value << ": ";
            int value;
            cin >> value;
            node->left = new Node(value);
            populate(node->left);
        }

        cout << "Do you want to enter right of " << node->value << " (1/0): ";
        cin >> right;

        if (right) {
            cout << "Enter the value of the right of " << node->value << ": ";
            int value;
            cin >> value;
            node->right = new Node(value);
            populate(node->right);
        }
    }

    void displayPretty(Node* node, string indent = "", bool isLeft = true) {
    if (node == nullptr) return;

    cout << indent;

    if (isLeft) {
        cout << "|----->";
        indent += "|      ";
    } else {
        cout << "------>";
        indent += "       ";
    }

    cout << node->value << endl;

    displayPretty(node->left, indent, true);
    displayPretty(node->right, indent, false);
}

public:
    BinaryTree() {
        root = nullptr;
    }

    void populate() {
        cout << "Enter the root node: ";
        int value;
        cin >> value;
        root = new Node(value);
        populate(root);
    }

    void display() {
        displayPretty(root);
    }
};

int main() {
    BinaryTree tree;
    tree.populate();
    cout << "\nTree structure:\n";
    tree.display();
    return 0;
}