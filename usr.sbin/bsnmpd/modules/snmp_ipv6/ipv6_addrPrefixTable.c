/*
 * Copyright (c) 2017 Dell EMC Isilon
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/cdefs.h>

__FBSDID("$FreeBSD$");

#include <sys/param.h>
#include <sys/sysctl.h>
#include <bsnmp/snmpmod.h>

#include "ipv6_addrPrefixTable.h"

int
op_ipv6AddrPrefixTable(struct snmp_context *ctx __unused,
    struct snmp_value *value, u_int sub, u_int iidx __unused, enum snmp_op op)
{
	asn_subid_t which;

	switch (op) {
	case SNMP_OP_GETNEXT:
	case SNMP_OP_GET:
		break;
	case SNMP_OP_SET:
		return (SNMP_ERR_NOT_WRITEABLE);
	case SNMP_OP_ROLLBACK:
	case SNMP_OP_COMMIT:
		return (SNMP_ERR_NOERROR);
	}

	which = value->var.subs[sub - 1];

	switch (which) {
	case LEAF_ipv6AddrPrefix:
	case LEAF_ipv6AddrPrefixLength:
	case LEAF_ipv6AddrPrefixOnLinkFlag:
	case LEAF_ipv6AddrPrefixAutonomousFlag:
	case LEAF_ipv6AddrPrefixAdvPreferredLifetime:
	case LEAF_ipv6AddrPrefixPrefixAdvValidLifetime:
	default:
		return (SNMP_ERR_RES_UNAVAIL);
	}

	return (SNMP_ERR_NOERROR);
}
