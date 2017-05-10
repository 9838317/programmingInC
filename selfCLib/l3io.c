#include <l1head.h>
#define RIO_BUFSIZE 8192

typedef struct 
{
    int rio_fd;
    int rio_cnt;
    char *rio_bufptr;
    char rio_buf[RIO_BUFSIZE];
} rio_t;


// This is to get bytes from a fd.
ssize_t rio_readn(int fd, void *usrbuf, size_t n) 
{
    size_t nleft = n;
    ssize_t nread;
    char *bufp = usrbuf;

    while (nleft > 0) {
    	if ((nread = read(fd, bufp, nleft)) < 0) {
    	    if (errno == EINTR) /* interrupted by sig handler return */
    		    nread = 0;      /* and call read() again */
    	    else
    		    return -1;      /* errno set by read() */ 
    	} 
    	else if (nread == 0)
    	    break;              /* EOF */
    	nleft -= nread;
    	bufp += nread;
    }
    return (n - nleft);         /* return >= 0 */
} 

// This is to write bytes to fd.
ssize_t rio_writen(int fd, void *usrbuf, size_t n) 
{
    size_t nleft = n;
    ssize_t nwritten;
    char *bufp = usrbuf;

    while (nleft > 0) {
	if ((nwritten = write(fd, bufp, nleft)) <= 0) {
	    if (errno == EINTR)  /* interrupted by sig handler return */
		nwritten = 0;    /* and call write() again */
	    else
		return -1;       /* errno set by write() */
	}
	nleft -= nwritten;
	bufp += nwritten;
    }
    return n;
}
