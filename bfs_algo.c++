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
  vector<int>Graph[N];
  vector<int>visited(N,0);

  void bfs(int i)
  {

        visited[i]=1;
        queue<int>q;
        q.push(i);
        while(q.size()>0)
        {
            int tp=q.front();
            q.pop();
             cout<<tp<<endl;

            for(auto it:Graph[tp])
            {
                if(!visited[it])
                {
                    q.push(it);
                }
            }
            visited[tp]=1;
        }
  }





  int32_t main()
  {
  #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
  #endif
  




  int n;
  cin>>n;
  for(int i=0;i<(n-1);i++)
  {
    int x,y;
    cin>>x>>y;
    Graph[x].push_back(y);
  }


  bfs(1);


 
    
 
      return 0;
  }
