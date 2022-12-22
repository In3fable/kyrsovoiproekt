#define _CRT_SECURE_NO_WARNINGS
#define N 50
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


struct gonka {
	char* name[N];
	int time;
	float distance;
	int complexity;
	int avg_speed;
};
typedef struct gonka GONKA;

GONKA add(GONKA* gon, int count);
void vivod(GONKA* gon, int count);
GONKA searchdist(GONKA* gon, int count);
GONKA searchname(GONKA* gon, int count);
GONKA sort(GONKA* gon, int count);
int write(char* namefile, GONKA* gon, int count);
GONKA read(char* namefile);
int main()
{
	system("chcp 1251");
	system("cls");
	setlocale(LC_ALL, "Rus");
	int kol=0, flag1 = 1, choice1, choice2, compl,kol1,z;
	char namefile[100];
	GONKA* gon;
	gon = (GONKA*)malloc(50 * sizeof(GONKA));
	printf("***************************************\n");
	printf("*             База данных             *\n");
	printf("*Тема: Гонки                          *\n");
	printf("*Выполнил: Белоусов Даниил Алексеевич *\n");
	printf("*Группа: бИСТ-221                     *\n");
	printf("***************************************\n");
	system("pause");
	while (flag1)
	{
		system("cls");
		printf("Выберите функцию\n1.Ввод значений.\n2.Вывод значений\n3.Поиск структуры по названию соревнований\n4.Поиск структуры по длинне трассы\n5.Сортировка данных\n6.Запись данных в файл\n7.Чтение данных из файла\n0.Выход из программы\n");
		scanf("%d", &choice1);
		system("cls");
		switch (choice1)
		{
		case 1:
			printf("Введите кол-во записей, которое хотите добавить\n");
			scanf("%d", &kol);
			gon = (GONKA*)realloc(gon, kol * sizeof(GONKA));
			add(gon, kol);
			break;


		case 2:

			vivod(gon, kol);
			break;


		case 3:
			searchname(gon, kol);
			system("pause");
			break;
		case 4:
			searchdist(gon, kol);
			system("pause");
			break;
		case 5:
			sort(gon, kol);
			break;
		case 6:
			printf("Введите название файла\n");
			scanf("%s", &namefile);
			write(namefile, gon, kol);
			break;
		case 7:
			printf("Введите название файла\n");
			scanf("%s", &namefile);
			read(namefile, gon);
			system("pause");
			break;

		case 0:

			flag1 = 0;
			printf("Программа заверешна\n");
			break;
		default:
			puts("Данный выбор невозможен");

		}

	}
	free(gon);
	system("pause");
}

