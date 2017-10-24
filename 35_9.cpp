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
	int size1 = 0, size2 = 0, count = 0, cc = 0;

	FILE* file1 = fopen("file6_1.txt", "r");
	fseek(file1, 0, SEEK_END);
	size1 = ftell(file1);
	fseek(file1, 0, SEEK_SET);

	FILE* file2 = fopen("file6_2.txt", "r");
	fseek(file2, 0, SEEK_END);
	size2 = ftell(file2);
	fseek(file2, 0, SEEK_SET);

	char* t1 = (char*)malloc(size1 * sizeof(char));
	char* t2 = (char*)malloc(size2 * sizeof(char));
	
	while (feof(file1) == 0)
	{
		int p = 0;
		fgets(t1, size1, file1);
		while (feof(file2) == 0)
		{
			fgets(t2, size2, file2);
			if (strstr(t2, t1) != NULL)
			{
				p++;
				break;
			}
		}
		if (p == 0)
		{
			std::cout << t1;
		}
		fseek(file2, 0, SEEK_SET);
	}
	fseek(file1, 0, SEEK_SET);
	fseek(file2, 0, SEEK_SET);
	while (feof(file2) == 0)
	{
		int p = 0;
		fgets(t2, size2, file2);
		while (feof(file1) == 0)
		{
			fgets(t1, size1, file1);
			if (strstr(t1, t2) != NULL)
			{
				p++;
				break;
			}
		}
		if (p == 0)
		{
			std::cout << t2;
		}
		fseek(file1, 0, SEEK_SET);
	}


	fclose(file1);
	fclose(file2);


	system("pause");
	return 0;
}