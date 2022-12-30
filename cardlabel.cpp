#include "cardlabel.h"
#include <QMouseEvent>

CardLabel::CardLabel(QWidget *parent, bool bType) :
    QLabel(parent),
    m_maskWidget(nullptr),
    m_hoverWidget(nullptr),
    m_animation(nullptr),
    m_Renderer(nullptr),
    m_ptInit(QPoint(0, 0))
{
    m_info = new cardInfo();
    if(bType == Card)
        setFixedSize(57, 57);
    else
        setFixedSize(48, 48);

    QStringList qss;
    qss.append("QWidget{border-radius: 12px;}");
    qss.append("QWidget{background-color:rgba(0, 0, 0, 0.6);}");
    m_maskWidget = new QWidget(this);
    m_maskWidget->setStyleSheet(qss.join(""));
    m_maskWidget->setGeometry(0, 0, width(), height());
    m_maskWidget->close();

    qss.clear();
    qss.append("QWidget{background-color:rgba(220, 232, 246, 0.3);}");
    qss.append("QWidget{border-radius: 12px;}");
    m_hoverWidget = new QWidget(this);
    m_hoverWidget->setStyleSheet(qss.join(""));
    m_hoverWidget->setGeometry(0, 0, width(), height());
    m_hoverWidget->close();

    if(bType == Prop)
    {
        qss.clear();
        qss.append(QString("QLabel{"
                           "background-color:#000000;"
                           "color: #ffffff;"
                           "border-radius: 6px;"
                           "font-weight:bold;}"));
        m_count = new QLabel(this);
        m_count->setGeometry(32, 0, 16, 16);
        m_count->setAlignment(Qt::AlignCenter);
        QFont ft;
        ft.setPixelSize(15);
        m_count->setFont(ft);
        m_count->setText("+");
        m_count->setStyleSheet(qss.join(""));
    }

    qss.clear();
    if(bType == Prop)
    {
        qss.append(QString("CardLabel{"
                       "border-top: 2px solid  #000000;"
                       "border-left: 2px solid  #000000;"
                       "border-right: 2px solid #000000;"
                       "border-bottom: 2px solid #000000;}"));
    }
    qss.append("CardLabel{border-radius: 8px;}");

    this->setStyleSheet(qss.join(""));
}

void CardLabel::setMask(bool state)
{
    if(m_maskWidget && state)
        m_maskWidget->close();
    else if(m_maskWidget && !state)
        m_maskWidget->show();
    setEnabled(state);
}

void CardLabel::setCardInfo(int row, int column, int layer, int type, int mode, CardLabel *card, bool bHorizon)
{
    m_info->row = row;
    m_info->column = column;
    m_info->layer = layer;
    m_info->type = type;
    m_info->mode = mode;
    m_info->card = card;
    m_info->bHorizon = bHorizon;
    LoadNormalImg(type);
}

void CardLabel::setCardType(int type)
{
    m_info->type = type;
    LoadNormalImg(type);
}

void CardLabel::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit mouseClicked();
        if(m_hoverWidget->isVisible())
            m_hoverWidget->close();
    }
    QLabel::mouseReleaseEvent(event);
}

void CardLabel::enterEvent(QEvent *event)
{
    if(m_hoverWidget)
        m_hoverWidget->show();
    event->ignore();
}

void CardLabel::leaveEvent(QEvent *event)
{
    if(m_hoverWidget)
        m_hoverWidget->close();
    event->ignore();
}

void CardLabel::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(m_Renderer && m_Renderer->isValid())
    {
        m_Renderer->render(&painter);
    }
    QLabel::paintEvent(event);
}

void CardLabel::animationMove(QPoint ptEnd, bool bAnimation)
{
    if(!bAnimation)
    {
        move(ptEnd);
        return;
    }
    if(!m_animation)
        m_animation = new QPropertyAnimation(this, "geometry",this);
    if(m_animation->state() == QPropertyAnimation::Running)
    {
        m_animation->stop();
    }
    QRect rtEnd = QRect(ptEnd, size());
    m_animation->setDuration(200);
    m_animation->setStartValue(geometry());
    m_animation->setEndValue(rtEnd);
    m_animation->start();
}

void CardLabel::LoadSvgImg(QString path)
{
    if(!m_Renderer)
        m_Renderer = new QSvgRenderer(this);

    if(m_Renderer->load(path))
        update();
}

void CardLabel::LoadNormalImg(int type)
{
    QString path;
    switch (type){
    case ONE:
        path = ":/res/1.png";
        break;
    case TWO:
        path = ":/res/2.png";
        break;
    case THREE:
        path = ":/res/3.png";
        break;
    case FOUR:
        path = ":/res/4.png";
        break;
    case FIVE:
        path = ":/res/5.png";
        break;
    case SIX:
        path = ":/res/6.png";
        break;
    case SEVEN:
        path = ":/res/7.png";
        break;
    case EIGHT:
        path = ":/res/8.png";
        break;
    case NINE:
        path = ":/res/9.png";
        break;
    case TEN:
        path = ":/res/10.png";
        break;
    case ELEVEN:
        path = ":/res/11.png";
        break;
    case TWELVE:
        path = ":/res/12.png";
        break;
    case THIRTEEN:
        path = ":/res/13.png";
        break;
    case FOURTEEN:
        path = ":/res/14.png";
        break;
    case FIFTEEN:
        path = ":/res/15.png";
        break;
    case SIXTEEN:
        path = ":/res/16.png";
        break;
    case QUESTION:
        path = ":/res/plus.png";
        m_info->bQuestion = true;
        break;
    }
    setPixmap(QPixmap(path));
}

void CardLabel::setGeometry(int x, int y, int w, int h)
{
    m_ptInit = QPoint(x, y);
    QLabel::setGeometry(x, y, w, h);
}

void CardLabel::setPropCount(QString text)
{
    m_count->setText(text);
}


