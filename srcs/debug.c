#include "debug.h"

void	print_spec(t_spec *spec)
{
	printf("FLAG tests: \n");
	printf("# flag: %d\n", test_bit(SHARP, spec->flags));
	printf("0 flag: %d\n", test_bit(ZERO, spec->flags));
	printf("Space flag: %d\n", test_bit(SPACE, spec->flags));
	printf("- flag: %d\n", test_bit(MINUS, spec->flags));
	printf("+ flag: %d\n", test_bit(PLUS, spec->flags));

	printf("\nWIDTH AND PRECISION: \n");
	printf("dot: %d\n", test_bit(DOT, spec->digits));
	printf("width: %d, precision: %d\n", spec->width, spec->precision);
	printf("width*: %d, precision*: %d\n", test_bit(WIDTH_ARG, spec->digits),  test_bit(PREC_ARG, spec->digits));

	printf("\nLENGTH FLAGS: \n");
	printf("l len: %d\n", test_bit(ELL, spec->length));
	printf("ll len: %d\n", test_bit(ELLELL, spec->length));
	printf("h len: %d\n", test_bit(H, spec->length));
	printf("hh len: %d\n", test_bit(HH, spec->length));
	printf("Specifier: ");
	switch (spec->specifier)
	{
	case NOT_SET:
		printf("Not set.\n");
		break;
	case PERCENT:
		printf("Percent.\n");
		break;
	case CHAR:
		printf("Char.\n");
		break;
	case STRING:
		printf("String.\n");
		break;
	case ADDRESS:
		printf("Address.\n");
		break;
	case LOWHEX:
		printf("Lowercase Hex.\n");
		break;
	case UPPHEX:
		printf("Uppercase Hex.\n");
		break;
	case INT:
		printf("Integer.\n");
		break;
	case FLOAT:
		printf("Float.\n");
		break;
	}
	printf("\n");
}