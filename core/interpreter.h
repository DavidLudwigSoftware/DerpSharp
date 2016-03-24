#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <QDebug>
#include <QList>
#include <QObject>
#include <QString>

#include "token.h"

class Interpreter : public QObject
{
    Q_OBJECT
public:
    Interpreter();

private:
    QList<Token*> _tokens;
    QList<int> _nums;

    int _index;
    int _nIndex;

signals:

public slots:
    void execute(QList<Token*> tokens);
    void incN();
    void decN();
    void incNIndex();
    void decNIndex();

    void output(bool ascii = false);

    void next(int offset = 1);
    void prev(int offset = 1);
    Token* token(int offset = 0);
};

#endif // INTERPRETER_H
