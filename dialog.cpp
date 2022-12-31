#include "dialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <QToolTip>
#include <QListView>
#include "mainwindow.h"

Dialog::Dialog(QWidget *parent, DialogType type) :
    QDialog(parent),
    m_bVolume(true),
    m_type(type),
    m_pWidget(nullptr),
    m_pBtnVolume(nullptr),
    m_pBtnAbout(nullptr),
    m_pBtnCheat(nullptr),
    m_pBtnReward(nullptr),
    m_pBtnGiveup(nullptr),
    m_pBtnRestart(nullptr),
    m_pInfoAbout(nullptr),
    m_pLineCheat(nullptr),
    m_pListWidget(nullptr),
    m_pLineLevel(nullptr),
    m_pLineType(nullptr),
    m_pStage(nullptr)
{
    this->setFixedSize(320, 490);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::X11BypassWindowManagerHint);
    setAttribute(Qt::WA_TranslucentBackground, true);
    m_pWidget = new QLabel(this);
    m_pTitle = new QLabel(this);
    m_pBtnClose = new QPushButton(this);
    m_pPic = new QLabel;
    m_pInfo = new QLabel;
    m_pBtnFirst = new QPushButton;
    m_pBtnSecond = new QPushButton;

    for(int i = 0; i <= 1; i++)// 一个对象只能作用于一个部件
    {
        QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();//阴影边框效果
        shadow->setBlurRadius(10);
        shadow->setColor(Qt::black);
        shadow->setOffset(0);// 阴影偏移值
        if(i == 0)
            m_pBtnFirst->setGraphicsEffect(shadow);
        else if(i == 1)
            m_pBtnSecond->setGraphicsEffect(shadow);
    }

    m_pWidget->setObjectName("widget");
    m_pTitle->setObjectName("title");
    m_pPic->setObjectName("pic");
    m_pInfo->setObjectName("info");
    m_pBtnClose->setObjectName("close");

    connect(m_pBtnSecond, &QPushButton::clicked, this, [this]()
    {
        this->done(Back);
    });
    connect(m_pBtnClose, &QPushButton::clicked, this, [this]()
    {
        this->done(Close);
    });
    if(m_type == AddCardSlot)
    {
        connect(m_pBtnFirst, &QPushButton::clicked, this, [this]()
        {
            MainWindow::getPlayWidget()->m_bAddOneSlot = true;
            Dialog *dialog = new Dialog(this, Dialog::Cheat);
            dialog->exec();
            this->done(Done);
        });
    }
    else if(m_type == Custom)
    {
        connect(m_pBtnFirst, &QPushButton::clicked, this, [this]()
        {
            if(m_pLineLevel->text().isEmpty())
            {
                m_pLineLevel->setFocus();
                QToolTip::showText(m_pLineLevel->mapToGlobal(QPoint(0, 0)), LoadStringFromID(IDS_CUSTOM_EMPTY));
                return;
            }
            if(m_pLineType->text().isEmpty())
            {
                m_pLineLevel->setFocus();
                QToolTip::showText(m_pLineLevel->mapToGlobal(QPoint(0, 0)), LoadStringFromID(IDS_CUSTOM_EMPTY));
                return;
            }
            int typeNum = m_pLineType->text().toInt();
            if(typeNum < 2 || typeNum > 16)
            {
                m_pLineType->setFocus();
                QToolTip::showText(m_pLineType->mapToGlobal(QPoint(0, 0)), LoadStringFromID(IDS_CUSTOM_RANGE));
                return;
            }
            int levelNum = m_pLineLevel->text().toInt();
            if(levelNum < 1 || levelNum > 30)
            {
                m_pLineLevel->setFocus();
                QToolTip::showText(m_pLineLevel->mapToGlobal(QPoint(0, 0)), LoadStringFromID(IDS_CUSTOM_RANGE));
                return;
            }
            this->done(Done);
        });
    }
    else
    {
        connect(m_pBtnFirst, &QPushButton::clicked, this, [this]()
        {
            this->done(Done);
        });
    }

    if(m_type == About)
    {
        m_pBtnFirst->setEnabled(false);
        m_pBtnSecond->setEnabled(false);
    }
    else if(m_type == Reward || m_type == Clearance)
        m_pBtnFirst->setVisible(false);
    else if(m_type == Easy || m_type == Medium || m_type == Hard || m_type == Infernal)
        m_pBtnSecond->setVisible(false);
    else if(m_type == Fail)
        m_pBtnFirst->setEnabled(false);

    m_pTitle->setGeometry(width()/2 - 80, 0, 160, 50);
    m_pTitle->raise();
    m_pTitle->setAlignment(Qt::AlignCenter);
    m_pBtnClose->move(width() - 45, 10);
    m_pBtnClose->raise();
    m_pInfo->setWordWrap(true);
    m_pInfo->setAlignment(Qt::AlignCenter);
    m_pWidget->setGeometry(20, 20, 280, 430);

    LoadNormalImg(type);
    setTitleText(type);
    setInfoText(type);
    setBtnFirstText(type);
    setBtnSecondText(type);

    switch (type){
    case PropRemove:
    case PropRetract:
    case PropShuffle:
    case Reward:
    case About:
    case Giveup:
    case Restart:
    case Success:
    case Revive:
    case Fail:
    case Easy:
    case Medium:
    case Hard:
    case Infernal:
    case AddCardSlot:
    case Clearance:
        InitNormalDialog();
        break;
    case Setting:
    case SettingGame:
        InitSettingDialog();
        break;
    case Cheat:
        InitCheatDialog();
        break;
    case CheatSuccess:
    case AddSlotSuccess:
    case CheatFail:
        InitCheatConfirmDialog();
        break;
    case Leaderboard:
        InitLeaderboardDialog();
        break;
    case Custom:
        InitCustomDialog();
        break;
    }

    setStyle();
}

