//bakcedge in a undirected graph

  
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
  
  vector<int>G[N];
  int visited[N];

  bool cycle=false;

  //backedges are completely depend on root node aur iske liye special case v bnaenge



  void dfs(int curr,int par)
  {
    visited[curr]=1;
    cout<<curr<<endl;

    for(auto it:G[curr])
      {   if(!visited[it])
           {
             dfs(it,curr);
           }else if(it!=par){
            // for backedges

            cout<<"backedge is"<<endl;

              cout<<curr<<" "<<it<<endl;
              cycle=true;

            }

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
      memset(visited,0,sizeof(visited));



      for(int i=0;i<m;i++)
      {
        int x,y;
        cin>>x>>y;

        G[x].push_back(y);
        G[y].push_back(x);
      }

      for(int i=1;i<=n;i++)
      {
        if(!visited[i])
        {
           dfs(i,0);
        }
      }

      if(cycle)
      {
        cout<<"found"<<endl;
      }else
      {
        cout<<"Not found"<<endl;
      }


      



  
 
 
 
      return 0;
  }



  //Dfs tree and backedges in directed graph as well as undirected 


  
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
  
  vector<int>G[N];
  int visited[N];

  bool cycle=false;

  //backedges are completely depend on root node aur iske liye special case v bnaenge

// isme humne yeh alg kr rkha h ki jo markings h woh 0,1,2 
//0 means not visited,1 means visited and in call stack, and 2 means visited but not in call stack
//aur iska sidha sa mtlb yeh h ki call stack m kewal ancestors hi honge uss time



  void dfs(int curr,int par)
  {
    visited[curr]=1;
    cout<<curr<<endl;

    for(auto it:G[curr])
      {   if(!visited[it])
           {
             dfs(it,curr);
           }else if(it!=par && visited[it]==1){
            // for backedges

            cout<<"backedge is"<<endl;

              cout<<curr<<" "<<it<<endl;
              cycle=true;

            }

      }
      visited[curr]=2;

      return;

  }
 
 


  
  int32_t main()
  {
  #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
  #endif

      int n,m;
      cin>>n>>m;
      memset(visited,0,sizeof(visited));



      for(int i=0;i<m;i++)
      {
        int x,y;
        cin>>x>>y;

        G[x].push_back(y);
        G[y].push_back(x);
      }

      for(int i=1;i<=n;i++)
      {
        if(!visited[i])
        {
           dfs(i,0);
        }
      }

      if(cycle)
      {
        cout<<"found"<<endl;
      }else
      {
        cout<<"Not found"<<endl;
      }


      



  
 
 
 
      return 0;
  }


//print a cycle using backedge and dfs by using parents


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
  
  vector<int>G[N];
  int visited[N],parent[N];

  bool cycle=false;

  //backedges are completely depend on root node aur iske liye special case v bnaenge



  void dfs(int curr,int par)
  {
    visited[curr]=1;
    parent[curr]=par;
  //  cout<<curr<<endl;

    for(auto it:G[curr])
      {   if(!visited[it])
           {
             dfs(it,curr);
           }else if(it!=par && visited[it]==1){
            // for backedges

            cout<<"cycle is"<<endl;

            //  cout<<curr<<" "<<it<<endl;
              cycle=true;
              int u=curr,v=it;

              while(u!=v)
              {
                cout<<u<<" ";
                u=parent[u];

              }
              cout<<u;
              exit(0);

            }

      }
      visited[curr]=2;

      return;

  }
 
 


  
  int32_t main()
  {
  #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
  #endif

      int n,m;
      cin>>n>>m;
      memset(visited,0,sizeof(visited));



      for(int i=0;i<m;i++)
      {
        int x,y;
        cin>>x>>y;

        G[x].push_back(y);
        G[y].push_back(x);
      }

      for(int i=1;i<=n;i++)
      {
        if(!visited[i])
        {
           dfs(i,0);
        }
      }

      if(cycle)
      {
        cout<<"found"<<endl;
      }else
      {
        cout<<"Not found"<<endl;
      }


      



  
 
 
 
      return 0;
  }





