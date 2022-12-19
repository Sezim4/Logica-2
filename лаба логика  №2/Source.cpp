#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
#define N 5
void tosgest(int** mas);
void stagivanie(int** mas);
void rascheplenie(int** mas);
void logical_or(int** mas1, int** mas2);
void logical_and(int** mas1, int** mas2);
void logical_xor(int** mas1, int** mas2);
void convert_matrix(int** mas1, int** mas2);
struct sp
{
	int num;
	sp* next;
};
sp* elem = NULL;
sp* MAS[N];
sp* MAS2[N];
void main()
{
	setlocale(LC_ALL, "rus");
	int** matrix1;
	int** matrix2;
	int i = 0;
	int j = 0;
	int ch = 0;
	int num = 0;
	matrix1 = (int**)malloc(N * sizeof(int));
	matrix2 = (int**)malloc(N * sizeof(int));
	for (i = 0; i < N; i++)
	{
		matrix1[i] = (int*)malloc(N * sizeof(int));
		matrix2[i] = (int*)malloc(N * sizeof(int));
	}

	srand(time(NULL));
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (i == j)
			{
				matrix1[i][j] = 0;
				continue;
			}

			if (rand() % 21 < 10) matrix1[i][j] = 1;
			else matrix1[i][j] = 0;
			matrix1[j][i] = matrix1[i][j];
		}

	}
	printf_s("Ìàòðèöà 1:\n");
	for (i = 0; i < N; i++)
	{
		printf_s("%d|", i);
		for (j = 0; j < N; j++)
		{
			printf_s("%d ", matrix1[i][j]);
		}
		printf_s("\n");
	}
	printf_s("\n");

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (i == j)
			{
				matrix2[i][j] = 0;
				continue;
			}

			if (rand() % 31 < 10) matrix2[i][j] = 1;
			else matrix2[i][j] = 0;
			matrix2[j][i] = matrix2[i][j];
		}

	}
	printf_s("Ìàòðèöà 2: \n");
	for (i = 0; i < N; i++)
	{
		printf_s("%d|", i);
		for (j = 0; j < N; j++)
		{
			printf_s("%d ", matrix2[i][j]);
		}
		printf_s("\n");
	}
	convert_matrix(matrix1, matrix2);
	printf_s("Ìàòðèöà 1:\n");
	for (i = 0; i < N; i++)
	{
		elem = MAS[i];
		while (elem != NULL)
		{
			printf_s("%d->", elem->num);
			elem = elem->next;
		}
		printf_s("\n");
	}
	printf_s("Ìàòðèöà 2:\n");
	for (i = 0; i < N; i++)
	{
		elem = MAS2[i];
		while (elem != NULL)
		{
			printf_s("%d->", elem->num);
			elem = elem->next;
		}
		printf_s("\n");
	}
	while (1)
	{
		printf_s("\nÂâåäèòå äåéñòâèå:\n1-Îòîæäåñòâëåíèå\n2-Ñòÿãèâàíèå\n3-Ðàñùåïëåíèå\n4-Îáúåäèíåíèå\n5-Ïåðåñå÷åíèå\n6-Êîëüöåâàÿ ñóììà\n0-Çàâåðøåíèå\n");
		scanf_s("%d", &ch);
		if (ch == 0) break;
		switch (ch)
		{
		case 1:
		{
			printf_s("Ââåäèòå íîìåð ãðàôà: ");
			scanf_s("%d", &num);
			if (num == 1) tosgest(matrix1);
			if (num == 2) tosgest(matrix2);
			if ((num != 1) && (num != 2))printf_s("Ãðàô íå ñóùåñòâóåò.\n");
		}
		break;
		case 2:
		{
			printf_s("Ââåäèòå íîìåð ãðàôà: ");
			scanf_s("%d", &num);
			if (num == 1) stagivanie(matrix1);
			if (num == 2) stagivanie(matrix2);
			if ((num != 1) && (num != 2))printf_s("Ãðàô íå ñóùåñòâóåò.\n");
		}
		break;
		case 3:
		{
			printf_s("Ââåäèòå íîìåð ãðàôà: ");
			scanf_s("%d", &num);
			if (num == 1) rascheplenie(matrix1);
			if (num == 2) rascheplenie(matrix2);
			if ((num != 1) && (num != 2))printf_s("Ãðàô íå ñóùåñòâóåò.\n");
		}
		break;
		case 4:
			logical_or(matrix1, matrix2);
			break;
		case 5:
			logical_and(matrix1, matrix2);
			break;
		case 6:
			logical_xor(matrix1, matrix2);
			break;
		}

	};
}

