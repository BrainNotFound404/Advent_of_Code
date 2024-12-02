#include <cstdio>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("input");
    vector<int> v1, v2;
    int nr1, nr2;

    while(fin >> nr1 >> nr2) {
        v1.push_back(nr1);
        v2.push_back(nr2);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int diff = 0;
    for(int i = 0; i < v1.size(); i++) {
        diff += abs(v1[i] - v2[i]);
    }

    printf("%d\n", diff);

    return 0;
}