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

void buildTree(vector<ll> &v, ll s, ll e, vector<ll> &tree, ll index)
{
	if(s==e)
	{
		tree[index] = v[s];
		return;
	}
	ll mid = (s+e)/2;
	buildTree(v,s,mid,tree,2*index);
	buildTree(v,mid+1,e,tree,2*index+1);
	tree[index] = min(tree[2*index],tree[2*index+1]);
}

//Lazy Propagation

ll solveQueryLazy(vector<ll> &tree, ll l, ll r, ll s, ll e, ll index, vector<ll> &lazy)
{
	//No overlap
	if(s>e || s>r || e<l)
		return INT_MAX;
	tree[index] += lazy[index];
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
	return min(solveQueryLazy(tree,l,r,s,mid,2*index,lazy),solveQueryLazy(tree,l,r,mid+1,e,2*index+1,lazy));
}

void updateRangeLazy(vector<ll> &tree, ll l, ll r, ll value, ll s, ll e, ll index, vector<ll> &lazy)
{
	//No overlap
	if(s>r || e<l)
		return;
	//Update lazy values
	tree[index] += lazy[index];
	if(s!=e)
	{
		lazy[2*index] += lazy[index];
		lazy[2*index+1] += lazy[index];
	}
	lazy[index] = 0;
	//Complete overlap
	if(s>=l && e<=r)
	{
		tree[index] += value;
		if(s!=e)
		{
			lazy[2*index] += value;
			lazy[2*index+1] += value;
		}
		return;
	}
	ll mid = (s+e)/2;
	updateRangeLazy(tree,l,r,value,s,mid,2*index,lazy);
	updateRangeLazy(tree,l,r,value,mid+1,e,2*index+1,lazy);
	tree[index] = min(tree[2*index],tree[2*index+1]);
}

int main()
{
	layout();
	vector<ll> v{1,3,2,-5,6,4};
	ll n = v.size(),q;
	vector<ll> tree(4*n+1);
	vector<ll> lazy(4*n+1,0);
	buildTree(v,0,n-1,tree,1);
	updateRangeLazy(tree,0,2,10,0,n-1,1,lazy);
	updateRangeLazy(tree,0,4,10,0,n-1,1,lazy);
	cout << solveQueryLazy(tree,1,1,0,n-1,1,lazy) << endl;
	updateRangeLazy(tree,3,4,10,0,n-1,1,lazy);
	cout << solveQueryLazy(tree,3,5,0,n-1,1,lazy) << endl;
}