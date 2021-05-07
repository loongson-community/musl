struct statfs {
	long f_type, f_bsize;
	unsigned long f_blocks, f_bfree, f_bavail, f_files, f_ffree;
	fsid_t f_fsid;
	long f_namelen, f_frsize, f_flags, f_spare[4];
};
