# 1 "alarmmonitor.c"
# 1 "<command-line>"
# 1 "alarmmonitor.c"
# 1 "alarmmonitor.h" 1


# 1 "Platform_Types.h" 1
# 13 "Platform_Types.h"
typedef _Bool boolean;
# 25 "Platform_Types.h"
typedef signed char sint8_t;
typedef unsigned char usint8_t;

typedef signed short int sint16_t;
typedef unsigned short int usint16_t;

typedef signed int sint32_t;
typedef unsigned int usint32_t;

typedef signed long long int sint64_t;
typedef unsigned long long int usint64_t;



typedef volatile signed char vsint8_t;
typedef volatile unsigned char vusint8_t;

typedef volatile signed short int vsint16_t;
typedef volatile unsigned short int vusint16_t;

typedef volatile signed int vsint32_t;
typedef volatile unsigned int vusint32_t;

typedef volatile signed long long int vsint64_t;
typedef volatile unsigned long long int vusint64_t;
# 4 "alarmmonitor.h" 2
# 1 "driver/driver.h" 1
# 1 "c:\\arm_toolchain\\bin\\../lib/gcc/arm-none-eabi/4.7.2/include/stdint.h" 1 3 4


# 1 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdint.h" 1 3 4
# 41 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdint.h" 3 4
typedef signed char int8_t ;
typedef unsigned char uint8_t ;




typedef signed char int_least8_t;
typedef unsigned char uint_least8_t;




typedef signed short int16_t;
typedef unsigned short uint16_t;
# 67 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdint.h" 3 4
typedef int16_t int_least16_t;
typedef uint16_t uint_least16_t;
# 79 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdint.h" 3 4
typedef signed long int32_t;
typedef unsigned long uint32_t;
# 97 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdint.h" 3 4
typedef int32_t int_least32_t;
typedef uint32_t uint_least32_t;
# 119 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdint.h" 3 4
typedef signed long long int64_t;
typedef unsigned long long uint64_t;
# 129 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdint.h" 3 4
typedef int64_t int_least64_t;
typedef uint64_t uint_least64_t;
# 159 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdint.h" 3 4
  typedef signed int int_fast8_t;
  typedef unsigned int uint_fast8_t;




  typedef signed int int_fast16_t;
  typedef unsigned int uint_fast16_t;




  typedef signed int int_fast32_t;
  typedef unsigned int uint_fast32_t;
# 213 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdint.h" 3 4
  typedef int_least64_t int_fast64_t;
  typedef uint_least64_t uint_fast64_t;







  typedef long long int intmax_t;
# 231 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdint.h" 3 4
  typedef long long unsigned int uintmax_t;
# 243 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdint.h" 3 4
typedef signed int intptr_t;
typedef unsigned int uintptr_t;
# 4 "c:\\arm_toolchain\\bin\\../lib/gcc/arm-none-eabi/4.7.2/include/stdint.h" 2 3 4
# 2 "driver/driver.h" 2
# 1 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdio.h" 1 3 4
# 29 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdio.h" 3 4
# 1 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/_ansi.h" 1 3 4
# 15 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/_ansi.h" 3 4
# 1 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/newlib.h" 1 3 4
# 16 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/_ansi.h" 2 3 4
# 1 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/config.h" 1 3 4



# 1 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/machine/ieeefp.h" 1 3 4
# 5 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/config.h" 2 3 4
# 1 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/features.h" 1 3 4
# 6 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/config.h" 2 3 4
# 17 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/_ansi.h" 2 3 4
# 30 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdio.h" 2 3 4




# 1 "c:\\arm_toolchain\\bin\\../lib/gcc/arm-none-eabi/4.7.2/include/stddef.h" 1 3 4
# 213 "c:\\arm_toolchain\\bin\\../lib/gcc/arm-none-eabi/4.7.2/include/stddef.h" 3 4
typedef unsigned int size_t;
# 35 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdio.h" 2 3 4


# 1 "c:\\arm_toolchain\\bin\\../lib/gcc/arm-none-eabi/4.7.2/include/stdarg.h" 1 3 4
# 40 "c:\\arm_toolchain\\bin\\../lib/gcc/arm-none-eabi/4.7.2/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 38 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdio.h" 2 3 4