void Dialog::InitNormalDialog()
{
    QHBoxLayout *picLayout = new QHBoxLayout;
    picLayout->addStretch(1);
    picLayout->addWidget(m_pPic);
    picLayout->addStretch(1);

    QHBoxLayout *btnFirstLayout = new QHBoxLayout;
    btnFirstLayout->addStretch(1);
    btnFirstLayout->addWidget(m_pBtnFirst);
    btnFirstLayout->addStretch(1);

    QHBoxLayout *btnSecondLayout = new QHBoxLayout;
    btnSecondLayout->addStretch(1);
    btnSecondLayout->addWidget(m_pBtnSecond);
    btnSecondLayout->addStretch(1);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(picLayout);
    mainLayout->addWidget(m_pInfo);
    if(m_type == About)
        mainLayout->addWidget(m_pInfoAbout);
    mainLayout->addLayout(btnFirstLayout);
    mainLayout->addLayout(btnSecondLayout);
    mainLayout->setSpacing(15);
    mainLayout->setContentsMargins(12, 40, 12, 15);
    mainLayout->setAlignment(Qt::AlignHCenter);
    m_pWidget->setLayout(mainLayout);
}

void Dialog::InitSettingDialog()
{
    m_pInfoAbout = new QLabel;
    m_pInfoAbout->setObjectName("info");
    m_pInfoAbout->setWordWrap(true);
    m_pInfoAbout->setAlignment(Qt::AlignCenter);
    m_pInfoAbout->setText(LoadStringFromID(IDS_INFO_ABOUT));
    m_pBtnVolume = new QPushButton;
    m_pBtnAbout = new QPushButton;
    m_pBtnCheat = new QPushButton;
    m_pBtnReward = new QPushButton;
    m_pBtnGiveup = new QPushButton;
    m_pBtnRestart = new QPushButton;
    for(int i = 0; i <= 5; i++)// 一个对象只能作用于一个部件
    {
        QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();//阴影边框效果
        shadow->setBlurRadius(10);
        shadow->setColor(Qt::black);
        shadow->setOffset(0);// 阴影偏移值
        if(i == 0)
            m_pBtnVolume->setGraphicsEffect(shadow);
        else if(i == 1)
            m_pBtnAbout->setGraphicsEffect(shadow);
        else if(i == 2)
            m_pBtnCheat->setGraphicsEffect(shadow);
        else if(i == 3)
            m_pBtnReward->setGraphicsEffect(shadow);
        else if(i == 4)
            m_pBtnGiveup->setGraphicsEffect(shadow);
        else if(i == 5)
            m_pBtnRestart->setGraphicsEffect(shadow);
    }
    m_pBtnVolume->setText(LoadStringFromID(IDS_SET_VOLUME));
    m_pBtnAbout->setText(LoadStringFromID(IDS_SET_ABOUT));
    m_pBtnCheat->setText(LoadStringFromID(IDS_TITLE_CHEATCODE));
    m_pBtnReward->setText(LoadStringFromID(IDS_SET_REWARD));
    m_pBtnGiveup->setText(LoadStringFromID(IDS_FIRST_GIVEUP));
    m_pBtnRestart->setText(LoadStringFromID(IDS_FIRST_RESTART));
    connect(m_pBtnVolume, &QPushButton::clicked, this, &Dialog::onBtnVolumeRsp);
    connect(m_pBtnAbout, &QPushButton::clicked, this, &Dialog::onBtnAboutRsp);
    connect(m_pBtnCheat, &QPushButton::clicked, this, &Dialog::onBtnCheatRsp);
    connect(m_pBtnReward, &QPushButton::clicked, this, &Dialog::onBtnRewardRsp);
    connect(m_pBtnGiveup, &QPushButton::clicked, this, &Dialog::onBtnGiveupRsp);
    connect(m_pBtnRestart, &QPushButton::clicked, this, &Dialog::onBtnRestartRsp);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(m_pBtnVolume);
    if(m_type == Setting)
        mainLayout->addWidget(m_pBtnAbout);
    mainLayout->addWidget(m_pBtnCheat);
    if(m_type == Setting)
        mainLayout->addWidget(m_pBtnReward);
    else if(m_type == SettingGame)
    {
        mainLayout->addWidget(m_pBtnGiveup);
        mainLayout->addWidget(m_pBtnRestart);
    }
    mainLayout->setSpacing(30);
    mainLayout->setContentsMargins(30, 40, 30, 15);
    mainLayout->setAlignment(Qt::AlignHCenter);
    m_pWidget->setLayout(mainLayout);
}

