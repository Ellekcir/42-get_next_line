#include "get_next_line.h"

// This will update the STATIC variable 'remaining'.
// That's what is left of the .txt file that needs to be read.
// It creates a buffer of the correct size to read one line at a time only.
// the 'chars_read' will be how many characters (bytes) it will read from the remaining text in the file.
// This will be at a max size of the the input of the BUFFER_SIZE or defaulted at 42.
// If the chars_read returns a -1 (error reading) it will return NULL.
// 
// Otherwise the chars_read will return a max of the BUFFER_SIZE
// & then set the buffer[chars_read] = '\0' to end the line that will be returned.
// no need to chars_read++ as buffer index starts at 0 and will now be at the end of the 'line'.
// Assign the remaining to the temp variable so we can modify the variable 'remaining' in the meantime.
// This is done by making the 'new_remaining' == the remaining to the read characters from the buffer 
// free temp variable ready to be used for the next call
// returning the new remaining line.
static char	*read_line(int fd, char *remaining)
{
	char	buffer[BUFFER_SIZE + 1];
	int	chars_read;
	char	*new_remaining;
	char	*temp;
	
	chars_read = read(fd, buffer, BUFFER_SIZE);
	if (chars_read == -1)
		return (NULL);
	buffer[chars_read] = '\0';
	temp = remaining;
	new_remaining = ft_strjoin(remaining, buffer);
	free(temp);
	return (new_remaining);
}

// This will update the STATIC variable 'remaining'.
// and takes a double pointer to where the newline should start - **newline_pointer
// Sets an index for the newline to 0, takes the static remaining,
// checks that the index ins't a NULL or new line and moves up the chars in remaining text
// after incrementing one more it is checked if a newline is found,
// if so it will make the newline_pointer point to the current index of the remaining which is a '\n'
// Otherwise it will set it to NULL. 
// If it is a '\n' the lines' length will = the newline index,
// otherwise it will return the line length as the string length of 'remaining'
// which is technically the max sizeof the buffer in the read_line function - BUFFER_SIZE;
// it will increment once more to account for the NULL terminator.
// Memory is allocated for the next line at the line length named 'line'. 
// Error handling to check it allocated memory successfully. 
// The characters from remaining are then copied to the line one character at a time.
// concluding with '\0' to finish and return of 'line'. 


static char	*extract_line(char *remaining, char **newline_pointer)
{
	char	*line;
	size_t	*newline_pointer;
	int	newline_index;
	
	newline_index = 0;
	while (remaining[newline_index] != '\n' && remaining[newline_index] != '\0')
		newline_index++;
	if (remaining[newline_index] == '\n')
		*newline_pointer = &remaining[newline_index];
	else
		*newline_pointer = NULL;
	if (remaining[newline_index] == '\n')
		line_length = newline_index;
	else
		line_length = ft_strlen(remaining);
	line_length++;
	line = (char *)malloc(line_length * sizeof(char));
	if (!line)
		return (NULL);
	newline_index = 0;
	while (remaining[newline_index] != '\0' && remaining[newline_index] != '\n')
	{
		line[newline_index] = remaining[newline_index];
		newline_index++;
	}
	line[newline_index] = '\0';
	return (line);
}

// This is our main function that will run to get the next line
// It will return the next line by taking in the file descriptor
// This file descriptor ex: fd = open(argv[1], O_RDONLY);
// will take a file and check it exists/is open and able to 'read'
// It checks that there is a designated BUFFER_SIZE 
// (this will be the size of bytes that will be read at a time i.e per line)
// remaining = the read line from the file
// checks it read successfully
// Assigns variable 'line' which is essentiallt taking the line from the remaining text,
// starting from the start of the new line
// if the new line pointer isn't '\0' it will minus from the *remaining equal 
// (+ 1 for the NULL terminator)
// and give remaining the new value of only what hasn't been already taken
// otherwise conclude with a '\0' to indicate the line is finished.
// fianlly, returning the line back to the user


char	*get_next_line(int fd)
{
	static char	*remaining; // remaining text (lines) to be read
	char		*line; // the line that is to be returned '1 at a time' - the next line
	char		*newline_pointer; // this is the pointer to where each new line will point to before being returned
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
      // error handling - checks that there is no error reading (-1) the fd input & the checks it has a valid BUF size
	remaining = read_line(fd, remaining);
      // the remaining text of the .txt file to be read
	if (!remaining)
		return (NULL);
	line = extract_line(remaining, &newline_pointer);
	if (newline_pointer != NULL)
		remaining += (newline_pointer - remaining) + 1;
	else
		*remaining = '\0';
	return (line);
}
