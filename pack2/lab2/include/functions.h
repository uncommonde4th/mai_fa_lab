#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>

#if defined(__APPLE__) && defined(__MACH__)
    #define OS_MACOS 1
    #define OS_LINUX 0
#elif defined(__linux__)
    #define OS_MACOS 0
    #define OS_LINUX 1
#else
    #define OS_MACOS 0
    #define OS_LINUX 0
#endif

#define EPERM           1
#define ENOENT          2
#define ESRCH           3
#define EINTR           4
#define EIO             5
#define ENXIO           6
#define E2BIG           7
#define ENOEXEC         8
#define EBADF           9
#define ECHILD          10
#define EAGAIN          11
#define ENOMEM          12
#define EACCES          13
#define EFAULT          14
#define ENOTBLK         15
#define EBUSY           16
#define EEXIST          17
#define EXDEV           18
#define ENODEV          19
#define ENOTDIR         20
#define EISDIR          21
#define EINVAL          22
#define ENFILE          23
#define EMFILE          24
#define ENOTTY          25
#define ETXTBSY         26
#define EFBIG           27
#define ENOSPC          28
#define ESPIPE          29
#define EROFS           30
#define EMLINK          31
#define EPIPE           32
#define EDOM            33
#define ERANGE          34

#if OS_MACOS
    #define ERROR_MESSAGES { \
        [0] = "Success", \
        [EPERM] = "Operation not permitted", \
        [ENOENT] = "No such file or directory", \
        [ESRCH] = "No such process", \
        [EINTR] = "Interrupted system call", \
        [EIO] = "Input/output error", \
        [ENXIO] = "Device not configured", \
        [E2BIG] = "Argument list too long", \
        [ENOEXEC] = "Exec format error", \
        [EBADF] = "Bad file descriptor", \
        [ECHILD] = "No child processes", \
        [EAGAIN] = "Resource temporarily unavailable", \
        [ENOMEM] = "Cannot allocate memory", \
        [EACCES] = "Permission denied", \
        [EFAULT] = "Bad address", \
        [ENOTBLK] = "Block device required", \
        [EBUSY] = "Device or resource busy", \
        [EEXIST] = "File exists", \
        [EXDEV] = "Cross-device link", \
        [ENODEV] = "Operation not supported by device", \
        [ENOTDIR] = "Not a directory", \
        [EISDIR] = "Is a directory", \
        [EINVAL] = "Invalid argument", \
        [ENFILE] = "Too many open files in system", \
        [EMFILE] = "Too many open files", \
        [ENOTTY] = "Inappropriate ioctl for device", \
        [ETXTBSY] = "Text file busy", \
        [EFBIG] = "File too large", \
        [ENOSPC] = "No space left on device", \
        [ESPIPE] = "Illegal seek", \
        [EROFS] = "Read-only file system", \
        [EMLINK] = "Too many links", \
        [EPIPE] = "Broken pipe", \
        [EDOM] = "Numerical argument out of domain", \
        [ERANGE] = "Result too large" \
    }
#elif OS_LINUX
    #define ERROR_MESSAGES { \
        [0] = "Success", \
        [EPERM] = "Operation not permitted", \
        [ENOENT] = "No such file or directory", \
        [ESRCH] = "No such process", \
        [EINTR] = "Interrupted system call", \
        [EIO] = "Input/output error", \
        [ENXIO] = "No such device or address", \
        [E2BIG] = "Argument list too long", \
        [ENOEXEC] = "Exec format error", \
        [EBADF] = "Bad file descriptor", \
        [ECHILD] = "No child processes", \
        [EAGAIN] = "Resource temporarily unavailable", \
        [ENOMEM] = "Cannot allocate memory", \
        [EACCES] = "Permission denied", \
        [EFAULT] = "Bad address", \
        [ENOTBLK] = "Block device required", \
        [EBUSY] = "Device or resource busy", \
        [EEXIST] = "File exists", \
        [EXDEV] = "Invalid cross-device link", \
        [ENODEV] = "No such device", \
        [ENOTDIR] = "Not a directory", \
        [EISDIR] = "Is a directory", \
        [EINVAL] = "Invalid argument", \
        [ENFILE] = "Too many open files in system", \
        [EMFILE] = "Too many open files", \
        [ENOTTY] = "Inappropriate ioctl for device", \
        [ETXTBSY] = "Text file busy", \
        [EFBIG] = "File too large", \
        [ENOSPC] = "No space left on device", \
        [ESPIPE] = "Illegal seek", \
        [EROFS] = "Read-only file system", \
        [EMLINK] = "Too many links", \
        [EPIPE] = "Broken pipe", \
        [EDOM] = "Numerical argument out of domain", \
        [ERANGE] = "Numerical result out of range" \
    }
#else
    #define ERROR_MESSAGES { \
        [0] = "Success", \
        [EPERM] = "Operation not permitted", \
        [ENOENT] = "No such file or directory" \
    }
#endif

#define ERROR_COUNT 35


void *memchr(const void *str, int c, size_t n);
int memcmp(const void *str1, const void *str2, size_t n);
void *memcpy(void *dest, const void *src, size_t n);
void *memset(void *str, int c, size_t n);
char *strncat(char *dest, const char *src, size_t n);
char *strchr(const char *str, int c);
int strncmp(const char *str1, const char *str2, size_t n);
char *strncpy(char *dest, const char *src, size_t n);
size_t strcspn(const char *str1, const char *str2);
char *strerror(int errnum);
size_t strlen(const char *str);
char *strpbrk(const char *str1, const char *str2);
char *strrchr(const char *str, int c);
char *strstr(const char *haystack, const char *needle);
char *strtok(char *str, const char *delim);

#endif

