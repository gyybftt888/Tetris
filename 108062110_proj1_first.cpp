#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

#define MAX_HEIGHT 16
#define MAX_WIDTH 41


class board;
class blocks;
class point;

class board :public blocks {
private:
    int cur_board[MAX_HEIGHT][MAX_WIDTH];
public:
    board(int row, int column) {
        for (int i = 0; i < MAX_HEIGHT; i++)
            for (int j = 0; j < MAX_WIDTH; j++) {
                if (i > 0 && i <= row && j > 0 && j <= column)
                    cur_board[i][j] = 0;		//0 = empty
                else cur_board[i][j] = -1;		//-1 = wall
            }
    }
    void upboard(string shape, int start_col, int move) {
        getblocks(shape);
    }


    blocks*
};

class blocks {
private:
    int t1[4][4] = {
        {0,0,0,0},
        {0,0,0,0},
        {1,1,1,0},
        {0,1,0,0}
    }, t2[4][4] = {
        {0,0,0,0},
        {0,1,0,0},
        {1,1,0,0},
        {0,1,0,0}
    }, t3[4][4] = {
        {0,0,0,0},
        {0,0,0,0},
        {0,1,0,0},
        {1,1,1,0}
    }, t4[4][4] = {
        {0,0,0,0},
        {1,0,0,0},
        {1,1,0,0},
        {1,0,0,0}
    }, l1[4][4] = {
        {0,0,0,0},
        {1,0,0,0},
        {1,0,0,0},
        {1,1,0,0}
    }, l2[4][4] = {
        {0,0,0,0},
        {0,0,0,0},
        {1,1,1,0},
        {1,0,0,0}
    }, l3[4][4] = {
        {0,0,0,0},
        {1,1,0,0},
        {0,1,0,0},
        {0,1,0,0}
    }, l4[4][4] = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,1,0},
        {1,1,1,0}
    }, j1[4][4] = {
        {0,0,0,0},
        {0,1,0,0},
        {0,1,0,0},
        {1,1,0,0}
    }, j2[4][4] = {
        {0,0,0,0},
        {0,0,0,0},
        {1,0,0,0},
        {1,1,1,0}
    }, j3[4][4] = {
        {0,0,0,0},
        {1,1,0,0},
        {1,0,0,0},
        {1,0,0,0}
    }, j4[4][4] = {
        {0,0,0,0},
        {0,0,0,0},
        {1,1,1,0},
        {0,0,1,0}
    }, s1[4][4] = {
        {0,0,0,0},
        {0,0,0,0},
        {0,1,1,0},
        {1,1,0,0}
    }, s2[4][4] = {
        {0,0,0,0},
        {1,0,0,0},
        {1,1,0,0},
        {0,1,0,0}
    }, z1[4][4] = {
        {0,0,0,0},
        {0,0,0,0},
        {1,1,0,0},
        {0,1,1,0}
    }, z2[4][4] = {
        {0,0,0,0},
        {0,1,0,0},
        {1,1,0,0},
        {1,0,0,0}
    }, i1[4][4] = {
        {1,0,0,0},
        {1,0,0,0},
        {1,0,0,0},
        {1,0,0,0}
    }, i2[4][4] = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {1,1,1,1}
    }, o[4][4] = {
        {0,0,0,0},
        {0,0,0,0},
        {1,1,0,0},
        {1,1,0,0}
    };
    
public:
    point* getblocks(string shape) {

    }
};

class point
{int x, y;}a[4], b[4];

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
    board b(m, n);
    string shape;
    int start_col, move;
    while (true) {
        infile >> shape;
        if (shape == "End")
            break;
        infile >> start_col;
        infile >> move;
        b.upboard(shape, start_col, move);
    }
	return 0;
}