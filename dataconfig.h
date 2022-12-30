#ifndef DATACONFIG_H
#define DATACONFIG_H
/**
 * @brief
 *
 * version 1.0
 * @date 2022-10-08
 *
 * 每关的卡片数要确保是3的倍数；array是8*8的二维数组。
 * array[row][column]说明:
 * 1) array[row][column] = 0, 表示该层的第row行第column列的位置没有卡片。
 * 2) array[row][column] = 1, 表示该层的第row行第column列的位置有一张卡片, 采用牌堆模式C。
 * 3) 1 < array[row][column] < 10, 采用牌堆模式A, 仅在第0层使用, 设为多少就表示有多少张卡片,
 * 且只能在array[0][6], array[1][7], array[7][6], array[6][7]设置,
 * 所有层(包括第0层)array[0][5], array[0][6], array[0][7], array[1][7], arr[2][7]
 * array[7][5], array[7][6], array[7][7], array[6][7], array[5][7]必须设置为0,
 * 也就是左下角和右下角的外围三角区域。
 * 4) array[row][column] = 11, 采用牌堆模式B, 水平布局;
 *    array[row][column] = 12, 采用牌堆模式B, 垂直布局。
 *
 * 牌堆模式A：上面1张牌只挡住下面1张牌；同时下面的牌仅被上面1张牌挡住。
 * 只要上面的1张牌被取走，下面的牌就成为窗口牌；（类似蜘蛛纸牌发牌区, 看不见被挡的卡片类型）
 * 牌堆模式B: 上面1张牌可以挡住下面2张牌；同时下面的牌可能被上面2张牌挡住，
 * 一张牌只有它上面的2张牌都被取走，它自己才成为窗口牌。
 * 牌堆模式C：上面1张牌可以挡住下面4张牌；同时下面的牌可能被上面4张牌挡住，
 * 一张牌只有它上面的4张牌都被取走，它自己才成为窗口牌。
 *
 * 参考https://blog.csdn.net/csdnnews/article/details/126935553?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522166519045816800180620859%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=166519045816800180620859&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-2-126935553-null-null.142^v51^control,201^v3^control_2&utm_term=%E7%BE%8A%E4%BA%86%E4%B8%AA%E7%BE%8A&spm=1018.2226.3001.4187
 *
 * Copyright (c) 2007-2022,Raysharp Technology Co.,Ltd.
 * All Rights Reserved
 * Histrory:
 * Revision
 */
#include <QObject>
#include <QMap>
#include <QVector>

class dataConfig : public QObject
{
    Q_OBJECT
public:
    explicit dataConfig(QObject *parent = 0);

private:
    void Level1();
    void Level2();
    void Level3();
    void Level4();
    void Level5();
    void Level6();
    void Level7();
    void Level8();
    void Level9();
    void Level10();
    void Level11();
    void Level12();
    void Level13();
    void Level14();// 底层看不清
    void Level15();
    void Level16();// 模式B垂直
    void Level17();
    void Level18();
    void Level19();
    void Level20();
    void Level21();// 底层和倒数第二层看不清
    void Level22();// 底层看不清
    void Level23();
    void Level24();
    void Level25();
    void Level26();
    void Level27();
    void Level28();
    void Level29();
    void Level30();

public:

    QMap<int, QMap<int, QVector< QVector<int>> > >m_Data;//<关卡数, <层数, 二维数组>>
    QMap<int, int> m_cardCount;// <关卡数, 卡片数>



signals:

public slots:
};

#endif // DATACONFIG_H
