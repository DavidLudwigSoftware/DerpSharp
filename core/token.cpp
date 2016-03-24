#include "token.h"

Token::Token(Token::Type type, QString content) :
    _type(type), _content(content)
{

}

Token::Type Token::type()
{
    return _type;
}

QString Token::content()
{
    return _content;
}
