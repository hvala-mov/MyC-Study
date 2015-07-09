#include"game.h"

shared_ptr<Game> Game::instance;
//bool Game::FLAG=true;

//Context* Game::graph=nullptr;

Game::Game(const initialism&){
    //memset(GameSpace,0,sizeof(GameSpace));
    /*for(int i=0;i<HIGHT;++i){
        for(int j=0;j<WIDTH;++j){
            GameSpace[i][j]=0;
        }
    }*/
    for(int i=0;i<HIGHT;++i){
        for(int j=0;j<WIDTH;++j){
            if(0==i||0==j||HIGHT-1==i||WIDTH-1==j){
                GameSpace[i][j]=1;
            }
        }
    }
    score.printMessage();
    printGameSpace();
    /*for(int i=0;i<HIGHT;++i){
        for(int j=0;j<WIDTH;++j){
            cout<<GameSpace[i][j]<<" ";
        }
        cout<<endl;
    }*/

}

shared_ptr<Game> Game::creatGame(){
    if(!instance){
        instance=make_shared<Game>(initialism{});
    }
    return instance;
}

void Game::printGameSpace(){
    system("clear");
    CubePoint point;
    point.setColor(Colors::BLUE);
    for(int i=0;i<HIGHT;++i){
        for(int j=0;j<WIDTH;++j){
            if(1==GameSpace[i][j]){
                point.setLocate(i,j);
                point.printPoint();
            }
        }
    }
}//I don't what happied there some problem in printing gamespace

char Game::randChar(){
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
/*Colors Game::randColor(){
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
*/
void Game::creatFigure(){
    //graph=make_shared<Context>(randChar());
    graph=new Context();
    graph->draw();
    graph->printGraph();
    FLAG=false;
}

void Game::moveFigure(const Control &dir){
    if(isLegal(dir)){
        graph->ereaseGraph();
        graph->move(dir);
        graph->printGraph();
    }
}
bool Game::isAttachLeft(){
    int ax,ay;
    int temp[4][4];
    graph->getLocate(ax,ay);
    memcpy(temp,graph->getArray(),sizeof(temp));
    for(int i=3;i>=0;--i){
        for(int j=0;j<4;++j){
            if(temp[i][j]!=0&&GameSpace[i+ax][j+ay-1]!=0){
                return true;
            }
        }
    }
    return false;

    return false;
}
bool Game::isAttachRight(){
    int ax,ay;
    int temp[4][4];
    graph->getLocate(ax,ay);
    memcpy(temp,graph->getArray(),sizeof(temp));
    for(int i=3;i>=0;--i){
        for(int j=3;j>=0;--j){
            if(temp[i][j]!=0&&GameSpace[i+ax][j+ay+1]!=0){
                return true;
            }
        }
    }
    return false;
}
bool Game::isAttachBottom(){
    int ax,ay;
    int temp[4][4];
    graph->getLocate(ax,ay);
    memcpy(temp,graph->getArray(),sizeof(temp));
    /*for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            cout<<temp[i][j]<<" ";
        }
    }
    */
    for(int i=3;i>=0;--i){
        for(int j=0;j<4;++j){
            if(temp[i][j]!=0&&GameSpace[i+1+ax][j+ay]!=0){
                resetRoom();
                FLAG=true;
                return true;
            }
        }
    }
    return false;
}
bool Game::RollRightAvailable(){
    int ax,ay;
    int temp[4][4];
    int temp2[4][4];
    graph->getLocate(ax,ay);
    memcpy(temp,graph->getArray(),sizeof(temp));
    for(int i=3;i>=0;--i){
        for(int j=3;j>=0;--j){
            if(temp[i][j]!=0&&GameSpace[i+ax][j+ay+1]!=0){
                return true;
            }
        }
    }
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            temp2[j][3-i]=temp[i][j];
        }
    }
    for(int i=3;i>=0;--i){
        for(int j=3;j>=0;--j){
            if(temp2[i][j]!=0&&GameSpace[i+ax][j+ay+1]!=0){
                return true;
            }
        }
    }
    return false;
}
bool Game::isLegal(const Control &dir){
    /*
    if(isAttachLeft()){
        return false;
    }
    if(isAttachRight()){
        return false;
    }
    if(isAttachBottom()){
        return false;
    }
    */
    switch(dir){
        case Control::DOWN:
            if(isAttachBottom()){
                return false;
            }
            break;
        case Control::LEFT:
            if(isAttachBottom()){
                return false;
            }
            if(isAttachLeft()){
                return false;
            }
            break;
        case Control::RIGHT:
            if(isAttachBottom()){
                return false;
            }
            if(isAttachRight()){
                return false;
            }
            break;
        case Control::ROLL:
            if(isAttachLeft()){
                return false;
            }
            if(isAttachRight()){
                return false;
            }
            if(isAttachBottom()){
                return false;
            }
            break;
        default:
            break;
    }
    return true;
}

