#ifndef TIMELISTWIDGET_H
#define TIMELISTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QListWidget>

class TimeListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit TimeListWidget(QMap<int, QString> leaderboard, QWidget *parent = nullptr);
    void setStyle();

};


/************************
 *  TimeListItem  *
 ************************/
class TimeListItem : public QWidget
{
    Q_OBJECT

public:
    explicit TimeListItem(QString level, QString time, QListWidgetItem *item , QWidget *parent = nullptr, bool bPicVisible = true);
    QString getItemName();

private:
    QListWidgetItem *m_pItem;
    QLabel *m_labelPic;
    QLabel *m_labelLevel;
    QLabel *m_labelTime;

};

#endif // TIMELISTWIDGET_H
