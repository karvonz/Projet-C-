#ifndef COMBOBOX_H
#define COMBOBOX_H
#include <iostream>

#include <QComboBox>

class VComboBox : public QComboBox
{
    Q_OBJECT
public:
    VComboBox(QWidget *parent = 0);

signals:
    void mouseEntered(VComboBox* adresse);
    void mouseLeft(VComboBox* adresse);
protected:
    void enterEvent(QEvent*);
    void leaveEvent(QEvent*);
};

#endif // COMBOBOX_H
