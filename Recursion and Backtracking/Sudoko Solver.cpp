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

bool canPlace(int mat[][9], int n, int i, int j, int num)
{
	//row and columns
	for(int k=0; k<n; k++)
	{
		if(mat[i][k]==num || mat[k][j]==num)
			return false;
	}

	//sub grid
	int rn = sqrt(n);
	int si = (i/rn)*rn;
	int sj = (j/rn)*rn;
	for(int x=si; x<si+rn; x++)
	{
		for(int y=sj; y<sj+rn; y++)
		{
			if(mat[x][y]==num)
				return false;
		}
	}

	return true;
}

bool sudokoSolver(int mat[][9], int n, int i, int j)
{
	//Base Case
	if(i==n)
	{
		for(int x=0; x<n; x++)
		{
			for(int y=0; y<n; y++)
				cout << mat[x][y] << " ";
			cout << endl;
		}
		return true;
	}

	if(j==n)
		return sudokoSolver(mat,n,i+1,0);

	if(mat[i][j]!=0)
		return sudokoSolver(mat,n,i,j+1);

	//Recursive
	for(int num=1; num<=n; num++)
	{
		if(canPlace(mat,n,i,j,num))
		{
			mat[i][j]=num;
			if(sudokoSolver(mat,n,i,j+1))
				return true;
		}
	}
	mat[i][j]=0;
	return false;
}

int main()
{
	layout();
	int mat[9][9] =
		{
			{5,3,0,0,7,0,0,0,0},
			{6,0,0,1,9,5,0,0,0},
			{0,9,8,0,0,0,0,6,0},
			{8,0,0,0,6,0,0,0,3},
			{4,0,0,8,0,3,0,0,1},
			{7,0,0,0,2,0,0,0,6},
			{0,6,0,0,0,0,2,8,0},
			{0,0,0,4,1,9,0,0,5},
			{0,0,0,0,8,0,0,7,9}
		};
	sudokoSolver(mat,9,0,0);
}