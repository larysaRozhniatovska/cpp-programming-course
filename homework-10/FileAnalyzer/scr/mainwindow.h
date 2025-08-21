#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPushButton>
#include <QLabel>
#include <QTableWidget>
#include <QProgressBar>
#include <QList>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QFileDialog>
#include <QLineEdit>
#include <qDebug>
#include <QThread>
#include <QElapsedTimer>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QMenu>
#include <QAction>

#include "file_item.h"
#include "file_scanner.h"

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
    void selectDirectory();
    void startScan();
    void stopScan();
    void exportResults();

    // Слоти для worker
    void onFileFound(const FileItem &file);
    void onScanProgress(int filesProcessed, const QString &currentPath);
    void onScanFinished(const QList<FileItem> &allFiles);
    void onScanError(const QString &error);

    void data_sort(int ind);
    void filterLineEdit_textChanged(const QString &arg1);

protected:
    //Обработка миши
    void mousePressEvent(QMouseEvent *event) override;
private:
    void setupUI();
    void updateStatistics();
    void updateProgress(int current, int total);
    void updateTable();
    void ensureThread();
    Ui::MainWindow *ui;

    // Threading
    QThread *m_scanThread = nullptr;
    FileScanner *m_scanner = nullptr;

    // Данні
    QList<FileItem> m_files;
    QString m_selectedPath;

    qint64 allFiles = 0;
    qint64 sizeFiles = 0;
    qint64 maxSize = 0;
    QString nameMaxFile = "";

    int totalFiles = 0;
    int curFiles = 0;


    QList<int> countExe;
    QList<QString> nameExe;
    QString maxExe = "";

    QElapsedTimer timerScan;


    // UI компоненти
    QMenu *menuSelect;

    QLabel *m_fileTableLabel;
    QTableWidget *m_fileTable;
    QProgressBar *m_progressBar;
    QLabel *m_progressBarLabel_1;
    QLabel *m_progressBarLabel_2;
    QLabel *m_progressBarLabel_3;
    QLabel *m_progressBarLabel_4;

    QLabel *m_statusLabel;
    QLabel *m_statsLabel;

    QLabel *m_statisticLabel_1;
    QLabel *m_statisticLabel_2;
    QLabel *m_statisticLabel_2a;
    QLabel *m_statisticLabel_3;
    QLabel *m_statisticLabel_3a;
    QLabel *m_statisticLabel_4;
    QLabel *m_statisticLabel_4a;
    QLabel *m_statisticLabel_5;
    QLabel *m_statisticLabel_5a;
    // Кнопки
    QPushButton *m_selectButton;
    QPushButton *m_scanButton;
    QPushButton *m_stopButton;
    QPushButton *m_exportButton;
    QPushButton *m_closeButton;
    QLineEdit *m_filterLineEdit;
};
#endif // MAINWINDOW_H
