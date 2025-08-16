#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,player(new QMediaPlayer(this))//初始化
    ,audioOutput(new QAudioOutput(this))//初始化音频输出
    ,currentFilePath("")
{
    ui->setupUi(this);

    //将播放器与音频输出关联

    audioOutput->setVolume(0.7f); // 设置实际音量
    ui->volumeSlider->setRange(0, 100);   // 0% ~ 100%
    ui->volumeSlider->setValue(70);       // 默认 70%
    player->setAudioOutput(audioOutput);
    /********************************音量调节滑块**************************************/

    connect(ui->volumeSlider, &QSlider::valueChanged, this, [this](int value){  // 当滑块值改变时，执行这里
        audioOutput->setVolume(value/100.0);//
        qDebug() << "音量已设置为:" << value << "%";
    });

    //初始显示播放
    ui->playPauseButton->setText("播放");
}

MainWindow::~MainWindow()
{
    delete ui;
}

/********************************播放**************************************/
void MainWindow::on_playPauseButton_clicked() //转到槽。适用场景：按钮点击、简单事件。隐式调用（Qt 内部自动 connect）
{
    // 如果当前没有设置任何文件，且 currentFilePath 为空，则提示
    if(currentFilePath.isEmpty()){
        QMessageBox::warning(this,"提示","请先选择一首歌曲");
        return;
    }

    // 检查文件是否存在
    if(!QFile::exists(currentFilePath)){
        QMessageBox::warning(this,"错误","文件不存在！\n请检查路径：" +currentFilePath);
        return;
    }


    //播放与暂停
    if(player->playbackState() == QMediaPlayer::PlayingState){
        player->pause();
        ui->playPauseButton->setText("播放");// 按钮文字变成“播放”
        qDebug() << "已暂停";
    }else if(player->playbackState() == QMediaPlayer::StoppedState){
        player->setSource(QUrl::fromLocalFile(currentFilePath));
        player->play();
        ui->playPauseButton->setText("暂停");

        qDebug() << "开始播放...";
        qDebug() << "当前音量 (0.0-1.0):" << audioOutput->volume(); // 调试：打印当前音量
    }else{
        player->play();
        ui->playPauseButton->setText("暂停");
        qDebug() << "开始播放...";
        qDebug() << "当前音量 (0.0-1.0):" << audioOutput->volume(); // 调试：打印当前音量
    }
    // 调试输出
    qDebug() << "当前文件路径: " << currentFilePath;
    qDebug() << "播放器状态: " << player->playbackState();

}

/********************************选择音乐**************************************/
void MainWindow::on_pushButton_clicked()
{
    QString filepath = QFileDialog :: getOpenFileName(this,"选择音乐文件","F:/QT_project/ncmdump", "音频文件 (*.mp3 *.wav);;所有文件 (*)");

    //如果用户选择了文件
    if(!filepath.isEmpty()){ // isEmpty() 是 QString 的一个函数，意思是“这个字符串是不是空的？”
        player->pause();
        ui->playPauseButton->setText("播放");
        currentFilePath = filepath;

        QUrl url = QUrl::fromLocalFile(filepath);
        player->setSource(url); // setSource() 是 QMediaPlayer 的函数，播放文件

        // 新增：提取并显示音乐文件名
        QFileInfo fileInfo(filepath);
        QString musicName = fileInfo.baseName(); // 获取文件名（不带扩展名）
        ui->musicNameLabel->setText(musicName);  // 更新标签显示

        qDebug() << "已加载并播放：" << filepath;
        qDebug() << "当前音量 (0.0-1.0):" << audioOutput->volume(); // 调试：打印当前音量
    }
}

