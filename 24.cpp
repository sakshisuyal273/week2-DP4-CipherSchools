//convert sorted array to BST


public class Node
{

	public int data;
	public Node left, right;

	public Node(int d)
	{
		data = d;
		left = right = null;
	}
}

public class BinaryTree
{

	public static Node root;

	
	public virtual Node sortedArrayToBST(int[] arr, int start, int end)
	{

	
		if (start > end)
		{
			return null;
		}

		int mid = (start + end) / 2;
		Node node = new Node(arr[mid]);

		node.left = sortedArrayToBST(arr, start, mid - 1);

	 
		node.right = sortedArrayToBST(arr, mid + 1, end);

		return node;
	}

	public virtual void preOrder(Node node)
	{
		if (node == null)
		{
			return;
		}
		Console.Write(node.data + " ");
		preOrder(node.left);
		preOrder(node.right);
	}

	public static void Main(string[] args)
	{
		BinaryTree tree = new BinaryTree();
		int[] arr = new int[]{1, 2, 3, 4, 5, 6, 7};
		int n = arr.Length;
		root = tree.sortedArrayToBST(arr, 0, n - 1);
		Console.WriteLine("Preorder traversal of constructed BST");
		tree.preOrder(root);
	}
}







//Lowest Common Ancestor of a Binary Search Tree


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(root == NULL)
            return NULL;
        
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left , p , q);
        
        else if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right , p , q);
        
        else
            return root;
    }
};








//print BST in given range
public class Node
{

	public int data;
	public Node left, right;

	public Node(int d)
	{
		data = d;
		left = right = null;
	}
}

public class BinaryTree
{

	public static Node root;

	/* The functions prints all the keys which in the
	given range [k1..k2]. The function assumes than k1 < k2 */
	public virtual void Print(Node node, int k1, int k2)
	{

		/* base case */
		if (node == null)
		{
			return;
		}

		/* Since the desired o/p is sorted, recurse for left subtree first
		If root->data is greater than k1, then only we can get o/p keys
		in left subtree */
		if (k1 < node.data)
		{
			Print(node.left, k1, k2);
		}

		/* if root's data lies in range, then prints root's data */
		if (k1 <= node.data && k2 >= node.data)
		{
			Console.Write(node.data + " ");
		}

		/* recursively call the right subtree */
			Print(node.right, k1, k2);
	}

	public static void Main(string[] args)
	{
		BinaryTree tree = new BinaryTree();
		int k1 = 10, k2 = 25;
		BinaryTree.root = new Node(20);
		BinaryTree.root.left = new Node(8);
		BinaryTree.root.right = new Node(22);
		BinaryTree.root.left.left = new Node(4);
		BinaryTree.root.left.right = new Node(12);

		tree.Print(root, k1, k2);
	}
}

