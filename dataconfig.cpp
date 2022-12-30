#include "dataconfig.h"
#include <QDebug>
dataConfig::dataConfig(QObject *parent) : QObject(parent)
{
    Level1();
    Level2();
    Level3();
    Level4();
    Level5();
    Level6();
    Level7();
    Level8();
    Level9();
    Level10();
    Level11();
    Level12();
    Level13();
    Level14();
    Level15();
    Level16();
    Level17();
    Level18();
    Level19();
    Level20();
    Level21();
    Level22();
    Level23();
    Level24();
    Level25();
    Level26();
    Level27();
    Level28();
    Level29();
    Level30();
}

void dataConfig::Level1()
{
    QMap<int, QVector< QVector<int>> >gameArray;// 当前关卡数据
    int count = 0;// 卡片数
    int array0[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 0, 1, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 0, 1, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 0, 1, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    QVector< QVector<int>> v;
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array0[i][j]);
            if(array0[i][j] > 10)
                count += 1;
            else
                count += array0[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(0,v);

    int array1[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 0, 1, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 0, 1, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 0, 1, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array1[i][j]);
            if(array1[i][j] > 10)
                count += 1;
            else
                count += array1[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(1,v);

    int array2[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 1, 0, 1, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 1, 0, 1, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 1, 0, 1, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array2[i][j]);
            if(array2[i][j] > 10)
                count += 1;
            else
                count += array2[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(2,v);
    // 第1关
    m_cardCount.insert(1, count);
    m_Data.insert(1, gameArray);
}

void dataConfig::Level2()
{
    QMap<int, QVector< QVector<int>> >gameArray;// 当前关卡数据
    int count = 0;// 卡片数
    int array0[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 12, 0, 12, 0, 12, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    QVector< QVector<int>> v;
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array0[i][j]);
            if(array0[i][j] > 10)
                count += 1;
            else
                count += array0[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(0,v);

    int array1[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 12, 0, 12, 0, 12, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array1[i][j]);
            if(array1[i][j] > 10)
                count += 1;
            else
                count += array1[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(1,v);

    int array2[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 12, 0, 12, 0, 12, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array2[i][j]);
            if(array2[i][j] > 10)
                count += 1;
            else
                count += array2[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(2,v);

    int array3[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 12, 0, 12, 0, 12, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array3[i][j]);
            if(array3[i][j] > 10)
                count += 1;
            else
                count += array3[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(3,v);

    int array4[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 12, 0, 12, 0, 12, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array4[i][j]);
            if(array4[i][j] > 10)
                count += 1;
            else
                count += array4[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(4,v);
    // 第2关
    m_cardCount.insert(2, count);
    m_Data.insert(2, gameArray);
}

void dataConfig::Level3()
{
    QMap<int, QVector< QVector<int>> >gameArray;// 当前关卡数据
    int count = 0;// 卡片数
    int array0[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 1, 1, 1, 0, 0},
                        {0, 0, 1, 0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0, 1, 0, 0},
                        {0, 0, 1, 1, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    QVector< QVector<int>> v;
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array0[i][j]);
            if(array0[i][j] > 10)
                count += 1;
            else
                count += array0[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(0,v);

    int array1[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 0, 1, 0, 1, 0, 0, 0},
                        {0, 0, 1, 0, 1, 0, 0, 0},
                        {0, 0, 1, 0, 1, 0, 0, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array1[i][j]);
            if(array1[i][j] > 10)
                count += 1;
            else
                count += array1[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(1,v);
    // 第3关
    m_cardCount.insert(3, count);
    m_Data.insert(3, gameArray);
}

void dataConfig::Level4()
{
    QMap<int, QVector< QVector<int>> >gameArray;// 当前关卡数据
    int count = 0;// 卡片数
    int array0[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0, 1, 0, 0},
                        {0, 1, 1, 1, 1, 1, 1, 0},
                        {0, 1, 1, 1, 1, 1, 1, 0},
                        {0, 0, 1, 1, 1, 1, 0, 0},
                        {0, 0, 0, 1, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    QVector< QVector<int>> v;
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array0[i][j]);
            if(array0[i][j] > 10)
                count += 1;
            else
                count += array0[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(0,v);

    int array1[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 1, 0, 0, 0},
                        {0, 1, 1, 1, 1, 1, 0, 0},
                        {0, 1, 1, 1, 1, 1, 0, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array1[i][j]);
            if(array1[i][j] > 10)
                count += 1;
            else
                count += array1[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(1,v);
    // 第4关
    m_cardCount.insert(4, count);
    m_Data.insert(4, gameArray);
}

void dataConfig::Level5()
{
    QMap<int, QVector< QVector<int>> >gameArray;// 当前关卡数据
    int count = 0;// 卡片数
    int array0[8][8] = {{1, 1, 1, 1, 0, 0, 1, 1},
                        {1, 1, 0, 1, 1, 1, 1, 1},
                        {1, 0, 0, 0, 1, 1, 0, 1},
                        {1, 1, 1, 1, 0, 0, 1, 1},
                        {1, 1, 0, 1, 1, 1, 1, 1},
                        {0, 0, 0, 0, 1, 1, 0, 0},
                        {4, 1, 1, 1, 0, 0, 1, 4},
                        {0, 4, 0, 0, 0, 0, 4, 0}};

    QVector< QVector<int>> v;
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array0[i][j]);
            if(array0[i][j] > 10)
                count += 1;
            else
                count += array0[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(0,v);

    int array1[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0, 0, 1},
                        {0, 0, 0, 1, 1, 1, 0, 0},
                        {0, 0, 0, 1, 1, 0, 0, 0},
                        {0, 0, 0, 1, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array1[i][j]);
            if(array0[i][j] > 10)
                count += 1;
            else
                count += array1[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(1,v);
    // 第5关
    m_cardCount.insert(5, count);
    m_Data.insert(5, gameArray);
}

void dataConfig::Level6()
{
    QMap<int, QVector< QVector<int>> >gameArray;// 当前关卡数据
    int count = 0;// 卡片数
    int array0[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 1, 0, 0, 1, 1, 0},
                        {0, 1, 1, 0, 0, 1, 1, 0},
                        {0, 1, 1, 0, 0, 1, 1, 0},
                        {0, 1, 1, 0, 0, 1, 1, 0},
                        {0, 1, 1, 0, 0, 1, 1, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    QVector< QVector<int>> v;
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array0[i][j]);
            if(array0[i][j] > 10)
                count += 1;
            else
                count += array0[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(0,v);

    int array1[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 1, 0, 1, 1, 0, 0},
                        {0, 1, 1, 0, 1, 1, 0, 0},
                        {0, 1, 1, 0, 1, 1, 0, 0},
                        {0, 1, 1, 0, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array1[i][j]);
            if(array1[i][j] > 10)
                count += 1;
            else
                count += array1[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(1,v);

    int array2[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array2[i][j]);
            if(array2[i][j] > 10)
                count += 1;
            else
                count += array2[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(2,v);
    // 第6关
    m_cardCount.insert(6, count);
    m_Data.insert(6, gameArray);
}

void dataConfig::Level7()
{
    QMap<int, QVector< QVector<int>> >gameArray;// 当前关卡数据
    int count = 0;// 卡片数
    int array0[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 1, 1, 1, 1, 1, 0, 0},
                        {1, 1, 0, 0, 0, 1, 1, 0},
                        {1, 1, 0, 0, 0, 1, 1, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0}};

    QVector< QVector<int>> v;
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array0[i][j]);
            if(array0[i][j] > 10)
                count += 1;
            else
                count += array0[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(0,v);

    int array1[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0, 0, 0},
                        {0, 1, 1, 1, 1, 0, 0, 0},
                        {1, 1, 0, 0, 1, 1, 0, 0},
                        {1, 0, 0, 0, 0, 1, 0, 0},
                        {0, 1, 1, 1, 1, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array1[i][j]);
            if(array1[i][j] > 10)
                count += 1;
            else
                count += array1[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(1,v);

    int array2[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 1, 1, 0, 1, 1, 0, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array2[i][j]);
            if(array2[i][j] > 10)
                count += 1;
            else
                count += array2[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(2,v);
    // 第7关
    m_cardCount.insert(7, count);
    m_Data.insert(7, gameArray);
}

void dataConfig::Level8()
{
    QMap<int, QVector< QVector<int>> >gameArray;// 当前关卡数据
    int count = 0;// 卡片数
    int array0[8][8] = {{0, 1, 1, 0, 1, 1, 0, 0},
                        {1, 1, 1, 0, 1, 1, 1, 0},
                        {1, 1, 1, 0, 1, 1, 1, 0},
                        {0, 1, 1, 1, 1, 1, 0, 0},
                        {0, 1, 1, 1, 1, 1, 0, 0},
                        {1, 1, 1, 0, 1, 1, 1, 0},
                        {1, 1, 1, 0, 1, 1, 1, 0},
                        {0, 1, 1, 0, 1, 1, 0, 0}};

    QVector< QVector<int>> v;
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array0[i][j]);
            if(array0[i][j] > 10)
                count += 1;
            else
                count += array0[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(0,v);

    int array1[8][8] = {{0, 1, 0, 1, 1, 0, 0, 0},
                        {1, 1, 0, 1, 1, 1, 0, 0},
                        {0, 1, 0, 1, 1, 0, 0, 0},
                        {0, 1, 0, 0, 1, 0, 0, 0},
                        {0, 1, 1, 0, 1, 0, 0, 0},
                        {1, 1, 1, 0, 1, 1, 0, 0},
                        {0, 1, 1, 0, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array1[i][j]);
            if(array1[i][j] > 10)
                count += 1;
            else
                count += array1[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(1,v);

    // 第8关
    m_cardCount.insert(8, count);
    m_Data.insert(8, gameArray);
}

void dataConfig::Level9()
{
    QMap<int, QVector< QVector<int>> >gameArray;// 当前关卡数据
    int count = 0;// 卡片数
    int array0[8][8] = {{0, 1, 1, 1, 1, 1, 1, 0},
                        {0, 1, 0, 0, 0, 0, 1, 0},
                        {0, 1, 0, 0, 0, 0, 1, 0},
                        {0, 1, 0, 0, 0, 0, 1, 0},
                        {0, 1, 0, 0, 0, 0, 1, 0},
                        {0, 1, 0, 0, 0, 0, 1, 0},
                        {0, 1, 0, 0, 0, 0, 1, 0},
                        {0, 1, 1, 1, 1, 1, 1, 0}};

    QVector< QVector<int>> v;
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array0[i][j]);
            if(array0[i][j] > 10)
                count += 1;
            else
                count += array0[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(0,v);

    int array1[8][8] = {{0, 1, 1, 1, 1, 1, 0, 0},
                        {0, 1, 0, 0, 0, 1, 0, 0},
                        {0, 1, 0, 0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 0, 0, 0, 1, 0, 0},
                        {0, 1, 0, 0, 0, 1, 0, 0},
                        {0, 1, 1, 1, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array1[i][j]);
            if(array1[i][j] > 10)
                count += 1;
            else
                count += array1[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(1,v);

    int array2[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 1, 1, 1, 0, 0},
                        {0, 0, 1, 1, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 1, 1, 1, 0, 0},
                        {0, 0, 1, 1, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array2[i][j]);
            if(array2[i][j] > 10)
                count += 1;
            else
                count += array2[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(2,v);

    int array3[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array3[i][j]);
            if(array3[i][j] > 10)
                count += 1;
            else
                count += array3[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(3,v);
    // 第9关
    m_cardCount.insert(9, count);
    m_Data.insert(9, gameArray);
}

void dataConfig::Level10()
{
    QMap<int, QVector< QVector<int>> >gameArray;// 当前关卡数据
    int count = 0;// 卡片数
    int array0[8][8] = {{12, 11, 11, 11, 11, 11, 11, 12},
                        {0, 11, 11, 11, 11, 11, 11, 0},
                        {0, 11, 11, 11, 11, 11, 11, 0},
                        {0, 11, 11, 11, 11, 11, 11, 0},
                        {0, 0, 1, 0, 1, 0, 0, 0},
                        {0, 1, 0, 1, 0, 1, 0, 0},
                        {6, 0, 1, 0, 1, 0, 0, 5},
                        {0, 0, 0, 1, 0, 0, 0, 0}};

    QVector< QVector<int>> v;
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array0[i][j]);
            if(array0[i][j] > 10)
                count += 1;
            else
                count += array0[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(0,v);

    int array1[8][8] = {{12, 11, 11, 11, 11, 0, 0, 12},
                        {0, 11, 11, 11, 11, 0, 0, 0},
                        {0, 11, 11, 11, 11, 0, 0, 0},
                        {0, 11, 11, 11, 11, 0, 0, 0},
                        {0, 0, 1, 0, 1, 0, 0, 0},
                        {0, 1, 0, 1, 0, 1, 0, 0},
                        {0, 0, 1, 0, 1, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array1[i][j]);
            if(array1[i][j] > 10)
                count += 1;
            else
                count += array1[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(1,v);

    int array2[8][8] = {{0, 0, 11, 11, 11, 11, 0, 0},
                        {12, 0, 11, 11, 11, 11, 0, 12},
                        {0, 0, 11, 11, 11, 11, 0, 0},
                        {0, 0, 11, 11, 11, 11, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {1, 1, 1, 1, 1, 1, 1, 1},
                        {0, 0, 1, 0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array2[i][j]);
            if(array2[i][j] > 10)
                count += 1;
            else
                count += array2[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(2,v);

    int array3[8][8] = {{0, 0, 11, 11, 11, 11, 0, 0},
                        {12, 0, 11, 11, 11, 11, 0, 12},
                        {0, 0, 11, 11, 11, 11, 0, 0},
                        {0, 0, 11, 11, 11, 11, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array3[i][j]);
            if(array3[i][j] > 10)
                count += 1;
            else
                count += array3[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(3,v);
    // 第10关
    m_cardCount.insert(10, count);
    m_Data.insert(10, gameArray);
}

void dataConfig::Level11()
{
    QMap<int, QVector< QVector<int>> >gameArray;// 当前关卡数据
    int count = 0;// 卡片数
    int array0[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 1, 1, 1, 1, 0, 0},
                        {1, 1, 1, 0, 1, 1, 0, 0},
                        {1, 1, 1, 0, 1, 1, 1, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {1, 1, 1, 0, 1, 1, 1, 0},
                        {1, 1, 1, 0, 1, 1, 1, 0},
                        {0, 1, 1, 1, 1, 1, 0, 0}};

    QVector< QVector<int>> v;
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array0[i][j]);
            if(array0[i][j] > 10)
                count += 1;
            else
                count += array0[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(0,v);

    int array1[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {1, 1, 1, 1, 1, 1, 0, 0},
                        {1, 1, 1, 1, 1, 1, 0, 0},
                        {1, 1, 1, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 1, 1, 0, 0},
                        {1, 1, 1, 1, 1, 1, 0, 0},
                        {1, 1, 1, 1, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array1[i][j]);
            if(array1[i][j] > 10)
                count += 1;
            else
                count += array1[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(1,v);

    // 第11关
    m_cardCount.insert(11, count);
    m_Data.insert(11, gameArray);
}

void dataConfig::Level12()
{
    QMap<int, QVector< QVector<int>> >gameArray;// 当前关卡数据
    int count = 0;// 卡片数
    int array0[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {1, 1, 1, 0, 1, 1, 1, 0},
                        {1, 0, 1, 0, 1, 1, 1, 0},
                        {1, 1, 1, 0, 1, 1, 1, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {1, 1, 1, 0, 1, 1, 1, 0},
                        {1, 1, 1, 0, 1, 1, 1, 0},
                        {1, 1, 1, 0, 1, 1, 1, 0}};

    QVector< QVector<int>> v;
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array0[i][j]);
            if(array0[i][j] > 10)
                count += 1;
            else
                count += array0[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(0,v);

    int array1[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {1, 1, 0, 0, 1, 1, 0, 0},
                        {1, 1, 0, 0, 1, 1, 0, 0},
                        {0, 0, 1, 1, 0, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0, 0, 0},
                        {1, 1, 0, 0, 1, 1, 0, 0},
                        {1, 1, 0, 0, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array1[i][j]);
            if(array1[i][j] > 10)
                count += 1;
            else
                count += array1[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(1,v);

    int array2[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 0, 0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 0, 0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array2[i][j]);
            if(array2[i][j] > 10)
                count += 1;
            else
                count += array2[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(2,v);
    // 第12关
    m_cardCount.insert(12, count);
    m_Data.insert(12, gameArray);
}

void dataConfig::Level13()
{
    QMap<int, QVector< QVector<int>> >gameArray;// 当前关卡数据
    int count = 0;// 卡片数
    int array0[8][8] = {{1, 1, 0, 1, 1, 1, 1, 1},
                        {1, 1, 0, 0, 1, 1, 1, 1},
                        {0, 0, 0, 0, 0, 1, 1, 1},
                        {1, 0, 0, 0, 1, 0, 1, 1},
                        {1, 1, 0, 1, 0, 0, 0, 1},
                        {1, 1, 1, 0, 0, 0, 0, 0},
                        {1, 1, 1, 1, 0, 0, 1, 1},
                        {1, 1, 1, 1, 1, 0, 1, 1}};

    QVector< QVector<int>> v;
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array0[i][j]);
            if(array0[i][j] > 10)
                count += 1;
            else
                count += array0[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(0,v);

    int array1[8][8] = {{1, 1, 0, 1, 1, 1, 1, 0},
                        {1, 0, 0, 0, 0, 1, 1, 0},
                        {0, 0, 0, 0, 1, 0, 1, 0},
                        {1, 0, 0, 1, 0, 0, 1, 0},
                        {1, 0, 1, 0, 0, 0, 0, 0},
                        {1, 1, 0, 0, 0, 0, 1, 0},
                        {1, 1, 1, 1, 0, 1, 1, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array1[i][j]);
            if(array1[i][j] > 10)
                count += 1;
            else
                count += array1[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(1,v);

    int array2[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 0, 0, 1, 1, 1, 0},
                        {0, 0, 0, 0, 0, 1, 1, 0},
                        {0, 0, 0, 0, 1, 0, 1, 0},
                        {0, 1, 0, 1, 0, 0, 0, 0},
                        {0, 1, 1, 0, 0, 0, 0, 0},
                        {0, 1, 1, 1, 0, 0, 1, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array2[i][j]);
            if(array2[i][j] > 10)
                count += 1;
            else
                count += array2[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(2,v);
    // 第13关
    m_cardCount.insert(13, count);
    m_Data.insert(13, gameArray);
}

void dataConfig::Level14()
{
    QMap<int, QVector< QVector<int>> >gameArray;// 当前关卡数据
    int count = 0;// 卡片数
    int array0[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 1, 1, 1, 0, 0},
                        {0, 0, 1, 1, 1, 1, 0, 0},
                        {1, 1, 0, 0, 0, 0, 1, 1},
                        {1, 1, 0, 1, 0, 0, 1, 1},
                        {1, 1, 0, 0, 0, 0, 1, 1},
                        {0, 0, 1, 1, 1, 1, 0, 0},
                        {0, 0, 1, 1, 1, 1, 0, 0}};

    QVector< QVector<int>> v;
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array0[i][j]);
            if(array0[i][j] > 10)
                count += 1;
            else
                count += array0[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(0,v);

    int array1[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 1, 1, 1, 1, 0, 0},
                        {1, 1, 0, 0, 0, 1, 1, 0},
                        {1, 1, 0, 0, 0, 1, 1, 0},
                        {1, 1, 0, 0, 0, 1, 1, 0},
                        {1, 1, 0, 0, 0, 1, 1, 0},
                        {0, 1, 1, 1, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array1[i][j]);
            if(array1[i][j] > 10)
                count += 1;
            else
                count += array1[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(1,v);

    int array2[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 1, 1, 1, 1, 1, 0},
                        {0, 0, 1, 1, 1, 1, 0, 0},
                        {0, 1, 1, 1, 1, 1, 1, 0},
                        {0, 0, 1, 1, 1, 1, 0, 0},
                        {0, 1, 1, 1, 1, 1, 1, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array2[i][j]);
            if(array2[i][j] > 10)
                count += 1;
            else
                count += array2[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(2,v);
    // 第14关
    m_cardCount.insert(14, count);
    m_Data.insert(14, gameArray);
}

void dataConfig::Level15()
{
    QMap<int, QVector< QVector<int>> >gameArray;// 当前关卡数据
    int count = 0;// 卡片数
    int array0[8][8] = {{1, 0, 0, 0, 0, 0, 1, 0},
                        {1, 1, 0, 0, 0, 1, 1, 0},
                        {1, 1, 1, 0, 1, 1, 1, 0},
                        {1, 1, 1, 1, 1, 1, 1, 0},
                        {1, 1, 1, 1, 1, 1, 1, 0},
                        {1, 1, 1, 0, 1, 1, 1, 0},
                        {1, 1, 0, 0, 0, 1, 1, 0},
                        {1, 0, 0, 0, 0, 0, 1, 0}};

    QVector< QVector<int>> v;
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array0[i][j]);
            if(array0[i][j] > 10)
                count += 1;
            else
                count += array0[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(0,v);

    int array1[8][8] = {{1, 0, 0, 0, 0, 1, 0, 0},
                        {1, 0, 0, 1, 0, 1, 0, 0},
                        {1, 1, 1, 1, 1, 1, 0, 0},
                        {1, 1, 1, 1, 1, 1, 0, 0},
                        {1, 1, 1, 1, 1, 1, 0, 0},
                        {1, 0, 1, 0, 0, 1, 0, 0},
                        {1, 0, 0, 0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array1[i][j]);
            if(array1[i][j] > 10)
                count += 1;
            else
                count += array1[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(1,v);

    int array2[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 0, 0, 0, 1, 0, 0},
                        {0, 1, 0, 0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 1, 0, 0, 0},
                        {0, 0, 1, 0, 1, 0, 0, 0},
                        {0, 1, 0, 0, 0, 1, 0, 0},
                        {0, 1, 0, 0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array2[i][j]);
            if(array2[i][j] > 10)
                count += 1;
            else
                count += array2[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(2,v);
    // 第15关
    m_cardCount.insert(15, count);
    m_Data.insert(15, gameArray);
}

void dataConfig::Level16()
{
    QMap<int, QVector< QVector<int>> >gameArray;// 当前关卡数据
    int count = 0;// 卡片数
    int array0[8][8] = {{12, 12, 12, 12, 12, 12, 12, 0},
                        {12, 12, 12, 12, 12, 12, 12, 0},
                        {12, 12,  0,  0,  0, 12, 12, 0},
                        {12, 12,  0,  0,  0, 12, 12, 0},
                        {12, 12,  0,  0,  0, 12, 12, 0},
                        {12, 12,  0,  0,  0, 12, 12, 0},
                        {12, 12, 12, 12, 12, 12, 12, 0},
                        {12, 12, 12, 12, 12, 12, 12, 0}};

    QVector< QVector<int>> v;
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array0[i][j]);
            if(array0[i][j] > 10)
                count += 1;
            else
                count += array0[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(0,v);

    int array1[8][8] = {{12, 12, 12, 12, 12, 12, 12, 0},
                        {12, 12, 12, 12, 12, 12, 12, 0},
                        {12, 12,  0,  0,  0, 12, 12, 0},
                        {12, 12,  0, 12,  0, 12, 12, 0},
                        {12, 12,  0,  0,  0, 12, 12, 0},
                        {12, 12, 12, 12, 12, 12, 12, 0},
                        {12, 12, 12, 12, 12, 12, 12, 0},
                        { 0,  0,  0,  0,  0,  0,  0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array1[i][j]);
            if(array1[i][j] > 10)
                count += 1;
            else
                count += array1[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(1,v);

    int array2[8][8] = {{ 0,  0,  0,  0,  0,  0, 0, 0},
                        {12, 12, 12, 12, 12, 12, 12, 0},
                        {12, 12,  0,  0,  0, 12, 12, 0},
                        {12,  0,  0,  0,  0,  0, 12, 0},
                        {12,  0,  0,  0,  0,  0, 12, 0},
                        {12, 12,  0,  0,  0, 12, 12, 0},
                        {12, 12, 12, 12, 12, 12, 12, 0},
                        { 0,  0,  0,  0,  0,  0,  0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array2[i][j]);
            if(array2[i][j] > 10)
                count += 1;
            else
                count += array2[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(2,v);
    // 第16关
    m_cardCount.insert(16, count);
    m_Data.insert(16, gameArray);
}

void dataConfig::Level17()
{
    QMap<int, QVector< QVector<int>> >gameArray;// 当前关卡数据
    int count = 0;// 卡片数
    int array0[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {1, 1, 0, 0, 0, 1, 1, 0},
                        {1, 1, 0, 1, 0, 1, 1, 0},
                        {1, 1, 0, 0, 0, 1, 1, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0}};

    QVector< QVector<int>> v;
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array0[i][j]);
            if(array0[i][j] > 10)
                count += 1;
            else
                count += array0[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(0,v);

    int array1[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0, 0, 0},
                        {0, 1, 1, 1, 1, 0, 0, 0},
                        {1, 1, 0, 0, 1, 1, 0, 0},
                        {1, 1, 0, 0, 1, 1, 0, 0},
                        {0, 1, 1, 1, 1, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array1[i][j]);
            if(array1[i][j] > 10)
                count += 1;
            else
                count += array1[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(1,v);

    int array2[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 0, 1, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 0, 1, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 0, 1, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array2[i][j]);
            if(array2[i][j] > 10)
                count += 1;
            else
                count += array2[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(2,v);
    // 第17关
    m_cardCount.insert(17, count);
    m_Data.insert(17, gameArray);
}

void dataConfig::Level18()
{
    QMap<int, QVector< QVector<int>> >gameArray;// 当前关卡数据
    int count = 0;// 卡片数
    int array0[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {1, 1, 0, 0, 0, 1, 1, 0},
                        {1, 1, 1, 0, 1, 1, 1, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {1, 0, 0, 1, 0, 0, 1, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {1, 1, 1, 0, 1, 1, 1, 0},
                        {1, 1, 0, 0, 0, 1, 1, 0}};

    QVector< QVector<int>> v;
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array0[i][j]);
            if(array0[i][j] > 10)
                count += 1;
            else
                count += array0[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(0,v);

    int array1[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {1, 1, 0, 0, 1, 1, 0, 0},
                        {1, 1, 0, 0, 1, 1, 0, 0},
                        {1, 0, 0, 0, 0, 1, 0, 0},
                        {1, 0, 0, 0, 0, 1, 0, 0},
                        {1, 1, 0, 0, 1, 1, 0, 0},
                        {1, 1, 0, 0, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array1[i][j]);
            if(array1[i][j] > 10)
                count += 1;
            else
                count += array1[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(1,v);

    int array2[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 0, 0, 0, 1, 0, 0},
                        {0, 1, 1, 0, 1, 1, 0, 0},
                        {0, 1, 0, 0, 0, 1, 0, 0},
                        {0, 1, 1, 0, 1, 1, 0, 0},
                        {0, 1, 0, 0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array2[i][j]);
            if(array2[i][j] > 10)
                count += 1;
            else
                count += array2[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(2,v);
    // 第18关
    m_cardCount.insert(18, count);
    m_Data.insert(18, gameArray);
}

void dataConfig::Level19()
{
    QMap<int, QVector< QVector<int>> >gameArray;// 当前关卡数据
    int count = 0;// 卡片数
    int array0[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0},
                        {0, 1, 1, 1, 1, 1, 0, 0},
                        {0, 1, 0, 0, 0, 1, 0, 0},
                        {1, 1, 0, 1, 0, 1, 1, 0},
                        {0, 1, 0, 0, 0, 1, 0, 0},
                        {0, 1, 1, 1, 1, 1, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0}};

    QVector< QVector<int>> v;
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array0[i][j]);
            if(array0[i][j] > 10)
                count += 1;
            else
                count += array0[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(0,v);

    int array1[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0, 0, 0},
                        {0, 1, 1, 1, 1, 0, 0, 0},
                        {1, 1, 1, 1, 1, 1, 0, 0},
                        {1, 1, 1, 1, 1, 1, 0, 0},
                        {0, 1, 1, 1, 1, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array1[i][j]);
            if(array1[i][j] > 10)
                count += 1;
            else
                count += array1[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(1,v);

    int array2[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 1, 1, 0, 1, 1, 0, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array2[i][j]);
            if(array2[i][j] > 10)
                count += 1;
            else
                count += array2[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(2,v);
    // 第19关
    m_cardCount.insert(19, count);
    m_Data.insert(19, gameArray);
}

void dataConfig::Level20()
{
    QMap<int, QVector< QVector<int>> >gameArray;// 当前关卡数据
    int count = 0;// 卡片数
    int array0[8][8] = {{0, 0, 0, 1, 0, 0, 0, 0},
                        {1, 1, 1, 1, 1, 1, 1, 0},
                        {0, 1, 1, 1, 1, 1, 0, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0},
                        {0, 1, 1, 1, 1, 1, 0, 0},
                        {1, 1, 1, 1, 1, 1, 1, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0}};

    QVector< QVector<int>> v;
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array0[i][j]);
            if(array0[i][j] > 10)
                count += 1;
            else
                count += array0[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(0,v);

    int array1[8][8] = {{0, 0, 1, 1, 0, 0, 0, 0},
                        {1, 1, 1, 1, 1, 1, 0, 0},
                        {0, 0, 1, 1, 0, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0, 0, 0},
                        {1, 1, 1, 1, 1, 1, 0, 0},
                        {0, 0, 1, 1, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array1[i][j]);
            if(array1[i][j] > 10)
                count += 1;
            else
                count += array1[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(1,v);

    int array2[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 1, 1, 1, 1, 0, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 1, 1, 1, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array2[i][j]);
            if(array2[i][j] > 10)
                count += 1;
            else
                count += array2[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(2,v);
    // 第20关
    m_cardCount.insert(20, count);
    m_Data.insert(20, gameArray);
}

void dataConfig::Level21()
{
    QMap<int, QVector< QVector<int>> >gameArray;// 当前关卡数据
    int count = 0;// 卡片数
    int array0[8][8] = {{0, 0, 0, 1, 1, 0, 0, 0},
                        {0, 0, 1, 0, 0, 1, 0, 0},
                        {0, 1, 0, 0, 0, 0, 1, 0},
                        {1, 0, 0, 0, 0, 0, 0, 1},
                        {1, 0, 0, 0, 0, 0, 0, 1},
                        {0, 1, 0, 0, 0, 0, 1, 0},
                        {0, 0, 1, 0, 0, 1, 0, 0},
                        {0, 0, 0, 1, 1, 0, 0, 0}};

    QVector< QVector<int>> v;
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array0[i][j]);
            if(array0[i][j] > 10)
                count += 1;
            else
                count += array0[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(0,v);

    int array1[8][8] = {{0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 1, 0, 0, 0, 1, 0, 0},
                        {1, 0, 0, 0, 0, 0, 1, 0},
                        {1, 0, 0, 0, 0, 0, 1, 0},
                        {1, 0, 0, 0, 0, 0, 1, 0},
                        {0, 1, 0, 0, 0, 1, 0, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array1[i][j]);
            if(array1[i][j] > 10)
                count += 1;
            else
                count += array1[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(1,v);

    int array2[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 1, 0, 0, 0},
                        {0, 0, 1, 1, 1, 1, 0, 0},
                        {0, 1, 1, 0, 0, 1, 1, 0},
                        {0, 1, 1, 0, 0, 1, 1, 0},
                        {0, 0, 1, 1, 1, 1, 0, 0},
                        {0, 0, 0, 1, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array2[i][j]);
            if(array2[i][j] > 10)
                count += 1;
            else
                count += array2[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(2,v);

    int array3[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0},
                        {0, 0, 1, 0, 1, 0, 0, 0},
                        {0, 1, 0, 0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 1, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array3[i][j]);
            if(array3[i][j] > 10)
                count += 1;
            else
                count += array3[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(3,v);
    // 第21关
    m_cardCount.insert(21, count);
    m_Data.insert(21, gameArray);
}

void dataConfig::Level22()
{
    QMap<int, QVector< QVector<int>> >gameArray;// 当前关卡数据
    int count = 0;// 卡片数
    int array0[8][8] = {{0, 1, 1, 1, 1, 1, 1, 0},
                        {1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 0, 0, 0, 1, 1},
                        {1, 1, 0, 0, 0, 0, 1, 1},
                        {1, 1, 0, 0, 0, 0, 1, 1},
                        {1, 1, 0, 0, 0, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1},
                        {0, 1, 1, 1, 1, 1, 1, 0}};

    QVector< QVector<int>> v;
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array0[i][j]);
            if(array0[i][j] > 10)
                count += 1;
            else
                count += array0[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(0,v);

    int array1[8][8] = {{0, 1, 1, 1, 1, 1, 0, 0},
                        {1, 1, 0, 0, 0, 1, 1, 0},
                        {1, 0, 0, 0, 0, 0, 1, 0},
                        {1, 0, 0, 0, 0, 0, 1, 0},
                        {1, 0, 0, 0, 0, 0, 1, 0},
                        {1, 1, 0, 0, 0, 1, 1, 0},
                        {0, 1, 1, 1, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array1[i][j]);
            if(array1[i][j] > 10)
                count += 1;
            else
                count += array1[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(1,v);

    int array2[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 1, 1, 1, 0, 0},
                        {0, 1, 1, 0, 0, 1, 1, 0},
                        {0, 1, 0, 0, 0, 0, 1, 0},
                        {0, 1, 0, 0, 0, 0, 1, 0},
                        {0, 1, 1, 0, 0, 1, 1, 0},
                        {0, 0, 1, 1, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array2[i][j]);
            if(array2[i][j] > 10)
                count += 1;
            else
                count += array2[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(2,v);

    int array3[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 1, 0, 0, 0, 1, 0, 0},
                        {0, 1, 0, 0, 0, 1, 0, 0},
                        {0, 1, 0, 0, 0, 1, 0, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array3[i][j]);
            if(array3[i][j] > 10)
                count += 1;
            else
                count += array3[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(3,v);
    // 第22关
    m_cardCount.insert(22, count);
    m_Data.insert(22, gameArray);
}

void dataConfig::Level23()
{
    QMap<int, QVector< QVector<int>> >gameArray;// 当前关卡数据
    int count = 0;// 卡片数
    int array0[8][8] = {{1, 0, 1, 1, 1, 1, 0, 1},
                        {1, 0, 1, 1, 1, 1, 0, 1},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {1, 1, 0, 0, 0, 0, 1, 1},
                        {1, 1, 0, 0, 0, 0, 1, 1},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {1, 0, 1, 1, 1, 1, 0, 1},
                        {1, 0, 1, 1, 1, 1, 0, 1}};

    QVector< QVector<int>> v;
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array0[i][j]);
            if(array0[i][j] > 10)
                count += 1;
            else
                count += array0[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(0,v);

    int array1[8][8] = {{1, 1, 1, 1, 1, 1, 1, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {1, 0, 1, 1, 1, 0, 1, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {1, 1, 1, 1, 1, 1, 1, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array1[i][j]);
            if(array1[i][j] > 10)
                count += 1;
            else
                count += array1[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(1,v);

    int array2[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 1, 0, 0, 0},
                        {0, 0, 0, 1, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array2[i][j]);
            if(array2[i][j] > 10)
                count += 1;
            else
                count += array2[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(2,v);

    int array3[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array3[i][j]);
            if(array3[i][j] > 10)
                count += 1;
            else
                count += array3[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(3,v);

    // 第23关
    m_cardCount.insert(23, count);
    m_Data.insert(23, gameArray);
}

void dataConfig::Level24()
{
    QMap<int, QVector< QVector<int>> >gameArray;// 当前关卡数据
    int count = 0;// 卡片数
    int array0[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 1, 1, 1, 1, 0},
                        {0, 0, 1, 1, 1, 1, 1, 0},
                        {0, 0, 1, 1, 1, 1, 1, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0, 0, 0},
                        {1, 1, 1, 1, 1, 1, 1, 0}};

    QVector< QVector<int>> v;
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array0[i][j]);
            if(array0[i][j] > 10)
                count += 1;
            else
                count += array0[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(0,v);

    int array1[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 1, 1, 1, 0, 0},
                        {0, 0, 1, 1, 1, 1, 0, 0},
                        {0, 0, 1, 0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0, 0, 0, 0},
                        {1, 1, 1, 1, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array1[i][j]);
            if(array1[i][j] > 10)
                count += 1;
            else
                count += array1[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(1,v);

    int array2[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 1, 1, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 0},
                        {0, 1, 1, 1, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array2[i][j]);
            if(array2[i][j] > 10)
                count += 1;
            else
                count += array2[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(2,v);

    int array3[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 0, 1, 0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0, 0, 0, 0},
                        {0, 1, 1, 1, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array3[i][j]);
            if(array2[i][j] > 10)
                count += 1;
            else
                count += array3[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(3,v);
    // 第24关
    m_cardCount.insert(24, count);
    m_Data.insert(24, gameArray);
}

void dataConfig::Level25()
{
    QMap<int, QVector< QVector<int>> >gameArray;// 当前关卡数据
    int count = 0;// 卡片数
    int array0[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 1, 1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 0, 0, 0, 1},
                        {0, 1, 0, 1, 1, 1, 0, 1},
                        {0, 1, 0, 1, 0, 1, 0, 1},
                        {0, 1, 0, 1, 1, 1, 0, 1},
                        {0, 1, 0, 0, 0, 0, 0, 1},
                        {0, 1, 1, 1, 0, 1, 1, 1}};

    QVector< QVector<int>> v;
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array0[i][j]);
            if(array0[i][j] > 10)
                count += 1;
            else
                count += array0[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(0,v);

    int array1[8][8] = {{1, 1, 1, 0, 0, 1, 1, 1},
                        {1, 0, 0, 0, 0, 0, 0, 1},
                        {1, 0, 1, 1, 1, 1, 0, 1},
                        {1, 0, 1, 0, 0, 1, 0, 1},
                        {1, 0, 1, 0, 0, 1, 0, 1},
                        {1, 0, 1, 1, 1, 1, 0, 1},
                        {1, 0, 0, 0, 0, 0, 0, 1},
                        {1, 1, 1, 0, 0, 1, 1, 1}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array1[i][j]);
            if(array1[i][j] > 10)
                count += 1;
            else
                count += array1[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(1,v);

    int array2[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 1, 0, 0, 0, 1, 1},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0, 1, 0, 0},
                        {0, 1, 0, 0, 1, 0, 0, 1},
                        {0, 0, 0, 1, 0, 1, 0, 0},
                        {0, 1, 1, 0, 0, 0, 1, 1},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array2[i][j]);
            if(array2[i][j] > 10)
                count += 1;
            else
                count += array2[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(2,v);
    // 第25关
    m_cardCount.insert(25, count);
    m_Data.insert(25, gameArray);
}

void dataConfig::Level26()
{
    QMap<int, QVector< QVector<int>> >gameArray;// 当前关卡数据
    int count = 0;// 卡片数
    int array0[8][8] = {{1, 0, 0, 0, 0, 0, 0, 1},
                        {1, 1, 0, 0, 0, 0, 1, 1},
                        {0, 1, 1, 0, 0, 1, 1, 0},
                        {0, 0, 1, 1, 1, 1, 0, 0},
                        {0, 0, 1, 1, 1, 1, 0, 0},
                        {0, 1, 1, 0, 0, 1, 1, 0},
                        {1, 1, 0, 0, 0, 0, 1, 1},
                        {1, 0, 0, 0, 0, 0, 0, 1}};

    QVector< QVector<int>> v;
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array0[i][j]);
            if(array0[i][j] > 10)
                count += 1;
            else
                count += array0[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(0,v);

    int array1[8][8] = {{1, 0, 0, 0, 0, 0, 1, 0},
                        {1, 1, 0, 0, 0, 1, 1, 0},
                        {0, 1, 1, 0, 1, 1, 0, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 1, 1, 1, 1, 1, 0, 0},
                        {1, 1, 0, 0, 0, 1, 1, 0},
                        {1, 0, 0, 0, 0, 0, 1, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array1[i][j]);
            if(array1[i][j] > 10)
                count += 1;
            else
                count += array1[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(1,v);

    int array2[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 0, 0, 0, 0, 1, 0},
                        {0, 1, 1, 0, 0, 1, 1, 0},
                        {0, 0, 1, 1, 1, 1, 0, 0},
                        {0, 0, 1, 1, 1, 1, 0, 0},
                        {0, 1, 1, 0, 0, 1, 1, 0},
                        {0, 1, 0, 0, 0, 0, 1, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array2[i][j]);
            if(array2[i][j] > 10)
                count += 1;
            else
                count += array2[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(2,v);
    // 第26关
    m_cardCount.insert(26, count);
    m_Data.insert(26, gameArray);
}

void dataConfig::Level27()
{
    QMap<int, QVector< QVector<int>> >gameArray;// 当前关卡数据
    int count = 0;// 卡片数
    int array0[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 1, 1, 1, 1, 0},
                        {0, 0, 0, 1, 1, 1, 0, 0},
                        {0, 0, 0, 1, 1, 1, 0, 0},
                        {0, 0, 0, 1, 1, 1, 0, 0},
                        {0, 0, 1, 1, 1, 1, 1, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    QVector< QVector<int>> v;
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array0[i][j]);
            if(array0[i][j] > 10)
                count += 1;
            else
                count += array0[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(0,v);

    int array1[8][8] = {{0, 0, 0, 1, 1, 0, 0, 0},
                        {0, 0, 1, 1, 1, 1, 0, 0},
                        {0, 0, 0, 1, 1, 0, 0, 0},
                        {0, 0, 0, 1, 1, 0, 0, 0},
                        {0, 0, 0, 1, 1, 0, 0, 0},
                        {0, 0, 0, 1, 1, 0, 0, 0},
                        {0, 0, 1, 1, 1, 1, 0, 0},
                        {0, 0, 0, 1, 1, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array1[i][j]);
            if(array1[i][j] > 10)
                count += 1;
            else
                count += array1[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(1,v);

    int array2[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 1, 1, 0, 0},
                        {0, 0, 0, 0, 1, 0, 0, 0},
                        {0, 0, 0, 0, 1, 0, 0, 0},
                        {0, 0, 0, 1, 0, 1, 0, 0},
                        {0, 0, 0, 0, 1, 0, 0, 0},
                        {0, 0, 0, 0, 1, 0, 0, 0},
                        {0, 0, 0, 1, 1, 1, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array2[i][j]);
            if(array2[i][j] > 10)
                count += 1;
            else
                count += array2[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(2,v);
    // 第27关
    m_cardCount.insert(27, count);
    m_Data.insert(27, gameArray);
}

void dataConfig::Level28()
{
    QMap<int, QVector< QVector<int>> >gameArray;// 当前关卡数据
    int count = 0;// 卡片数
    int array0[8][8] = {{0, 1, 1, 1, 1, 1, 1, 0},
                        {1, 1, 1, 1, 1, 1, 1, 1},
                        {0, 0, 0, 1, 1, 0, 0, 0},
                        {0, 0, 0, 1, 1, 0, 0, 0},
                        {0, 0, 0, 1, 1, 0, 0, 0},
                        {0, 0, 0, 1, 1, 0, 0, 0},
                        {1, 1, 1, 1, 1, 1, 1, 1},
                        {0, 1, 1, 1, 1, 1, 1, 0}};

    QVector< QVector<int>> v;
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array0[i][j]);
            if(array0[i][j] > 10)
                count += 1;
            else
                count += array0[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(0,v);

    int array1[8][8] = {{1, 1, 1, 1, 1, 1, 1, 0},
                        {0, 1, 1, 1, 1, 1, 0, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 0, 1, 0, 1, 0, 0, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 1, 1, 1, 1, 1, 0, 0},
                        {1, 1, 1, 1, 1, 1, 1, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array1[i][j]);
            if(array1[i][j] > 10)
                count += 1;
            else
                count += array1[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(1,v);

    int array2[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 1, 1, 1, 1, 1, 0},
                        {0, 0, 1, 0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0, 1, 0, 0},
                        {0, 1, 1, 1, 1, 1, 1, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array2[i][j]);
            if(array2[i][j] > 10)
                count += 1;
            else
                count += array2[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(2,v);
    // 第28关
    m_cardCount.insert(28, count);
    m_Data.insert(28, gameArray);
}

void dataConfig::Level29()
{
    QMap<int, QVector< QVector<int>> >gameArray;// 当前关卡数据
    int count = 0;// 卡片数
    int array0[8][8] = {{1, 1, 1, 0, 0, 0, 0, 0},
                        {1, 1, 1, 0, 0, 0, 0, 0},
                        {1, 1, 1, 1, 1, 1, 0, 0},
                        {1, 1, 1, 0, 1, 1, 1, 0},
                        {1, 1, 1, 1, 1, 1, 1, 0},
                        {0, 1, 1, 1, 1, 1, 1, 0},
                        {0, 0, 0, 0, 1, 1, 1, 0},
                        {0, 0, 0, 0, 1, 1, 1, 0}};

    QVector< QVector<int>> v;
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array0[i][j]);
            if(array0[i][j] > 10)
                count += 1;
            else
                count += array0[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(0,v);

    int array1[8][8] = {{1, 1, 1, 0, 0, 0, 0, 0},
                        {1, 0, 1, 0, 0, 0, 0, 0},
                        {1, 0, 1, 1, 1, 0, 0, 0},
                        {1, 0, 0, 0, 0, 1, 0, 0},
                        {0, 1, 1, 1, 0, 1, 0, 0},
                        {0, 0, 0, 1, 0, 1, 0, 0},
                        {0, 0, 0, 1, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};


    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array1[i][j]);
            if(array1[i][j] > 10)
                count += 1;
            else
                count += array1[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(1,v);

    int array2[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 1, 1, 1, 0, 0, 0, 0},
                        {0, 1, 0, 1, 0, 0, 0, 0},
                        {0, 1, 0, 1, 1, 1, 0, 0},
                        {0, 1, 1, 1, 0, 1, 0, 0},
                        {0, 0, 0, 1, 0, 1, 0, 0},
                        {0, 0, 0, 1, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};


    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array2[i][j]);
            if(array2[i][j] > 10)
                count += 1;
            else
                count += array2[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(2,v);
    // 第29关
    m_cardCount.insert(29, count);
    m_Data.insert(29, gameArray);
}

void dataConfig::Level30()
{
    QMap<int, QVector< QVector<int>> >gameArray;// 当前关卡数据
    int count = 0;// 卡片数
    int array0[8][8] = {{0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 1, 1, 1, 1, 1, 0, 0},
                        {0, 1, 1, 1, 1, 1, 0, 0},
                        {0, 1, 1, 1, 1, 1, 0, 0},
                        {0, 1, 1, 1, 1, 1, 0, 0},
                        {0, 1, 1, 1, 1, 1, 0, 0},
                        {0, 1, 1, 1, 1, 1, 0, 0},
                        {0, 0, 1, 1, 1, 1, 0, 0}};

    QVector< QVector<int>> v;
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array0[i][j]);
            if(array0[i][j] > 10)
                count += 1;
            else
                count += array0[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(0,v);

    int array1[8][8] = {{0, 1, 1, 1, 1, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0, 0, 0},
                        {0, 1, 1, 1, 1, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0, 0, 0},
                        {0, 1, 1, 1, 1, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0, 0, 0},
                        {0, 1, 1, 1, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array1[i][j]);
            if(array1[i][j] > 10)
                count += 1;
            else
                count += array1[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(1,v);

    int array2[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 0, 1, 1, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array2[i][j]);
            if(array2[i][j] > 10)
                count += 1;
            else
                count += array2[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(2,v);

    int array3[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array3[i][j]);
            if(array3[i][j] > 10)
                count += 1;
            else
                count += array3[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(3,v);
    // 第30关
    m_cardCount.insert(30, count);
    m_Data.insert(30, gameArray);
}


/* *********************** 模板 ***************************
    QMap<int, QVector< QVector<int>> >gameArray;// 当前关卡数据
    int count = 0;// 卡片数
    int array0[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    QVector< QVector<int>> v;
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array0[i][j]);
            if(array0[i][j] > 10)
                count += 1;
            else
                count += array0[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(0,v);

    int array1[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array1[i][j]);
            if(array1[i][j] > 10)
                count += 1;
            else
                count += array1[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(1,v);

    int array2[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    v.clear();
    for(int i = 0 ; i < 8;i++)
    {
        QVector<int>vv;
        for(int j = 0 ; j < 8;j++)
        {
            vv.push_back(array2[i][j]);
            if(array2[i][j] > 10)
                count += 1;
            else
                count += array2[i][j];
        }
        v.push_back(vv);
    }
    gameArray.insert(2,v);
    // 第N关
    m_cardCount.insert(N, count);
    m_Data.insert(N, gameArray);
*/


