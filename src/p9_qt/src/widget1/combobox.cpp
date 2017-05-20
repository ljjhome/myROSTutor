#include <QHBoxLayout>
#include "combobox.h"

ComboBoxEx::ComboBoxEx(QWidget* parent):QWidget(parent){
    
    QStringList distros = {"Arch","Xubuntu","RedHat","Debian","Mandriva"};

    QHBoxLayout *hbox = new QHBoxLayout(this);

    combo = new QComboBox();
    combo->addItems(distros);

    hbox->addWidget(combo);
    hbox->addSpacing(15);

    label = new QLabel("Arch",this);
    hbox->addWidget(label);

    connect(combo,static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::activated),
            label,&QLabel::setText);
}
