#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>
#include <chrono> 
using namespace std;
using namespace std::chrono; 

vector<vector<int>> create(int size, int offset){
	int i, j;
	vector<vector<int>> matrix(size, vector<int>(size));
	srand (time(NULL) +offset);	

	for(i = 0; i < size; ++i){
		for(j = 0; j < size; ++j){
			matrix[i][j] = (rand() % 100 + 1);
		}
	}
	return matrix;
}

vector<vector<int>> multiply(vector<vector<int>> matrix1, vector<vector<int>> matrix2, int size){
	int i, j, k;
	vector<vector<int>> res(size, vector<int>(size));
	for(i = 0; i < size; ++i){
		for(j = 0; j < size; ++j){
			for(k = 0; k < size; ++k){
				res[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
	return res;
}

void display(vector<vector<int>> matrix, int size){
	int i, j;
	for(i = 0; i < size; ++i){
		for(j = 0; j < size; ++j){
			cout << matrix[i][j] << " ";
			if(j == size - 1){
				cout << endl;
			}
		}
	}
}

int main(){
	int size;
	cout << "Enter the size of two square matrices: ";
	cin >> size;
	cout << endl;

	// create two matrices with random numbers and calculate exe time
	auto start = high_resolution_clock::now(); 
	vector<vector<int>> matrix1 = create(size, 1);
	vector<vector<int>> matrix2 = create(size, 2);
	vector<vector<int>> res = multiply(matrix1, matrix2, size);
	auto stop = high_resolution_clock::now(); 
	auto duration = duration_cast<microseconds>(stop - start);

	// display matrices and execution time
	cout << "Matrix1: " << endl;
	display(matrix1, size);
	cout << endl;
	cout << "Matrix2: " << endl;
	display(matrix2, size);
	cout << endl;
	cout << "Multiple of M1 and M2: " << endl;
	display(res, size);
	cout << endl;
	cout << "Execution time: " << duration.count() << endl;
	printf ("\n");
	return 0;
}
