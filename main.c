/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 23:21:24 by gbudau            #+#    #+#             */
/*   Updated: 2020/08/01 23:44:01 by gbudau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include "libasm.h"

static void	test_ft__strlen(const char *str)
{
	assert(ft__strlen(str) == strlen(str));
}

static void	tests_ft__strlen(void)
{

	test_ft__strlen("");
	test_ft__strlen("1");
	test_ft__strlen("Hola");
	test_ft__strlen("Hello, world!\n");
}

/*
static void test_equal_ft__strcmp(const char *str)
{
	assert(ft__strcmp(str, str) == strcmp(str, str));
}

static void test_diff_ft__strcmp(const char *s1, const char *s2)
{
	assert(ft__strcmp(s1, s2) == strcmp(s1, s2));
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
*/

int		main(void)
{
	tests_ft__strlen();
	//tests_ft__strcmp();
}
