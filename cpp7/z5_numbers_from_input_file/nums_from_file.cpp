#include <iostream>
#include <fstream>

using namespace std;

int MAX_NUM_LENGTH = 32;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "[ERROR] First params should be path to file!\n";
        return -1;
    }

    string filename = argv[1];
    ifstream myInputFile(filename);
    char c;

    char num[MAX_NUM_LENGTH + 1];
    int numId = 0;

    while (myInputFile.get(c)) {
        if (c >= '0' && c <= '9') {
            num[numId++] = c;
        } else {
            if (numId > 0) {
                num[numId] = '\0';
                cout << "liczba: " << num << endl;

                numId = 0;
                num[numId] = '\0';
            }
        }
    }

    return 0;
}
