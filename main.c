#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
	int board[5][5];
	int stone;
	int player;
	char row;
	int temp_row;
	int column;
	int judge;
	int result;
	int turn;
	
	
/*---盤面(board変数)の初期化関数---*/
void initBoard()
{
	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++) {
			if(i == 0 || i == 4 || j == 0 || j == 4) {
				board[i][j] = 2;
			} else {
				board[i][j] = 0;
			}
		}
	}
}
/*---変数Stoneの初期化関数---*/
void initStone(void)
{	
	/*
	 * commented by akira 2014/10/25
	 * 初期化するためのコードが必要なので、ここで*-1を行うのは適切ではありません。
	 * 正しくは、初期に入っているべき値を代入します。
	stone *= -1; 
	 */
	 // add by akira 1024/10/25
	stone = -1; //stoneの初期値は-1
}
/*---変数Stoneの初期化関数---*/
void initPlayer(void)
{	
	player = 0;
}
/*---変数Turnの初期化関数---*/
void initTurn(void)
{	
	turn = 0;
}
/*---プレーヤーを見せる--*/
void showPlayer()
{
	if(0 == player) {
		printf("Player is White\n");
	} else if(1 == player) {
		printf("Player is Black\n");
	}
}	
/*---碁盤を見せる--*/	
void showBoard()
{
	for(int i=1; i<4; i++) {
		for(int j=1; j<4; j++) {
			switch(board[i][j]) {
				case 0:
					printf("?");
					break;
				case 1:
					printf("o");
					break;
				case -1:
					printf("x");
					break;
				default:
					break;
			}
		}
		printf("\n");
	} 
	printf("\n");
}
/*---石が置ける場所かどうか判断する---*/
int putableStone()
{
	/* 
	 * commented by akira 2014/10/25
	 * resultという変数がどこにも定義されていないので、本来このコードだと値を代入することも返すことも出来ません。
	 * ですが、Cは少し抜けたコードなので、もしかすると毎回0を返しているかもしれません。
	 * なので、ここではresultという変数の定義が必要です。
	 */
	 // add by akira 2014/10/25
	int result = 0; // 0->置けない, 1->置ける
	if(0 == board[temp_row][column]) {
		result = 1;
	}
	return result;
}
/*---勝利鑑定を行う---*/
int checkWin(int flag, int check_row, int check_column, int index_row, int index_column)
{
	int dir_row[4] = {-1, -1, 0, 1};
	int dir_column[4] = {0, 1, 1, 1};
	/*
	 * commented by akira 2014/10/25
	 * 2つの数字の大小を比べるということを一つの分岐式の中でやると、うまく動きません。
	 * なので、分けてあげるか、2つの式が同じように増えていくならどちらか一つの式の値だけを見てあげればいいことになります。
	 * while(index_row < 5 && index_column < 5) {
	 */
	// edit by akira 2014/10/25
	while(index_row < 5) {
		if(2 == board[temp_row + dir_row[index_row]*flag][column + dir_column[index_column]*flag]) {
			if(flag == 1) {
				flag *= -1;
				checkWin(flag, temp_row, column, index_row, index_column);
			} else {
				judge = 1;
				return judge;
			}
		} else if(0 == board[temp_row + dir_row[index_row]*flag][column + dir_column[index_column]*flag]) {
			checkWin(flag, temp_row, column, ++index_row, ++index_column);
		} else if(stone != board[temp_row + dir_row[index_row]*flag][column + dir_column[index_column]*flag]) {
			checkWin(flag, temp_row, column, ++index_row, ++index_column);
		} else if(stone == board[temp_row + dir_row[index_row]*flag][column + dir_column[index_column]*flag]) {
			int p_row = temp_row + dir_row[index_row]*flag;
			int p_column = column + dir_column[index_column]*flag;
			checkWin(flag, p_row, p_column, index_row, index_column);
		}
		judge = 0;
		return judge;
	}
	/*
	 * commented by akira 2014/10/25
	 * returnというものは、関数内でしか使えない値を、グローバル変数を使わずに関数の外に渡してやりたい場合に、関数の走った結果として値を返します。
	 * 今回の場合judgeはグローバル変数で、どの関数からでもアクセスできるので、returnして返してやる必要はありません。
	 */
	// add by akira 2014/10/25
	return judge;
}
/*---勝者を表示する---*/
void dispWinner()
{
	if(0 == player) {
		printf("Winner is White!\n");
	} else {
		printf("Winner is Black!\n");
	}
}
/*---石を変える---*/
void changeStone()
{
	stone *= -1;
}
/*---プレーヤーを変える---*/
void changePlayer()
{
	if(0 == player) {
		player = 1;
	} else if(1 == player) {
		player = 0;
	}
}
/*---ユーザーからの入力を受け付ける関数---*/
void inputRow()
{	
	printf("行を入力：");
	fflush(stdin);
	scanf("%c" , &row);
	/*
	 * commented by akira 2014/10/25
	 * 盤面が5x5で定義されているので、入力するべきrowの値は1～3です。
	 * このコードのとおりに実行すると、aを入力した場合、番兵の居る場所への入力となってしまいます。
	switch(row) {
		case 'a':
			temp_row = 0;
			break;
		case 'b':
			temp_row = 1;
			break;
		case 'c':
			temp_row = 2;
			break;
		default:
			printf("please input row\n");
			break;
	}
	 */
	// edit by akira 2014/10/25
	switch(row) {
		case 'a':
			temp_row = 1;
			break;
		case 'b':
			temp_row = 2;
			break;
		case 'c':
			temp_row = 3;
			break;
		default:
			printf("please re-input row\n");
			break;
	}
}
int inputColumn()
{
	printf("Please input column：");
	scanf("%d" , &column);
	/*
	 * commented by akira 2014/10/25
	 * 盤面が5x5で定義されているので、入力するべきcolumnの値は1～3です。
	 * このコードのとおりに実行すると、1列づつ左にずれて入力されてしまいます。
	switch(column) {
		case 0:
		case 1:
		case 2:
			if(putableStone() == 1) {
					board[temp_row][column] = stone;
					turn = turn + 1;
					return turn;
					}
			else{
					printf("Pleaes input appropriate row:\n");
					inputRow();
			}
			break;
		default:
			printf("Please input appropriate column:\n");
			inputColumn();
			break;
	}
	*/
	switch(column) {
		case 1:
		case 2:
		case 3:
			if(putableStone() == 1) {
				board[temp_row][column] = stone;
				turn = turn + 1;
				return turn;
			} else {
				printf("Pleaes input appropriate row:\n");
				inputRow();
			}
			break;
		default:
			printf("Please input appropriate column:\n");
			inputColumn();
			break;
	}
	/*
	 * commented by akira 2014/10/25
	 * inputColumn関数はint型(数字)の返り値を持つ関数らしいので、
	 * 然るべき値をreturnしてあげる必要があります。
	 */
	 // add by akira 2014/10/25
	return 0;
}
int main(int argc, char **argv)
{
	initBoard();
	initStone();
	initPlayer();
	initTurn();
	if(turn < 9) {
		if(checkWin == 0) {
			/*
			 * commented by akira 2014/10/25
			 * the comparison will always evaluate as 'false' for the address of 'checkWin' will neber be NULL [-Waddress]
			 * checkWin関数に引数が渡されていないため、コードがちゃんと動いていません。
			 * 引数を渡してあげてください。
			 */
			showBoard();
			showPlayer();
			inputRow();
			inputColumn();
		} else {
			dispWinner();
		}
	} else {
		/*
		 * commented by akira 2014/10/25
		 * 文字の表示をする場合は
		 * printf("表示したい文字列");
		 * です。
		 * ("draw\n");
		 */
		// add by akira 2014/10/25
		printf("draw\n");
	}
	// add by akira 2014/10/25
	return 0;
}