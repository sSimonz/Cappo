#include "PlayWidget.h"

#include <QRandomGenerator>
#include <QBitmap>
#include <QDebug>
#include "dataconfig.h"
#include "mainwindow.h"

#define WIDTH 48    // 卡片宽高
#define NUM 8       // 行列数
#define PLACE 50    // 占位符, 起点留白
PlayWidget::PlayWidget(Stage degree, int level, QWidget *parent) :
    QWidget(parent),
    m_cardCount(0),
    m_levelCount(1),
    m_type(8),
    m_stage(degree),
    m_FailCount(0),
    m_RemoveCount(0),
    m_RetractCount(0),
    m_ShuffleCount(0),
    m_cardSlotCount(NUM-1),
    m_btnSetting(nullptr),
    m_btnRemove(nullptr),
    m_btnRetract(nullptr),
    m_btnShuffle(nullptr),
    m_bRevive(false),
    m_bCheat(false),
    m_timer(nullptr),
    m_level(level),
    m_flickerTimer(nullptr),
    m_waitDialog(nullptr),
    m_bAddOneSlot(false),
    m_clickMusic(false),
    m_removeMusic(false)
{
    setWindowIcon(QIcon(":/res/app.png"));
    setWindowTitle("Cappo of Cappo");
    if(degree == EasyLevel || degree == MediumLevel)
        m_type = 8;
    else
        m_type = 16;

    Init();
}

PlayWidget::~PlayWidget()
{

}

void PlayWidget::Init()
{
    this->setFixedSize(WIDTH*NUM + WIDTH/2 + 2*PLACE, WIDTH*NUM + 6*PLACE);
    dataConfig m_config;
    m_Data = m_config.m_Data.value(m_level);
    m_cardCount = m_config.m_cardCount.value(m_level);
    m_levelCount = m_config.m_cardCount.count();
    setRandomCards();

    if(!m_btnSetting)
        InitBtnSetting();
    if(!m_timer)
        InitTimer();
    if(!m_btnRemove || !m_btnRetract || !m_btnShuffle)
        InitBtnProp();

    int index = 0;// 所有卡牌的种类索引
    for(int layer = 0; layer < m_Data.count(); layer++)
    {
        QVector< QVector<int>> gameArray = m_Data.value(layer);
        for(int row = 0; row < NUM; row++)
        {
            for(int column = 0; column < NUM; column++)
            {
                if(gameArray[row][column] == 0)
                    continue;   
                else if(gameArray[row][column] > 1 && gameArray[row][column] <= 10)// 模式A
                {
                    InitModeA(layer, row, column, index, gameArray);
                }
                else if(gameArray[row][column] > 10)// 模式B
                {
                    InitModeB(layer, row, column, index, gameArray);
                }
                else if(gameArray[row][column] == 1)// 模式C
                {
                    InitModeC(layer, row, column, index, gameArray);
                }
            }
        }
    }
//    InitQCards();
    m_timer->start();
}

void PlayWidget::InitModeA(int layer, int row, int column, int &index, QVector< QVector<int>> gameArray)
{
    QList<CardLabel *> cards;
    for(int i = 0; i < gameArray[row][column]; i++)
    {
        CardLabel *card = new CardLabel(this);
        if(index >= m_cardsType.size())// 防止越界
            index = 0;
        card->setCardInfo(row, column, i, m_cardsType.at(index++), MODEA, card);
        if(!cards.isEmpty())
        {
            CardLabel *cardPrev = cards.last();
            cardPrev->setMask(false);
        }
        cards.append(card);
        connect(card, &CardLabel::mouseClicked, this, &PlayWidget::addCardSlot);
        if(row == 6)// 垂直
            card->setGeometry(PLACE + WIDTH*column, PLACE + WIDTH*row + 10*i, WIDTH, WIDTH);
        else if(row == 7 && column < (NUM / 2))// 水平左到右
            card->setGeometry(PLACE + WIDTH*column + 10*i, PLACE + WIDTH*row, WIDTH, WIDTH);
        else// 水平右到左
            card->setGeometry(PLACE + WIDTH*column - 10*i, PLACE + WIDTH*row, WIDTH, WIDTH);
    }
    m_cardsModeA.insert(qMakePair(row, column), cards);
}

void PlayWidget::InitModeB(int layer, int row, int column, int &index, QVector< QVector<int>> gameArray)
{
    CardLabel *card = new CardLabel(this);
    if(index >= m_cardsType.size())// 防止越界
        index = 0;
    if(layer % 2 == 0)
    {
        card->setGeometry(PLACE + WIDTH*column, PLACE + WIDTH*row, WIDTH, WIDTH);
        if(gameArray[row][column] == 11)
            card->setCardInfo(row, column, layer, m_cardsType.at(index++), MODEB, card, true);
        else
            card->setCardInfo(row, column, layer, m_cardsType.at(index++), MODEB, card, false);
    }

    else if(layer % 2 && gameArray[row][column] == 11)
    {
        card->setGeometry(PLACE + (WIDTH / 2) + WIDTH*column, PLACE + WIDTH*row, WIDTH, WIDTH);
        card->setCardInfo(row, column, layer, m_cardsType.at(index++), MODEB, card, true);
    }
    else if(layer % 2 && gameArray[row][column] == 12)
    {
        card->setGeometry(PLACE + WIDTH*column, PLACE + (WIDTH / 2) + WIDTH*row, WIDTH, WIDTH);
        card->setCardInfo(row, column, layer, m_cardsType.at(index++), MODEB, card, false);
    }
    m_cardsModeB.append(card->getCardInfo());
    setEnabledByModeB(row, column, layer);
    connect(card, &CardLabel::mouseClicked, this, &PlayWidget::addCardSlot);
}

