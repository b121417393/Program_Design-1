#include <stdio.h>
	

//泡沫排序法
void bubble(int value[],int count){

	int i,j,temp;

	for(i=0;i<count;i++)
			for(j=count-1;j>i;j--)
					if(value[j]>value[j-1]){
							temp=value[j-1];
							value[j-1]=value[j];
							value[j]=temp;
					}
}

//開根號到小數點後兩位
double mysqrt (double num){
			
	double new=1;
				
	num=(num*10000);

	while(new*new<num)
		new++;
	new--;
	new=new/100;

	return new;
}


//主程式
int main(){

	int number[1000];
	int input=0,i=0,count=0;
	double sum=0,mid,ave,var=0,sd=0;

//讀取資料並排序，印出最大最小
	while(scanf("%d",&input)!=EOF)
		if(input <= 9999 && input >= 0){
			number[i]=input;
			i++,count++;
		}
		else
			continue;
	
	bubble(number,count);

	printf("Top 10 value\n");
	
	if (count > 10)
		for(i=0;i<10;i++)
			printf("%d\n",number[i]);
	
	else
		for(i=0;i<count;i++)
			printf("%d\n",number[i]);

	printf("Max value:%d\n",number[0]);
	printf("Min value:%d\n",number[count-1]);


//印出中位數
	mid=count/2;

	if(mid==(count+1)/2){
			mid=(double)(number[count/2]+number[count/2-1])/2;
			printf("Mid value:%.1f\n",mid);
	}
	else{
			mid=number[count/2];
			printf("Mid value:%.0f\n",mid);
	}


//印出平均值
	for(i=0,sum=0;i<count;i++)
			sum+=number[i];
	ave=sum/count;
	ave=(((int)(ave*10+0.5))/10.0);
	printf("Avg value:%.1f\n",ave);
	

//印出標準差
	for(i=0;i<count;i++)
			var+=((number[i]-ave)*(number[i]-ave))/count;
	sd=mysqrt(var);
	sd=((int)(sd*10+0.5))/10.0;
	printf("SD value:%.1f\n",sd);
	

//印出90%平均值
	int skip;
	skip=(count*5+50)/100;

	for(i=skip,sum=0;i<(count-skip);i++)
		sum+=number[i];
	ave=0;
	ave=sum/(count-2*skip);
	ave=((int)(ave*10+0.5))/10.0;
	printf("90%%Avg value:%.1f\n",ave);


//印出90%標準差
	for(i=skip,var=0;i<(count-skip);i++)
			var+=((number[i]-ave)*(number[i]-ave))/(count-2*skip);
	sd=mysqrt(var);
	sd=((int)(sd*10+0.5))/10.0;
	printf("90%%SD value:%.1f\n",sd);
	

	return 0;
}
