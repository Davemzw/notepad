#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"highlighter.h"
#include"myhistorydialog.h"
#include<QDialog>
#include"newmainwindow.h"
#include<QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionnew_triggered();

    void on_actionsave_triggered();

    void on_actionopen_triggered();

    void on_actioncexiao_triggered();

    void on_actionhuifu_triggered();

    void on_actioncut_triggered();

    void on_actioncopy_triggered();

    void on_actionzhantie_triggered();

    void on_actionhistory_triggered();

    void on_actionsearch_triggered();

    void on_actiontihuan_triggered();

    void on_actionzdhh_triggered();

    void on_actionyfglfa_triggered();

    void on_actionztl_triggered();

    void on_action_A_triggered();

private:
    Ui::MainWindow *ui;
    bool userEditConfirmed();
    QString filepath;
    bool textChanged;
    Highlighter *highlighter;
     myhistoryDialog *dlg;
     QLabel statusCursorLabel;
     QLabel statusLabel;
};
#endif // MAINWINDOW_H