void Dialog::InitCheatDialog()
{
    m_pLineCheat = new QLineEdit;
    connect(m_pBtnFirst, &QPushButton::clicked, this, &Dialog::onBtnCheatOKRsp);
    m_pWidget->setGeometry(30, 200, 260, 150);
    m_pTitle->move(width()/2 - 80, 180);
    m_pBtnClose->move(width() - 55, 190);
    QHBoxLayout *btnLayout = new QHBoxLayout;
    btnLayout->addStretch(1);
    btnLayout->addWidget(m_pBtnFirst);
    btnLayout->addStretch(1);
    btnLayout->addWidget(m_pBtnSecond);
    btnLayout->addStretch(1);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(m_pLineCheat);
    mainLayout->addLayout(btnLayout);
    mainLayout->setSpacing(15);
    mainLayout->setContentsMargins(15, 40, 15, 10);
    m_pWidget->setLayout(mainLayout);
}

void Dialog::InitCheatConfirmDialog()
{
    m_pWidget->setGeometry(30, 200, 260, 180);
    m_pTitle->move(width()/2 - 80, 180);
    m_pBtnClose->move(width() - 55, 190);
    QHBoxLayout *btnLayout = new QHBoxLayout;
    btnLayout->addStretch(1);
    btnLayout->addWidget(m_pBtnSecond);
    btnLayout->addStretch(1);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(m_pInfo);
    mainLayout->addLayout(btnLayout);
    mainLayout->setSpacing(15);
    mainLayout->setContentsMargins(15, 40, 15, 10);
    m_pWidget->setLayout(mainLayout);
}

