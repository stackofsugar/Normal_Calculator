#include <algorithm>
#include <iostream>
#include <limits>
#include <math.h>
#include <string>
#define hardLimit 2147483646
using namespace std;

void cleanbuf(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
}

template<typename Ty>
Ty input(Ty floor = 0, Ty ceil = hardLimit){
    Ty buffer;
    while(1){
        if(cin >> buffer){
            if(buffer < floor){
                cout << "Your input was too small! Try again: \n";
            } else if(buffer > ceil){
                cout << "Your input was too big! Try again: \n";
            } else {
                return buffer;
            }
        } else {
            cout << "Invalid input! Please try again: \n";
            cleanbuf();
        }
    }
}

float grabZarea(float zVvalue); // Moved below for goodness sake.

float findZvalue(float x, float mean, float stddev){
    return ((x - mean) / stddev);
}

int main() {
    int opndone = 1;
    cout << "Normal Distribution Calculator \n(C) 2020 Christopher Digno \n";

    while(opndone){
        cout << "Choose your desired operation! \n1. a < X < b \n2. X > a \n3. X < a \n> ";
        int opChoice = input<int>(1,3);
        float dataint[4], ans, resbuf1, resbuf2;

        if(opChoice == 1){
            cout << "Enter a <space> b <space> mean <space> stddev | a < b \n> ";
            for(int i = 0; i < 4; i++){
                dataint[i] = input<float>();
            }
            //     a             b             mean           stddev
            if(dataint[0] >= dataint[1]){ // dataint[2]     dataint[3]
                cout << "a can't be higher or as same as b!\n";
            }
            else {
                resbuf1 = grabZarea(findZvalue(dataint[0],dataint[2],dataint[3]));
                resbuf2 = grabZarea(findZvalue(dataint[1],dataint[2],dataint[3]));
                if((dataint[0] < dataint[2]) && (dataint[1] < dataint[2])){
                    ans = resbuf1 - resbuf2;
                }
                else if((dataint[0] > dataint[2]) && (dataint[1] > dataint[2])){
                    ans = resbuf2 - resbuf1;
                }
                else {
                    ans = resbuf1 + resbuf2;
                }
            }
        }
        else if(opChoice == 2){ // X > a
            cout << "Enter a <space> mean <space> stddev\n> ";
            for(int i = 0; i < 3; i++){
                dataint[i] = input<float>();
            }
            resbuf1 = grabZarea(findZvalue(dataint[0],dataint[1],dataint[2]));
            if(dataint[0] < dataint[1]){
                ans = resbuf1 + 0.5f;
            }
            else {
                ans = 0.5f - resbuf1;
            }
        }
        else { // X < a
            cout << "Enter a <space> mean <space> stddev\n> ";
            for(int i = 0; i < 3; i++){
                dataint[i] = input<float>();
            }
            resbuf1 = grabZarea(findZvalue(dataint[0],dataint[1],dataint[2]));
            if(dataint[0] < dataint[1]){
                ans = 0.5f - resbuf1;
            }
            else {
                ans = resbuf1 + 0.5f;
            }
        }
        cout << "Calculation returned: " << ans << endl;
        cout << "Do you want to do the operation again? (0/1) \n> ";
        opndone = input<int>(0,1);
    }
}

