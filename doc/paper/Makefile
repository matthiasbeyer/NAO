#
# Makefile
#
# This makefile helps you building the document and testing the sources.
#




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
## Files
##


#
# The PDF file we want
#
PDF_FILE=main.pdf

#
# The latex source file
#
LATEX_MAIN_SOURCE=main.tex

#
# All latex sources
#
LATEX_SUB_SOURCES:=$(shell find src -iname '*.tex')

#
# The main.aux file
#
AUX_FILE=main.aux

#
# Bibtex sources
#
BIBTEX_SOURCE=bibtex.bib

#
# Bibliography file
#
BBL_FILE=main.bbl

#
# .ist file
#
IST_FILE=main.ist

#
# Glossary file
#
GLO_FILE=main.glo

#
# Sorted/processed glossaries file
#
GLS_FILE=main.gls

#
# The glossary source
#
GLOSSARY_SOURCE=./main

#
# Destination of the log from the make files
#
MAKELOG=make.log
export MAKELOG




##
## Directories
##


#
# The directory where scripts are located
#
SCRIPTS=scripts
export SCRIPTS

#
# The directory where are the generator scripts
#
GEN_DIR=gen
export GEN_DIR




##
## Misc vars
##


# Avoid strange shell setups, as proposed by the GNU coding standards
SHELL = /bin/sh

#
# removeable latex temporary files
#
LATEX_TMPFILES_FLAT=log nav out snm toc vrb bbl blg idx lof lot glg glo gls ist glsdefs
LATEX_TMPFILES_RECURSIVE=aux



##
## High level tasks
##


#
# The standard task, compiling the latex source to a
# pdf document.
#
# We compile the sources three times, to be sure everything compiled correctly
#
all: $(PDF_FILE)

#
# Testing task. Not meant to produce a pdf but to check for flaws in the source
# files
#
test one_time: $(AUX_FILE) $(BBL_FILE) $(GLS_FILE)




gen_tex:
	@$(ECHO) "\t[MAKE] $(GEN_DIR)"
	@$(MAKE) $(MAKE_FLAGS) -C $(GEN_DIR)




##
## Generation tasks
##


#
# Generate main.aux from TeX sources
#
$(AUX_FILE): $(LATEX_MAIN_SOURCE) $(LATEX_SUB_SOURCES) gen_tex
	@$(ECHO) "\t[LATEX]"
	@$(LATEX) $(LATEX_FLAGS) -draftmode $< >> $(MAKELOG)


#
# "Generate" .ist and .glo file simply by depending on the auxilary file
#
$(IST_FILE) $(GLO_FILE): $(AUX_FILE)


#
# Generate bibliography
#
$(BBL_FILE): $(AUX_FILE) $(BIBTEX_SOURCE)
	@$(ECHO) "\t[BIBTEXC]"
	@$(BIBTEXC) $< >> $(MAKELOG)


#
# Generate glossaries
#
$(GLS_FILE): $(GLO_FILE) $(IST_FILE)
	@$(ECHO) "\t[GLOSSARY]"
	@$(GLOSSARY) $(basename $(LATEX_MAIN_SOURCE)) >> $(MAKELOG)

#
# Generate the PDF TODO: use stamp file and [[ -nt ]] or [[ -ot ]] (maybe in script)
#
$(PDF_FILE): $(AUX_FILE) $(BBL_FILE) $(GLS_FILE)
	@$(ECHO) "\t[LATEX]"
	@$(LATEX) $(LATEX_FLAGS) $(LATEX_MAIN_SOURCE) >> $(MAKELOG)

	@$(ECHO) "\t[LATEX]"
	@$(LATEX) $(LATEX_FLAGS) $(LATEX_MAIN_SOURCE) >> $(MAKELOG)




##
## Clean tasks
##


#
# Clean everything
#
clean: nearly_clean
	@$(ECHO) "\t[RM] *.pdf"
	@$(RM) "*.pdf"

#
# Remove everything except the target pdf file
#
nearly_clean: clean_gen
	@for tmp in $(LATEX_TMPFILES_FLAT);do		\
		$(ECHO) "\t[RM]\t*.$$tmp";				\
		$(RM) *.$$tmp;							\
	done
	@for tmp in $(LATEX_TMPFILES_RECURSIVE);do	\
		$(ECHO) "\t[RM]\t*.$$tmp";				\
		$(RM) $$(find -name *.$$tmp -type f);	\
	done
	@$(ECHO) "\t[RM]\t$(MAKELOG)"
	@$(RM) $(MAKELOG)

#
# Clean gen
#
clean_gen:
	@$(ECHO) "\t[MAKE]\t$(GEN_DIR) clean"
	@$(MAKE) $(MAKE_FLAGS) -C $(GEN_DIR) clean


