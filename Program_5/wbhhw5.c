#include <stdio.h>
#include <string.h>

int getword(char word[], int line){

		int c, i;

		for(i=0;i<line && (c=getchar())!=EOF && c!='\n' && c!=' ';i++){
				word[i]=c;
				if(c=='.'||c==',')
						word[i]='\0';
		}

		word[i]='\0';

		if (c==EOF)
				return 777;
		else
				return 0;
}


int weight(char word[],int N){

		int sum=0,i;

		for(i=0;i<N;i++)
				sum+=word[i];

		return sum;
}

int main(){
		double sum = 0, ave = 0;
		unsigned int count = 0, i ,max=0 ,flag;
		char words[1000][20],fatwords[20]={0};

		for(i=0,count=0;i<1000;i++,count++){
				flag=getword(words[i], 20);
				if(flag==777)
						break;
		}


		for (i = 0,max=0; i < count; i++){			
				sum += strlen(words[i]);
				if(strlen(words[i]) > max)
						max=strlen(words[i]);
		}

		ave = sum / count;

		for(i=0;i<count;i++)
				if(strlen(words[i]) == max)
						if(weight(words[i],max)>weight(fatwords,max))
								strcpy(fatwords,words[i]);


		printf("The longest word: %s\n",fatwords);
		printf("Average word length: %.2f\n",ave);
		return 0;
}
