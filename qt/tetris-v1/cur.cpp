#include"cur.h"
#include<cstdio>
#include<cstdlib>
void Cur::moveCur(const int &x,const int &y){
    int i=0;
    for(i=0;i<y;++i){
        cout<<"\33[2C";
    }
    for(i=0;i<x;++i){
        cout<<"\33[1B";
    }
}

void Cur::saveCur(){
    cout<<"\33[s";
}

void Cur::resumeCur(){
    cout<<"\33[u";
}
