#include <cstdio>
#include <vector>
#include <unordered_map>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("input");
    vector<int> v;
    unordered_map<int, int> map;
    int nr1, nr2;
    
    while(fin >> nr1 >> nr2) {
        v.push_back(nr1);

        if(map.count(nr2))
            map[nr2]++;
        else
            map.insert(make_pair(nr2, 1));
    }

    int sim_score = 0;
    for(int i = 0; i < v.size(); i++) {
        if(map.count(v[i]))
            sim_score += v[i] * map[v[i]];
    }

    printf("%d", sim_score);

    return 0;
}