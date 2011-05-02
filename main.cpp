#include "linegraph.h"

#include <QApplication>
#include <QFileDialog>
#include <QList>
#include <QString>
#include <QFile>

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	QFileDialog diag(0, "Select CSV", QString(), "*.csv");
	if(diag.exec()) {
		QList<QString> selectedFiles = diag.selectedFiles();
		QString file;
		Q_FOREACH(file, selectedFiles) {
			QFile *f = new QFile(file);
			f->open(QIODevice::ReadOnly);
			LineGraph *lg = LineGraph::fromCsv(*f);
		}
	}

	return 0;
}

