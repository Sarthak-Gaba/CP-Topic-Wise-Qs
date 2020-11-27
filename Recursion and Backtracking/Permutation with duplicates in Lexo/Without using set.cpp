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

vector<string> res;

void genPerm(string s, ll i)
{
	if(i==s.size())
	{
		res.push_back(s);
		return;
	}
	sort(s.begin()+i+1,s.end());
	for(ll k=i; k<s.size(); k++)
	{
		while(k+1<s.size() && s[k]==s[k+1])
			k++;
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
	sort(s.begin(),s.end());
	genPerm(s,0);
	sort(res.begin(),res.end());
	for(auto i:res)
		cout << i << endl;
}