#if 0 //these lines are not compiled
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#endif
// some constants, I need to know what are they used to ?!!
#define IMA_YONDERU 'x'  /* iranai */
#define IMA_KAITERU  0   /* iranai */
#define KAKIOWATTA  'w'
#define YOMIOWATTA  'r'
#define OSHIMAI     'd'
#define ISRUNNING    0
#define SEMAPHORE    1
#define STATUS       2

#define IPC_ALLOC 0100000
