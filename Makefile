
bin_stack 		= test_stack
bin_path		= bin
csml_path 		= -I includes/
RM 				= rm -rf

all:
	mkdir -p $(bin_path)
	$(CC) $(csml_path) tests/test_stack.c -o $(bin_path)/$(bin_stack)

clean:
	$(RM) $(bin_path)