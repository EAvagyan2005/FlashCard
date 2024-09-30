#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QSettings>
#include <QLabel>
#include <QStackedLayout>
#include <QStackedWidget>



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private:
    QWidget *centralWidget;
    QVBoxLayout* mainLayout{}, *dataManagerLayout{}, *flashcardLayout{};


};
#endif // MAINWINDOW_H
