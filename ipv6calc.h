/*
 * Version:     $Id: ipv6calc.h,v 1.1.1.1 2001/10/07 14:47:40 peter Exp $
 *
 * Author:      Peter Bieringer <pb@bieringer.de>
 *
 */ 


#ifndef _ipv6calc_h_

#define _ipv6calc_h_

/* global program related definitions */
#define PROGRAM_NAME "ipv6calc"
#define PROGRAM_VERSION "0.29"
#define PROGRAM_COPYRIGHT "(P) & (C) 2001 by Peter Bieringer <pb@bieringer.de>\n published under GNU GPL"

/* global includes */
#include <netinet/in.h>

/*** global definitions ***/
/* max length of a string for storage in a char array */
#define NI_MAXHOST 1024

/* debug switches */
/* #define DEBUG_addr_to_compressed */
/* #define DEBUG_addr_to_uncompressed */
/* #define DEBUG_addr_to_fulluncompressed */
/* #define DEBUG_ifinet6_to_compressed */

/* debug switches for libaries */
/* #define DEBUG_librfc1924 */
/* #define DEBUG_libipv6calc */
/* #define DEBUG_libmac */
/* #define DEBUG_libeui64 */


/* command values */
#define CMD_MINOR_MASK          0x0000Fl
#define CMD_FORMAT_MASK         0x000F0l
#define CMD_printhelp           0x00001l
#define CMD_printversion        0x00002l
#define CMD_printlowercase      0x00004l
#define CMD_printuppercase      0x00008l
#define CMD_printprefix         0x00010l
#define CMD_printsuffix         0x00020l
#define CMD_maskprefix        	0x00040l
#define CMD_masksuffix         	0x00080l

#define CMD_MAJOR_MASK               0xFFF00l
#define CMD_addr_to_ip6int           0x00100l
#define CMD_addr_to_compressed       0x00200l
#define CMD_addr_to_uncompressed     0x00400l
#define CMD_addr_to_fulluncompressed 0x00800l
#define CMD_addr_to_ifinet6          0x01000l
#define CMD_ifinet6_to_compressed    0x02000l
#define CMD_addr_to_base85           0x04000l
#define CMD_base85_to_addr           0x08000l
#define CMD_mac_to_eui64             0x10000l
#define CMD_eui64_to_privacy         0x20000l
#define CMD_showinfo                 0x40000l

/* debug values */
#define DEBUG_eui64_to_privacy		CMD_eui64_to_privacy
#define DEBUG_showinfo              CMD_showinfo
#define DEBUG_addr_to_ifinet6		CMD_addr_to_ifinet6
#define DEBUG_base85_to_addr		CMD_base85_to_addr
#define DEBUG_addr_to_base85		CMD_addr_to_base85
#define DEBUG_addr_to_ip6int 		CMD_addr_to_ip6int
#define DEBUG_mac_to_eui64			CMD_mac_to_eui64 

#define DEBUG_libipv6calc			0x000001l
#define DEBUG_librfc3041			0x000002l
#define DEBUG_librfc1884			0x000004l

/* structures */
typedef struct {
	unsigned int addr[6];		/* MAC address in 6x 8 bit */
} ipv6calc_macaddr;

typedef struct {
	struct in6_addr in6_addr;	/* in6_addr structure */
	unsigned short prefixlength;	/* prefix length (0-128) 8 bit*/
	int flag_prefixuse;				/* =1 prefix length in use */
	unsigned int scope;				/* address scope value 16 bit*/
} ipv6calc_ipv6addr;

/* global debug value */
extern long int ipv6calc_debug;

/* external functions */
extern int  addr_to_ip6int(char *addrstring, char *resultstring);
extern void addr_to_ip6int_printhelp();
extern void addr_to_ip6int_printhelplong();

extern int  addr_to_compressed(char *addrstring, char *resultstring);
extern void addr_to_compressed_printhelp();
extern void addr_to_compressed_printhelplong();

extern int  addr_to_uncompressed(char *addrstring, char *resultstring, unsigned int formatselector);
extern void addr_to_uncompressed_printhelp();
extern void addr_to_uncompressed_printhelplong();

extern int  addr_to_fulluncompressed(char *addrstring, char *resultstring, unsigned int formatselector);
extern void addr_to_fulluncompressed_printhelp();
extern void addr_to_fulluncompressed_printhelplong();

extern int  addr_to_ifinet6(char *addrstring, char *resultstring);
extern void addr_to_ifinet6_printhelp();
extern void addr_to_ifinet6_printhelplong();

extern int  ifinet6_to_compressed(char *addrstring, char *resultstring);
extern int  ifinet6_to_compressedwithprefixlength(char *addrstring, char *prefixlengthstring, char *resultstring);
extern void ifinet6_to_compressed_printhelp();
extern void ifinet6_to_compressed_printhelplong();

extern int eui64_to_privacy(char *hostidentifier, char *token, char *resultstring);
extern void eui64_to_privacy_printhelp();
extern void eui64_to_privacy_printhelplong();

extern int  addr_to_base85(char *addrstring, char *resultstring);
extern void addr_to_base85_printhelp();
extern void addr_to_base85_printhelplong();

extern int  base85_to_addr(char *addrstring, char *resultstring);
extern void base85_to_addr_printhelp();
extern void base85_to_addr_printhelplong();

extern int  mac_to_eui64(char *addrstring, char *resultstring);
extern void mac_to_eui64_printhelp();
extern void mac_to_eui64_printhelplong();

extern int showinfo(char *addrstring, char *resultstring);
extern void showinfo_printhelp();
extern void showinfo_printhelplong();


/* libipv6calc */
extern int addr_to_ipv6addrstruct(char *addrstring, char *resultstring, ipv6calc_ipv6addr *ipv6addrp);

extern int ipv6addrstruct_to_uncompaddr(ipv6calc_ipv6addr *ipv6addrp, char *resultstring);
extern int ipv6addrstruct_to_uncompaddrprefix(ipv6calc_ipv6addr *ipv6addrp, char *resultstring);
extern int ipv6addrstruct_to_uncompaddrsuffix(ipv6calc_ipv6addr *ipv6addrp, char *resultstring);

extern int ipv6addrstruct_to_fulluncompaddr(ipv6calc_ipv6addr *ipv6addrp, char *resultstring);

extern void ipv6addrstruct_maskprefix(ipv6calc_ipv6addr *ipv6addrp);
extern void ipv6addrstruct_masksuffix(ipv6calc_ipv6addr *ipv6addrp);

extern int identifier_to_ipv6addrstruct(char *addrstring, char *resultstring, ipv6calc_ipv6addr *ipv6addrp);

/* libmac */
extern int mac_to_macaddrstruct(char *addrstring, char *resultstring, ipv6calc_macaddr *macaddrp);

/* libeui64 */
extern int create_eui64_from_mac(ipv6calc_ipv6addr *ipv6addrp, ipv6calc_macaddr *macaddrp);

#endif
