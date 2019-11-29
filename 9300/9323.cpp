#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
#define mp make_pair
using pii = pair<int,int>;
using pdi = pair<double,int>;
using pid = pair<int,double>;
using pidi = pair<int,pdi>;
const double INF = 987654321.0;
struct Edge{
    int to,w,p;
    Edge(){}
    Edge(int _to,int _p,int _w):to(_to),p(_p),w(_w){}
};
int N,M,S,P,Y,ST,E;
double d[2][202];
double dist[202];
vector<Edge> adj[202];
int main(){
    int C; cin>>C;
    while(C--){
        cin>>N>>M>>ST>>E>>S>>P>>Y;
        fill(d[0],d[0]+N+1,INF);
        fill(d[1],d[1]+N+1,INF);
        fill(dist,dist+N+1,INF);
        for(int i=0;i<=N;i++) adj[i].clear();
        for(int a,b,p,w,i=0;i<M;i++){
            scanf("%d%d%d%d",&a,&b,&p,&w);
            adj[a].push_back(Edge(b,p,w));
            adj[b].push_back(Edge(a,p,w));
        }
        priority_queue<pdi,vector<pdi>,greater<pdi>> pq;
        pq.push({0.0,ST});
        d[0][ST]=double(S);
        d[1][ST]=0;
        dist[ST]=0;
        int here;
        double c;
        while(!pq.empty()){
            tie(c,here) = pq.top(); pq.pop();
            if(here==E){
                printf("%.2lf\n",c);
                break;
            }
            if(dist[here] < c) continue;
            for(Edge ne:adj[here]){
                int v = ne.to;
                d[0][v] = min(d[0][v],min(d[0][here],d[1][here]+S)+ne.w*P);
                d[1][v] = min(d[1][v],min(d[0][here],d[1][here])+(ne.w*P+Y)*ne.p/100.0);
                double w = min(d[0][v],d[1][v]);
                if(w < dist[v]){
                    dist[v] = w;
                    pq.push({w,v});
                }
            }
        }
    }
}