#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;
void printBFS(vector<int> adjList[],int v,int s)
{
  bool visited[v];
  queue<int> q;
  memset(visited,false,sizeof(visited));
  visited[s]=true;
  q.push(s);
  while (!q.empty())
  {
      int curr = q.front();
      cout<<curr<<" ";
      q.pop();
      for(int i=0;i<adjList[curr].size();i++)
      {
          if(!visited[adjList[curr][i]])
          {
              q.push(adjList[curr][i]);
              visited[adjList[curr][i]]=true;
          }
      }
  }
}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<int> adjList [v];
    int x,y;
    for(int i=0;i<e;i++)
    {
      cin>>x>>y;
      adjList[x].push_back(y);
      adjList[y].push_back(x);
    }
    printBFS(adjList,v,0);
    return 0;
}