/* Stack Machine Header */

/* Code Operations: Representation in Machine */

enum code_ops { PUSHCI, PUSHI, POPI, PUSHGI, POPGI, FETCHI, POPII, PUSHA, PUSHGA, PUSHS, STOREI,
		ADDI, SUBI, MULI, DIVI, NEGI,
		EQI, NEI, LTI, LEI, GTI, GEI,
		JUMPZ, JUMPNZ, JUMP,
		ENTER, ALLOC,
		SETRVI, RETURN, RETURNF, CALL,
		INT, INTB, FLT, FLTB,
		HALT };

/* Code Operations: External Representation */

char *op_name[] = "pushcI", "pushI", "popI", "pushgI", "popgI", "fetchI", "popiI", "pusha", "pushga", "pushs", "storeI",
		  "addI", "subI", "mulI", "divI", "negI",
		  "eqI", "neI", "ltI", "leI" "gtI", "geI",
		  "jumpz", "jumpnz", "jump",
		  "enter", "alloc",
		  "setrvI", "return", "returnf", "call",
		  "int", "intb", "flt", "fltb",
		  "halt" };

struct instruction
{
	enum code_ops op;
	int arg;
};

/* Code Segement */

struct instruction code[999];

/* Run-time Data and Expression Stack */

int stack[999];

/* Special Purpose Registers */

int	pc = 0;		// Program Counter
struct 	instruction ir;	// Instruction Register
int	ar = 0;		// Frame Pointer (Activation Record)
int	top = 0;	// Stack Pointer (Top of Stack)

/* Fetch Execution Code Cycle */

void fetch_execute_cycle()
{
	do
	{
		/* Fetch the operation */
		ir = code[pc++];
	
		/* Execute the operation */
		switch (ir.op)
		{
			case HALT:
				printf( "halt\n" );
				break;
			case PUSHCI:
				top = top + 1;
				stack[top] = ir.arg;
				break;
			case PUSHI:
				top = top + 1;
				stack[top] = stack[ar + ir.arg];
				break;
			case POPI:
				stack[ar + ir.arg] = stack[top--];
				break;
			case PUSHGI:
				top++;
				stack[top] = stack[ar + ir.arg];
				break;
			case POPGI:
				stack[ar + ir.arg] = stack[top--];
				break;
			case FETCHI:
				stack[top] = stack[stack[top]];
				break;
			case POPII:
				stack[stack[top-1]]; = stack[top];
				top -= 2;
				break;
			case PUSHA:
				top++;
				stack[top] = ar + ir.arg;
				break;
			case PUSHGA:
				top++;
				stack[top] = ar + ir.arg;
				break;
			case PUSHS:
				top++;
				stack[top] = ir.arg;
				break;
			case STOREI:
				stack[stack[top-1]] = stack[top];
				stack[top-1] = stack[top];
				top--;
				break;
			case ADDI:
				stack[top-1] = stack[top-1] + stack[top];
				top--;
				break;
			case SUBI:
				stack[top-1] = stack[top-1] - stack[top];
				top--;
				break;
			case MULI:
				stack[top-1] = stack[top-1] * stack[top];
				top--;
				break;
			case DIVI:
				stack[top-1] = stack[top-1] / stack[top];
				top--;
				break;
			case NEGI:
				stack[top] = 0 - stack[top];
				break;
			case EQI:
				if( stack[top-1] == stack[top] )
					stack[--top] = 1;
				else
					stack[--top] = 0;
				break;
			case NEI:
				if( stack[top-1] != stack[top] )
					stack[--top] = 1;
				else
					stack[--top] = 0;
				break;
			case LTI:
				if( stack[top-1] < stack[top] )
					stack[--top] = 1;
				else
					stack[--top] = 0;
				break;
			case LEI:
				if( stack[top-1] <= stack[top] )
					stack[--top] = 1;
				else
					stack[--top] = 0;
				break;
			case GTI:
				if( stack[top-1] > stack[top] )
					stack[--top] = 1;
				else
					stack[--top] = 0;
				break;
			case GEI:
				if( stack[top-1] >= stack[top] )
					stack[--top] = 1;
				else
					stack[--top] = 0;
				break;
			case JUMPZ:
				if( stack[top--] == 0 )
					pc = ir.arg;
				break;
			case JUMPNZ:
				if( stack[top--] != 0 )
					pc = ir.arg;
				break;
			case JUMP:
				pc = ir.arg;
				break;
			case ENTER:
				stack[top+1] = &stack[ar]; // base(N)?
				stack[top+2] = ar;
				top += 3;
				break;
			case ALLOC:
				top = top + ir.arg;
				break;
			case SETRVI:
				stack[ar] = stack[top--];
				break;
			case RETURN:
				top = ar - 1;
				pc = stack[ar+2];
				ar = stack[ar+1];
				break;
			case RETURNF:
				top = ar;
				pc = stack[ar+2];
				ar = stack[ar+1];
				break;
			case CALL:
				ar = top - (ar+2);
				stack[ar+2] = pc;
				pc = ir.arg;
				break;
			case INT:
				stack[top] = ((int)stack[top]);
				break;
			case INTB:
				stack[top-1] = ((int)stack[top-1]);
				break;
			case FLT:
				stack[top] = ((long)stack[top]);
				break;
			case FLTB:
				stack[top-1] = ((long)stack[top-1]);
				break;
		}
	}
	while (ir.op != HALT);

} // end fetch_execute_cycle()
