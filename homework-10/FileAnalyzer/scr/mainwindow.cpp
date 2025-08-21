#include "mainwindow.h"
#include "scr/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupUI();
    updateStatistics();
    m_statusLabel->setText("Cтатус: Необхідно вибрати папку");

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setupUI()
{
    setWindowFlags( Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint
                      | Qt::WindowStaysOnTopHint);
    setWindowTitle("Сканер файлів");

    menuSelect = new QMenu(this);
    QAction *selectFolder = new QAction("Вибрати папку",this);
    connect(selectFolder, SIGNAL(triggered()), this, SLOT( selectDirectory()));

    menuSelect->addAction(selectFolder);

    // frame   btn
    QFrame *frameBtn = new QFrame();
    frameBtn->setStyleSheet(
                "QFrame {border: 1px solid  #B4B4B4; border-radius: 4px; }");
    auto layout  = new QHBoxLayout();

    m_selectButton = new QPushButton("Вибрати папку");
    m_selectButton->setIcon(QPixmap(QString::fromUtf8(":/folder")));
    m_selectButton->setMinimumSize(QSize(0, 40));
    m_selectButton->setMaximumSize(QSize(16777215,40));
    m_selectButton->setStyleSheet(
                "QPushButton {border: 1px solid  #B4B4B4; border-radius: 4px; }");
    connect(m_selectButton, &QPushButton::clicked,
            this,           &MainWindow::selectDirectory);
    layout->addWidget(m_selectButton);

    m_scanButton = new QPushButton("Сканувати");
    m_scanButton->setIcon(QPixmap(QString::fromUtf8(":/lupa")));
    m_scanButton->setMinimumSize(QSize(0, 40));
    m_scanButton->setMaximumSize(QSize(16777215,40));
    m_scanButton->setStyleSheet(
                "QPushButton {border: 1px solid  #B4B4B4; border-radius: 4px; }");
    connect(m_scanButton, &QPushButton::clicked,
            this,         &MainWindow::startScan);
    layout->addWidget(m_scanButton);

    m_stopButton = new QPushButton("Стоп");
    m_stopButton->setIcon(QPixmap(QString::fromUtf8(":/cancel")));
    m_stopButton->setMinimumSize(QSize(0, 40));
    m_stopButton->setMaximumSize(QSize(16777215,40));
    m_stopButton->setStyleSheet(
                "QPushButton {border: 1px solid  #B4B4B4; border-radius: 4px; }");
    connect(m_stopButton, &QPushButton::clicked,
            this,         &MainWindow::stopScan);
    m_stopButton->setEnabled(false);
    layout->addWidget(m_stopButton);

    m_exportButton = new QPushButton("Експорт");
    m_exportButton->setIcon(QPixmap(QString::fromUtf8(":/export")));
    m_exportButton->setMinimumSize(QSize(0, 40));
    m_exportButton->setMaximumSize(QSize(16777215,40));
    m_exportButton->setStyleSheet(
                "QPushButton {border: 1px solid  #B4B4B4; border-radius: 4px; }");
    connect(m_exportButton, &QPushButton::clicked,
            this,           &MainWindow::exportResults);

    layout->addWidget(m_exportButton);
    layout->addSpacing(80);

    m_filterLineEdit = new QLineEdit("");
    m_filterLineEdit->setPlaceholderText("Введіть фільтр");
    m_filterLineEdit->setMaxLength(10);
    connect(m_filterLineEdit, &QLineEdit::textChanged,
            this,             &MainWindow::filterLineEdit_textChanged);
    layout->addWidget(m_filterLineEdit);
    layout->addSpacing(120);

    m_closeButton = new QPushButton("Закрити");
    m_closeButton->setIcon(QPixmap(QString::fromUtf8(":/close")));
    m_closeButton->setMinimumSize(QSize(0, 40));
    m_closeButton->setMaximumSize(QSize(16777215,40));
    m_closeButton->setStyleSheet(
                "QPushButton {border: 1px solid  #B4B4B4; border-radius: 4px; }");

    connect(m_closeButton, &QPushButton::clicked,
            this , &MainWindow::close);
    layout->addWidget(m_closeButton);


    frameBtn->setLayout(layout);
    ui->centralwidget->layout()->addWidget(frameBtn);
    //---- end frame btn
    //---- start frame progress
    QFrame *frameProgress = new QFrame();
    auto layoutProgress  = new QVBoxLayout();
    layoutProgress->setContentsMargins(5,0,10,0);
    QSizePolicy sizePolicy( QSizePolicy::Expanding,QSizePolicy::Minimum );
    sizePolicy.setVerticalStretch(0);
    frameProgress->setSizePolicy(sizePolicy);
    frameProgress->setMinimumSize(QSize(0, 60));
    frameProgress->setMaximumSize(QSize(16777215,60));

    auto layoutProgress_1  = new QHBoxLayout();
    m_progressBarLabel_1 = new QLabel("Прогрес:");
    m_progressBarLabel_2 = new QLabel("");
    m_progressBarLabel_2->setAlignment(Qt::AlignRight);
    layoutProgress_1->addWidget(m_progressBarLabel_1);
    layoutProgress_1->addSpacing(100);
    layoutProgress_1->addWidget(m_progressBarLabel_2);

    layoutProgress->addLayout(layoutProgress_1);
    m_progressBar = new QProgressBar();
    m_progressBar->setTextVisible(false);
    m_progressBar->setMinimumSize(QSize(0, 5));
    m_progressBar->setMaximumSize(QSize(16777215,5));
    m_progressBar->setMinimum(0);
    m_progressBar->setMaximum(100);

    layoutProgress->addWidget(m_progressBar);

    auto layoutProgress_2  = new QHBoxLayout();
    m_progressBarLabel_3 = new QLabel("");
    m_progressBarLabel_4 = new QLabel("");
    m_progressBarLabel_4->setAlignment(Qt::AlignRight);
    layoutProgress_2->addWidget(m_progressBarLabel_3);
    layoutProgress_2->addSpacing(100);
    layoutProgress_2->addWidget(m_progressBarLabel_4);
    layoutProgress->addLayout(layoutProgress_2);

    frameProgress->setLayout(layoutProgress);

    ui->centralwidget->layout()->addWidget(frameProgress);
    updateProgress(10, 1000);
    //--- end progress
    //--- start Table
    QFrame *frameTable = new QFrame();
    frameTable->setSizePolicy(sizePolicy);



    auto layoutTable  = new QVBoxLayout();
    frameTable->setLayout(layoutTable);
    QFont fontBold;
    fontBold.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
    fontBold.setPointSize(10);
    fontBold.setBold(true);

    m_fileTableLabel = new QLabel("Таблиця файлів");
    m_fileTableLabel->setFont(fontBold);
    layoutTable->addWidget(m_fileTableLabel);


    m_fileTable = new QTableWidget();
    m_fileTable->setColumnCount(4); // Указываем число колонок
    m_fileTable->setShowGrid(true); // Включаем сетку
    m_fileTable->setColumnWidth(0, 350);//"Назва"
    m_fileTable->verticalHeader()->hide();



    QStringList list;
    list<<"Назва"<< "Розмір"<<"Тип"<< "Дата";
    m_fileTable->setHorizontalHeaderLabels(list);
    // В конструкторе вашей формы или класса

    QHeaderView *head=m_fileTable->horizontalHeader();
    connect(head, &QHeaderView::sectionClicked,
            this, &MainWindow::data_sort );


    layoutTable->addWidget(m_fileTable);

    ui->centralwidget->layout()->addWidget(frameTable);
    //--- end Table

    //--- set Statistics
    QFrame *frameStatistics = new QFrame();
    frameStatistics->setSizePolicy(sizePolicy);
    auto layoutStatistics  = new QVBoxLayout();
    layoutStatistics->setContentsMargins(5,0,10,10);
    frameStatistics->setLayout(layoutStatistics);
    frameStatistics->setFrameShape(QFrame::Box);
    frameStatistics->setFrameShadow(QFrame::Sunken);
//    frameStatistics->setStyleSheet(
//                "QFrame {border: 1px solid  #B4B4B4; border-radius: 4px; }");

    m_statisticLabel_1 = new QLabel("Базова статистика");
    m_statisticLabel_1->setFont(fontBold);
    m_statisticLabel_1->setMinimumSize(QSize(0, 40));
    m_statisticLabel_1->setMaximumSize(QSize(16777215,40));
    layoutStatistics->addWidget(m_statisticLabel_1);

    auto layoutStatistics_1  = new QHBoxLayout();
    m_statisticLabel_2 = new QLabel("Всього файлів:");
    m_statisticLabel_2a = new QLabel("");
    m_statisticLabel_2a->setAlignment(Qt::AlignRight);
    layoutStatistics_1->setContentsMargins(0,0,0,0);
    layoutStatistics_1->addWidget(m_statisticLabel_2);
    layoutStatistics_1->addSpacing(100);
    layoutStatistics_1->addWidget(m_statisticLabel_2a);
    layoutStatistics->addLayout(layoutStatistics_1);

    auto layoutStatistics_2  = new QHBoxLayout();
    m_statisticLabel_3 = new QLabel("Загальний розмір:");
    m_statisticLabel_3a = new QLabel("");
    m_statisticLabel_3a->setAlignment(Qt::AlignRight);
    layoutStatistics_2->setContentsMargins(0,0,0,0);
    layoutStatistics_2->addWidget(m_statisticLabel_3);
    layoutStatistics_2->addSpacing(100);
    layoutStatistics_2->addWidget(m_statisticLabel_3a);
    layoutStatistics->addLayout(layoutStatistics_2);


    auto layoutStatistics_3  = new QHBoxLayout();
    m_statisticLabel_4 = new QLabel("Найбільний файл:");
    m_statisticLabel_4a = new QLabel("");
    m_statisticLabel_4a->setAlignment(Qt::AlignRight);
    layoutStatistics_3->setContentsMargins(0,0,0,0);
    layoutStatistics_3->addWidget(m_statisticLabel_4);
    layoutStatistics_3->addSpacing(100);
    layoutStatistics_3->addWidget(m_statisticLabel_4a);
    layoutStatistics->addLayout(layoutStatistics_3);

    auto layoutStatistics_4  = new QHBoxLayout();
    m_statisticLabel_5 = new QLabel("Найпоширеніший тип:");
    m_statisticLabel_5a = new QLabel("");
    m_statisticLabel_5a->setAlignment(Qt::AlignRight);
    layoutStatistics_4->setContentsMargins(0,0,0,0);
    layoutStatistics_4->addWidget(m_statisticLabel_5);
    layoutStatistics_4->addSpacing(100);
    layoutStatistics_4->addWidget(m_statisticLabel_5a);
    layoutStatistics->addLayout(layoutStatistics_4);

    ui->centralwidget->layout()->addWidget(frameStatistics);

    QFrame *frameStatus = new QFrame();
    frameStatus->setSizePolicy(sizePolicy);
    auto layoutStatus  = new QVBoxLayout();
    layoutStatus->setContentsMargins(5,0,10,0);
    frameStatus->setLayout(layoutStatus);

    m_statusLabel = new QLabel("Status");
    m_statusLabel->setMinimumSize(QSize(0, 40));
    m_statusLabel->setMaximumSize(QSize(16777215,40));
    m_statusLabel->setStyleSheet(
                "QLabel {border: 1px solid  #B4B4B4; border-radius: 4px; }");
    layoutStatus->addWidget(m_statusLabel);


    ui->centralwidget->layout()->addWidget(frameStatus);
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int _x = event->x();
    int _y = event->y();
    QRect rect = this->geometry();
    if (event->button() == Qt::RightButton )
    {
        menuSelect->exec(QPoint(rect.left()+_x,rect.top()+_y));
    }
}
void MainWindow::data_sort(int ind)
{
    qDebug() << "Click header colum: " << ind;
    static auto sortDirect = Qt::AscendingOrder;
    if(sortDirect == Qt::AscendingOrder){
        sortDirect = Qt::DescendingOrder;
    }else{
        sortDirect = Qt::AscendingOrder;
    }

    m_fileTable->sortByColumn(ind, sortDirect);
}
void MainWindow::updateStatistics()
{
    if(allFiles == 0){
        m_statisticLabel_2a->setText("");
        m_statisticLabel_3a->setText("");
        m_statisticLabel_4a->setText("");
        m_statisticLabel_5a->setText("");
    }else
    {
        m_statisticLabel_2a->setText(QString::number(allFiles));
        QString allSize = QString::number(sizeFiles/1024.0/1024.0/1024.0,'f',4)+" ГБ";
        m_statisticLabel_3a->setText(allSize);
        m_statisticLabel_4a->setText(nameMaxFile+"("+QString::number(maxSize/1024.0/1024.0)+" МБ)");
        m_statisticLabel_5a->setText(maxExe);

        m_progressBarLabel_3->setText("Знайдено: "+QString::number(allFiles));
        m_progressBarLabel_4->setText(allSize);
    }
}
void MainWindow::updateProgress(int current, int total)
{
    double value = current * 100.0 /total;
    int ivalue = int(value);
    m_progressBarLabel_2->setText(QString::number(ivalue) +" %");
    m_progressBar->setValue(ivalue);
}

