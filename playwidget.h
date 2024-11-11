#ifndef PLAYWIDGET_H
#define PLAYWIDGET_H

#include <QWidget>
#include <QCloseEvent>


class PlayWidget : public QWidget {
    Q_OBJECT
public:
    PlayWidget(QWidget* parent);
protected:
    void closeEvent(QCloseEvent* event) override {
        qDebug() << "Окно закрывается";
        event->accept();
        delete this;
    }
};

#endif // PLAYWIDGET_H
