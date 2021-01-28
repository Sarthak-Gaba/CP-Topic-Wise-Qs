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

ll solveQuery(vector<ll> &tree, ll l, ll r, ll s, ll e, ll index)
{
	//No overlap
	if(s>r || e<l)
		return INT_MAX;
	//Complete overlap
	if(s>=l && e<=r)
		return tree[index];
	//Partial Overlap
	ll mid = (s+e)/2;
	return min(solveQuery(tree,l,r,s,mid,2*index),solveQuery(tree,l,r,mid+1,e,2*index+1));
}

void updatePoint(vector<ll> &tree, ll pos, ll value, ll s, ll e, ll index)
{
	if(s>e)
		return;
	if(s==pos && e==pos)
	{
		tree[index] += value;
		return; 
	}
	//Overlap
	if(s<=pos && e>=pos)
	{
		ll mid = (s+e)/2;
		updatePoint(tree,pos,value,s,mid,2*index);
		updatePoint(tree,pos,value,mid+1,e,2*index+1);
		tree[index] = min(tree[2*index],tree[2*index+1]);
	}
}

void updateRange(vector<ll> &tree, ll l, ll r, ll value, ll s, ll e, ll index)
{
	//No overlap
	if(e<l || s>r)
		return;
	//Element match
	if(s==e)
	{
		tree[index] += value;
		return;
	}
	//Overlap
	ll mid = (s+e)/2;
	updateRange(tree,l,r,value,s,mid,2*index);
	updateRange(tree,l,r,value,mid+1,e,2*index+1);
	tree[index] = min(tree[2*index],tree[2*index+1]);
}

int main()
{
	layout();
	vector<ll> v{11,3,2,-5,6,4};
	ll n = v.size(),q;
	vector<ll> tree(4*n+1);
	buildTree(v,0,n-1,tree,1);
	cin >> q;
	updateRange(tree,1,5,20,0,n-1,1);
	while(q--)
	{
		ll l,r;
		cin >> l >> r;
		cout << solveQuery(tree,l,r,0,n-1,1) << endl;
	}
}