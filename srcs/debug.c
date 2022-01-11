#include "debug.h"

void	print_spec(t_spec *spec)
{
	printf("FLAGS: #: %d, 0: %d, ' ': %d, -: %d, +: %d\n",
		test_bit(SHARP, spec->flags),
		test_bit(ZERO, spec->flags),
		test_bit(SPACE, spec->flags),
		test_bit(MINUS, spec->flags),
		test_bit(PLUS, spec->flags));

	printf("\nWIDTH AND PRECISION: \n");
	printf("dot: %d, width: %d, precision: %d, width*: %d, precision*: %d\n",
		test_bit(DOT, spec->digits),
		spec->width,
		spec->precision,
		test_bit(WIDTH_ARG, spec->digits),
		test_bit(PREC_ARG, spec->digits));

	printf("\nLENGTH FLAGS: \n");
	printf("l: %d, ll: %d, h: %d, hh: %d\n",
		test_bit(ELL, spec->length),
		test_bit(ELLELL, spec->length),
		test_bit(H, spec->length),
		test_bit(HH, spec->length));

	printf("SPECIFIER: ");
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