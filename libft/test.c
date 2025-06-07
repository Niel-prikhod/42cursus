#include <stdio.h>
#include <string.h>
#include "libft.h"

void	test_ft_isalpha()
{
	printf("ft_isalpha('A') = %d (expected 1)\n", ft_isalpha('A'));
	printf("ft_isalpha('1') = %d (expected 0)\n", ft_isalpha('1'));
}

void	test_ft_strlen()
{
	printf("ft_strlen(\"hello\") = %d (expected 5)\n", ft_strlen("hello"));
}

void	test_ft_memset()
{
	char buf[10] = "abcdef";
	ft_memset(buf, 'X', 3);
	printf("ft_memset: %s (expected XXXdef)\n", buf);
}

void	test_ft_strlcpy()
{
	char dest[10];
	size_t ret = ft_strlcpy(dest, "world", 10);
	printf("ft_strlcpy: %s (expected world), return: %zu (expected 5)\n", dest, ret);
}

void	test_ft_strlcat()
{
	char dest[20] = "foo";
	size_t ret = ft_strlcat(dest, "bar", 10);
	printf("ft_strlcat: %s (expected foobar), return: %zu\n", dest, ret);
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

int main(void)
{
	// test_ft_isalpha();
	// test_ft_strlen();
	// test_ft_memset();
	// test_ft_strlcpy();
	// test_ft_strlcat();
	// test_ft_toupper();
	// test_ft_tolower();
	test_ft_strchr();
	test_ft_strrchr();
	return 0;
}
