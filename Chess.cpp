#include <bits/stdc++.h>
#include <fcntl.h>
#include <windows.h>

using namespace std;
int time_of_player1 = 0, time_of_player2 = 0;

void gotoxy(short int x, short int y) {                    //卞強高炎
    COORD pos = {x, y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
}


void SetColorAndBackground(int ForgC, int BackC) {
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

void Unic_Print(string chess, string use) {
    _setmode(_fileno(stdout), _O_WTEXT);
    if (use == "White") {
        if (chess == "King") {
            wcout << L'\u2654';
        } else if (chess == "Queen") {
            wcout << L'\u2655';
        } else if (chess == "Rook") {
            wcout << L'\u2656';
        } else if (chess == "Bishop") {
            wcout << L'\u2657';
        } else if (chess == "Knight") {
            wcout << L'\u2658';
        } else if (chess == "Pawn") {
            wcout << L'\u2659';
        }
    } else {
        if (chess == "King") {
            wcout << L'\u265A';
        } else if (chess == "Queen") {
            wcout << L'\u265B';
        } else if (chess == "Rook") {
            wcout << L'\u265C';
        } else if (chess == "Bishop") {
            wcout << L'\u265D';
        } else if (chess == "Knight") {
            wcout << L'\u265E';
        } else if (chess == "Pawn") {
            wcout << L'\u265F';
        }
    }


}

class Timer {
public:
    int s = 30;

    void Print_time() {
        double t_origin = clock();
        while (1) {
            double t_now = clock(), t_minus;
            t_minus = (t_now - t_origin) / 1000;
            if (t_minus >= 1) {
                cout << "00:" << s-- << endl;
                t_origin = t_now;
            }
            if (s < 0)
                break;
        }
    }
};

bool is_chess_here[10][10] = {0};
string index_of_chess[10][10] = {};
string name_chess[6] = {"King", "Queen", "Rook", "Bishop", "Knight", "Pawn"};

class Chess {
public:
    string name, user;
    int loc_x_num, loc_y_char;

    Chess(string n, string u) {
        name = n;
        user = u;
        if (u == "White") {
            if (n == "King") {
                loc_x_num = 1, loc_y_char = 5;
                index_of_chess[1][5] = "King";
            }
            if (n == "Queen") {
                loc_x_num = 1, loc_y_char = 4;
                index_of_chess[1][4] = "Queen";
            }
            if (n == "Rook") {
                if (!is_chess_here[1][1]) {
                    loc_x_num = 1, loc_y_char = 1;
                    is_chess_here[1][1] = 1;
                    index_of_chess[1][1] = "Rook";
                } else {
                    loc_x_num = 1, loc_y_char = 8;
                    is_chess_here[1][8] = 1;
                    index_of_chess[1][8] = "Rook";
                }
            }
            if (n == "Bishop") {
                if (!is_chess_here[1][3]) {
                    loc_x_num = 1, loc_y_char = 3;
                    is_chess_here[1][3] = 1;
                    index_of_chess[1][3] = "Bishop";
                } else {
                    loc_x_num = 1, loc_y_char = 6;
                    is_chess_here[1][6] = 1;
                    index_of_chess[1][6] = "Bishop";
                }
            }
            if (n == "Knight") {
                if (!is_chess_here[1][2]) {
                    loc_x_num = 1, loc_y_char = 2;
                    is_chess_here[1][2] = 1;
                    index_of_chess[1][2] = "Knight";
                } else {
                    loc_x_num = 1, loc_y_char = 7;
                    is_chess_here[1][7] = 1;
                    index_of_chess[1][7] = "Knight";
                }
            }
            if (n == "Pawn") {
                for (int i = 1; i <= 8; i++) {
                    if (!is_chess_here[2][i]) {
                        is_chess_here[2][i] = 1;
                        loc_x_num = 2, loc_y_char = i;

                        index_of_chess[2][i] = "Pawn";
                        break;
                    }
                }
            }
        }
        if (u == "Black") {
            if (n == "King") {
                loc_x_num = 8, loc_y_char = 5;
                index_of_chess[8][5] = "King";
            }
            if (n == "Queen") {
                loc_x_num = 8, loc_y_char = 4;
                index_of_chess[8][4] = "Queen";
            }
            if (n == "Rook") {
                if (!is_chess_here[8][1]) {
                    loc_x_num = 8, loc_y_char = 1;
                    is_chess_here[8][1] = 1;
                    index_of_chess[8][1] = "Rook";
                } else {
                    loc_x_num = 8, loc_y_char = 8;
                    is_chess_here[8][8] = 1;
                    index_of_chess[8][8] = "Rook";
                }
            }
            if (n == "Bishop") {
                if (!is_chess_here[8][3]) {
                    loc_x_num = 8, loc_y_char = 3;
                    is_chess_here[8][3] = 1;
                    index_of_chess[8][3] = "Bishop";
                } else {
                    loc_x_num = 8, loc_y_char = 6;
                    is_chess_here[8][6] = 1;
                    index_of_chess[8][6] = "Bishop";
                }
            }
            if (n == "Knight") {
                if (!is_chess_here[8][2]) {
                    loc_x_num = 8, loc_y_char = 2;
                    is_chess_here[8][2] = 1;
                    index_of_chess[8][2] = "Knight";
                } else {
                    loc_x_num = 8, loc_y_char = 7;
                    is_chess_here[8][7] = 1;
                    index_of_chess[8][7] = "Knight";
                }
            }
            if (n == "Pawn") {
                for (int i = 1; i <= 8; i++) {
                    if (!is_chess_here[7][i]) {
                        loc_x_num = 7, loc_y_char = i;
                        is_chess_here[7][i] = true;
                        index_of_chess[7][i] = "Pawn";
                        break;
                    }
                }
            }
        }
    }

};

void get_back_of_ChessPoint(Chess *Target[10][10], Chess *pos) {
    if (Target[pos->loc_x_num][pos->loc_y_char] == NULL) {
        Target[pos->loc_x_num][pos->loc_y_char] = pos;
    }

}

void min_max_order(int *x, int *y) {
    if (*x > *y) {
        int temp = *y;
        *y = *x;
        *x = temp;
    }
}

class Map {
public:
    Chess *board[10][10] = {{NULL}};
    int Remain_White=16,Remain_Black=16;
    bool White_Control[10][10] = {{0}}, Black_Control[10][10] = {{0}};
    Chess *King_White = new Chess("King", "White");
    Chess *Queen_White = new Chess("Queen", "White");
    Chess *Rook1_White = new Chess("Rook", "White");
    Chess *Rook2_White = new Chess("Rook", "White");
    Chess *Bishop1_White = new Chess("Bishop", "White");
    Chess *Bishop2_White = new Chess("Bishop", "White");
    Chess *Knight1_White = new Chess("Knight", "White");
    Chess *Knight2_White = new Chess("Knight", "White");
    Chess *Pawn1_White = new Chess("Pawn", "White");
    Chess *Pawn2_White = new Chess("Pawn", "White");
    Chess *Pawn3_White = new Chess("Pawn", "White");
    Chess *Pawn4_White = new Chess("Pawn", "White");
    Chess *Pawn5_White = new Chess("Pawn", "White");
    Chess *Pawn6_White = new Chess("Pawn", "White");
    Chess *Pawn7_White = new Chess("Pawn", "White");
    Chess *Pawn8_White = new Chess("Pawn", "White");

    Chess *King_Black = new Chess("King", "Black");
    Chess *Queen_Black = new Chess("Queen", "Black");
    Chess *Rook1_Black = new Chess("Rook", "Black");
    Chess *Rook2_Black = new Chess("Rook", "Black");
    Chess *Bishop1_Black = new Chess("Bishop", "Black");
    Chess *Bishop2_Black = new Chess("Bishop", "Black");
    Chess *Knight1_Black = new Chess("Knight", "Black");
    Chess *Knight2_Black = new Chess("Knight", "Black");
    Chess *Pawn1_Black = new Chess("Pawn", "Black");
    Chess *Pawn2_Black = new Chess("Pawn", "Black");
    Chess *Pawn3_Black = new Chess("Pawn", "Black");
    Chess *Pawn4_Black = new Chess("Pawn", "Black");
    Chess *Pawn5_Black = new Chess("Pawn", "Black");
    Chess *Pawn6_Black = new Chess("Pawn", "Black");
    Chess *Pawn7_Black = new Chess("Pawn", "Black");
    Chess *Pawn8_Black = new Chess("Pawn", "Black");

    Map() {

        get_back_of_ChessPoint(board, King_White);

        get_back_of_ChessPoint(board, King_Black);
        get_back_of_ChessPoint(board, Queen_White);
        get_back_of_ChessPoint(board, Queen_Black);
        get_back_of_ChessPoint(board, Rook1_Black);
        get_back_of_ChessPoint(board, Rook1_White);
        get_back_of_ChessPoint(board, Rook2_Black);
        get_back_of_ChessPoint(board, Rook2_White);
        get_back_of_ChessPoint(board, Bishop1_Black);
        get_back_of_ChessPoint(board, Bishop2_Black);
        get_back_of_ChessPoint(board, Bishop1_White);
        get_back_of_ChessPoint(board, Bishop2_White);
        get_back_of_ChessPoint(board, Knight1_Black);
        get_back_of_ChessPoint(board, Knight1_White);
        get_back_of_ChessPoint(board, Knight2_Black);
        get_back_of_ChessPoint(board, Knight2_White);
        get_back_of_ChessPoint(board, Pawn1_White);
        get_back_of_ChessPoint(board, Pawn1_Black);
        get_back_of_ChessPoint(board, Pawn2_White);
        get_back_of_ChessPoint(board, Pawn2_Black);
        get_back_of_ChessPoint(board, Pawn3_White);
        get_back_of_ChessPoint(board, Pawn3_Black);
        get_back_of_ChessPoint(board, Pawn4_White);
        get_back_of_ChessPoint(board, Pawn4_Black);
        get_back_of_ChessPoint(board, Pawn5_White);
        get_back_of_ChessPoint(board, Pawn5_Black);
        get_back_of_ChessPoint(board, Pawn6_White);
        get_back_of_ChessPoint(board, Pawn6_Black);
        get_back_of_ChessPoint(board, Pawn7_White);
        get_back_of_ChessPoint(board, Pawn7_Black);
        get_back_of_ChessPoint(board, Pawn8_White);
        get_back_of_ChessPoint(board, Pawn8_Black);
//        for (int i=1;i<=8;i++){
//        	for (int j=1;j<=8;j++){
//        		if(board[i][j]!=NULL)
//        		cout<<i<<","<<(char)('A'+j-1)<<","<<board[i][j] -> name<<endl;
//			}
//		}
    }

    void Fresh_Control_Area(string team) {
        for (int i = 1; i <= 10; i++) {
            for (int j = 1; j <= 10; j++) {
                Black_Control[i][j] = false;
                White_Control[i][j] = false;
            }
        }
        if (team == "White") {
            for (int i = 1; i <= 8; i++) {
                for (int j = 1; j <= 8; j++) {


                    if (board[i][j] != NULL && board[i][j]->user == "White") {
                        if (board[i][j]->name == "Pawn") {
                            for (int xx = 1; xx <= 8; xx++) {
                                for (int yy = 1; yy <= 8; yy++) {
                                    if (xx - i == 1 && abs(yy - j) == 1) {
                                        if (board[xx][yy] == NULL)
                                            White_Control[xx][yy] = true;
                                    }
                                }
                            }
                        }
                        if (board[i][j]->name == "Bishop") {
                            for (int xx = 1; xx <= 8; xx++) {
                                for (int yy = 1; yy <= 8; yy++) {
                                    if (!Any_Chess_Front("Bishop", i, j, xx, yy) && (xx - i == yy - j)) {
                                        if (board[xx][yy] == NULL)
                                            White_Control[xx][yy] = true;
                                    }
                                }
                            }
                        }
                        if (board[i][j]->name == "Knight") {
                            for (int xx = 1; xx <= 8; xx++) {
                                for (int yy = 1; yy <= 8; yy++) {
                                    if ((abs(xx - i) == 1 && abs(yy - j) == 2) ||
                                        (abs(xx - i) == 2 && abs(yy - j) == 1)) {
                                        if (board[xx][yy] == NULL)
                                            White_Control[xx][yy] = true;
                                    }
                                }
                            }

                        }
                        if (board[i][j]->name == "Queen") {
                            for (int xx = 1; xx <= 8; xx++) {
                                for (int yy = 1; yy <= 8; yy++) {
                                    if ((xx - i == yy - j) || (xx == i) || (yy == j)) {
                                        if (board[xx][yy] == NULL && !Any_Chess_Front("Queen", i, j, xx, yy))
                                            White_Control[xx][yy] = true;
                                    }
                                }
                            }
                        }
                        if (board[i][j]->name == "King") {
                            for (int xx = 1; xx <= 8; xx++) {
                                for (int yy = 1; yy <= 8; yy++) {
                                    if ((abs(xx - i) <= 1 && abs(yy - j) <= 1)) {
                                        if (board[xx][yy] == NULL)
                                            White_Control[xx][yy] = true;
                                    }
                                }
                            }
                        }
                        if (board[i][j]->name == "Rook") {
                            for (int xx = 1; xx <= 8; xx++) {
                                for (int yy = 1; yy <= 8; yy++) {
                                    if ((!Any_Chess_Front("Rook", i, j, xx, yy)) && (xx == i || yy == j)) {
                                        if (board[xx][yy] == NULL)
                                            White_Control[xx][yy] = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            for (int i = 1; i <= 8; i++) {
                for (int j = 1; j <= 8; j++) {
                    if (board[i][j] != NULL && board[i][j]->user == "Black") {
                        if (board[i][j]->name == "Pawn") {
                            for (int xx = 1; xx <= 8; xx++) {
                                for (int yy = 1; yy <= 8; yy++) {
                                    if (xx - i == -1 && abs(yy - j) == 1) {
                                        if (board[xx][yy] == NULL)
                                            Black_Control[xx][yy] = true;
                                    }
                                }
                            }
                        }
                        if (board[i][j]->name == "Bishop") {
                            for (int xx = 1; xx <= 8; xx++) {
                                for (int yy = 1; yy <= 8; yy++) {
                                    if (!Any_Chess_Front("Bishop", i, j, xx, yy) && (xx - i == yy - j)) {
                                        if (board[xx][yy] == NULL)
                                            Black_Control[xx][yy] = true;
                                    }
                                }
                            }
                        }
                        if (board[i][j]->name == "Knight") {
                            for (int xx = 1; xx <= 8; xx++) {
                                for (int yy = 1; yy <= 8; yy++) {
                                    if ((abs(xx - i) == 1 && abs(yy - j) == 2) ||
                                        (abs(xx - i) == 2 && abs(yy - j) == 1)) {
                                        if (board[xx][yy] == NULL)
                                            Black_Control[xx][yy] = true;
                                    }
                                }
                            }

                        }
                        if (board[i][j]->name == "Queen") {
                            for (int xx = 1; xx <= 8; xx++) {
                                for (int yy = 1; yy <= 8; yy++) {
                                    if ((xx - i == yy - j) || (xx == i) || (yy == j)) {
                                        if (board[xx][yy] == NULL && !Any_Chess_Front("Queen", i, j, xx, yy))
                                            Black_Control[xx][yy] = true;
                                    }
                                }
                            }
                        }
                        if (board[i][j]->name == "King") {
                            for (int xx = 1; xx <= 8; xx++) {
                                for (int yy = 1; yy <= 8; yy++) {
                                    if ((abs(xx - i) <= 1 && abs(yy - j) <= 1)) {
                                        if (board[xx][yy] == NULL)
                                            Black_Control[xx][yy] = true;
                                    }
                                }
                            }
                        }
                        if (board[i][j]->name == "Rook") {
                            if ( (!Any_Chess_Front("Rook", i, j, 3, 1)) &&(3 == i || 1 == j)) {
                                if (board[3][1] == NULL){
                                    Black_Control[3][1] = true;
                                }}
//                            for (int xx = 1; xx <= 8; xx++) {
//                                for (int yy = 1; yy <= 8; yy++) {
//
//                                    if ( (!Any_Chess_Front("Rook", i, j, xx, yy)) &&(xx == i || yy == j)) {
//                                          if (board[xx][yy] == NULL){
//                                            Black_Control[xx][yy] = true;
//                                        }
//
//                                    }wcout<<i<<","<<j<<","<<xx<<","<<yy<<endl;
//                                }
//                            }
                        }
                    }
                }
            }
        }
    }

    bool Check_location_possess(int locx, int locy) {
        if (board[locx][locy] == NULL)
            return false;
        else
            return true;
    }

    void Print_Move_Wrong(string n) {
        cout << n << " can't move like that !\n";
        system("PAUSE");
    }

    bool Any_Chess_Front(string chess_name, int old_x, int old_y, int n_x, int n_y) {
//        cout<<old_x<<","<<old_y<<","<<n_x<<","<<n_y<<endl;
        if (chess_name == "Queen") {
            if (old_x == n_x) {
                min_max_order(&old_y, &n_y);
                for (int i = old_y + 1; i <= n_y; i++) {
                    if (board[old_x][i] != NULL) {
                        if (board[old_x][i]->user == board[old_x][old_y]->user)
                            return true;
                    }
                }
                return false;
            } else if (old_y == n_y) {
                min_max_order(&old_x, &n_x);
                for (int i = old_x + 1; i <= n_x; i++) {
                    if (board[i][old_y] != NULL) {
                        if (board[i][old_y]->user == board[old_x][old_y]->user)
                            return true;
                    }
                }
                return false;
            } else {
                if (old_x < n_x) { //x++
                    if (old_y < n_y) {//y++
                        for (int i = old_x + 1, j = old_y + 1; i <= n_x, j <= n_y; i++, j++) {
                            if (board[i][j] != NULL) {
                                if (board[i][j]->user == board[old_x][old_y]->user)
                                    return true;
                            }
                        }
                        return false;
                    } else {//y--
                        for (int i = old_x + 1, j = old_y - 1; i <= n_x, j >= n_y; i++, j--) {
                            if (board[i][j] != NULL) {
                                if (board[i][j]->user == board[old_x][old_y]->user)
                                    return true;
                            }
                        }
                        return false;
                    }
                } else {//x--
                    if (old_y < n_y) {//y++
                        for (int i = old_x - 1, j = old_y + 1; i >= n_x, j <= n_y; i--, j++) {
                            if (board[i][j] != NULL) {
                                if (board[i][j]->user == board[old_x][old_y]->user)
                                    return true;
                            }
                        }
                        return false;
                    } else {//y--
                        for (int i = old_x - 1, j = old_y - 1; i >= n_x, j >= n_y; i--, j--) {
                            if (board[i][j] != NULL) {
                                if (board[i][j]->user == board[old_x][old_y]->user)
                                    return true;
                            }
                        }
                        return false;
                    }
                }
            }

        } else if (chess_name == "Rook") {
            if (old_x == n_x) {
                min_max_order(&old_y, &n_y);
                for (int i = old_y + 1; i <= n_y; i++) {

                    if (board[old_x][i] != NULL) {
                        if (board[old_x][i]->user == board[old_x][old_y]->user)
                            return true;
                    }

                }
                return false;
            } else if (old_y == n_y) {
                min_max_order(&old_x, &n_x);
                for (int i = old_x + 1; i <= n_x; i++) {
//                    if(old_y==1&&old_x==8&&n_x==3)

                    if (board[i][old_y] != NULL) {
                        if (board[i][old_y]->user == board[old_x][old_y]->user)
                            return true;
                    }
                }
                return false;
            }
        } else if (chess_name == "Bishop") {
            if (old_x < n_x) { //x++
                if (old_y < n_y) {//y++
                    for (int i = old_x + 1, j = old_y + 1; i <= n_x, j <= n_y; i++, j++) {
                        if (board[i][j] != NULL) {
                            if (board[i][j]->user == board[old_x][old_y]->user)
                                return true;
                        }
                    }
                    return false;
                } else {//y--
                    for (int i = old_x + 1, j = old_y - 1; i <= n_x, j >= n_y; i++, j--) {
                        if (board[i][j] != NULL) {
                            if (board[i][j]->user == board[old_x][old_y]->user)
                                return true;
                        }
                    }
                    return false;
                }
            } else {//x--
                if (old_y < n_y) {//y++
                    for (int i = old_x - 1, j = old_y + 1; i >= n_x, j <= n_y; i--, j++) {
                        if (board[i][j] != NULL) {
                            if (board[i][j]->user == board[old_x][old_y]->user)
                                return true;
                        }
                    }
                    return false;
                } else {//y--
                    for (int i = old_x - 1, j = old_y - 1; i >= n_x, j >= n_y; i--, j--) {
                        if (board[i][j] != NULL) {
                            if (board[i][j]->user == board[old_x][old_y]->user)
                                return true;
                        }
                    }
                    return false;
                }
            }
        }
    }

    void move(int x, int y, int new_x, int new_y) {
        if (x > 8 || x < 1 || y > 8 || y < 1) {
            cout << "Error! Location is not exist!";
        }
        string t_name = board[x][y]->name;
        if (t_name == "King") {
            if (new_y - y <= 1 && new_x - x <= 1) {
                if (!Check_location_possess(new_x, new_y)) {
                    board[new_x][new_y] = board[x][y];
                    board[new_x][new_y]->loc_x_num = new_x, board[new_x][new_y]->loc_y_char = new_y;

                    board[x][y] = NULL;
                } else {
                    cout << board[new_x][new_y]->name << " is eaten by King.\n";
                    if (board[new_x][new_y]->user=="White")Remain_White--;
                    else Remain_Black--;

                    board[new_x][new_y] = board[x][y];
                    board[new_x][new_y]->loc_x_num = new_x, board[new_x][new_y]->loc_y_char = new_y;

                    board[x][y] = NULL;
                }
            } else {
                Print_Move_Wrong(t_name);
            }
        }
        if (t_name == "Queen") {
            if (((new_x == x || new_y == y) || (new_x - x == new_y - y)) &&
                !Any_Chess_Front("Queen", x, y, new_x, new_y)) {//can move

                if (!Check_location_possess(new_x, new_y)) {
                    board[new_x][new_y] = board[x][y];
                    board[new_x][new_y]->loc_x_num = new_x, board[new_x][new_y]->loc_y_char = new_y;
                    board[x][y] = NULL;
                } else {
                    cout << board[new_x][new_y]->name << " is eaten by Queen.\n";
                    if (board[new_x][new_y]->user=="White")Remain_White--;
                    else Remain_Black--;

                    board[new_x][new_y] = board[x][y];
                    board[new_x][new_y]->loc_x_num = new_x, board[new_x][new_y]->loc_y_char = new_y;
                    board[x][y] = NULL;
                }
            } else {
                cout << "Queen can't move to there !\n";
            }
        }
        if (t_name == "Rook") {
            if ((new_x == x || new_y == y) && !Any_Chess_Front("Rook", x, y, new_x, new_y)) {
                if (!Check_location_possess(new_x, new_y)) {
                    board[new_x][new_y] = board[x][y];
                    board[new_x][new_y]->loc_x_num = new_x, board[new_x][new_y]->loc_y_char = new_y;
                    board[x][y] = NULL;
                } else {
                    if (board[new_x][new_y]->user=="White")Remain_White--;
                    else Remain_Black--;

                    cout << board[new_x][new_y]->name << " is eaten by Rook.\n";
                    board[new_x][new_y] = board[x][y];
                    board[new_x][new_y]->loc_x_num = new_x, board[new_x][new_y]->loc_y_char = new_y;
                    board[x][y] = NULL;
                }
            } else {
                Print_Move_Wrong(t_name);
            }
        }
        if (t_name == "Bishop") {
            if ((new_x - x == new_y - y) && !Any_Chess_Front("Bishop", x, y, new_x, new_y)) {
                if (!Check_location_possess(new_x, new_y)) {
                    board[new_x][new_y] = board[x][y];
                    board[new_x][new_y]->loc_x_num = new_x, board[new_x][new_y]->loc_y_char = new_y;
                    board[x][y] = NULL;
                } else {
                    if (board[new_x][new_y]->user=="White")Remain_White--;
                    else Remain_Black--;

                    cout << board[new_x][new_y]->name << " is eaten by Bishop.\n";
                    board[new_x][new_y] = board[x][y];
                    board[new_x][new_y]->loc_x_num = new_x, board[new_x][new_y]->loc_y_char = new_y;
                    board[x][y] = NULL;
                }
            } else {
                Print_Move_Wrong(t_name);
            }
        }
        if (t_name == "Knight") {
            if ((abs(new_x - x) == 1 && abs(new_y - y) == 2) || (abs(new_x - x) == 2 && abs(new_y - y) == 1)) {
                if (!Check_location_possess(new_x, new_y)) {
                    board[new_x][new_y] = board[x][y];
                    board[new_x][new_y]->loc_x_num = new_x, board[new_x][new_y]->loc_y_char = new_y;
                    board[x][y] = NULL;
                } else {//eat
                    if (board[new_x][new_y]->user=="White")Remain_White--;
                    else Remain_Black--;

                    cout << board[new_x][new_y]->name;
                    wcout << " is eaten by Knight.\n";
                    board[new_x][new_y] = board[x][y];
                    board[new_x][new_y]->loc_x_num = new_x, board[new_x][new_y]->loc_y_char = new_y;
                    board[x][y] = NULL;
                }
            } else {
                Print_Move_Wrong(t_name);
            }
        }
        if (t_name == "Pawn") {
            if (Check_location_possess(new_x, new_y)) {
                if ((x == 2 || x == 7) && ((board[x][y]->user == "White" && new_x > x && new_x - x <= 2) ||
                                           (board[x][y]->user == "Black" && new_x < x && x - new_x <= 2))) {
                    if (abs(new_x - x) == 1 && abs(new_y - y) == 1) {//eat
                        cout << board[new_x][new_y]->name;
                        if (board[new_x][new_y]->user=="White")Remain_White--;
                        else Remain_Black--;

                        wcout << " is eaten by Pawn.\n";
                        board[new_x][new_y] = board[x][y];
                        board[new_x][new_y]->loc_x_num = new_x, board[new_x][new_y]->loc_y_char = new_y;
                        board[x][y] = NULL;
                    } else if ((board[x][y]->user == "White" && new_x > x && new_x - x == 1 && abs(y - new_y) == 1) ||
                               (board[x][y]->user == "Black" && new_x < x && x - new_x == 1 && abs(y - new_y) == 1)) {
                        if (board[new_x][new_y]->user=="White")Remain_White--;
                        else Remain_Black--;

                        cout << board[new_x][new_y]->name << " is eaten by Pawn.\n";
                        board[new_x][new_y] = board[x][y];
                        board[new_x][new_y]->loc_x_num = new_x, board[new_x][new_y]->loc_y_char = new_y;
                        board[x][y] = NULL;
                    } else Print_Move_Wrong(t_name);
                } else {
                    if (abs(new_x - x) == 1 && abs(new_y - y) == 1) {//eat
                        cout << board[new_x][new_y]->name;
                        if (board[new_x][new_y]->user=="White")Remain_White--;
                        else Remain_Black--;

                        wcout << " is eaten by Pawn.\n";
                        board[new_x][new_y] = board[x][y];
                        board[new_x][new_y]->loc_x_num = new_x, board[new_x][new_y]->loc_y_char = new_y;
                        board[x][y] = NULL;
                    } else if ((board[x][y]->user == "White" && new_x > x && new_x - x == 1 && abs(y - new_y) == 1) ||
                               (board[x][y]->user == "Black" && new_x < x && x - new_x == 1 && abs(y - new_y) == 1)) {
                        if (board[new_x][new_y]->user=="White")Remain_White--;
                        else Remain_Black--;

                        cout << board[new_x][new_y]->name << " is eaten by Pawn.\n";
                        board[new_x][new_y] = board[x][y];
                        board[new_x][new_y]->loc_x_num = new_x, board[new_x][new_y]->loc_y_char = new_y;
                        board[x][y] = NULL;
                    } else Print_Move_Wrong(t_name);
                }
            } else {
                if ((x == 2 || x == 7) && ((board[x][y]->user == "White" && new_x > x && new_x - x <= 2) ||
                                           (board[x][y]->user == "Black" && new_x < x && x - new_x <= 2))) {
                    board[new_x][new_y] = board[x][y];
                    board[new_x][new_y]->loc_x_num = new_x, board[new_x][new_y]->loc_y_char = new_y;
                    board[x][y] = NULL;
                } else if ((board[x][y]->user == "White" && new_x > x && new_x - x <= 1) ||
                           (board[x][y]->user == "Black" && new_x < x && x - new_x <= 1)) {
                    board[new_x][new_y] = board[x][y];
                    board[new_x][new_y]->loc_x_num = new_x, board[new_x][new_y]->loc_y_char = new_y;
                    board[x][y] = NULL;
                }
            }

        }
    }

    void PrintMap() {

        cout << R"(|||         @@@@@@@@@     =@@@@\       =@@@@^  =@@@@@@@@@@@    @@@@@@@@@      @@@@@@@@@@        |||
|||       @@@@@@@@@@@@@   =@@@@O       =@@@@^  =@@@O@@@@@@@   @@@@@@@@@@@@   @@@@@@@@@@@@       |||
|||      @@@@             =@@@@O       =@@@@^  =@@@@^         @@@@           @@@@               |||
|||     @@@@@             =@@@@@@@@@@@@@@@@@^  =@@@@@@@@@      @@@@@@@@       @@@@@@@@          |||
|||      @@@@             =@@@@O       =@@@@^  =@@@@                   @@@@           @@@@      |||
|||      @@@@        @@   =@@@@O       =@@@@^  =@@@@          @@       @@@@@ @@        @@@@     |||
|||          @@@@@@@@@    .O@@@O       =@@@@^  ,O@@@@@@@@@@@    @@@@@@@@@       @@@@@@@@@       |||
！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！ )";
        cout << endl;
        bool x = 0, sx = 0;
        cout << "   ";
        cout << "                       ";
//___________________________________________________________________________
        SetColorAndBackground(0, 15);
        cout << "   ";
        SetColorAndBackground(15, 0);
        for (int i = 1; i <= 48; i++) {
            if (i % 6 == 1)x = !x;
            if (i % 6 == 3) {
                if (!x) {
                    SetColorAndBackground(0, 15);
                    cout << (char) ('A' + (i / 6));
                } else {
                    SetColorAndBackground(15, 0);
                    cout << (char) ('A' + (i / 6));
                }
                SetColorAndBackground(15, 0);
                continue;
            }
            if (!x)
                printf("%c%c", 0xa8, 0x80);
            else printf(" ");

        }
        cout << endl;
        SetColorAndBackground(15, 0);
//________________________________________________________
        x = 1;

        for (int i = 1; i <= 24; i++) {
            wcout << "                          ";
            SetColorAndBackground(15, 0);
            if (i % 3 == 1)sx = !sx;
            if (i % 3 == 2) {

                if (sx) {
                    wcout << " ";
                    wcout << i / 3 + 1 << " ";
                } else {
                    wcout << L'\u2588';
                    SetColorAndBackground(0, 15);
                    wcout << i / 3 + 1 << " ";
                }
                SetColorAndBackground(15, 0);
            }
                //print column location
            else {
                if (!sx) {

                    for (int z = 1; z <= 3; z++)wcout << L'\u2588';
                } else {
                    wcout << "   ";
                }
                SetColorAndBackground(15, 0);
            }

            if (i % 3 == 1) {     //change color every 3 rows
                x = !x;
            }

            for (int j = 1; j <= 48; j++) {

                if (j % 6 == 1) {   //change color every 6 columns
                    x = !x;
                }
                //*****put the chess on board start*******
                if (j % 6 == 3 && i % 3 == 2) {
                    if (x) {
                        _setmode(_fileno(stdout), _O_WTEXT);
                        SetColorAndBackground(0, 15);
                        if (board[i / 3 + 1][j / 6 + 1] != NULL)
                            Unic_Print(board[i / 3 + 1][j / 6 + 1]->name, board[i / 3 + 1][j / 6 + 1]->user);
                        else wcout << " ";
                        SetColorAndBackground(15, 0);
                    } else {
                        SetColorAndBackground(15, 0);
                        if (board[i / 3 + 1][j / 6 + 1] != NULL)
                            Unic_Print(board[i / 3 + 1][j / 6 + 1]->name, board[i / 3 + 1][j / 6 + 1]->user);
                        else wcout << " ";
//                        	Unic_Print(board[i/3][j/6]->name);
                        SetColorAndBackground(15, 0);
                    }

                }//*****put the chess on board end*******
                else {
                    if (x) {
                        _setmode(_fileno(stdout), _O_WTEXT);
                        wcout << L'\u2588';

                    } else
                        wcout << " ";
                }
            }

            wcout << L'\u007c' << endl;
        }
        //______________________________________________________________________
        wcout << "                          ";
        wcout << "   ";
        for (int i = 1; i <= 48; i++) {
            if (i % 6 == 1)x = !x;
            if (i % 6 == 3) {
                if (!x) {
                    SetColorAndBackground(0, 15);
                    _setmode(_fileno(stdout), _O_WTEXT);

                    wcout << (char) ('A' + (i / 6));
                } else {
                    _setmode(_fileno(stdout), _O_WTEXT);
                    SetColorAndBackground(15, 0);
                    wcout << (char) ('A' + (i / 6));
                }
                SetColorAndBackground(15, 0);
                continue;
            }
            if (!x) {
                _setmode(_fileno(stdout), _O_WTEXT);
                wcout << L'\u2588';
            } else wcout << L'\u0020';

        }
        wcout << endl;
        SetColorAndBackground(15, 0);
//___________________________________________________________________________
    }


    string Print_Game_UI() {
        wcout << "1==>Move\t2==>Give up\t3==>Quit\n ";
        wcout << "Choose Option: ";
        string op;
        cin >> op;
        if (op == "1" || op == "2" || op == "3")
            return op;
        else return "error";
    }

    void TEST1() {
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                if (board[i][j] != NULL) {
                    wcout << i << "," << j << "=> ";
                    cout << board[i][j]->name;
                    wcout << ", :";
                    cout << board[i][j]->user;
                    wcout << endl;
                }
            }
        }
    }
};

string Print_Start_UI() {
    wcout << "1==>Start Game\t2==>Quit Game\n";
    string op;
    wcout << "Choose: ";
//賠茅補秘産喝曝議輝念佩
//    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
//賠茅補秘産喝曝戦侭嗤坪否
//　cin.ignore(numeric_limits<std::streamsize>::max()); 
//賠茅匯倖忖憲
//    cin.ignore();
    cin >> op;
    if (op == "1" || op == "2")
        return op;
    else return "error";
}

bool Read_Loc(int *x, int *y, string s_loc) {
    if (s_loc.length() == 2 && s_loc[0] >= 'A' && s_loc[0] <= 'Z' && s_loc[1] >= '1' && s_loc[1] <= '8') {
        *x = int(s_loc[1] - '0');
        *y = int(s_loc[0] - 'A' + 1);
        return true;
    } else return false;
}

std::wstring GetWStringByChar(const char *szString) {
    std::wstring wstrString;
    if (szString != NULL) {
        std::string str(szString);
        wstrString.assign(str.begin(), str.end());
    }

    return wstrString;
}

int main() {
    Map *map = new Map();
    double t_origin = clock(), t_now, total_b_play_time = 0, total_a_play_time = 0;
    bool Start = false, Black = false;
//    map->TEST1();
    while (true) {
        system("cls");
        map->PrintMap();
        if (Start) {
            double temp_origin = clock(), temp_end;


            if (Black) {//Black Turns
                //Win or Lose Judgement
                if (map->Remain_White==1){
                    wcout<<"Draw!!!\n";
                    system("PAUSE");
                    break;
                }
//                for (int i = 1; i <= 8; i++) {
//                    for (int j = 1; j <= 8; j++) {
//                        if (map->board[i][j] != NULL) {
//                            if (map->board[i][j]->user == "Black" && map->board[i][j]->name == "King") {
//                                map->Fresh_Control_Area("White");
//                                int survival = 0;
//                                for (int xx = 1; xx <= 8; xx++) {
//                                    for (int yy = 1; yy <= 8; yy++) {
//                                        if (abs(xx - i) <= 1 && abs(yy - j) <= 1 && map->board[i][j] == NULL){
//                                            if(!map->White_Control[xx][yy])
//                                                    survival++;
//                                        }
//                                    }
//                                }
//                                if(survival==0){
//                                    wcout<<"Black Lost!!!\n";
//                                    system("PAUSE");
//                                    break;
//                                }
//                            }
//                        }
//                    }
//                }

                SetColorAndBackground(0, 10);
                wcout << "Current Turn => Black Player\n";
                SetColorAndBackground(15, 0);
                string option = map->Print_Game_UI();
                if (option == "1") {
                    int xloc, nxloc;
                    int nyloc, yloc;
                    wcout << "Choose the chess (by location): ";
                    string sloc;
                    cin >> sloc;

                    if (Read_Loc(&xloc, &yloc, sloc) == false) {
                        wcout << "ERROR! Wrong format!\n";
                        system("PAUSE");
                        continue;
                    }

                    if (map->board[xloc][yloc] != NULL && map->board[xloc][yloc]->user == "Black") {
                        wcout << "Take the (";
                        wcout << GetWStringByChar(map->board[xloc][yloc]->name.c_str());
                        wcout << ") Move to (by location): ";
                        cin >> sloc;

                        if (Read_Loc(&nxloc, &nyloc, sloc) == false) {
                            wcout << "ERROR! Wrong format!";
                            system("PAUSE");
                            continue;
                        }

                        map->move(xloc, yloc, nxloc, nyloc);
                    } else {
                        wcout << "ERROR! You could not take the White!\n";
                        system("PAUSE");
                    }
                } else if (option == "2") {
                    wcout << "GAME OVER! White WIN!!!\n";
                    t_now = clock();
                    wcout << "Total time of game is " << (t_now - t_origin) / 1000 << " seconds\n";
                    wcout << "Total Time of white player is " << total_a_play_time / 1000 << " seconds\n";
                    wcout << "Total Time of black player is " << (t_now - t_origin - total_a_play_time) / 1000
                          << " seconds";
                    return 0;
                } else if (option == "3") {
                    wcout << "GAME OVER! Nobody WIN !!!\n";
                    t_now = clock();
                    wcout << "Total time of game is " << (t_now - t_origin) / 1000 << " seconds\n";
                    wcout << "Total Time of white player is " << total_a_play_time / 1000 << " seconds\n";
                    wcout << "Total Time of black player is " << (t_now - t_origin - total_a_play_time) / 1000
                          << " seconds";
                    return 0;
                } else {
                    wcout << "ERROR!\n";
                    system("PAUSE");
                    continue;
                }
                Black = !Black;//turn next;
            } else {//White Turns
                SetColorAndBackground(0, 10);
                wcout << "Current Turn => White Player\n";
                SetColorAndBackground(15, 0);
                if (map->Remain_Black==1){
                    wcout<<"Draw!!!\n";
                    system("PAUSE");
                    break;
                }
//                for (int i = 1; i <= 8; i++) {
//                    for (int j = 1; j <= 8; j++) {
//                        if (map->board[i][j] != NULL) {
//                            if (map->board[i][j]->user == "White" && map->board[i][j]->name == "King") {
//                                map->Fresh_Control_Area("Black");
//                                int survival = 0;
//                                for (int xx = 1; xx <= 8; xx++) {
//                                    for (int yy = 1; yy <= 8; yy++) {
//                                        if (abs(xx - i) <= 1 && abs(yy - j) <= 1 && map->board[i][j] == NULL){
//                                            if(!map->Black_Control[xx][yy])
//                                                survival++;
//                                        }
//                                    }
//                                }
//                                if(survival==0){
//                                    wcout<<"White Lost!!!\n";
//                                    system("PAUSE");
//                                    break;
//                                }
//                            }
//                        }
//                    }
//                }

                string option = map->Print_Game_UI();
                if (option == "1") {
                    int xloc, nxloc;
                    int nyloc, yloc;
                    string sloc;
                    wcout << "Choose the chess (by location): ";
                    cin >> sloc;

                    if (Read_Loc(&xloc, &yloc, sloc) == false) {
                        wcout << "ERROR! Wrong format!\n";
                        system("PAUSE");
                        continue;
                    }
                    if (map->board[xloc][yloc] != NULL && map->board[xloc][yloc]->user == "White") {
                        string xname = map->board[xloc][yloc]->name;
                        wcout << "Take the (";
                        cout << xname;
                        wcout << ") Move to (by location): ";
                        cin >> sloc;
                        if (Read_Loc(&nxloc, &nyloc, sloc) == false) {
                            wcout << "ERROR! Wrong format!\n";
                            system("PAUSE");
                            continue;
                        }
                        map->move(xloc, yloc, nxloc, nyloc);
                    } else {
                        wcout << "ERROR! You could not take the Black!\n";
                        system("PAUSE");
                        continue;
                    }
                } else if (option == "2") {
                    wcout << "GAME OVER! White WIN!!!\n";
                    t_now = clock();
                    wcout << "Total time of game is " << (t_now - t_origin) / 1000 << " seconds\n";
                    wcout << "Total Time of black player is " << total_a_play_time / 1000 << " seconds\n";
                    wcout << "Total Time of white player is " << (t_now - t_origin - total_a_play_time) / 1000
                          << " seconds";
                    return 0;
                } else if (option == "3") {
                    wcout << "GAME OVER! Nobody WIN !!!\n";
                    t_now = clock();
                    wcout << "Total time of game is " << (t_now - t_origin) / 1000 << " seconds\n";
                    wcout << "Total Time of black player is " << total_a_play_time / 1000 << " seconds\n";
                    wcout << "Total Time of white player is " << (t_now - t_origin - total_a_play_time) / 1000
                          << " seconds";
                    return 0;
                } else {
                    wcout << "ERROR!\n";
                    system("PAUSE");
                    continue;
                }
                //compute the white time;
                temp_end = clock();
                total_a_play_time += (temp_end - temp_origin);
                Black = !Black;//turn next;
            }

        } else {
            string option = Print_Start_UI();
            cout << option << endl;
            if (option == "1") {

                wcout << "GAME START SUCCESSFUL!\n Please Choose your side: 1=>White\t2=>Black" << endl;
                cin >> option;
                if (option == "1") {
                    Start = true;
                    Black = false;
                    continue;
                } else if (option == "2") {
                    Start = true;
                    Black = true;
                    continue;
                } else {
                    wcout << "ERROR! Will Restart the Game Soon!\n";
                    system("PAUSE");
                    continue;
                }

            } else if (option == "2") {
                wcout << "GAME OVER!\n";
                return 0;
            } else {
                wcout << "ERROR!\n";
                system("PAUSE");
                continue;
            }

        }

    }
    return 0;
}

