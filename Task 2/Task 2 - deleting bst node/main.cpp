#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

ifstream fin("data.txt");
ofstream fout("data.txt");

struct node {
	string data;
	struct node *left, *right;
};
//Function to find minimum in a tree. 
node* FindMin(node* root)
{
	while (root->left != NULL) root = root->left;
	return root;
}

// Function to search a delete a value from tree.
struct node* Delete(struct node *root, string data) {
	if (root == NULL) return root;
	else if (data < root->data) root->left = Delete(root->left, data);
	else if (data > root->data) root->right = Delete(root->right, data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		//Case 2: One child 
		else if (root->left == NULL) {
			struct node *temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL) {
			struct node *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else {
			struct node *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	return root;
}

//Function to visit nodes in Inorder
void Inorder(node *root) {
	if (root == NULL) return;

	Inorder(root->left);       //Visit left subtree
	cout<<(root->data) << " ";  //Print data
	Inorder(root->right);      // Visit right subtree
}

// Function to Insert Node in a Binary Search Tree
node* Insert(node *root, string data) {
	if (root == NULL) {
		root = new node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if (data <= root->data)
		root->left = Insert(root->left, data);
	else
		root->right = Insert(root->right, data);
	return root;
}

int main() {

	node* root = NULL;
	vector<string> wordsInBST{ "rush","just","disarm","hurt","love","even","actor","need","unnatural","suspend","bat","no","drink","sugar","stuff","depend","difficult","arranging" };
	for (auto word : wordsInBST) {
		root = Insert(root, word);
	}
	cout << "Printing the tree before removing a node:" << '\n';
	Inorder(root);
	
	cout << '\n' << '\n';


	// Deleting node with value 5, change this value to test other cases
	root = Delete(root, "just");
	cout << "Printing the tree after the node has been removed:" << '\n';
	Inorder(root);
	cout << "\n";
	system("pause");
}