void Game::rollFigure(){
    if(isLegal(Control::ROLL)){
     graph->ereaseGraph();
     graph->roll();
     graph->printGraph();
    }
}
void Game::resetRoom(){
    int ax,ay;
    bool key=true;
    int temp[4][4];
    graph->getLocate(ax,ay);
    memcpy(temp,graph->getArray(),sizeof(temp));
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            if(temp[i][j]!=0){
                GameSpace[i+ax][j+ay]=temp[i][j];
            }
         }
    }
    for(int i=HIGHT-2;i>=0;--i){
        key=true;
        for(int j=1;j<WIDTH-1;++j){
            if(0==GameSpace[i][j]){
                key=false;
                break;
            }
        }
        if(key==true){
            clearRoom(i,ax);
            score.setScore(10);
            score.printMessage();
        }
    }
    
}
void Game::clearRoom(const int &line,const int &top){
    for(int i=1;i<WIDTH-1;++i){
        GameSpace[line][i]=0;
    }
    dropGraph(line,top);  
}
void Game::dropGraph(const int &line,const int &top){
    //cout<<line<<" "<<top;
    for(int i=line-1;i>=top-1;--i){
        for(int j=1;j<WIDTH-1;++j){
            GameSpace[i+1][j]=GameSpace[i][j];
        }
    }
    for(int i=line;i>=1;--i){
        for(int j=1;j<WIDTH-1;++j){
            CubePoint point;
            point.setLocate(i,j);
            point.ereasePoint();
        }
    }
    for(int i=line;i>=1;--i){
        for(int j=1;j<WIDTH-1;++j){
            if(GameSpace[i][j]!=0){
                CubePoint point;
                point.setLocate(i,j);
                point.setColor(Colors(GameSpace[i][j]));
                point.printPoint();
            }
        }
    }
   
}
bool Game::isOver(){
    for(int i=1;i<WIDTH-1;++i){
        if(GameSpace[1][i]!=0){
            return true;
        }
    }
    return false;
}
/*******************************************************************************/
void* Fun(void *arg){
    //system("stty -icanon -echo");
    shared_ptr<Game> game=Game::creatGame();
    //game->creatFigure();
    while(true){
        if(game->isOver()){
            break;
        }
        if(game->flag()){
            game->creatFigure();
        }
        system("stty -icanon -echo");
        auto key=getchar();
        system("stty icanon echo");
        switch(key){
            case 'a':
                game->moveFigure(Control::LEFT);
                break;
            case 'd':
                game->moveFigure(Control::RIGHT);
                break;
            case 'w':
                game->rollFigure();
                break;
            case 's':
                /*
                while(true){
                    if(game->isLegal(Control::DOWN)){
                        game->moveFigure(Control::DOWN);
                    }else{
                        break;
                    }
                }*/
                while(game->isLegal(Control::DOWN)){
                    game->moveFigure(Control::DOWN);
                }
                break;
        }
    }
    //game->moveFigure(Control::DOWN);
    return ((void*)0);
}

int main (){
    pthread_t pid;
    shared_ptr<Game> game=Game::creatGame();
    pthread_create(&pid,NULL,Fun,NULL);
    while(true){
        fflush(stdout);
        usleep(500000);
        game->moveFigure(Control::DOWN);
    }
    //system("stty -icanon -echo");
    return 0;
}
