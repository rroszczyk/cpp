#include <iostream>
#include <cstring>

using namespace std;

enum Arrow
{
	leftAr,
	upAr,
	upLeftAr,
	none
};

typedef struct cell
{
	int value = 0;
	Arrow arrow = none;
} tCell;

void validateInput(const char *topStr, const char *leftStr);

cell **createAndInitMatrix(int leftLen, int topLen);

void fillMatrix(cell **matrix, const char *topStr, const char *leftStr);

char *findLcs(cell **matrix, const char *topStr, const char *leftStr);

void free(cell **matrix, int rows);

int main(int argc, char *argv[])
{

	const char *topStr;
	const char *leftStr;
	int topLen;
	int leftLen;
	int rows;
	cell **matrix;
	char *result;

	topStr = (argc >= 2) ? argv[1] : "często_z_odkrywaniem";
	leftStr = (argc == 3) ? argv[2] : "rzeczy_nie_trzeba\n_się_spieszyć";
	validateInput(topStr, leftStr);

	topLen = strlen(topStr);
	leftLen = strlen(leftStr);
	rows = leftLen + 1;

	matrix = createAndInitMatrix(leftLen, topLen);
	fillMatrix(matrix, topStr, leftStr);
	result = findLcs(matrix, topStr, leftStr);

	cout << "Result LCS: " << result << endl;

	free(matrix, rows);
	delete[] result;

	return 0;
}

void validateInput(const char *topStr, const char *leftStr)
{
	if (topStr == NULL || strlen(topStr) <= 0)
	{
		cerr << "Input topStr cannot be empty or null!\n";
	}
	if (leftStr == NULL || strlen(leftStr) <= 0)
	{
		cerr << "Input leftStr cannot be empty or null!\n";
	}
}

cell **createAndInitMatrix(int leftLen, int topLen)
{
	int rows = leftLen + 1;
	int cols = topLen + 1;
	cell **matrix = new cell *[rows];

	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new cell[cols];
	}

	for (int i = 0; i < rows; i++)
	{
		matrix[i][0].value = 0;
	}

	for (int i = 0; i < cols; i++)
	{
		matrix[0][i].value = 0;
	}

	return matrix;
}

void fillMatrix(cell **matrix, const char *topStr, const char *leftStr)
{
	int rows = strlen(leftStr) + 1;
	int cols = strlen(topStr) + 1;

	for (int i = 1; i < rows; i++)
	{
		for (int j = 1; j < cols; j++)
		{
			if (topStr[j - 1] == leftStr[i - 1])
			{
				matrix[i][j].value = matrix[i - 1][j - 1].value + 1;
				matrix[i][j].arrow = upLeftAr;
			}
			else if (matrix[i - 1][j].value >= matrix[i][j - 1].value)
			{
				matrix[i][j].value = matrix[i - 1][j].value;
				matrix[i][j].arrow = upAr;
			}
			else
			{
				matrix[i][j].value = matrix[i][j - 1].value;
				matrix[i][j].arrow = leftAr;
			}
		}
	}
}

char *findLcs(cell **matrix, const char *topStr, const char *leftStr)
{
	int rows = strlen(leftStr) + 1;
	int cols = strlen(topStr) + 1;
	int maxLen = matrix[rows - 1][cols - 1].value;
	char *result = new char[maxLen + 1];
	int resultIndex = maxLen - 1;

	int i = rows - 1;
	int j = cols - 1;

	while (i >= 1 && j >= 1)
	{
		if (matrix[i][j].arrow == upLeftAr)
		{
			result[resultIndex] = topStr[j - 1];
			i--;
			j--;
			resultIndex--;
		}
		else if (matrix[i][j].arrow == upAr)
		{
			i--;
		}
		else if (matrix[i][j].arrow == leftAr)
		{
			j--;
		}
		else
		{
			cout << "Something goes wrong :( ...\n";
			exit(-1);
		}
	}
	result[maxLen] = '\0';

	return result;
}

void free(cell **matrix, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}