# 1 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/reent.h" 1 3 4
# 13 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/reent.h" 3 4
# 1 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/_ansi.h" 1 3 4
# 14 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/reent.h" 2 3 4
# 1 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/_types.h" 1 3 4
# 12 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/_types.h" 3 4
# 1 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/machine/_types.h" 1 3 4






# 1 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/machine/_default_types.h" 1 3 4
# 26 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/machine/_default_types.h" 3 4
typedef signed char __int8_t ;
typedef unsigned char __uint8_t ;
# 36 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/machine/_default_types.h" 3 4
typedef signed short __int16_t;
typedef unsigned short __uint16_t;
# 46 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/machine/_default_types.h" 3 4
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
# 58 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/machine/_default_types.h" 3 4
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
# 76 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/machine/_default_types.h" 3 4
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
# 99 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/machine/_default_types.h" 3 4
typedef signed long long __int64_t;
typedef unsigned long long __uint64_t;
# 8 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/machine/_types.h" 2 3 4
# 13 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/_types.h" 2 3 4
# 1 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/lock.h" 1 3 4





typedef int _LOCK_T;
typedef int _LOCK_RECURSIVE_T;
# 14 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/_types.h" 2 3 4


typedef long _off_t;







typedef short __dev_t;




typedef unsigned short __uid_t;


typedef unsigned short __gid_t;



__extension__ typedef long long _off64_t;







typedef long _fpos_t;
# 56 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/_types.h" 3 4
typedef int _ssize_t;






# 1 "c:\\arm_toolchain\\bin\\../lib/gcc/arm-none-eabi/4.7.2/include/stddef.h" 1 3 4
# 354 "c:\\arm_toolchain\\bin\\../lib/gcc/arm-none-eabi/4.7.2/include/stddef.h" 3 4
typedef unsigned int wint_t;
# 64 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/_types.h" 2 3 4



typedef struct
{
  int __count;
  union
  {
    wint_t __wch;
    unsigned char __wchb[4];
  } __value;
} _mbstate_t;



typedef _LOCK_RECURSIVE_T _flock_t;




typedef void *_iconv_t;
# 15 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/reent.h" 2 3 4






typedef unsigned long __ULong;
# 37 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/reent.h" 3 4
struct _reent;






struct _Bigint
{
  struct _Bigint *_next;
  int _k, _maxwds, _sign, _wds;
  __ULong _x[1];
};


struct __tm
{
  int __tm_sec;
  int __tm_min;
  int __tm_hour;
  int __tm_mday;
  int __tm_mon;
  int __tm_year;
  int __tm_wday;
  int __tm_yday;
  int __tm_isdst;
};







struct _on_exit_args {
 void * _fnargs[32];
 void * _dso_handle[32];

 __ULong _fntypes;


 __ULong _is_cxa;
};
# 89 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/reent.h" 3 4
struct _atexit {
 struct _atexit *_next;
 int _ind;

 void (*_fns[32])(void);
        struct _on_exit_args _on_exit_args;
};
# 105 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/reent.h" 3 4
struct __sbuf {
 unsigned char *_base;
 int _size;
};
# 169 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/reent.h" 3 4
struct __sFILE {
  unsigned char *_p;
  int _r;
  int _w;
  short _flags;
  short _file;
  struct __sbuf _bf;
  int _lbfsize;






  void * _cookie;

  int (* _read) (struct _reent *, void *, char *, int)
                     ;
  int (* _write) (struct _reent *, void *, const char *, int)
                            ;
  _fpos_t (* _seek) (struct _reent *, void *, _fpos_t, int);
  int (* _close) (struct _reent *, void *);


  struct __sbuf _ub;
  unsigned char *_up;
  int _ur;


  unsigned char _ubuf[3];
  unsigned char _nbuf[1];


  struct __sbuf _lb;


  int _blksize;
  int _offset;


  struct _reent *_data;



  _flock_t _lock;

  _mbstate_t _mbstate;
  int _flags2;
};
# 273 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/reent.h" 3 4
typedef struct __sFILE __FILE;



struct _glue
{
  struct _glue *_next;
  int _niobs;
  __FILE *_iobs;
};
# 305 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/reent.h" 3 4
struct _rand48 {
  unsigned short _seed[3];
  unsigned short _mult[3];
  unsigned short _add;




};
# 580 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/reent.h" 3 4
struct _reent
{
  int _errno;




  __FILE *_stdin, *_stdout, *_stderr;

