#include "timelistwidget.h"
#include <QHBoxLayout>
#include "comm/CXmlLanguage.h"
#define HEIGHT 45

TimeListWidget::TimeListWidget(QMap<int, QString> leaderboard, QWidget *parent) : QListWidget(parent)
{
    setFocusPolicy(Qt::NoFocus);
    setSelectionMode(QAbstractItemView::SingleSelection);
    setSelectionBehavior(QAbstractItemView::SelectRows);
    setAlternatingRowColors(true);
    QListWidgetItem *item = new QListWidgetItem(this);
    addItem(item);
    TimeListItem *itemWidget = new TimeListItem(LoadStringFromID(IDS_LEVEL), LoadStringFromID(IDS_TIMES), item, this, false);
    setItemWidget(item, itemWidget);
    for(auto it = leaderboard.begin(); it != leaderboard.end(); it++)
    {
        QListWidgetItem *item = new QListWidgetItem(this);
        addItem(item);
        TimeListItem *itemWidget = new TimeListItem(QString::number(it.key()), it.value(), item, this);
        setItemWidget(item, itemWidget);
    }
    setStyle();
}

void TimeListWidget::setStyle()
{
    QStringList qss;
    qss.append(QString("TimeListWidget{"
                       "background-color: #f5f7f8;"
                       "alternate-background-color:#e7eff4;"
                       "border-left: 1px solid  #34A4C4;"
                       "border-top: 1px solid  #34A4C4;"
                       "border-right: 1px solid #34A4C4;"
                       "border-bottom: 1px solid #34A4C4;"
                       "outline: 0px;}"
                       "TimeListWidget::item:hover{"
                        "background-color: #d3eefb;}"
                       "TimeListWidget::item:selected{"
                       "background-color: #d3eefb;"
                       "color: #000000;}"));
    this->setStyleSheet(qss.join(""));
}

/************************
 *  TimeListItem  *
 ************************/
TimeListItem::TimeListItem(QString level, QString time, QListWidgetItem *item, QWidget *parent, bool bPicVisible) :
    QWidget(parent),
    m_pItem(item)
{
    QFont ft;
    ft.setPointSize(18);
    ft.setBold(true);

    m_labelLevel = new QLabel(this);
    m_labelLevel->setText(level);
    m_labelLevel->setAlignment(Qt::AlignCenter);
    m_labelLevel->setFont(ft);
    m_labelTime = new QLabel(this);
    m_labelTime->setText(time);
    m_labelTime->setAlignment(Qt::AlignCenter);
    m_labelTime->setFont(ft);
    m_labelPic = new QLabel(this);
    m_labelPic->setFixedSize(32, 32);
    m_labelPic->setPixmap(QPixmap(":/res/medal.png"));
    m_labelPic->setVisible(bPicVisible);
    m_pItem->setSizeHint(QSize(0, HEIGHT));
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(m_labelPic);
    mainLayout->addWidget(m_labelLevel);
    mainLayout->addStretch(1);
    mainLayout->addWidget(m_labelTime);
    mainLayout->setSpacing(10);
    mainLayout->setContentsMargins(15, 10, 15, 10);
    setLayout(mainLayout);

}
