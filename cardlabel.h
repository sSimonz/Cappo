#ifndef CARDLABEL_H
#define CARDLABEL_H

#include <QWidget>
#include <QLabel>
#include <QPropertyAnimation>
#include <QSvgRenderer>
#include <QPainter>

class CardLabel;
enum CardType
{
    QUESTION = 0,
    ONE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    ELEVEN,
    TWELVE,
    THIRTEEN,
    FOURTEEN,
    FIFTEEN,
    SIXTEEN
};

enum MODE
{
    MODEA = 0,
    MODEB,
    MODEC,
    MODEPEND // 使用移出道具时使用
};

enum type
{
    Card = 0,
    Prop
};

struct cardInfo
{
    int row;
    int column;
    int layer;
    int type;
    int mode;// 牌堆模式A:上面1张牌只挡住下面1张牌; 牌堆模式B:上面1张牌可以挡住下面2张牌; 牌堆模式C：上面1张牌可以挡住下面4张牌
    CardLabel *card;
    bool bHorizon;// 只在牌堆模式B使用, true: 水平堆放; false: 垂直堆放
    bool bQuestion;
    cardInfo()
    {
        row = 0;
        column = 0;
        layer = 0;
        type = 0;
        mode = MODEC;
        card = nullptr;
        bHorizon = true;
        bQuestion = false;
    }
};

class CardLabel : public QLabel
{
    Q_OBJECT
public:
    explicit CardLabel(QWidget *parent = nullptr, bool bType = Card);
    void setCardInfo(int x, int y, int layer, int type, int mode, CardLabel *card, bool bHorizon = true);
    cardInfo *getCardInfo() {   return m_info;}
    void setCardMode(int mode)  {   m_info->mode = mode;}
    void setCardType(int type);
    void setMask(bool state);// false: 暗化不可点击; true: 正常可点击
    void animationMove(QPoint ptEnd, bool bAnimation = true);
    void LoadSvgImg(QString path);
    void LoadNormalImg(int type);
    void setGeometry(int x, int y, int w, int h);
    void setPropCount(QString text);// 道具可用次数

    QPoint m_ptInit;

protected:
    void mouseReleaseEvent(QMouseEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    void paintEvent(QPaintEvent *event);

signals:
    void mouseClicked();

public slots:

private:
    cardInfo *m_info;
    QWidget *m_maskWidget;
    QWidget *m_hoverWidget;
    QLabel *m_count;// 道具可用次数
    QPropertyAnimation* m_animation;//移动动画
    QSvgRenderer *m_Renderer;
};

#endif // CARDLABEL_H
