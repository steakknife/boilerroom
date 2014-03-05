#ifndef __WAIT_H__
#define __WAIT_H__

# ifdef __cplusplus
extern "C" {
# endif

int wait_pid(int *wstat, int pid);
int wait_nohang(int *wstat);

# define wait_crashed(w) ((w) & 127)
# define wait_exitcode(w) ((w) >> 8)
# define wait_stopsig(w) ((w) >> 8)
# define wait_stopped(w) (((w) & 127) == 127)

# ifdef __cplusplus
}
# endif

#endif /* __WAIT_H__ */

