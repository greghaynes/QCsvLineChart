#include "linegraph.h"
#include "csvreader.h"

#include <qwt_plot_curve.h>
#include <qwt_legend.h>

#include <QDebug>
#include <QVector>
#include <QPointF>

#define line_color_cnt 4
static QColor line_colors[] = { Qt::red, Qt::magenta, Qt::darkGreen, Qt::cyan };

LineGraph *LineGraph::fromCsv(QIODevice &device)
{
	int i;
	CsvReader cr;
	cr.setDevice(device);
	QList<QList<QString> > lines = cr.parseToEnd();

	QList<QString> args;
	QString arg;

	// Run sanity check on csv
	int len = lines[0].length();
	Q_FOREACH(args, lines) {
		if(len != args.length())
		{
			qDebug() << "Invalid CSV, line: " << args;
			return 0;
		}
	}

	// Reorder CSV into dict of plot : values
	QHash<QString, QVector<qreal> > plots;
	QList<QString> x_vals;
	QList<QString> args_2;
	QList<QString> arg_2;
	i = 0;
	int j = 0;
	Q_FOREACH(arg, lines[0]) {
		plots[arg] = QVector<qreal>(lines.size());
		j = 0;
		Q_FOREACH(args_2, lines) {
			if(!i) {
				// First col is x value
				x_vals.append(args_2[i]);
			} else {
				// Add y value to plot
				plots[arg][j] = args_2[i].toFloat();
			}
			++j;
		}
		++i;
	}

	// Create plots (lines)
	QList<QwtPlotCurve*> plot_curves;
	QwtPlotCurve *c;
	LineGraph *lg = new LineGraph();
	QVector<qreal> x_points(x_vals.size());
	for(i = 0;i < x_points.size();i++)
		x_points[i] = i;
	i = 0;
	Q_FOREACH(arg, plots.keys()) {
		c = new QwtPlotCurve(arg);
		qDebug() << arg << plots[arg];
		c->setData(x_points, plots[arg]);
		c->setPen(line_colors[i%line_color_cnt]);
		c->attach(lg);
		++i;
	}

	lg->insertLegend(new QwtLegend(), QwtPlot::RightLegend);

	return lg;
}

LineGraph::LineGraph(QWidget *parent)
	: QwtPlot(parent)
{
}

LineGraph::LineGraph(const QwtText &title, QWidget *parent)
	: QwtPlot(title, parent)
{
}

