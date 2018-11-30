#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector<vector<int>> adjMatrix{ 0 };
vector<int> visited{ 0 };
vector<int> q{ 0 };
int nodes;

void InitialisationMatrix() {
	for (int i = 1; i <= nodes; i++) {
		vector <int> temp;
		for (int j = 1; j <= nodes; j++) {
			temp.push_back(0);
		}
		adjMatrix.push_back(temp);
	}
	for (int i = 0; i < nodes; i++) {
		visited.push_back(0);
	}
}

void InitialisationVisited() {
	for (int i = 0; i < nodes; i++) {
		visited[i] = 0;
	}
}

void Read() {
	for (int i = 0; i < nodes; i++) {
		for (int j = i + 1; j < nodes; j++) {
			//cout << "Is an edge between " << i << " and " << j << " ? ";
			fin >> adjMatrix[i][j];
			adjMatrix[j][i] = adjMatrix[i][j];
		}
	}
}

void DFS(int start) {
	visited[start] = 1; // Marking the node as visited.
	cout << start << " ";
	for (int i = 0; i < nodes; i++) {
		/*If we have edge between the node and the node "i"
		and node "i" has not been visited we recall the function.*/
		if (adjMatrix[start][i] == 1 && visited[i] == 0)
			DFS(i);
	}
}

void BFS(int start) {
	int node, queueStart = 1, queueFinish = 1;
	visited[start] = 1; // marking the node as visited.
	q.push_back(start); //introducing the node in to the queue
	cout << start << " ";
	while (queueStart <= queueFinish) {
		node = q[queueStart];
		for (int i = 0; i < nodes; i++) {
			/* If we have edge between the node and the node "i" we increase the queue
			and we introduce the node to the queue.*/
			if (adjMatrix[node][i] == 1 && visited[i] == 0) {
				queueFinish++;
				q.push_back(i);
				cout << i << " ";
				visited[i] = 1; // Mark the node as visited.
			}
		}
		queueStart++;
	}
}

int main() {
	//cout << "Enter number of nodes: ";
	fin >> nodes;

	// Iunction to initialise the matrix with 0.
	InitialisationMatrix();

	// Initialising the visited vector with 0.
	InitialisationVisited();
	Read();

	int startNode;
	fin >> startNode;
	cout << "DFS" << '\n';
	DFS(startNode);

	cout << '\n';

	InitialisationVisited();
	cout << "BFS" << '\n';
	BFS(startNode);
	cout << '\n';
	system("pause");
	return 0;
}