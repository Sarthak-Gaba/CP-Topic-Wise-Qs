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

int n,DONE,ans=0;

void solve(int rowMask, int ld, int rd)
{
	if(rowMask == DONE)
	{
		ans++;
		return;
	}
	int safe = DONE & (~(rowMask | ld | rd));
	while(safe)
	{
		int p = safe & (-safe);
		safe = safe-p;
		solve(rowMask | p, (ld | p) << 1, (rd | p) >> 1);

	}
}

int main()
{
	layout();
	cin >> n;
	DONE = ((1<<n)-1);
	//cout << "HEY";
	solve(0,0,0);
	cout << ans << endl;
}

