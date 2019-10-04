#include <stdio.h>

int main(){

		double a=0 ,e=0 ,i=0 ,o=0 ,u=0 ;
		double digit=0 ,space=0 ;
		int count=0 ;
		char temp ;
		double maxvalue ; 
		
		while ((temp = getchar()) != EOF){

		temp = tolower(temp);

		switch(temp){
				case 'a':
				a++;
				count++;
				break;

				case 'e':
				e++;
				count++;
				break;
		
				case 'i':
				i++;
				count++;
				break;

				case 'o':
				o++;
				count++;
				break;

				case 'u':
				u++;
				count++;
				break;

				case '0': case '1': case '2': case '3': case '4':
				case '5': case '6': case '7': case '8': case '9':
				digit++;
				count++;
				break;
				
				case ' ': case '\t': case'\n':
				space++;
				count++;
				break;

				default:
				count++;
				break;
				}
		}		
		
		if (count>0){
		a = a/count;
		e = e/count;
		i = i/count;
		o = o/count;
		u = u/count;
		digit = digit/count;
		space = space/count;
		}

		else{
		a=0;
		e=0;
		i=0;
		o=0;
		u=0;
		digit=0;
		space=0;
		}

		maxvalue=a;

		if (e>maxvalue)
			maxvalue=e;

		if (i>maxvalue)
			maxvalue=i;
		
		if (o>maxvalue)
			maxvalue=o;

		if (u>maxvalue)
			maxvalue=u;


		if (a>0)
			printf("a:%f\n",a);
		else
			printf("a:0\n");

		if (e>0)
				printf("e:%f\n",e);
		else
				printf("e:0\n");

		if (i>0)
				printf("i:%f\n",i);
		else
				printf("i:0\n");
		
		if (o>0)
				printf("o:%f\n",o);
		else
				printf("o:0\n");
		
		if (u>0)
				printf("u:%f\n",u);
		else
				printf("u:0\n");

		if (digit>0)
				printf("digit:%f\n",digit);
		else
				printf("digit:0\n");

		if (space>0)
				printf("space:%f\n",space);
		else
				printf("space:0\n");

		if (maxvalue==0)
				printf("the most common vowel:\n");
		else{
				printf("the most common vowel:");
				if (a==maxvalue)
					printf("a");
				if (e==maxvalue){
						if (a==maxvalue)
							printf(",");
					printf("e");
				}
				if (i==maxvalue){
						if (a==maxvalue||e==maxvalue)
							printf(",");
					printf("i");
				}
				if (o==maxvalue){
						if (a==maxvalue||e==maxvalue||i==maxvalue)
							printf(",");
					printf("o");
				}
				if (u==maxvalue){
						if (a==maxvalue||e==maxvalue||i==maxvalue||o==maxvalue)
							printf(",");
					printf("u");
				}
				printf("\n");
		}
						return 0;
}
