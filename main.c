/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 23:21:24 by gbudau            #+#    #+#             */
/*   Updated: 2020/08/13 21:00:15 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include "libasm.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUFFER_SIZE 128

static void	test_ft_strlen(const char *str)
{
	size_t len_one = ft_strlen(str);
	size_t len_two = strlen(str);

	assert(len_one == len_two);
}

static void test_equal_ft_strcmp(const char *str)
{
	int ret_one = ft_strcmp(str, str);
	int ret_two = strcmp(str, str);

	if (ret_two < 0)
		assert(ret_one < 0);
	else if (ret_two > 0)
		assert(ret_one > 0);
	else
		assert(ret_one == 0);
}

static void test_diff_ft_strcmp(const char *s1, const char *s2)
{
	int ret_one = ft_strcmp(s1, s2);
	int ret_two = strcmp(s1, s2);

	if (ret_two < 0)
		assert(ret_one < 0);
	else if (ret_two > 0)
		assert(ret_one > 0);
	else
		assert(ret_one == 0);
}

static void test_ft_strcpy(const char *str)
{
	char	buffer_one[BUFFER_SIZE];
	char	buffer_two[BUFFER_SIZE];

	if (strlen(str) >= BUFFER_SIZE)
	{
		printf("Error: buffer overflow\n");
		return ;
	}
	memset(buffer_one, 'K', BUFFER_SIZE);
	ft_strcpy(buffer_one, str);
	memset(buffer_two, 'K', BUFFER_SIZE);
	strcpy(buffer_two, str);
	assert(memcmp(buffer_one, buffer_two, BUFFER_SIZE) == 0);
}

static void test_ft_strdup(const char *str)
{
	char	*ptr_one = ft_strdup(str);

	if (ptr_one == NULL)
	{
		printf("Memory allocation error\n");
		return ;
	}

	char	*ptr_two = strdup(str);

	if (ptr_two == NULL)
	{
		free(ptr_one);
		printf("Memory allocation error\n");
		return ;
	}

	size_t	len_one = strlen(ptr_one);
	size_t	len_two = strlen(ptr_two);

	assert(len_one == len_two);
	assert(memcmp(ptr_one, ptr_two, len_one) == 0);
	free(ptr_one);
	free(ptr_two);
}

static void	test_ft_write(const char *str, int fd)
{
	size_t len = str ? strlen(str) : 1;

	errno = 0;
	printf("ft_write: |");
	ssize_t ret_one = ft_write(fd, str, len);
	int		errno_one = errno;
	printf("|\n");

	errno = 0;
	printf("    write: |");
	ssize_t ret_two = write(fd, str, len);
	int		errno_two = errno;
	printf("|\n");
	assert(ret_one == ret_two);
	assert(errno_one == errno_two);
}

static void	test_ft_read(const char *str)
{
	char	buffer_one[BUFFER_SIZE];
	char	buffer_two[BUFFER_SIZE];
	int		fd_one = open(str, O_RDONLY);
	int		fd_two = open(str, O_RDONLY);

	memset(buffer_one, 'K', BUFFER_SIZE);
	memset(buffer_two, 'K', BUFFER_SIZE);

	errno = 0;
	ssize_t	ret_one = ft_read(fd_one, buffer_one, BUFFER_SIZE);
	int errno_one = errno;

	errno = 0;
	ssize_t	ret_two = read(fd_two, buffer_two, BUFFER_SIZE);
	int errno_two = errno;

	assert(ret_one == ret_two);
	assert(errno_one == errno_two);
	assert(memcmp(buffer_one, buffer_two, BUFFER_SIZE) == 0);

	close(fd_one);
	close(fd_two);
}

static void	tests_ft_strlen(void)
{

	test_ft_strlen("");
	test_ft_strlen("1");
	test_ft_strlen("Hola");
	test_ft_strlen("Hello, world!\n");
}

static void	tests_ft_strcmp(void)
{
	test_equal_ft_strcmp("");
	test_equal_ft_strcmp("1");
	test_equal_ft_strcmp("Hola");
	test_equal_ft_strcmp("Hello, world!\n");
	test_diff_ft_strcmp("", "1");
	test_diff_ft_strcmp("", "");
	test_diff_ft_strcmp("", "1124asdfasdfp;ap");
	test_diff_ft_strcmp("1", "2");
	test_diff_ft_strcmp("112141241414", "2");
	test_diff_ft_strcmp("Hola", "H");
	test_diff_ft_strcmp("Hello, world!\n", "Hello, 42!");
}

static void tests_ft_strcpy(void)
{
	test_ft_strcpy("");
	test_ft_strcpy("a");
	test_ft_strcpy("Hello\n");
	test_ft_strcpy("123456abc");
}

static void	tests_ft_strdup(void)
{
	test_ft_strdup("");
	test_ft_strdup("a");
	test_ft_strdup("Hello\n");
	test_ft_strdup("123456abc");
}

static void	tests_ft_write(void)
{
	test_ft_write("", 1);
	test_ft_write("a", 1);
	test_ft_write("Hello", 1);
	test_ft_write("123456abc", 1);
	test_ft_write("Hello", 123456);
	test_ft_write(NULL, 1000);
}

static void	tests_ft_read(void)
{
	test_ft_read("main.c");
	test_ft_read(NULL);
	test_ft_read("hello");
}

int		main(void)
{
	tests_ft_strlen();
	tests_ft_strcmp();
	tests_ft_strcpy();
	tests_ft_strdup();
	setbuf(stdout, NULL);
	tests_ft_write();
	tests_ft_read();
	printf("All tests passed\n");
}
