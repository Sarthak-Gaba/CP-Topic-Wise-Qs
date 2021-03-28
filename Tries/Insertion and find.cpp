#include<bits/stdc++.h>
#include<bitset>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long

typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,
        tree_order_statistics_node_update>
        PBDS;

void layout()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

class Node {
public:
	char data;
	unordered_map<char, Node*> children;
	bool terminal;

	Node(char d) {
		data = d;
		terminal = false;
	}
};

class Trie {
public:
	Node* root;
	int cnt;

	Trie() {
		root = new Node('\0');
		cnt = 0;
	}

	void insert(string s)
	{
		Node* temp = root;
		for (ll i = 0; i < s.length(); i++)
		{
			char c = s[i];
			if (temp->children.count(c))
				temp = temp->children[c];
			else
			{
				Node* n = new Node(c);
				temp->children[c] = n;
				temp = n;
			}
		}
		temp->terminal = true;
	}

	bool find(string s)
	{
		Node* temp = root;
		for (ll i = 0; i < s.length(); i++)
		{
			char c = s[i];
			if (temp->children.count(c))
				temp = temp->children[c];
			else
				return false;
		}
		return temp->terminal;
	}
};

int main()
{
	layout();
	ll n;
	cin >> n;
	vector<string> v(n);
	for (ll i = 0; i < n; i++)
		cin >> v[i];
	Trie t;
	for (ll i = 0; i < n; i++)
		t.insert(v[i]);
	string s;
	cin >> s;
	cout << t.find(s) << endl;
}