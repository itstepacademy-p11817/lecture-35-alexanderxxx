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
	int size = 0, count = 0, max_len = 0;

	FILE* file = fopen("file4.txt", "r");
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	fseek(file, 0, SEEK_SET);

	std::cout << "size: " << size << '\n';


	char* t = (char*)malloc(size * sizeof(char));


	while (feof(file) == 0)
	{
		fgets(t, size, file);
		if (strlen(t) > max_len)
		{
			max_len = strlen(t);
		}
		count++;
	}
	fseek(file, 0, SEEK_SET);

	std::cout << "count: " << count << '\n';

	fread(t, size, 1, file);
	t[size-7] = '\0';
	//std::cout << t << '\n';

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
	


	for (int i = 0; i < count; i++)
	{
		if (strlen(l_m[i]) == max_len)
		{
			std::cout << l_m[i] << '\n';
			break;
		}
	}


	char find[100], ch[100];
	std::cout << "Что заменить: ";
	fgets(find, 100, stdin);
	std::cout << "На что заменить: ";
	fgets(ch, 100, stdin);
	find[strlen(find) - 1] = '\0';
	ch[strlen(ch) - 1] = '\0';
	//std::cout << strlen(find);

	int i = 0, i2 = 0, f1 = 0, c1 = 0;

	char temp[1000];

	while (t[i] != '\0')
	{
		if (t[i] == find[f1])
		{
			f1++;
		}
		else if (f1 == strlen(find) && t[i] == ' ' && t[i - strlen(find)-1] == ' ' || f1 == strlen(find) && t[i] == ' ' && t[i - strlen(find)-1] == '\n' || f1 == strlen(find) && t[i] == '\n' && t[i - strlen(find)-1] == ' ' || f1 == strlen(find) && t[i] == ' ' && i - strlen(find) == 0 )
		{
			f1 = 0;
			i2 -= strlen(find);
			while (f1 < strlen(ch))
			{
				temp[i2] = ch[f1];
				f1++;
				i2++;
			}			
		}
		else
		{
			f1 = 0;
		}

		temp[i2] = t[i];
		i++;
		i2++;
	}
	temp[i] = '\0';

	//std::cout << temp << '\n';

	fclose(file);
	FILE* result = fopen("file4.txt", "w");

	fprintf(result, temp);


	fclose(result);
	system("pause");
	return 0;
}