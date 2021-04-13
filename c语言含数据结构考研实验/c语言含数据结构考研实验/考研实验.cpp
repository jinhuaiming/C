#include "stdio.h"

#pragma region 数据结构定义
//字符统计结构
typedef struct WordStatistics
{
	char word;//字符类型
	int count;//字符数量
};
#pragma endregion

#pragma region 函数定义
#pragma region string常用字符串函数伪源码
//小写字母换大写字母；
void strupr(char a[]){
	for (int i = 0; a[i]!= '\0'; i++)
	{
		if (a[i]>='a'&&a[i]<='z')
		{
			a[i]-=32;
		}
	}
	puts(a);
	printf("\n");
}
#pragma endregion
#pragma region 字符串提取数字
void TNum(char str[]){
	int m=0,i;
	for ( i = 0; str[i]!='\0'; i++)
	{
		if (str[i]>='0'&&str[i]<='9')
		{
			m=m*10+str[i]-'0';
		}	
	}
	printf("提取的数字为:%d\n\n",m);
}
#pragma endregion
#pragma region 字符串统计字符类型函数
void Word_Statistics(char string[]){
	WordStatistics str[100];//储存字符统计数据
	WordStatistics a;
	int count=0;//字符统计数组的下标
	for (int i = 0; string[i]!='\0'; i++)
	{
		int j=0;
		//第一个字符直接储存
		if (i==0)
		{		
			a.word=string[i];
			a.count=1;
			str[count++]=a;
			str[count++].word='#';
			continue;
		}
		//除第一个以外其他字符与统计字符数组比较，相同则个个数加一，跳出循环；
		while (str[j].word!='#')
		{
			if (str[j].word==string[i])
			{
				str[j].count++;
				break;
			}
			j++;
		}

		//字符与统计字符都不相同，则先储存一个新的统计字符；
		if (str[j].word=='#')
		{
			a.word=string[i];
			a.count=1;
			str[j]=a;
			str[j+1].word='#';
		}
	}

    //输出统计结果
	for (int i = 0; str[i].word!='#' ; i++)
	{
		printf("字符：%C，数量：%d\t",str[i].word,str[i].count);
		if (i%4==0&&i!=0)
		{
			printf("\n");
		}
	}
}
#pragma endregion
#pragma endregion


int main(){
#pragma region 数据类型定义
	 char x;//标识是否操作类型；
#pragma endregion
  
#pragma region 标题
	 printf("\t\t\t\t\t   ！！！C语言含数据结构考研实验！！！\n\n");
#pragma endregion

#pragma region 操作说明
	  printf("！！！！！！！！！！！！！！！！！\n");
	  printf("！！！！！！操作指南！！！！！！！\n");
	  printf("！！！！！0:退出系统！！！！！！！\n");
	  printf("！！1:字母小写字符串转大写！！！！\n");
	  printf("！！2:提取字符串中的数字！！！！！\n");
	  printf("！3:统计字符串中的字符类型和数量！\n\n\n");
#pragma endregion

#pragma region 功能
	 	while (true)
	{	
		//每一次操作结束后，新的操作类型确定；
		printf("请输入操作类型(数字):");
    	scanf("%c",&x);
		//功能分区
		switch (x)
		{
		case '1':char a[10];
			printf("请输入英文字符串：");
			getchar();
			gets(a);
			printf("大写英文字符串:");
		    strupr(a);
			break;
		case '2':char a1[10];
			printf("请输入字符串：");
			getchar();
			gets(a1);
		    TNum(a1);
			break;
		case '3':char string[100];
			getchar();
			printf("请输入你想统计的字符语句：");
			gets(string);
			printf("统计的字符结果：\n");
			Word_Statistics(string);		
			printf("\n\n");
			break;
		default:printf("无此功能，请重新输入！\n\n");
			break;
		}
	}
#pragma endregion

	return 0;
}