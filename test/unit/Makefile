PYTHON ?= python3
C2ROB ?= ../../c2rob
CC ?= cc
ROBCMP ?=
LLVM_OPT ?= opt
ARCH ?= stm32f1
OUT ?= out

.PHONY: all test integration clean
all: test

test:
	$(PYTHON) run_tests.py --c2rob "$(C2ROB)" --out "$(OUT)"

# Separate from translation: compile ARM objects, verify IR, and compare host results.
integration:
	$(PYTHON) run_tests.py --c2rob "$(C2ROB)" --out "$(OUT)" --robcmp "$(ROBCMP)" --opt "$(LLVM_OPT)" --cc "$(CC)" --arch "$(ARCH)"

clean:
	rm -rf "$(OUT)"
