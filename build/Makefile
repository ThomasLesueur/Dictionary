CC :=gcc
LD :=gcc
TARGET :=Dictio
OUT :=./Dictio
LIBS :=
CC_DEPS :=
OBJECTS :=
RM :=rm -v

all: $(OUT)

-include ./src/subdir.mk
-include $(CC_DEPS)

$(OUT): $(OBJECTS)
	@echo Building target: "$@".
	@echo Invoking $(LD) Linker ...
	$(LD) $(OBJECTS) $(LIBS)  -o $(OUT)
	@echo Target $(TARGET) build successfully.
	@echo Done.

clean:
	$(RM) $(OBJECTS) ./Dictio