void PlayWidget::InitModeC(int layer, int row, int column, int &index, QVector< QVector<int>> gameArray)
{
    CardLabel *card = new CardLabel(this);
    if(index >= m_cardsType.size())// 防止越界
        index = 0;
    card->setCardInfo(row, column, layer, m_cardsType.at(index++), MODEC, card);
    if(layer % 2 == 0)
        card->setGeometry(PLACE + WIDTH*column, PLACE + WIDTH*row, WIDTH, WIDTH);
    else
        card->setGeometry(PLACE + (WIDTH / 2) + WIDTH*column, PLACE + (WIDTH / 2) + WIDTH*row, WIDTH, WIDTH);
    m_cardsModeC.append(card->getCardInfo());
    setEnabledByModeC(row, column, layer);
    connect(card, &CardLabel::mouseClicked, this, &PlayWidget::addCardSlot);
}

void PlayWidget::InitBtnSetting()
{
    m_btnSetting = new QPushButton(this);
    m_btnSetting->setGeometry(16, 16, 32, 32);
    m_btnSetting->setStyleSheet("QPushButton{"
                                "border-image: url(:/res/setting.png);"
                                "border-radius: 8px;}"
                                "QPushButton:hover{"
                                "background-color: #DCE8F6;}"
                                "QPushButton:pressed{"
                                "margin: 1px;"
                                "background-color: #DCE8F6;}");
    connect(m_btnSetting, &QPushButton::clicked, this, [this]()
    {
        Dialog *dialog = new Dialog(this, Dialog::SettingGame);
        connect(dialog, &Dialog::sendGame, this, [=](int result)
        {
            if(result == Dialog::Giveup)
                emit sendHome(Back);
            else if(result == Dialog::Restart)
                emit sendHome(Dialog::Restart);
            else if(result == Dialog::Volume_open)
                MainWindow::controlMusic(true);
            else if(result == Dialog::Volume_close)
                MainWindow::controlMusic(false);
        });
        dialog->exec();
    });

    // 测试用
    QPushButton *btn = new QPushButton(this);
    btn->setGeometry(0, height()-48, 48, 48);
    connect(btn, &QPushButton::clicked, this, [this]()
    {
        emit sendHome(Done);
    });
}

void PlayWidget::InitBtnProp()
{
    m_ptSlot = QPoint((width() - WIDTH*NUM) / 2, height() - 3*WIDTH - 10);
    m_ptPend = m_ptSlot;
    m_ptPend.setY(m_ptSlot.y() - WIDTH - 15);
    m_ptPend.setX(m_ptSlot.x() + WIDTH/2);

    m_btnRemove = new CardLabel(this, Prop);
    m_btnRemove->LoadSvgImg(":/res/Remove.svg");
    m_btnRemove->setToolTip(LoadStringFromID(IDS_TITLE_REMOVE));
    connect(m_btnRemove, &CardLabel::mouseClicked, this, &PlayWidget::propRemoveRsp);
    m_btnRetract = new CardLabel(this, Prop);
    m_btnRetract->LoadSvgImg(":/res/retract.svg");
    m_btnRetract->setToolTip(LoadStringFromID(IDS_TITLE_RETRACT));
    connect(m_btnRetract, &CardLabel::mouseClicked, this, &PlayWidget::propRetractRsp);
    m_btnShuffle = new CardLabel(this, Prop);
    m_btnShuffle->LoadSvgImg(":/res/shuffleCards.svg");
    m_btnShuffle->setToolTip(LoadStringFromID(IDS_TITLE_SHUFFLE));
    connect(m_btnShuffle, &CardLabel::mouseClicked, this, &PlayWidget::propShuffleRsp);

    QHBoxLayout *btnsLayout = new QHBoxLayout;
    btnsLayout->addStretch(1);
    btnsLayout->addWidget(m_btnRemove);
    btnsLayout->addWidget(m_btnRetract);
    btnsLayout->addWidget(m_btnShuffle);
    btnsLayout->addStretch(1);
    btnsLayout->setSpacing(WIDTH);
    QPoint ptBtns = m_ptSlot;
    ptBtns.setY(m_ptSlot.y() + 2*WIDTH);
    ptBtns.setX(m_ptSlot.x() + WIDTH/2);
    QRect rtBtns = QRect(ptBtns, QSize(7*WIDTH, WIDTH));
    btnsLayout->setGeometry(rtBtns);

    m_btnAddSlot = new QPushButton(this);
    QPoint ptBtn = m_ptSlot;
    ptBtn.setX(m_ptSlot.x() + WIDTH*7 + 7);
    ptBtn.setY(m_ptSlot.y() + 7);
    QRect rtBtn = QRect(ptBtn, QSize(WIDTH, WIDTH));
    m_btnAddSlot->setGeometry(rtBtn);
    m_btnAddSlot->setStyleSheet("QPushButton{"
                                "border-image: url(:/res/plus.png);"
                                "background-color: #FFBF31;"
                                "border-radius: 8px;}"
                                "QPushButton:hover{"
                                "background-color: #DCE8F6;}"
                                "QPushButton:pressed{"
                                "margin: 1px;}");
    connect(m_btnAddSlot, &QPushButton::clicked, this, [this]()
    {
        Dialog *dialog = new Dialog(this, Dialog::AddCardSlot);
        dialog->exec();
    });
    m_clickMusic = new QMediaPlayer(this);
    m_clickMusic->setMedia(QUrl("qrc:/res/BackButtonSound.wav"));
    m_removeMusic = new QMediaPlayer(this);
    m_removeMusic->setMedia(QUrl("qrc:/res/BackButtonSound.wav"));
//    connect(m_clickMusic, &QMediaPlayer::mediaStatusChanged, this, [this](QMediaPlayer::MediaStatus status)
//    {
//        if(status == QMediaPlayer::PlayingState)
//        {
//            m_clickMusic->stop();
//            m_clickMusic->setPosition(0);
//            m_clickMusic->play();
//        }
//    });

}

