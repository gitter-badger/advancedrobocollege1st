#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	int enzan,a,b,c,e,i=1;
	char d[5]={'\0','+','-','*','/'};
	
	srand((unsigned int)time(NULL));
	
	while(i==1){
	
	printf("�v�Z�������l�����Z�����߂Ă�������\n");
	printf("\n1. ���Z 2.���Z 3.��Z 4.���Z >");
	scanf("%d",&enzan);
	printf("\n");
	
	//���R�}���h
		if(enzan==114514){
			printf("�Q�l�l�l�l�l�Q\n> ���R�}���h <\n�PY^Y^Y^Y^Y^Y�P\n\n");
			switch((rand()%10)+1){
				case 1:
					printf("��������\n\n");
					continue;
				case 2:
					while(a!=1){
						printf("���������A���゠�񂾂��ǁc�Ă��čs���Ȃ��H\n\n");
						printf("�C�L�܂����H\n1.�C�� 2.�C���Ȃ� >");
						scanf("%d",&a);
						if(a==1){
							printf("\n�f�f�h��!(��])\n\n");
							return 0;
						}else if(a==2){
							printf("\n�t�@�b�I�H\n\n");
							break;
						}else{
							printf("\n���Ⴏ��A�����Ɛ��l�����܂��傤�ˁ`\n\n\n");
							continue;
						}
					}
					continue;
				case 3:
					printf("���܂����I�A�C�X�e�B�[�����Ȃ��������ǂ������ȁH\n\n");
					continue;
				case 4:
					printf("�����旈����I���ɂ����āA���ɁI\n\n");
					continue;
				case 5:
					printf("�ʂ킠�����ꂽ����������������\n\n");
					continue;
				case 6:
					printf("���Ⴏ���s���܂��傤�ˁ`\n\n");
					continue;
				case 7:
					printf("������Ǝ��������[\n\n");
					continue;
				case 8:
					printf("���A�b�[�I\n\n");
					continue;
				case 9:
					printf("�\���Ȃ�c�c�\���Ȃ�c�c\n\n");
					continue;
				case 10:
					printf("���O�̂��Ƃ��D���������񂾂�I\n\n");
					continue;
			}
		}else if(enzan==1426072){
			printf("�Q�l�l�l�l�l�Q\n> ���R�}���h <\n�PY^Y^Y^Y^Y^Y�P\n\n");
			printf("�� �y�� �u( �K�́K)o�c�K�����ς��I�����ς��I�v\n\n");
			continue;
		}else if(enzan==1919){
			printf("�Q�l�l�l�l�l�Q\n> ���R�}���h <\n�PY^Y^Y^Y^Y^Y�P\n\n");
			printf("�A���I�A���I�A���I�A���I�A���I�A���I�A���I�A���I�A���I�A�b�[�����I�I�i�����j\n\n");
			continue;
		}else if(enzan==1426126){
			printf("�Q�l�l�l�l�l�Q\n> ���R�}���h <\n�PY^Y^Y^Y^Y^Y�P\n\n");
			printf("�X �Y�u�u�ӂ��Ȃ�͐_�l�v\n\n");
			continue;
		}else if(enzan==1426077){
			printf("�Q�l�l�l�l�l�Q\n> ���R�}���h <\n�PY^Y^Y^Y^Y^Y�P\n\n");
			switch((rand()%5)+1){
				case 1:
					printf("�݂Ȃ� �u���ɂȂ肽���B�����ɂ𖡂킢�����v\n\n");
					continue;
				case 2:
					printf("�݂Ȃ� �u���w�Z�ŏ��̎q�̃m�[�g���񂶂���ăr���^����ĂȂ񂩂�����`���Ďv�����v\n\n");
					continue;
				case 3:
					printf("�݂Ȃ� �u���ɂȂ�����j�ɚ��点�����v\n\n");
					continue;
				case 4:
					printf("�݂Ȃ� �u�q�[�������Ă݂����v\n\n");
					continue;
				case 5:
					printf("�݂Ȃ� �u���l�ɂȂ�̂͂������ǂ���ς艺�l�������l�ƍŏI�I�ɗ��ꂪ�ς��̂������񂾂�I�v\n\n");
					continue;
			}
		}else if(enzan<1||enzan>4){
			printf("�����Ƃ������l����͂��Ă�������\n\n");
			continue;
	}
	
	printf("a %c b �̌v�Z�����܂�\n",d[enzan]);
	printf("a �̒l����͂��Ă������� >");
	scanf("%d",&a);
	printf("b �̒l����͂��Ă������� >");
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
	printf("\n%d %c %d = %d�ł�\n\n",a,d[enzan],b,c);
	
	i=3;
	
	while(i!=1){
		
		printf("�J��Ԃ��v�Z���܂����H\n");
		printf("1.�͂� 2.������ >");
		scanf("%d",&i);
		printf("\n");
		
		if(i==2){
			return 0;
		}else if(i!=1|i!=2){
			printf("�����Ƃ������l����͂��Ă�������\n\n");
		}
	
	}
	
	}
	
	return 0;

}