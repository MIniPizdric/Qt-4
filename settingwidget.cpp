#include "settingwidget.h"
#include <QGridLayout>
#include <QFileInfo>
#include <QMessageBox>

SettingWidget::SettingWidget() : QWidget(nullptr) {
    QGridLayout* my_layout = new QGridLayout(this);
    this->setLayout(my_layout);

    enterPath = new QLabel("path: ", this);
    path = new QLineEdit(this);
    save = new QPushButton("save ", this);

    my_layout->addWidget(enterPath, 0, 0);
    my_layout->addWidget(path, 0, 1);
    my_layout->addWidget(save, 1, 0, 1, 2);

    connect(save,SIGNAL(clicked(bool)),this,SLOT(savePressed()));
}

void SettingWidget::savePressed() {

    QFileInfo checkPath( path->text());

    if (checkPath.exists())
    {
        statsFilePathChanged(path->text());
        this->close();
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Указанный путь не существует. Пожалуйста, проверьте введенные данные.");
    }
}
