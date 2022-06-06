#include "idiom.h"

int main() {
    int result;
    int end = 1;
    IdiomRead();
    while (end) {
        result = Menu();
        switch (result) {
            case 1:
                //PXY EDITED
                switch(LevelSelection()){
                    case 1:
                        InitMap();
                        while (GameStart()) {}
                        break;
                    case 2:
                        InitMap();
                        while (GameStart2()) {}
                        break;
                }
                //END OF PXY EDITED
                break;
            case 2:
                List();
                break;
            case 3:
                Help();
                break;
            case 4:
                About();
                break;
            case 0:
                end = 0;
                break;
        }
    }
    return 0;
}
