#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)

#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#define MINSIGSTKSZ 8192
#define SIGSTKSZ (MINSIGSTKSZ + 32768)
#endif

#define ARCH_MIN_TASKALIGN	32
#define FPU_REG_WIDTH		256
#define FPU_ALIGN		__attribute__((aligned(32)))

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
typedef unsigned long greg_t, gregset_t[32];

struct sigcontext {
	unsigned long   sc_pc;
	unsigned long   sc_regs[32];
	unsigned int    sc_flags;
	unsigned int    sc_fcsr;
	unsigned int    sc_vcsr;
	unsigned long   sc_fcc;
	unsigned long   sc_scr[4];
	union {
		unsigned int		val32[FPU_REG_WIDTH / 32];
		unsigned long long	val64[FPU_REG_WIDTH / 64];
	} sc_fpregs[32] FPU_ALIGN;
	unsigned char	sc_reserved[4096] __attribute__((__aligned__(16)));
};

typedef struct {
	unsigned long   pc;
	unsigned long   gregs[32];
	unsigned int    flags;
	unsigned int    fcsr;
	unsigned int    vcsr;
	unsigned long   fcc;
	unsigned long   scr[4];
	union {
                unsigned int            val32[FPU_REG_WIDTH / 32];
                unsigned long long      val64[FPU_REG_WIDTH / 64];
        } fpregs[32] FPU_ALIGN;
	unsigned char   reserved[4096] __attribute__((__aligned__(16)));
} mcontext_t;

#else
typedef struct {
	unsigned long __mc1[32];
	union {
                unsigned int            val32[FPU_REG_WIDTH / 32];
                unsigned long long      val64[FPU_REG_WIDTH / 64];
        } _mc2[32] FPU_ALIGN;
	unsigned int __mc3[3];
	unsigned long __mc4[2];
	unsigned long __mc5[4];
	unsigned char reserved[4096] __attribute__((__aligned__(16)));
} mcontext_t;

#endif

struct sigaltstack {
	void *ss_sp;
	int ss_flags;
	size_t ss_size;
};

typedef struct __ucontext
{
	unsigned long  __uc_flags;
	struct __ucontext *uc_link;
	stack_t            uc_stack;
	mcontext_t uc_mcontext;
	sigset_t           uc_sigmask;
} ucontext_t;


#define SA_NOCLDSTOP  1          /* Don't send SIGCHLD when children stop.  */
#define SA_NOCLDWAIT  2          /* Don't create zombie on child death.  */
#define SA_SIGINFO    4          /* Invoke signal-catching function with
                                    three arguments instead of one.  */
#define SA_ONSTACK   0x08000000 /* Use signal stack by using `sa_restorer'. */
#define SA_RESTART   0x10000000 /* Restart syscall on signal return.  */
#define SA_NODEFER   0x40000000 /* Don't automatically block the signal when
                                    its handler is being executed.  */
#define SA_RESETHAND 0x80000000 /* Reset to SIG_DFL on entry to handler.  */
#define SA_RESTORER  0x04000000

#undef SIG_BLOCK
#undef SIG_UNBLOCK
#undef SIG_SETMASK
#define SIG_BLOCK     0
#define SIG_UNBLOCK   1
#define SIG_SETMASK   2

#undef SI_ASYNCIO
#undef SI_MESGQ
#undef SI_TIMER
#define SI_ASYNCIO (-4)
#define SI_MESGQ (-3)
#define SI_TIMER (-2)


#endif

#define SIGHUP           1
#define SIGINT           2
#define SIGQUIT          3
#define SIGILL           4
#define SIGTRAP          5
#define SIGABRT          6
#define SIGIOT           6
#define SIGBUS           7
#define SIGFPE           8
#define SIGKILL          9
#define SIGUSR1         10
#define SIGSEGV         11
#define SIGUSR2         12
#define SIGPIPE         13
#define SIGALRM         14
#define SIGTERM         15
#define SIGSTKFLT       16
#define SIGCHLD         17
#define SIGCONT         18
#define SIGSTOP         19
#define SIGTSTP         20
#define SIGTTIN         21
#define SIGTTOU         22
#define SIGURG          23
#define SIGXCPU         24
#define SIGXFSZ         25
#define SIGVTALRM       26
#define SIGPROF         27
#define SIGWINCH        28
#define SIGIO           29
#define SIGPOLL         SIGIO
/*
#define SIGLOST         29
*/
#define SIGPWR          30
#define SIGSYS          31

#define SIGUNUSED SIGSYS

#define _NSIG 128