void MainWindow::filterLineEdit_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    updateTable();
}

void MainWindow::updateTable()
{
    while (m_fileTable->rowCount() > 0){
        int rows = m_fileTable->rowCount();
        m_fileTable->removeRow(rows-1);
    }
    auto iRow=0;
    QString filtr = m_filterLineEdit->text();
    foreach ( FileItem item, m_files){
        auto iCol = 0;
        if(m_fileTable->rowCount() > 100){
            return;
        }
        if  (filtr != "" && item.type() != filtr ){
            continue;
        }

       m_fileTable->insertRow(iRow);

       m_fileTable->setItem(iRow,iCol++, new QTableWidgetItem(item.name() ));
       m_fileTable->setItem(iRow,iCol, new QTableWidgetItem(item.sizeString() ));
       m_fileTable->item(iRow,iCol++)->setTextAlignment(Qt::AlignCenter);
       m_fileTable->setItem(iRow,iCol, new QTableWidgetItem(item.extension() ));
       m_fileTable->item(iRow,iCol++)->setTextAlignment(Qt::AlignCenter);
       m_fileTable->setItem(iRow,iCol, new QTableWidgetItem(item.modifiedString() ));
       m_fileTable->item(iRow,iCol++)->setTextAlignment(Qt::AlignCenter);
       m_fileTable->setRowHeight(iRow,16);
       iRow++;
    }
}

