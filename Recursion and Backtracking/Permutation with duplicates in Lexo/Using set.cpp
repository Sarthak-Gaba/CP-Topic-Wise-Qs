#include<bits/stdc++.h>
#include<bitset>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define hash unordered_map<ll,ll>

typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag,
tree_order_statistics_node_update>
PBDS;

ll z=1000000007;

void layout()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

set<string> res;

void genPerm(string s, ll i)
{
	if(i==s.size())
	{
		res.insert(s);
		return;
	}
	sort(s.begin()+i,s.end());
	for(ll k=i; k<s.size(); k++)
	{
		swap(s[i],s[k]);
		genPerm(s,i+1);
		swap(s[i],s[k]);
	}
}

int main()
{
	layout();
	string s;
	cin >> s;
	genPerm(s,0);
	for(auto i:res)
		cout << i << endl;
}