#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "PlayWidget.h"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setStyle();
    static PlayWidget *getPlayWidget()  {   return s_widget;}
    static void controlMusic(bool state);// true:play, false:pause

signals:

public slots:
    void onBtnStageRsp();

protected:
    void paintEvent(QPaintEvent *event);

private:
    QPushButton *m_btnSetting;
    QPushButton *m_btnEasy;
    QPushButton *m_btnMedium;
    QPushButton *m_btnHard;
    QPushButton *m_btnInfernal;
    QPushButton *m_btnCustom;
    QPushButton *m_btnBoard;

    static QMediaPlaylist *s_playerList;
    static QMediaPlayer *s_music;
    static PlayWidget *s_widget;
    static int s_level;
};

#endif // MAINWINDOW_H
