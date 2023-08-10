int N=1e5+10;
   int INF=1e9+10;
   vector<pair<int,int>>G[100010];
    int n1;

   int dijkstra(int source)
   {
       vector<int>visited(N,0);
        vector<int>dist(N,INF);
       set<pair<int,int>>st;
       st.insert({0,source});
         
       dist[source]=0;
       while(st.size()>0)
       {
           auto node=*st.begin();
           int v=node.second;int node_d=node.first;st.erase(st.begin());
           if(visited[v])continue;
           visited[v]=1;

           for(auto child:G[v])
           {
               int child_v=child.first;
               int wt=child.second;
               if(dist[v]+wt < dist[child_v]){
                   dist[child_v]=dist[v]+wt;
                   st.insert({dist[child_v],child_v});
               }
           }

       }
       
       int mx=-1;
        for(int i=1;i<=n1;i++)
        {
            mx=max(mx,dist[i]);
        }


     return mx;

   } 