  int _inc;
  char _emergency[25];

  int _current_category;
  const char *_current_locale;

  int __sdidinit;

  void (* __cleanup) (struct _reent *);


  struct _Bigint *_result;
  int _result_k;
  struct _Bigint *_p5s;
  struct _Bigint **_freelist;


  int _cvtlen;
  char *_cvtbuf;

  union
    {
      struct
        {
          unsigned int _unused_rand;
          char * _strtok_last;
          char _asctime_buf[26];
          struct __tm _localtime_buf;
          int _gamma_signgam;
          __extension__ unsigned long long _rand_next;
          struct _rand48 _r48;
          _mbstate_t _mblen_state;
          _mbstate_t _mbtowc_state;
          _mbstate_t _wctomb_state;
          char _l64a_buf[8];
          char _signal_buf[24];
          int _getdate_err;
          _mbstate_t _mbrlen_state;
          _mbstate_t _mbrtowc_state;
          _mbstate_t _mbsrtowcs_state;
          _mbstate_t _wcrtomb_state;
          _mbstate_t _wcsrtombs_state;
   int _h_errno;
        } _reent;



      struct
        {

          unsigned char * _nextf[30];
          unsigned int _nmalloc[30];
        } _unused;
    } _new;


  struct _atexit *_atexit;
  struct _atexit _atexit0;


  void (**(_sig_func))(int);




  struct _glue __sglue;
  __FILE __sf[3];
};
# 818 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/reent.h" 3 4
extern struct _reent *_impure_ptr ;
extern struct _reent *const _global_impure_ptr ;

void _reclaim_reent (struct _reent *);
# 46 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdio.h" 2 3 4
# 1 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/types.h" 1 3 4
# 69 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/types.h" 3 4
# 1 "c:\\arm_toolchain\\bin\\../lib/gcc/arm-none-eabi/4.7.2/include/stddef.h" 1 3 4
# 150 "c:\\arm_toolchain\\bin\\../lib/gcc/arm-none-eabi/4.7.2/include/stddef.h" 3 4
typedef int ptrdiff_t;
# 325 "c:\\arm_toolchain\\bin\\../lib/gcc/arm-none-eabi/4.7.2/include/stddef.h" 3 4
typedef unsigned int wchar_t;
# 70 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/types.h" 2 3 4
# 1 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/machine/types.h" 1 3 4
# 19 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/machine/types.h" 3 4
typedef long int __off_t;
typedef int __pid_t;

__extension__ typedef long long int __loff_t;
# 71 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/types.h" 2 3 4
# 92 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/types.h" 3 4
typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;
typedef unsigned long u_long;



typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;



typedef unsigned long clock_t;




typedef long time_t;




struct timespec {
  time_t tv_sec;
  long tv_nsec;
};

struct itimerspec {
  struct timespec it_interval;
  struct timespec it_value;
};


typedef long daddr_t;
typedef char * caddr_t;






typedef unsigned short ino_t;
# 163 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/types.h" 3 4
typedef _off_t off_t;
typedef __dev_t dev_t;
typedef __uid_t uid_t;
typedef __gid_t gid_t;





typedef int pid_t;







typedef long key_t;

typedef _ssize_t ssize_t;
# 196 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/types.h" 3 4
typedef unsigned int mode_t __attribute__ ((__mode__ (__SI__)));




typedef unsigned short nlink_t;
# 223 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/types.h" 3 4
typedef long fd_mask;







typedef struct _types_fd_set {
 fd_mask fds_bits[(((64)+(((sizeof (fd_mask) * 8))-1))/((sizeof (fd_mask) * 8)))];
} _types_fd_set;
# 254 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/types.h" 3 4
typedef unsigned long clockid_t;




typedef unsigned long timer_t;



typedef unsigned long useconds_t;
typedef long suseconds_t;
# 47 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdio.h" 2 3 4



typedef __FILE FILE;




typedef _fpos_t fpos_t;





# 1 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/sys/stdio.h" 1 3 4
# 62 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdio.h" 2 3 4
# 171 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdio.h" 3 4
FILE * tmpfile (void);
char * tmpnam (char *);
int fclose (FILE *);
int fflush (FILE *);
FILE * freopen (const char *, const char *, FILE *);
void setbuf (FILE *, char *);
int setvbuf (FILE *, char *, int, size_t);
int fprintf (FILE *, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)))
                                                            ;
