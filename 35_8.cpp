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
	int size = 0, count = 0, cc = 0;

	FILE* file = fopen("file5.txt", "r");
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	fseek(file, 0, SEEK_SET);

	char* t = (char*)malloc(size * sizeof(char));

	while (feof(file) == 0)
	{
		fgets(t, size, file);
		count++;
	}
	fseek(file, 0, SEEK_SET);

	char** l_m = (char**)malloc(count * sizeof(char*));
	for (int i = 0; i < count; i++)
	{
		char m[1000];
		fgets(m, size, file);
		l_m[i] = (char*)malloc(strlen(m) * sizeof(char));
		strcpy(l_m[i], m);
	}
	fseek(file, 0, SEEK_SET);
	char find[100];
	std::cin >> find;
	int q = strlen(find);
	find[q] = ' ';
	find[q + 1] = '\0';


	for (int i = 0; i < count; i++)
	{
		if (strstr(l_m[i], find) != NULL)
		{
			cc++;
		}
	}
	std::cout << cc << '\n';

	fclose(file);


	system("pause");
	return 0;
}