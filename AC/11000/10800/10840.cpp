#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


typedef pair<int,int> pii;
typedef long long int lld;

const lld MOD = 100000007;
const lld p1 = 1511,p2 = 1531;
lld ex1[27],ex2[27];
string a,b;
vector<int> hashed1(MOD/32+1,0),hashed2(MOD/32+1,0);

int ans;
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>a>>b;
    if(a.length()<b.length()) swap(a,b);
    int al=a.length(),bl=b.length();

    vector<int> A(al),B(bl);
    for(int i=0;i<al;i++) A[i]=a[i]-'a';
    for(int i=0;i<bl;i++) B[i]=b[i]-'a';

    ex1[0]=ex2[0]=1;
    for(int i=1;i<26;i++){
        ex1[i]=ex1[i-1]*p1%MOD;
        ex2[i]=ex2[i-1]*p2%MOD;
    }
    
    for(int l=bl;l>0;l--){
        lld h1,h2;
        h1=h2=0;
        vector<lld> s1,s2;
        s1.clear(); s2.clear();
        for(int i=0;i<l;i++){
            h1=(h1+ex1[A[i]])%MOD;
            h2=(h2+ex2[A[i]])%MOD;
        }
        for(int i=0;l+i<=al;i++){
            hashed1[h1/32]|=1<<(h1%32);
            hashed2[h2/32]|=1<<(h2%32);
            s1.push_back(h1);
            s2.push_back(h2);
            if(i+l<al){
                h1=(h1+ex1[A[i+l]]-ex1[A[i]]+MOD)%MOD;
                h2=(h2+ex2[A[i+l]]-ex2[A[i]]+MOD)%MOD;
            }
        } h1=h2=0;
        for(int i=0;i<l;i++){
            h1=(h1+ex1[B[i]])%MOD;
            h2=(h2+ex2[B[i]])%MOD;
        }
        for(int i=0;l+i<=bl;i++){
            if(hashed1[h1/32]&(1<<h1%32) && hashed2[h2/32]&(1<<h2%32)){
                cout<<l;
                return 0;
            }
            if(i+l<bl){
                h1=(h1+ex1[B[i+l]]-ex1[B[i]]+MOD)%MOD;
                h2=(h2+ex2[B[i+l]]-ex2[B[i]]+MOD)%MOD;
            }
        }
        for(int i=0;i+l<=al;i++){
            hashed1[s1[i]/32]&= ~(1<<(s1[i]%32));
            hashed2[s2[i]/32]&= ~(1<<(s2[i]%32));
        }
    }
    cout<<0;
}