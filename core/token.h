#ifndef TOKEN_H
#define TOKEN_H

#include <QString>
#include <QObject>

class Token
{

public:
    enum Type
    {
        Marker,
        Jump,
        Other,
        Eof,
    };

    Token(Token::Type type, QString content = "");

    Token::Type type();
    QString content();

private:
    const Token::Type _type;
    const QString _content;

};

#endif // TOKEN_H
