#include "mainwindow.h"

int MainWindow::s_level = 1;
QMediaPlaylist *MainWindow::s_playerList = nullptr;
PlayWidget *MainWindow::s_widget = nullptr;
QMediaPlayer *MainWindow::s_music = nullptr;
MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(508, 634);
    setWindowIcon(QIcon(":/res/app.png"));
    setWindowTitle("Cappo of Cappo");

    m_btnSetting = new QPushButton;
    m_btnEasy = new QPushButton;
    m_btnMedium = new QPushButton;
    m_btnHard = new QPushButton;
    m_btnInfernal = new QPushButton;
    m_btnCustom = new QPushButton;
    m_btnBoard = new QPushButton;
    m_btnSetting->setFixedSize(32, 32);
    m_btnBoard->setFixedSize(48, 48);

    for(int i = 0; i <= 3; i++)// 一个对象只能作用于一个部件
    {
        QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();//阴影边框效果
        shadow->setBlurRadius(10);
        shadow->setColor(Qt::black);
        shadow->setOffset(0);// 阴影偏移值
        if(i == 0)
            m_btnEasy->setGraphicsEffect(shadow);
        else if(i == 1)
            m_btnMedium->setGraphicsEffect(shadow);
        else if(i == 2)
            m_btnHard->setGraphicsEffect(shadow);
        else if(i == 3)
            m_btnInfernal->setGraphicsEffect(shadow);
    }

    m_btnEasy->setText(LoadStringFromID(IDS_LEVEL_EASY));
    m_btnMedium->setText(LoadStringFromID(IDS_LEVEL_MEDIUM));
    m_btnHard->setText(LoadStringFromID(IDS_LEVEL_HARD));
    m_btnInfernal->setText(LoadStringFromID(IDS_LEVEL_INFERNAL));
    m_btnCustom->setText(LoadStringFromID(IDS_LEVEL_CUSTOM));

    QHBoxLayout *settingLayout = new QHBoxLayout;
    settingLayout->addWidget(m_btnSetting);
    settingLayout->addStretch(1);
    settingLayout->addWidget(m_btnBoard);
    settingLayout->setContentsMargins(0, 0, 0, 0);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(settingLayout);
    layout->addStretch(1);
    layout->addWidget(m_btnEasy);
    layout->addWidget(m_btnMedium);
    layout->addWidget(m_btnHard);
    layout->addWidget(m_btnInfernal);
    layout->addWidget(m_btnCustom);
    layout->setSpacing(20);
    layout->setContentsMargins(16, 16, 16, 25);
    layout->setAlignment(Qt::AlignCenter);
    setLayout(layout);
    connect(m_btnSetting, &QPushButton::clicked, this, [this]()
    {
        Dialog *dialog = new Dialog(this, Dialog::Setting);
        connect(dialog, &Dialog::sendGame, this, [=](int result)
        {
            if(result == Dialog::Volume_open)
                s_music->play();
            else if(result == Dialog::Volume_close)
                s_music->pause();

        });
        dialog->exec();
    });
    connect(m_btnBoard, &QPushButton::clicked, this, [this]()
    {
        Dialog *dialog = new Dialog(this, Dialog::Leaderboard);
        dialog->exec();
    });

    if(!s_music)
    {
        s_playerList = new QMediaPlaylist(this);
        s_playerList->addMedia(QUrl("qrc:/res/disco.mp3"));
//        m_playerList->addMedia(QUrl("qrc:/res/disco.mp3"));
//        m_playerList->setCurrentIndex(1);
        s_playerList->setPlaybackMode(QMediaPlaylist::Loop);
        s_music = new QMediaPlayer(this);
        s_music->setPlaylist(s_playerList);
        connect(s_music, &QMediaPlayer::mediaStatusChanged, this, [](QMediaPlayer::MediaStatus status)
        {
            if(status == QMediaPlayer::EndOfMedia)
            {
                s_music->setPosition(0);
                s_music->play();
            }
        });
        s_music->setVolume(30);//音量
        s_music->play();
    }
    if(!s_widget)
        s_widget = new PlayWidget();
    connect(m_btnEasy, &QPushButton::clicked, this, &MainWindow::onBtnStageRsp);
    connect(m_btnMedium, &QPushButton::clicked, this, &MainWindow::onBtnStageRsp);
    connect(m_btnHard, &QPushButton::clicked, this, &MainWindow::onBtnStageRsp);
    connect(m_btnInfernal, &QPushButton::clicked, this, &MainWindow::onBtnStageRsp);
    connect(m_btnCustom, &QPushButton::clicked, this, &MainWindow::onBtnStageRsp);

    setStyle();
}

