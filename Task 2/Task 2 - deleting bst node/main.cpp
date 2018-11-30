/*Code modified from 
	title: BST Deletition.
	Author: mycodeschool
	Aviability: https://gist.github.com/mycodeschool
*/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct node {
	string data;
	struct node *left, *right;
};

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

//Function to find minimum in a tree. 
node* FindMin(node* root)
{
	while (root->left != NULL) 
		root = root->left;
	return root;
}

// Function for Binary Search Tree
bool Search(node *root, string data) {
	// output the path
	fout << root->data << " ";

	if (root->data == data)
		return true;
	else if (root == NULL)
		return false;

	if (root->data > data) {
		if (root->left != NULL)
			return Search(root->left, data);
		else
			return false;
	}
	else if (root->data < data) {
		if (root->right != NULL)
			return Search(root->right, data);
		else
			return false;
	}
}

// Function to delete a node from the BST
struct node* Delete(struct node *root, string data) {
	if (root == NULL) 
		return root;
	else if (data < root->data) 
		root->left = Delete(root->left, data);
	else if (data > root->data) 
		root->right = Delete(root->right, data);
	// The value has been found.	
	else {
		// Case where the node is a leaf
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		// Case where the node has only one child.
		// if the child is on the right side
		else if (root->left == NULL) {
			struct node *temp = root;
			root = root->right;
			delete temp;
		}
		// if the child is on the right side
		else if (root->right == NULL) {
			struct node *temp = root;
			root = root->left;
			delete temp;
		}
		// Case where the node has two children.
		else {
			//finding the minimum between the right nodes
			struct node *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	return root;
}

//Function to visit nodes in Inorder
void Preorder(struct node *root) {
	if (root == NULL)
		return;

	cout << root->data << " ";
	Preorder(root->left);
	Preorder(root->right);
}

int main() {

	node* root = NULL;
	vector<string> wordsInBST{ "rush","just","disarm","hurt","love","even","actor","need","unnatural","suspend","bat","no","drink","sugar","stuff","depend","difficult","arranging" };
	for (auto word : wordsInBST) {
		root = Insert(root, word);
	}
	cout << "Printing the BST before removing a node:" << '\n';
	Preorder(root);
	
	cout << '\n' << '\n';

	string nodeToBeDeleted;
	cout << "What node you want to delete? ";
	cin >> nodeToBeDeleted;

	cout << '\n';
	if (Search(root, nodeToBeDeleted)) {
		root = Delete(root, nodeToBeDeleted);
		cout << "Printing the BST after the node has been removed:" << '\n';
		Preorder(root);
	}
	else {
		cout << "The node is not in the tree.";
	}	

	cout << "\n" << "\n";
	system("pause");
}