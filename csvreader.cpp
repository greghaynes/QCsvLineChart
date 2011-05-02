#include "csvreader.h"

#include <QStringList>

CsvReader::CsvReader(QObject *parent)
	: QObject(parent)
	, m_device(0)
{
}

void CsvReader::setDevice(QIODevice &from)
{
	from.setParent(this);
	m_device = &from;
}

QList< QList<QString> > CsvReader::parseToEnd(void)
{
	QString buff = m_device->readAll();
	QList<QString> lines = buff.split('\n');

	// Parse lines
	QList< QList<QString> > lineArgs;
	QString cur_line;
	Q_FOREACH(cur_line, lines) {
		lineArgs.append(cur_line.split(','));
	}

	return lineArgs;
}

