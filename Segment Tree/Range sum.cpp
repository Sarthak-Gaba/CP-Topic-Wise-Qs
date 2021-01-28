#include<bits/stdc++.h>
#include<bitset>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long

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

// Code Range Sum Problem

void buildTree(vector<ll> &v, vector<ll> &tree, ll s, ll e, ll index)
{
	if(s==e)
	{
		tree[index] = v[s];
		return;
	}
	ll mid = (s+e)/2;
	buildTree(v,tree,s,mid,2*index);
	buildTree(v,tree,mid+1,e,2*index+1);
	tree[index] = tree[2*index] + tree[2*index+1];
}

ll solveQuery(vector<ll> &tree, ll l, ll r, ll s, ll e, ll index, vector<ll> &lazy)
{
	//No overlap
	if(e<l || s>r)
		return 0;
	//Lazy Updates
	tree[index] += (e-s+1)*lazy[index];
	if(s!=e)
	{
		lazy[2*index] += lazy[index];
		lazy[2*index+1] += lazy[index];
	}
	lazy[index] = 0;
	//Complete overlap
	if(s>=l && e<=r)
		return tree[index];
	//Partial Overlap
	ll mid = (s+e)/2;
	return solveQuery(tree,l,r,s,mid,2*index,lazy) + solveQuery(tree,l,r,mid+1,e,2*index+1,lazy);
}

void rangeUpdate(vector<ll> &tree, ll l, ll r, ll value, ll s, ll e, ll index, vector<ll> &lazy)
{
	//No overlap
	if(e<l || s>r || s>e)
		return;
	//Lazy Updates
	tree[index] += (e-s+1)*lazy[index];
	if(s!=e)
	{
		lazy[2*index] += lazy[index];
		lazy[2*index+1] += lazy[index];
	}
	lazy[index] = 0;
	//Complete overlap
	if(s>=l && e<=r)
	{
		tree[index] += (e-s+1)*value;
		if(s!=e)
		{
			lazy[2*index] += value;
			lazy[2*index+1] += value;
		}
		return;
	}
	//Partial Overlap
	ll mid = (s+e)/2;
	rangeUpdate(tree,l,r,value,s,mid,2*index,lazy);
	rangeUpdate(tree,l,r,value,mid+1,e,2*index+1,lazy);
}

int main()
{
	layout();
	vector<ll> v{1,3,2,-5,6,4};
	ll n = v.size();
	vector<ll> tree(4*n+1,0),lazy(4*n+1,0);
	buildTree(v,tree,0,n-1,1);
	rangeUpdate(tree,2,3,10,0,n-1,1,lazy);
	cout << solveQuery(tree,1,3,0,n-1,1,lazy);
}