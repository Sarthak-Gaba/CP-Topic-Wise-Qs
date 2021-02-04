#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long 
#define ld long double
#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define MOD 1000000007
#define N 100007
#define MAXN 117
typedef pair<ll,ll> pll;
vector<ll> graph[N];
map<pll,ll> mymap;
bool visited[N]={0};
ll helper(ll sv){
	visited[sv]=1;
	ll ans=graph[sv].size()%2;
	for(auto it:graph[sv]){
		if(visited[it]) continue;
		ans+=helper(it);
	}
	return ans;
}

void dfs(ll z){
	

	ll t=0,cnt=0;
	for(int i=1;i<=z;i++){
		if(visited[i]) continue;
		ll temp=helper(i);
		cnt++;
		t+=max(temp, 2ll);
	}
	cout<<max(cnt-1, (t-1)/2)<<endl;
}

int main(){
   #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  fast_cin();

  ll m,z=1;
  cin>>m;
  for(int i=1;i<=m;i++){
  	ll x1,y1,x2,y2;
  	cin>>x1>>y1>>x2>>y2;
  	ll u,v;
  	if(mymap[{x1,y1}]==0){
  		mymap[{x1,y1}]=z;
  		z++;
  	}
  	if(mymap[{x2,y2}]==0){
  		mymap[{x2,y2}]=z;
  		z++;
  	}
  	u=mymap[{x1,y1}];
  	v=mymap[{x2,y2}];

  	graph[u].pb(v);
  	graph[v].pb(u);

  }
  z--;
  dfs(z);

}