void Dialog::InitLeaderboardDialog()
{
    QMap<int, QString> leaderboard = MainWindow::getPlayWidget()->getLeaderboard();
    m_pListWidget = new TimeListWidget(leaderboard);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(m_pListWidget);
    mainLayout->setContentsMargins(0, 30, 0, 0);
    m_pWidget->setLayout(mainLayout);
}

void Dialog::InitCustomDialog()
{
    m_pLineLevel = new QLineEdit;
    m_pLineType = new QLineEdit;
    m_pStage = new CustomComboBox;
    m_pLineLevel->setFixedHeight(35);
    m_pLineType->setFixedHeight(35);
    m_pLineLevel->setText(QString::number(1));
    m_pLineLevel->setValidator(new QIntValidator(1, 30, this));
    m_pLineType->setText(QString::number(8));
    m_pLineType->setValidator(new QIntValidator(1, 16, this));
    m_pStage->addItem(LoadStringFromID(IDS_CUSTOM_INSERT));
    m_pStage->addItem(LoadStringFromID(IDS_CUSTOM_ADDEND));
    m_pStage->setCurrentIndex(0);
    QFont ft;
    ft.setPixelSize(19);
    ft.setBold(true);
    QLabel *pLevel = new QLabel;
    QLabel *pType = new QLabel;
    QLabel *pStage = new QLabel;
    pLevel->setFont(ft);
    pType->setFont(ft);
    pStage->setFont(ft);
    pLevel->setText(LoadStringFromID(IDS_CUSTOM_LEVEL));
    pType->setText(LoadStringFromID(IDS_CUSTOM_TYPES));
    pStage->setText(LoadStringFromID(IDS_CUSTOM_STAGE));
    QHBoxLayout *picLayout = new QHBoxLayout;
    picLayout->addStretch(1);
    picLayout->addWidget(m_pPic);
    picLayout->addStretch(1);

    QGridLayout *ChooseLayout = new QGridLayout;
    ChooseLayout->addWidget(pLevel, 0, 0, 1, 1);
    ChooseLayout->addWidget(m_pLineLevel, 0, 1, 1, 1);
    ChooseLayout->addWidget(pType, 1, 0, 1, 1);
    ChooseLayout->addWidget(m_pLineType, 1, 1, 1, 1);
    ChooseLayout->addWidget(pStage, 2, 0, 1, 1);
    ChooseLayout->addWidget(m_pStage, 2, 1, 1, 1);
    ChooseLayout->setHorizontalSpacing(0);

    QHBoxLayout *btnFirstLayout = new QHBoxLayout;
    btnFirstLayout->addStretch(1);
    btnFirstLayout->addWidget(m_pBtnFirst);
    btnFirstLayout->addStretch(1);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(picLayout);
    mainLayout->addLayout(ChooseLayout);
    mainLayout->addLayout(btnFirstLayout);

    mainLayout->setSpacing(15);
    mainLayout->setContentsMargins(12, 40, 12, 15);
    mainLayout->setAlignment(Qt::AlignHCenter);
    m_pWidget->setLayout(mainLayout);
}

