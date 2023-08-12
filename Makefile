include Makefile.mk

NAME         := SmartCalc_v2.0
APP          := $(if $(filter Linux,$(OS)),$(NAME),$(NAME).app)

SRC_DIR      := src
BUILD_DIR    := build
LIB_DIR      := src/Model
DVI_DIR      := manual
DVI_FILE     := manual.texi

ifeq ($(OS), Linux)
RUN          := ./$(BUILD_DIR)/$(APP)
else
RUN          := open $(BUILD_DIR)/$(APP)
endif

MAKEDVI      := makeinfo --html
BUILDER      := qmake

all: install run

install:
	mkdir $(BUILD_DIR) && cd $(BUILD_DIR)
	$(BUILDER) .. && $(MAKE)

uninstall:
	$(RM) $(BUILD_DIR)

run:
	$(RUN)

dvi:
	$(MAKEDVI) $(DVI_FILE)
	$(OPEN) $(DVI_DIR)/index.html

dist:
	mkdir ../$(NAME)
	$(CP) * ../$(NAME)
	mv ../$(NAME) .
	$(TAR) $(NAME).tgz $(NAME)
	mv $(NAME).tgz $(HOME)/Desktop

check-style:
	find $(SRC_DIR) -name '*.cc' -o -name '*.h' | xargs clang-format -style=google -n

test:
	mkdir $(LIB_DIR)/$(BUILD_DIR) && cd $(LIB_DIR)/$(BUILD_DIR)
	$(BUILDER) .. && $(MAKE)

gcov_report:
	mkdir $(LIB_DIR)/$(BUILD_DIR) && cd $(LIB_DIR)/$(BUILD_DIR)
	$(BUILDER) .. && $(MAKE) $@

clean: uninstall
	$(RM) $(NAME)
	$(RM) $(LIB_DIR)/$(BUILD_DIR)

fclean: clean

	$(MAKE) -C $(LIB_DIR) -f Makefile $@
