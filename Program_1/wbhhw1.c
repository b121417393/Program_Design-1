#include <stdio.h>      
#include <string.h>      
        
int main(){      
      
    char a[100][100]={{0}},b[100][100]={{0}},c;      
    int i=0;      
          
    for (i=0;i<100;i++){
       scanf("%s%s",a[i],b[i]); 
  
       if(strcmp(a[i],b[i]) == 0)
           printf("Yes\n");
       else
           printf("No\n");
    }
       if((c=getchar())==EOF)
            break;

    return 0;      
      
}      