void tosgest(int** mas)
{
	int a, b;
	int matr1[N][N] = { 0 };
	int matr2[N - 1][N - 1] = { 0 };
	int m[N - 1];
	int j = 0;
	int i = 0;
	int r = 0;
	a = b = 0;
label:
	printf_s("Ââåäèòå âåðøèíó 1: ");
	scanf_s("%d", &a);
	printf_s("Ââåäèòå âåðøèíó 2: ");
	scanf_s("%d", &b);
	if (a > b)
	{
		i = b;
		b = a;
		a = i;
	}
	if (a == b)
	{
		printf_s("Îøèáêà\n");
		goto label;
	}

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
		{
			matr1[i][j] = mas[i][j];
		}
	for (j = 0; j < N; j++)
	{
		if ((mas[j][a] == 0) && (mas[j][b] == 0)) matr1[j][a] = 0;
		else matr1[j][a] = 1;

		if ((mas[a][j] == 0) && (mas[b][j] == 0)) matr1[a][j] = 0;
		else matr1[a][j] = 1;
	}
	for (i = 0; i < (N - 1); i++)
	{
		if (i == b)
		{
			r = i + 1;
		}
		m[i] = matr1[a][r];
		r = r++;
	}//â ìàññèâ çàïèñûâàåòñÿ ñòðîêà, å¸ íóæíî âñòàâèòü â ðåçóëüòèðóþùóþ ìàòðèöó.
	r = 0;//ñ÷åò÷èê ñòðîêè ñ ðåçóëüòàòîì ñëîæåíèÿ
	int q = 0;
	int g = 0;//Ñ÷åò÷èêè äëÿ ìàññèâà mas[]
	for (i = 0; i < (N - 1); i++)
	{
		j = 0;
		if (i == a)
		{
			j = 0;
			while (j != (N - 1))
			{
				matr2[i][j] = m[j];
				j++;
			}
			i++;
			j = 0;
			q = i + 1;
			r++;
		}
		g = 0;
		while (j < a)
		{
			matr2[i][j] = matr1[q][g];
			j++; g++;
		}
		if (j == a) {
			matr2[i][j] = m[r];
			r++; j++; g = g + 2;
		}
		while (j < (N - 1))
		{
			matr2[i][j] = matr1[q][g];
			j++; g++;
		}
		q = q++;

	}
	printf_s("Ðåçóëüòàò îòîæäåñòâëåíèÿ:\n");
	for (i = 0; i < (N - 1); i++)
	{
		if (i == a) printf_s("%d`|", i);
		else
			printf_s("%d|", i);
		for (j = 0; j < (N - 1); j++)
		{
			printf_s("%d ", matr2[i][j]);
		}
		printf_s("\n");
	}

}
void stagivanie(int** mas)
{
	int a, b;
	int matr1[N][N] = { 0 };
	int matr2[N - 1][N - 1] = { 0 };
	int m[N - 1];
	int j = 0;
	int i = 0;
	int r = 0;
	int flag = 0;
	a = b = 0;
label:
	printf_s("Ââåäèòå âåðøèíó 1: ");
	scanf_s("%d", &a);
	printf_s("Ââåäèòå âåðøèíó 2: ");
	scanf_s("%d", &b);
	if (mas[a][b] != 1)
	{
		printf_s("Âåðøèíû íåñìåæíû, ñòÿãèâàíèå íåâîçìîæíî");
	}
	if (a > b)
	{
		i = b;
		b = a;
		a = i;
	}
	if (a == b)
	{
		printf_s("Îøèáêà\n");
		goto label;
	}
	//Ïðîâåðêà, åñòü ëè ïåòëÿ
	if ((mas[a][a] == 1) || (mas[b][b] == 1)) flag = 1;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
		{
			matr1[i][j] = mas[i][j];
		}
	for (j = 0; j < N; j++)
	{
		if ((mas[j][a] == 0) && (mas[j][b] == 0)) matr1[j][a] = 0;
		else matr1[j][a] = 1;

		if ((mas[a][j] == 0) && (mas[b][j] == 0)) matr1[a][j] = 0;
		else matr1[a][j] = 1;
	}
	for (i = 0; i < (N - 1); i++)
	{
		if (i == b)
		{
			r = i + 1;
		}
		m[i] = matr1[a][r];
		r = r++;
	}//â ìàññèâ çàïèñûâàåòñÿ ñòðîêà, å¸ íóæíî âñòàâèòü â ðåçóëüòèðóþùóþ ìàòðèöó.
	r = 0;//ñ÷åò÷èê ñòðîêè ñ ðåçóëüòàòîì ñëîæåíèÿ
	int q = 0;
	int g = 0;//Ñ÷åò÷èêè äëÿ ìàññèâà mas[]
	for (i = 0; i < (N - 1); i++)
	{
		j = 0;
		if (i == a)
		{
			j = 0;
			while (j != (N - 1))
			{
				matr2[i][j] = m[j];
				j++;
			}
			i++;
			j = 0;
			q = i + 1;
			r++;
		}
		g = 0;
		while (j < a)
		{
			matr2[i][j] = matr1[q][g];
			j++; g++;
		}
		if (j == a) {
			matr2[i][j] = m[r];
			r++; j++; g = g + 2;
		}
		while (j < (N - 1))
		{
			matr2[i][j] = matr1[q][g];
			j++; g++;
		}
		q = q++;

	}
	//Ïðîâåðêà, áûëà ïåòëÿ èëè íåò:
	if (flag == 1) matr2[a][a] = 1;
	else matr2[a][a] = 0;

	printf_s("Ðåçóëüòàò ñòÿãèâàíèÿ ðåáðà:\n");
	for (i = 0; i < (N - 1); i++)
	{
		if (i == a) printf_s("%d`|", i);
		else
			printf_s("%d|", i);
		for (j = 0; j < (N - 1); j++)
		{
			printf_s("%d ", matr2[i][j]);
		}
		printf_s("\n");
	}

}
void rascheplenie(int** mas)
{
	int a = 0;
	int matr[N + 1][N + 1] = { 0 };
	int m[N + 1];
	int j = 0;
	int i = 0;
	int r = 0;
	printf_s("Ââåäèòå âåðøèíó äëÿ ðàñùåïëåíèÿ: ");
	scanf_s("%d", &a);
	for (i = 0; i < N; i++)
	{
		m[i] = mas[a][i];
	}
	m[N] = 0;
	i = 0;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
		{
			matr[i][j] = mas[i][j];
		}
	for (i = 0; i < (N + 1); i++)
		matr[N][i] = m[i];
	for (i = 0; i < (N + 1); i++)
		matr[i][N] = m[i];

	matr[a][N] = 1;
	matr[N][a] = 1;
	printf_s("Ðåçóëüòàò ðàñùåïëåíèÿ âåðøèíû (íîâàÿ âåðøèíà äîáàâëåíà â êîíåö ìàòðèöû):\n");
	for (i = 0; i < (N + 1); i++)
	{
		printf_s("%d|", i);
		for (j = 0; j < (N + 1); j++)
		{
			printf_s("%d ", matr[i][j]);
		}
		printf_s("\n");
	}
}
void logical_or(int** mas1, int** mas2)
{
	int result_mas[N][N] = { 0 };
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			result_mas[i][j] = mas1[i][j] | mas2[i][j];
		}
	printf_s("\nÐåçóëüòàò îáúåäèíåíèÿ: \n");
	for (int i = 0; i < N; i++)
	{
		printf_s("%d|", i);
		for (int j = 0; j < N; j++)
		{
			printf_s(" %d", result_mas[i][j]);
		}
		printf_s("\n");
	}
}
void logical_and(int** mas1, int** mas2)
{
	int result_mas[N][N] = { 0 };
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			result_mas[i][j] = mas1[i][j] & mas2[i][j];
		}
	printf_s("\nÐåçóëüòàò ïåðåñå÷åíèÿ: \n");
	for (int i = 0; i < N; i++)
	{
		printf_s("%d|", i);
		for (int j = 0; j < N; j++)
		{
			printf_s(" %d", result_mas[i][j]);
		}
		printf_s("\n");
	}
}
void logical_xor(int** mas1, int** mas2)
{
	int result_mas[N][N] = { 0 };
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			result_mas[i][j] = mas1[i][j] ^ mas2[i][j];
		}
	printf_s("\nÐåçóëüòàò êîëüöåâîé ñóììû: \n");
	for (int i = 0; i < N; i++)
	{
		printf_s("%d|", i);
		for (int j = 0; j < N; j++)
		{
			printf_s(" %d", result_mas[i][j]);
		}
		printf_s("\n");
	}
}
void convert_matrix(int** mas1, int** mas2)
{
	int i = 0;
	int j = 0;
	sp* new_elem = NULL;
	for (i = 0; i < N; i++)
	{
		elem = (sp*)malloc(sizeof(sp));
		elem->num = i;
		elem->next = NULL;
		MAS[i] = elem;
		for (j = 0; j < N; j++)
		{
			if (mas1[i][j] == 1)
			{
				new_elem = (sp*)malloc(sizeof(sp));
				new_elem->num = j;
				new_elem->next = NULL;
				elem->next = new_elem;
				elem = new_elem;
			}
		}
	}


	for (i = 0; i < N; i++)
	{
		elem = (sp*)malloc(sizeof(sp));
		elem->num = i;
		elem->next = NULL;
		MAS2[i] = elem;
		for (j = 0; j < N; j++)
		{
			if (mas2[i][j] == 1)
			{
				new_elem = (sp*)malloc(sizeof(sp));
				new_elem->num = j;
				new_elem->next = NULL;
				elem->next = new_elem;
				elem = new_elem;
			}
		}
	}
}
