#include "waitingdialog.h"
#include "ui_waitingdialog.h"

#include <QMovie>
#include <QPainter>
#include <QTimer>
#include <QDebug>

WaitingDialog::WaitingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WaitingDialog)
{
    ui->setupUi(this);

//    setAttribute(Qt::WA_DeleteOnClose);// 调用close()会执行析构函数
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint| Qt::X11BypassWindowManagerHint);
    setAttribute(Qt::WA_TranslucentBackground, true);

    QString strgif = ":/res/loading.gif";
    pMovie = new QMovie(strgif);
    ui->image->setMovie(pMovie);

    m_waitForTime = new QTimer(this);
    m_waitForTime->setInterval(600);
    connect(m_waitForTime, &QTimer::timeout, this, &WaitingDialog::Stop);

    QPainterPath path;
    QRectF rect = QRectF(0,0,130,89);
    path.addRoundRect(rect,4,4);
    QPolygon polygon = path.toFillPolygon().toPolygon();
    QRegion region(polygon);
    setMask(region);

}

WaitingDialog::~WaitingDialog()
{
    if (m_waitForTime->isActive())
        m_waitForTime->stop();
    delete ui;
}

void WaitingDialog::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.fillRect(rect(), QColor(0x55,0x55,0x55,204));
}

void WaitingDialog::Start()
{
    if (m_waitForTime->isActive())
        m_waitForTime->stop();
    pMovie->start();
    m_waitForTime->start();
    this->exec();
}

void WaitingDialog::Stop()
{
    if (m_waitForTime->isActive())
        m_waitForTime->stop();
    pMovie->stop();
    this->close();
}

void WaitingDialog::keyPressEvent(QKeyEvent *event)
{
   switch(event->key()) {
     //进行界面退出，重写Esc键，否则重写reject()方法
      case Qt::Key_Escape:
          event->accept();
          break;

      default:
         QDialog::keyPressEvent(event);
   }
}
