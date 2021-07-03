#include "web.h"

typedef struct { char *url; int i; wwwResponse www; } Url;
Url urls[] = {
  { "//www.ramarcollins.com" /* ... */ }
, { "http://www.ramarcollins.com" /* ... */ }
, { "http://neverssl.com" /* ... */ }
, { "http://ramar.work" /* ... */ }
, { "https://amp.businessinsider.com/images/592f4169b74af41b008b5977-750-563.jpg" }
, { "https://cabarruscountycars.com/legacy" } //contains clen
#if 0
, {	"https://www.httpwatch.com/httpgallery/chunked/chunkedimage.aspx?0.46782549706004284" }
#endif

#if 0
	//This is some script that I can use to test with memcmp
,	{ "https://jigsaw.w3.org/HTTP/ChunkedScript" }
, { "//upload.wikimedia.org/wikipedia/commons/thumb/1/1d/Nissan_GT-R_PROTO.jpg/220px-Nissan_GT-R_PROTO.jpg" }
#endif

#if 0
	//These are all binary images... just write them out and call it a day
, { "https://amp.businessinsider.com/images/592f4169b74af41b008b5977-750-563.jpg" }
, { "https://i.gifer.com/1TM.gif" }
, { "http://blogs.smithsonianmag.com/smartnews/files/2013/06/5008578082_2b5f4434bd_z.jpg" }
#endif

#if 0
// #include "tests/urlHttps.c"
#endif

#if 0
	//These are simple SSL pages
, {	"https://www.google.com/search?client=opera&q=gnutls+error+string&sourceid=opera&ie=UTF-8&oe=UTF-8" }
//these seem to work...
, { "http://www.ramarcollins.com" }
, { "https://cabarruscountycars.com/legacy" } //contains clen
, {	"https://www.google.com/search?client=opera&q=gnutls+error+string&sourceid=opera&ie=UTF-8&oe=UTF-8" }

//so why not these? (they do, but they reject bots... so you'll need js)
, { "https://www.heritagerides.com/inventory.aspx" /*This one just doesn't work... (js block)*/ }
, { "https://www.importmotorsportsnc.com/cars-for-sale" }
#endif

, { NULL }
};



int main (int argc, char *argv[]) {
	//...
	char *buf = NULL;
	int buflen = 0;
	const char bannerFmt[] = "%-50s\t%-6s\t%-6s\t%-6s\n";
	const char argFmt[] = "%-50s\t%-6d\t%-6d\t%-6d\n";

	//Fetch all of the URLs
	fprintf( stderr, "%s\n", "Running test suite..." );
	for ( Url *j = urls; j->url; j++ ) {
		wwwResponse *w = &j->www;
	#if 0
		//Pretty banner to detect what happened when
		char t[81];
		memset( t, 0, sizeof(t) );
		memset( t, 61 /* '=' */, 80 );
		fprintf( stderr, bannerFmt, "Site", "Status", "Clen", "Mlen" );
		fprintf( stderr, "%s\n", t );
	#endif

		//if ( !( j->i = load_www( j->url, &buf, &buflen, &j->www ) ) ) {
		if ( !( j->i = load_www( j->url, w ) ) ) {
			fprintf( stderr, "Failed to load URL at '%s'\n", j->url );
			continue;
		}

		fprintf( stderr, "Loaded URL at '%s'\n", j->url );
		fprintf( stderr, argFmt, j->url, w->status, w->clen, w->len );
		//WRITEF( fname( j->url ), w->data, w->len ); 
		//WRITEF( fname( j->url ), w->body, w->clen ); 
		free( w->data );
	}

	return 0;
}
