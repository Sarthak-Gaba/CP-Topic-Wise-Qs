#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define matmap unordered_map<int,unordered_map<int,int>>
#define hash unordered_map<int,int>

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

void util(int n, int i, hash col, hash dif, hash sum, vector<int> v, bool &z)
{
	if(v.size()==n)
	{
		z=true;
		cout << "[";
		for(auto i: v)
			cout << i << " ";
		cout << "] ";
	}
	for(int k=1; k<=n; k++)
	{
		bool b=false;
		if(col[k]==0 && dif[k-i]==0 && sum[i+k]==0)
		{
			b=true;
			v.push_back(k);
			col[k]=1;
			dif[k-i]=1;
			sum[k+i]=1;
			util(n, i+1, col, dif, sum, v, z);
		}
		if(b)
		{
			v.pop_back();
			col[k]=dif[k-i]=sum[k+i]=0;
		}
	}
}

int main()
{
	layout();
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		hash col,dif,sum;
		vector<int> v;
		bool b=false;
		util(n,1,col,dif,sum,v,b);
		if(b==false)
			cout << -1 << endl;
		cout << endl;
	}
}
// [2 4 1 3 ] [3 1 4 2 ]
