/*
    Name: Chetan Shekhar Patil
    Batch: A1
    Roll No: 17

    Program : Design & Implement Huffman Algorithm using Greedy Approach. 
	Calculate the time complexity of the algorithm.
*/ 


#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// tree node
struct HuffmanNode {
    char character;
    int frequency;
    HuffmanNode *left, *right;
    HuffmanNode(char character, int frequency)
        : character(character), frequency(frequency), left(nullptr), right(nullptr) {}
};

// custom comparator
struct CompareNodes {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->frequency > b->frequency;
    }
};

// Building Huffman tree
HuffmanNode* buildHuffmanTree(string text) {
    // Count frequency of each character in the text
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    // Create a priority queue to store the nodes
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (auto p : freq) {
        pq.push(new HuffmanNode(p.first, p.second));
    }

    // Build Huffman tree by combining the two nodes with the smallest frequency
    while (pq.size() > 1) {
        HuffmanNode* left = pq.top();
        pq.pop();
        HuffmanNode* right = pq.top();
        pq.pop();
        HuffmanNode* parent = new HuffmanNode('#', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    // The remaining node is the root of the Huffman tree
    return pq.top();
}

// Traverse Huffman tree and generate codes for each character
void generateCodes(HuffmanNode* root, string code, unordered_map<char, string>& codes) {
    if (root == nullptr) {
        return;
    }

    if (root->left == nullptr && root->right == nullptr) {
        codes[root->character] = code;
    }

    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

// Encode text using Huffman codes
string encode(string text, unordered_map<char, string>& codes) {
    string encoded = "";
    for (char ch : text) {
        encoded += codes[ch];
    }
    return encoded;
}

// Decode text using Huffman codes
string decode(string encoded, HuffmanNode* root) {
    string decoded = "";
    HuffmanNode* node = root;
    for (char bit : encoded) {
        if (bit == '0') {
            node = node->left;
        } else {
            node = node->right;
        }
        if (node->left == nullptr && node->right == nullptr) {
            decoded += node->character;
            node = root;
        }
    }
    return decoded;
}


int main() {
    string text = "";
    cout<<"\nEnter Input String : ";
    cin >> text ;
    HuffmanNode* root = buildHuffmanTree(text);
    unordered_map<char, string> codes;
    generateCodes(root, "", codes);
    string encoded = encode(text, codes);
    string decoded = decode(encoded, root);
    cout << "\nOriginal text: " << text << endl;
    cout << "Encoded text: " << encoded << endl;
    cout << "Decoded text: " << decoded << endl;
    return 0;
}


/*

	Time Complexity Analysis : 
	
	Counting the frequency of each character in the text takes O(n) time, 
	where n is the length of the text.
	
	Building a priority queue of nodes takes O(k log k) time, 
	where k is the number of distinct characters in the text.
	
	Building the Huffman tree by repeatedly combining the two nodes with the 
	smallest frequency takes O(k log k) time.
	
	Generating codes for each character by traversing the Huffman 
	tree takes O(k) time.
	
	Encoding the text using the codes takes O(n) time.
	
	Decoding the encoded text using the Huffman tree takes O(n log k) 
	time in the worst case, where each code has length log k and 
	there are n codes to decode.
	
	Therefore, the overall time complexity of the Huffman tree algorithm 
	is O(n log k) in the worst case. 

*/
