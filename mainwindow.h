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
    void on_listButton_clicked();
    //void updateTimerDisplay();
    void initButtons();
    void playCurrentSong();
    void setButtonStyle(QPushButton * button,const QString & filename);
    void setBackGround(const QString & filename);
    void loadList(const QString & filepath);



private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
    QString currentFilePath;// 保存当前播放的文件路径
    bool isUserDragging = false; // 标记用户是否正在拖动
    bool isListVisible = true; // 初始假设列表是可见的
    QString formatTime(qint64 milliseconds);
    void updateTimerDisplay();

    PLAYMODE m_mode;//当前播放模式

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    QPixmap m_originalBackground; // 保存原始背景图片
    void updateBackground(); // 更新背景的函数
};
#endif // MAINWINDOW_H
