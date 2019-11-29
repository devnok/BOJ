#include<iostream>
#include<string>
#include<map>
#include<stdlib.h>
#include<sstream>
#include<cmath>
#include<set>
using namespace std;

using ll = long long;
using pii = pair<ll,ll>;
map<string,pii> M;
map<string,ll> oil;
ll dis(string s,string e){
    pii a=M[s],b=M[e];
    return abs(a.first-b.first)+abs(a.second-b.second);
}
int main(){
    ll a,b,c,n,k,money;
    string s,here;
    multimap<string,ll> host;
    getline(cin,s);
    stringstream ss1(s);
    ss1>>a>>b>>c;
    getline(cin,s);
    n=stoi(s);
    for(ll x,y,i=0,j;i<n;i++){
        j=0;
        getline(cin,s);
        while(isalpha(s[j])||s[j]=='\''||s[j]==' ') j++;
        stringstream ss(s.substr(j));
        ss>>x>>y;
        M[s.substr(0,j-1)] = {x,y};
    }
    for(ll p,i=0,j=0;i<3;i++){
        j=0;
        getline(cin,s);
        while(isalpha(s[j])||s[j]=='\''||s[j]==' ') j++;
        oil[s.substr(0,j-1)] = stoi(s.substr(j-1));
    }
    ll d=1;
    for(auto i:oil) d*=i.second;
    ll A=a*c*d;
    here = "Taxi Garage";
    getline(cin,s);
    k=stoi(s);
    while(k--){
        getline(cin,s);
        if(s[0]=='G'){
            s = s.substr(6); s = s.substr(0,s.size()-1);
            ll dist = dis(here,s);
            A-=dist*d;
            if(A<0){
                puts("OUT OF GAS");
                return 0;
            }
            for(auto it=host.begin();it!=host.end();++it) it->second += dist;
            auto it = host.find(s);
            while(it != host.end()){
                money += it->second * b * c * d;
                host.erase(it);
                it = host.find(s);
            }
            if(oil.find(s) != oil.end()){
                ll cost = (a*c*d-A)*oil[s];
                cost -= cost%(c*d);
                if(cost <= money) money-=cost, A=a*c*d;
                else A+=(money/oil[s]),money=0;
            }
            here = s;
        } else {
            s = s.substr(28); s = s.substr(0,s.size()-1);
            host.insert({s,0});
            if(host.size() > 3){
                puts("CAPACITY FULL");
                return 0;
            }
        }
        //cout<<A<<" "<<money<<" "<<here<<endl;
    }
    if(here != "Taxi Garage"){
        puts("NOT IN GARAGE");
    } else if(!host.empty()){
        puts("REMAINING PASSENGER");
    } else {
        cout<<money/c/d;
    }
}