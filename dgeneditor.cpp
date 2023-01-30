#include "dgeneditor.h"

DGenEditor::DGenEditor(const QString &text, QWidget *parent):
    QPlainTextEdit(text, parent)
{

}

DGenEditor::DGenEditor(QWidget *parent) :
    QPlainTextEdit(parent)
{

}