int fscanf (FILE *, const char *, ...) __attribute__ ((__format__ (__scanf__, 2, 3)))
                                                           ;
int printf (const char *, ...) __attribute__ ((__format__ (__printf__, 1, 2)))
                                                            ;
int scanf (const char *, ...) __attribute__ ((__format__ (__scanf__, 1, 2)))
                                                           ;
int sscanf (const char *, const char *, ...) __attribute__ ((__format__ (__scanf__, 2, 3)))
                                                           ;
int vfprintf (FILE *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)))
                                                            ;
int vprintf (const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 1, 0)))
                                                            ;
int vsprintf (char *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)))
                                                            ;
int fgetc (FILE *);
char * fgets (char *, int, FILE *);
int fputc (int, FILE *);
int fputs (const char *, FILE *);
int getc (FILE *);
int getchar (void);
char * gets (char *);
int putc (int, FILE *);
int putchar (int);
int puts (const char *);
int ungetc (int, FILE *);
size_t fread (void *, size_t _size, size_t _n, FILE *);
size_t fwrite (const void * , size_t _size, size_t _n, FILE *);



int fgetpos (FILE *, fpos_t *);

int fseek (FILE *, long, int);



int fsetpos (FILE *, const fpos_t *);

long ftell ( FILE *);
void rewind (FILE *);
void clearerr (FILE *);
int feof (FILE *);
int ferror (FILE *);
void perror (const char *);

FILE * fopen (const char *_name, const char *_type);
int sprintf (char *, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)))
                                                            ;
int remove (const char *);
int rename (const char *, const char *);






int fseeko (FILE *, off_t, int);
off_t ftello ( FILE *);




int asiprintf (char **, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)))
                                                            ;
char * asniprintf (char *, size_t *, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
                                                            ;
char * asnprintf (char *, size_t *, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
                                                            ;
int asprintf (char **, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)))
                                                            ;

int diprintf (int, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)))
                                                            ;

int fcloseall (void);
int fiprintf (FILE *, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)))
                                                            ;
int fiscanf (FILE *, const char *, ...) __attribute__ ((__format__ (__scanf__, 2, 3)))
                                                           ;
int iprintf (const char *, ...) __attribute__ ((__format__ (__printf__, 1, 2)))
                                                            ;
int iscanf (const char *, ...) __attribute__ ((__format__ (__scanf__, 1, 2)))
                                                           ;
int siprintf (char *, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)))
                                                            ;
int siscanf (const char *, const char *, ...) __attribute__ ((__format__ (__scanf__, 2, 3)))
                                                           ;
int snprintf (char *, size_t, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
                                                            ;
int sniprintf (char *, size_t, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
                                                            ;
char * tempnam (const char *, const char *);
int vasiprintf (char **, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)))
                                                            ;
char * vasniprintf (char *, size_t *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
                                                            ;
char * vasnprintf (char *, size_t *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
                                                            ;
int vasprintf (char **, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)))
                                                            ;
int vdiprintf (int, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)))
                                                            ;
int vfiprintf (FILE *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)))
                                                            ;
int vfiscanf (FILE *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 2, 0)))
                                                           ;
int vfscanf (FILE *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 2, 0)))
                                                           ;
int viprintf (const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 1, 0)))
                                                            ;
int viscanf (const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 1, 0)))
                                                           ;
int vscanf (const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 1, 0)))
                                                           ;
int vsiprintf (char *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)))
                                                            ;
int vsiscanf (const char *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 2, 0)))
                                                           ;
int vsniprintf (char *, size_t, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
                                                            ;
int vsnprintf (char *, size_t, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
                                                            ;
int vsscanf (const char *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 2, 0)))
                                                           ;
# 313 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdio.h" 3 4
FILE * fdopen (int, const char *);

int fileno (FILE *);
int getw (FILE *);
int pclose (FILE *);
FILE * popen (const char *, const char *);
int putw (int, FILE *);
void setbuffer (FILE *, char *, int);
int setlinebuf (FILE *);
int getc_unlocked (FILE *);
int getchar_unlocked (void);
void flockfile (FILE *);
int ftrylockfile (FILE *);
void funlockfile (FILE *);
int putc_unlocked (int, FILE *);
int putchar_unlocked (int);
# 338 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdio.h" 3 4
int dprintf (int, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)))
                                                            ;

