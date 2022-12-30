#include "customcombobox.h"
#include <QListView>
#include <QLineEdit>

CustomComboBox::CustomComboBox(QWidget *parent) :
    QComboBox(parent)
{
    setFixedHeight(35);
    setEditable(true);
    lineEdit()->setReadOnly(true);
    lineEdit()->setTextMargins(5,3,0,3);
    setView(new QListView);// 不设置这一项下拉框样式无法设置

    QStringList qss;
    qss.append(QString("QComboBox{"
                       "height:50px;"
                       "font-size: 20px;"
                       "border: 2px solid  #b3b3b3;"
                       "border-radius: 5px;"
                       "background: #f6f7f8;"
                       "selection-color:#ffffff;}"));
    qss.append(QString("QComboBox:hover,QComboBox:focus{"
                       "border: 2px solid #666666;}"));
    qss.append(QString("QComboBox::drop-down{"
                       "subcontrol-origin: padding;"
                       "subcontrol-position: top right;"
                       "width: 30px;"
                       "outline: 0px;"
                       "border:0px;}"));
    qss.append(QString("QComboBox::down-arrow{"
                       "image: url(:/res/DownInput.svg);"
                       "border: 0px;}"));
    qss.append(QString("QComboBox::down-arrow:hover{"
                       "border: 0px;}"));
    qss.append(QString("QComboBox QAbstractItemView{"
                       "background-color:#f5f7f8;"
                       "outline: 0px;"
                       "border: 1px solid #b3b3b3;"
                       "border-radius: 5px;}"));
    qss.append(QString("QComboBox QAbstractItemView:item{"
                       "height:35px;"
                       "outline: 0px;}"));

    setStyleSheet(qss.join(""));
}

