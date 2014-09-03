#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	int enzan,a,b,c,e,i=1;
	char d[5]={'\0','+','-','*','/'};
	
	srand((unsigned int)time(NULL));
	
	while(i==1){
	
	printf("計算したい四則演算を決めてください\n");
	printf("\n1. 加算 2.減算 3.乗算 4.除算 >");
	scanf("%d",&enzan);
	printf("\n");
	
	//裏コマンド
		if(enzan==114514){
			printf("＿人人人人人＿\n> 裏コマンド <\n￣Y^Y^Y^Y^Y^Y￣\n\n");
			switch((rand()%10)+1){
				case 1:
					printf("こ↑こ↓\n\n");
					continue;
				case 2:
					while(a!=1){
						printf("うちさぁ、屋上あんだけど…焼いて行かない？\n\n");
						printf("イキますか？\n1.イく 2.イかない >");
						scanf("%d",&a);
						if(a==1){
							printf("\nデデドン!(絶望)\n\n");
							return 0;
						}else if(a==2){
							printf("\nファッ！？\n\n");
							break;
						}else{
							printf("\nじゃけん、ちゃんと数値を入れましょうね～\n\n\n");
							continue;
						}
					}
					continue;
				case 3:
					printf("おまたせ！アイスティーしかなかったけどいいかな？\n\n");
					continue;
				case 4:
					printf("いいよ来いよ！胸にかけて、胸に！\n\n");
					continue;
				case 5:
					printf("ぬわああん疲れたもおおおおおおん\n\n");
					continue;
				case 6:
					printf("じゃけん夜行きましょうね～\n\n");
					continue;
				case 7:
					printf("ちょっと歯あたんよー\n\n");
					continue;
				case 8:
					printf("ンアッー！\n\n");
					continue;
				case 9:
					printf("暴れんなよ……暴れんなよ……\n\n");
					continue;
				case 10:
					printf("お前のことが好きだったんだよ！\n\n");
					continue;
			}
		}else if(enzan==1426072){
			printf("＿人人人人人＿\n> 裏コマンド <\n￣Y^Y^Y^Y^Y^Y￣\n\n");
			printf("関 遥太 「( ゜∀゜)o彡゜おっぱい！おっぱい！」\n\n");
			continue;
		}else if(enzan==1919){
			printf("＿人人人人人＿\n> 裏コマンド <\n￣Y^Y^Y^Y^Y^Y￣\n\n");
			printf("アン！アン！アン！アン！アン！アン！アン！アン！アン！アッーンン！！（高音）\n\n");
			continue;
		}else if(enzan==1426126){
			printf("＿人人人人人＿\n> 裏コマンド <\n￣Y^Y^Y^Y^Y^Y￣\n\n");
			printf("森 雄志「ふたなりは神様」\n\n");
			continue;
		}else if(enzan==1426077){
			printf("＿人人人人人＿\n> 裏コマンド <\n￣Y^Y^Y^Y^Y^Y￣\n\n");
			switch((rand()%5)+1){
				case 1:
					printf("みなと 「女になりたい。生理痛を味わいたい」\n\n");
					continue;
				case 2:
					printf("みなと 「小学校で女の子のノート踏んじゃってビンタされてなんかいいわ～って思った」\n\n");
					continue;
				case 3:
					printf("みなと 「女になったら男に奢らせたい」\n\n");
					continue;
				case 4:
					printf("みなと 「ヒール履いてみたい」\n\n");
					continue;
				case 5:
					printf("みなと 「下僕になるのはいいけどやっぱり下僕が女王様と最終的に立場が変わるのがいいんだよ！」\n\n");
					continue;
			}
		}else if(enzan<1||enzan>4){
			printf("ちゃんとした数値を入力してください\n\n");
			continue;
	}
	
	printf("a %c b の計算をします\n",d[enzan]);
	printf("a の値を入力してください >");
	scanf("%d",&a);
	printf("b の値を入力してください >");
	scanf("%d",&b);
	
	if(enzan==1){
		c=a+b;
	}else if(enzan==2){
		c=a-b;
	}else if(enzan==3){
		c=a*b;
	}else if(enzan==4){
		c=a/b;
	}
	printf("\n%d %c %d = %dです\n\n",a,d[enzan],b,c);
	
	i=3;
	
	while(i!=1){
		
		printf("繰り返し計算しますか？\n");
		printf("1.はい 2.いいえ >");
		scanf("%d",&i);
		printf("\n");
		
		if(i==2){
			return 0;
		}else if(i!=1|i!=2){
			printf("ちゃんとした数値を入力してください\n\n");
		}
	
	}
	
	}
	
	return 0;

}