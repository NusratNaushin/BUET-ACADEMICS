#ifndef _STAT_H
#define _STAT_H

#include "types.h"
#define T_DIR     1   // Directory
#define T_FILE    2   // File
#define T_DEVICE  3   // Device

struct stat {
  int dev;     // File system's disk device
  uint ino;    // Inode number
  short type;  // Type of file
  short nlink; // Number of links to file
  uint64 size; // Size of file in bytes
};
struct syscall_stat
{
    char syscall_name[16];
    int count;
    int accum_time;
};

extern struct syscall_stat syscall_stats[];

#endif