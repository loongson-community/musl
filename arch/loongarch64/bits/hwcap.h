/* HWCAP - Hardware Capabilities
 * Hardware information is not clear at present, leave it blank. 
 */
#define HWCAP_LOONGARCH_CPUCFG	(1 << 0)
#define HWCAP_LOONGARCH_FPU	(1 << 1)
#define HWCAP_LOONGARCH_LSX	(1 << 2)  /* support 128bit vectors*/
#define HWCAP_LOONGARCH_LASX	(1 << 3)  /* support 256bit vectors*/
#define HWCAP_LOONGARCH_LBT	(1 << 4)  /* support LBT*/
#define HWCAP_LOONGARCH_LVZ	(1 << 5)  /* support virtualization expansion*/
#define HWCAP_LOONGARCH_CRC32	(1 << 7)  /* support CRC32 check*/
#define HWCAP_LOONGARCH_AES	(1 << 6)
#define HWCAP_LOONGARCH_SHA1	(1 << 8)
#define HWCAP_LOONGARCH_SHA2	(1 << 9)
#define HWCAP_LOONGARCH_SHA3	(1 << 10)

