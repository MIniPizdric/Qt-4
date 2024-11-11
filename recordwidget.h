#ifndef RECORDWIDGET_H
#define RECORDWIDGET_H

#include <QWidget>
#include <QTableWidget>


class RecordWidget : public QWidget {
    Q_OBJECT
public:
    explicit RecordWidget(const QString &filePath, QWidget *parent = nullptr);
    void loadFileToTable(const QString &filePath);

};

#endif // RECORDWIDGET_H
