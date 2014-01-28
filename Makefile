
bin_stack       = test_stack
bin_queue       = test_queue
bin_vector 		= test_vector
bin_pair 		= test_pair
bin_map 		= test_map
bin_list 		= test_forward_list
bin_path		= bin
csml_path 		= -I includes/
rm 				= rm -rf
cflags 			= -Wall -ansi #-W

all:
	mkdir -p $(bin_path)
	$(CC) $(cflags) $(csml_path) tests/test_stack.c -o $(bin_path)/$(bin_stack)
	$(CC) $(cflags) $(csml_path) tests/test_queue.c -o $(bin_path)/$(bin_queue)    
	$(CC) $(cflags) $(csml_path) tests/test_vector.c -o $(bin_path)/$(bin_vector)    
	$(CC) $(cflags) $(csml_path) tests/test_pair.c -o $(bin_path)/$(bin_pair)    
	$(CC) $(cflags) $(csml_path) tests/test_map.c -o $(bin_path)/$(bin_map)    
	$(CC) $(cflags) $(csml_path) tests/test_forward_list.c -o $(bin_path)/$(bin_list)    

clean:
	$(rm) $(bin_path)