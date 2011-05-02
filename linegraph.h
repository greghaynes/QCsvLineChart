#ifndef LINE_GRAPH_H
#define LINE_GRAPH_H

#include <qwt_plot.h>
#include <qwt_text.h>

#include <QIODevice>

class LineGraph
	: public QwtPlot
{

	public:
		static LineGraph *fromCsv(QIODevice &device);

		LineGraph(QWidget *parent = 0);
		LineGraph(const QwtText &title, QWidget *parent = 0);

};

#endif

