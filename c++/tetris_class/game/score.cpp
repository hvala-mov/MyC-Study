#include"score.h"

Score::Score(istream& is){
    is>>player;
    score=0;
}

void Score::printMessage(){
    Cur c;
    CubePoint p;
    p.setLocate(2,19);
    p.setColor(Colors::WHITE);
    p.printPoint();
    
    c.saveCur();
    c.moveCur(2,21);
    cout<<"player:"<<player;
    c.resumeCur();

    p.setLocate(4,19);
    p.setColor(Colors::GREEN);
    p.printPoint();

    c.saveCur();
    c.moveCur(4,21);
    cout<<"score:"<<score;
    c.resumeCur();
}
/*
int main (){
    Score s(cin);
    s.setName("wines");
    s.setScore(1000);
    s.printMessage();
    return 0;
}
*/
