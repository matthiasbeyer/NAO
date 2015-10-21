##
## Commands
##

#
# The latex compiler
#
LATEX=$(shell which pdflatex)
export LATEX

#
# The bibtex compiler
#
BIBTEXC=$(shell which bibtex)
export BIBTEXC

#
# The glossary compiler
#
GLOSSARY=$(shell which makeglossaries)
export GLOSSARY

#
# Destination of the log from the make files
#
MAKELOG=make.log
export MAKELOG

#
# The output command
#
ECHO_CMD=$(shell which echo)

#
# The command to remove something
#
RM_CMD=$(shell which rm)

##
## Flags
##

#
# Flags for subdirectories
#
MAKE_FLAGS=--no-print-directory
export MAKE_FLAGS

#
# Flags for the latex compilre
#
LATEX_FLAGS=-halt-on-error
export LATEX_FLAGS

#
# Output flags
#
ECHO_FLAGS=-e
export ECHO_FLAGS

#
# The remove flags
#
RM_FLAGS=-f


##
## Standard commands
##

#
# The command for printing something
#
ECHO=$(ECHO_CMD) $(ECHO_FLAGS)
export ECHO

RM=$(RM_CMD) $(RM_FLAGS)
export RM



##
## Tasks
##

all:
	@for dir in $(shell find -mindepth 1 -type d);do 	\
		$(ECHO) "\t[MAKE]\t$$dir";						\
		$(MAKE) -C $$dir $(MAKE_FLAGS);					\
	done

.PHONY: all

