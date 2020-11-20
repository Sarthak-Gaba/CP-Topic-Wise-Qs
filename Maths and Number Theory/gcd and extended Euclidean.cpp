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
 
void layout()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

ll gcd(ll a, ll b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}

pair<ll,ll> extendedEuclidean(ll a, ll b)
{
	if(b==0)
		return make_pair(1,0);
	pair<ll,ll> p = extendedEuclidean(b,a%b);
	ll x=p.first,y=p.second;
	return make_pair(y,x-((a/b)*y));
}
 
int main()
{
	layout();
	ll a,b;
	cin >> a >> b;
	pair<ll,ll> p = extendedEuclidean(a,b);
	cout << p.first << " " << p.second << endl;
}