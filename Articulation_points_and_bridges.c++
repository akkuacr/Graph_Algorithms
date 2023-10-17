 #include<bits/stdc++.h>
 
 #define int long long int
 #define F first
 #define S second
 #define pb push_back
 #define que_max priority_queue<int>
 #define que_min priority_queue<int,vector<int>,greater<int>>;
  #define endl "\n"
  using namespace std;


  const int N=1e5;
  vector<int>gr[N];
  int vis[N],low[N],disc[N],tme=1;

  vector<pair<int,int>>bridges;
  set<int>articulationPoints;

  void dfs(int curr,int par)
  {
    vis[curr]=1;
    disc[curr]=low[curr]=tme++;
    int child=0;

    for(auto x:gr[curr])
    {
      if(!vis[x])
      {
        child++;
        dfs(x,curr);

        //we know low and disc of x
        low[curr]=min(low[curr],low[x]);

        //bridges

        if(low[x]>disc[curr])
        {
          bridges.push_back({curr,x});
        }


        //articulation points

        if(par!=0 && (low[x]>=disc[curr])){

            articulationPoints.insert(curr);
        }



      }else if(x!=par)
      {
        //backedge
          low[curr]=min(low[curr],disc[x]);

      }
    }

    // whether root is an articulation points
     
     if(par==0 && child>1)
     {
          articulationPoints.insert(curr);
     }

  }


  
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
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
     }

     dfs(1,0);

     cout<<"articulationPoints are"<<endl;
     for(auto it:articulationPoints)
     {
      cout<<it<<" ";
     }
     cout<<endl;
     cout<<"Bridges are"<<endl;
     for(auto it:bridges)
     {
        cout<<it.first<<" "<<it.second<<endl;
     }



 
 
 
      return 0;
  }
