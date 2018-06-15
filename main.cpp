#include "BigInt.h"
int main(int argc, char* argv[])
{ 
	if (argc > 4)
	{
		BIGINT b1;
		Input(b1, argv[1]);
		BIGINT b2;
		Input(b2, argv[2]);

		if (argv[4] == "+")
			Output(b1 + b2, argv[3]);
		if (argv[4] == "-")
			Output(b1 - b2, argv[3]);
		if (argv[4] == "*")
			Output(b1 * b2, argv[3]);
	}

	return 1;
}