#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

int adjMatrix[10][10]{}, vertex, vertexStart, vertexEnd;
vector<int> queue{};

ifstream fin("input.txt");
ofstream fout("output.txt");

void IsPath(int v, int w) {
	if (v > w) {
		int temp = v;
		v = w;
		w = temp;
	}
	for (int i = v; i < v + 1; i++) {
		for (int j = i + 1; j < vertex + 1; j++) {
			
		}
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

	//for (int i = 1; i < vertex + 1; i++) {
	//	for (int j = 1; j < vertex + 1; j++) {
	//		fout<< adjMatrix[i][j] << " ";
	//	}
	//	fout << '\n';
	//}

	cout << '\n';
	system("pause");
	return 0;
}