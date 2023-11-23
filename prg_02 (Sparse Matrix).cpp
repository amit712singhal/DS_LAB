#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{

	int size = 0;

	int sparseMatrix[4][8] = {
		{0, 0, 0, 2, 0, 4, 0, 7},
		{0, 0, 0, 0, 0, 5, 1, 0},
		{0, 3, 0, 0, 0, 6, 7, 8},
		{1, 0, 0, 0, 0, 0, 1, 0}};

	cout << "Original Sparse_Matrix is -> " << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			printf("%d ", sparseMatrix[i][j]);
		}
		cout << endl;
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{

			if (sparseMatrix[i][j] != 0)
				size++;
		}
	}

	int compactMatrix[3][size];

	int k = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (sparseMatrix[i][j] != 0)
			{
				compactMatrix[0][k] = i + 1;
				compactMatrix[1][k] = j + 1;
				compactMatrix[2][k] = sparseMatrix[i][j];
				k++;
			}
		}
	}

	cout << "\nThe New Compacted_Matrix is ->\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%d ", compactMatrix[i][j]);
		}
		cout << endl;
	}

	return 0;
}
