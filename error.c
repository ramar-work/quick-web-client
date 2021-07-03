#include "error.h"

const char *errMessages[] = {
	NULL
};

//An error string buffer (useless)
static char _errbuf[2048] = {0};

//Use this to return from functions
int err_set ( int status, char *fmt, ... ) {
	va_list ap;
	va_start( ap, fmt ); 
	vsnprintf( _errbuf, sizeof( _errbuf ), fmt, ap );  
#if 1
	//fprintf( stderr, _errbuf ); //Banner should go here...
	fprintf( stderr, "%s\n", _errbuf );
#endif
	va_end( ap );
	return status;
}


//Use this to return from main()
int err_print ( int status, char *fmt, ... ) {
	died = 1;
	fprintf( stderr, PROG ": " );
	va_list ap;
	va_start( ap, fmt ); 
	//write in the "base" arg first (the program name)
	//then do each of the others...
	vfprintf( stderr, fmt, ap );  
	va_end( ap );
	fprintf( stderr, "\n" );
	return status;
}