FILE * fmemopen (void *, size_t, const char *);


FILE * open_memstream (char **, size_t *);



int vdprintf (int, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)))
                                                            ;







int _asiprintf_r (struct _reent *, char **, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
                                                            ;
char * _asniprintf_r (struct _reent *, char *, size_t *, const char *, ...) __attribute__ ((__format__ (__printf__, 4, 5)))
                                                            ;
char * _asnprintf_r (struct _reent *, char *, size_t *, const char *, ...) __attribute__ ((__format__ (__printf__, 4, 5)))
                                                            ;
int _asprintf_r (struct _reent *, char **, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
                                                            ;
int _diprintf_r (struct _reent *, int, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
                                                            ;
int _dprintf_r (struct _reent *, int, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
                                                            ;
int _fclose_r (struct _reent *, FILE *);
int _fcloseall_r (struct _reent *);
FILE * _fdopen_r (struct _reent *, int, const char *);
int _fflush_r (struct _reent *, FILE *);
int _fgetc_r (struct _reent *, FILE *);
char * _fgets_r (struct _reent *, char *, int, FILE *);




int _fgetpos_r (struct _reent *, FILE *, fpos_t *);
int _fsetpos_r (struct _reent *, FILE *, const fpos_t *);

int _fiprintf_r (struct _reent *, FILE *, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
                                                            ;
int _fiscanf_r (struct _reent *, FILE *, const char *, ...) __attribute__ ((__format__ (__scanf__, 3, 4)))
                                                           ;
FILE * _fmemopen_r (struct _reent *, void *, size_t, const char *);
FILE * _fopen_r (struct _reent *, const char *, const char *);
FILE * _freopen_r (struct _reent *, const char *, const char *, FILE *);
int _fprintf_r (struct _reent *, FILE *, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
                                                            ;
int _fpurge_r (struct _reent *, FILE *);
int _fputc_r (struct _reent *, int, FILE *);
int _fputs_r (struct _reent *, const char *, FILE *);
size_t _fread_r (struct _reent *, void *, size_t _size, size_t _n, FILE *);
int _fscanf_r (struct _reent *, FILE *, const char *, ...) __attribute__ ((__format__ (__scanf__, 3, 4)))
                                                           ;
int _fseek_r (struct _reent *, FILE *, long, int);
int _fseeko_r (struct _reent *, FILE *, _off_t, int);
long _ftell_r (struct _reent *, FILE *);
_off_t _ftello_r (struct _reent *, FILE *);
void _rewind_r (struct _reent *, FILE *);
size_t _fwrite_r (struct _reent *, const void * , size_t _size, size_t _n, FILE *);
int _getc_r (struct _reent *, FILE *);
int _getc_unlocked_r (struct _reent *, FILE *);
int _getchar_r (struct _reent *);
int _getchar_unlocked_r (struct _reent *);
char * _gets_r (struct _reent *, char *);
int _iprintf_r (struct _reent *, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)))
                                                            ;
int _iscanf_r (struct _reent *, const char *, ...) __attribute__ ((__format__ (__scanf__, 2, 3)))
                                                           ;
FILE * _open_memstream_r (struct _reent *, char **, size_t *);
void _perror_r (struct _reent *, const char *);
int _printf_r (struct _reent *, const char *, ...) __attribute__ ((__format__ (__printf__, 2, 3)))
                                                            ;
int _putc_r (struct _reent *, int, FILE *);
int _putc_unlocked_r (struct _reent *, int, FILE *);
int _putchar_unlocked_r (struct _reent *, int);
int _putchar_r (struct _reent *, int);
int _puts_r (struct _reent *, const char *);
int _remove_r (struct _reent *, const char *);
int _rename_r (struct _reent *, const char *_old, const char *_new)
                                          ;
int _scanf_r (struct _reent *, const char *, ...) __attribute__ ((__format__ (__scanf__, 2, 3)))
                                                           ;
int _siprintf_r (struct _reent *, char *, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
                                                            ;
int _siscanf_r (struct _reent *, const char *, const char *, ...) __attribute__ ((__format__ (__scanf__, 3, 4)))
                                                           ;
int _sniprintf_r (struct _reent *, char *, size_t, const char *, ...) __attribute__ ((__format__ (__printf__, 4, 5)))
                                                            ;
int _snprintf_r (struct _reent *, char *, size_t, const char *, ...) __attribute__ ((__format__ (__printf__, 4, 5)))
                                                            ;
int _sprintf_r (struct _reent *, char *, const char *, ...) __attribute__ ((__format__ (__printf__, 3, 4)))
                                                            ;
int _sscanf_r (struct _reent *, const char *, const char *, ...) __attribute__ ((__format__ (__scanf__, 3, 4)))
                                                           ;
char * _tempnam_r (struct _reent *, const char *, const char *);
FILE * _tmpfile_r (struct _reent *);
char * _tmpnam_r (struct _reent *, char *);
int _ungetc_r (struct _reent *, int, FILE *);
int _vasiprintf_r (struct _reent *, char **, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
                                                            ;
char * _vasniprintf_r (struct _reent*, char *, size_t *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 4, 0)))
                                                            ;
char * _vasnprintf_r (struct _reent*, char *, size_t *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 4, 0)))
                                                            ;
int _vasprintf_r (struct _reent *, char **, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
                                                            ;
int _vdiprintf_r (struct _reent *, int, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
                                                            ;
int _vdprintf_r (struct _reent *, int, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
                                                            ;
int _vfiprintf_r (struct _reent *, FILE *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
                                                            ;
int _vfiscanf_r (struct _reent *, FILE *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 3, 0)))
                                                           ;
int _vfprintf_r (struct _reent *, FILE *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
                                                            ;
int _vfscanf_r (struct _reent *, FILE *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 3, 0)))
                                                           ;
int _viprintf_r (struct _reent *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)))
                                                            ;
int _viscanf_r (struct _reent *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 2, 0)))
                                                           ;
