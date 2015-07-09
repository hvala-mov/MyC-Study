#include"graph.h"
#include<unistd.h>
void Gbase::printGraph(){
    CubePoint point;
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            if(address[i][j]!=0){
                point.setLocate(i+x,j+y);
                point.setColor(Gcolor);
                point.printPoint();
            }
        }
    }
}
void Gbase::ereaseGraph(){
    CubePoint point;
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            if(address[i][j]!=0){
                point.setLocate(i+x,j+y);
                //point.setColor(Colors::BLACK);
                point.ereasePoint();
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
char Context::randChar(){
    switch(Rand::creatRand()->uniform_randNum(0,4)){
        case 0:
            return 'Z';
        case 1:
            return 'T';
        case 2:
            return 'O';
        case 3:
            return 'I';
        case 4:
            return 'L';
        default:
            return ' ';
    }
}
Colors Gbase::randColor(){
    switch(Rand::creatRand()->uniform_randNum(0,5)){
        case 0:
            return Colors::RED;
        case 1:
            return Colors::GREEN;
        case 2:
            return Colors::YELLOW;
        case 3:
            return Colors::WHITE;
        case 4:
            return Colors::PURPLE;
        case 5:
            return Colors::DEEP_GREEN;
        default:
            return Colors::CLEAR;
    }
}
/*
char randChar(){
    switch(Rand::creatRand()->uniform_randNum(0,4)){
        case 0:
            return 'Z';
        case 1:
            return 'T';
        case 2:
            return 'O';
        case 3:
            return 'L';
        case 4:
            return 'I';
        default:
            return ' ';
    }
}

*/

/*
int main (){
    for(int i=0;i<1;i=i+1){
        Context c(randChar());
        c.draw();
        c.setLocate(i,i);
        auto a=Colors::RED;
        c.printGraph(a);
        cout<<i<<endl;
        sleep(2);
        c.ereaseGraph();
        //system("clear");
    }
    system("clear");
        Context c;
        c.draw();
        c.setLocate(3,3);
        //auto a=Colors::RED;
        c.printGraph();
        //cout<<"aaa";
        sleep(2);
        //c.ereaseGraph();
    return 0;
}
*/
