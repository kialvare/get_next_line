#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
#endif

In the main function, open the file to return a file descriptor(fd), that file descriptor is then sent to get_next_line to start
the gnl function

In the gnl function, now you read the file with the file descriptor that you get from opening it(how to handle multiple file descriptors?)
	In that function, read up until the size of buffer
		Searching for newline: strchr vs strstr?
		When you find the newline
			Check if there are any extra towards the end
		// How to store any extra buffers?
	// Store entire file in static variable to make it easier to go through?
		Malloc the size of the file thats inputed (the buf?)
		static char *file; <-