int _vprintf_r (struct _reent *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 2, 0)))
                                                            ;
int _vscanf_r (struct _reent *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 2, 0)))
                                                           ;
int _vsiprintf_r (struct _reent *, char *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
                                                            ;
int _vsiscanf_r (struct _reent *, const char *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 3, 0)))
                                                           ;
int _vsniprintf_r (struct _reent *, char *, size_t, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 4, 0)))
                                                            ;
int _vsnprintf_r (struct _reent *, char *, size_t, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 4, 0)))
                                                            ;
int _vsprintf_r (struct _reent *, char *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__printf__, 3, 0)))
                                                            ;
int _vsscanf_r (struct _reent *, const char *, const char *, __gnuc_va_list) __attribute__ ((__format__ (__scanf__, 3, 0)))
                                                           ;



int fpurge (FILE *);
ssize_t __getdelim (char **, size_t *, int, FILE *);
ssize_t __getline (char **, size_t *, FILE *);
# 515 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdio.h" 3 4
int __srget_r (struct _reent *, FILE *);
int __swbuf_r (struct _reent *, int, FILE *);
# 535 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdio.h" 3 4
FILE *funopen (const void * __cookie, int (*__readfn)(void * __cookie, char *__buf, int __n), int (*__writefn)(void * __cookie, const char *__buf, int __n), fpos_t (*__seekfn)(void * __cookie, fpos_t __off, int __whence), int (*__closefn)(void * __cookie))



                                   ;
FILE *_funopen_r (struct _reent *, const void * __cookie, int (*__readfn)(void * __cookie, char *__buf, int __n), int (*__writefn)(void * __cookie, const char *__buf, int __n), fpos_t (*__seekfn)(void * __cookie, fpos_t __off, int __whence), int (*__closefn)(void * __cookie))



                                   ;







typedef ssize_t cookie_read_function_t(void *__cookie, char *__buf, size_t __n);
typedef ssize_t cookie_write_function_t(void *__cookie, const char *__buf,
     size_t __n);




typedef int cookie_seek_function_t(void *__cookie, off_t *__off, int __whence);

typedef int cookie_close_function_t(void *__cookie);
typedef struct
{


  cookie_read_function_t *read;
  cookie_write_function_t *write;
  cookie_seek_function_t *seek;
  cookie_close_function_t *close;
} cookie_io_functions_t;
FILE *fopencookie (void *__cookie, const char *__mode, cookie_io_functions_t __functions)
                                                         ;
FILE *_fopencookie_r (struct _reent *, void *__cookie, const char *__mode, cookie_io_functions_t __functions)
                                                         ;
# 683 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdio.h" 3 4

