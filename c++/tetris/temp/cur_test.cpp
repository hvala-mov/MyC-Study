#include<iostream>
#include<cstdio>
using namespace std;
int main (){
    //printf(" \033[44;31m\033[4m你好\033[0m");
    for(int i=0;i<10;++i){
        cout<<"\33[2C";
        printf("\33[2C");
    }
    for(int i=0;i<10;++i){
        //cout<<"\33[1B";
        printf("\33[1B");
    }
    return 0;
}
