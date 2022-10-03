#include <iostream>
using namespace std;

int size = 0;

int parent(int i) { return ( (i-1)/2); }

int left(int i){ return (2 * i + 1); }

int right(int i){ return (2 * i + 2); }

void heapify(int heap[], int n, int i){
	int l = left(i), r = right(i), s = i;
	if( l < n && heap[l] < heap[s] ){
		s = l;
	}
	if( r < n && heap[r] < heap[s] ){
		s = r;
	}
	
	if( s != i ) {
		swap(heap[s],heap[i]);
		heapify(heap,n,s);
	}
}
void build_heap(int heap[], int n){
	for(int j = (n-1)/2; j >= 0; j--){
		heapify(heap,n,j);
	}
}

void heapSort(int heap[], int n){
	build_heap(heap, n);
	for (int i = n-1; i > 0; i--)
	{
		swap(heap[0],heap[i]);
		heapify(heap,i,0);
		
	}
	
}

int extractMin(int heap[]){
	int root = heap[0];
	heap[0] = heap[size-1];
	size -= 1;
	return root;
}

void decreaseKey(int heap[], int i,int val){
	heap[i] = val;
	while(i != 0 && heap[parent(i)] > heap[i] ){
		swap(heap[parent(i)], heap[i]);
		i = parent(i);
	}
}
int main()
{
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n];
		size = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			size++;
		}
		build_heap(a,n);
		cout << extractMin(a) << '\t';
		//decreaseKey(heap,
		for (int i = 0; i < size ; i++)
		{
			cout<<a[i]<<"\t";
		}
		cout << endl;
		
	}
}

