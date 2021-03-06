#include <stdio.h>
	int board[3][3];	/*盤面の配列オブジェクト*/
	int stone; 　　　/*石を表す変数 -1,1が入る*/
	int player; 　　/*プレーヤーを表す変数 0,1が入る*/
	char row; 　　　/*盤面の列を表す変数 a,b,cが入る*/
	int temp_row;  /*盤面の列を表す変数 0,1,2が入る*/
	int column; 　　/*盤面の行を表す変数　0,1,2が入る*/
	int judge; 　　　/*勝者を判定するときに使用する変数*/
	
	
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
	stone = 1;
}
/*---変数Stoneの初期化関数---*/
void initPlayer(void)
{	
	player = 0;
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

/*---ユーザーからの入力を受け付ける関数---*/
void input()
{	
	row = NULL;
	column = NULL;
	printf("列を入力：");
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
			printf("列を正しく入力してください\n");
			input();
			break;
	}
	printf("行を入力：");
	scanf("%d" , &column);
	switch(column) {
		case 0:
		case 1:
		case 2:
			if(putableStone()) {
					board[temp_row][column] = stone;
					changeStone();
					changePlayer();
			}
			else{
					printf("行を正しく入力してください\n");
					input();
			}
			break;
		default:
				printf("行を正しく入力してください\n");
				input();
				break;
	}
}
u
int putableStone(){
	int result = -1;
	if(0 == board[temp_row][column]){
		int result = 1;
	}
	return result;
}
void changeStone() {
	stone *= -1;
}

void changePlayer() {
	if(0 == player) {
		player = 1
	}else if(1 == player){
		player = 0 ;
	}
}
int main(void)
{
	initBoard();
	initStone();
	initPlayer();
	showBoard();
	input();
}