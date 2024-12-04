#include <cstdio>
#include <fstream>
#include <string>

using namespace std;

int main() {

    ifstream fin("input");

    string l1, l2, l3, l4, valid_characters = "XS";
    fin >> l1 >> l2 >> l3;

    long long xmas = 0;

    while(fin >> l4) {
        for(int i = 0; i < l1.size(); i++) {
            if(l1[i] == 'X' || l1[i] == 'S') {
                //printf("%d", i);
                string candidate = string(1, l1[i]) + l2[i] + l3[i] + l4[i];
                if(candidate == "XMAS" || candidate == "SAMX") {
                    //printf("(%d, %d, %d, %d)", i, i, i, i);
                    xmas++;
                }
                if(i < l1.size() - 3) {
                    candidate = l1.substr(i, 4);
                    if(candidate == "XMAS" || candidate == "SAMX") {
                        //printf("(%d, %d, %d, %d)", i, i + 1, i + 2, i + 3);
                        xmas++;
                    }
                    candidate = string(1, l1[i]) + l2[i + 1] + l3[i + 2] + l4[i + 3];
                    if(candidate == "XMAS" || candidate == "SAMX") {
                        //printf("(%d, %d, %d, %d)", i, i + 1, i + 2, i + 3);
                        xmas++;
                    }
                }
                if(i > 2) {
                    candidate = string(1, l1[i]) + l2[i - 1] + l3[i - 2] + l4[i - 3];
                    if(candidate == "XMAS" || candidate == "SAMX") {
                        //printf("(%d, %d, %d, %d)", i, i - 1, i - 2, i - 3);
                        xmas++;
                    }
                }
            }
        }
        //printf("\n");
        //printf("%s\n%s\n%s\n%s\n\n", l1.c_str(), l2.c_str(), l3.c_str(), l4.c_str());
        l1 = l2;
        l2 = l3;
        l3 = l4;
    }
    for(int i = 0; i < l1.size() - 3; i++) {
        string candidate = l1.substr(i, 4);
        if(candidate == "XMAS" || candidate == "SAMX") {
            //printf("(%d, %d, %d, %d a)", i, i + 1, i + 2, i + 3);
            xmas++;
        }
    }
    //printf("\n");
    for(int i = 0; i < l1.size() - 3; i++) {
        string candidate = l2.substr(i, 4);
        if(candidate == "XMAS" || candidate == "SAMX") {
            //printf("(%d, %d, %d, %d)", i, i + 1, i + 2, i + 3);
            xmas++;
        }
    }
    //printf("\n");
    for(int i = 0; i < l1.size() - 3; i++) {
        string candidate = l3.substr(i, 4);
        if(candidate == "XMAS" || candidate == "SAMX") {
            //printf("(%d, %d, %d, %d)", i, i + 1, i + 2, i + 3);
            xmas++;
        }
    }
    //printf("\n");
    printf("%lld\n", xmas);
    return 0;
} 

