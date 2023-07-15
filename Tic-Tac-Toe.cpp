#include<iostream>
using namespace std;
int Row = 3, Col = 3;
int** Create_Board(int** Board) {
	Board = new int* [Row];
	for (int i = 0; i < Row; i++) {
		Board[i] = new int[Col];
	}
	return Board;
}
int** Init_Board(int** Board) {
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Col; j++) {
			Board[i][j] = 0;
		}
	}
	return Board;
}
void Display_Board(int** Board) {
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Col; j++) {
			cout << Board[i][j]<<'\t';
		}
		cout << endl;
	}
	cout << endl;
}
int Search_choices(int** Board) {
	int Choices = 0;
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Col; j++) {
			if (Board[i][j] == 0)Choices++;
		}
	}
	cout << "Remaining Choices : " << Choices << endl << endl;
	return Choices;
}
int** Move_P1(int** Board)throw() {
	int R, C;
o:
	cout << "-- PLAYER 1 MOVE --\nEnter Row no :"; cin >> R; R = R - 1;
	cout << "Enter Column no :"; cin >> C; C = C - 1;
	if (Board[R][C] == 0) {
		Board[R][C] = 1;
	}
	else
	{
		cout << "Invalid Input\n";
		goto o;
	}
	
	return Board;
}
int** Move_P2(int** Board) {
	int R, C; 
o:
	cout << "-- PLAYER 2 MOVE --\nEnter Row no :"; cin >> R; R = R - 1;
	cout << "Enter Column no :"; cin >> C; C = C - 1;
	if (Board[R][C] == 0) {
			Board[R][C] = 2;
	}
	else
	{
		cout << "Invalid Input\n";
		goto o;
	}
	return Board;
}
int Match_moves(int** Board) {
	int P = 0;
	if (Board[2][0] == 1 && Board[1][1] == 1 && Board[0][2] == 1) P = 1;
	if (Board[0][0] == 1 && Board[1][1] == 1 && Board[2][2] == 1) P = 1;
	if (Board[0][0] == 1 && Board[0][1] == 1 && Board[0][2] == 1) P = 1;
	if (Board[1][0] == 1 && Board[1][1] == 1 && Board[1][2] == 1) P = 1;
	if (Board[2][0] == 1 && Board[2][1] == 1 && Board[2][2] == 1) P = 1;
	if (Board[0][0] == 1 && Board[1][0] == 1 && Board[2][0] == 1) P = 1;
	if (Board[0][1] == 1 && Board[1][1] == 1 && Board[2][1] == 1) P = 1;
	if (Board[0][2] == 1 && Board[1][2] == 1 && Board[2][2] == 1) P = 1;

	if (Board[2][0] == 2 && Board[1][1] == 2 && Board[0][2] == 2) P = 2;
	if (Board[0][0] == 2 && Board[1][1] == 2 && Board[2][2] == 2) P = 2;
	if (Board[0][0] == 2 && Board[0][1] == 2 && Board[0][2] == 2) P = 2;
	if (Board[1][0] == 2 && Board[1][1] == 2 && Board[1][2] == 2) P = 2;
	if (Board[2][0] == 2 && Board[2][1] == 2 && Board[2][2] == 2) P = 2;
	if (Board[0][0] == 2 && Board[1][0] == 2 && Board[2][0] == 2) P = 2;
	if (Board[0][1] == 2 && Board[1][1] == 2 && Board[2][1] == 2) P = 2;
	if (Board[0][2] == 2 && Board[1][2] == 2 && Board[2][2] == 2) P = 2;
	return P;
}
int main() {
	int win = 0,choice=-1;
	int** Board = nullptr;
	Board=Create_Board(Board);
	Board = Init_Board(Board);
	while(1){
		choice=Search_choices(Board);
		Display_Board(Board);
		Board = Move_P1(Board); 
		Display_Board(Board);
		win=Match_moves(Board);
		if (win == 1) {
			cout << "Player 1 Wins\n"; delete[]Board;
			break;
		}
		Board = Move_P2(Board);
		win = Match_moves(Board);
		if (win == 2) {
			cout << "Player 2 Wins\n";	delete[]Board;
			break;
		}
		if (choice == 0) {
			break;
		}
	}
	if (win == 0)cout << "MATCH DRAWS\n";
	return 0;
}