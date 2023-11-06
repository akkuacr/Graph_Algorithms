

//code for prims algorithm

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
   vector<pair<int,int>>Graph[N];
   vector<int>visited(N,0);
   int n,m;

   int prims_mst(){
    
    // most important stuff
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    

     


     //another array
    //visited array that denotes whether a node has been included 
   
     int ans=0;
     q.push({0,1});//weight ,node
     while(!q.empty())
     {
        auto best = q.top();
        q.pop();

        int to = best.second;
        int weight =best.first;
        if(visited[to]){
          
          continue;

        }


        
        //otherwise take the current edge
        ans+=weight;
        visited[to] =1;

        for(auto x:Graph[to] ){
              
              if(visited[x.first]==0)
              {
                q.push({x.second,x.first});
              }

        }


     }

    return ans;

   }
 
   
 
 
 
 
   int32_t main()
   {
   #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
   #endif
   
 
 
 
 
   // int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        Graph[x].push_back({y,w});
        Graph[y].push_back({x,w});
    }



   cout<<prims_mst()<<endl;
 
  
     
  
       return 0;
   }
