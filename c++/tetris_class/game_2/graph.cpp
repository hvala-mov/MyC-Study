#include"graph.h"
#include<unistd.h>
void Gbase::printGraph(const Colors &GraphColor){
    CubePoint point;
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            if(1==address[i][j]){
                point.setLocate(i+x,j+y);
                point.setColor(GraphColor);
                point.printPoint();
            }
        }
    }
}
void Gbase::ereaseGraph(){
    CubePoint point;
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            if(1==address[i][j]){
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


int main (){
    system("clear");
    //Context c(randChar());
    auto c=make_shared<Context>(randChar());
    c->draw();
    c->setLocate(3,3);
    //auto a=Colors::RED;
    c->printGraph(Colors::RED);
    //cout<<"aaa";
    sleep(2);
    //c->ereaseGraph();
    return 0;
}

