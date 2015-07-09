#include<iostream>
#include<cstring>
using namespace std;
int main (){
    const int HIGHT=24,WIDTH=18;
    int GameSpace[HIGHT][WIDTH];
    memset(GameSpace,0,sizeof(GameSpace));
    for(int i=0;i<HIGHT;++i){
        for(int j=0;j<WIDTH;++j){
            GameSpace[i][j]=0;
        }
    }
    /*for(int i=1;i<HIGHT-1;++i){
        for(int j=1;j<WIDTH-1;++j){
            cout<<GameSpace[i][j]<<" ";
        }
        cout<<endl;
    }*/
    for(int i=0;i<HIGHT;++i){
        for(int j=0;j<WIDTH;++j){
            if(0==i||0==j||HIGHT-1==i||WIDTH-1==j){
                GameSpace[i][j]=1;
            }
        }
    }
    for(int i=0;i<HIGHT;++i){
        for(int j=0;j<WIDTH;++j){
            cout<<GameSpace[i][j]<<" ";
        }
        cout<<endl;
    }
}
