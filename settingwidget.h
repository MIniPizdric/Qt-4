#ifndef SETTINGWIDGET_H
#define SETTINGWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>


class SettingWidget : public QWidget {
    Q_OBJECT
public:
    SettingWidget();
signals:
    void statsFilePathChanged(const QString &newPath);
public slots:
    void savePressed();
private:
    QLabel *enterPath;
    QLineEdit *path;
    QPushButton *save;
};

#endif // SETTINGWIDGET_H
