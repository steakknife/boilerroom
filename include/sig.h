#ifndef __SIG_H__
#define __SIG_H__

# ifdef __cplusplus
extern "C" {
# endif

const int sig_alarm;
const int sig_child;
const int sig_cont;
const int sig_hangup;
const int sig_int;
const int sig_pipe;
const int sig_term;

void (*sig_defaulthandler)();
void (*sig_ignorehandler)();

void sig_catch(int sig, void (*handler)());
#define sig_ignore(s) (sig_catch((s), sig_ignorehandler))
#define sig_uncatch(s) (sig_catch((s), sig_defaulthandler))

void sig_block(int sig);
void sig_unblock(int sig);
void sig_blocknone(void);
void sig_pause(void);
void sig_dfl(int sig);

# ifdef __cplusplus
}
# endif

#endif /* __SIG_H__ */
