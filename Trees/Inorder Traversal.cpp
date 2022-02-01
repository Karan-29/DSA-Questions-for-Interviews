/*
Given a binary tree, return the inorder traversal of its elements.

Sample Input
5
12
1 2 3 4 5 6 -1 -1 -1 7 -1 8
7
1 2 -1 4 -1 5 6
7
8 -1 9 -1 10 11 12
5
28 14 11 -1 48
1
6
Expected Output
4 2 7 5 1 8 6 3
5 4 6 2 1
8 9 11 10 12
14 48 28 11
6

*/

// Recursive:-

void inorder(Node *root, vector<int> &ans){
    if(!root) return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

vector<int> getInorderTraversal(Node* root) {
    // add your logic here
    vector<int> ans;
    inorder(root, ans);
    return ans;
}

// Iterative

vector<int> inOrder(struct Node *root)
{
    stack<Node *> s;
    vector<int> ans;
    Node *curr = root;
 
    while (true)
    {
        if(curr !=  NULL)
        {
            s.push(curr);
            curr = curr->left;
        } else {
            if(s.empty()) break;
            curr = s.top();
            s.pop();
            ans.push_back(curr->data);
            curr = curr->right;
        }
    } 
    return ans;
}