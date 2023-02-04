//vertical order traversal

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	Node *left, *right;
};

struct Node* newNode(int key)
{
	struct Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return node;
}


vector<vector<int> > printVerticalOrder(Node* root)
{

	
	map<int, map<int, multiset<int> > > mpp;

	queue<pair<Node*, pair<int, int> > > q;

	q.push({ root, { 0, 0 } });

	while (!q.empty()) {
		auto p = q.front();
		q.pop();

		Node* temp = p.first;
		
		int vertical = p.second.first;
		int level = p.second.second;

		mpp[vertical][level].insert(temp->key);

		
		if (temp->left)
			q.push({ temp->left,
					{ vertical - 1,
					level + 1 } });

		
		if (temp->right)
			q.push({ temp->right,
					{ vertical + 1,
					level + 1 } });
	}

	vector<vector<int> > ans;

	for (auto p : mpp) {
		vector<int> col;
		for (auto q : p.second) {
			col.insert(col.end(),
					q.second.begin(),
					q.second.end());
		}
		ans.push_back(col);
	}
	return ans;
}

int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(11);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);
	root->right->right->right = newNode(9);

	vector<vector<int> > v =
		printVerticalOrder(root);

	for (auto i : v) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}




//right side view of binary tree


void rightSide(Node*root,vector<int>&ans,int level){
        if(root==NULL){
            return;
        }
        
        if(level==ans.size()){
            ans.push_back(root->data);
        }
        
        rightSide(root->right,ans,level+1);
        rightSide(root->left,ans,level+1);
     
    }
    
    vector<int> rightView(Node *root)
    {
       vector<int>ans;
   
       if(root==NULL){
           return ans;
       }
       
       rightSide(root,ans,0);
       
       return ans;
    }




    //left side view of bt


#include<bits/stdc++.h>
using namespace std;


struct Node
{
	int data;
	struct Node *left, *right;
};

Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}


void printLeftView(Node* root)
{
	if (!root)
		return;

	queue<Node*> q;
	q.push(root);

	while (!q.empty())
	{	
		int n = q.size();
		
		for(int i = 1; i <= n; i++)
		{
			Node* temp = q.front();
			q.pop();
				
			if (i == 1)
				cout<<temp->data<<" ";
			
			if (temp->left != NULL)
				q.push(temp->left);

			if (temp->right != NULL)
				q.push(temp->right);
		}
	}
}	


int main()
{


	Node* root = newNode(10);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(7);
	root->left->right = newNode(8);
	root->right->right = newNode(15);
	root->right->left = newNode(12);
	root->right->right->left = newNode(14);

	printLeftView(root);
}
