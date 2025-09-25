#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
// 使用前向声明，减少编译依赖
#include <QPushButton>
class QMediaPlayer;
class QAudioOutput;

QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;}
QT_END_NAMESPACE

enum PLAYMODE
{
    ORDER_MODE,
    RANDOM_MODE,
    CIRCLE_MODE
};
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_playPauseButton_clicked();
    void on_modeButton_clicked();//播放模式
    void on_nextButton_clicked();
    void on_prevButton_clicked();
    //void updateTimerDisplay();
    void initButtons();
    void playCurrentSong();
    void setButtonStyle(QPushButton * button,const QString & filename);
    void setBackGround(const QString & filename);
    void listButton(const QString & filepath);

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
    QString currentFilePath;// 新增：保存当前播放的文件路径
   // QString formatTime(qint64 milliseconds);
    bool isUserDragging = false; // 标记用户是否正在拖动


    PLAYMODE m_mode;//当前播放模式


};
#endif // MAINWINDOW_H
