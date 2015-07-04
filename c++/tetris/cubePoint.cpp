#include"cubePoint.h"
void CubePoint::printPoint(){
    Cur cur;
    cur.saveCur();
    cur.moveCur(x,y);
    switch(color){
        case BLACK:
            cout<<"\33[40;30m  \033[0m";
            break;
        case RED:
            cout<<"\33[41;31m  \033[0m";
            break;
        case GREEN:
            cout<<"\33[42;32m  \033[0m";
            break;
        case YELLOW:
            cout<<"\33[43;33m  \033[0m";
            break;
        case BLUE:
            cout<<"\33[44;34m  \033[0m";
            break;
        case PURPLE:
            cout<<"\33[45;35m  \033[0m";
            break;
        case DEEP_GREEN:
            cout<<"\33[46;36m  \033[0m";
            break;
        case WHITE:
            cout<<"\33[47;37m  \033[0m";
            break;
        case CLEAR:
            cout<<"\033[8m";
            break;
        default:
            break;
    }
    cur.resumeCur();
}
