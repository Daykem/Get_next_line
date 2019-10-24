/*
** EPITECH PROJECT, 2018
** get next line
** File description:
** Made by Daykem (TR)
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int my_strlen(char *str, char c)
{
	int i = 0;
	int nb = 0;

	while (str != 0 && str[i] != c) {
		i++;
		nb++;
	}
	return nb;
}

int my_cond(char *str)
{
	int i = 0;

	while (str != 0 && str[i] != '\0') {
		if (str[i] == '\n')
			return 1;
		i++;
	}
	return 0;
}

char *my_strconcat(char *str1, char *str2)
{
	int i = 0;
	int size1 = my_strlen(str1, '\0');
	int size2 = my_strlen(str2, '\0');
	char *res = malloc(sizeof(char *) * (size1 + size2 + 1));

	if (!res)
		return NULL;
	if (str1 == NULL) {
		for (i = 0; str2[i]; i++)
			res[i] = str2[i];
		res[i] = 0;
		return res;
	}
	for (i = 0; str1[i]; i++)
		res[i] = str1[i];
	for (i = 0; str2[i] != '\0'; i++)
		res[size1 + i] = str2[i];
	res[size1 + i] = 0;
	return res;
}

char *my_strdup(char *src)
{
	char *a = malloc(sizeof(char) * my_strlen(src, '\0') + 1);
	int i = 0;

	if (!a)
		return NULL;
	while (src[i] != '\0') {
		a[i] = src[i];
		i++;
	}
	a[i] = '\0';
	return a;
}

char *get_next_line(int fd)
{
	int i = 0;
	int rd = 0;
	char *buff = malloc(sizeof(char) * READ_SIZE * 20);
	char *line = malloc(sizeof(char) * READ_SIZE * 20);
	static char *a = NULL;

	if (!buff || fd < 0 || !line)
		return NULL;
	while (my_cond(a) == 0) {
		rd = read(fd, buff, READ_SIZE);
		if (rd == 0) {
			if (a == NULL)
				return NULL;
			for (; a[i] != '\0'; i++)
				line[i] = a[i];
			a = NULL;
			return line;
		}
		buff[rd] = 0;
		a = my_strconcat(a, buff);
	}
	for (; a[i] != '\n'; i++)
		line[i] = a[i];
	free(buff);
	a = &a[my_strlen(a, '\n') + 1];
	return line;
}

int main(void)
{
	char *s = get_next_line();

	while (s) {
		printf("%s\n", s);
		free(s);
		s = get_next_line(0);
	}
	return 0;
}
