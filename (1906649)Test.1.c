#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int display( char *string1, int size );

int main()

{
  char string[80];
  int i, size;

  printf("Binary number: ");
  fgets( string, 80, stdin);
  for ( i = 0 ; i < 80 ; i++ )
    if ( string[i] == '\n' )
      string[i] = '\0';
  size = strlen( string );
  display( string, size - 1 );
  return(0);

}

int display( char *string, int i )

{
  if ( i == 0 )
  {
    return 0;
  }
  if ( string[i] != 'x' )
  {
    i -= 1;
    display( string, i );
    return 0;
  }
  if ( string[i] == 'x' )
  {
    string[i] = '0';
    i -= 1;
    display( string, i );
    printf("%s\n", string );
    i += 1;
    string[i] = '1';
    printf("%s\n", string );
    return 0;
  }
  return(0);
}
