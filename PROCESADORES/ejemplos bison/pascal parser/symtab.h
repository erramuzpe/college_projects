/**
 **    This example can be compiled with either C or C++ compiler
 **/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <search.h>

/*   this is an Entry   */

struct symrec
{
  char *name;	/* Name of the symbol */
  int offset;	/* Data offset */
  int   val;	/* Value of symbol */
};
typedef struct symrec symrec;

symrec *root = NULL;

/* and its comparison function -- note the explicit casts */

int symrec_cmp( const void *e1, const void *e2)
{
  return strcmp( ((symrec*)e1)->name, ((symrec*)e2)->name );
}

void printEntry( const void *node, VISIT v, int level )
{
  symrec *e = (*(symrec **)node);

  if( v == postorder || v == leaf )
    printf( "Level: %d, %s: %d\n", level,
            e->name, e->val );
}
/*
void insert( char *key, int value )
{
	symrec *new_symrec;
	symrec **found;

	new_symrec = (symrec*) malloc( sizeof(symrec) );
	new_symrec->name = strdup( key );
	new_symrec->val = value;

	printf( "Inserting %s...\n", key);
	fflush( stdout );
	found = (symrec**) tsearch( new_symrec, (void**)&root, symrec_cmp);

	/* If already exists */
	if (*found != new_symrec )
		printf("symrec already exists.\n");
	else
		printf("Inserted %s.\n", key);
}
*/
symrec *insert( char *key )
{
        symrec *new_symrec;
        symrec **found;

        new_symrec = (symrec*) malloc( sizeof(symrec) );
        new_symrec->name = strdup( key );
	
	new_symrec->offset = data_location();

        printf( "Inserting %s...\n", key);
        fflush( stdout );
        found = (symrec**) tsearch( new_symrec, (void**)&root, symrec_cmp);

        /* If already exists */
        if (*found != new_symrec )
	{
                printf("symrec already exists.\n");
	}
	else
	{
            	printf("Inserted %s.\n", key);
		return found;
	}
}
symrec *lookup( char *key )
{
	symrec *new_symrec;
	symrec **found;

	new_symrec = (symrec*) malloc( sizeof(symrec) );
	new_symrec->name = strdup( key );

	found = (symrec**) tfind( new_symrec, (void**)&root, symrec_cmp );

	if ( found == NULL )
	{
		printf("Could not locate symrec.\n");
		return 0;
	}
	else
	{
		printf( "Found %s. Value: %d\n", (*found)->name, (*found)->val );
		return found;
	}
}
/*
int main ()
{
  symrec **found;
  symrec  *new_symrec;

  /* create a new symrec */
/*  new_symrec = (symrec*) malloc( sizeof(symrec) );
  new_symrec->name = strdup( "b" );
  new_symrec->val = 11;

  insert(new_symrec->name, new_symrec->val);

  /* repeat with a couple more entries */
/*  new_symrec = (symrec*) malloc( sizeof(symrec) );
  new_symrec->name = strdup( "a" );
  new_symrec->val = 12;

  insert(new_symrec->name, new_symrec->val); 

  new_symrec = (symrec*) malloc( sizeof(symrec) );
  new_symrec->name = strdup( "c" );
  new_symrec->val = 13;

  insert(new_symrec->name, new_symrec->val);

  /* now try to insert an already existing key */
/*  new_symrec = (symrec*) malloc( sizeof(symrec) );
  new_symrec->name = strdup( "a" );
  new_symrec->val = 14;
 
  insert(new_symrec->name, new_symrec->val);

  new_symrec = (symrec*) malloc( sizeof(symrec) );
  new_symrec->name = strdup( "d" );
  new_symrec->val = 141;

  insert(new_symrec->name, new_symrec->val);

  /* and now lookup an existing key */
/*  new_symrec = (symrec*) malloc( sizeof(symrec) );
  new_symrec->name = strdup( "b" );
  printf( "Looking up \"b\"..." );
  fflush( stdout );

  lookup(new_symrec->name);

  /* and now lookup an non-existing key */
/*  new_symrec = (symrec*) malloc( sizeof(symrec) );
  new_symrec->name = strdup( "xxx" );
  printf( "Looking up \"xxx\"..." );
  fflush( stdout );
  found = (symrec**) tfind( new_symrec, (void**)&root, symrec_cmp );
  if ( found == NULL )
    printf("not there\n");
  else
    printf( "found it: %s val %d\n", (*found)->name, (*found)->val );

  twalk( root, printEntry );

  return 0;
}
*/
