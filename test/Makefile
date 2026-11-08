OUT ?= out
C2ROB ?= ../c2rob
ROBCMP ?= robcmp
ARCH ?= stm32f1
DUMP ?= llvm-objdump-21

# Select input basenames explicitly. Other sources still take the direct path.
PREPROCESS_FILES ?= dummy.c
CFILES := $(wildcard cfiles/*.c)
ROBFILES := $(patsubst cfiles/%.c,$(OUT)/%.rob,$(CFILES))
OBJECTS := $(ROBFILES:.rob=.o)
SFILES := $(patsubst cfiles/%.c,$(OUT)/%.s,$(CFILES))

.SUFFIXES:
.PHONY: all count clean

all : $(OUT) $(SFILES)

count:
	@echo "Assembly files in $(OUT): $(words $(wildcard $(OUT)/*.s))"

$(OUT) :
	mkdir -p "$@"

# Keep translation and object files on success; delete failed outputs.
.SECONDARY: $(ROBFILES) $(OBJECTS)
.DELETE_ON_ERROR:
$(OUT)/%.rob : cfiles/%.c $(C2ROB) | $(OUT)
	"$(C2ROB)" $(if $(filter $(notdir $<),$(PREPROCESS_FILES)),--preprocess) "$<" > "$@"

$(OUT)/%.o : $(OUT)/%.rob
	"$(ROBCMP)" -I .. -bdep -a "$(ARCH)" "$<" -o "$@"

$(OUT)/%.s : $(OUT)/%.o
	"$(DUMP)" -D "$<" > "$@"

clean:
	rm -f "$(OUT)"/*.rob "$(OUT)"/*.o "$(OUT)"/*.s
