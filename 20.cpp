//level order traversal

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        queue<TreeNode*> q;
        if(root==NULL) return v;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int size = q.size();
            for(int i=0; i<size; i++ ) {
                TreeNode * node = q.front();
                q.pop();
                if(node->left != NULL) {
                    q.push(node->left);
                }
                if(node->right != NULL) {
                    q.push(node->right);
                }
                level.push_back(node->val);
            }
            v.push_back(level);
        }
        return v;
    }
};










//level order using queue



#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

void printLevelOrder(Node* root)
{
	if (root == NULL)
		return;

	queue<Node*> q;

	q.push(root);

	while (q.empty() == false) {
		Node* node = q.front();
		cout << node->data << " ";
		q.pop();

		if (node->left != NULL)
			q.push(node->left);

		if (node->right != NULL)
			q.push(node->right);
	}
}

Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "Level Order traversal of binary tree is \n";
	printLevelOrder(root);
	return 0;
}













///diameter of binary tree

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        check(root);
        return maxm;
    }
    
    int check(TreeNode* node){
        if(node==NULL) return 0;
        int l = check(node->left);
        int r = check(node->right);
        maxm = max(maxm, l+r);
        return 1+max(l,r);
    }
    private:
    int maxm=0;
};