GONKA add(GONKA* gon, int count)
{
	for (int z = 0; z < count; z++)
	{
		printf("Введите название соревнований = ");
		scanf("%s", gon->name);
		printf("Продолжительность гонки (в минутах) = ");
		scanf("%d", &gon->time);
		printf("Длина трассы(в метрах) = ");
		scanf("%f", &gon->distance);
		printf("Сложность = ");
		scanf("%d", &gon->complexity);
		printf("Введите среднюю скорость = ");
		scanf("%d", &gon->avg_speed);
		printf("\n");
		gon++;
	}
	return *gon;
}
void vivod(GONKA* gon, int count)
{
	printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("|| Номер  || Название соревнований  ||  Продолжительность гонки(мин)  ||  Длина трассы(метры)  ||  Сложность  ||  Средняя скорость(км/ч)  ||\n");
	printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
	for (int q = 0; q < count; q++)
	{
		printf("||%8d||%24s||%28d Мин||%21f М||%13d||%21d Км/ч||\n", q + 1, gon[q].name, gon[q].time, gon[q].distance, gon[q].complexity, gon[q].avg_speed);
		printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
		gon++;
	}
	system("pause");
	return 0;

}
GONKA searchname(GONKA* gon, int count)
{
	char kr1[10];
	int choice, kr2, kr3, kr4, kr5, flag2 = 1;
	printf("Введите название соревнований\n");
	scanf("%s", kr1);
	printf("---------------------------------------------------------------------------------------------------------------------------\n");
	printf("|| Название соревнований || Продолжительность гонки(мин) || Длина трассы(метры) || Сложность || Средняя скорость(км / ч) || \n");
	printf("---------------------------------------------------------------------------------------------------------------------------\n");
	for (int i = 0; i < count; i++)
	{
		if (strcmp((gon + i)->name, kr1) == 0)
		{
			printf("||%23s||%26d Мин||%19f М||%11d||%21d Км/ч||\n", (gon + count)->name, (gon + count)->time, (gon + count)->distance, (gon + count)->complexity, (gon + count)->avg_speed);
			printf("---------------------------------------------------------------------------------------------------------------------------\n");
		}


	}
	gon++;


	return *gon;
}
GONKA searchdist(GONKA* gon, int count)
{
	char kr1[10];
	int choice, kr2, kr3, kr4, kr5, flag2 = 1;
	printf("Введите длину трассы\n");
	scanf("%d", &kr3);
	printf("---------------------------------------------------------------------------------------------------------------------------\n");
	printf("|| Название соревнований || Продолжительность гонки(мин) || Длина трассы(метры) || Сложность || Средняя скорость(км / ч) || \n");
	printf("---------------------------------------------------------------------------------------------------------------------------\n");
		for (int i = 0; i < count; i++)
		{
			if ((gon + i)->distance >= kr3)
			{
				printf("||%23s||%26d Мин||%19f М||%11d||%21d Км/ч||\n", (gon + count)->name, (gon + count)->time, (gon + count)->distance, (gon + count)->complexity, (gon + count)->avg_speed);
				printf("---------------------------------------------------------------------------------------------------------------------------\n");
			}

		}
		gon++;

	return *gon;
}
GONKA sort(GONKA* gon, int count)
{
	system("cls");
	GONKA sort;
	for (int q = count - 1; q >= 0; q--)
	{
		for (int p = 0; p < q; p++)
		{
			if ((gon[p].avg_speed * gon[p].complexity) < (gon[p + 1].avg_speed * gon[p + 1].complexity))
			{
				sort = gon[p];
				gon[p] = gon[p + 1];
				gon[p + 1] = sort;
			}
		}
	}
	printf("Сортировка по Средней скорости * сложность в порядке убывания завершена\n");
	system("pause");
	system("cls");
	return *gon;
}
int write(char* namefile, GONKA* gon, int count)
{
	FILE* data;
	int i;
	if ((data = fopen(namefile, "wt")) == NULL)
	{
		fprintf(stderr, "Файл нельзя открыть для записи\n");
		system("pause");
		return -1;

	}
	else
	{
		for (i = 0; i < count; i++)
		{
			fprintf(data, "%d\n", i + 1);
			fprintf(data, "%s\n", gon[i].name);
			fprintf(data, "%f\n", gon[i].distance);
			fprintf(data, "%d\n",gon[i].time);
			fprintf(data, "%d\n",gon[i].complexity);
			fprintf(data, "%d\n",gon[i].avg_speed);
			

		}
		fclose(data);
		printf("Данные записаны\n");
		system("pause");
	}
	return 0;
}
GONKA read(char* namefile,GONKA* gon)
{
	FILE* open;
	char buffer[50];
	int n = 0;
	int z;
	open = fopen(namefile, "r");
	while (!feof(open)) {
		fgets(buffer, 100, open);
		n++;
	}
	n /= 6 ;
	gon = (GONKA*)malloc(n * sizeof(gon));
	fseek(open, 0, SEEK_SET);
	for (int i = 0; i < n; i++) {
		fscanf(open, "%d\n", &z);
		fgets(&gon[i].name, 10, open);
		fscanf(open, "%f\n", &gon[i].distance);
		fscanf(open, "%d\n", &gon[i].time);
		fscanf(open, "%d\n", &gon[i].complexity);
		fscanf(open, "%d\n", &gon[i].avg_speed);

	}
	fclose(open);
	printf("Файл успешно прочитан!\n");
	return *gon;
}
