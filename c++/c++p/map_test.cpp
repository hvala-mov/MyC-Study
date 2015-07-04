#include<iostream>
#include<map>
using namespace std;
int main()
{
    map name_score_map;
    name_score_map["LiMin"] = 90;
    name_score_map["ZiLinMi"] = 79;
    name_score_map["BoB"] = 92;
    name_score_map.insert(make_pair("Bing",99));
    name_score_map.insert(make_pair("Albert",86));
    for (map::iterator iter = name_score_map.begin(); iter != name_score_map.end(); ++iter)
    {
        cout << *iter << endl;
    }
    return 0;
}
