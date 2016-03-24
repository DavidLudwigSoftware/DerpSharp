#include "application.h"

Application::Application(int argc, char *argv[]) :
    QApplication(argc, argv)
{
}

bool Application::interpretFile(QString path)
{
    QString content = loadFile(path);

    Parser *parser = new Parser();
    Interpreter *interpreter = new Interpreter();

    try
    {
        QList<Token*> tokens = parser->parse(content);

        interpreter->execute(tokens);
    }
    catch(...)
    {
        qDebug() << "YOUR PROGRAM HAS CANCER";
        return false;
    }

    return true;
}

QString Application::loadFile(QString path)
{
    QFile file(path);

    file.open(QFile::ReadOnly);

    QString content(file.readAll());

    file.close();

    return content;
}
