#include "ft_printf/ft_printf.h"
#include <stdio.h>

static void	test_ft_printf_basic()
{
	int ret1, ret2;

	// %c - char
	ret1 = ft_printf("Test %%c: %c\n", 'A');
	ret2 = printf("Test %%c: %c\n", 'A');
	printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

	// %s - string
	ret1 = ft_printf("Test %%s: %s\n", "Hello, world!");
	ret2 = printf("Test %%s: %s\n", "Hello, world!");
	printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

	// %p - pointer
	int x = 42;
	ret1 = ft_printf("Test %%p: %p\n", &x);
	ret2 = printf("Test %%p: %p\n", &x);
	printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

	// %d - decimal
	ret1 = ft_printf("Test %%d: %d\n", -12345);
	ret2 = printf("Test %%d: %d\n", -12345);
	printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

	// %i - integer
	ret1 = ft_printf("Test %%i: %i\n", 67890);
	ret2 = printf("Test %%i: %i\n", 67890);
	printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

	// %u - unsigned
	ret1 = ft_printf("Test %%u: %u\n", 4294967295u);
	ret2 = printf("Test %%u: %u\n", 4294967295u);
	printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

	// %x - lowercase hexadecimal
	ret1 = ft_printf("Test %%x: %x\n", 305441741);
	ret2 = printf("Test %%x: %x\n", 305441741);
	printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

	// %X - uppercase hexadecimal
	ret1 = ft_printf("Test %%X: %X\n", 305441741);
	ret2 = printf("Test %%X: %X\n", 305441741);
	printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

	// %% - percent sign
	ret1 = ft_printf("Test %%%%: %%\n");
	ret2 = printf("Test %%%%: %%\n");
	printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

	// Mixed test
	ret1 = ft_printf("Mix: %c %s %p %d %i %u %x %X %%\n", 'Z', "str", &x, -1, 42, 123u, 0xabc, 0xABC);
	ret2 = printf("Mix: %c %s %p %d %i %u %x %X %%\n", 'Z', "str", &x, -1, 42, 123u, 0xabc, 0xABC);
	printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);
}

int	main(void)
{
	// test_ft_printf_basic();

	// Empty string
	int ret1, ret2;
	char	*string = "Hello world!";
	ret1 = ft_printf("%s", string);
	// ret2 = printf("");
	// printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

	// // NULL string
	// ret1 = ft_printf("NULL string: %s\n", (char *)NULL);
	// ret2 = printf("NULL string: %s\n", (char *)NULL);
	// printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

	// // NULL pointer
	// ret1 = ft_printf("NULL pointer: %p\n", (void *)NULL);
	// ret2 = printf("NULL pointer: %p\n", (void *)NULL);
	// printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

	// // Zero values
	// ret1 = ft_printf("Zero int: %d, Zero unsigned: %u, Zero hex: %x %X\n", 0, 0u, 0, 0);
	// ret2 = printf("Zero int: %d, Zero unsigned: %u, Zero hex: %x %X\n", 0, 0u, 0, 0);
	// printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

	// // INT_MIN and INT_MAX
	// ret1 = ft_printf("INT_MIN: %d, INT_MAX: %d\n", -2147483648, 2147483647);
	// ret2 = printf("INT_MIN: %d, INT_MAX: %d\n", -2147483648, 2147483647);
	// printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

	// // UINT_MAX
	// ret1 = ft_printf("UINT_MAX: %u\n", 4294967295u);
	// ret2 = printf("UINT_MAX: %u\n", 4294967295u);
	// printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

	// // Large hex values
	// ret1 = ft_printf("Large hex: %x %X\n", 0xFFFFFFFF, 0xFFFFFFFF);
	// ret2 = printf("Large hex: %x %X\n", 0xFFFFFFFF, 0xFFFFFFFF);
	// printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

	// // Multiple consecutive percent signs
	// // ret1 = ft_printf("%%%%%%\n");
	// // ret2 = printf("%%%%%%\n");
	// // printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

	// // Unknown format specifier
	// // ret1 = ft_printf("Unknown: %q cont\n");
	// // ret2 = printf("Unknown: %q cont\n");
	// // printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

	// // Format string ends with single '%'
	// // ret1 = ft_printf("Ends with percent: %");
	// // ret2 = printf("Ends with percent: %");
	// // printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

	// // Print all ASCII characters
	// for (int ch = 0; ch < 128; ++ch) {
	// 	ret1 = ft_printf("ASCII %d: %c\n", ch, ch);
	// 	ret2 = printf("ASCII %d: %c\n", ch, ch);
	// 	if (ret1 != ret2)
	// 		printf("Mismatch at ASCII %d\n", ch);
	// }

	// // Print string with embedded nulls (should stop at first null)
	// char str_with_nulls[] = {'a', 'b', '\0', 'c', 'd', 0};
	// ret1 = ft_printf("String with nulls: %s\n", str_with_nulls);
	// ret2 = printf("String with nulls: %s\n", str_with_nulls);
	// printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);
	// return 0;
}
