#include "include/color.h"

char coresToChar(Cores a){
    switch (a) {
        case R:
            return 'R';
        case G:
            return 'G';
        case B:
            return 'B';
        case Y:
            return 'Y';
        case P:
            return 'P';
        case W:
            return 'W';
    }
}