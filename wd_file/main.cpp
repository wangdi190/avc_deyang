#include <qapplication.h>
#include "Mainform.h"


#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define LOCKFILE "/users/ems/wd_file/SingleApplication"
#define LOCKMODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

int lockfile(int fd)
{
    struct flock fl;
    fl.l_type = F_WRLCK;
    fl.l_start = 0;
    fl.l_whence = SEEK_SET;
    fl.l_len = 0;
    return (fcntl(fd,F_SETLK,&fl));
}

int alread_running(char * filename)
{
    char buf[16]={0};
    int fd = open(filename, O_RDWR|O_CREAT, LOCKMODE);
    if(fd<0)
    {
       printf("cannot open %s\n", filename);
       return -1;
   }
    
    if(lockfile(fd) == -1)
    {
	if(errno==EACCES || errno==EAGAIN)
	{
	    printf("file %s already locked\n", filename);
	    close(fd);
	    return -1;
	}
	printf("cannot lock %s\n", filename);
	return -1;
    }
    ftruncate(fd, 0);
    sprintf(buf, "%ld", (long)getpid());
    write(fd, buf, strlen(buf)+1);
    return 0;
}

int main( int argc, char ** argv )
{
    if(alread_running(LOCKFILE) == -1)
    {
	//printf("okokokok\n");
	return 0;
    }

    QApplication a( argc, argv );
    MainForm w;
    w.show();
    //a.connect( &a, SIGNAL( lastWindowClosed() ), &a, SLOT( quit() ) );
    return a.exec();
}
