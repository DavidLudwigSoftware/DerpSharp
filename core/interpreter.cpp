#include "interpreter.h"

Interpreter::Interpreter() :
    QObject()
{
    _nums << 0;

    _nIndex = 0;
}

void Interpreter::execute(QList<Token*> tokens)
{
    _tokens = tokens;

    for (_index = 0; _index < _tokens.count(); next())
    {
        if (token()->type() == Token::Other)
        {
            if (token()->content() == "HURR")

                incN();

            else if (token()->content() == "DURR")

                decN();

            else if (token()->content() == "HERP")

                incNIndex();

            else if (token()->content() == "DERP")

                decNIndex();

            else if (token()->content() == "GIGGITY")

                output(false);

            else if (token()->content() == "GOO")

                output(true);
        }
    }
}

void Interpreter::incN()
{
    _nums[_nIndex]++;
}

void Interpreter::decN()
{
    _nums[_nIndex]++;
}

void Interpreter::incNIndex()
{
    _nIndex++;

    while (_nIndex >= _nums.length())

        _nums << 0;
}

void Interpreter::decNIndex()
{
    _nIndex--;

    if (_nIndex < 0)

        _nIndex = 0;
}

void Interpreter::output(bool ascii)
{
    if (ascii)
    {
        qDebug() << QChar(_nums[_nIndex]);
    }
    else
    {
        qDebug() << _nums[_nIndex];
    }
}

void Interpreter::next(int offset)
{
    _index += offset;
}

void Interpreter::prev(int offset)
{
    _index -= offset;

    if (_index < 0)

        _index = 0;
}

Token* Interpreter::token(int offset)
{
    if (_index + offset < _tokens.length())

        return _tokens.at(_index + offset);

    return _tokens.last();
}
