#include <dietstdio.h>
#include <unistd.h>

#ifndef __NO_STAT64
off64_t fseeko64(FILE *stream, off64_t offset, int whence) {
  fflush(stream);
#ifdef WANT_BUFFERED_STDIO
  stream->bm=0; stream->bs=0;
#endif
  stream->flags&=~(ERRORINDICATOR|EOFINDICATOR);
  return (lseek64(stream->fd,offset,whence));
}
#endif