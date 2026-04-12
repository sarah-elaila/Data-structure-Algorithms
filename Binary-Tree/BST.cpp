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

    // O(1)
    int height(Node* node) {
        if (node == nullptr) return -1;
        return node->height;
    }

    // O(log n) average, O(n) worst
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

    // O(n)
    bool balanced(Node* node) {
        if (node == nullptr) return true;

        return abs(height(node->left) - height(node->right)) <= 1
            && balanced(node->left)
            && balanced(node->right);
    }

    // O(n)
    void display(Node* node, string details) {
        if (node == nullptr) return;

        cout << details << node->value << endl;

        display(node->left, "Left child of " + to_string(node->value) + " : ");
        display(node->right, "Right child of " + to_string(node->value) + " : ");
    }

    // O(n)
    void populateSorted(vector<int>& nums, int start, int end) {
        if (start >= end) return;

        int mid = (start + end) / 2;

        insert(nums[mid]); // O(log n)

        populateSorted(nums, start, mid);
        populateSorted(nums, mid + 1, end);
    }

public:
    BST() {
        root = nullptr;
    }

    // O(1)
    bool isEmpty() {
        return root == nullptr;
    }

    // O(log n) average
    void insert(int value) {
        root = insert(root, value);
    }

    // O(n)
    bool isBalanced() {
        return balanced(root);
    }

    // O(n)
    void display() {
        display(root, "Root Node: ");
    }

    // O(n log n)
    void populate(vector<int> nums) {
        for (int num : nums) {
            insert(num); // each insert O(log n)
        }
    }

    // O(n log n)
    void populateSorted(vector<int> nums) {
        populateSorted(nums, 0, nums.size());
    }
};

int main() {
    BST tree;

    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};

    // This creates a BALANCED BST
    tree.populateSorted(nums);

    tree.display();

    cout << "\nIs Balanced: " << (tree.isBalanced() ? "Yes" : "No") << endl;

    return 0;
}