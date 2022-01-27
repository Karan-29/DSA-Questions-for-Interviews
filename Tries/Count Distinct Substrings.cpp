/*
Problem Statement
Ninja developed a love for arrays and strings so this time his teacher gave 
him an array of strings, ‘A’ of size ‘N’. Each element of this array is a string
.The teacher taught Ninja about prefixes in the past, so he wants to test his knowledge.
A string is called a complete string if every prefix of this string is also 
present in the array ‘A’. Ninja is challenged to find the longest complete 
string in the array ‘A’.If there are multiple strings with the same length, 
return the lexicographically smallest one and if no string exists, return "None".

Sample Input 1 :
2
6
n ni nin ninj ninja ninga
2
ab bc
Sample Output 1 :
ninja
None
Explanation Of Sample Input 1 :
For test case 1 we have, 

All the prefixes of “ninja” -> “n”, “ni”, “nin”, “ninj” and “ninja” are present in array ‘A’. So, “ninja” is a valid answer whereas for “ninga” , the prefix “ning” is not present in array ‘A’.

So we output “ninja”.

For test case 2 we have, 

The prefixes of “ab” are “a” and “ab”. “a” is not present in array ‘A’. So, “ab” is not a valid answer.

The prefixes of “bc” are “b” and “bc”. “b” is not present in array ‘A’. So, “ab” is not a valid answer.

Since none of the strings is a valid answer we output “None”.

*/

// TC - O(n*len)

struct Node {
    Node *links[26]; 
    bool flag = false; 
    
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL); 
    }
    Node* get(char ch) {
        return links[ch-'a']; 
    }
    void put(char ch, Node* node) {
        links[ch-'a'] = node; 
    }
    void setEnd() {
        flag = true; 
    }
    bool isEnd() {
        return flag; 
    }
}; 
class Trie {
    private: Node *root; 
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node(); 
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *node = root;
        for(int i = 0;i<word.size();i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node()); 
            }
            node = node->get(word[i]); 
        }
        node->setEnd(); 
    }
    bool checkIfAllPrefixExists(string word) {
        Node *node = root;
        bool flag = true; 
        for(int i = 0;i<word.size();i++) {
            if(node->containsKey(word[i])) {
                node = node->get(word[i]); 
                flag = flag & node->isEnd(); 
            }
            else {
                return false; 
            } 
        }
        return flag; 
    }
};
string completeString(int n, vector<string> &a){
    Trie* obj = new Trie();
    for(auto word : a) obj->insert(word); 
    string longest = ""; 
    for(auto word: a) {
        if(obj->checkIfAllPrefixExists(word)) {
            if(word.size() > longest.size()) {
                longest = word; 
            }
            else if(word.size() == longest.size() && word < longest) {
                longest = word; 
            }
        }
    }
    if(longest == "") return "None"; 
    return longest; 
}