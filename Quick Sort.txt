#include <iostream>
using namespace std;
#define pb push_back
#define mk make_pair
#define fop first
#define sop second
#define ll long long int
#define vi vector<ll>
#define vs vector<string>
#define print(a) cout << a

#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define test(string,a) cout<<string<<a

#define FEI(el,s) for(int el : s)
#define FOR(index,a,n) for (int index = a; index < n; index++)
#define FORD(index,a,n) for (ll index = a; index >= n; index--)
#define NL cout<<"\n"
#define TAB '\t'

int partition(int a[], int low, int high){
	int pivot = a[high];
	int i = low - 1;
	FOR(j,low,high){
		if ( a[j] <= pivot ) {
			i++;
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			//swap(a[i],a[j]);
		}
	}
	int temp = a[i+1];
	a[i+1] = a[high];
	a[high] = temp;

	//swap(a[i+1],a[high]);
	return i+1;
}
void quicksort(int a[], int low, int high) {
	if ( low < high ) {
		int pivot = partition(a, low, high);
		quicksort(a,low,pivot-1);
		quicksort(a,pivot+1,high);
	}
}
int main() {
	int t,n; cin >> t;
	while(t--) {
		cin >> n;
		int a[n];
		FOR(i,0,n) {
			cin >> a[i];
		}
		quicksort(a,0,n-1);
		FEI(el,a)
			print(el)<<TAB;
	}
}
