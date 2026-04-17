#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
private:
    class Node {
    public:
        int data;
        int startInterval;
        int endInterval;
        Node* left;
        Node* right;

        Node(int startInterval, int endInterval) {
            this->startInterval = startInterval;
            this->endInterval = endInterval;
            this->data = 0;
            this->left = nullptr;
            this->right = nullptr;
        }
    };

    Node* root;

    // Time Complexity: O(n)
    // Builds the segment tree from the input array.
    Node* constructTree(const vector<int>& arr, int start, int end) {
        if (start == end) {
            // Leaf node
            Node* leaf = new Node(start, end);
            leaf->data = arr[start];
            return leaf;
        }

        Node* node = new Node(start, end);
        int mid = (start + end) / 2;

        node->left = constructTree(arr, start, mid);
        node->right = constructTree(arr, mid + 1, end);

        node->data = node->left->data + node->right->data;
        return node;
    }

    void display(Node* node) {
        if (node == nullptr) return;

        string str = "";

        if (node->left != nullptr) {
            str += "Interval=[" + to_string(node->left->startInterval) + "-" +
                   to_string(node->left->endInterval) + "] and data: " +
                   to_string(node->left->data) + " => ";
        } else {
            str += "No left child => ";
        }

        str += "Interval=[" + to_string(node->startInterval) + "-" +
               to_string(node->endInterval) + "] and data: " +
               to_string(node->data) + " <= ";

        if (node->right != nullptr) {
            str += "Interval=[" + to_string(node->right->startInterval) + "-" +
                   to_string(node->right->endInterval) + "] and data: " +
                   to_string(node->right->data);
        } else {
            str += "No right child";
        }

        cout << str << "\n\n";

        if (node->left != nullptr) {
            display(node->left);
        }

        if (node->right != nullptr) {
            display(node->right);
        }
    }

    // Time Complexity: O(log n) in a segment tree
    // Returns sum in range [qsi, qei].
    int query(Node* node, int qsi, int qei) {
        // Completely inside query range
        if (node->startInterval >= qsi && node->endInterval <= qei) {
            return node->data;
        }
        // Completely outside query range
        else if (node->startInterval > qei || node->endInterval < qsi) {
            return 0;
        }
        // Partially overlaps
        else {
            return query(node->left, qsi, qei) + query(node->right, qsi, qei);
        }
    }

    // Time Complexity: O(log n)
    // Updates the value at a given index.
    int update(Node* node, int index, int value) {
        if (index >= node->startInterval && index <= node->endInterval) {
            // Leaf node
            if (index == node->startInterval && index == node->endInterval) {
                node->data = value;
                return node->data;
            } else {
                int leftAns = update(node->left, index, value);
                int rightAns = update(node->right, index, value);
                node->data = leftAns + rightAns;
                return node->data;
            }
        }
        return node->data;
    }

public:
    // Time Complexity: O(n)
    SegmentTree(const vector<int>& arr) {
        root = constructTree(arr, 0, arr.size() - 1);
    }

    void display() {
        display(root);
    }

    // Time Complexity: O(log n)
    int query(int qsi, int qei) {
        return query(root, qsi, qei);
    }

    // Time Complexity: O(log n)
    void update(int index, int value) {
        root->data = update(root, index, value);
    }
};

int main() {
    vector<int> arr = {3, 8, 6, 7, -2, -8, 4, 9};
    SegmentTree tree(arr);

    // tree.display();

    cout << tree.query(1, 6) << endl;

    return 0;
}