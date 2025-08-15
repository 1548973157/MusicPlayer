#include "mainwindow.h"
// ↪ 自定义头文件：包含你自己的 MainWindow 类声明
//   比如：按钮、播放器指针、槽函数等都在这里定义
//   必须包含，否则编译器不知道 MainWindow 是什么

#include "ui_mainwindow.h"
// ↪ Qt 自动生成的界面头文件
//   当你用 Qt Designer 设计界面（.ui 文件）后，
//   Qt 会自动生成这个文件，里面包含所有控件的指针
//   比如：ui->playButton、ui->label 等
//   没有它，你就无法访问界面上的按钮、标签等

#include <QMediaPlayer>
// ↪ Qt 多媒体模块的核心类：用于播放音频（MP3、WAV 等）和视频
//   提供 play()、pause()、setSource() 等方法
//   必须包含才能使用音乐播放功能
//   注意：需要在 .pro 文件中添加 QT += multimedia

#include <QAudioOutput>
// ↪ Qt 6 中控制音量、音频输出的类
//   在 Qt 6 里，QMediaPlayer 不再直接支持 setVolume()
//   必须通过 QAudioOutput 来设置音量、选择输出设备（扬声器、耳机等）
//   所以必须包含它，否则无法调节音量

#include <QFile>
// ↪ 用于操作文件系统：检查文件是否存在、读写文件等
//   我们用它来判断音乐文件路径是否正确
//   比如：QFile::exists(filePath) 检查 MP3 文件是否存在
//   避免播放一个不存在的文件导致崩溃

#include <QMessageBox>
// ↪ 弹出对话框的类：显示提示、警告、错误信息
//   比如：当文件不存在时，弹出警告框提醒

#include <QDebug>
// ↪ 调试输出工具：在 Qt Creator 的“应用程序输出”面板打印信息
//   比如：qDebug() << "正在播放:" << filePath;
//   帮助你调试程序，查看变量值、播放状态、路径是否正确
//   开发阶段非常有用，相当于“打印日志”

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,player(new QMediaPlayer(this))//初始化
    ,audioOutput(new QAudioOutput(this))//初始化音频输出
{
    ui->setupUi(this);

    //将播放器与音频输出关联
    player->setAudioOutput(audioOutput);

    //设置默认音量（0.0 ~ 1.0）
    audioOutput->setVolume(0.7f);// 70% 音量
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_playButton_clicked()
{
    //1.定义文件路径
    QString filepath = "F:/QT_project/Music/Jamie Berry - Delight (Original Mix).mp3";

    //2. 检查文件是否存在
    if(!QFile::exists(filepath)){
        QMessageBox::warning(this,"错误","文件不存在！\n请检查路径：" +filepath);
        return;
    }

    //3. 创建 URL 对象（现在定义了！
    QUrl url = QUrl::fromLocalFile(filepath);
    //4. 设置音频源
    player ->setSource(url);
    //5. 播放
    player ->play();
    //  6. 调试输出（全部正确！）
    qDebug()<<" 正在播放 " << filepath;
    qDebug()<< "当前状态 " << player->playbackState();
    qDebug()<< "当前音量 " << audioOutput->volume();
    qDebug()<< "文件路径 " << url.toString();
}

