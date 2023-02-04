#include <bits/stdc++.h>
using namespace std;


stack<int> recur(stack<int> S, int N)
{
	if (S.empty())
		S.push(N);

	else {

		int X = S.top();

		S.pop();

		S = recur(S, N);

		S.push(X);
	}
	return S;
}


void insertToBottom(
	stack<int> S, int N)
{

	
	S = recur(S, N);

	while (!S.empty()) {
		cout << S.top() << " ";
		S.pop();
	}
}

int main()
{
	stack<int> S;
	S.push(5);
	S.push(4);
	S.push(3);
	S.push(2);
	S.push(1);

	int N = 7;

	insertToBottom(S, N);

	return 0;
}













#include <bits/stdc++.h>
using namespace std;

class LRUCache {
	list<int> dq;

	unordered_map<int, list<int>::iterator> ma;
	int csize; 

public:
	LRUCache(int);
	void refer(int);
	void display();
};


LRUCache::LRUCache(int n) { csize = n; }


void LRUCache::refer(int x)
{

	if (ma.find(x) == ma.end()) {
		
		if (dq.size() == csize) {
			int last = dq.back();

			dq.pop_back();

			ma.erase(last);
		}
	}

	else
		dq.erase(ma[x]);

	dq.push_front(x);
	ma[x] = dq.begin();
}

void LRUCache::display()
{

	for (auto it = dq.begin(); it != dq.end(); it++)
		cout << (*it) << " ";

	cout << endl;
}

int main()
{
	LRUCache ca(4);

	ca.refer(1);
	ca.refer(2);
	ca.refer(3);
	ca.refer(1);
	ca.refer(4);
	ca.refer(5);
	ca.display();

	return 0;
}
