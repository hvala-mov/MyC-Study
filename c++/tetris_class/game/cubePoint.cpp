#include"cubePoint.h"
void CubePoint::printPoint(){
    Cur cur;
    cur.saveCur();
    cur.moveCur(x,y);
    switch(color){
        case Colors::BLACK:
            cout<<"\33[40;30m  \033[0m";
            break;
        case Colors::RED:
            cout<<"\33[41;31m  \033[0m";
            break;
        case Colors::GREEN:
            cout<<"\33[42;32m  \033[0m";
            break;
        case Colors::YELLOW:
            cout<<"\33[43;33m  \033[0m";
            break;
        case Colors::BLUE:
            cout<<"\33[44;34m  \033[0m";
            break;
        case Colors::PURPLE:
            cout<<"\33[45;35m  \033[0m";
            break;
        case Colors::DEEP_GREEN:
            cout<<"\33[46;36m  \033[0m";
            break;
        case Colors::WHITE:
            cout<<"\33[47;37m  \033[0m";
            break;
        case Colors::CLEAR:
            cout<<"\033[8m";
            break;
        default:
            break;
    }
    cur.resumeCur();
}

/*
int main (){
    CubePoint p;
    system("clear");
    int i,j,n=20,m=30;
    for(i=0;i<n-1;++i){
        p.setLocate(0,i);
        p.setColor(BLUE);
        p.printPoint();
    }
    for(j=0;i<m;++j){
        p.setLocate(j,i);
        p.setColor(BLUE);
        p.printPoint();
    }

    return 0;
}
*/
