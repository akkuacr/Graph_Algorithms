
//description of algorithm is done in notebook but overall isme topological sorting lag rhi h



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
  vector<int>Graph[N],GraphRev[N];
  vector<int>visited(N,0),col(N,0);


  //topological sorting
  vector<int>order;

  void dfs1(int cur)
  {
    visited[cur]=1;
     
    //cout<<cur<<" ";
      
      for(auto it:Graph[cur])
      {
        if(!visited[it])
        {
          dfs1(it);
        }
      }
 

 //I am here because i came from the subtree 

      order.push_back(cur);

      return;       
        
  }

   void dfs2(int cur,int comp)
  {
    visited[cur]=1;
    col[cur]=comp;
    //  cout<<"yha aya"<<endl;
    // cout<<cur<<" ";
      
      for(auto it:GraphRev[cur])
      {
        if(!visited[it])
        {
          dfs2(it,comp);
        }
      }
 

 //I am here because i came from the subtree 

     // order.push_back(cur);

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
  for(int i=0;i<m;i++)
  {
    int x,y;
    cin>>x>>y;
    Graph[x].push_back(y);
    GraphRev[y].push_back(x);
  }
  

  for(int i=1;i<=n;i++)
  {  
       if(!visited[i])
        { 
          dfs1(i);
        }
  }
  reverse(order.begin(), order.end());

   for(int i=1;i<=N;i++)
   {
    visited[i]=0;
   }
   int comp=1;
  for(auto it:order)
  {
    if(!visited[it]){
      dfs2(it,comp++);
    }
  }


  for(int i=1;i<=n;i++)
  {
    cout<<i<<" "<<col[i]<<endl;
  }
  
  cout<<"Total strong components are"<<comp-1<<endl;
    

 
    
 
      return 0;
  }
