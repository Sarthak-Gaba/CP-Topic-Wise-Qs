#include<bits/stdc++.h>
#include<bitset>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long

typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,
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

void buildPie(int pie[], string s2)
{
	int m = s2.length();
	int i=1,j=0,counter=0;
	while(i<m)
	{
		if(s2[i]==s2[j])
		{
			counter++;
			pie[i]=counter;
			i++;
			j++;
		}
		else
		{
			if(j>0)
			{
				counter = pie[j-1];
				j = pie[j-1];
			}
			else
			{
				counter=0;
				i++;
			}
		}
	}
}

int kmp(string s1, string s2)
{
	int n = s1.length(), m = s2.length();
	int pie[m] = {0};
	buildPie(pie,s2);
	int i=0,j=0,k=0;
	while(i<n && j<m)
	{
		if(s1[i]==s2[j])
		{
			i++;
			j++;
		}
		else
		{
			if(j>0)
			{
				j = pie[j-1];
				k = i-j; 
			}
			else
			{
				i++;
				k=i;
			}
		}
	}
	if(j==m)
		return k;
	else
		return -1;
	// for(int i=0; i<m; i++)
	// 	cout << pie[i] << " ";	
}

int main()
{
	layout();
	string s1,s2;
	cin >> s1 >> s2;
	cout << kmp(s1,s2);
}

// ababcabcabaaaaaaababd
// ababd