void PlayWidget::InitTimer()
{
    QFont ft;
    ft.setPixelSize(28);
    ft.setBold(true);
    m_timeDisplay = new QLabel(this);
    m_timeDisplay->setGeometry((width() - 150)/2, 10, 150, 30);
    m_timeDisplay->setAlignment(Qt::AlignCenter);
    m_timeDisplay->setFont(ft);
    m_time.setHMS(0,0,0,0);
    m_timeDisplay->setText(m_time.toString("hh:mm:ss"));
    m_timer = new QTimer(this);
    m_timer->setInterval(1000);
    connect(m_timer, &QTimer::timeout, this, [this]()
    {
        m_time = m_time.addSecs(1);
        m_timeDisplay->setText(m_time.toString("hh:mm:ss"));
    });
    m_levelDisplay = new QLabel(this);
    m_levelDisplay->setGeometry(width() - 150, 10, 150, 30);
    m_levelDisplay->setAlignment(Qt::AlignCenter);
    m_levelDisplay->setFont(ft);
    m_levelDisplay->setText(QString("Level:%1").arg(m_level));
}

void PlayWidget::ResetTimer()
{
    m_timer->stop();
    m_time.setHMS(0,0,0,0);
    m_timeDisplay->setText(m_time.toString("hh:mm:ss"));

}

/* 上判断下
 * 奇数层上偶数层下: (0,0)遮挡 (0,0)(0,1)(1,0)(1,1); (0,1)遮挡 (0,1)(0,2)(1,1)(1,2)
 * 偶数层上奇数层下: (1,1)遮挡 (0,0)(0,1)(1,0)(1,1); (1,2)遮挡 (0,1)(0,2)(1,1)(1,2)
*/
void PlayWidget::setEnabledByModeC(int row, int column, int layer, bool bInit)
{
    for(int curLayer = layer-1; curLayer >= 0; curLayer-=2)
    {
        QVector< QVector<int>> gameArray = m_Data.value(curLayer);// 下一层数据
        if(gameArray.isEmpty())
            continue;
        if(gameArray[row][column])
            FindCardToSetMask(row, column, curLayer, bInit, MODEC);
        if(layer % 2)
        {
            if(row + 1 < NUM && gameArray[row + 1][column])
                FindCardToSetMask(row + 1, column, curLayer, bInit, MODEC);
            if(column + 1 < NUM && gameArray[row][column + 1])
                FindCardToSetMask(row, column + 1, curLayer, bInit, MODEC);
            if(row + 1 < NUM && column + 1 < NUM && gameArray[row + 1][column + 1])
                FindCardToSetMask(row + 1, column + 1, curLayer, bInit, MODEC);
        }
        else
        {
            if(row - 1 >= 0 && gameArray[row - 1][column])
                FindCardToSetMask(row - 1, column, curLayer, bInit, MODEC);
            if(column - 1 >= 0 && gameArray[row][column - 1])
                FindCardToSetMask(row, column - 1, curLayer, bInit, MODEC);
            if(row - 1  >= 0 && column - 1  >= 0 && gameArray[row - 1][column - 1])
                FindCardToSetMask(row - 1, column - 1, curLayer, bInit, MODEC);
        }
    }

}

/* 下判断上
 * 偶数层下奇数层上: (1,1)被遮挡 (0,0)(0,1)(1,0)(1,1); (1,2)被遮挡 (0,1)(1,1)(0,2)(1,2)
 * 奇数层下偶数层上: (0,0)被遮挡 (0,0)(0,1)(1,0)(1,1); (0,1)被遮挡 (0,1)(0,2)(1,1)(1,2)
*/
bool PlayWidget::IsUpEnabledByModeC(int row, int column, int layer)
{
    for(int curLayer = layer+1; curLayer < m_Data.count(); curLayer+=2)
    {
        QVector< QVector<int>> upGameArray = m_Data.value(curLayer);
        if(upGameArray.isEmpty())
            continue;

        if(upGameArray[row][column])
            return false;
        if(layer % 2 == 0)
        {
            if(row - 1 >= 0 && upGameArray[row - 1][column] == 1)
                return false;
            if(column - 1 >= 0 && upGameArray[row][column - 1] == 1)
                return false;
            if(row - 1 >= 0 && column - 1 >= 0 && upGameArray[row - 1][column - 1] == 1)
                return false;
        }
        else
        {
            if(row + 1 < NUM && upGameArray[row + 1][column] == 1)
                return false;
            if(column + 1 < NUM && upGameArray[row][column + 1] == 1)
                return false;
            if(row + 1 < NUM && column + 1 < NUM && upGameArray[row + 1][column + 1] == 1)
                return false;
        }
    }



    return true;
}

