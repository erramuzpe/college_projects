/* Code Generation */

int data_offset = 0; 	// Initial offset starting at ZERO

/* Returns the address of the Reserved Location */
int data_location()
{
	return data_offset++;
}

int code_offset = 0;	// Start of the code segment

/* Returns the address of the Reserved Location */
int reserve_loc()
{
	return code_offset++;
}

/* Returns the value of the Code Offset */
int gen_label()
{
	return code_offset++;
}

/* Generates code at the current offset */
void gen_code( enum code_ops operation, int arg )
{
	code[code_offset].op = operation;
	code[code_offset++].arg = arg;
}

/* Generates code at some previously reserved address */
void back_patch( int addr, enum code_ops operation, int arg )
{
	code[addr].op = operation;
	code[addr].arg = arg;
}

