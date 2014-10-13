#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
	int board[3][3];
	int stone;
	int player;
	char row;
	int temp_row;
	int column;
	int judge;
	int result;
	
	
/*---盤面(board変数)の初期化関数---*/
void initBoard()
{	
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			board[i][j] = 0;
		}
	}
}
/*---変数Stoneの初期化関数---*/
void initStone(void)
{	
	stone = -1; 
}
/*---変数Stoneの初期化関数---*/
void initPlayer(void)
{	
	player = 0;
}
/*---プレーヤーを見せる--*/
void showPlayer(){
	if (0 == player){
		printf("プレーヤーは白です\n");
	}else if(1 == player){
		printf("プレーヤーは黒です\n");
	}
}	
/*---碁盤を見せる--*/	
void showBoard()
{
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
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
int putableStone(){
	if(0 == board[row][column]){
		result = 1;
	}
	return result;
}
/*---石を変える---*/
void changeStone() {
	stone *=-1;
}
/*---プレーヤーを変える---*/
void changePlayer() {
	if(0 == player) {
		player = 1;
	}else if(1 == player){
		player = 0;
	}
}
/*---ユーザーからの入力を受け付ける関数---*/
void inputRow()
{	
	printf("行を入力：");
	fflush(stdin);
	scanf("%c" , &row);
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
			printf("行を正しく入力してください\n");
			break;
	}
}
void inputColumn(){
	printf("列を入力：");
	scanf("%d" , &column);
	switch(column) {
		case 0:
		case 1:
		case 2:
			if(putableStone() == 1) {
					board[temp_row][column] = stone;
					changeStone();
					changePlayer();
					showPlayer();
					showBoard();
					inputRow();
			}
			else{
					printf("行を正しく入力してください\n");
					inputRow();
			}
			break;
		default:
				printf("列を正しく入力してください\n");
				inputColumn();
				break;
	}
}
int main()
{
	initBoard();
	initStone();
	initPlayer();
	showPlayer();
	showBoard();
	inputRow();
	inputColumn();
}