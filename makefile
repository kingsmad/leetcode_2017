CC = g++
CFLAGS = -std=c++11 -D ROACH_ONLINE_JUDGE
source_cpp = $(shell ls | grep $(MAKECMDGOALS))

%:
	@echo "compiling $(source_cpp)..."
	$(CC) $(CFLAGS) -o test $(source_cpp) $(LDFLAGS)
