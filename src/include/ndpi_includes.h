/*
 * ndpi_includes.h
 *
 * Copyright (C) 2011-16 - ntop.org
 *
 * This file is part of nDPI, an open source deep packet inspection
 * library based on the OpenDPI and PACE technology by ipoque GmbH
 *
 * nDPI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * nDPI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with nDPI.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef __NDPI_INCLUDES_H__
#define __NDPI_INCLUDES_H__

#ifndef __KERNEL__

#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>

#ifdef WIN32
#include "ndpi_win32.h"
#else
#include <sys/types.h>
#include <sys/param.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

#if !defined __APPLE__ && !defined __FreeBSD__ && !defined __NetBSD__ && !defined __OpenBSD__
#include <endian.h>
#include <byteswap.h>

#if defined __FreeBSD__ || defined __NetBSD__ || defined __OpenBSD__
#include <netinet/in.h>

#if defined __NetBSD__ || defined __OpenBSD__
#include <netinet/in_systm.h>

#ifdef __OpenBSD__
#include <pthread.h>

#endif
#endif
#endif
#endif

#endif	/* Win32 */

#else /* KERNEL */

#include "ndpi_define.h"
#include <asm/byteorder.h>
#include <linux/types.h>
#include <linux/spinlock.h>
#include <linux/in.h>
#include <linux/times.h>
#include <linux/ctype.h>
#include <linux/slab.h>

# if BYTE_ORDER == __LITTLE_ENDIAN
#  define htobe16(x) __bswap_16 (x)
#  define htole16(x) (x)
#  define be16toh(x) __bswap_16 (x)
#  define le16toh(x) (x)

#  define htobe32(x) __bswap_32 (x)
#  define htole32(x) (x)
#  define be32toh(x) __bswap_32 (x)
#  define le32toh(x) (x)

#  define htobe64(x) __bswap_64 (x)
#  define htole64(x) (x)
#  define be64toh(x) __bswap_64 (x)
#  define le64toh(x) (x)
# else
#  define htobe16(x) (x)
#  define htole16(x) __bswap_16 (x)
#  define be16toh(x) (x)
#  define le16toh(x) __bswap_16 (x)

#  define htobe32(x) (x)
#  define htole32(x) __bswap_32 (x)
#  define be32toh(x) (x)
#  define le32toh(x) __bswap_32 (x)

#  define htobe64(x) (x)
#  define htole64(x) __bswap_64 (x)
#  define be64toh(x) (x)
#  define le64toh(x) __bswap_64 (x)
# endif

#define printf(format, ...)    printk(format,##__VA_ARGS__)
#ifndef IPVERSION
#define        IPVERSION       4
#endif

#endif

#endif /* __NDPI_INCLUDES_H__ */
