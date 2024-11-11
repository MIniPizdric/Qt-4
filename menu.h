#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QPushButton>
#include <playwidget.h>
#include <settingwidget.h>
#include "recordwidget.h"
#include <QTableWidget>
class Menu : public QWidget {
Q_OBJECT
public:
    Menu();
public slots:
    void playClicked();
    void settingsClicked();
    void recordClicked();
   // void updateStatsFilePath(const QString &newPath);

private:
    QPushButton *play;
    QPushButton *setting;
    QPushButton *records;

    PlayWidget *playWidget = nullptr;
    SettingWidget *settingsWidget = nullptr;
    RecordWidget *recordWidget = nullptr;

    QString statsFilePath = "C:/Users/user/Desktop/интерфейсы/рекорды.txt";

};

#endif // MENU_H
