#include <stdio.h>


//調分公式 原始分數開根號至小數點第二位 四捨五入至小數點第一位後*10
//等同原始成績*10000 來尋找原始成績開根號至小數點後第二位 後四捨五入進位
int adjust (int score)
{
		int new=1;

		score = (score*10000);

		while (new*new<score)
				new++;

		new--;
		new = ((new+5))/10;

		return new;
}


int main(){

		int score[1000][5];
		int i,j,k;
		int average[4],max[4],min[4];
		int temp,sum,tempscore[5];
		int count=0;


		printf("No\tMath\tEnglish\tProg\tAverage\n");
		printf("----------------------------------------\n");


		for(i=0;i<1000;i++,count++){
				for(j=0;j<3;j++){
						scanf("%d",&temp);
						score[i][j]=adjust(temp);
				}	
				if(getchar()==EOF)
						break;
		}

		for(i=0;i<1000;i++)
				score[i][4]=i;

		for(i=0;i<count;i++)
				score[i][3]=((score[i][0]+score[i][1]+score[i][2])*100+55*3)/300;

		for (k=0;k<count;k++)
				for (i=count-1;i>k;i--)
						if(score[i][3]>score[i-1][3]){
								for(j=0;j<5;j++){
										tempscore[j]=score[i][j];
										score[i][j]=score[i-1][j];
										score[i-1][j]=tempscore[j];
								}
						}

		for(i=0;i<count;i++){
				printf("%d\t",score[i][4]);
				for(j=0;j<3;j++){
						printf("%d\t",score[i][j]);
				}
				printf("%d\n",score[i][3]);
		}


		printf("----------------------------------------\n");


		for(j=0;j<4;j++){
				for(i=0,sum=0;i<count;i++){
						sum+=score[i][j];
						average[j]=(sum*100+55*count)/(100*count);
				}
		}

		printf("Avg\t");
		for(i=0;i<3;i++)
				printf("%d\t",average[i]);
		printf("%d\n",average[3]);


		for(j=0;j<4;j++){
				for(i=0,max[j]=score[0][j];i<count;i++){
						if (score[i][j]>max[j])
								max[j]=score[i][j];
				}
		}

		printf("Max\t");
		for(i=0;i<3;i++)
				printf("%d\t",max[i]);
		printf("%d\n",max[3]);


		for(j=0;j<4;j++){
				for(i=0,min[j]=score[0][j];i<count;i++){
						if (score[i][j]<min[j])
								min[j]=score[i][j];
				}
		}

		printf("Min\t");
		for(i=0;i<3;i++)
				printf("%d\t",min[i]);
		printf("%d\n",min[3]);


		return 0;
}

