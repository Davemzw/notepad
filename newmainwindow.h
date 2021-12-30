#ifndef NEWMAINWINDOW_H
#define NEWMAINWINDOW_H

#include <QMainWindow>
#include"highlighter.h"
#include"myhistorydialog.h"
#include<QLabel>

namespace Ui {
class newMainWindow;
}

class newMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit newMainWindow(QWidget *parent = nullptr);
    ~newMainWindow();
     void openfile(QString text);

private slots:
     void on_actionnew_triggered();

     void on_actionsave_triggered();

     void on_actionopen_triggered();

     void on_actionhistory_triggered();

     void on_actioncexiao_triggered();

     void on_actionhuifu_triggered();

     void on_actioncut_triggered();

     void on_actioncopy_triggered();

     void on_actionzhantie_triggered();

     void on_actiontihuan_triggered();

     void on_actionsearch_triggered();

     void on_actiongbzt_triggered();

     void on_actionztl_triggered();

     void on_action_A_triggered();

private:
    Ui::newMainWindow *ui;
    bool userEditConfirmed();
    QString filepath;
    bool textChanged;
    Highlighter *highlighter;
     myhistoryDialog *dlg;
     QLabel statusCursorLabel;
     QLabel statusLabel;
};

#endif // NEWMAINWINDOW_H
