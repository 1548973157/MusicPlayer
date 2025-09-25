#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMediaPlayer>
#include <QAudioOutput>

/*文件操作*/
#include <QFile>
#include <QDir>
#include <QFileInfo>
/*对话框*/
#include <QMessageBox>
/*时间函数*/
#include <time.h>
#include <QTimer>
#include <QDebug>
#include <QFileDialog>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , player(new QMediaPlayer(this))      //
    , audioOutput(new QAudioOutput(this)) //
    , m_mode(ORDER_MODE)
// player和audioOutput在函数体内创建
{
    player->setAudioOutput(audioOutput);  // <<<< 放在最前面！
    ui->setupUi(this);
    setBackGround(":/Image/2A4E83B8FB50B24096D8C3975A128C3D.jpg");
    this->setMinimumSize(800, 500);//设置最小窗口尺寸
    //按钮大小
    initButtons();

    QString musicDir = "F:/QT_project/ncmdump";
    loadList(musicDir);

    srand(time(NULL));//随机数种子
    audioOutput->setVolume(0.7f); // 设置实际音量
    ui->volumeSlider->setRange(0, 100);   // 0% ~ 100%
    ui->volumeSlider->setValue(70);       // 默认 70%

    // 当双击列表中的歌曲时，播放它
    connect(ui->musicList, &QListWidget::itemDoubleClicked, this, [this](QListWidgetItem *item){
        currentFilePath = item->data(Qt::UserRole).toString(); // 获取路径
        playCurrentSong(); // 调用播放逻辑
    });


    // 连接信号与槽：播放结束自动下一首
    connect(player, &QMediaPlayer::mediaStatusChanged, this, [this](QMediaPlayer::MediaStatus status){
        // 当媒体播放到末尾时触发下一首
        if (status == QMediaPlayer::EndOfMedia) {
            on_nextButton_clicked();  // 直接调用正确的函数
        }
    });
    /********************************音量调节滑块**************************************/

    connect(ui->volumeSlider, &QSlider::valueChanged, this, [this](int value){  // 当滑块值改变时，执行这里
        audioOutput->setVolume(value/100.0);//
        qDebug() << "音量已设置为:" << value << "%";
    });
    /********************************进程滑块**************************************/
    connect(player, &QMediaPlayer::positionChanged, this, [this](qint64 position) {
        if (!isUserDragging) { // 只有非拖动状态才自动更新
            qint64 duration = player->duration();
            if (duration > 0) {
                int value = (position * 1000) / duration;
                ui->progressSlider->setValue(value);
            }
        }

        // 更新时间显示（可选）
        updateTimerDisplay(); // 我们下面定义这个函数
    });

    connect(player, &QMediaPlayer::durationChanged, this, [this](qint64 duration) {
        Q_UNUSED(duration);
        // duration 改变时也更新一次（比如换歌）
        if (!isUserDragging) {
            qint64 pos = player->position();
            qint64 dur = player->duration();
            if (dur > 0) {
                ui->progressSlider->setValue((pos * 1000) / dur);
            }
        }
        updateTimerDisplay(); // 初始总时间
    });

    // 用户开始拖动
    connect(ui->progressSlider, &QSlider::sliderPressed, this, [this]() {
        isUserDragging = true;
    });


    // 用户松开滑块 → 跳转到该位置
    connect(ui->progressSlider, &QSlider::sliderReleased, this, [this]() {
        isUserDragging = false;
        qint64 duration = player->duration();
        qint64 newPos = (ui->progressSlider->value() * duration) / 1000;
        player->setPosition(newPos);
        qDebug() << "跳转到位置:" << formatTime(newPos);
    });
 /********************************playbackStateChanged信号来准确跟踪状态**************************************/
    connect(player, &QMediaPlayer::playbackStateChanged, this, [this](QMediaPlayer::PlaybackState state){
        qDebug() << "播放状态改变:" << state;

        switch(state) {
        case QMediaPlayer::PlayingState:
            ui->playPauseButton->setIcon(QIcon(":/Icon/play.png"));
            // 更新歌曲名称显示
            if(!currentFilePath.isEmpty()) {
                ui->musicNameLabel->setText(QFileInfo(currentFilePath).baseName());
            }
            break;
        case QMediaPlayer::PausedState:
            ui->playPauseButton->setIcon(QIcon(":/Icon/Pause.png"));
            break;
        case QMediaPlayer::StoppedState:
            ui->playPauseButton->setIcon(QIcon(":/Icon/Pause.png"));
            break;
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

/********************************背景**************************************/
void MainWindow::setBackGround(const QString & filename){
    m_originalBackground = QPixmap(filename); // 保存原始图片
    if (m_originalBackground.isNull()) {
        qDebug() << "背景图片加载失败:" << filename;
        return;
    }
    updateBackground();
}
void MainWindow::updateBackground()
{
    if (m_originalBackground.isNull()) {
        return;
    }

    QSize windowSize = this->size();
    QPixmap scaledPixmap = m_originalBackground.scaled(windowSize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, QBrush(scaledPixmap));
    this->setPalette(palette);
    this->setAutoFillBackground(true);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event); // 调用基类处理
    updateBackground(); // 窗口大小改变时更新背景
}

/********************************按钮UI**************************************/
void MainWindow::setButtonStyle(QPushButton * button,const QString & filename){
    button->setFixedSize(40,40);
    button->setIcon(QIcon(filename));
    //图标大小
    button->setIconSize(QSize(ui->prevButton->width(),ui->prevButton->height()));
    /*设置图表背景透明*/
    button->setStyleSheet("background-color:transparent");
    //将播放器与音频输出关联

}
void MainWindow::initButtons(){
    setButtonStyle(ui->prevButton,":/Icon/Prev.png");
    setButtonStyle(ui->nextButton,":/Icon/Next.png");
    setButtonStyle(ui->playPauseButton,":/Icon/Pause.png");
    setButtonStyle(ui->listButton,":/Icon/List.png");
    setButtonStyle(ui->modeButton,":/Icon/Order.png");

    connect(ui->modeButton,&QPushButton::clicked,this, &MainWindow::on_modeButton_clicked);
    connect(ui->nextButton,&QPushButton::clicked,this, &MainWindow::on_nextButton_clicked);
    connect(ui->prevButton,&QPushButton::clicked,this, &MainWindow::on_prevButton_clicked);
}
/********************************下一首逻辑**************************************/
void MainWindow::on_nextButton_clicked()
{
    int currentRow = ui->musicList->currentRow();//当前播放
    int totalCount = ui->musicList->count();
    if (totalCount == 0)return;
    int nextRow = 0;
    if (m_mode == ORDER_MODE)
    {
        nextRow = (currentRow + 1) % totalCount;
    }
    else if(m_mode == RANDOM_MODE)
    {
        if (totalCount == 1) {
            nextRow = 0;
        } else {
            do {
                nextRow = rand() % totalCount;
            } while(currentRow == nextRow);
        }
    }
    else if(m_mode == CIRCLE_MODE)
    {
        nextRow = currentRow;
    }

    ui->musicList->setCurrentRow(nextRow);
    currentFilePath = ui->musicList->currentItem()->data(Qt::UserRole).toString();

   playCurrentSong();
}
/********************************上一首逻辑**************************************/
void MainWindow::on_prevButton_clicked()
{
    int currentRow = ui->musicList->currentRow();//当前播放
    int totalCount = ui->musicList->count();
    if (totalCount == 0)return;
    int prevRow = 0;
    if (m_mode == ORDER_MODE)
    {
        prevRow = currentRow - 1;
        if (prevRow < 0)
        {
            prevRow = totalCount - 1;
        }
    }
    else if(m_mode == RANDOM_MODE) {
        if (totalCount == 1) {
            prevRow = 0;
        } else {
            do {
                prevRow = rand() % totalCount;
            } while(currentRow == prevRow);
        }
    }
    else if(m_mode == CIRCLE_MODE)
    {
        prevRow = currentRow;
    }

    ui->musicList->setCurrentRow(prevRow);
    currentFilePath = ui->musicList->currentItem()->data(Qt::UserRole).toString();

    playCurrentSong();
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
        //ui->playPauseButton->setIcon(QIcon(":/Icon/Pause.png"));
        qDebug() << "已暂停";
    }else{
        if(player->source().toString() != QUrl::fromLocalFile(currentFilePath).toString()){
            player->setSource(QUrl::fromLocalFile(currentFilePath));
        }
        player->play();  // 直接播放，不调用playCurrentSong()
    }

    // 调试输出
    qDebug() << "当前文件路径: " << currentFilePath;
    qDebug() << "播放器状态: " << player->playbackState();

}
/********************************播放当前歌曲**************************************/
void MainWindow::playCurrentSong()
{
    if (currentFilePath.isEmpty()) return;

    if (!QFile::exists(currentFilePath)) {
        QMessageBox::warning(this, "错误", "文件不存在：" + currentFilePath);
        return;
    }

    // 设置音频源
    if(player->source().toString() != QUrl::fromLocalFile(currentFilePath).toString()){
        player->setSource(QUrl::fromLocalFile(currentFilePath));
        qDebug() << "设置新的音频源:" << QFileInfo(currentFilePath).fileName();
    }

    // 开始播放
    player->play();

    qDebug() << "开始播放:" << currentFilePath;
}
/********************************播放模式**************************************/
void MainWindow::on_modeButton_clicked()
{
    if(m_mode == ORDER_MODE)
    {
        m_mode = RANDOM_MODE;
        ui->modeButton->setIcon(QIcon(":/Icon/Random.png"));
    }
    else if(m_mode == RANDOM_MODE)
    {
        m_mode = CIRCLE_MODE;
        ui->modeButton->setIcon(QIcon(":/Icon/Circle.png"));
    }
    else if(m_mode == CIRCLE_MODE)
    {
        m_mode = ORDER_MODE;
        ui->modeButton->setIcon(QIcon(":/Icon/Order.png"));
    }

}
void MainWindow::updateTimerDisplay()
{
    qint64 pos = player->position();
    qint64 dur = player->duration();

    // 确保 dur > 0，避免除以 0
    if (dur <= 0) {
        ui->currentTimeLabel->setText("00:00");
        ui->totalTimeLabel->setText("00:00");
        return;
    }

    ui->currentTimeLabel->setText(formatTime(pos));
    ui->totalTimeLabel->setText(formatTime(dur));
}
/********************************列表按钮**************************************/
void MainWindow::on_listButton_clicked()
{
    if (ui->musicList->isVisible()) {
        // 当前可见 → 隐藏
        ui->musicList->setVisible(false);
        isListVisible = false;
        //ui->listButton->setIcon(QIcon(":/Icon/List_off.png")); // 可选：切换图标
        qDebug() << "播放列表已隐藏";
    } else {
        // 当前隐藏 → 显示
        ui->musicList->setVisible(true);
        isListVisible = true;
        //ui->listButton->setIcon(QIcon(":/Icon/List.png")); // 恢复原图标
        qDebug() << "播放列表已显示";
    }
}
/********************************选择音乐**************************************/
void MainWindow::loadList(const QString & filepath)
{
    QDir dir(filepath);
    if(!dir.exists())
    {
        QMessageBox::warning(this,"文件夹","文件夹打开失败");
        return;
    }
    QStringList filters;
    filters << "*.mp3" << "*.wav" << "*.flac" << "*.aac" << "*.ogg" << "*.m4a";
    QFileInfoList fileList = dir.entryInfoList(filters, QDir::Files);


    for(const auto &fileInfo : fileList)
    {
        QListWidgetItem *item = new QListWidgetItem(fileInfo.baseName()); // 创建列表项，显示文件名，不含后缀
        item->setData(Qt::UserRole, fileInfo.filePath());  // 使用 Qt::UserRole 保存完整文件路径，便于后续获取
        item->setSizeHint(QSize(item->sizeHint().width(), 60));// 设置每项高度为 40 像素
        ui->musicList->addItem(item); // 添加到列表控件
    }

    if (ui->musicList->count() > 0) {
        ui->musicList->setCurrentRow(0);
        currentFilePath = ui->musicList->currentItem()->data(Qt::UserRole).toString(); // 设置初始文件路径
    } else {
        currentFilePath = ""; //  列表为空时清空路径
    }
}
QString MainWindow::formatTime(qint64 milliseconds)
{
    int seconds = milliseconds / 1000;
    int minutes = seconds / 60;
    int secs = seconds % 60;
    return QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(secs, 2, 10, QChar('0'));
}


