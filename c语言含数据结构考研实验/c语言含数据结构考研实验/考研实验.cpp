#include "stdio.h"

#pragma region ���ݽṹ����
//�ַ�ͳ�ƽṹ
typedef struct WordStatistics
{
	char word;//�ַ�����
	int count;//�ַ�����
};
#pragma endregion

#pragma region ��������
#pragma region string�����ַ�������αԴ��
//Сд��ĸ����д��ĸ��
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
#pragma region �ַ�����ȡ����
void TNum(char str[]){
	int m=0,i;
	for ( i = 0; str[i]!='\0'; i++)
	{
		if (str[i]>='0'&&str[i]<='9')
		{
			m=m*10+str[i]-'0';
		}	
	}
	printf("��ȡ������Ϊ:%d\n\n",m);
}
#pragma endregion
#pragma region �ַ���ͳ���ַ����ͺ���
void Word_Statistics(char string[]){
	WordStatistics str[100];//�����ַ�ͳ������
	WordStatistics a;
	int count=0;//�ַ�ͳ��������±�
	for (int i = 0; string[i]!='\0'; i++)
	{
		int j=0;
		//��һ���ַ�ֱ�Ӵ���
		if (i==0)
		{		
			a.word=string[i];
			a.count=1;
			str[count++]=a;
			str[count++].word='#';
			continue;
		}
		//����һ�����������ַ���ͳ���ַ�����Ƚϣ���ͬ���������һ������ѭ����
		while (str[j].word!='#')
		{
			if (str[j].word==string[i])
			{
				str[j].count++;
				break;
			}
			j++;
		}

		//�ַ���ͳ���ַ�������ͬ�����ȴ���һ���µ�ͳ���ַ���
		if (str[j].word=='#')
		{
			a.word=string[i];
			a.count=1;
			str[j]=a;
			str[j+1].word='#';
		}
	}

    //���ͳ�ƽ��
	for (int i = 0; str[i].word!='#' ; i++)
	{
		printf("�ַ���%C��������%d\t",str[i].word,str[i].count);
		if (i%4==0&&i!=0)
		{
			printf("\n");
		}
	}
}
#pragma endregion
#pragma endregion


int main(){
#pragma region �������Ͷ���
	 char x;//��ʶ�Ƿ�������ͣ�
#pragma endregion
  
#pragma region ����
	 printf("\t\t\t\t\t   ������C���Ժ����ݽṹ����ʵ�飡����\n\n");
#pragma endregion

#pragma region ����˵��
	  printf("����������������������������������\n");
	  printf("����������������ָ�ϣ�������������\n");
	  printf("����������0:�˳�ϵͳ��������������\n");
	  printf("����1:��ĸСд�ַ���ת��д��������\n");
	  printf("����2:��ȡ�ַ����е����֣���������\n");
	  printf("��3:ͳ���ַ����е��ַ����ͺ�������\n\n\n");
#pragma endregion

#pragma region ����
	 	while (true)
	{	
		//ÿһ�β����������µĲ�������ȷ����
		printf("�������������(����):");
    	scanf("%c",&x);
		//���ܷ���
		switch (x)
		{
		case '1':char a[10];
			printf("������Ӣ���ַ�����");
			getchar();
			gets(a);
			printf("��дӢ���ַ���:");
		    strupr(a);
			break;
		case '2':char a1[10];
			printf("�������ַ�����");
			getchar();
			gets(a1);
		    TNum(a1);
			break;
		case '3':char string[100];
			getchar();
			printf("����������ͳ�Ƶ��ַ���䣺");
			gets(string);
			printf("ͳ�Ƶ��ַ������\n");
			Word_Statistics(string);		
			printf("\n\n");
			break;
		default:printf("�޴˹��ܣ����������룡\n\n");
			break;
		}
	}
#pragma endregion

	return 0;
}