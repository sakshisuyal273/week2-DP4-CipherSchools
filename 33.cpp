// knapsack problem

#include <bits/stdc++.h>
using namespace std;
int knapSack(int W, int wt[], int val[], int n)
{
	int dp[W + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i < n + 1; i++) {
		for (int w = W; w >= 0; w--) {

			if (wt[i - 1] <= w)
				
				dp[w] = max(dp[w],dp[w - wt[i - 1]] + val[i - 1]);
		}
	}
	return dp[W]; 
}

int main()
{
	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(val) / sizeof(val[0]);
	cout << knapSack(W, wt, val, n);
	return 0;
}





//longest palindrome subsequence


#include<stdio.h>
#include<string.h>

int max (int x, int y) { return (x > y)? x : y; }

int lps(char *str)
{
int n = strlen(str);
int i, j, cl;
int L[n][n]; 


for (i = 0; i < n; i++)
	L[i][i] = 1;

	
	for (cl=2; cl<=n; cl++)
	{
		for (i=0; i<n-cl+1; i++)
		{
			j = i+cl-1;
			if (str[i] == str[j] && cl == 2)
			L[i][j] = 2;
			else if (str[i] == str[j])
			L[i][j] = L[i+1][j-1] + 2;
			else
			L[i][j] = max(L[i][j-1], L[i+1][j]);
		}
	}

	return L[0][n-1];
}

int main()
{
	char seq[] = "GEEKSFORGEEKS";
	int n = strlen(seq);
	printf ("The length of the LPS is %d", lps(seq));
	getchar();
	return 0;
}
