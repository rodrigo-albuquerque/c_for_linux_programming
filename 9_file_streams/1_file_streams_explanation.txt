#### Opening a File ####
Open files in standard C library are referred to as file streams and have the type:

FILE * streams;

We open a file using fopen() which has the following prototype:

FILE * fopen(const char *path, const char *mode);

First argument path is a string storing file system path of the file to open, and mode describes the permission/purpose of the file.
For example:

FILE * stream = fopen("gonavy.txt", "w");

The above command will open a file in current directory called "gonavy.txt" with write mode.

Just like pointers, file streams are dynamically allocated and must be deallocated or closed.
Here's how we close a file stream using fclose():

fclose( stream );

### File Modes ###
Modes = reading/writing/appending.

Options:
r      Open text file for reading.  The stream is positioned at the beginning of the file.

r+     Open for reading and writing.  The stream is positioned at the beginning of the file.

w      Truncate  file  to zero length or create text file for writing.  The stream is positioned at the
       beginning of the file.

w+     Open for reading and writing.  The file is created if it does not exist, otherwise it  is  trun‐
       cated.  The stream is positioned at the beginning of the file.

a      Open  for  appending  (writing  at end of file).  The file is created if it does not exist.  The
       stream is positioned at the end of the file.

a+     Open for reading and appending (writing at end of file).  The file is created  if  it  does  not
       exist.   The  initial  file  position for reading is at the beginning of the file, but output is
       always appended to the end of the file.

Any mode with "+" sign is for both reading and writing but the following behaviour applies:
r+ never truncates file if it exists, i.e. it deletes its content. It doesn't create the file if it doesn't exist.
w+ always truncate file if it exists or creates one if it doesn't.
"a" mode doesn't truncate file if it exists and all writes occur at the end of the file.

### File Errors ###
Upon successful completion fopen(), fdopen() and freopen() return a FILE pointer.
Otherwise, NULL is returned and errno is set to indicate the error.

So we can check for NULL for errors, for example:

if ( ( stream = fopen("DOESNOTEXIST.txt, "r") ) == NULL) {
  fprintf("ERROR ... \n");
}

Keep in mind that an error can also occur because of insufficient permissions.
E.g. opening a file without reading permission or trying to write a file without writing permission.
Additionally, read/write from a file with the wrong mode can also be the cause of errors.
