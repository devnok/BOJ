#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
    double a,b,c;
    cin>>a>>b>>c;
    double x, next=0;
    do{
        x = next;
        next = x - (a*x+b*sin(x)-c) / (a+b*cos(x));
    }while(abs(next-x)>1e-10);
    printf("%.10f",next);
}