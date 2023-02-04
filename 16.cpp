//top k frequent elements
#include <bits/stdc++.h>
using namespace std;

struct compare {
	bool operator()(pair<int, int> p1, pair<int, int> p2)
	{
		if (p1.second == p2.second)
			return p1.first < p2.first;

		return p1.second < p2.second;
	}
};

void print_N_mostFrequentNumber(int arr[], int N, int K)
{
	
	unordered_map<int, int> mp;
	for (int i = 0; i < N; i++)
		mp[arr[i]]++;

	
	priority_queue<pair<int, int>, vector<pair<int, int> >,
				compare>
		pq(mp.begin(), mp.end());

	cout << K << " numbers with most occurrences are:\n";
	for (int i = 1; i <= K; i++) {
		cout << pq.top().first << " ";
		pq.pop();
	}
}

int main()
{
	int arr[] = { 3, 1, 4, 4, 5, 2, 6, 1 };
	int N = sizeof(arr) / sizeof(arr[0]);
	int K = 2;

	print_N_mostFrequentNumber(arr, N, K);
	return 0;
}
