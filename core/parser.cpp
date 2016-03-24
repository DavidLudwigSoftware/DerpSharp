#include "parser.h"

Parser::Parser() :
    QObject()
{

}

QList<Token*> Parser::parse(QString content)
{
    QList<Token*> tokens;

    if (content.toUpper() != content)

        throw new QException();

    _parts = content.split(QRegExp("\\s+"), QString::SkipEmptyParts);
    _partCount = _parts.length();

    for (_index = 0; _index < _partCount; next())
    {
        if (comment())

            continue;

        else if (define("PLOOF"))

            tokens << new Token(Token::Marker, part());

        else if (define("JUMPJIM"))

            tokens << new Token(Token::Jump, part());

        else if (error())

            throw new QException();

        else

            tokens << new Token(Token::Other, part());

    }

    tokens << new Token(Token::Eof, part());

    return tokens;
}

bool Parser::comment()
{
    if (part() == "HURBLURG")
    {
        do
            next();
        while (part() != "DURBLURG" && part() != NULL);

        return true;
    }
    return false;
}

bool Parser::define(QString key)
{
    if (part() == key)
    {
        next();

        if (part() == "HURBLURG")
        {
            comment();
            next();
        }

        if (part() == NULL)

            throw new QException();

        return true;
    }

    return false;
}

bool Parser::error()
{
    if (part() == "DURBLURG")

        return true;

    return false;
}

void Parser::next(int offset)
{
    _index += offset;
}

void Parser::prev(int offset)
{
    _index -= offset;
}

QString Parser::part(int offset)
{
    return _index + offset < _partCount ? _parts.at(_index + offset) : NULL;
}
