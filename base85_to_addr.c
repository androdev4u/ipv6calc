/*
 * base85_to_addr:
 *  A function to format a given base85 formatted IPv6 address to a
 *   normal one (reverse RFC 1924)
 *
 * Version:		$Id: base85_to_addr.c,v 1.1.1.1 2001/10/07 14:47:40 peter Exp $
 * 
 * Author:		Peter Bieringer <pb@bieringer.de>
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "ipv6calc.h"
#include "librfc1924.h"

void base85_to_addr_printhelp() {
	fprintf(stderr, " %s --base85_to_addr base85_formatted_ipv6addr\n", PROGRAM_NAME);
};

void base85_to_addr_printhelplong() {
	base85_to_addr_printhelp();
	fprintf(stderr, "  Converts base85 formatted IPv6 address to a normal one (reverse RFC 1924)\n");
	fprintf(stderr, "   e.g. 4)+k&C#VzJ4br>0wv%%Yp -> 1080:0:0:0:8:800:200c:417a\n");
};

/* Function converts a base85 formatted IPv6 address to a normal one
 *  
 * in : *addrstring = base85 formatted IPv6 address
 * out: *resultstring = result
 * ret: ==0: ok, !=0: error
 */
#define DEBUG_function_name "base85_to_addr"
int base85_to_addr(char *addrstring, char *resultstring) {
	int retval = 1, result;
	ipv6calc_ipv6addr ipv6addr;

	if ( ipv6calc_debug & DEBUG_base85_to_addr) {
		fprintf(stderr, "%s: Got input %s\n", DEBUG_function_name, addrstring);
	};

	result = base85_to_ipv6addrstruct(addrstring, resultstring, &ipv6addr);

	if ( ipv6calc_debug & DEBUG_base85_to_addr) {
		fprintf(stderr, "%s: result of 'base85_to_ipv6calc_ipv6addr': %d\n", DEBUG_function_name,result);
	};

	if ( result != 0 ) {
		retval = 1;
		return (retval);
	};

	result = ipv6addrstruct_to_uncompaddr(&ipv6addr, resultstring);
   
	retval = 0;
	return (retval);
};
#undef DEBUG_function_name
