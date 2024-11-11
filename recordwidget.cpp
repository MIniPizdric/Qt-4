#include "recordwidget.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

RecordWidget::RecordWidget(const QString &filePath, QWidget *parent)
    : QWidget(parent)
{

    qDebug() << "Путь к файлу:" << filePath;

    loadFileToTable(filePath);


}

void RecordWidget::loadFileToTable(const QString &filePath) {

    QTableWidget *table = new QTableWidget(this);
    table->setRowCount(0);
    table->setColumnCount(0);
    table->setHorizontalHeaderLabels(QStringList() << "Имя игрока" << "Рекорд");
    table->show();

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл.");
        return;
    }

    QTextStream in(&file);
    int row = 0;

    table->setColumnCount(2);
    table->setHorizontalHeaderLabels(QStringList() << "Имя игрока" << "Рекорд");

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList values = line.split(",");

        if (values.size() < 2) {
            QMessageBox::warning(this, "Ошибка", "Некорректная строка в файле: " + line);
            continue;
        }

        table->insertRow(row);
        QTableWidgetItem *nameItem = new QTableWidgetItem(values[0].trimmed());
        QTableWidgetItem *scoreItem = new QTableWidgetItem(values[1].trimmed());

        table->setItem(row, 0, nameItem);
        table->setItem(row, 1, scoreItem);

        row++;
    }

    file.close();
}
