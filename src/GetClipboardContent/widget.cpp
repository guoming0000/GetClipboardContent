#include "widget.h"
#include "ui_widget.h"
#include <QClipboard>
#include <QMimeData>
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    on_btnRefresh_clicked();
}

const QMimeData* getClipboardMimeData()
{
    QClipboard *clipboard = QGuiApplication::clipboard();
    const QMimeData *mimeData = clipboard->mimeData();
    return mimeData;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnHtml_clicked()
{
    const QMimeData *mimeData = getClipboardMimeData();
    if(mimeData->hasHtml())
    {
        //ui->textBrowser->setHtml(mimeData->html());
       // qDebug()<<mimeData->html();
        ui->textBrowser->setPlainText(mimeData->html());
    }
}

void Widget::on_btnImage_clicked()
{
    const QMimeData *mimeData = getClipboardMimeData();
    if(mimeData->hasImage())
    {
         QImage image = qvariant_cast<QImage>(mimeData->imageData());
         image.save("D:/image.png");
        // ui->textBrowser->loadResource(QTextDocument::ImageResource, )
    }
}

void Widget::on_btnText_clicked()
{
    const QMimeData *mimeData = getClipboardMimeData();
    if(mimeData->hasText())
    {
        ui->textBrowser->setPlainText(mimeData->text());
    }
}

void Widget::on_btnUrl_clicked()
{
    const QMimeData *mimeData = getClipboardMimeData();
    QStringList strList;
    if(mimeData->hasUrls())
    {
        QList<QUrl> urls = mimeData->urls();
        for(int i = 0; i < urls.count(); ++i)
        {
            strList.push_back(urls.at(i).url());
        }
        ui->textBrowser->setPlainText(strList.join('\n'));
    }
}

void Widget::on_btnRefresh_clicked()
{
    const QMimeData *mimeData = getClipboardMimeData();
    ui->btnHtml->setEnabled(mimeData->hasHtml());
    ui->btnText->setEnabled(mimeData->hasText());
    ui->btnUrl->setEnabled(mimeData->hasUrls());
    ui->btnImage->setEnabled(mimeData->hasImage());
    ui->btnColor->setEnabled(mimeData->hasColor());
}

void Widget::on_btnColor_clicked()
{
    const QMimeData *mimeData = getClipboardMimeData();
    if(mimeData->hasColor())
    {
        qDebug()<<mimeData->colorData();
        ui->textBrowser->setPlainText(mimeData->colorData().toString());
    }
}
