#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class BST {
private:
    class Node {
    public:
        int value;
        Node* left;
        Node* right;
        int height;

        Node(int value) {
            this->value = value;
            left = nullptr;
            right = nullptr;
            height = 0;
        }
    };

    Node* root;

    int height(Node* node) {
        if (node == nullptr) return -1;
        return node->height;
    }

    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->value) {
            node->left = insert(node->left, value);
        }

        if (value > node->value) {
            node->right = insert(node->right, value);
        }

        node->height = max(height(node->left), height(node->right)) + 1;

        return node;
    }

    bool balanced(Node* node) {
        if (node == nullptr) return true;

        return abs(height(node->left) - height(node->right)) <= 1
            && balanced(node->left)
            && balanced(node->right);
    }

    void display(Node* node, string details) {
        if (node == nullptr) return;

        cout << details << node->value << endl;

        display(node->left, "Left child of " + to_string(node->value) + " : ");
        display(node->right, "Right child of " + to_string(node->value) + " : ");
    }

public:
    BST() {
        root = nullptr;
    }

    bool isEmpty() {
        return root == nullptr;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    bool isBalanced() {
        return balanced(root);
    }

    void display() {
        display(root, "Root Node: ");
    }

    void populate(vector<int> nums) {
        for (int num : nums) {
            insert(num);
        }
    }
};

int main() {
    BST tree;

    vector<int> nums = {5, 20, 7, 1, 4, 13, 9, 8, 3, 30};

    tree.populate(nums);

    tree.display();

    cout << "\nIs Balanced: " << (tree.isBalanced() ? "Yes" : "No") << endl;

    return 0;
}