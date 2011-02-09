NOM = manual
DOC = $(NOM).tex

PDF = pdflatex
LATEX = latex
DVI = dvipdf


# No tendremos en cuenta las referencias bibliográficas. Seguramente de error
pdf:
	$(PDF) $(DOC) && $(PDF) $(DOC)

latex-bib: 
	$(LATEX) $(DOC) && $(BIB) $(NOM) | make latex

latex: 
	$(LATEX) $(DOC) && $(LATEX) $(DOC)

# Pasa de .dvi a .pdf
dvi-pdf: 
	$(DVI) $(NOM).tex

clean: 
	$(RM) *.aux *.toc *.log \
	*.lof *.lot *.out *.bbl \
	*.blg *~ *\#
	$(RM) -r auto

clean-all:
	make clean
	$(RM) $(NOM).pdf $(NOM).dvi