void Dialog::setStyle()
{
    QStringList qss;
    qss.append(QString("QLabel#widget{"
                       "border-top: 5px solid  #000000;"
                       "border-left: 5px solid  #000000;"
                       "border-right: 5px solid #000000;"
                       "border-bottom: 5px solid #000000;"
                       "border-radius: 8px;"
                       "background-color:#ffffff;}"));
    m_pWidget->setStyleSheet(qss.join(""));

    qss.clear();
    qss.append(QString("QLabel#title{"
                       "border-radius: 8px;"
                       "font-size: 19px;"
                       "font-weight:bold;"
                       "color: #D7D749;"
                       "background-color:#000000;}"));
    m_pTitle->setStyleSheet(qss.join(""));

    qss.clear();
    int picSize;
    if(m_type == About)
        picSize = 100;
    else
        picSize = 150;
    qss.append(QString("QLabel#pic{"
                       "min-width: %1px;"
                       "max-width: %1px;"
                       "min-height: %1px;"
                       "max-height: %1px;"
                       "border-radius: 75px;"
                       "background-color:#000000;}").arg(picSize));
    m_pPic->setStyleSheet(qss.join(""));
    if(m_type == Success || m_type == Revive || m_type == Fail)
        m_pPic->setStyleSheet("");

    qss.clear();
    int infoSize;
    if(m_type == About)
    {
        infoSize = 17;
        qss.append("QLabel#info{font-weight:bold;}");
    }
    else
        infoSize = 20;
    qss.append(QString("QLabel#info{"
                       "font-size: %1px;"
                       "color:#000000;}").arg(infoSize));

    m_pInfo->setStyleSheet(qss.join(""));
    if(m_pInfoAbout)
        m_pInfoAbout->setStyleSheet(qss.join(""));

    qss.clear();
    QSize btnSize;
    if(m_type == About)
        btnSize = QSize(190, 30);
    else if(m_type == Cheat || m_type == CheatSuccess || m_type == CheatFail || m_type == AddSlotSuccess)
        btnSize = QSize(80, 35);
    else
        btnSize = QSize(190, 50);
    qss.append(QString("QPushButton{"
                       "width: %1px;"
                       "height: %2px;"
                       "border-top: 3px solid  #000000;"
                       "border-left: 3px solid  #000000;"
                       "border-right: 3px solid #000000;"
                       "border-bottom: 3px solid #000000;"
                       "border-radius: 8px;"
                       "color: #000000;"
                       "background-color:#ffffff;"
                       "font-size: 24px;"
                       "font-weight:bold}").arg(btnSize.width()).arg(btnSize.height()));
    qss.append(QString("QPushButton:hover{"
                       "outline: none;"
                       "background-color: #DCE8F6;}"));
    qss.append(QString("QPushButton:pressed{"
                       "margin: 1px;"
                       "background-color: #DCE8F6;}"));
    qss.append(QString("QPushButton:disabled{"
                       "color: #a0a0a0;"
                       "background-color: #d4d7d7;}"));
    if(m_pBtnAbout)
        m_pBtnAbout->setStyleSheet(qss.join(""));
    if(m_pBtnCheat)
        m_pBtnCheat->setStyleSheet(qss.join(""));
    if(m_pBtnReward)
        m_pBtnReward->setStyleSheet(qss.join(""));
    if(m_pBtnGiveup)
        m_pBtnGiveup->setStyleSheet(qss.join(""));
    if(m_pBtnRestart)
        m_pBtnRestart->setStyleSheet(qss.join(""));
    m_pBtnSecond->setStyleSheet(qss.join(""));
    m_pBtnFirst->setStyleSheet(qss.join(""));

    qss.append(QString("QPushButton{"
                       "background-image: url(:/res/volume_open.png);"
                       "background-origin: content;"
                       "background-position: left;"
                       "padding-left: 15px;"
                       "background-repeat: no-repeat;"
                       "text-align: right;"
                       "padding-right: 30px;}"));
    if(m_pBtnVolume)
        m_pBtnVolume->setStyleSheet(qss.join(""));

    qss.clear();
    qss.append(QString("QPushButton#close{"
                       "min-width: 42px;"
                       "max-width: 42px;"
                       "min-height: 42px;"
                       "max-height: 42px;"
                       "border-radius: 21px;"
                       "background-color:#000000;"
                       "image: url(:/res/closebutton.svg);}"));
    m_pBtnClose->setStyleSheet(qss.join(""));

    qss.clear();
    qss.append(QString("QLineEdit{"
                       "font-size: 22px;"
                       "border-left: 2px solid  #b3b3b3;"
                       "border-top: 2px solid  #b3b3b3;"
                       "border-right:2px solid #b3b3b3;"
                       "border-bottom:2px solid #b3b3b3;"
                       "border-radius: 5px;"
                       "background: #f6f7f8;}"));
    qss.append(QString("QLineEdit:hover,QLineEdit:focus{"
                       "border-left: 2px solid  #666666;"
                       "border-top: 2px solid  #666666;"
                       "border-right:2px solid #666666;"
                       "border-bottom:2px solid #666666;"
                       "border-radius: 5px;"
                       "background: #f6f7f8;}"));
    if(m_pLineCheat)
        m_pLineCheat->setStyleSheet(qss.join(""));
    if(m_pLineType)
        m_pLineType->setStyleSheet(qss.join(""));
    if(m_pLineLevel)
        m_pLineLevel->setStyleSheet(qss.join(""));
}

