/*Code modified from
	title: BST Deletition.
	Author: mycodeschool
	Aviability: https://gist.github.com/mycodeschool
*/

#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

vector <string> paragraph{};

struct node{
	string data;
	node *left, *right;
};

//function to insert node in a binary tree
node* Insert(node *root, string data) {
	if (root == NULL) {
		root = new node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if (data <= root->data) {
		root->left = Insert(root->left, data);
	}
	else {
		root->right = Insert(root->right, data);
	}

	return root;
}

//function to visit nodes in pre order
void Preorder(struct node *root) {
	if (root == NULL)
		return;

	fout << root->data << " ";
	Preorder(root->left);
	Preorder(root->right);
}

//function to read the paragraph from file
void ReadParagraph() {
	string words{};

	while (fin >> words) {
		paragraph.push_back(words);
	}

	fin.close();
}

// Function for Binary Search Tree
 bool Search(node *root, string data) {
	 // output the path
	fout << root->data << " ";

	if (root->data == data)
		return true;
	else if (root == NULL)
		return false;

	if (root->data > data){
		if (root->left != NULL)
			return Search(root->left, data);
		else
			return false;
	}
	else if (root->data < data){
		if (root->right != NULL)
			return Search(root->right, data);
		else
			return false;
	}
}


int main() {
	node* root{ NULL };

	vector<string> insertionVector{ "rush","just","disarm","hurt","love","even","actor","need","unnatural","suspend","bat","no","drink","sugar","stuff","depend","difficult", "yes", "say", "fox", "dog", "quick"};

	for (auto insert : insertionVector) {
		root = Insert(root, insert);
	}

	fout << "Preorder: " <<'\n';
	Preorder(root);

	fout << '\n';

	ReadParagraph();

	fout << "The frequency of words: " << '\n';
	for (auto word : paragraph) {
		if (Search(root, word))
		{
			fout << '\t';
			fout << "Yes" << '\n';
		}
		else
		{
			fout << '\t';
			fout << "No" << '\n';
		}
	}

	cout << '\n';
	system("pause");
	return 0;
}