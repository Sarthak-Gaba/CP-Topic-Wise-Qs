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

//Q link: https://hack.codingblocks.com/app/practice/6/1044/problem

int binarySearch(int arr[], int n, int key){
    int s = 0;
    int e = n-1;
    int mid;
    while(s<=e)
    {
        mid = (s+e)/2;
        if(arr[mid]==key)
            return mid;
        else if(arr[s]<=arr[mid])
        {
        	if(arr[s]<=key and arr[mid]>key)
        		e = mid-1;
        	else
        		s = mid+1;
        }
        else
        {
        	if(arr[mid]<key and arr[e]>=key)
        	{
        		s=mid+1;
        	}
        	else
        		e=mid-1;
        }
    }
    return -1;
}

int main()
{
	layout();
	int n, first=-1, key;
	cin >> n;
	int v[n];
	for(ll i=0; i<n; i++)
	{
		cin >> v[i];
	}
	cin >> key;
	cout << binarySearch(v,n,key);
}