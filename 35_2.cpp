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

	FILE* file = fopen("file2.txt", "r");
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	fseek(file, 0, SEEK_SET);

	FILE* result = fopen("file2_result.txt", "w");

	char* t = (char*)malloc(size * sizeof(char));
	char* r = (char*)malloc(size * sizeof(char));

	while (feof(file) == 0)
	{
		fgets(t, size, file);
		int i = 0;
		while (t[i] != '\n')
		{
			if (t[i] == '1')
			{
				t[i] = '0';
			}
			else if (t[i] == '0')
			{
				t[i] = '1';
			}
			i++;
		}
		fprintf(result, t);
	}




	//fprintf(result, t);

	free(t);
	fclose(file);
	fclose(result);
	system("pause");
	return 0;
}