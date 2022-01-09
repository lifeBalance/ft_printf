#include "debug.h"

void	print_spec(t_spec *spec);

int	main(void)
{
	// Flag Parsing (disable dispatcher to test this)
	ft_printf("%s");
	ft_printf("%-s");
	ft_printf("%c");
	ft_printf("% c");
	ft_printf("%#-+d");

	return (0);
}
void	print_spec(t_spec *spec)
{
	printf("Conversion Specification tests: \n");
	printf("# flag: %d\n", test_bit(SHARP, spec->flags));
	printf("0 flag: %d\n", test_bit(ZERO, spec->flags));
	printf("Space flag: %d\n", test_bit(SPACE, spec->flags));
	printf("- flag: %d\n", test_bit(MINUS, spec->flags));
	printf("+ flag: %d\n", test_bit(PLUS, spec->flags));
	printf("Specifier: ");
	switch (spec->specifier)
	{
	case -1:
		printf("Not set.\n");
		break;
	case 0:
		printf("Percent.\n");
		break;
	case 1:
		printf("Char.\n");
		break;
	case 2:
		printf("String.\n");
		break;
	case 3:
		printf("Address.\n");
		break;
	case 4:
		printf("Lowercase Hex.\n");
		break;
	case 5:
		printf("Uppercase Hex.\n");
		break;
	case 6:
		printf("Integer.\n");
		break;
	case 7:
		printf("Float.\n");
		break;
	}
	printf("\n");
}