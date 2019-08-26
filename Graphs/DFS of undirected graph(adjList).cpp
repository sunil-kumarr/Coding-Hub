#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;
void printDFS(vector<int> adjList[],bool visited[],int node)
{
  if(!visited[node])
  {
      visited[node]=true;
      cout<<node<<" ";
      for(int i=0;i<adjList[node].size();i++)
      {
          printDFS(adjList,visited,adjList[node][i]);
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
    bool visited[v];
    memset(visited,false,sizeof(visited));
    printDFS(adjList,visited,0);
    return 0;
}