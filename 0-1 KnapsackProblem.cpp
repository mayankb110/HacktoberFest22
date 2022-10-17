#include <bits/stdc++.h>
using namespace std;
int knapSack(int W, int wt[], int v[], int n)
{
    int i, w;
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));

    // Building  table dp[][] in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(v[i - 1] +
                                   dp[i - 1][w - wt[i - 1]],
                               dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}
//Time complexity - O(n*W)
//Space complexity - O(n*W)

int main()
{
    // number of items
    int n;
    cin >> n;
    // value of each item
    int v[n];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // weight of each item
    int wt[n];
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    // Weight of knapsack
    int W;
    cin >> W;

    cout<<knapSack(W,wt,v,n);
    return 0;
}
