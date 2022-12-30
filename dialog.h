#ifndef DIALOG_H
#define DIALOG_H

#include <QWidget>
#include <QFrame>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QGraphicsDropShadowEffect>
#include "timelistwidget.h"
#include "comm/CXmlLanguage.h"
#include "comm/customcombobox.h"

enum ResultType
{
    Close = -1, // 关闭按钮
    Done, // 第一个按钮
    Back, // 第二个按钮
};
class Dialog : public QDialog
{
    Q_OBJECT
public:
    enum DialogType
    {
        PropRemove = 0, // 移出道具弹窗
        PropRetract, // 撤回道具弹窗
        PropShuffle, // 洗牌道具弹窗
        Setting, // 主页设置弹窗
        SettingGame,// 游戏内设置弹窗
        About, // 关于弹窗
        Cheat, // 作弊码弹窗
        CheatSuccess, // 设置中输入作弊码后的成功弹窗
        AddSlotSuccess,// 增加卡槽输入作弊码后的成功弹窗
        CheatFail, //  作弊码输入错误弹窗
        Reward, // 打赏弹窗
        Giveup, // 放弃挑战弹窗
        Restart, // 重新开始弹窗
        Success, // 过关弹窗
        Revive, // 第一次失败弹窗(询问是否复活)
        Fail, // 第二次失败弹窗
        Easy, // 简单难度弹窗
        Medium, // 中等难度弹窗
        Hard, // 困难难度弹窗
        Infernal, // 地狱难度弹窗
        Custom,// 自定义关卡弹窗
        AddCardSlot, // 增加一个卡槽位弹窗
        Clearance, // 通关弹窗
        Leaderboard, // 排行榜弹窗
        Volume_open, // 音量开
        Volume_close, // 音量关
    };

    explicit Dialog(QWidget *parent = nullptr, DialogType type = PropRemove);
    int getLevel()  {   return m_pLineLevel->text().toInt();}
    int getTypes()  {   return m_pLineType->text().toInt();}
    int getStage()  {   return m_pStage->currentIndex();}

private:
    void InitNormalDialog();
    void InitSettingDialog();
    void InitCheatDialog();
    void InitCheatConfirmDialog();
    void InitLeaderboardDialog();
    void InitCustomDialog();

    void LoadNormalImg(DialogType type);
    void setTitleText(DialogType type);
    void setInfoText(DialogType type);
    void setBtnFirstText(DialogType type);
    void setBtnSecondText(DialogType type);
    void setStyle();

signals:
    void sendGame(int);

public slots:
    void onBtnVolumeRsp();
    void onBtnAboutRsp();
    void onBtnCheatRsp();
    void onBtnRewardRsp();
    void onBtnGiveupRsp();
    void onBtnRestartRsp();

private slots:
    void onBtnCheatOKRsp();

private:
    QLabel *m_pTitle;
    QLabel *m_pPic;
    QLabel *m_pInfo;
    QPushButton *m_pBtnFirst;
    QPushButton *m_pBtnSecond;
    QPushButton *m_pBtnClose;
    QLabel *m_pWidget;

    QPushButton *m_pBtnVolume;
    QPushButton *m_pBtnAbout;
    QPushButton *m_pBtnCheat;
    QPushButton *m_pBtnReward;
    QPushButton *m_pBtnGiveup;
    QPushButton *m_pBtnRestart;

    QLabel *m_pInfoAbout;
    QLineEdit *m_pLineCheat;
    TimeListWidget *m_pListWidget;
    QLineEdit *m_pLineLevel;
    QLineEdit *m_pLineType;
    CustomComboBox *m_pStage;

    bool m_bVolume;
    DialogType m_type;
};

#endif // DIALOG_H
