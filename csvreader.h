#ifndef CSV_READER_H
#define CSV_READER_H
 
#include <QObject>
#include <QIODevice>
#include <QString>
#include <QList>

class CsvReader
	: public QObject
{

	public:
		CsvReader(QObject *parent = 0);

		void setDevice(QIODevice &from);

		QList< QList<QString> > parseToEnd(void);

	private:
		QIODevice *m_device;

};

#endif