void PlayWidget::FindCardToSetMask(int row, int column, int layer, bool bInit, int mode)
{
    QList<cardInfo *> cards;
    if(mode == MODEC)
        cards = m_cardsModeC;
    else if(mode == MODEB)
        cards = m_cardsModeB;
    CardLabel *card = nullptr;
    foreach(cardInfo *info, cards)
    {
        if(info->row == row && info->column == column && info->layer == layer)
        {
            card = info->card;
            break;
        }
    }
    if(card)
    {
        if(bInit)
            card->setMask(false);
        else if(!bInit && mode == MODEC && IsUpEnabledByModeC(row, column, layer))
            card->setMask(true);
        else if(!bInit && mode == MODEB && IsUpEnabledByModeB(row, column, layer, card->getCardInfo()->bHorizon))
            card->setMask(true);
    }
}

/* 上判断下
 * 奇数层上偶数层下: (0,0)遮挡 水平(0,0)(0,1) 垂直(0,0)(1,0); (0,1)遮挡 水平(0,1)(0,2) 垂直(0,1)(1,1)
 * 偶数层上奇数层下: (1,1)遮挡 水平(1,0)(1,1) 垂直(0,1)(1,1); (1,2)遮挡 水平(1,1)(1,2) 垂直(0,2)(1,2)
*/
void PlayWidget::setEnabledByModeB(int row, int column, int layer, bool bInit)
{
    bool bHorizon = true;// true:水平 , false:垂直
    foreach(cardInfo *info, m_cardsModeB)
    {
        if(info->row == row && info->column == column && info->layer == layer)
        {
            bHorizon = info->bHorizon;
            break;
        }
    }

    for(int curLayer = layer-1; curLayer >= 0; curLayer-=2)
    {
        QVector< QVector<int>> gameArray = m_Data.value(curLayer);// 下一层数据
        if(gameArray.isEmpty())
            continue;
        if(gameArray[row][column])
            FindCardToSetMask(row, column, curLayer, bInit, MODEB);
        if(layer % 2)
        {
            if(!bHorizon && row + 1 < NUM && gameArray[row + 1][column])
                FindCardToSetMask(row + 1, column, curLayer, bInit, MODEB);
            if(bHorizon && column + 1 < NUM && gameArray[row][column + 1])
                FindCardToSetMask(row, column + 1, curLayer, bInit, MODEB);
        }
        else
        {
            if(!bHorizon && row - 1 >= 0 && gameArray[row - 1][column])
                FindCardToSetMask(row - 1, column, curLayer, bInit, MODEB);
            if(bHorizon && column - 1 >= 0 && gameArray[row][column - 1])
                FindCardToSetMask(row, column - 1, curLayer, bInit, MODEB);
        }
    }


}

/* 下判断上
 * 偶数层下奇数层上: (1,1)被遮挡 水平(1,0)(1,1) 垂直(0,1)(1,1); (1,2)被遮挡 水平(0,2)(1,2) 垂直(1,1)(1,2)
 * 奇数层下偶数层上: (0,0)被遮挡 水平(0,0)(0,1) 垂直(0,0)(1,0); (0,1)被遮挡 水平(0,1)(0,2) 垂直(0,1)(1,1)
*/
bool PlayWidget::IsUpEnabledByModeB(int row, int column, int layer, bool bHorizon)
{
    for(int curLayer = layer+1; curLayer < m_Data.count(); curLayer+=2)
    {
        QVector< QVector<int>> upGameArray = m_Data.value(layer + 1);
        if(upGameArray.isEmpty())
            continue;

        if(upGameArray[row][column])
            return false;
        if(layer % 2 == 0)// 偶数层下奇数层上
        {
            if(!bHorizon && row - 1 >= 0 && upGameArray[row - 1][column])
                return false;
            if(bHorizon && column - 1 >= 0 && upGameArray[row][column - 1])
                return false;
        }
        else// 奇数层下偶数层上
        {
            if(!bHorizon && row + 1 < NUM && upGameArray[row + 1][column])
                return false;
            if(bHorizon && column + 1 < NUM && upGameArray[row][column + 1])
                return false;
        }
    }
    return true;
}

