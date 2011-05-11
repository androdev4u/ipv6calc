/*
 * Project    : ipv6calc
 * File       : ipv6loganonoptions.h
 * Version    : $Id: ipv6loganonoptions.h,v 1.6 2011/05/11 20:12:20 peter Exp $
 * Copyright  : 2007-2011 by Peter Bieringer <pb (at) bieringer.de>
 *
 * Information:
 *  Header file containing options for ipvloganon.c
 */ 

#include <getopt.h> 

#include "ipv6calctypes.h"


#ifndef _ipv6loganonoptions_h_

#define _ipv6loganonoptions_h_

/* Options */

/* define short options */
static char *ipv6loganon_shortopts = "vnVh?d:c:w:a:";

/* define long options */
static struct option ipv6loganon_longopts[] = {
	{"version", 0, 0, (int) 'v'},
	{"debug", 1, 0, (int) 'd'},
	{"verbose", 0, 0, (int) 'V'},
	{"nocache", 0, 0, (int) 'n'},
	{"cachelimit", 1, 0, (int) 'c'},
	{"write", 1, 0, (int) 'w'},
	{"append", 1, 0, (int) 'a'},

	/* help options */
	{"help", 0, 0, (int) 'h'},

	/* options */
	{ "anonymize-standard" , 0, 0, CMD_ANON_PRESET_STANDARD },
	{ "anonymize-careful" , 0, 0, CMD_ANON_PRESET_CAREFUL },
	{ "anonymize-paranoid" , 0, 0, CMD_ANON_PRESET_PARANOID },
	{ "mask-ipv4" , 1, 0, CMD_ANON_MASK_IPV4 },
	{ "mask-ipv6" , 1, 0, CMD_ANON_MASK_IPV6 },
	{ "no-mask-iid" , 0, 0, CMD_ANON_NO_MASK_IID },

	{NULL, 0, 0, 0}
};                

#endif
