
bin_stack       = test_stack
bin_queue       = test_queue
bin_path		= bin
csml_path 		= -I includes/
rm 				= rm -rf

all:
	mkdir -p $(bin_path)
	$(CC) $(csml_path) tests/test_stack.c -o $(bin_path)/$(bin_stack)
	$(CC) $(csml_path) tests/test_queue.c -o $(bin_path)/$(bin_queue)    

clean:
	$(rm) $(bin_path)