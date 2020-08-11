/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 23:21:24 by gbudau            #+#    #+#             */
/*   Updated: 2020/08/11 21:15:35 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include "libasm.h"
#define BUFFER_SIZE 128

static void	test_ft__strlen(const char *str)
{
	size_t len_one;
	size_t len_two;

	len_one = ft__strlen(str);
	len_two = strlen(str);
	assert(len_one == len_two);
}

static void	tests_ft__strlen(void)
{

	test_ft__strlen("");
	test_ft__strlen("1");
	test_ft__strlen("Hola");
	test_ft__strlen("Hello, world!\n");
}

static void test_equal_ft__strcmp(const char *str)
{
	int	ret_one;
	int	ret_two;

	ret_one = ft__strcmp(str, str);
	ret_two = strcmp(str, str);
	assert(ret_one == ret_two);
}

static void test_diff_ft__strcmp(const char *s1, const char *s2)
{
	int	ret_one;
	int	ret_two;

	ret_one = ft__strcmp(s1, s2);
	ret_two = strcmp(s1, s2);
	assert(ret_one == ret_two);
}

static void	tests_ft__strcmp(void)
{
	test_equal_ft__strcmp("");
	test_equal_ft__strcmp("1");
	test_equal_ft__strcmp("Hola");
	test_equal_ft__strcmp("Hello, world!\n");
	test_diff_ft__strcmp("", "1");
	test_diff_ft__strcmp("1", "2");
	test_diff_ft__strcmp("Hola", "H");
	test_diff_ft__strcmp("Hello, world!\n", "Hello, 42!");
}

static void test_ft__strcpy(const char *str)
{
	char	buffer_one[BUFFER_SIZE];
	char	buffer_two[BUFFER_SIZE];

	memset(buffer_one, 'K', BUFFER_SIZE);
	ft__strcpy(buffer_one, str);
	memset(buffer_two, 'K', BUFFER_SIZE);
	strcpy(buffer_two, str);
	assert(memcmp(buffer_one, buffer_two, BUFFER_SIZE) == 0);
}

static void tests_ft__strcpy(void)
{
	test_ft__strcpy("");
	test_ft__strcpy("a");
	test_ft__strcpy("Hello\n");
	test_ft__strcpy("123456abc");
}

int		main(void)
{
	tests_ft__strlen();
	tests_ft__strcmp();
	tests_ft__strcpy();
	printf("All tests passed\n");
}
