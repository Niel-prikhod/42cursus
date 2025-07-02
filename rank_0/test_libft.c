/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 23:12:29 by niel              #+#    #+#             */
/*   Updated: 2025/06/24 13:11:21 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <bsd/string.h>
#include <stdlib.h>
#include <ctype.h>
#include "libft.h"
#include <limits.h>

void	test_ft_isalpha()
{
	printf("ft_isalpha('A') = %d (expected 1)\n", ft_isalpha('A'));
	printf("ft_isalpha('1') = %d (expected 0)\n", ft_isalpha('1'));
}

void	test_ft_isascii()
{
	printf("ft_isascii('A') = %d (expected 1)\n", ft_isascii('A'));
	printf("ft_isascii(128) = %d (expected 0)\n", ft_isascii(128));
}

void	test_ft_isdigit()
{
	printf("ft_isdigit('5') = %d (expected 1)\n", ft_isdigit('5'));
	printf("ft_isdigit('a') = %d (expected 0)\n", ft_isdigit('a'));
}

void	test_ft_isalnum()
{
	printf("ft_isalnum('A') = %d (expected 1)\n", ft_isalnum('A'));
	printf("ft_isalnum('5') = %d (expected 1)\n", ft_isalnum('5'));
	printf("ft_isalnum('@') = %d (expected 0)\n", ft_isalnum('@'));
}

void	test_ft_isprint()
{
	printf("ft_isprint(' ') = %d (expected 1)\n", ft_isprint(' '));
	printf("ft_isprint('\n') = %d (expected 0)\n", ft_isprint('\n'));
}

void	test_ft_strlen()
{
	printf("ft_strlen(\"hello\") = %zu (expected 5)\n", ft_strlen("hello"));
}

void	test_ft_memset()
{
	char buf[10] = "abcdef";
	ft_memset(buf, 'X', 3);
	printf("ft_memset: %s (expected XXXdef)\n", buf);
}

void	test_ft_bzero()
{
	char buf[10] = "abcdef";
	ft_bzero(buf, 3);
	printf("ft_bzero: %s (expected def)\n", buf + 3);
}

void	test_ft_memcpy()
{
	char dest[10] = "abcdef";
	ft_memcpy(dest, "123", 3);
	printf("ft_memcpy: %s (expected 123def)\n", dest);
}

void	test_ft_memmove()
{
	char dest[10] = "abcdef";
	ft_memmove(dest + 2, dest, 4);
	printf("ft_memmove: %s (expected ababcd)\n", dest);
}

void	test_ft_strlcpy()
{
	char dest[10];
	size_t ret = ft_strlcpy(dest, "world", 10);
	printf("ft_strlcpy: %s (expected world), return: %zu (expected 5)\n", dest, ret);
}

void	test_ft_strlcat()
{
	{
		char dst[20] = "foo";
		char dst_ref[20] = "foo";
		size_t ret = ft_strlcat(dst, "bar", 10);
		size_t ref = strlcat(dst_ref, "bar", 10);
		printf("ft_strlcat(\"foo\", \"bar\", 10) = %s (expected %s), ret = %zu (expected %zu)\n", dst, dst_ref, ret, ref);
	}
	{
		char dst[20] = "foo";
		char dst_ref[20] = "foo";
		size_t ret = ft_strlcat(dst, "", 10);
		size_t ref = strlcat(dst_ref, "", 10);
		printf("ft_strlcat(\"foo\", \"\", 10) = %s (expected %s), ret = %zu (expected %zu)\n", dst, dst_ref, ret, ref);
	}
	{
		char dst[20] = "";
		char dst_ref[20] = "";
		size_t ret = ft_strlcat(dst, "bar", 10);
		size_t ref = strlcat(dst_ref, "bar", 10);
		printf("ft_strlcat(\"\", \"bar\", 10) = %s (expected %s), ret = %zu (expected %zu)\n", dst, dst_ref, ret, ref);
	}
	{
		char dst[20] = "foo";
		char dst_ref[20] = "foo";
		size_t ret = ft_strlcat(dst, "bar", 0);
		size_t ref = strlcat(dst_ref, "bar", 0);
		printf("ft_strlcat(\"foo\", \"bar\", 0) = %s (expected %s), ret = %zu (expected %zu)\n", dst, dst_ref, ret, ref);
	}
	{
		char dst[7] = "foobar";
		char dst_ref[7] = "foobar";
		size_t ret = ft_strlcat(dst, "baz", 7);
		size_t ref = strlcat(dst_ref, "baz", 7);
		printf("ft_strlcat(\"foobar\", \"baz\", 7) = %s (expected %s), ret = %zu (expected %zu)\n", dst, dst_ref, ret, ref);
	}
	{
		char dst[4] = "foo";
		char dst_ref[4] = "foo";
		size_t ret = ft_strlcat(dst, "bar", 4);
		size_t ref = strlcat(dst_ref, "bar", 4);
		printf("ft_strlcat(\"foo\", \"bar\", 4) = %s (expected %s), ret = %zu (expected %zu)\n", dst, dst_ref, ret, ref);
	}
	{
		char dst[20] = "foo";
		char dst_ref[20] = "foo";
		char src[100];
		memset(src, 'A', 99);
		src[99] = '\0';
		size_t ret = ft_strlcat(dst, src, 20);
		size_t ref = strlcat(dst_ref, src, 20);
		printf("ft_strlcat(\"foo\", long_src, 20) = %s (expected %s), ret = %zu (expected %zu)\n", dst, dst_ref, ret, ref);
	}
	{
		char dst[7] = "foo";
		char dst_ref[7] = "foo";
		size_t ret = ft_strlcat(dst, "bar", 7);
		size_t ref = strlcat(dst_ref, "bar", 7);
		printf("ft_strlcat(\"foo\", \"bar\", 7) = %s (expected %s), ret = %zu (expected %zu)\n", dst, dst_ref, ret, ref);
	}
}

void	test_ft_toupper()
{
    printf("ft_toupper('a') = %c (expected A)\n", ft_toupper('a'));
    printf("ft_toupper('A') = %c (expected A)\n", ft_toupper('A'));
    printf("ft_toupper('1') = %c (expected 1)\n", ft_toupper('1'));
}

void	test_ft_tolower()
{
    printf("ft_tolower('A') = %c (expected a)\n", ft_tolower('A'));
    printf("ft_tolower('a') = %c (expected a)\n", ft_tolower('a'));
    printf("ft_tolower('1') = %c (expected 1)\n", ft_tolower('1'));
}

void	test_ft_strchr()
{
    const char *s = "hello";
    char *res = ft_strchr(s, 'e');
	char *ref = strchr(s, 'e');
    printf("ft_strchr(\"hello\", 'e') = %s (expected %s)\n", res, ref);
    res = ft_strchr(s, 'z');
	ref = strchr(s, 'z');
    printf("ft_strchr(\"hello\", 'z') = %s (expected %s)\n", res, ref);
}

void	test_ft_strrchr()
{
    const char *s = "hello";
    char *res = ft_strrchr(s, 'l');
    char *ref = strrchr(s, 'l');
    printf("ft_strrchr(\"hello\", 'l') = %s (expected %s)\n", res, ref);
    res = ft_strrchr(s, 'z');
    ref = strrchr(s, 'z');
    printf("ft_strrchr(\"hello\", 'z') = %s (expected %s)\n", res, ref);
}

void	test_ft_strnstr()
{
	const char *big = "hello world";
	const char *little = "world";
	char *res = ft_strnstr(big, little, 11);
	char *ref = strnstr(big, little, 11);
	printf("ft_strnstr(\"hello world\", \"world\", 11) = %s (expected %s)\n", res, ref);

	res = ft_strnstr(big, "notfound", 11);
	ref = strnstr(big, "notfound", 11);
	printf("ft_strnstr(\"hello world\", \"notfound\", 11) = %s (expected %s)\n", res, ref);
}

void	test_ft_strncmp()
{
	char s1[] = "hello";
	char s2[] = "hello";
	int res = ft_strncmp(s1, s2, 5);
	int ref = strncmp(s1, s2, 5);
	printf("ft_strncmp(\"hello\", \"hello\", 5) = %d (expected %d)\n", res, ref);

	s2[0] = 'H';
	res = ft_strncmp(s1, s2, 5);
	ref = strncmp(s1, s2, 5);
	printf("ft_strncmp(\"hello\", \"Hello\", 5) = %d (expected %d)\n", res, ref);
}

void	test_ft_memchr()
{
	const char *s = "hello world";
	char *res = ft_memchr(s, 'o', 11);
	char *ref = memchr(s, 'o', 11);
	printf("ft_memchr(\"hello world\", 'o', 11) = %s (expected %s)\n", res, ref);

	res = ft_memchr(s, 'z', 11);
	ref = memchr(s, 'z', 11);
	printf("ft_memchr(\"hello world\", 'z', 11) = %s (expected %s)\n", res, ref);
}

void	test_ft_memcmp()
{
	char s1[] = "hello";
	char s2[] = "hello";
	int res = ft_memcmp(s1, s2, 5);
	int ref = memcmp(s1, s2, 5);
	printf("ft_memcmp(\"hello\", \"hello\", 5) = %d (expected %d)\n", res, ref);

	s2[0] = 'H';
	res = ft_memcmp(s1, s2, 5);
	ref = memcmp(s1, s2, 5);
	printf("ft_memcmp(\"hello\", \"Hello\", 5) = %d (expected %d)\n", res, ref);
}

void	test_ft_atoi()
{
	char *str = "   -123abc";
	int res = ft_atoi(str);
	int ref = atoi(str);
	printf("ft_atoi(\"%s\") = %d (expected %d)\n", str, res, ref);

	str = "42";
	res = ft_atoi(str);
	ref = atoi(str);
	printf("ft_atoi(\"%s\") = %d (expected %d)\n", str, res, ref);
}

void	test_ft_calloc()
{
	void *ptr = ft_calloc(5, sizeof(int));
	if (ptr)
	{
		printf("ft_calloc(5, sizeof(int)) = %p\n", ptr);
		free(ptr);
	}
	else
	{
		printf("ft_calloc failed\n");
	}
}

void	test_ft_strdup()
{
	char *str = "hello";
	char *dup = ft_strdup(str);
	if (dup)
	{
		printf("ft_strdup(\"%s\") = %s\n", str, dup);
		free(dup);
	}
	else
	{
		printf("ft_strdup failed\n");
	}
}

void	test_ft_substr()
{
	char			*str = "hello";
	unsigned int	start = 2;
	char			*sub;
	sub = ft_substr(str, start, ft_strlen(str));
	printf("ft_substr(\"%s, %d, %zu\") = %s\n", str, start, ft_strlen(str), sub);
}

void	test_ft_itoa()
{
	char *res;

	res = ft_itoa(0);
	printf("ft_itoa(0) = \"%s\" (expected \"0\")\n", res);
	free(res);

	res = ft_itoa(123);
	printf("ft_itoa(123) = \"%s\" (expected \"123\")\n", res);
	free(res);

	res = ft_itoa(-456);
	printf("ft_itoa(-456) = \"%s\" (expected \"-456\")\n", res);
	free(res);

	res = ft_itoa(1);
	printf("ft_itoa(1) = \"%s\" (expected \"1\")\n", res);
	free(res);

	res = ft_itoa(-1);
	printf("ft_itoa(-1) = \"%s\" (expected \"-1\")\n", res);
	free(res);

	res = ft_itoa(INT_MAX);
	printf("ft_itoa(INT_MAX) = \"%s\" (expected \"%d\")\n", res, INT_MAX);
	free(res);

	res = ft_itoa(INT_MIN);
	printf("ft_itoa(INT_MIN) = \"%s\" (expected \"%d\")\n", res, INT_MIN);
	free(res);

	res = ft_itoa(1000000);
	printf("ft_itoa(1000000) = \"%s\" (expected \"1000000\")\n", res);
	free(res);

	res = ft_itoa(-999999);
	printf("ft_itoa(-999999) = \"%s\" (expected \"-999999\")\n", res);
	free(res);
}

void test_ft_strjoin_basic() {
	char *s1 = "Hello, ";
	char *s2 = "world!";
	char *result = ft_strjoin(s1, s2);
	printf("ft_strjoin(\"%s\", \"%s\") = \"%s\" (expected \"Hello, world!\")\n", s1, s2, result);
	free(result);
}

// // Test ft_strjoin with empty first string
// void test_ft_strjoin_empty_first() {
// 	char *s1 = "";
// 	char *s2 = "world!";
// 	char *result = ft_strjoin(s1, s2);
// 	printf("ft_strjoin(\"%s\", \"%s\") = \"%s\" (expected \"world!\")\n", s1, s2, result);
// 	free(result);
// }

// // Test ft_strjoin with empty second string
// void test_ft_strjoin_empty_second() {
// 	char *s1 = "Hello, ";
// 	char *s2 = "";
// 	char *result = ft_strjoin(s1, s2);
// 	printf("ft_strjoin(\"%s\", \"%s\") = \"%s\" (expected \"Hello, \")\n", s1, s2, result);
// 	free(result);
// }

// // Test ft_strjoin with both strings empty
// void test_ft_strjoin_both_empty() {
// 	char *s1 = "";
// 	char *s2 = "";
// 	char *result = ft_strjoin(s1, s2);
// 	printf("ft_strjoin(\"%s\", \"%s\") = \"%s\" (expected \"\")\n", s1, s2, result);
// 	free(result);
// }

// // Test ft_strjoin with NULL first string
// void test_ft_strjoin_null_first() {
// 	char *s1 = NULL;
// 	char *s2 = "world!";
// 	char *result = ft_strjoin(s1, s2);
// 	printf("ft_strjoin(NULL, \"%s\") = %s (expected NULL)\n", s2, result ? result : "NULL");
// 	free(result);
// }

// // Test ft_strjoin with NULL second string
// void test_ft_strjoin_null_second() {
// 	char *s1 = "Hello, ";
// 	char *s2 = NULL;
// 	char *result = ft_strjoin(s1, s2);
// 	printf("ft_strjoin(\"%s\", NULL) = %s (expected NULL)\n", s1, result ? result : "NULL");
// 	free(result);
// }

// // Test ft_strjoin with both NULL
// void test_ft_strjoin_both_null() {
// 	char *result = ft_strjoin(NULL, NULL);
// 	printf("ft_strjoin(NULL, NULL) = %s (expected NULL)\n", result ? result : "NULL");
// 	free(result);
// }

// // Test ft_strjoin with long strings
// void test_ft_strjoin_long() {
// 	char s1[1024];
// 	char s2[1024];
// 	memset(s1, 'A', 1023); s1[1023] = '\0';
// 	memset(s2, 'B', 1023); s2[1023] = '\0';
// 	char *result = ft_strjoin(s1, s2);
// 	printf("ft_strjoin(long A, long B) length = %zu (expected 2046)\n", result ? strlen(result) : 0);
// 	free(result);
// }

int main(void)
{
	// test_ft_isalpha();
	// test_ft_isascii();
	// test_ft_isdigit();
	// test_ft_isalnum();
	// test_ft_isprint();
	// test_ft_strlen();
	// test_ft_memset();
	// test_ft_bzero();
	// test_ft_memcpy();
	// test_ft_memmove();
	// test_ft_strlcpy();
	test_ft_strlcat();
	// test_ft_toupper();
	// test_ft_tolower();
	// test_ft_strchr();
	// test_ft_strrchr();
	// test_ft_strnstr();
	// test_ft_strncmp();
	// test_ft_memchr();
	// test_ft_memcmp();
	// test_ft_atoi();
	// test_ft_calloc();
	// test_ft_strdup();
	// test_ft_substr();
	// test_ft_itoa();

	// test_ft_strjoin_basic();
	// test_ft_strjoin_empty_first();
	// test_ft_strjoin_empty_second();
	// test_ft_strjoin_both_empty();
	// test_ft_strjoin_null_first();
	// test_ft_strjoin_null_second();
	// test_ft_strjoin_both_null();
	// test_ft_strjoin_long();

	return (0);
}
