#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QRegExp>
#include <QObject>

#include "interpreter.h"
#include "parser.h"

class Application : public QApplication
{
    Q_OBJECT
public:
    Application(int argc, char *argv[]);

    bool interpretFile(QString path);

private:
    QString loadFile(QString path);

signals:

public slots:
};

#endif // APPLICATION_H