/*
  @return -1 in exceptions   
*/
float grabZarea(float zvalue){ // Basis of 0 to z
    float zareas[40][10] = 
    {   /*  0        1        2        3        4        5        6        7        8        9  */
        {0.00000, 0.00399, 0.00798, 0.01197, 0.01595, 0.01994, 0.02392, 0.02790, 0.03188, 0.03586},  // 0.0
        {0.03983, 0.04380, 0.04776, 0.05172, 0.05567, 0.05962, 0.06356, 0.06749, 0.07142, 0.07535},  // 0.1
        {0.07926, 0.08317, 0.08706, 0.09095, 0.09483, 0.09871, 0.10257, 0.10642, 0.11026, 0.11409},  // 0.2
        {0.11791, 0.12172, 0.12552, 0.12930, 0.13307, 0.13683, 0.14058, 0.14431, 0.14803, 0.15173},  // 0.3
        {0.15542, 0.15910, 0.16276, 0.16640, 0.17003, 0.17364, 0.17724, 0.18082, 0.18439, 0.18793},  // 0.4
        {0.19146, 0.19497, 0.19847, 0.20194, 0.20540, 0.20884, 0.21226, 0.21566, 0.21904, 0.22240},  // 0.5
        {0.22575, 0.22907, 0.23237, 0.23565, 0.23891, 0.24215, 0.24537, 0.24857, 0.25175, 0.25490},  // 0.6
        {0.25804, 0.26115, 0.26424, 0.26730, 0.27035, 0.27337, 0.27637, 0.27935, 0.28230, 0.28524},  // 0.7
        {0.28814, 0.29103, 0.29389, 0.29673, 0.29955, 0.30234, 0.30511, 0.30785, 0.31057, 0.31327},  // 0.8
        {0.31594, 0.31859, 0.32121, 0.32381, 0.32639, 0.32894, 0.33147, 0.33398, 0.33646, 0.33891},  // 0.9
        {0.34134, 0.34375, 0.34614, 0.34849, 0.35083, 0.35314, 0.35543, 0.35769, 0.35993, 0.36214},  // 1.0
        {0.36433, 0.36650, 0.36864, 0.37076, 0.37286, 0.37493, 0.37698, 0.37900, 0.38100, 0.38298},  // 1.1
        {0.38493, 0.38686, 0.38877, 0.39065, 0.39251, 0.39435, 0.39617, 0.39796, 0.39973, 0.40147},  // 1.2
        {0.40320, 0.40490, 0.40658, 0.40824, 0.40988, 0.41149, 0.41308, 0.41466, 0.41621, 0.41774},  // 1.3
        {0.41924, 0.42073, 0.42220, 0.42364, 0.42507, 0.42647, 0.42785, 0.42922, 0.43056, 0.43189},  // 1.4
        {0.43319, 0.43448, 0.43574, 0.43699, 0.43822, 0.43943, 0.44062, 0.44179, 0.44295, 0.44408},  // 1.5
        {0.44520, 0.44630, 0.44738, 0.44845, 0.44950, 0.45053, 0.45154, 0.45254, 0.45352, 0.45449},  // 1.6
        {0.45543, 0.45637, 0.45728, 0.45818, 0.45907, 0.45994, 0.46080, 0.46164, 0.46246, 0.46327},  // 1.7
        {0.46407, 0.46485, 0.46562, 0.46638, 0.46712, 0.46784, 0.46856, 0.46926, 0.46995, 0.47062},  // 1.8
        {0.47128, 0.47193, 0.47257, 0.47320, 0.47381, 0.47441, 0.47500, 0.47558, 0.47615, 0.47670},  // 1.9
        {0.47725, 0.47778, 0.47831, 0.47882, 0.47932, 0.47982, 0.48030, 0.48077, 0.48124, 0.48169},  // 2.0
        {0.48214, 0.48257, 0.48300, 0.48341, 0.48382, 0.48422, 0.48461, 0.48500, 0.48537, 0.48574},  // 2.1
        {0.48610, 0.48645, 0.48679, 0.48713, 0.48745, 0.48778, 0.48809, 0.48840, 0.48870, 0.48899},  // 2.2
        {0.48928, 0.48956, 0.48983, 0.49010, 0.49036, 0.49061, 0.49086, 0.49111, 0.49134, 0.49158},  // 2.3
        {0.49180, 0.49202, 0.49224, 0.49245, 0.49266, 0.49286, 0.49305, 0.49324, 0.49343, 0.49361},  // 2.4
        {0.49379, 0.49396, 0.49413, 0.49430, 0.49446, 0.49461, 0.49477, 0.49492, 0.49506, 0.49520},  // 2.5
        {0.49534, 0.49547, 0.49560, 0.49573, 0.49585, 0.49598, 0.49609, 0.49621, 0.49632, 0.49643},  // 2.6
        {0.49653, 0.49664, 0.49674, 0.49683, 0.49693, 0.49702, 0.49711, 0.49720, 0.49728, 0.49736},  // 2.7
        {0.49744, 0.49752, 0.49760, 0.49767, 0.49774, 0.49781, 0.49788, 0.49795, 0.49801, 0.49807},  // 2.8
        {0.49813, 0.49819, 0.49825, 0.49831, 0.49836, 0.49841, 0.49846, 0.49851, 0.49856, 0.49861},  // 2.9
        {0.49865, 0.49869, 0.49874, 0.49878, 0.49882, 0.49886, 0.49889, 0.49893, 0.49896, 0.49900},  // 3.0
        {0.49903, 0.49906, 0.49910, 0.49913, 0.49916, 0.49918, 0.49921, 0.49924, 0.49926, 0.49929},  // 3.1
        {0.49931, 0.49934, 0.49936, 0.49938, 0.49940, 0.49942, 0.49944, 0.49946, 0.49948, 0.49950},  // 3.2
        {0.49952, 0.49953, 0.49955, 0.49957, 0.49958, 0.49960, 0.49961, 0.49962, 0.49964, 0.49965},  // 3.3
        {0.49966, 0.49968, 0.49969, 0.49970, 0.49971, 0.49972, 0.49973, 0.49974, 0.49975, 0.49976},  // 3.4
        {0.49977, 0.49978, 0.49978, 0.49979, 0.49980, 0.49981, 0.49981, 0.49982, 0.49983, 0.49983},  // 3.5
        {0.49984, 0.49985, 0.49985, 0.49986, 0.49986, 0.49987, 0.49987, 0.49988, 0.49988, 0.49989},  // 3.6
        {0.49989, 0.49990, 0.49990, 0.49990, 0.49991, 0.49991, 0.49992, 0.49992, 0.49992, 0.49992},  // 3.7
        {0.49993, 0.49993, 0.49993, 0.49994, 0.49994, 0.49994, 0.49994, 0.49995, 0.49995, 0.49995},  // 3.8
        {0.49995, 0.49995, 0.49996, 0.49996, 0.49996, 0.49996, 0.49996, 0.49996, 0.49997, 0.49997}   // 3.9
    };

    float lookupArray[41] =
    {
        0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9,
        1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9,
        2.0, 2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9,
        3.0, 3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7, 3.8, 3.9, 4.0f
    };

    zvalue = roundf(zvalue * 100) / 100;

    if(zvalue < 0){                         // Bunch of ...
        zvalue *= -1;
        if(zvalue < 0){
            cerr << "Error correcting Z-value! \n";
            return -1.0f;
        }
    }
    if(zvalue > 3.999f){
        cerr << "Z-value can't be more than 3.99..! \n";
        return -1.0f;
    }                                       // ... error checking
    else {
        for(int i = 0; i < 41; i++){        // Just imagine that i is an index
            if(zvalue < lookupArray[i]){
                i--;
                for(int j = 0; j <= 10; j++){ // And j too, an index
                    if ( zvalue < (lookupArray[i] + (float)(j / 100.0f)) ){
                        j--;
                        return zareas[i][j];
                    }
                }
                cerr << "Something went wrong! > zvalue-not-found \n";
                return -1.0f;
            }
        }
    }
    cerr << "Something went wrong! > z-function-reaches-end \n";
    return -1.0f;
}