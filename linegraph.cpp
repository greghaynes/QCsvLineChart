#include "linegraph.h"
#include "csvreader.h"

LineGraph *LineGraph::fromCsv(QIODevice &device)
{
	CsvReader cr;
	cr.setDevice(device);
	QList<QList<QString> > lineargs = cr.parseToEnd();

	QList<QString> line;
	QString arg;

	// Run sanity check on csv
	int len = lineargs[0].length();
	Q_FOREACH(line, lineargs) {
		if(len != line.length())
			return 0;
	}

	Q_FOREACH(line, lineargs) {
	}

	LineGraph *lg = new LineGraph();
}

LineGraph::LineGraph(QWidget *parent)
	: QwtPlot(parent)
{
}

LineGraph::LineGraph(const QwtText &title, QWidget *parent)
	: QwtPlot(title, parent)
{
}

