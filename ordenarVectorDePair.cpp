#include <bits/stdc++.h>

using namespace std;

inline bool comparador(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.first == b.first)
		return a.second > b.second;

	return a.first < b.first;
}

int main(void)
{
	vector< pair<int, int> > v1;

	v1.push_back(make_pair(9, 0));
	v1.push_back(make_pair(9, 1));
	v1.push_back(make_pair(0, 1));
	v1.push_back(make_pair(1, 1));
	v1.push_back(make_pair(1, 5));

	/*vector < pair <int, int> > figth(dragons);

	for (int i = 0; i < dragons; ++i)
		cin >> figth[i].first >> figth[i].second;

	sort(figth.begin(), figth.end(), comparador);
	*/

	sort(v1.begin(), v1.end(), comparador);

	for (pair<int, int> p : v1)
		cout << "(" << p.first << "," << p.second << ") ";

	cout << endl;

	return 0;
}