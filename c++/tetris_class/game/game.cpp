#include"game.h"

shared_ptr<Game> Game::instance;

shared_ptr<Context> Game::graph;

Game::Game(const initialism&){
    memset(GameSpace,0,sizeof(GameSpace));
    for(int i=0;i<WIDTH;++i){
        for(int j=0;j<HIGHT;++j){
            if(0==i||0==j||HIGHT-1==j||WIDTH-1==i){
                GameSpace[i][j]=1;
            }
        }
    }
}

shared_ptr<Game> Game::creatGame(){
    if(!instance){
        instance=make_shared<Game>(initialism{});
    }
    return instance;
}

void Game::printGameSpace(){
    CubePoint point;
    point.setColor(Colors::BLUE);
    for(int i=0;i<WIDTH;++i){
        for(int j=0;j<HIGHT;++j){
            if(1==GameSpace[i][j]){
                point.setLocate(j,i);
                point.printPoint();
            }
        }
    }
}
char Game::randChar(){
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
            return 'L';
        default:
            return ' ';
    }
}
Colors Game::randColor(){
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
void Game::creatFigure(){
    graph=make_shared<Context>(randChar());      
    //cout<<randChar()<<endl;
    //graph=make_shared<Context>('Z');
    //graph->printGraph(Colors::RED);

}
void Game::printFigure(){
    //graph->printGraph(randColor());
    graph->printGraph(Colors::RED);
}


void* Fun(void *arg){
    shared_ptr<Game> game=Game::creatGame();
    system("clear");
    //system("stty -icanon -echo");
    game->printGameSpace();
    //game->creatFigure();
    //game->printFigure();
    //cout<<"hello,world!"<<endl;
    return ((void*)0);
}

int main (){
    pthread_t pid;
    pthread_create(&pid,NULL,Fun,NULL);
    while(1);
    //system("stty -icanon -echo");
    return 0;
}
