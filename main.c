#include <stdio.h>
	int board[3][3];	/*盤面の配列オブジェクト*/
	int stone; 　　　/*石を表す変数 -1,1が入る*/
	int player; 　　/*プレーヤーを表す変数 0,1が入る*/
	char row; 　　　/*盤面の列を表す変数 a,b,cが入る*/
	int column; 　　/*盤面の行を表す変数　0,1,2が入る*/
	int judge; 　　　/*勝者を判定するときに使用する変数*/
/*---盤面(board変数)の初期化関数---*/
void initBoard(void)
{	
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			board[i][j]=0;
		}
	}
}
/*---変数Stoneの初期化関数---*/
void initStone(void)
{	
	stone=1;
}
/*---変数Stoneの初期化関数---*/
void initPlayer(void)
{	
	player=0;
}
/*---碁盤を見せる--*/
void showBoard(void)
{
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			printf("%d \n" , board[i][j]);
		}
	}
}
/*---ユーザーからの入力を受け付ける関数---*/
void input(void)
{	
	printf("列を選択してください:\n"); scanf("%c , &row");
	printf("行を選択してください:\n"); scanf("%d , &column");
}
int main(void)
{
	initBoard();
	initStone();
	initPlayer();
	showBoard();
	input();
}