#include"cur.h"

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

//test for this class
int main (){
    Cur cur;
    system("clear");
    cur.saveCur();
    cur.moveCur(10,5);
    cout<<"**";
    //cout<<"\033[8m";
    cout<<"\033[45;32m        \033[0m";
    cur.resumeCur();
    //cout<<"\033[2J";
    return 0;
}