void PlayWidget::addCardSlot()
{
    m_clickMusic->stop();
    m_clickMusic->play();
    CardLabel *card = static_cast<CardLabel *>(sender());
    card->blockSignals(true);
    card->raise();
    int curLayer = card->getCardInfo()->layer;
    int curRow = card->getCardInfo()->row;
    int curColumn = card->getCardInfo()->column;
    int curType = card->getCardInfo()->type;
    int curMode = card->getCardInfo()->mode;
    bool bQuest = card->getCardInfo()->bQuestion;
    qDebug()<<"type:"<<curType;
    if(bQuest)
    {
        card->LoadNormalImg(curType);
    }
    if(curMode == MODEA)
    {
        QList<CardLabel *> cards = m_cardsModeA.value(qMakePair(curRow, curColumn));
        cards.removeOne(card);
        if(!cards.isEmpty())
        {
            CardLabel *cardNew = cards.last();
            cardNew->setMask(true);
            m_cardsModeA.insert(qMakePair(curRow, curColumn), cards);
        }
        else
            m_cardsModeA.remove(qMakePair(curRow, curColumn));

    }
    else if(curMode == MODEB)
    {
        QVector< QVector<int>> gameArray = m_Data.value(curLayer);
        gameArray[curRow][curColumn] = 0;
        m_Data.insert(curLayer, gameArray);
        if(curLayer > 0)
        {
            setEnabledByModeB(curRow, curColumn, curLayer, false);
        }
        m_cardsModeB.removeOne(card->getCardInfo());
    }
    else if(curMode == MODEC)
    {
        QVector< QVector<int>> gameArray = m_Data.value(curLayer);
        gameArray[curRow][curColumn] = 0;
        m_Data.insert(curLayer, gameArray);
        if(curLayer > 0)
        {
            setEnabledByModeC(curRow, curColumn, curLayer, false);
        }
        m_cardsModeC.removeOne(card->getCardInfo());
    }
    else if(curMode == MODEPEND)
    {
        int index = m_cardPending.indexOf(card);
        m_cardPending.removeOne(card);
        for(int i = index; i < m_cardPending.count(); i++)// 将右边的卡片左移
        {
            CardLabel *card = m_cardPending.at(i);
            QPoint pt = card->pos();
            pt.setX(pt.x() - WIDTH);
            card->animationMove(pt);
        }
    }

    int count = m_cardSlot.count();
    CardLabel *cardOne = nullptr;
    CardLabel *cardTwo = nullptr;
    QPoint ptNew = m_ptSlot;
    bool bInsert = false;
    if(m_stage == EasyLevel || m_stage == HardLevel)
    {
        for(int i = count; i > 0; i--)
        {
            CardLabel *cardIn = m_cardSlot.at(i-1);
            if(cardIn->getCardInfo()->type == curType)
            {
                bInsert = true;
                ptNew.setX(m_ptSlot.x() + i * WIDTH);// 插在该卡片后面
                m_cardSlot.insert(i, card);
                resizeCardsPos(i, RIGHT);
                cardOne = cardIn;
                if(i-2 >= 0)
                    cardTwo = m_cardSlot.at(i-2);
                break;
            }
        }
    }
    if(m_stage == MediumLevel || m_stage == InfernalLevel || !bInsert)
    {
        ptNew.setX(m_ptSlot.x() + count * WIDTH);// 插在最后面
        m_cardSlot.append(card);
        if(count >= 2)
        {
            cardOne = m_cardSlot.at(count - 1);
            cardTwo = m_cardSlot.at(count - 2);
        }
    }
    card->animationMove(ptNew);
    QTimer::singleShot(300, [=]() { Eliminate(card, cardOne, cardTwo); });// 等移动动画完毕后再消除

}

void PlayWidget::Eliminate(CardLabel *curCard, CardLabel *cardOne, CardLabel *cardTwo)
{
    if(cardOne && cardTwo && cardOne->getCardInfo()->type == cardTwo->getCardInfo()->type
        && cardTwo->getCardInfo()->type == curCard->getCardInfo()->type)
    {
        m_removeMusic->stop();
        m_removeMusic->play();
        int index = m_cardSlot.indexOf(curCard);
        m_cardSlot.removeOne(cardOne);
        m_cardSlot.removeOne(cardTwo);
        m_cardSlot.removeOne(curCard);
        delete cardOne;
        cardOne = nullptr;
        delete cardTwo;
        cardTwo = nullptr;
        curCard->deleteLater();
        RemoveAnimation(index);// 消除动画
        if(m_stage == EasyLevel || m_stage == HardLevel)
        {
            resizeCardsPos(index, LEFT);
        }
        if(m_cardSlot.isEmpty() && m_cardsModeC.isEmpty() && m_cardsModeA.isEmpty()
               && m_cardsModeB.isEmpty() && m_cardPending.isEmpty())
        {
            QTimer::singleShot(300, [=]() { popSuccessDialog(); });// 胜利弹窗
        }
    }
    else
    {
        if(m_cardsModeC.isEmpty() && m_cardsModeB.isEmpty() && m_cardsModeA.isEmpty() && m_cardPending.isEmpty())
        {
            QTimer::singleShot(300, [=]() { popFailDialog(); });// 失败弹窗
        }
    }
    if(m_cardSlot.count() == m_cardSlotCount)
    {
        QTimer::singleShot(300, [=]() { popFailDialog(); });// 失败弹窗
    }
}

void PlayWidget::resizeCardsPos(int index, int Direction)
{
    if(Direction == LEFT)// 消除后左移
    {
        if(index + 1 - 3 >= m_cardSlot.count())// 越界
            return;
        for(int i = index + 1 - 3; i < m_cardSlot.count(); i++)
        {
            CardLabel *card = m_cardSlot.at(i);
            QPoint pt = card->pos();
            pt.setX(pt.x() - 3*WIDTH);
            card->animationMove(pt);
        }
    }
    else if(Direction == RIGHT)// 插入后右移
    {
        for(int i = index; i < m_cardSlot.count(); i++)
        {
            CardLabel *card = m_cardSlot.at(i);
            card->raise();
            QPoint pt = card->pos();
            pt.setX(pt.x() + WIDTH);
            card->animationMove(pt);
        }
    }
}

