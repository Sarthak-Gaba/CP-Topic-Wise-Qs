#include<bits/stdc++.h>
#include<bitset>

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define ll long long

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

vector<ll> v(30007);
vector<vector<ll>> tree(4*30007+1);


void buildTree(ll s, ll e, ll index)
{
	if(s==e)
	{
		vector<ll> temp(1);
		temp[0]=v[s];
		tree[index] = temp;
		return;
	}
	ll mid = (s+e)/2;
	buildTree(s,mid,2*index);
	buildTree(mid+1,e,2*index+1);
	vector<ll> left = tree[2*index], right = tree[2*index+1];
	vector<ll> temp(left.size()+right.size());
	ll i=0,j=0,k=0;
	while(i<left.size() && j<right.size())
	{
		if(left[i] > right[j])
			temp[k++] = right[j++];	
		else
			temp[k++] = left[i++];
	}
	while(i<left.size())
		temp[k++] = left[i++];
	while(j<right.size())
		temp[k++] = right[j++];
	tree[index] = temp;
}

ll solveQuery(ll l, ll r, ll s, ll e, ll index, ll k)
{
	//No overlap
	if(s>r || e<l)
		return 0;
	//Complete overlap
	if(s>=l && e<=r)
	{
		return tree[index].size() - (upper_bound(tree[index].begin(),tree[index].end(),k)-tree[index].begin());
	}
	//Partial overlap
	ll mid = (s+e)/2;
	ll left = solveQuery(l,r,s,mid,2*index,k);
	ll right = solveQuery(l,r,mid+1,e,2*index+1,k);
	return left+right;	
}

int main()
{
	layout();
	ll n;
	cin >> n;
	for(ll i=0; i<n; i++)
		cin >> v[i];
	buildTree(0,n-1,1);
	ll q,last_ans=0;
	cin >> q;
	while(q--)
	{
		ll a,b,c,i,j,k;
		cin >> a >> b >> c;
		i=a^last_ans;
		j=b^last_ans;
		k=c^last_ans;
		last_ans = solveQuery(i-1,j-1,0,n-1,1,k);
		cout << last_ans << endl;
	}
}