void Dialog::LoadNormalImg(DialogType type)
{
    QString path;
    switch (type){
    case PropRemove:
        path = ":/res/Remove.svg";
        break;
    case PropRetract:
        path = ":/res/retract.svg";
        break;
    case PropShuffle:
        path = ":/res/shuffleCards.svg";
        break;
    case About:
        path = ":/res/about.png";
        break;
    case Reward:
        path = ":/res/qrcode.png";
        break;
    case Giveup:
        path = ":/res/giveup.svg";
        break;
    case Restart:
        path = ":/res/restart.svg";
        break;
    case Success:
        path = ":/res/success.svg";
        break;
    case Revive:
        path = ":/res/heart.svg";
        break;
    case Fail:
        path = ":/res/fail.svg";
        break;
    case Easy:
        path = ":/res/easy.svg";
        break;
    case Medium:
        path = ":/res/medium.svg";
        break;
    case Hard:
        path = ":/res/hard.svg";
        break;
    case Infernal:
        path = ":/res/infernal.svg";
        break;
    case Custom:
        path = ":/res/custom.svg";
        break;
    case AddCardSlot:
        path = ":/res/addslot.svg";
        break;
    }
    QPixmap *pixmap = new QPixmap(path);
    pixmap->scaled(m_pPic->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    m_pPic->setScaledContents(true);
    m_pPic->setPixmap(*pixmap);
}

void Dialog::setTitleText(DialogType type)
{
    QString text = "";
    switch (type){
    case PropRemove:
        text = LoadStringFromID(IDS_TITLE_REMOVE);
        break;
    case PropRetract:
        text = LoadStringFromID(IDS_TITLE_RETRACT);
        break;
    case PropShuffle:
        text = LoadStringFromID(IDS_TITLE_SHUFFLE);
        break;
    case Setting:
    case SettingGame:
        text = LoadStringFromID(IDS_TITLE_SETTING);
        break;
    case About:
        text = LoadStringFromID(IDS_TITLE_APPNAME);
        break;
    case Cheat:
        text = LoadStringFromID(IDS_TITLE_CHEATCODE);
        break;
    case CheatSuccess:
    case AddSlotSuccess:
    case Success:
    case Clearance:
        text = LoadStringFromID(IDS_TITLE_CONGRA);
        break;
    case CheatFail:
        text = LoadStringFromID(IDS_TITLE_ERROR);
        break;
    case Reward:
        text = LoadStringFromID(IDS_TITLE_REWARD);
        break;
    case Giveup:
        text = LoadStringFromID(IDS_TITLE_SURE);
        break;
    case Restart:
        text = LoadStringFromID(IDS_TITLE_RESTART);
        break;
    case Revive:
    case Fail:
        text = LoadStringFromID(IDS_TITLE_RESTART);
        break;
    case Easy:
        text = LoadStringFromID(IDS_TITLE_EASY);
        break;
    case Medium:
        text = LoadStringFromID(IDS_TITLE_MEDIUM);
        break;
    case Hard:
        text = LoadStringFromID(IDS_TITLE_HARD);
        break;
    case Infernal:
        text = LoadStringFromID(IDS_TITLE_INFERNAL);
        break;
    case Custom:
        text = LoadStringFromID(IDS_LEVEL_CUSTOM);
        break;
    case AddCardSlot:
        text = LoadStringFromID(IDS_TITLE_ADD);
        break;
    case Leaderboard:
        text = LoadStringFromID(IDS_TITLE_BOARD);
        break;
    }
    m_pTitle->setText(text);
}

void Dialog::setInfoText(DialogType type)
{
    QString text = "";
    switch (type){
    case PropRemove:
        text = LoadStringFromID(IDS_INFO_REMOVE);
        break;
    case PropRetract:
        text = LoadStringFromID(IDS_INFO_RETRACT);
        break;
    case PropShuffle:
        text = LoadStringFromID(IDS_INFO_SHUFFLE);
        break;
    case About:
        text = LoadStringFromID(IDS_INFO_INTRO);
        break;
    case CheatSuccess:
        text = LoadStringFromID(IDS_INFO_CHEATSUC);
        break;
    case AddSlotSuccess:
        text = LoadStringFromID(IDS_INFO_ADDSUC);
        break;
    case CheatFail:
        text = LoadStringFromID(IDS_INFO_FAIL);
        break;
    case Reward:
        text = LoadStringFromID(IDS_INFO_REWARD);
        break;
    case Giveup:
        text = LoadStringFromID(IDS_INFO_GIVEUP);
        break;
    case Restart:
        text = LoadStringFromID(IDS_INFO_RESTART);
        break;
    case Success:
        text = LoadStringFromID(IDS_INFO_SUC);
        break;
    case Revive:
        text = LoadStringFromID(IDS_INFO_REVIVE);
        break;
    case Fail:
        text = LoadStringFromID(IDS_INFO_FAIL);
        break;
    case Easy:
        text = LoadStringFromID(IDS_INFO_EASY);
        break;
    case Medium:
        text = LoadStringFromID(IDS_INFO_MEDIUM);
        break;
    case Hard:
        text = LoadStringFromID(IDS_INFO_HARD);
        break;
    case Infernal:
        text = LoadStringFromID(IDS_INFO_INFERNAL);
        break;
    case AddCardSlot:
        text = LoadStringFromID(IDS_INFO_ADD);
        break;
    case Clearance:
        text = LoadStringFromID(IDS_INFO_CLEARANCE);
        break;

    }
    m_pInfo->setText(text);
}

void Dialog::setBtnFirstText(DialogType type)
{
    QString text = "";
    switch (type){
    case PropRemove:
    case PropRetract:
    case PropShuffle:
    case AddCardSlot:
        text = LoadStringFromID(IDS_FIRST_PROP);
        break;
    case About:
        text = LoadStringFromID(IDS_FIRST_ABOUT);
        break;
    case Cheat:
        text = LoadStringFromID(IDS_FIRST_OK);
        break;
    case Giveup:
        text = LoadStringFromID(IDS_FIRST_GIVEUP);
        break;
    case Restart:
        text = LoadStringFromID(IDS_FIRST_RESTART);
        break;
    case Success:
        text = LoadStringFromID(IDS_FIRST_NEXT);
        break;
    case Revive:
        text = LoadStringFromID(IDS_FIRST_REVIVE);
        break;
    case Fail:
        text = LoadStringFromID(IDS_FIRST_FAIL);
        break;
    case Easy:
    case Medium:
    case Hard:
    case Infernal:
    case Custom:
        text = LoadStringFromID(IDS_FIRST_START);
        break;
    }
    m_pBtnFirst->setText(text);
}

void Dialog::setBtnSecondText(DialogType type)
{
    QString text = "";
    switch (type){
    case PropRemove:
    case PropRetract:
    case PropShuffle:
    case AddCardSlot:
        text = LoadStringFromID(IDS_SECOND_PROP);
        break;
    case About:
        text = LoadStringFromID(IDS_SECOND_ABOUT);
        break;
    case Cheat:
        text = LoadStringFromID(IDS_SECOND_CANCEL);
        break;
    case CheatSuccess:
    case AddSlotSuccess:
    case CheatFail:
    case Reward:
        text = LoadStringFromID(IDS_FIRST_OK);
        break;
    case Giveup:
    case Restart:
        text = LoadStringFromID(IDS_SECOND_RESTART);
        break;
    case Success:
    case Revive:
    case Fail:
    case Easy:
    case Medium:
    case Hard:
    case Infernal:
    case Clearance:
        text = LoadStringFromID(IDS_SECOND_HOME);
        break;
    }
    m_pBtnSecond->setText(text);
}

void Dialog::onBtnVolumeRsp()
{
    m_bVolume = !m_bVolume;
    QString style = m_pBtnVolume->styleSheet();
    if(m_bVolume)
    {
        style.replace("close", "open");
        emit sendGame(Volume_open);
    }
    else
    {
        style.replace("open", "close");
        emit sendGame(Volume_close);
    }

    m_pBtnVolume->setStyleSheet(style);

}

void Dialog::onBtnAboutRsp()
{
    Dialog *dialog = new Dialog(nullptr, Dialog::About);
    dialog->exec();
}

void Dialog::onBtnCheatRsp()
{
    Dialog *dialog = new Dialog(nullptr, Dialog::Cheat);
    dialog->exec();
}

void Dialog::onBtnRewardRsp()
{
    Dialog *dialog = new Dialog(nullptr, Dialog::Reward);
    dialog->exec();
}

void Dialog::onBtnGiveupRsp()
{
    Dialog *dialog = new Dialog(nullptr, Dialog::Giveup);
    int result = dialog->exec();
    if(result == Done)
    {
        emit sendGame(Giveup);
        this->done(Close);
    }
    else if(result == Back)
        this->done(Close);
}

void Dialog::onBtnRestartRsp()
{
    Dialog *dialog = new Dialog(nullptr, Dialog::Restart);
    int result = dialog->exec();
    if(result == Done)
    {
        emit sendGame(Restart);
        this->done(Close);
    }
    else if(result == Back)
        this->done(Close);
}


void Dialog::onBtnCheatOKRsp()
{
    PlayWidget *widget = MainWindow::getPlayWidget();
    if(widget->m_bAddOneSlot)// 添加卡槽位
    {
        widget->m_bAddOneSlot = false;
        if(m_pLineCheat->text() == "CAPPO")
        {
            widget->AddOneSlot();
            this->close();
            Dialog *dialogSuccess = new Dialog(nullptr, Dialog::AddSlotSuccess);
            dialogSuccess->exec();
        }
        else
        {
            Dialog *dialogFail = new Dialog(nullptr, Dialog::CheatFail);
            dialogFail->exec();
        }
    }
    else// 设置里的作弊码, 无限道具
    {
        if(m_pLineCheat->text() == "CAPPO")
        {
            widget->Cheat();
            this->close();
            Dialog *dialogSuccess = new Dialog(nullptr, Dialog::CheatSuccess);
            dialogSuccess->exec();
        }
        else
        {
            Dialog *dialogFail = new Dialog(nullptr, Dialog::CheatFail);
            dialogFail->exec();
        }
    }
}

\
