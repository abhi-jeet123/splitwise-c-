/*
  Author- Abhijeet Trigunait
*/

#include<bits/stdc++.h>
#define lld long long int
#define P pair<int,int>
#define pb push_back
#define mod 1e9+7
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define gcd(x,y) __gcd(x,y)
#define endl '\n'

using namespace std;

class person_compare {
public:
	bool operator()(pair<string, int> p1, pair<string, int> p2) {
		return p1.second < p2.second;
	}
};
int main() {
	int no_of_transaction, friends;
	cin >> no_of_transaction >> friends;

	string x, y;
	int amount;

	map<string, int> net;

	while (no_of_transaction--) {
		cin >> x >> y >> amount;
		if (net.count(x) == 0) {
			net[x] = 0;
		}
		if (net.count(y) == 0) {
			net[y] = 0;
		}
		net[x] -= amount;
		net[y] += amount;
	}

	multiset<pair<string, int>, person_compare> m;
	for (auto p : net) {
		string person = p.first;
		int amount = p.second;

		if (net[person] != 0) {
			m.insert(make_pair(person, amount));
		}

	}
	int cnt = 0;
	//3.settlement amount and detail print
	while (!m.empty()) {
		auto low = m.begin();
		auto high = prev(m.end());

		string debit_person = low->first;
		int debit = low->second;

		string credit_person = high->first;
		int credit = high->second;

		m.erase(low);
		m.erase(high);

		int settle_amount = min(-debit, credit);

		cout << debit_person << " will pay " << settle_amount << " to " << credit_person << endl;

		debit += settle_amount;
		credit -= settle_amount;

		if (debit != 0) {
			m.insert(make_pair(debit_person, debit));
		}
		if (credit != 0) {
			m.insert(make_pair(credit_person, credit));
		}
		cnt += 1;
	}
	cout << "Total no of transaction " << cnt << endl;



}