void PlayWidget::popSuccessDialog()
{
    m_timer->stop();
    QMap<int, QString>::iterator it = m_leaderboard.find(m_level);
    if(it != m_leaderboard.end())
    {
        QString prevTime = it.value();
        if(QString::compare(m_time.toString(), prevTime) < 0)
            m_leaderboard.insert(m_level, m_time.toString());
    }
    else
        m_leaderboard.insert(m_level, m_time.toString());

    Dialog::DialogType dialogType;
    if(m_level == m_levelCount)// 通关
        dialogType = Dialog::Clearance;
    else// 过关
        dialogType = Dialog::Success;
    Dialog *dialog = new Dialog(nullptr, dialogType);
    int result = dialog->exec();
    emit sendHome(result);
}

void PlayWidget::popFailDialog()
{
    m_timer->stop();
    if(!m_FailCount)// 第一次失败
    {
        m_FailCount++;
        Dialog *dialog = new Dialog(nullptr, Dialog::Revive);
        int result = dialog->exec();
        if(result == Done)
        {
            m_timer->start();
            m_bRevive = true;
            propRemoveRsp();
        }
        else
            emit sendHome(Back);
    }
    else// 第二次失败
    {
        Dialog *dialog = new Dialog(nullptr, Dialog::Fail);
        dialog->exec();
        emit sendHome(Back);
    }
}

void PlayWidget::setRandomCards()
{
    if(m_cardCount > m_type*3)
    {
        setRandomCardsIsGreater(true);
        setRandomCardsIsGreater(false);
    }
    else
        setRandomCardsIsGreater(false);

    std::mt19937 gen(std::random_device{}());// std::random_device rd;
    std::shuffle(m_cardsType.begin(), m_cardsType.end(), gen);// 洗牌(打乱)
}

void PlayWidget::setRandomCardsIsGreater(bool greater)
{
    int pile =m_cardCount / (m_type*3);// 每种卡片有几堆(每3个为1堆)
    int num = m_cardCount > m_type*3 ? m_cardCount/3 - m_type*pile : m_cardCount/3;// (cardsCount - NUM*3*pile)/3
    int typeCount = greater ? m_type : num;// 种类数(有多少种类型)
    int echTypeCount = greater ? 3*pile : 3;// 每种类型的数量
    for(int type = 1; type <= typeCount; type++)
    {
        int count = 0;
        while(count < echTypeCount)// 每种类型的卡片数
        {
            m_cardsType.push_back(type);
            count++;
/*********************** 老方法, 随机坐标给值, 效率太低, 弃用 ******************************/
//            int layer = QRandomGenerator::global()->bounded(m_Data.count());
//            int row = QRandomGenerator::global()->bounded(NUM);// 产生0~8(不包括8)的随机整数
//            int column = QRandomGenerator::global()->bounded(NUM);
//            QVector< QVector<int>> gameArray = m_Data.value(layer);
//            if(gameArray[row][column] == 1)// 牌堆模式C
//            {
//                CardLabel *card = nullptr;
//                foreach(cardInfo *info, m_cardsModeC)
//                {
//                    if(info->row == row && info->column == column && info->layer == layer)
//                    {
//                        card = info->card;
//                        if(!card->getCardInfo()->type)// 该卡片还未赋予类型
//                        {
//                            card->setCardType(type);
//                            count++;
//                        }
//                        break;
//                    }
//                }
//                if(card == nullptr)// 牌堆模式A第一层
//                {
//                    QList<CardLabel *> cards = m_cardsModeA.value(qMakePair(row, column));
//                    CardLabel *card = cards.at(gameArray[row][column] - 1);
//                    m_Data.insert(layer, gameArray);
//                    if(!card->getCardInfo()->type)// 该卡片还未赋予类型
//                    {
//                        card->setCardType(type);
//                        count++;
//                    }
//                }
//            }
//            else if(gameArray[row][column] != 0 && gameArray[row][column] != 1)// 牌堆模式A
//            {
//                QList<CardLabel *> cards = m_cardsModeA.value(qMakePair(row, column));
//                CardLabel *card = cards.at(gameArray[row][column] - 1);
//                gameArray[row][column]--;
//                m_Data.insert(layer, gameArray);
//                if(!card->getCardInfo()->type)// 该卡片还未赋予类型
//                {
//                    card->setCardType(type);
//                    count++;
//                }
//            }
        }
    }
}

void PlayWidget::propRemoveRsp()
{
    if(m_bRevive)
    {
        m_bRevive = false;
        goto again;
    }
    if(m_RemoveCount == 0)
    {
        Dialog *dialog = new Dialog(this, Dialog::PropRemove);
        if(dialog->exec() == Done)
            m_btnRemove->setPropCount(QString::number(++m_RemoveCount));
        return;
    }
    m_btnRemove->setPropCount(QString::number(--m_RemoveCount));
    if(m_RemoveCount == 0)
        m_btnRemove->setMask(false);

    if(m_cardPending.count() >= 6)
        return;

again:
    for(int i = 0; i < 3; i++)
    {
        if(!m_cardSlot.isEmpty())
        {
            CardLabel *card = m_cardSlot.takeLast();
            card->setCardMode(MODEPEND);
            QPoint move = m_ptPend;
            move.setX(m_ptPend.x() + m_cardPending.count() * (10 + WIDTH));
            card->animationMove(move);
            card->m_ptInit = move;
            card->blockSignals(false);
            m_cardPending.append(card);
        }
    }
}

