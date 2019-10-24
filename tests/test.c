/*
** EPITECH PROJECT, 2017
** get_next_line
** File description:
** Made by Daykem
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <fcntl.h>
#include <unistd.h>

char *get_next_line(int fd);

Test(get_next_line, read_line) {
	int fd = -1;
	fd = open("tests/data.txt", O_RDONLY);
	cr_redirect_stdout();
	char *expected = "MAN(1) Manual pager utils MAN(1)";
	char *got = get_next_line(fd);
	cr_assert_str_eq(got, expected);
	if (fd != -1)
		close(fd);
}

Test(get_next_line, read_line1) {
	int fd = -1;
	fd = open("tests/data2.txt", O_RDONLY);
	cr_redirect_stdout();
	char *expected = " ";
	char *got = get_next_line(fd);
	cr_assert_str_eq(got, expected);
	if (fd != -1)
		close(fd);
}

Test(get_next_line, read_line2) {
	int fd = -1;
	fd = open("tests/data3.txt", O_RDONLY);
	cr_redirect_stdout();
	char *expected = "";
	char *got = get_next_line(fd);
	cr_assert_str_eq(got, expected);
	if (fd != -1)
		close(fd);
}
