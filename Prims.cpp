#include<bits/stdc++.h>
using namespace std;

int graph[100][100],n,cost[100],prev[100],visited[100];
void initializeSingleSource(int s)
{
    for(int i=0;i<n;i++)
    {
        cost[i]=10000;
        prev[i]=-1;
        visited[i]=0;
    }
    cost[s]=0;
}

int Extractmin()
{
    int min = 10000,u;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0 && cost[i]<min)
        {
            min=cost[i];
            u=i;
        }
    }
    return u;
}

void relax(int u,int v)
{
    if(cost[v]>graph[u][v] && visited[v]==0)
    {
        cost[v]=graph[u][v];
        prev[v]=u;
    }
}

void prim(int s)
{
    int u;
    initializeSingleSource(s);
    while(1)
    {
        u=Extractmin();
        visited[u]=1;
        for(int v = 0 ;v < n ; v++)
        {
            if(graph[u][v]>0)
            {
                relax(u,v);
            }
        }
        int i;
        for(i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                break;
            }
        }
        if(i==n)
        {
            break;
        }
    }
}

int main()
{
    int e,u,v,w;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        cin>>u>>v>>w;
        graph[u][v]=w;
        graph[v][u]=w;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
    prim(0);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=cost[i];
    }
    cout << "MST = " << ans << endl;
    return 0;
}
