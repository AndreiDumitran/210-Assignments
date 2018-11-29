#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

int adjMatrix[10][10]{}, vertex, vertexStart, vertexEnd, queue[10]{}, visited[10]{};

ifstream fin("input.txt");
ofstream fout("output.txt");

void IsPath(int start, int finish) {
	int first, last, currentElement;
	if (start > finish) {
		int temp = start;
		start = finish;
		finish = temp;
	}
	visited[start] = 1;
	queue[1] = start;
	first = 1;
	last = 1;

	while (first <= last) {
		currentElement = queue[first];
		for (int j = 1; j <= vertex + 1; j++) {
			if (adjMatrix[currentElement][j] == 1 && visited[j] == 0) {
				last += 1;
				queue[last] = j;
				visited[j] = 1;
			}
		}
		first++;
	}
	for (int i = 1; i < last + 1; i++) {
		i = start;
		if(i != finish)
			cout << queue[i]<< " ";
		else break;
	}
	
}

int main() {
	fin >> vertex;

	for (int i = 1; i < vertex + 1; i++) {
		for (int j = i + 1; j < vertex + 1; j++) {
			//cout << "Is connection between vertex " << i << " and " << j << " ? ";
			fin >> adjMatrix[i][j];
			adjMatrix[j][i] = adjMatrix[i][j];
		}
	}

	fin >> vertexStart >> vertexEnd;

	IsPath(vertexStart, vertexEnd);

	for (int i = 1; i < vertex + 1; i++) {
		for (int j = 1; j < vertex + 1; j++) {
			fout<< adjMatrix[i][j] << " ";
		}
		fout << '\n';
	}

	cout << '\n';
	system("pause");
	return 0;
}