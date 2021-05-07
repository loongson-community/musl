#ifndef __RELOC_H__
#define __RELOC_H__

#define _GNU_SOURCE
#include <endian.h>

#ifdef __loongarch64_soft_float
#define FP_SUFFIX "-sf"
#else
#define FP_SUFFIX ""
#endif

#define LDSO_ARCH "loongarch64"  FP_SUFFIX

#define TPOFF_K (0x0)

//#define REL_SYM_OR_REL  4611  
#define REL_PLT         R_LOONGARCH_JUMP_SLOT
#define REL_COPY        R_LOONGARCH_COPY
#define REL_DTPMOD      R_LOONGARCH_TLS_DTPMOD64
#define REL_DTPOFF      R_LOONGARCH_TLS_DTPREL64
#define REL_TPOFF       R_LOONGARCH_TLS_TPREL64
#define REL_RELATIVE    R_LOONGARCH_RELATIVE
#define REL_SYMBOLIC    R_LOONGARCH_64

//#undef R_TYPE
//#undef R_SYM
//#undef R_INFO
//#define R_TYPE(x) (be64toh(x)&0x7fffffff)
//#define R_SYM(x) (be32toh(be64toh(x)>>32))
//#define R_INFO(s,t) (htobe64((uint64_t)htobe32(s)<<32 | (uint64_t)t))

#define CRTJMP(pc,sp) __asm__ __volatile__( \
	"move $sp,%1 ; jr %0" : : "r"(pc), "r"(sp) : "memory" )

#define GETFUNCSYM(fp, sym, got) __asm__ ( \
	".hidden " #sym "\n" \
	".align 8 \n" \
	"	la.local $t1, "#sym" \n" \
	"	or %0, $t1, $zero \n" \
	: "=r"(*(fp)) : : "memory" )

#endif
