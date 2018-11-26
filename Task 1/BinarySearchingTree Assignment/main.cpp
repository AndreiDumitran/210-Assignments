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

	cout << root->data << '\n';
	Preorder(root->left);
	Preorder(root->right);
}

bool HasPath(struct node *root, vector <string> &path, string toThePath) {
	if (root == NULL)
		return false;

	path.push_back(root->data);
	if (root->data == toThePath)
		return true;

	if (HasPath(root->left, path, toThePath) || HasPath(root->right, path, toThePath)) {
		return true;
	}
	return false;
}

void PrintPath(node *root, string word) {
	vector<string> path;

	if (HasPath(root, path, word)) {
		for (int i = 0; i < path.size() - 1; i++) {
			cout << path[i] << "->";
		}
		cout << path[path.size() - 1];
	}
	else {
		for (int i = 0; i < path.size() - 1; i++) {
			cout << path[i] << "->";
		}
		cout << path[path.size() - 1];
	}
}

//function to read the paragraph from file
void ReadParagraph() {
	string words{};

	while (fin >> words) {
		paragraph.push_back(words);
	}

	fin.close();
}

 bool Search(node *root, string data) {
	if (root == NULL)
		return false;

	else if (root->data == data) {
		return true;
	}
		
	else if (data <= root->data)
		return Search(root->left, data);
	else
		return Search(root->right, data);
}


int main() {
	node* root{ NULL };

	root = Insert(root, "rush"); root = Insert(root, "veil"); root = Insert(root, "disarm");
	root = Insert(root, "hurt"); root = Insert(root, "love"); root = Insert(root, "deeply");

	root = Insert(root, "even"); root = Insert(root, "actor"); root = Insert(root, "need");
	root = Insert(root, "unnatural"); root = Insert(root, "suspend"); root = Insert(root, "bat");

	root = Insert(root, "no"); root = Insert(root, "drink"); root = Insert(root, "sugar");
	root = Insert(root, "stuff"); root = Insert(root, "depend"); root = Insert(root, "difficult");

	//printing the nodes in pre order. 
	cout << "Preorder: " <<'\n';
	Preorder(root);

	cout << '\n';

	ReadParagraph();

	cout << "The frequency of words: " << '\n' << '\n';
	for (auto word : paragraph) {
		if (Search(root, word))
		{
			PrintPath(root, word);
			cout << '\t';
			cout << "Yes" << '\n';
		}
		else
		{
			PrintPath(root, word);
			cout << '\t' << '\t';
			cout << "No" << '\n';
		}
	}


	cout << '\n';
	system("pause");
	return 0;
}