#ifndef PARSER_H
#define PARSER_H

#include <QDebug>
#include <QException>
#include <QObject>

#include "token.h"

class Parser : public QObject
{
    Q_OBJECT
public:
    Parser();

    void next(int offset = 1);
    void prev(int offset = 1);
    QString part(int offset = 0);

protected:
    bool comment();
    bool define(QString key);
    bool error();

private:
    int _index;
    QStringList _parts;
    int _partCount;

signals:

public slots:
    QList<Token*> parse(QString content);
};

#endif // PARSER_H