# 3 "driver/driver.h" 2
# 21 "driver/driver.h"
void Delay(int nCount);
int getPressureVal();
void Set_Alarm_actuator(int i);
void GPIO_INITIALIZATION ();
# 5 "alarmmonitor.h" 2
# 1 "state.h" 1
# 10 "state.h"
# 1 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdlib.h" 1 3 4
# 10 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdlib.h" 3 4
# 1 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/machine/ieeefp.h" 1 3 4
# 11 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdlib.h" 2 3 4




# 1 "c:\\arm_toolchain\\bin\\../lib/gcc/arm-none-eabi/4.7.2/include/stddef.h" 1 3 4
# 16 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdlib.h" 2 3 4


# 1 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/machine/stdlib.h" 1 3 4
# 19 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdlib.h" 2 3 4

# 1 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/alloca.h" 1 3 4
# 21 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdlib.h" 2 3 4








typedef struct
{
  int quot;
  int rem;
} div_t;

typedef struct
{
  long quot;
  long rem;
} ldiv_t;


typedef struct
{
  long long int quot;
  long long int rem;
} lldiv_t;
# 58 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdlib.h" 3 4
int __locale_mb_cur_max (void);



void abort (void) __attribute__ ((noreturn));
int abs (int);
int atexit (void (*__func)(void));
double atof (const char *__nptr);

float atoff (const char *__nptr);

int atoi (const char *__nptr);
int _atoi_r (struct _reent *, const char *__nptr);
long atol (const char *__nptr);
long _atol_r (struct _reent *, const char *__nptr);
void * bsearch (const void * __key, const void * __base, size_t __nmemb, size_t __size, int (* _compar) (const void *, const void *))



                                                         ;
void * calloc (size_t __nmemb, size_t __size) ;
div_t div (int __numer, int __denom);
void exit (int __status) __attribute__ ((noreturn));
void free (void *) ;
char * getenv (const char *__string);
char * _getenv_r (struct _reent *, const char *__string);
char * _findenv (const char *, int *);
char * _findenv_r (struct _reent *, const char *, int *);

extern char *suboptarg;
int getsubopt (char **, char * const *, char **);

long labs (long);
ldiv_t ldiv (long __numer, long __denom);
void * malloc (size_t __size) ;
int mblen (const char *, size_t);
int _mblen_r (struct _reent *, const char *, size_t, _mbstate_t *);
int mbtowc (wchar_t *, const char *, size_t);
int _mbtowc_r (struct _reent *, wchar_t *, const char *, size_t, _mbstate_t *);
int wctomb (char *, wchar_t);
int _wctomb_r (struct _reent *, char *, wchar_t, _mbstate_t *);
size_t mbstowcs (wchar_t *, const char *, size_t);
size_t _mbstowcs_r (struct _reent *, wchar_t *, const char *, size_t, _mbstate_t *);
size_t wcstombs (char *, const wchar_t *, size_t);
size_t _wcstombs_r (struct _reent *, char *, const wchar_t *, size_t, _mbstate_t *);


char * mkdtemp (char *);
int mkostemp (char *, int);
int mkostemps (char *, int, int);
int mkstemp (char *);
int mkstemps (char *, int);
char * mktemp (char *) __attribute__ ((__warning__ ("the use of `mktemp' is dangerous; use `mkstemp' instead")));

char * _mkdtemp_r (struct _reent *, char *);
int _mkostemp_r (struct _reent *, char *, int);
int _mkostemps_r (struct _reent *, char *, int, int);
int _mkstemp_r (struct _reent *, char *);
int _mkstemps_r (struct _reent *, char *, int);
char * _mktemp_r (struct _reent *, char *) __attribute__ ((__warning__ ("the use of `mktemp' is dangerous; use `mkstemp' instead")));

void qsort (void * __base, size_t __nmemb, size_t __size, int(*_compar)(const void *, const void *));
int rand (void);
void * realloc (void * __r, size_t __size) ;

void * reallocf (void * __r, size_t __size);

void srand (unsigned __seed);
double strtod (const char *__n, char **__end_PTR);
double _strtod_r (struct _reent *,const char *__n, char **__end_PTR);
float strtof (const char *__n, char **__end_PTR);






long strtol (const char *__n, char **__end_PTR, int __base);
long _strtol_r (struct _reent *,const char *__n, char **__end_PTR, int __base);
unsigned long strtoul (const char *__n, char **__end_PTR, int __base);
unsigned long _strtoul_r (struct _reent *,const char *__n, char **__end_PTR, int __base);

