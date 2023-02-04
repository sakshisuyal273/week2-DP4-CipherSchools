//Serialize & Deserialize

class Codec {
public:

    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }

private:

    void serialize(TreeNode* root, ostringstream& out) {
        if (root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "# ";
        }
    }

    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;
        if (val == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};







//root to leaf paths

vector<vector<int>>vv;

void ff(Node* root,vector<int>v)
{
    if(!root) return;
    
    v.push_back(root->data);
    
    if(!root->left && !root->right)
    {
        vv.push_back(v);
    }
    
    ff(root->left,v);
    ff(root->right,v);
}
 
vector<vector<int>> Paths(Node* root)
{
    vector<int>v;
    vv.clear();
    ff(root,v);
    return vv;
}







//ancestors of binary tree


public class Node
{
	public int data;
	public Node left, right, nextRight;

	public Node(int item)
	{
		data = item;
		left = right = nextRight = null;
	}
}

public class BinaryTree
{
	public Node root;

	public virtual bool printAncestors(Node node, int target)
	{
		
		if (node == null)
		{
			return false;
		}

		if (node.data == target)
		{
			return true;
		}

		
		if (printAncestors(node.left, target)
		|| printAncestors(node.right, target))
		{
			Console.Write(node.data + " ");
			return true;
		}

		return false;
	}

	public static void Main(string[] args)
	{
		BinaryTree tree = new BinaryTree();

		
		tree.root = new Node(1);
		tree.root.left = new Node(2);
		tree.root.right = new Node(3);
		tree.root.left.left = new Node(4);
		tree.root.left.right = new Node(5);
		tree.root.left.left.left = new Node(7);

		tree.printAncestors(tree.root, 7);

	}
}




//find lowest common ancestor of binary tree


TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL || root == p || root == q)
        return root;

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (left == NULL)
        return right;

    if (right == NULL)
        return left;

    else
        return root;
}




//Convert Binary Tree to Doubly Linked list



public class Node
{
	public int data;
	public Node left, right;

	public Node(int data)
	{
		this.data = data;
		left = right = null;
	}
}

class GFG
{
public Node root;


public Node head;


public static Node prev = null;

public virtual void BinaryTree2DoubleLinkedList(Node root)
{
	
	if (root == null)
	{
		return;
	}

	
	BinaryTree2DoubleLinkedList(root.left);

	if (prev == null)
	{
		head = root;
	}
	else
	{
		root.left = prev;
		prev.right = root;
	}
	prev = root;

	BinaryTree2DoubleLinkedList(root.right);
}


public virtual void printList(Node node)
{
	while (node != null)
	{
		Console.Write(node.data + " ");
		node = node.right;
	}
}


public static void Main(string[] args)
{
	
	GFG tree = new GFG();
	tree.root = new Node(10);
	tree.root.left = new Node(12);
	tree.root.right = new Node(15);
	tree.root.left.left = new Node(25);
	tree.root.left.right = new Node(30);
	tree.root.right.left = new Node(36);

	tree.BinaryTree2DoubleLinkedList(tree.root);

	tree.printList(tree.head);

}
}
