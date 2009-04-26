all: clean presentacion.pdf

pdf: presentacion.pdf

presentacion.pdf: presentacion.tex
	pdflatex presentacion.tex
	pdflatex presentacion.tex
	latex_count=5 ;
	while egrep -s 'Recompilando (LaTeX|para obtener las referencias correctamente)' presentacion.log && [ $$latex_count -gt 0 ] ;
	    do \
	      echo "Recompilando latex...." ;
	      pdflatex presentacion.tex ;
	      latex_count=`expr $$latex_count - 1` ;
	    done


clean: 
	rm -f *.ps *.dvi *.aux *.toc *.idx *.ind *.ilg *.log *.out *.snm *.nav *~ presentacion.pdf