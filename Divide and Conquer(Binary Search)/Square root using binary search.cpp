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

float sqrtByBinarySearch(int n, int p){
    int s = 0, e = n, mid;
    float ans;
    while(s<=e)
    {
        mid = (s+e)/2;
        if(mid*mid == n)
        	return mid;
        else if(mid*mid>n)
        	e = mid-1;
        else
        {
        	ans = mid;
        	s = mid+1;
        }
    }

    //for decimal precision
    float inc = 0.1;
    for(int i=0; i<p; i++)
    {
    	while(ans*ans<=n)
    		ans = ans+inc;
    	ans = ans-inc;
    	inc = inc/10;
    }

    return ans;
}

int main()
{
	layout();
	int n;
	cin >> n;
    // second argument p is for precision, set 0 for int value
	cout << sqrtByBinarySearch(n,3);
}