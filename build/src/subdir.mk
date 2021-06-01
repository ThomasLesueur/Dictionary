OBJECTS += ./src/binary_tree.o \
./src/dic.o \
./src/main.o \
./src/menu.o 

CC_DEPS += ./src/deps/binary_tree.d \
./src/deps/dic.d \
./src/deps/main.d \
./src/deps/menu.d 

./src/%.o: ../src/%.c
	@echo 'Building file: $<'
	$(CC) -c -Wall $< -o $@
	@echo 'Build finished: $<'
	@echo

./src/%.o: ../src/%.cc
	@echo 'Building file: $<'
	$(CC) -c -Wall $< -o $@
	@echo 'Build finished: $<'
	@echo

./src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	$(CC) -c -Wall $< -o $@
	@echo 'Build finished: $<'
	@echo

