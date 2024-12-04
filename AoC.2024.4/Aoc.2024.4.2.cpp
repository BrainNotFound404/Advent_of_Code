#include <cstdio>
#include <fstream>
#include <string>

using namespace std;

int main() {
    long long xmas = 0;
    string l1, l2, l3;

    ifstream fin("input");

    fin >> l1 >> l2;

    while(fin >> l3) {
        //printf("%s\n", l1.c_str());
        for(int i = 0; i < l1.size() - 2; i++) {
            if((l1[i] == 'M' || l1[i] == 'S') && (l1[i + 2] == 'M' || l1[i + 2] == 'S') ) {
                string d1 = string(1, l1[i]) + l2[i + 1] + l3[i + 2], d2 = string(1, l1[i + 2]) + l2[i + 1] + l3[i]; 
                //printf("d1: %s d2: %s\n", d1.c_str(), d2.c_str());
                // d comes from diagonal
                if((d1 == "MAS" || d1 == "SAM") && (d2 == "MAS" || d2 == "SAM"))
                    xmas++;
            }
        }

        l1 = l2;
        l2 = l3;
    }

    
    printf("%lld\n", xmas);
    fin.close();
    return 0;
}