MainWindow::~MainWindow()
{
    if(s_widget)
    {
        delete s_widget;
        s_widget = nullptr;
    }
}

void MainWindow::onBtnStageRsp()
{
    QPushButton *btn = static_cast<QPushButton *>(sender());
    Dialog::DialogType dialogType;
    PlayWidget::Stage stage;
    int types = 8;
    if(btn == m_btnEasy)
    {
        dialogType = Dialog::Easy;
        stage = PlayWidget::EasyLevel;
        types = 8;
    }
    else if(btn == m_btnMedium)
    {
        dialogType = Dialog::Medium;
        stage = PlayWidget::MediumLevel;
        types = 8;
    }
    else if(btn == m_btnHard)
    {
        dialogType = Dialog::Hard;
        stage = PlayWidget::HardLevel;
        types = 16;
    }
    else if(btn == m_btnInfernal)
    {
        dialogType = Dialog::Infernal;
        stage = PlayWidget::InfernalLevel;
        types = 16;
    }
    else
    {
        dialogType = Dialog::Custom;
        stage = PlayWidget::EasyLevel;
    }
    Dialog *dialog = new Dialog(nullptr, dialogType);
    if(dialog->exec() == Done)
    {
        this->hide();
        s_level = 1;
        if(dialogType == Dialog::Custom)
        {
            types = dialog->getTypes();
            s_level = dialog->getLevel();
            int way = dialog->getStage();// 添加方式
            if(way == 0)
                stage = PlayWidget::EasyLevel;
            else
                stage = PlayWidget::MediumLevel;
            s_widget->InitGame(stage, s_level, types);
        }
        else
        {
            s_widget->InitGame(stage);
        }

        connect(s_widget, &PlayWidget::sendHome, this, [=](int result)
        {
            s_widget->hide();
            if(result == Done)// 下一关
            {
                s_widget->InitGame(stage, ++s_level,types);
                s_widget->show();
            }
            else if(result == Back)// 返回主页
            {
                this->show();
            }
            else if(result == Dialog::Restart)// 重新开始
            {
                s_widget->InitGame(stage, s_level, types);
                s_widget->show();
            }
        });
        s_widget->show();
    }

}

void MainWindow::controlMusic(bool state)
{
    if(state)
        s_music->play();
    else
        s_music->pause();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
//    painter.fillRect(rect(), QColor(255, 255, 255));
    QRect target(0, 0, width(), height());
    painter.drawPixmap(target, QPixmap(":/res/PlaySceneBg.png").scaled(width(), height()));

    QWidget::paintEvent(event);
}

void MainWindow::setStyle()
{
    QStringList qss;
    qss.append(QString("QPushButton{"
                       "border-image: url(:/res/setting.png);"
                       "border-radius: 8px;}"
                       "QPushButton:hover{"
                       "background-color: #DCE8F6;}"
                       "QPushButton:pressed{"
                       "margin: 1px;"
                       "background-color: #DCE8F6;}"));
    m_btnSetting->setStyleSheet(qss.join(""));
    QString style = m_btnSetting->styleSheet();
    style.replace("setting", "board");
    m_btnBoard->setStyleSheet(style);

    qss.clear();
    qss.append(QString("QPushButton{"
                       "width: 190px;"
                       "height: 50px;"
                       "border-top: 3px solid  #000000;"
                       "border-left: 3px solid  #000000;"
                       "border-right: 3px solid #000000;"
                       "border-bottom: 3px solid #000000;"
                       "border-radius: 8px;"
                       "color: #000000;"
                       "background-color:#ffffff;"
                       "font-size: 24px;"
                       "font-weight:bold}"));
    qss.append(QString("QPushButton:hover{"
                       "outline: none;"
                       "background-color: #DCE8F6;}"));
    qss.append(QString("QPushButton:pressed{"
                       "margin: 1px;"
                       "background-color: #DCE8F6;}"));
    m_btnEasy->setStyleSheet(qss.join(""));
    m_btnMedium->setStyleSheet(qss.join(""));
    m_btnHard->setStyleSheet(qss.join(""));
    m_btnInfernal->setStyleSheet(qss.join(""));
    m_btnCustom->setStyleSheet(qss.join(""));
}
