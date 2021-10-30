#include <iostream>

using namespace std;

int *alloc_counter();
int *alloc_heap(int *heap_size);
void push(int *heap, int *heap_size, int *n, int new_val);
int pop(int heap[], int *n);
void heap_up(int *heap, int *n);
void heap_down(int *heap, int *n);
void swap(int *heap, int first, int second);
int get_id_of_bigger_child_if_any(int *heap, int n, int parent_id);

int main(int argc, char *argv[])
{
	int heap_size = 10;
	int *n = alloc_counter();
	int *heap = alloc_heap(&heap_size);

	push(heap, &heap_size, n, 4);
	push(heap, &heap_size, n, 5);
	push(heap, &heap_size, n, 6);
	push(heap, &heap_size, n, 1);
	push(heap, &heap_size, n, 10);
	push(heap, &heap_size, n, 11);

	for (int i = 0; i < *n; i++)
	{
		cout << heap[i] << endl;
	}

	while (*n > 0)
	{
		cout << "pop = " << pop(heap, n) << " | ";
	}
	cout << endl;

	free(heap);
	free(n);
	return 0;
}

int *alloc_counter()
{
	int *n = (int *)calloc(1, sizeof(int));
	if (n == NULL)
	{
		cerr << "Cannot alloc memory for \"n\".\n";
		exit(-1);
	}
	return n;
}

int *alloc_heap(int *heap_size)
{
	int *heap = (int *)calloc(*heap_size, sizeof(int));
	if (heap == NULL)
	{
		cerr << "Cannot alloc memory for heap. \
			Null pointer has been returned.\n";
		exit(-2);
	}
	return heap;
}

void push(int *heap, int *heap_size, int *n, int new_val)
{
	if (*n >= *heap_size)
	{
		(*heap_size) *= 2;
		heap = (int *)realloc(heap, *heap_size);
		if (heap == NULL)
		{
			cerr << "Cannot re-allocate mem for heap!\n";
			return;
		}
	}

	heap[*n] = new_val;
	(*n)++;
	heap_up(heap, n);
}

int pop(int heap[], int *n)
{
	if (*n <= 0)
	{
		cerr << "Cannot pop any value! Heap is empty!\n";
		exit(-3);
	}

	int result = heap[0];
	(*n)--;
	heap[0] = heap[*n];
	heap_down(heap, n);

	return result;
}

void heap_up(int *heap, int *n)
{
	int child_id = *n; // Tutaj jest błąd, który należy poprawić.
					   // (Indeks dziecka powinien być równy
					   // indeksowi ostatniego elementu w tablicy, czyli: (*n - 1).)
	int parent_id = (child_id - 1) / 2;
	int tmp_val;

	while (parent_id >= 0 && heap[parent_id] < heap[child_id])
	{
		swap(heap, parent_id, child_id);
		child_id = parent_id;
		parent_id = (child_id - 1) / 2;
	}
}

void heap_down(int *heap, int *n)
{
	int parent_id = 0;
	int bigger_child_id = get_id_of_bigger_child_if_any(heap, *n, parent_id);

	while (heap[parent_id] < heap[bigger_child_id])
	{
		swap(heap, parent_id, bigger_child_id);
		parent_id = bigger_child_id;
		bigger_child_id = get_id_of_bigger_child_if_any(heap, *n, parent_id);
	}
}

void swap(int *heap, int first, int second)
{
	int tmp_val = heap[first];
	heap[first] = heap[second];
	heap[second] = tmp_val;
}

int get_id_of_bigger_child_if_any(int *heap, int n, int parent_id)
{
	int left_child_id = parent_id * 2 + 1;
	int right_child_id = parent_id * 2 + 2;
	int bigger_child_id;

	if (right_child_id < n)
	{
		if (heap[left_child_id] >= heap[right_child_id])
		{
			bigger_child_id = left_child_id;
		}
		else
		{
			bigger_child_id = right_child_id;
		}
	}
	else if (left_child_id < n)
	{
		bigger_child_id = left_child_id;
	}
	else
	{
		bigger_child_id = parent_id;
	}

	return bigger_child_id;
}