int system (const char *__string);


long a64l (const char *__input);
char * l64a (long __input);
char * _l64a_r (struct _reent *,long __input);
int on_exit (void (*__func)(int, void *),void * __arg);
void _Exit (int __status) __attribute__ ((noreturn));
int putenv (char *__string);
int _putenv_r (struct _reent *, char *__string);
void * _reallocf_r (struct _reent *, void *, size_t);
int setenv (const char *__string, const char *__value, int __overwrite);
int _setenv_r (struct _reent *, const char *__string, const char *__value, int __overwrite);

char * gcvt (double,int,char *);
char * gcvtf (float,int,char *);
char * fcvt (double,int,int *,int *);
char * fcvtf (float,int,int *,int *);
char * ecvt (double,int,int *,int *);
char * ecvtbuf (double, int, int*, int*, char *);
char * fcvtbuf (double, int, int*, int*, char *);
char * ecvtf (float,int,int *,int *);
char * dtoa (double, int, int, int *, int*, char**);
int rand_r (unsigned *__seed);

double drand48 (void);
double _drand48_r (struct _reent *);
double erand48 (unsigned short [3]);
double _erand48_r (struct _reent *, unsigned short [3]);
long jrand48 (unsigned short [3]);
long _jrand48_r (struct _reent *, unsigned short [3]);
void lcong48 (unsigned short [7]);
void _lcong48_r (struct _reent *, unsigned short [7]);
long lrand48 (void);
long _lrand48_r (struct _reent *);
long mrand48 (void);
long _mrand48_r (struct _reent *);
long nrand48 (unsigned short [3]);
long _nrand48_r (struct _reent *, unsigned short [3]);
unsigned short *
       seed48 (unsigned short [3]);
unsigned short *
       _seed48_r (struct _reent *, unsigned short [3]);
void srand48 (long);
void _srand48_r (struct _reent *, long);
long long atoll (const char *__nptr);
long long _atoll_r (struct _reent *, const char *__nptr);
long long llabs (long long);
lldiv_t lldiv (long long __numer, long long __denom);
long long strtoll (const char *__n, char **__end_PTR, int __base);
long long _strtoll_r (struct _reent *, const char *__n, char **__end_PTR, int __base);
unsigned long long strtoull (const char *__n, char **__end_PTR, int __base);
unsigned long long _strtoull_r (struct _reent *, const char *__n, char **__end_PTR, int __base);


void cfree (void *);
int unsetenv (const char *__string);
int _unsetenv_r (struct _reent *, const char *__string);
# 206 "c:/arm_toolchain/lib/gcc/../../arm-none-eabi/sys-include/stdlib.h" 3 4
char * _dtoa_r (struct _reent *, double, int, int, int *, int*, char**);

void * _malloc_r (struct _reent *, size_t) ;
void * _calloc_r (struct _reent *, size_t, size_t) ;
void _free_r (struct _reent *, void *) ;
void * _realloc_r (struct _reent *, void *, size_t) ;
void _mstats_r (struct _reent *, char *);

int _system_r (struct _reent *, const char *);

void __eprintf (const char *, const char *, unsigned int, const char *);








# 11 "state.h" 2
# 6 "alarmmonitor.h" 2
void (*g_Alarm_Monitor_fun)();


typedef enum{

 OFF,ON
}ALARM_MONIROE_status;


void ST_OFF();
void ST_ON();

void Alarm_Monitor_Setup();
# 2 "alarmmonitor.c" 2
void (*g_Alarm_Monitor_fun)();
vusint32_t Alarm_START=0;
extern vusint32_t Alarm;
void ST_OFF(){
 Alarm_START=0;
if(Alarm){
 ALARM_MONIROE_status=ON;
 g_Alarm_Monitor_fun=ST_ON;
 }else{
 ALARM_MONIROE_status=OFF;
 g_Alarm_Monitor_fun=ST_OFF;
  }
}
void ST_ON(){
 Alarm_START=1;
  Delay(2000000);
  ALARM_MONIROE_status=OFF;
 g_Alarm_Monitor_fun=ST_OFF;
}

void Alarm_Monitor_Setup(){
 g_Alarm_Monitor_fun=ST_OFF;
}
