#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_btnHtml_clicked();

    void on_btnImage_clicked();

    void on_btnText_clicked();

    void on_btnUrl_clicked();

    void on_btnRefresh_clicked();

    void on_btnColor_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
