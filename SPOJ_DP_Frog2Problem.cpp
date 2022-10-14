#include<bits/stdc++.h>
// #define int long long
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop for(int i = 0; i < n; i++)
using namespace std;
const int N = 1e5;
 
int countDigit(long long n){
return floor(log10(n) + 1);
}
int dp[N];
//-----------------------------------------------------------------------------
int a[N];
int frog(int i, int k){
    if(i==0) return 0;
    int cost = INT_MAX;

    if(dp[i] != -1) return dp[i];

    //k ways
    // int temp = k;
    // while(temp--){
    //     if(i > temp) cost = min(cost, frog(i-temp, k) + abs(a[i]-a[i-temp]));
    // }

    //last
    for(int j = 1; j <= k; j++){
        if(i-j>=0) cost = min(cost, frog(i-j, k) + abs(a[i]-a[i-j]));
    }

    // //way 1
    // cost = min(cost, frog(i-1) + abs(a[i]-a[i-1]));

    // //way 2
    // if(i>1)
    // cost = min(cost, frog(i-2)+abs(a[i]-a[i-2]));

    return (dp[i] = cost);
}

void solve(){
    memset(dp, -1, sizeof(dp));
    int n, k; cin >> n >> k;
    
    for(int i = 0; i < n; i++){
       cin >> a[i];         
    }
    int ans = frog(n-1, k);
    cout << ans << endl;
}
//----------------------------------------------------------------------------
int32_t main(){

      solve();
   return 0;
}

//name - MEHAK GUPTA
//email - mehakmg542@gmail.com
