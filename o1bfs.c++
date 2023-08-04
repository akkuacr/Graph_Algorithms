





// isme pehle ye dhoondhna tha ki ise shortest path l]ki problem bnaye kese

// problem link:-https://www.codechef.com/problems/REVERSE







#include<bits/stdc++.h>
 
 #define int long long int
 #define F first
 #define S second
 #define pb push_back
 #define que_max priority_queue<int>
 #define que_min priority_queue<int,vector<int>,greater<int>>;
  #define endl "\n"
  using namespace std;

  const int N=1e5+10;
  const int INF=1e9+10;
  vector<pair<int,int>>G[N];
  vector<int>level(N,INF);
  vector<int>visited(N,0);
  int n,m;

  int bfs(int n)
{
    deque<int> q;
    q.push_back(1);
    level[1] = 0;

    while(!q.empty())
    {
        int cur_v = q.front();
        q.pop_front();
        for(auto child:G[cur_v])
        {
            int c_v = child.first;
            int wt = child.second;
            if(level[cur_v] + wt < level[c_v])
            {
                level[c_v] = level[cur_v] + wt;
                if(wt==1) q.push_back(c_v);
                else q.push_front(c_v);
            }
        }
    }
    return (level[n] == INF? -1 : level[n]);
}


  
  int32_t main()
  {
  #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
  #endif


      cin>>n>>m;

      for(int i=0;i<m;i++)
      {
        int x,y;
        cin>>x>>y;

        G[x].push_back({y,0});
        G[y].push_back({x,1});
      }

    

      cout<<bfs(n)<<endl;



  
 
 
 
      return 0;
  }
