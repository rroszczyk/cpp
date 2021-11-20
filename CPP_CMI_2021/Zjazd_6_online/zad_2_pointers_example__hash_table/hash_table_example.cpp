#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct Node
{
	int value;
	struct Node *next = NULL;
} s_node;

void initHash(s_node **hashTab, int size);
void putManyRandomVAlues(s_node **hashTab, int size, int nOfRandomNums);
void put(s_node **hashTab, int size, int value);
void getAndPrint(s_node **hashTab, int size, int valueToFind);
s_node *get(s_node **hashTab, int size, int valueToFind);
void remove(s_node **hashTab, int size, int valueToRemove);
void free(s_node **hashTab, int size);
int hashId(int value, int m);
void print(s_node **hashTab, int size);
void printPart(s_node **hashTab, int size, int start, int end);

int main(int argc, char *argv[])
{
	int size = 701;
	int nOfRandomNums = 3000;
	int printStart, printEnd;
	int valueToFind;
	s_node **hashTab = new s_node *[size];
	//s_node** hashTab = (s_node**) malloc( size * sizeof(s_node*));

	if (hashTab == NULL)
	{
		exit(-1);
	}

	initHash(hashTab, size);

	put(hashTab, size, 13);
	putManyRandomVAlues(hashTab, size, nOfRandomNums);

	put(hashTab, size, 14);
	put(hashTab, size, 11);
	put(hashTab, size, (size + 11));
	put(hashTab, size, 11323);
	put(hashTab, size, 654123);

	printStart = 22;
	printEnd = 26;
	valueToFind = 13;

	getAndPrint(hashTab, size, valueToFind);
	printPart(hashTab, size, printStart, printEnd);

	remove(hashTab, size, valueToFind);

	getAndPrint(hashTab, size, valueToFind);
	printPart(hashTab, size, printStart, printEnd);
	//print(hashTab, size);

	free(hashTab, size);
	return 0;
}

void initHash(s_node **hashTab, int size)
{
	for (int i = 0; i < size; i++)
	{
		hashTab[i] = NULL;
	}
}

void putManyRandomVAlues(s_node **hashTab, int size, int nOfRandomNums)
{
	srand(time(NULL));
	int value;

	for (int i = 0; i < nOfRandomNums; i++)
	{
		value = rand();
		put(hashTab, size, value);
	}
}

void put(s_node **hashTab, int size, int value)
{
	int index = hashId(value, size);
	s_node *current = new s_node;

	if (current == NULL)
	{
		exit(-2);
	}

	current->value = value;
	current->next = hashTab[index];
	hashTab[index] = current;
}

void getAndPrint(s_node **hashTab, int size, int valueToFind)
{
	s_node *result = get(hashTab, size, valueToFind);
	int index = hashId(valueToFind, size);

	if (result != NULL)
	{
		printf("Value (%d) exist (index: %d)!\n", result->value, index);
	}
	else
	{
		printf("Value (%d) not found!\n", valueToFind);
	}
}

void remove(s_node **hashTab, int size, int valueToRemove)
{
	int index = hashId(valueToRemove, size);
	s_node *current = hashTab[index];
	s_node *prev = NULL;

	while (current != NULL && current->value != valueToRemove)
	{
		prev = current;
		current = current->next;
	}

	if (current != NULL)
	{
		if (prev != NULL)
		{
			prev->next = current->next;
		}
		else
		{
			hashTab[index] = current->next;
		}
		delete current;
	}
}

s_node *get(s_node **hashTab, int size, int valueToFind)
{
	int index = hashId(valueToFind, size);
	s_node *current = hashTab[index];

	while (current != NULL && current->value != valueToFind)
	{
		current = current->next;
	}

	return current;
}

int hashId(int value, int m)
{
	int hashId;
	double a = 0.6180339887498949; //(sqrt(5) - 1) / 2
	value = value < 0 ? -value : value;

	//hashId = value % m; // haszowanie modularne
	hashId = m * ((value * a) - (int)(value * a)); // haszowanie przez mnożenie

	return hashId;
}

void free(s_node **hashTab, int size)
{
	s_node *head, *node;

	for (int i = 0; i < size; i++)
	{
		head = hashTab[i];

		while (head != NULL)
		{
			node = head;
			head = head->next;
			delete node;
		}
	}
	delete[] hashTab;
}

void print(s_node **hashTab, int size)
{
	printPart(hashTab, size, 0, size);
}

void printPart(s_node **hashTab, int size, int start, int end)
{
	s_node *node;
	for (int i = start; i <= end && i < size; i++)
	{
		if (hashTab[i] != NULL)
		{
			printf("hashTab[%d]", i);
			node = hashTab[i];

			while (node != NULL)
			{
				printf(" -> val=%d ", node->value);
				node = node->next;
			}
			printf("\n");
		}
	}
	printf("\n");
}
