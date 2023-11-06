 #include<bits/stdc++.h>
 
 #define int long long int
 #define F first
 #define S second
 #define pb push_back
 #define que_max priority_queue<int>
 #define que_min priority_queue<int,vector<int>,greater<int>>;
  #define endl "\n"
  using namespace std;



  class DSU
  {
   
   int *parent;
   int *rank;

  public:
     DSU(int n){
      parent = new int [n];
      rank = new int [n];
       for(int i=0;i<n;i++){

        parent[i]=-1;
        rank[i]=1;
      }
    }
     
      


      //find function
      int find(int i){
        if(parent[i]==-1)
        {
          return i;
        }
        return parent[i] =find(parent[i]);
      }


      void unite(int x,int y)
      {
           int s1= find(x);
           int s2 = find(y);
           if(s1!=s2)
           {

               if(rank[s1]<rank[s2])
               {
                parent[s1]=s2;
                rank[s2]+= rank[s1];
               }else{
                parent[s2]=s1;
                rank[s1]+=rank[s2];
               }
           }

     }
     
};



 class Graph{


     vector<vector<int>>edgelist;
     int V;
   public:
    Graph(int V)
    {
      this->V=V;
    }
    void addEdge(int x,int y,int w)
    {
      edgelist.push_back({w,x,y});
    }


    int krushkal_mst()
    {
         //1.sort all the based upon weight

         sort(edgelist.begin(),edgelist.end());

         int ans=0;
         DSU s(V);

         for(auto edge:edgelist)
         {int w= edge[0];
         int x=edge[1];
          int y =edge[2];

          //take that edge in mst if it doesnt form a cycle
          if(s.find(x)!=s.find(y)){
            s.unite(x,y);
            ans+=w;
          }   

         }


         return ans;

    }

 };


  
  int32_t main()
  {
  #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
  #endif
  
     Graph g(4);
     g.addEdge(0,1,1);
     g.addEdge(1,3,3);
     g.addEdge(3,2,4);
     g.addEdge(2,0,2);
     g.addEdge(0,3,2);
     g.addEdge(1,2,2);

     cout<<g.krushkal_mst()<<endl;




    
 
      return 0;
  }
