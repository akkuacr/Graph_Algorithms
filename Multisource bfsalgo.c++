// ye algo tb jyada use hogi jb aap ko multiple source se kisi single location m phuchna ho yah multiple source se distance nikalni ho

// isse hum matrix se related problems m v use kr skte h 

// problem link:https://www.codechef.com/problems/SNSOCIAL

 #include<bits/stdc++.h>
 
 #define int long long int
 #define F first
 #define S second
 #define pb push_back
 #define que_max priority_queue<int>
 #define que_min priority_queue<int,vector<int>,greater<int>>;
  #define endl "\n"
  using namespace std;
 
  const int N=510;
  const int INF=1e9+10;
  int G[N][N];
  queue<pair<int,int>>q;
   int n,m;

   bool isValid(int x,int y)
   {
      return (x>=0 && x<n && y>=0 && y<m);
   }
  
  int dist[N][N];

  int bfs()
  {
     while(q.size()>0)
     {
         
         auto it=q.front();q.pop();

         vector<pair<int,int>>movements={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{1,1},{1,-1},{-1,1}};

         for(auto it1:movements)
         {
            int x1=it.first+it1.first;
            int y1=it.second+it1.second;
            
            if(!isValid(x1,y1))continue;

            if((dist[it.first][it.second]+1)<dist[x1][y1])
            {
                dist[x1][y1]=dist[it.first][it.second]+1;
                q.push({x1,y1});

            }


         }

     }

     int mx_1=0;

     for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++)
        {
          // cout<<dist[i][j]<<" ";
            mx_1=max(mx_1,dist[i][j]);
        }
        // cout<<endl;
     }

     return mx_1;




  }





  
  int32_t main()
  {
  #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
  #endif
 
    int32_t t;
    cin>>t;
    while(t--)
    {  
        memset(G,0,sizeof(G));
        memset(dist,INF,sizeof(dist));

        
        cin>>n>>m;
          int mx=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>G[i][j];
                mx=max(mx,G[i][j]);
            }

        }


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mx==G[i][j])
                {
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }

        if(q.size()==(n*m))
        {
            cout<<"0"<<endl;
            continue;
        }


        


        cout<<bfs()<<endl;



    }

  
 
 
 
      return 0;
  }