void PlayWidget::propRetractRsp()
{
    if(m_RetractCount == 0)
    {
        Dialog *dialog = new Dialog(this, Dialog::PropRetract);
        if(dialog->exec() == Done)
            m_btnRetract->setPropCount(QString::number(++m_RetractCount));
        return;

    }
    m_btnRetract->setPropCount(QString::number(--m_RetractCount));
    if(m_RetractCount == 0)
        m_btnRetract->setMask(false);

    if(m_cardSlot.isEmpty())
        return;
    CardLabel *card = m_cardSlot.takeLast();
    card->raise();
    card->animationMove(card->m_ptInit);
    card->blockSignals(false);
    int curLayer = card->getCardInfo()->layer;
    int curRow = card->getCardInfo()->row;
    int curColumn = card->getCardInfo()->column;
    int curMode = card->getCardInfo()->mode;
    if(curMode == MODEC)
    {
        if(curLayer > 0)
            setEnabledByModeC(curRow, curColumn, curLayer);// 将下一层被遮挡的卡片暗化
        QVector< QVector<int>> gameArray = m_Data.value(curLayer);
        if(card->m_ptInit.y() < PLACE + 8*WIDTH)// 判断撤回的位置是游戏区还是待定区
            gameArray[curRow][curColumn] = 1;
        m_Data.insert(curLayer, gameArray);
        m_cardsModeC.append(card->getCardInfo());
    }
    else if(curMode == MODEB)
    {
        if(curLayer > 0)
            setEnabledByModeB(curRow, curColumn, curLayer);// 将下一层被遮挡的卡片暗化
        QVector< QVector<int>> gameArray = m_Data.value(curLayer);
        if(card->m_ptInit.y() < PLACE + 8*WIDTH)// 判断撤回的位置是游戏区还是待定区
        {
            if(card->getCardInfo()->bHorizon)
                gameArray[curRow][curColumn] = 11;
            else
                gameArray[curRow][curColumn] = 12;
        }
        m_Data.insert(curLayer, gameArray);
        m_cardsModeB.append(card->getCardInfo());
    }
    else if(curMode == MODEA)
    {
        QList<CardLabel *> cards = m_cardsModeA.value(qMakePair(curRow, curColumn));
        if(!cards.isEmpty())// 将下一层被遮挡的卡片暗化
            cards.last()->setMask(false);
        cards.append(card);
        m_cardsModeA.insert(qMakePair(curRow, curColumn), cards);
    }
}

void PlayWidget::propShuffleRsp()
{
    if(m_ShuffleCount == 0)
    {
        Dialog *dialog = new Dialog(this, Dialog::PropShuffle);
        if(dialog->exec() == Done)
            m_btnShuffle->setPropCount(QString::number(++m_ShuffleCount));
        return;

    }
    m_btnShuffle->setPropCount(QString::number(--m_ShuffleCount));
    if(m_ShuffleCount == 0)
        m_btnShuffle->setMask(false);

    if(!m_waitDialog)// 洗牌动画
        m_waitDialog = new WaitingDialog(this);
    m_waitDialog->Start();

    m_restCardsType.clear();
    ShuffleCards(true);// 取当前所有卡片的类型
    std::mt19937 gen(std::random_device{}());// std::random_device rd;
    std::shuffle(m_restCardsType.begin(), m_restCardsType.end(), gen);// 洗牌(打乱)
    ShuffleCards(false);// 重新赋予当前所有卡片类型
}

void PlayWidget::ShuffleCards(bool bGet)
{
    int index = 0;
    foreach(cardInfo *info, m_cardsModeC)
    {
        if(bGet)
            m_restCardsType.push_back(info->type);
        else
        {
            if(index < m_restCardsType.size())
                info->card->setCardType(m_restCardsType.at(index++));
        }

    }
    foreach(cardInfo *info, m_cardsModeB)
    {
        if(bGet)
            m_restCardsType.push_back(info->type);
        else
        {
            if(index < m_restCardsType.size())
                info->card->setCardType(m_restCardsType.at(index++));
        }

    }
    for(auto it = m_cardsModeA.begin(); it != m_cardsModeA.end(); it++)
    {
        QList<CardLabel *> cards = it.value();
        foreach(CardLabel *card, cards)
        {
            if(bGet)
                m_restCardsType.push_back(card->getCardInfo()->type);
            else
            {
                if(index < m_restCardsType.size())
                    card->setCardType(m_restCardsType.at(index++));
            }

        }
    }
    foreach(CardLabel *card, m_cardPending)
    {
        if(bGet)
            m_restCardsType.push_back(card->getCardInfo()->type);
        else
        {
            if(index < m_restCardsType.size())
                card->setCardType(m_restCardsType.at(index++));
        }
    }
}

