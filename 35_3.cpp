#include <iostream>
#include <cstdlib>
#include <utility>
#include <time.h>
#include <cstring>
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <stdarg.h>



int main()
{
	setlocale(LC_ALL, "Russian");
	int size = 0, count = 0;
	char m[5][1000] = { "qwert1","qwe2","qwer3","qweerdfs4","qwer5" };

	FILE* result = fopen("file3_result.txt", "w");
	for (int i = 0; i < 5; i++)
	{
		fprintf(result, m[i]);
		fprintf(result, "\n");
	}

	//fprintf(result, t);


	fclose(result);
	system("pause");
	return 0;
}