#include"graph.h"
#include<unistd.h>
void Gbase::printGraph(Colors &color){
    CubePoint point;
    for(int i=x;i<x+3;++i){
        for(int j=y;j<y+3;++j){
            if(1==a[i-x][j-y]){
                point.setLocate(i,j);
                point.setColor(color);
                point.printPoint();
            }
        }
    }
}
int Gbase::move(const int &dir){
    switch(dir){
        case DOWN:
            ++x;
            break;
        case LEFT:
            --y;
            break;
        case RIGHT:
            ++y;
            break;
        default:
            break;
    }
    return 0;
}
int Gbase::roll(){
    int temp[3][3];
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            temp[2-j][i]=a[i][j];
        }
    }
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            a[i][j]=temp[i][j];
        }    
    }
    return 0;
}
