
//Problem link:-https://www.spoj.com/problems/NAKANJ/





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
   vector<int>g[N];int level[8][8];int visited[8][8];

   int getX(string s)
   {
      return s[0]-'a';
   }

   int getY(string s)
   {
        return s[1]-'1';
   }


   bool isValid(int x,int y)
   {
        return (x>=0 && y>=0 && x<8 && y<8); 
   }
   vector<pair<int,int>>movements={{-1,2},{1,2},{-1,-2},{1,-2},{2,-1},{2,1},{-2,-1},{-2,1}};

   int bfs(string source,string dest)
   {

        int sourcex=getX(source);
        int sourcey=getY(source);
        int destx=getX(dest);
        int desty=getY(dest);
        queue<pair<int,int>>q;
        q.push({sourcex,sourcey});
        visited[sourcex][sourcey]=1;

        while(!q.empty())
        {
            pair<int,int>v=q.front();q.pop();
            int x=v.first,y=v.second;
            for(auto movement:movements)
            {
                 int childx=movement.first+x;
                 int childy=movement.second+y;
                 if(!isValid(childx,childy)){
                    continue;
                 }
                 if(!visited[childx][childy])
                 {
                    q.push({childx,childy});
                    level[childx][childy]=level[x][y]+1;
                    visited[childx][childy]=1;
                 }



            }

            if(level[destx][desty]!=0)
            {
                break;
            }
        }
        return level[destx][desty];
      
   }







  int32_t main()
  {
  #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
  #endif
  
 
 int32_t t;
 cin>>t;
 while(t--){

 memset(visited,0,sizeof(visited));
 memset(level,0,sizeof(level));
string a,b;
cin>>a>>b;
 cout<<bfs(a,b)<<endl;
}

 
      return 0;
  }
