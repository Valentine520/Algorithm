#include <stdio.h>
#define INF 1000

//求解fibonaci数列

//朴素方法
int Simple_Fibonaci(int n){
	if(n<=0){
		return 0;//避免非法输入
	}
	if(n==1){
		return 1;
	}
	else{
		return Simple_Fibonaci(n-1) + Simple_Fibonaci(n-2);
	}
}


//带备忘录的自顶向下法
//借助带备忘的自顶向下法可以同时求解出一个fibonaci序列

int Memoized_Fibonaci_Aux(int n,int *p);

int Memoized_Fibonaci(int n){
	int p[n+1];
	for(int i=0;i<=n;i++){
		p[i] = -INF;
	}
    p[0]=0;
    p[1]=1;//底
	//保证已经初始化
	int res = Memoized_Fibonaci_Aux(n,p);
	for(int i=0;i<=n;i++){
		printf("%d ",p[i]);
	}
	putc('\n',stdout);
	return res;
}


//自底向上法
int Bottom_fibonaci(int n){
	int p[n];
	p[0]=0;
	p[1]=1;//基
	for(int i=2;i<=n;i++){
		p[i] = p[i-1] + p[i-2];
	}
	for(int i=0;i<=n;i++){
		printf("%d ",p[i]);
	}
	putc('\n',stdout);
	return p[n];
}


int Memoized_Fibonaci_Aux(int n,int *p){
	if(n<0){
		return 0;//避免非法输入
	}
	if(p[n]>=0){
		return p[n];
	}
	else{
		int res1 = Memoized_Fibonaci_Aux(n-1,p);
		p[n-1] = res1;
		int res2 = Memoized_Fibonaci_Aux(n-2,p);
		p[n-2] = res2;
		p[n] = res1+res2;
		//存储已经完成过的数据
		return res1+res2;
	}
}




int main(int argc, char *argv[]) {
	//数列是从0开始的
	int i = 10;
	int res = Memoized_Fibonaci(i);
	int res2 = Bottom_fibonaci(i);
	int res3 = Simple_Fibonaci(i);
	printf("Res1:%d\n",res);
	printf("Res2:%d\n",res2);
	printf("Res3:%d\n",res3);
	return 0;
}
