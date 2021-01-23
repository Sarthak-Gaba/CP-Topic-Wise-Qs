#include<bits/stdc++.h>
#include<bitset>

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define ll long long
#define INT_MINM -15008
// typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag,
// tree_order_statistics_node_update>
// PBDS;

void layout()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

struct node{
	ll ps,ss,ts,ms;
};

vector<ll> v(500007);
vector<node> tree(4*500007+1);

void buildTree(ll s, ll e, ll index)
{
	if(s==e)
	{
		tree[index] = (node){v[s],v[s],v[s],v[s]};
		return;
	}
	ll mid = (s+e)/2;
	buildTree(s,mid,2*index);
	buildTree(mid+1,e,2*index+1);
	node left=tree[2*index], right=tree[2*index+1];
	tree[index].ps = max(left.ps,left.ts+right.ps);
	tree[index].ss = max(right.ss,right.ts+left.ss);
	tree[index].ts = left.ts + right.ts;
	tree[index].ms = max(max(left.ms,right.ms),left.ss+right.ps);
}

node solveQuery(ll l, ll r, ll s, ll e, ll index)
{
	//No overlap
	if(e<l || s>r)
		return (node){INT_MINM,INT_MINM,INT_MINM,INT_MINM};
	//Complete overlap
	if(s>=l && e<=r)
		return tree[index];
	//Partial Overlap
	ll mid = (s+e)/2;
	node left=solveQuery(l,r,s,mid,2*index), right=solveQuery(l,r,mid+1,e,2*index+1);
	node temp;
	temp.ps = max(left.ps,left.ts+right.ps);
	temp.ss = max(right.ss,right.ts+left.ss);
	temp.ts = left.ts + right.ts;
	temp.ms = max(max(left.ms,right.ms),left.ss+right.ps);
	return temp;
}

int main()
{
	layout();
	ll n;
	cin >> n;
	for(ll i=0; i<n; i++)
		cin >> v[i];
	buildTree(0,n-1,1);
	// for(auto i:tree)
	// 	cout << i << " ";
	// cout << endl;
	ll m;
	cin >> m;
	string res;
	while(m--)
	{
		ll l,r; 
		cin >> l >> r;
		cout << solveQuery(l-1,r-1,0,n-1,1).ms << endl;
	}
}