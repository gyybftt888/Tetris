#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

#define MAX_HEIGHT 16
#define MAX_WIDTH 41

class board
{
private:

public:
    board(string shape, int start_col, int move) {

    }
    int cur_board[MAX_HEIGHT][MAX_WIDTH];
    void initboard(int row, int column) {
        for (int i = 0; i < MAX_HEIGHT; i++)
            for (int j = 0; j < MAX_WIDTH; j++) {
                if (i > 0 && i <= row && j > 0 && j <= column)
                    cur_board[i][j] = 0;		//0 = empty
                else cur_board[i][j] = -1;		//-1 = wall
            }
    }
    blocks*
};

class blocks {
private:
    char[]
public:

};

class point {

};

void error() {
    cout << "Error!\n";
}

int main(int argc, char* argv[]) {
    ifstream infile(argv[1]);       //開啟檔案
    if (!infile) {                  //判斷是否正確開啟檔案
        cout << "Can not open file!\n";
        return 1;
    }

    int m, n;
    infile >> m >> n;
    if (m > 15 || n > 40) {
        error();
        return 1;
    }
    string shape;
    int start_col, move;
    while (true) {
        infile >> shape;
        if (shape == "End")
            break;
        infile >> start_col;
        infile >> move;
        board(shape, start_col, move);
    }
	return 0;
}