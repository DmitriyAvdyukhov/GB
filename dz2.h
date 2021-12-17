#pragma once

using MyVariant = struct
{
	union Union
	{
		int x;
		float f;
		char ch;
	}data;

	unsigned int is_int : 1;
	unsigned int is_float : 1;
	unsigned int is_char : 1;
};