#include <time.h>
#include <unistd.h>
#include <errno.h>

/*
struct timespec {
    time_t tv_sec;        // seconds
    long   tv_nsec;       // nanoseconds
};
*/

unsigned int sleep(unsigned int seconds)
{
    struct timespec req = {
        .tv_sec = seconds,
        .tv_nsec = 0
    };

    if (nanosleep(&req, NULL) == -1) {
        if (errno == EINTR) {
            return -1;
        }
    }

    return 0;
}
