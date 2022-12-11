#define _CRT_SECURE_NO_WARNINGS
#define N 50
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


struct gonka {
	char name[50];
	int time;
	int distance;
	int complexity;
	int avg_speed;
}*gon;

typedef struct gonka GONKA;
GONKA add(GONKA* gon, int count);
void vivod(GONKA* gon, int count);
void menu2(GONKA* gon, int count);
void menu1();
GONKA search(GONKA* gon, int count);
GONKA sort(GONKA* gon, int count);
int write(char* namefile, GONKA* gon, int count);
int read(char* namefile);
int main()
{
	system("chcp 1251");
	system("cls");
	setlocale(LC_ALL, "Rus");
	int kol = 0;
	gon = malloc(kol * sizeof(int));
	int flag1 = 1, choice1, choice2, compl;
	char namefile[100];
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
		printf("Выберите функцию\n1.Ввод значений.\n2.Вывод значений\n3.Поиск структуры по заданному критерию\n4.Сортировка данных\n5.Запись данных в файл\n6.Чтение данных из файла\n0.Выход из программы\n");
		scanf("%d", &choice1);
		system("cls");
		switch (choice1)
		{
		case 1:
			printf("Введите кол-во записей (меньше 50)\n");
			scanf("%d", &kol);
			add(gon, kol);
			break;


		case 2:

			vivod(gon, kol);
			break;


		case 3:
			search(gon, kol);
			system("pause");
			break;
		case 4:
			sort(gon, kol);
			break;
		case 5:
			printf("Введите название файла\n");
			scanf("%s", &namefile);
			write(namefile, gon, kol);
			break;
		case 6:
			printf("Введите название файла\n");
			scanf("%s", &namefile);
			read(namefile);
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
	if (count > 50)
	{
		printf("Недостаточно места для записи");

	}
	for (int z = 0; z < count; z++)
	{
		printf("Введите название соревнований = ");
		scanf("%s", gon->name);
		printf("Продолжительность гонки (в минутах) = ");
		scanf("%d", &gon->time);
		printf("Длина трассы(в метрах) = ");
		scanf("%d", &gon->distance);
		printf("Сложность = ");
		scanf("%d", &gon->complexity);
		printf("Введите среднюю скорость = ");
		scanf("%d", &gon->avg_speed);
		printf("\n");
		gon++;
	}
	return *gon;
}void vivod(GONKA* gon, int count)
{
	printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("|| Номер  || Название соревнований  ||  Продолжительность гонки(мин)  ||  Длина трассы(метры)  ||  Сложность  ||  Средняя скорость(км/ч)  ||\n");
	printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
	for (int q = 0; q < count; q++)
	{
		printf("||%8d||%24s||%28d Мин||%21d М||%13d||%21d Км/ч||\n", q + 1, gon->name, gon->time, gon->distance, gon->complexity, gon->avg_speed);
		printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
		gon++;
	}
	system("pause");
	return 0;

}
void menu2(GONKA* gon, int count)
{
	printf("||%23s||%26d Мин||%19d М||%11d||%21d Км/ч||\n", (gon + count)->name, (gon + count)->time, (gon + count)->distance, (gon + count)->complexity, (gon + count)->avg_speed);
	printf("---------------------------------------------------------------------------------------------------------------------------\n");
}
void menu1()
{
	printf("---------------------------------------------------------------------------------------------------------------------------\n");
	printf("|| Название соревнований || Продолжительность гонки(мин) || Длина трассы(метры) || Сложность || Средняя скорость(км / ч) || \n");
	printf("---------------------------------------------------------------------------------------------------------------------------\n");
}
GONKA search(GONKA* gon, int count)
{
	char kr1[10];
	int choice, kr2, kr3, kr4, kr5, flag2 = 1;
	printf("Выберите критерий поиска\n");
	printf("1.Название соревнований\n");
	printf("2.Сложность\n");
	printf("3.Продолжительность\n");
	printf("4.Длина трассы\n");
	printf("5.Средняя скорость\n");
	scanf("%d", &choice);
	if (choice == 1)
	{
		printf("Введите название соревнований\n");
		scanf("%s", kr1);
		menu1();
		for (int i = 0; i < count; i++)
		{
			if (strcmp((gon + i)->name, kr1) == 0)
			{
				menu2(gon, i);
			}


		}
		gon++;
	}
	if (choice == 2)
	{
		printf("Введите сложность\n");
		scanf("%d", &kr2);
		menu1();
		for (int i = 0; i < count; i++)
		{
			if ((gon + i)->complexity == kr2)
			{
				menu2(gon, i);
			}


		}
		gon++;
	}
	if (choice == 3)
	{
		printf("Введите продолжительность\n");
		scanf("%d", &kr4);
		menu1();
		for (int i = 0; i < count; i++)
		{
			if ((gon + i)->time == kr4)
			{
				menu2(gon, i);
			}

		}
		gon++;
	}
	if (choice == 4)
	{
		printf("Введите длину трассы\n");
		scanf("%d", &kr3);
		menu1();
		for (int i = 0; i < count; i++)
		{
			if ((gon + i)->distance == kr3)
			{
				menu2(gon, i);
			}

		}
		gon++;
	}
	if (choice == 5)
	{
		printf("Введите среднюю скорость\n");
		scanf("%d", &kr5);
		menu1();
		for (int i = 0; i < count; i++)
		{
			if ((gon + i)->avg_speed == kr5)
			{
				menu2(gon, i);
			}

		}
		gon++;
	}

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
		fprintf(data, "--------------------------------------------------------------------------------------------------------------------------------------------\n");
		fprintf(data, "|| Номер  || Название соревнований  ||  Продолжительность гонки(мин)  ||  Длина трассы(метры)  ||  Сложность  ||  Средняя скорость(км/ч)  ||\n");
		fprintf(data, "--------------------------------------------------------------------------------------------------------------------------------------------\n");
		for (i = 0; i < count; i++)
		{
			fprintf(data, "||%8d||%24s||%28d Мин||%21d М||%13d||%21d Км/ч||\n", i + 1, gon[i].name, gon[i].time, gon[i].distance, gon[i].complexity, gon[i].avg_speed);
			fprintf(data, "--------------------------------------------------------------------------------------------------------------------------------------------\n");
			

		}
		fclose(data);
		printf("Данные записаны\n");
		system("pause");
	}
	return 0;
}
int read(char* namefile)
{
	FILE* open;
	char file[200];
	open = fopen(namefile, "r");
	if (open != NULL)
	{
		printf("Файл открыт\n");
		while (!feof(open))
		{
			fgets(file, 200, open);
			if (!feof(open))
			{
				puts(file);
			}
		}
		return 1;
	}
	else
	{
		printf("Файл не удалось открыть\n");
		system("pause");
		return-1;
	}
	fclose(open);
	return 1;

}
