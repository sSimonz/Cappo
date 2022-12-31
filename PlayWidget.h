#ifndef PLAYWIDGET_H
#define PLAYWIDGET_H

#include <QWidget>
#include <QMap>
#include <QPainter>
#include <QHBoxLayout>
#include <QTimer>
#include <QTime>
#include <QSvgWidget>
#include <QMediaPlayer>
#include "cardlabel.h"
#include "dialog.h"
#include "waitingdialog.h"

class PlayWidget : public QWidget
{
    Q_OBJECT

public:
    enum Stage
    {
        EasyLevel = 0,
        MediumLevel,
        HardLevel,
        InfernalLevel,
        CustomLevel
    };
    enum Direction
    {
        LEFT = 0,
        RIGHT
    };

    PlayWidget(Stage degree = EasyLevel, int level = 5, QWidget *parent = 0);
    ~PlayWidget();

    void InitGame(Stage degree = EasyLevel, int level = 1, int types = 8);// 删除之前的数据, 重新初始化
    void Cheat();
    QMap<int, QString> getLeaderboard() {   return m_leaderboard;}
    void AddOneSlot();// 添加一个卡槽位
    bool m_bAddOneSlot;// 判断是否使用了增加卡槽

private:
    void Init();
    void InitModeA(int layer, int row, int column, int &index, QVector< QVector<int>> gameArray);
    void InitModeB(int layer, int row, int column, int &index, QVector< QVector<int>> gameArray);
    void InitModeC(int layer, int row, int column, int &index, QVector< QVector<int>> gameArray);
    void InitBtnSetting();
    void InitBtnProp();
    void InitQCards(int size = 4);// 初始化问号牌型(初始化为问号, 添加进卡槽显示对应类型)
    void InitTimer();
    void ResetTimer();
    /**
     * @brief setEnabledByMode
     * @param bInit: 为true是初始化时该卡片下一层的四张卡片暗化不可点击
     * 为false时是该卡片移除时判断下一层是四张卡片是否还有遮挡 */
    void setEnabledByModeC(int row, int column, int layer, bool bInit = true);
    bool IsUpEnabledByModeC(int row, int column, int layer);// 判断该卡片的上一层是否有遮挡(上一层的四张卡片是否存在)
    void setEnabledByModeB(int row, int column, int layer, bool bInit = true);
    bool IsUpEnabledByModeB(int row, int column, int layer, bool bHorizon = true);
    void FindCardToSetMask(int row, int column, int layer, bool bInit = true, int mode = MODEC);
    void setRandomCards();// 每张卡片随机赋予种类
    void setRandomCardsIsGreater(bool greater);// 先设置24*n张卡片种类，再设置剩余卡片
    void ShuffleCards(bool bGet);// true: GET; false:SET
    void resizeCardsPos(int index, int Direction);// 简单模式, 插入卡片时更新所有卡牌位置 (索引, 方向:左移或右移)
    void popSuccessDialog();// 胜利
    void popFailDialog();// 失败
    void RemoveAnimation(int index);// 消除闪烁动画, index和前两个位置开启闪烁动画

signals:
    void sendHome(int);

private slots:
    void addCardSlot();// 点击卡片添加到卡槽
    void Eliminate(CardLabel *curCard, CardLabel *cardOne, CardLabel *cardTwo);// 消除判定
    void propRemoveRsp();// 移出三个卡片并把它们堆放在旁边
    void propRetractRsp();// 撤回最近的一张牌并把他放到原位置
    void propShuffleRsp();// 随机打乱未使用的所有牌

protected:
    void paintEvent(QPaintEvent *event);

private:
    QList<cardInfo *> m_cardsModeC;// 未点击的牌堆模式C的卡片
    QList<cardInfo *> m_cardsModeB;// 未点击的牌堆模式B的卡片
    QMap<QPair<int, int >, QList<CardLabel *>>m_cardsModeA;// 未点击的牌堆模式A的卡片
    QList<CardLabel *> m_cardSlot;// 卡槽里的卡片
    QList<CardLabel *>m_cardPending;// 待定位里的卡片, 使用移出道具时所存放的位置
    std::vector<int> m_cardsType;// 所有卡牌的种类
    std::vector<int> m_restCardsType;// 剩余未点击卡牌的种类

    QPushButton *m_btnSetting;
    int m_type;// 种类数: 简单/中等难度8种; 困难/地狱难度16种
    int m_stage;// 简单/困难难度:插入到相同卡片的后面, 中等/地狱难度:添加到卡槽末尾
    int m_cardCount;// 卡片总数
    int m_levelCount;// 总共的关卡数
    QPoint m_ptSlot;// 卡槽起始坐标
    QPoint m_ptPend;// 待定区起始坐标
    QMap<int, QVector< QVector<int>> >m_Data;// 游戏数据
    CardLabel *m_btnRemove;
    CardLabel *m_btnRetract;
    CardLabel *m_btnShuffle;
    int m_RemoveCount;// 移出道具使用次数
    int m_RetractCount;// 撤回道具使用次数
    int m_ShuffleCount;// 洗牌道具使用次数
    int m_FailCount;// 失败次数, 第一次可复活, 第二次失败
    bool m_bRevive;// 是否复活
    bool m_bCheat;// 作弊
    QTimer *m_timer;// 显示时间定时器
    QTime m_time;
    QLabel *m_timeDisplay;
    QLabel *m_levelDisplay;
    QMap<int, QString> m_leaderboard;// <关卡, 所用时间>
    int m_level;
    QTimer *m_flickerTimer;// 消除动画定时器
    QList<QLabel *>m_flickerList;
    WaitingDialog *m_waitDialog;// 洗牌加载动画弹窗
    QPushButton *m_btnAddSlot;
    int m_cardSlotCount;// 卡槽可放的卡片数, 正常是7个, 添加卡槽位是8个
    QMediaPlayer *m_clickMusic;
    QMediaPlayer *m_removeMusic;
};

#endif // PLAYWIDGET_H
