#
# Makefile for ipv6calc
#
# Version:     $Id: Makefile,v 1.1.1.1 2001/10/07 14:47:40 peter Exp $
#
# Author:      Peter Bieringer <pb@bieringer.de>
#

# Compiler and Linker Options
#COPTS = -O2 -Wall -g		# old one
COPTS = -O2 -Wall -g -ansi	# ANSI compatible

CFLAGS	= $(COPTS)

CC	= gcc

#OBJS = ipv6calc.o addr_to_compressed.o addr_to_uncompressed.o addr_to_fulluncompressed.o addr_to_ifinet6.o addr_to_ip6int.o ifinet6_to_compressed.o  libipv6calc.o addr_to_base85.o librfc1924.o base85_to_addr.o librfc1884.o libmac.o libeui64.o mac_to_eui64.o eui64_to_privacy.o librfc3041.o showinfo.o ipv6types.o
OBJS = ipv6calc.o addr_to_compressed.o addr_to_uncompressed.o addr_to_fulluncompressed.o addr_to_ifinet6.o addr_to_ip6int.o ifinet6_to_compressed.o  libipv6calc.o addr_to_base85.o librfc1924.o base85_to_addr.o librfc1884.o libmac.o libeui64.o mac_to_eui64.o eui64_to_privacy.o librfc3041.o showinfo.o libipv6addr.o

all:	ipv6calc

.c.o:
		$(CC) $(CFLAGS) -c $<

$(OBJS):	ipv6calc.h libipv6addr.h librfc1884.h

ipv6calc:	$(OBJS)
			$(CC)  -o ipv6calc $(OBJS) /usr/lib/libcrypto.so

clean:
		rm -rf ipv6calc *.o

install:
		make test
		mkdir -p $(root)/bin/
		install -m 755 -o root -g root ipv6calc $(root)/bin/

installonly:
		mkdir -p $(root)/bin/
		install -m 755 -o root -g root ipv6calc $(root)/bin/

test:
		make
		./test_ipv6calc.sh || exit 1
