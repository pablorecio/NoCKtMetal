NOM = acta
DOC = $(NOM).tex

PDF = pdflatex
LATEX = latex
DVI = dvipdf

pdf:
	$(PDF) $(DOC) && $(PDF) $(DOC)

latex: 
	$(LATEX) $(DOC) && $(LATEX) $(DOC)

dvi: 
	$(DVI) $(NOM).tex

clean: 
	$(RM) *.aux *.toc *.log *~ *\#

clean-all:
	$(RM) *.aux *.toc *.log *~ *\# $(NOM).pdf $(NOM).dvi
