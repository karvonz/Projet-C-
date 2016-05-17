#include "combobox.h"

#include <iostream>
using namespace std;

VComboBox::VComboBox(QWidget *parent) : QComboBox(parent)
{

}

void VComboBox::enterEvent(QEvent *)
{
    emit mouseEntered(this);
}

void VComboBox::leaveEvent(QEvent *)
{
    emit mouseLeft(this);
}


