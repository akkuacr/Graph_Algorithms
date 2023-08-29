// aap bellman ford ka use negative weight  m kr skte h but negative cycle m ni kr skte but bellman ford se aap negative cycle pta kr skte h

// but ye variation h bellman ford ki isme hum maximum distance nikal re h


#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back
#define que_max priority_queue<int>
#define que_min priority_queue<int,vector<int>,greater<int>>;
 #define endl "\n"
 using namespace std;


int N=2501;
int INF=1e9+10;
vector<vector<int>>G;
int n1;
 
 int32_t main()
 {
 #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
 #endif

int n,m;
cin>>n>>m;
for(int i=0;i<m;i++)
{
    int a,b,wt;
    cin>>a>>b>>wt;
    G.push_back({a,b,wt});
}


vector<int>dist(n+1,INF);
int y=-1;
for(int i=1;i<=n;i++){dist[i]*=y;}
INF*=y;
dist[1]=0;
for(int i=1;i<=n;i++)
{
    for(int j=0;j<m;j++)
    {
        int u=G[j][0], v=G[j][1],wt=G[j][2];

        if(dist[u]!=INF && ((dist[u]+wt)>dist[v]))
        {
            dist[v]=dist[u]+wt;
        }
    }
}

 bool flag=0;
  for(int j=0;j<m;j++)
    {
        int u=G[j][0], v=G[j][1],wt=G[j][2];

        if(dist[u]!=INF && ((dist[u]+wt)>dist[v]))
        {
            flag=1;break;
        }
    }


 if(flag){
    cout<<"-1"<<endl;
 }else
 {
    cout<<dist[n]<<endl;
 }

  



     return 0;
 }













 

 
