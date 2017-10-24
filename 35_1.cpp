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
	char s;
	std::cout << "symbol: ";
	std::cin >> s;
	char* line = NULL;
	FILE* file = fopen("file1.txt", "r");
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	fseek(file, 0, SEEK_SET);

	char* t = (char*)malloc(size * sizeof(char));
	fgets(t, size, file);

	int i = 0;
	if (t[0] == s)
	{
		count++;
	}
	while (i < size)
	{
		if (t[i] == ' ')
		{
			i++;
			if (t[i] == s)
			{
				count++;
			}
		}
		i++;
	}

	std::cout << count << '\n';


	fclose(file);
	system("pause");
	return 0;
}