void PlayWidget::RemoveAnimation(int index)
{
    if(m_flickerList.isEmpty())
    {
        for(int i = 0; i < NUM - 1; i++)
        {
            QLabel *flicker = new QLabel(this);
            QPoint ptNew = m_ptSlot;
            ptNew.setX(m_ptSlot.x() + i * WIDTH);
            QRect rt = QRect(ptNew, QSize(48, 48));
            flicker->setGeometry(rt);
            flicker->setPixmap(QPixmap(":/res/flash.png"));
            flicker->setVisible(false);
            m_flickerList.append(flicker);
        }
    }
    if(!m_flickerTimer)
    {
        m_flickerTimer = new QTimer(this);
        m_flickerTimer->setInterval(200);
    }

    int tmpIndex = index;
    for(int i = 0; i < 3; i++)
    {
        if(tmpIndex < m_flickerList.count())
        {
            QLabel *flicker = m_flickerList.at(tmpIndex--);
            flicker->setVisible(true);
        }
    }

    disconnect(m_flickerTimer, &QTimer::timeout, 0, 0);
    connect(m_flickerTimer, &QTimer::timeout, this, [this, index]()
    {
        int tmpIndex = index;
        for(int i = 0; i < 3; i++)
        {
            if(tmpIndex < m_flickerList.count())
            {
                QLabel *flicker = m_flickerList.at(tmpIndex--);
                flicker->setVisible(false);
            }
        }
        if (m_flickerTimer->isActive())
            m_flickerTimer->stop();
    });
    if (m_flickerTimer->isActive())
        m_flickerTimer->stop();
    m_flickerTimer->start();
}

void PlayWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(rect(), QColor(255, 255, 255));
//    QRect target(0, 0, width(), height());
//    painter.drawPixmap(target, QPixmap(":/res/PlaySceneBg.png").scaled(width(), height()));

    // 卡槽
//    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine));
//    QBrush brush;
//    brush.setColor(QColor(61, 57, 47, 200));
//    brush.setStyle((Qt::SolidPattern));// 密集
//    painter.setBrush(brush);
//    int RADIUS = 5;
//    QRect rt = QRect(m_ptSlot, QSize(WIDTH*NUM, WIDTH));
//    painter.drawRoundedRect(rt, RADIUS, RADIUS);

    QPoint pt = m_ptSlot;
    pt.setY(m_ptSlot.y() - 5);
    pt.setX(m_ptSlot.x() - 6);
    painter.drawPixmap(pt, QPixmap(":/res/Cardslot.png"));

    QWidget::paintEvent(event);
}

void PlayWidget::InitGame(Stage degree, int level, int types)
{
    m_type = types;
    m_stage = degree;
    m_level = level;

    foreach(cardInfo *info, m_cardsModeC)
    {
        CardLabel * card = info->card;
        delete card;
        card = nullptr;
    }
    m_cardsModeC.clear();

    foreach(cardInfo *info, m_cardsModeB)
    {
        CardLabel * card = info->card;
        delete card;
        card = nullptr;
    }
    m_cardsModeB.clear();

    for(auto it = m_cardsModeA.begin(); it != m_cardsModeA.end(); it++)
    {
        QList<CardLabel *> cards = it.value();
        foreach(CardLabel *card, cards)
        {
            delete card;
            card = nullptr;
        }
    }
    m_cardsModeA.clear();

    foreach(CardLabel *card, m_cardSlot)
    {
        delete card;
        card = nullptr;
    }
    m_cardSlot.clear();

    foreach(CardLabel *card, m_cardPending)
    {
        delete card;
        card = nullptr;
    }
    m_cardPending.clear();
    m_cardsType.clear();
    m_restCardsType.clear();
    m_Data.clear();

    if(!m_bCheat)
    {
        m_RemoveCount = 0;
        m_RetractCount = 0;
        m_ShuffleCount = 0;
        m_btnRemove->setMask(true);
        m_btnRetract->setMask(true);
        m_btnShuffle->setMask(true);
        m_btnRemove->setPropCount("+");
        m_btnRetract->setPropCount("+");
        m_btnShuffle->setPropCount("+");
    }
    else
    {
        m_btnRemove->setPropCount(QString::number(m_RemoveCount));
        m_btnRetract->setPropCount(QString::number(m_RetractCount));
        m_btnShuffle->setPropCount(QString::number(m_ShuffleCount));
    }

    m_FailCount = 0;
    m_bRevive = false;
    m_levelDisplay->setText(QString("Level:%1").arg(m_level));

    ResetTimer();
    Init();

}

void PlayWidget::Cheat()
{
    m_bCheat = true;
    m_btnRemove->setMask(true);
    m_btnRetract->setMask(true);
    m_btnShuffle->setMask(true);
    m_RemoveCount = 99;
    m_RetractCount = 99;
    m_ShuffleCount = 99;
    m_btnRemove->setPropCount(QString::number(m_RemoveCount));
    m_btnRetract->setPropCount(QString::number(m_RetractCount));
    m_btnShuffle->setPropCount(QString::number(m_ShuffleCount));
}

void PlayWidget::AddOneSlot()
{
    m_btnAddSlot->setVisible(false);
    m_cardSlotCount = NUM;
}

void PlayWidget::InitQCards(int size)
{
    int count = 0;
    while(count < size)
    {
        int layer = QRandomGenerator::global()->bounded(m_Data.count());
        int row = QRandomGenerator::global()->bounded(NUM);// 产生0~8(不包括8)的随机整数
        int column = QRandomGenerator::global()->bounded(NUM);
        QVector< QVector<int>> gameArray = m_Data.value(layer);
        int num = gameArray[row][column];
        QList<cardInfo *> cards;
        if(num == 0 ||(num > 1 && num < 10))
            continue;
        else if(num == 1)
            cards = m_cardsModeC;
        else if(num > 10)
            cards = m_cardsModeB;

        foreach(cardInfo *info, cards)
        {
            if(info->row == row && info->column == column && info->layer == layer)
            {
                CardLabel *card = info->card;
                card->LoadNormalImg(QUESTION);
                count++;
                break;
            }
        }
    }
}

