/*************************************************************************
> File Name: main.c
> Author: yuhaitao
> Mail:acer_yuhaitao@163.com
> Created Time: Tue 25 Oct 2016 11:56:51 PM PDT
************************************************************************/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <iostream>
#define N 1024

void show()
{
	printf("+++++++++++++++++++++++++++++++++++++++++++\n");
	printf("              处方文件配置                  \n");
	printf("+++++++++++++++++++++++++++++++++++++++++++\n");
}

int data_in(int *min, int *max)
{
	puts("请输入开始编号(正整数)>");
	scanf("%d", min);
	puts("请输入结束编号(正整数)>");
	scanf("%d", max);
	return 0;
}

#if 0
int update_class_test(int i, char update[N])
{
	if (i < 10)
	{
		sprintf(update, "<PATIENT_NAME>测试00%d</PATIENT_NAME>\n", i);
	}
	else if (i > 10 && i < 100)
	{
		sprintf(update, "<PATIENT_NAME>测试0%d</PATIENT_NAME>\n", i);
	}
	else
	{
		sprintf(update, "<PATIENT_NAME>测试%d</PATIENT_NAME>\n", i);
	}

	return 0;
}
#endif

int main(int argc, char *argv[])
{
	int i = 0, min = 0, max = 0;
	char Newfile[N] = { 0 };
	char buf[N] = { 0 };
	char update[N] = { 0 };
	show();
	data_in(&min, &max);

	printf("您输入的范围%d-->%d\n",min, max);

	for (i = min; i <= max; i++)
	{
		if (i < 10)
		{
			sprintf(Newfile, "Prescription201609230000%d.xml", i);
		}
		else if(i >= 10 && i < 100)
		{
			sprintf(Newfile, "Prescription20160923000%d.xml", i);
		}
		else
		{
			sprintf(Newfile, "Prescription2016092300%d.xml", i);
		}

		FILE *in = fopen("Prescription2016092300XXX.xml", "r");
		FILE *out = fopen(Newfile, "w");  /*out是充当临时文件作用*/
		int linesize = 0;
		char *p = NULL;

		if (!in)
		{
			printf("cann't open Prescription2016092300101.xml\n");
			system("pause");
			return -1;
		}
		if (!out)
		{
			printf("cann't create Prescription2016092300XX.xml\n");
			system("pause");
			return -1;
		}
		/*开始复制*/
#if 0
		while (!feof(in))
		{
			ch = fgetc(in);
			if (ch == 'a') ch = 'p';
			fputc(ch, out);
		}
#endif
		while (fgets(buf, N, in) != NULL)
		{
#if 0
			linesize = strlen(buf);
			printf("%d\n", linesize);
			if (buf[linesize - 1] == '\n')
			{				
				buf[linesize - 1] = '\0';
			}
#endif
			if ((p = strstr(buf, "测试")) != NULL)
			{
				//sprintf(update, "<PATIENT_NAME>测试%d</PATIENT_NAME>\n", i);
				if (i < 10)
				{
					sprintf(update, "<PATIENT_NAME>测试00%d</PATIENT_NAME>\n", i);
				}
				else if (i >= 10 && i < 100)
				{
					sprintf(update, "<PATIENT_NAME>测试0%d</PATIENT_NAME>\n", i);
				}
				else
				{
					sprintf(update, "<PATIENT_NAME>测试%d</PATIENT_NAME>\n", i);
				}
				fputs(update, out);
			}
			else if ((p = strstr(buf, "<PATIENT_ID>")) != NULL)
			{
				//sprintf(update, "<PATIENT_ID>%d</PATIENT_ID>\n", i);
				if (i < 10)
				{
					sprintf(update, "<PATIENT_ID>00%d</PATIENT_ID>\n", i);
				}
				else if (i >= 10 && i < 100)
				{
					sprintf(update, "<PATIENT_ID>0%d</PATIENT_ID>\n", i);
				}
				else
				{
					sprintf(update, "<PATIENT_ID>%d</PATIENT_ID>\n", i);
				}
				fputs(update, out);
			}
			else if ((p = strstr(buf, "PRESCRIPTION_ID=")) != NULL)
			{
				//sprintf(update, " <PRESCRIPTION PRESCRIPTION_ID=\"2016092300%d\" PRESCRIPTION_DATE_TIME=\"2016-03-17T00:00:00\" ORDERED_BY=\"中医科门诊\" PRESCRIBER=\"任芳\" PRESCRIPTION_SOURCE=\"0\" DIAGNOSIS=\"乏力(气血两虚)\">", i);
				if (i < 10)
				{
					sprintf(update, " <PRESCRIPTION PRESCRIPTION_ID=\"201609230000%d\" PRESCRIPTION_DATE_TIME=\"2016-03-17T00:00:00\" ORDERED_BY=\"中医科门诊\" PRESCRIBER=\"任芳\" PRESCRIPTION_SOURCE=\"0\" DIAGNOSIS=\"乏力(气血两虚)\">", i);
				}
				else if (i >= 10 && i < 100)
				{
					sprintf(update, " <PRESCRIPTION PRESCRIPTION_ID=\"20160923000%d\" PRESCRIPTION_DATE_TIME=\"2016-03-17T00:00:00\" ORDERED_BY=\"中医科门诊\" PRESCRIBER=\"任芳\" PRESCRIPTION_SOURCE=\"0\" DIAGNOSIS=\"乏力(气血两虚)\">", i);
				}
				else
				{
					sprintf(update, " <PRESCRIPTION PRESCRIPTION_ID=\"2016092300%d\" PRESCRIPTION_DATE_TIME=\"2016-03-17T00:00:00\" ORDERED_BY=\"中医科门诊\" PRESCRIBER=\"任芳\" PRESCRIPTION_SOURCE=\"0\" DIAGNOSIS=\"乏力(气血两虚)\">", i);
				}
				fputs(update, out);
			}
			else
			{
				fputs(buf, out);
			}
		}

		fclose(in);
		fclose(out);

#if 0
		_unlink(Newfile); /*删除test.txt*/
		//	rename("f:\\back.txt","test.txt"); /*改名*/
#endif
		if (i < 10)
		{
			printf("Prescription201609230000%d.xml\n", i);
		}
		else if (i >= 10 && i < 100)
		{
			printf("Prescription20160923000%d.xml\n", i);
		}
		else
		{
			printf("Prescription2016092300%d.xml\n", i);
		}
	}

	system("pause");
	return 0;
}