#include"graph.h"
#include<unistd.h>
void Gbase::printGraph(const Colors &GraphColor){
    CubePoint point;
    for(int i=x;i<x+4;++i){
        for(int j=y;j<y+4;++j){
            if(1==address[i-x][j-y]){
                point.setLocate(i,j);
                point.setColor(GraphColor);
                point.printPoint();
            }
        }
    }
}
int Gbase::move(const Control &dir){
    switch(dir){
        case Control::DOWN:
            ++x;
            break;
        case Control::LEFT:
            --y;
            break;
        case Control::RIGHT:
            ++y;
            break;
        default:
            break;
    }
    return 0;
}
bool Gbase::roll(){
    int temp[4][4];
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            temp[j][3-i]=address[i][j];
        }
    }
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            address[i][j]=temp[i][j];
        }    
    }
    ++round;
    round=round%4;
    return true;
}


int main (){
    Context c('L');
    c.draw();
    c.setLocate(5,5);
    auto a=Colors::BLUE;
    system("clear");
    c.printGraph(a);
    return 0;
}

