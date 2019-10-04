#include <stdio.h>
#include <string.h>


void removed(char a[],char b[],int N){

	int i,j;
	
//去掉開頭空白
	for(i=0;i<N-1;i++){
		if(a[i]==' ')
			continue;
		else
			break;
	}


//去掉內文多餘空白
	for(j=0;i<N-1;i++,j++)
		if(a[i]==' ')
			if(a[i-1]==' ')
				j--;
			else
				b[j]=a[i];
		else
			b[j]=a[i];

	if(b[j-1]==' ')		
		b[j-1]='\0';
	else
		b[j]='\0';
}


//反轉
void reversed(char a[],char b[],int N){

	int i;

	for(i=0;N>0;i++,N--)
		b[i]=a[N-1];

	b[i]='\0';

}


int main(){

	char a[1000][1000]={{0}},b[1000][1000]={{0}},c[1000][1000]={{0}};
	int i=0,count=0;
	

	while(fgets(a[i],1000,stdin)!=NULL){
		i++;
		count++;
	}

	for(i=0;i<count;i++){
		removed(a[i],b[i],strlen(a[i]));
		reversed(b[i],c[i],strlen(b[i]));
		printf("%s\n",c[i]);
	}

	return 0;

}
