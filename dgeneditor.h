#ifndef DGENEDITOR_H
#define DGENEDITOR_H

#include <QPlainTextEdit>

class DGenEditor : public QPlainTextEdit
{
    Q_OBJECT
public:
    DGenEditor(const QString &text, QWidget *parent = nullptr);
    DGenEditor(QWidget * parent= nullptr);
};

#endif // DGENEDITOR_H
