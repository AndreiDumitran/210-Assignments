#include<iostream>
#include<fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int adjMatrix[20][20]{ 0 },
	visited[20]{ 0 },
	queue[20]{ 0 },
	nodes, queueDimension;

void DFS(int start) {
	cout << start << " ";
	visited[start] = 1;

	//For every unvisited neighbour the function is recalled and marks the node as visited.
	for (int j = 1; j < nodes + 1; j++) {
		if (adjMatrix[start][j] == 1 && visited[j] == 0) {
			DFS(j);
		}
	}
}

void BFS(int i) {
	for (int j = 1; j < nodes + 1; j++) {
		//if is adjacent and not visited, it's added to the queue and becomes visited
		if ((adjMatrix[queue[i]][j] == 1) && (visited[j] == 0)) {
			queueDimension += 1;
			queue[queueDimension] = j;
			visited[j] = 1;
		}
	}
	if (i < queueDimension)
		BFS(i + 1);
}

int main() {
	int startNode;

	cout << "Enter how many nodes:";
	cin >> nodes;

	for (int i = 1; i < nodes + 1; i++) {
		for (int j = i + 1; j < nodes + 1; j++) {
			cout << "Is connection between nodes " << i << " and " << j << " ? ";
			cin >> adjMatrix[i][j];
			adjMatrix[j][i] = adjMatrix[i][j];
		}
	}

	//for (int i = 1; i < nodes + 1; i++) {
	//	for (int j = 1; j < nodes + 1; j++) {
	//		cout << adjMatrix[i][j] << " ";
	//	}
	//	cout << '\n';
	//}
	
	//making sure the visited array is empty.
	for (int i = 0; i < nodes + 1; i++) {
		visited[i] = 0;
	}

	cout << "Enter the start node:";
	cin >> startNode;

	cout << "Depth First Search:" << '\n';
	DFS(startNode);


	cout << '\n';


	//reset the visited array.
	for (int i = 0; i < nodes + 1; i++) {
		visited[i] = 0;
	}

	visited[startNode] = 1;
	queue[1] = startNode;
	queueDimension = 1;

	//Call of the function for a visited node.
	BFS(1);

	cout << "Breadth first search:" << '\n';
	for (int i = 1; i < nodes + 1; i++) {
		cout << queue[i] << " ";
	}

	cout << '\n';
	system("pause");
	return 0;
}