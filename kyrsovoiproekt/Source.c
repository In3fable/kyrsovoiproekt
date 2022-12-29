#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


struct gonka {
	char name[50];
	int time;
	float distance;
	int complexity;
	int avg_speed;
};
typedef struct gonka GONKA;

GONKA* add(GONKA* gon, int* count, int size);
void vivod(GONKA* gon, int* count);
int* searchdist(GONKA* gon, int* count, int kr);
int searchname(GONKA* gon, int* count, char* kr);
GONKA* sort(GONKA* gon, int* count);
int write(char* namefile, GONKA* gon, int* count);
int read(char* namefile, GONKA* gon, int size_mas);
int prov(char* namefile);
int main()
{
	system("chcp 1251");
	system("cls");
	GONKA* gon;
	int kol = 0, flag1 = 1, choice1, nom, size_mas = 0, size_mas1 = 0, mas_in_file, kr2,k=0;
	gon = (GONKA*)malloc(kol * sizeof(GONKA));
	char namefile[100], kr1[10];
	int* nom1;
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
		printf("Выберите функцию\n1.Ввод значений.\n2.Вывод значений\n3.Поиск структуры по названию соревнований\n4.Поиск структуры по длине трассы (больше N)\n5.Сортировка данных\n6.Запись данных в файл\n7.Чтение данных из файла\n0.Выход из программы\n");
		scanf("%d", &choice1);
		system("cls");
		switch (choice1)
		{
		case 1:
			system("cls");
			printf("Введите кол-во записей ");
			scanf("%d", &kol);
			printf("------------------------\n");
			size_mas1 = kol;
			kol += size_mas;
			gon = (GONKA*)realloc(gon, kol * sizeof(GONKA));
			add(gon, &kol, size_mas);
			size_mas += size_mas1;
			break;


		case 2:

			vivod(gon, &kol);
			system("pause");
			break;


		case 3:
			printf("Введите название соревнований\n");
			scanf("%s", kr1);
			nom = searchname(gon, &kol, kr1);
			printf("---------------------------------------------------------------------------------------------------------------------------\n");
			printf("|| Название соревнований || Продолжительность гонки(мин) || Длина трассы(метры) || Сложность || Средняя скорость(км / ч) || \n");
			printf("---------------------------------------------------------------------------------------------------------------------------\n");
			printf("||%23s||%26d Мин||%19f М||%11d||%21d Км/ч||\n", gon[nom].name, gon[nom].time, gon[nom].distance, gon[nom].complexity, gon[nom].avg_speed);
			printf("---------------------------------------------------------------------------------------------------------------------------\n");
			system("pause");
			break;
		case 4:
			printf("Введите длину трассы\n");
			scanf("%d", &kr2);
			nom1 = searchdist(gon, &kol, kr2);
			printf("---------------------------------------------------------------------------------------------------------------------------\n");
			printf("|| Название соревнований || Продолжительность гонки(мин) || Длина трассы(метры) || Сложность || Средняя скорость(км / ч) || \n");
			printf("---------------------------------------------------------------------------------------------------------------------------\n");
			for (int i = 0; i < kol; i++)
			{
				if (nom1[i] >= 0 && nom1[i] < kol)
				{
					k = nom1[i];
					
					printf("||%23s||%26d Мин||%19f М||%11d||%21d Км/ч||\n", gon[k].name, gon[k].time, gon[k].distance, gon[k].complexity, gon[k].avg_speed);
					printf("---------------------------------------------------------------------------------------------------------------------------\n");
				}
			}
			system("pause");
			break;
		case 5:
			sort(gon, &kol);
			vivod(gon, &kol);
			system("pause");
			break;
		case 6:
			printf("Введите название файла\n");
			scanf("%s", &namefile);
			write(namefile, gon, &kol);
			break;
		case 7:

			printf("Введите название файла\n");
			scanf("%s", &namefile);
			mas_in_file= prov(namefile);
			kol += mas_in_file;
			gon = (GONKA*)realloc(gon, kol * sizeof(GONKA));
			kol = read(namefile, gon, size_mas);
			kol += size_mas;
			size_mas += mas_in_file;
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

GONKA* add(GONKA* gon, int* count, int size_mas)
{
	for (int z = size_mas; z < *count; z++)
	{
		printf("Введите название соревнований = ");
		scanf("%s", &gon[z].name);
		printf("Продолжительность гонки (в минутах) = ");
		scanf("%d", &gon[z].time);
		printf("Длина трассы(в метрах) = ");
		scanf("%f", &gon[z].distance);
		printf("Сложность = ");
		scanf("%d", &gon[z].complexity);
		printf("Введите среднюю скорость = ");
		scanf("%d", &gon[z].avg_speed);
		printf("\n");
	}
	return gon;
}
void vivod(GONKA* gon, int* count)
{
	printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("|| Номер  || Название соревнований  ||  Продолжительность гонки(мин)  ||  Длина трассы(метры)  ||  Сложность  ||  Средняя скорость(км/ч)  ||\n");
	printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
	for (int q = 0; q < *count; q++)
	{
		printf("||%8d||%24s||%28d Мин||%21f М||%13d||%21d Км/ч||\n", q + 1, gon[q].name, gon[q].time, gon[q].distance, gon[q].complexity, gon[q].avg_speed);
		printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
	}

}
int searchname(GONKA* gon, int* count, char* kr)
{

	int num = -1;
	for (int i = 0; i < *count; i++)
	{
		if (strcmp(gon[i].name, kr) == 0)
		{
			num= i;
		}



	}
	return num;


}
int* searchdist(GONKA* gon, int* count, int kr)
{

	int* num = (int*)malloc(*count * sizeof(int));

	int n = 0;

	for (int i = 0; i < *count; i++)
	{
		if (gon[i].distance >= kr)
		{
			num[n++] = i;
		}

	}
	return num;
}
GONKA* sort(GONKA* gon, int* count)
{
	system("cls");
	GONKA sort;
	for (int q = *count - 1; q >= 0; q--)
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
	return gon;
}
int write(char* namefile, GONKA* gon, int* count)
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
		for (i = 0; i < *count; i++)
		{
			fprintf(data, "%d\n", i + 1);
			fprintf(data, "%s\n", gon[i].name);
			fprintf(data, "%f\n", gon[i].distance);
			fprintf(data, "%d\n", gon[i].time);
			fprintf(data, "%d\n", gon[i].complexity);
			fprintf(data, "%d\n", gon[i].avg_speed);


		}
		fclose(data);
		printf("Данные записаны\n");
		system("pause");
	}
}
int read(char* namefile, GONKA* gon, int size_mas)
{
	FILE* open;
	int z;
	int  i = size_mas;
	int o = 0;
	open = fopen(namefile, "rb");
	while (!feof(open))
	{
		fscanf(open, "\r\n%d\r\n", &z);
		fscanf(open, "%s\r\n", gon[i].name);
		fscanf(open, "%f\r\n", &gon[i].distance);
		fscanf(open, "%d\r\n", &gon[i].time);
		fscanf(open, "%d\r\n", &gon[i].complexity);
		fscanf(open, "%d\r\n", &gon[i].avg_speed);
		i += 1;
		o += 1;
	}
	fclose(open);
	printf("Файл успешно прочитан!\n");
	return o;
}
int prov(char* namefile)
{
	FILE* open;
	int  i = 0;
	open = fopen(namefile, "rb");
	while (!feof(open))
	{
		if (fgetc(open) == '\n')
			i += 1;
	}
	fclose(open);
	return i / 6;
}