void MainWindow::selectDirectory()
{
    QString pathApp = QApplication::applicationDirPath();
    QFileDialog dialog;
    dialog.setDirectory(pathApp);
    m_selectedPath = "";
    m_selectedPath = dialog.getExistingDirectory(this, tr("Open Directory"),
                                                    pathApp,
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    m_statusLabel->setText("Cтатус: Вибрана папка "+ m_selectedPath);
    m_files.clear();


    m_fileTableLabel->setText("Таблиця файлів " + m_selectedPath);
    allFiles = 0;
    sizeFiles = 0;
    maxSize = 0;
    nameMaxFile = "";

    countExe.clear();
    nameExe.clear();
    maxExe = "";
    updateStatistics();
}
void MainWindow::ensureThread()
{
    if(m_scanThread != nullptr)
         return;

    if(m_selectedPath != ""){
        m_files.clear();

        while (m_fileTable->rowCount() > 0){
            int rows = m_fileTable->rowCount();
            m_fileTable->removeRow(rows-1);
        }
        m_scanButton->setEnabled(false);
        m_stopButton->setEnabled(true);

        allFiles = 0;
        sizeFiles = 0;
        maxSize = 0;
        nameMaxFile = "";

        countExe.clear();
        nameExe.clear();
        maxExe = "";
        updateStatistics();
        m_scanThread = new QThread();
        m_scanner = new FileScanner(m_selectedPath);
        //connect(m_thread, &QThread::finished, m_worker, &QObject::deleteLater);
        connect(m_scanThread, &QThread::finished, [this]{
            m_scanThread->deleteLater();
            m_scanThread = nullptr;
            m_scanner = nullptr;
            qint64 nMilliseconds1 = timerScan.elapsed();
            m_statusLabel->setText("Cтатус: Сканування завершилося за "+ QString::number(nMilliseconds1*0.001,'f',3) + " сек");
        });

        connect( m_scanThread, &QThread::started,
                 m_scanner,    &FileScanner::scanDirectory );

        connect( m_scanner, &FileScanner::finished,
                 this,    &MainWindow::onScanFinished,Qt::QueuedConnection );

        connect( m_scanner, &FileScanner::fileFound,
                 this,    &MainWindow::onFileFound,Qt::QueuedConnection );

        connect( m_scanner, &FileScanner::error,
                 this,    &MainWindow::onScanError,Qt::QueuedConnection );

        connect( m_scanner, &FileScanner::progress,
                 this,    &MainWindow::onScanProgress,Qt::QueuedConnection );

        connect( m_scanner, &FileScanner::finished,
                 m_scanThread, &QThread::quit);

        m_scanner->moveToThread(m_scanThread);
        m_statusLabel->setText("Cтатус: Сканування почалося ");

        m_scanThread->start();
        timerScan.start();
    }
}
void MainWindow::startScan()
{
    ensureThread();
}
void MainWindow::stopScan()
{
    m_scanner->stopScanning();
}
void MainWindow::exportResults()
{
    QDir dir(m_selectedPath);
    QString nameFile = QApplication::applicationDirPath() + "/Static_" + dir.dirName()+".json";
    QFile file(nameFile);
    if (!file.open( QIODevice::WriteOnly )) {
           return ;
    }

    QJsonObject  recordObject;

    QJsonObject addressObject;
    addressObject.insert("Всього файлів:", allFiles);
    QString allSize = QString::number(sizeFiles/1024.0/1024.0/1024.0,'f',4)+" ГБ";
    addressObject.insert("Загальний розмір:", QString::number(sizeFiles)+" (" +allSize+")");
    addressObject.insert("Найбільний файл:", nameMaxFile+"("+QString::number(maxSize/1024.0/1024.0)+" МБ)");
    addressObject.insert("Найпоширеніший тип:", maxExe);

    QJsonArray recordsArray;
    recordsArray.push_back(addressObject);

    recordObject.insert("Базова статистика", recordsArray);


    QJsonDocument  json(recordObject);


    file.write( json.toJson() );
    file.close();
}

// Слоти для worker
void MainWindow::onFileFound(const FileItem &file)
{
    m_files.append(file);
    allFiles++;
    qint64 _size = file.size();
    sizeFiles += _size;
    if( maxSize < _size){
        maxSize = _size;
        nameMaxFile = file.name();
    }
    bool find = false;
    QString exe = file.type();
    for(int i = 0; i < nameExe.count(); i++){
        if(nameExe[i] == exe){
            find = true;
            countExe[i]++;
            break;
        }
    }
    if(!find){
        nameExe.append(exe);
        countExe.append(1);
    }
    if (allFiles == 700){
            qDebug()<<" jkk";
        }
    int imax = 0;
    for(int i = 0; i < countExe.count(); i++){
        if(countExe[i] > imax){
            find = true;
            imax = countExe[i];
            maxExe = nameExe[i];
        }
    }
    updateStatistics();
    curFiles++;
    updateProgress(curFiles, totalFiles);
}
void MainWindow::onScanProgress(int filesProcessed, const QString &currentPath)
{
   totalFiles = filesProcessed;
   curFiles = 0;
   m_statusLabel->setText("Cтатус: Сканування папки: "+ currentPath);

}
void MainWindow::onScanFinished(const QList<FileItem> &allFiles)
{
    m_files.clear();
    m_files = allFiles;
    updateTable();
    updateStatistics();
    m_scanButton->setEnabled(true);
    m_stopButton->setEnabled(false);
}
void MainWindow::onScanError(const QString &error)
{
    m_statusLabel->setText("Cтатус: Помилка "+ error);
    updateTable();
    updateStatistics();
    m_scanButton->setEnabled(true);
    m_stopButton->setEnabled(false);
}


