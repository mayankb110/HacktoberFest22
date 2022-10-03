#include <bits/stdc++.h>
using namespace std;

#define TAB '\t'
#define pb push_back
#define vi vector<int>
#define vs vector<string>
#define print(a) cout << a
#define ll long long int
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define test(string,a) cout<<string<<a

#define FEI(el,s) for(int el : s)
#define FOR(index,a,n) for (int index = a; index < n; index++)

#define FORD(index,a,n) for (ll index = a; index >= n; index--)

#define NL cout<<"\n"

bool checkPalin(string s) {
	
	int n = (int)s.length();
	if ( n == 1 ) {
		return true;
	}else{
		int i = 0,j = n-1;
		while(i<j){
			if(s[i] != s[j]) return false;
			i++; j--;
		}
	}
	return true;
}

void recur(string s,vector<vs> result,vs temp){
		//test("s:",s)<<TAB;
		
		int n = (int)s.length();
		if(n <= 0 ){
			
			for(string t: temp){
				print(t)<<TAB;
			}
			NL;
			result.pb(temp);		
		
		}
		else{
			FOR(i,0,n) {
				string s3 = s.substr(0,i+1);
				
				//NL;
				if(checkPalin(s3)){
					temp.pb(s3);
					
						string s4 = s.substr(i+1,(n - i+1));
						recur(s4,result,temp);
						
					
					temp.erase(temp.begin()+temp.size());
					
				}
				//test("s3:",s3)<<TAB;
				
			}
		}
		
}


	
int main()
{
	//sync;
	int t; cin >> t; 
	while( t-- ) {
		string s;
		cin >> s;
		vector<vs> result;
		vs temp;
		//print(s);
		recur(s,result,temp);
		for(vs t: result){
			for(string p: t){
				print(p)<<TAB;
			}
			NL;
		}
	}
}
