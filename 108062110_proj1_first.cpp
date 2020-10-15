#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

#define MAX_HEIGHT 25
#define MAX_WIDTH 50

void initboard(int, int);
void erase(int);
void newblock(int, int);
bool isempty();
void upboard(int);

int cur_board[MAX_HEIGHT][MAX_WIDTH];
int m, n;
int type;
int x[4], y[4];

int block[20][4][4] = {         //[k][3][0] is reference point
/**********
0 ~ 3 = T
4 ~ 7 = L
8 ~ 11 = J
12 ~ 13 = S
14 ~ 15 = Z
16 ~ 17 = I
18 = O
**********/
{           
    {0,0,0,0},
    {0,0,0,0},
    {1,1,1,0},
    {0,1,0,0}
},
{
    {0,0,0,0},
    {0,1,0,0},
    {1,1,0,0},
    {0,1,0,0}
},
{
    {0,0,0,0},
    {0,0,0,0},
    {0,1,0,0},
    {1,1,1,0}
},
{
    {0,0,0,0},
    {1,0,0,0},
    {1,1,0,0},
    {1,0,0,0}
},
{
    {0,0,0,0},
    {1,0,0,0},
    {1,0,0,0},
    {1,1,0,0}
},
{
    {0,0,0,0},
    {0,0,0,0},
    {1,1,1,0},
    {1,0,0,0}
},
{
    {0,0,0,0},
    {1,1,0,0},
    {0,1,0,0},
    {0,1,0,0}
},
{
    {0,0,0,0},
    {0,0,0,0},
    {0,0,1,0},
    {1,1,1,0}
},
{
    {0,0,0,0},
    {0,1,0,0},
    {0,1,0,0},
    {1,1,0,0}
},
{
    {0,0,0,0},
    {0,0,0,0},
    {1,0,0,0},
    {1,1,1,0}
},
{
    {0,0,0,0},
    {1,1,0,0},
    {1,0,0,0},
    {1,0,0,0}
},
{
    {0,0,0,0},
    {0,0,0,0},
    {1,1,1,0},
    {0,0,1,0}
},
{
    {0,0,0,0},
    {0,0,0,0},
    {0,1,1,0},
    {1,1,0,0}
},
{
    {0,0,0,0},
    {1,0,0,0},
    {1,1,0,0},
    {0,1,0,0}
},
{
    {0,0,0,0},
    {0,0,0,0},
    {1,1,0,0},
    {0,1,1,0}
},
{
    {0,0,0,0},
    {0,1,0,0},
    {1,1,0,0},
    {1,0,0,0}
},
{
    {1,0,0,0},
    {1,0,0,0},
    {1,0,0,0},
    {1,0,0,0}
},
{
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {1,1,1,1}
},
{
    {0,0,0,0},
    {0,0,0,0},
    {1,1,0,0},
    {1,1,0,0}
} };

void initboard(int row, int column) {
    for (int i = 0; i < MAX_HEIGHT; i++)
        for (int j = 0; j < MAX_WIDTH; j++) {
            if (i > 0 && i <= row + 4 && j > 0 && j <= column)
                cur_board[i][j] = 0;	    	//0 = empty
            else cur_board[i][j] = -1;	    	//-1 = wall
        }
}

void erase(int r) {
    int full = 1;
    for (int j = 1; j <= n; j++)
        if (cur_board[r][j] == 0)
            full = 0;
    if (full) {
        for (int i = 0; i < r - 1; i++)
            for (int j = 1; j <= n; j++)
                cur_board[r - i][j] = cur_board[r - i - 1][j];
        for (int j = 1; j <= n; j++)
            cur_board[1][j] = 0;
    }
}

void newblock(int start_col, int move) {
    /******************************************
    layer1 type = 17
    layer2 type = 0, 2, 5, 7, 9, 11, 12, 14, 18
    layer3 type = 1, 3, 4, 6, 8, 10, 13, 15
    layer4 type = 16
    ******************************************/
    if (type == 17) {
        for (int j = 0; j < 4; j++)
            y[j] = 1, x[j] = start_col + j;
        upboard(move);
    }
    else if (type == 0 || type == 2 || type == 5 || type == 7 || type == 9 || type == 11 || type == 12 || type == 14 || type == 18) {
        int idx = 0;
        for (int i = 2; i < 4; i++)
            for (int j = 0; j < 3; j++)
                if (block[type][i][j])
                    y[idx] = i - 1, x[idx++] = start_col + j;
        upboard(move);
    }
    else if (type == 1 || type == 3 || type == 4 || type == 6 || type == 8 || type == 10 || type == 13 || type == 15) {
        int idx = 0;
        for (int i = 1; i < 4; i++)
            for (int j = 0; j < 2; j++)
                if (block[type][i][j])
                    y[idx] = i, x[idx++] = start_col + j;
        upboard(move);
    }
    else if (type == 16) {
        for (int i = 0; i < 4; i++)
            y[i] = 1 + i, x[i] = start_col;
        upboard(move);
    }
}

bool isempty() {
    for (int i = 0; i < 4; i++)
        if (cur_board[y[i] + 1][x[i]] != 0)return false;
    return true;
}

void upboard(int move) {
    while (isempty()) {
        for (int i = 0; i < 4; i++) {
            y[i]++;
        }
    }
    for (int i = 0; i < 4; i++) {
        x[i] += move;
    }
    while (isempty()) {
        for (int i = 0; i < 4; i++)
            y[i]++;
    }
    for (int i = 0; i < 4; i++) {
        if (cur_board[y[i]][x[i]] == 0) {
            cur_board[y[i]][x[i]] = 1;
            erase(y[i]);
        }
    }
}

int main(int argc, char* argv[]) {
    ifstream infile(argv[1]);               //開啟檔案
    if (!infile) {                          //判斷是否正確開啟檔案
        cout << "Can not open file!\n";
        return 1;
    }
    ofstream outfile;
    infile >> m >> n;
    //cin >> m >> n;
    initboard(m, n);
    string shape;
    int start_col, move;
    while (true) {
        infile >> shape;
        //cin >> shape;
        if (shape == "End") break;
        else if (shape == "T1") type = 0;
        else if (shape == "T2") type = 1;
        else if (shape == "T3") type = 2;
        else if (shape == "T4") type = 3;
        else if (shape == "L1") type = 4;
        else if (shape == "L2") type = 5;
        else if (shape == "L3") type = 6;
        else if (shape == "L4") type = 7;
        else if (shape == "J1") type = 8;
        else if (shape == "J2") type = 9;
        else if (shape == "J3") type = 10;
        else if (shape == "J4") type = 11;
        else if (shape == "S1") type = 12;
        else if (shape == "S2") type = 13;
        else if (shape == "Z1") type = 14;
        else if (shape == "Z2") type = 15;
        else if (shape == "I1") type = 16;
        else if (shape == "I2") type = 17;
        else if (shape == "O") type = 18;
        infile >> start_col;
        infile >> move;
        //cin >> start_col;
        //cin >> move;
        newblock(start_col, move);
    }
    outfile.open("108062110_proj1.final", ios::out);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j < n; j++)
            outfile << cur_board[i + 4][j] << " ";
        outfile << cur_board[i + 4][n] << endl;
    }
    infile.close();
    outfile.close();
    return 0;
}