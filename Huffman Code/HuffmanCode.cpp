#include <bits/stdc++.h>
using namespace std;

class HuffmanCoder {
public:
    unordered_map<char, string> encoder;
    unordered_map<string, char> decoder;

private:
    struct Node {
        char data;
        int cost;
        Node* left;
        Node* right;

        Node(char data, int cost) : data(data), cost(cost), left(nullptr), right(nullptr) {}

        bool operator>(const Node& other) const {
            return this->cost > other.cost;
        }
    };

    struct CompareNode {
        bool operator()(Node* a, Node* b) {
            return a->cost > b->cost; // min-heap
        }
    };

    void initEncoderDecoder(Node* node, string osf) {
        if (node == nullptr) return;

        if (node->left == nullptr && node->right == nullptr) {
            encoder[node->data] = osf;
            decoder[osf] = node->data;
        }

        initEncoderDecoder(node->left, osf + "0");
        initEncoderDecoder(node->right, osf + "1");
    }

    void deleteTree(Node* node) {
        if (!node) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    HuffmanCoder(const string& feeder) {
        unordered_map<char, int> fmap;
        for (char cc : feeder) {
            fmap[cc]++;
        }

        priority_queue<Node*, vector<Node*>, CompareNode> minHeap;
        for (auto& entry : fmap) {
            minHeap.push(new Node(entry.first, entry.second));
        }

        while (minHeap.size() != 1) {
            Node* first = minHeap.top(); minHeap.pop();
            Node* second = minHeap.top(); minHeap.pop();

            Node* newNode = new Node('\0', first->cost + second->cost);
            newNode->left = first;
            newNode->right = second;
            minHeap.push(newNode);
        }

        Node* root = minHeap.top(); minHeap.pop();
        initEncoderDecoder(root, "");
        deleteTree(root);
    }

    string encode(const string& source) {
        string ans = "";
        for (char c : source) {
            ans += encoder[c];
        }
        return ans;
    }

    string decode(const string& codedString) {
        string key = "";
        string ans = "";
        for (char c : codedString) {
            key += c;
            if (decoder.count(key)) {
                ans += decoder[key];
                key = "";
            }
        }
        return ans;
    }
};

int main() {
    string text = "huffman coding example";
    HuffmanCoder hc(text);

    cout << "Original : " << text << endl;

    string encoded = hc.encode(text);
    cout << "Encoded  : " << encoded << endl;

    string decoded = hc.decode(encoded);
    cout << "Decoded  : " << decoded << endl;

    cout << "\nCharacter Codes:" << endl;
    for (auto& entry : hc.encoder) {
        cout << "  '" << entry.first << "' -> " << entry.second << endl;
    }

    return 0;
}