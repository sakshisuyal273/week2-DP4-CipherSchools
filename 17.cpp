#include <bits/stdc++.h>
using namespace std;


void printNSE(int arr[], int n)
{
	stack<pair<int, int> > s;
	vector<int> ans(n);

	for (int i = 0; i < n; i++) {
		int next = arr[i];

		if (s.empty()) {
			s.push({ next, i });
			continue;
		}

		
		while (!s.empty() && s.top().first > next) {
			ans[s.top().second] = next;
			s.pop();
		}


		s.push({ next, i });
	}


	while (!s.empty()) {
		ans[s.top().second] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ---> " << ans[i] << endl;
	}
}

int main()
{
	int arr[] = { 11, 13, 21, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printNSE(arr, n);
	return 0;
}








#include <bits/stdc++.h>

using namespace std;

void nextLargerElement(int arr[], int n)
{
	vector<unordered_map<string, int> > s;

	for (int i = 0; i < n; i++) {
		while (s.size() > 0
			&& s[s.size() - 1]["value"] < arr[i]) {
			unordered_map<string, int> d = s[s.size() - 1];
			s.pop_back();
			arr[d["ind"]] = arr[i];
		}
		unordered_map<string, int> e;

		e["value"] = arr[i];
		e["ind"] = i;
		s.push_back(e);
	}

	while (s.size() > 0) {
		unordered_map<string, int> d = s[s.size() - 1];
		s.pop_back();
		arr[d["ind"]] = -1;
	}
}



int main()
{
	int arr[] = { 6, 8, 0, 1, 3 };
	int n = 5;

	nextLargerElement(arr, n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}












#include <bits/stdc++.h>
using namespace std;

int max(int x, int y, int z)
{ return max(max(x, y), z); }

int minVal(int *hist, int i, int j)
{
	if (i == -1) return j;
	if (j == -1) return i;
	return (hist[i] < hist[j])? i : j;
}

int getMid(int s, int e)
{ return s + (e -s)/2; }


int RMQUtil(int *hist, int *st, int ss, int se, int qs, int qe, int index)
{
	if (qs <= ss && qe >= se)
		return st[index];

	if (se < qs || ss > qe)
		return -1;

	int mid = getMid(ss, se);
	return minVal(hist, RMQUtil(hist, st, ss, mid, qs, qe, 2*index+1),
				RMQUtil(hist, st, mid+1, se, qs, qe, 2*index+2));
}

int RMQ(int *hist, int *st, int n, int qs, int qe)
{
	if (qs < 0 || qe > n-1 || qs > qe)
	{
		cout << "Invalid Input";
		return -1;
	}

	return RMQUtil(hist, st, 0, n-1, qs, qe, 0);
}


int constructSTUtil(int hist[], int ss, int se, int *st, int si)
{
	
	if (ss == se)
	return (st[si] = ss);

	
	int mid = getMid(ss, se);
	st[si] = minVal(hist, constructSTUtil(hist, ss, mid, st, si*2+1),
					constructSTUtil(hist, mid+1, se, st, si*2+2));
	return st[si];
}


int *constructST(int hist[], int n)
{
	
	int x = (int)(ceil(log2(n))); 
	int max_size = 2*(int)pow(2, x) - 1; 
	int *st = new int[max_size];

	constructSTUtil(hist, 0, n-1, st, 0);

	return st;
}


int getMaxAreaRec(int *hist, int *st, int n, int l, int r)
{
	// Base cases
	if (l > r) return INT_MIN;
	if (l == r) return hist[l];

	
	int m = RMQ(hist, st, n, l, r);

	
	return max(getMaxAreaRec(hist, st, n, l, m-1),
			getMaxAreaRec(hist, st, n, m+1, r),
			(r-l+1)*(hist[m]) );
}

int getMaxArea(int hist[], int n)
{
	
	int *st = constructST(hist, n);
	
	return getMaxAreaRec(hist, st, n, 0, n-1);
}

int main()
{
	int hist[] = {6, 1, 5, 4, 5, 2, 6};
	int n = sizeof(hist)/sizeof(hist[0]);
	cout << "Maximum area is " << getMaxArea(hist, n);
	return 0;
}















