#ifndef WAITINGDIALOG_H
#define WAITINGDIALOG_H

#include <QDialog>
#include <QTimer>
#include <QKeyEvent>

namespace Ui {
class WaitingDialog;
}

class WaitingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WaitingDialog(QWidget *parent = 0);
    ~WaitingDialog();
    void Start();
    void Stop();
private:
    virtual void paintEvent(QPaintEvent *);
    virtual void keyPressEvent(QKeyEvent *event);

private:
    Ui::WaitingDialog *ui;
    QMovie* pMovie;
    QTimer* m_waitForTime;
};

#endif // WAITINGDIALOG_H
