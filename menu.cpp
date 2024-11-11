#include "menu.h"
#include <QPushButton>
#include <QGridLayout>
#include "playwidget.h"
#include "settingwidget.h"
#include "recordwidget.h"
#include <QMessageBox>
#include <QDebug>



Menu::Menu() : QWidget(nullptr){
    play = new QPushButton("Играть", this);
    setting = new QPushButton("Настройки", this);
    records = new QPushButton("Статистика", this);

    recordWidget = new RecordWidget("C:/Users/user/Desktop/интерфейсы/рекорды.txt");

    settingsWidget = new SettingWidget();

    settingsWidget -> hide();


    recordWidget -> hide();




    QGridLayout *my_layout = new QGridLayout(this);
    this->setLayout(my_layout);

    my_layout->addWidget(play, 0, 0);
    my_layout->addWidget(setting, 1, 0);
    my_layout->addWidget(records, 2, 0);

    connect(play, SIGNAL(clicked(bool)), this, SLOT(playClicked()));

    connect(setting, SIGNAL(clicked(bool)), this, SLOT(settingsClicked()));

    connect(records, SIGNAL(clicked(bool)), this, SLOT(recordClicked()));






}

void Menu::recordClicked() {

    recordWidget->show();

    connect(settingsWidget,&SettingWidget::statsFilePathChanged,recordWidget,&RecordWidget::loadFileToTable);






}

void Menu::playClicked() {
    qDebug() << "Кнопка 'Играть' нажата";

    if (playWidget == nullptr) {
        playWidget = new PlayWidget(nullptr);
        playWidget->show();

        qDebug() << "Окно игры создано и показано";


        connect(playWidget, &QWidget::destroyed, this, [this]() {
            playWidget = nullptr;
            qDebug() << "Окно игры уничтожено";
        });
    } else {
        playWidget->raise();
        playWidget->activateWindow();
        qDebug() << "Окно игры уже открыто, поднято на передний план";

    }
}


void Menu::settingsClicked() {


    //connect(settingsWidget, &SettingWidget::statsFilePathChanged, this, &Menu::updateStatsFilePath);

    settingsWidget->show();

    // this->hide();
}




