#include <iostream>
#include <queue>
#include <map>
#include <chrono>
using namespace std;
using namespace std::chrono;

class Node {
public:
    char data;
    int freq;
    Node* left;
    Node* right;

    Node(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

struct CompareNodes {
    bool operator()(const Node* a, const Node* b) const {
        return a->freq > b->freq;
    }
};

void assignCodes(Node* root, string code, map<char, string>& huffmanCodes) {
    if (root == nullptr)
        return;

    if (!root->left && !root->right)
        huffmanCodes[root->data] = code;

    assignCodes(root->left, code + "0", huffmanCodes);
    assignCodes(root->right, code + "1", huffmanCodes);
}

Node* buildHuffmanTree(char arr[], int freq[], int size) {
    priority_queue<Node*, vector<Node*>, CompareNodes> pq;
    for (int i = 0; i < size; ++i)
        pq.push(new Node(arr[i], freq[i]));

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }
    return pq.top();
}

void printHuffmanCodes(Node* root) {
    map<char, string> huffmanCodes;
    assignCodes(root, "", huffmanCodes);

    cout << "Huffman Codes:" << endl;
    for (auto& pair : huffmanCodes)
        cout << pair.first << " : " << pair.second << endl;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    map<char, int> freqMap;
    for (char c : s)
        freqMap[c]++;

    int size = freqMap.size();
    char* arr = new char[size];
    int* freq = new int[size];

    int index = 0;
    for (auto& pair : freqMap) {
        arr[index] = pair.first;
        freq[index] = pair.second;
        ++index;
    }

    auto start = steady_clock::now();
    Node* root = buildHuffmanTree(arr, freq, size);
    auto stop = steady_clock::now();

    printHuffmanCodes(root);

    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " nanoseconds" << endl;

    return 0;
}

