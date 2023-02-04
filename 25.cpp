//balanced bst problem

class Solution {
public:
    void inorder(TreeNode* root , vector<int> &inorderVal){
        if(root == NULL)
            return ;
        
        inorder(root->left , inorderVal);
        inorderVal.push_back(root->val);
        inorder(root->right , inorderVal);
    }
    
    TreeNode* inorderToBST(int s , int e , vector<int> &inorderVal){
        if(s > e)
            return NULL;
        
        int mid = (s+e)/2;
        
        TreeNode* temp = new TreeNode(inorderVal[mid]);
        temp->left = inorderToBST(s , mid-1 , inorderVal);
        temp->right = inorderToBST(mid+1 , e , inorderVal);
        
        return temp;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorderVal;
        inorder(root , inorderVal);
        
        return inorderToBST(0 , inorderVal.size()-1 , inorderVal);
    }
};









// unique bst count problem
using System;

class BST {
	static int numberOfBST(int n)
	{

		
		int[] dp = new int[n + 1];

		
		dp[0] = 1;
		dp[1] = 1;

		
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= i; j++) {

				dp[i] = dp[i] + (dp[i - j] * dp[j - 1]);
			}
		}
		return dp[n];
	}

	public static void Main()
	{
		int n = 3;
		Console.Write("Number of structurally "	+ "Unique BST with " + n	+ " keys are : " + numberOfBST(n));
	}
}


