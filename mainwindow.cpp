#include "mainwindow.h"
#include "ui_mainwindow.h"


double marker_min, marker_max;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myPlot_left_hip = new MyQwtPlot(QString("left_hip"),ui->qwtPlot_left_hip);
    myPlot_right_hip = new MyQwtPlot(QString("right_hip"),ui->qwtPlot_right_hip);
    myPlot_left_knee = new MyQwtPlot(QString("left_knee"),ui->qwtPlot_left_knee);
    myPlot_right_knee = new MyQwtPlot(QString("right_knee"),ui->qwtPlot_right_knee);

    connect(myPlot_left_hip  , SIGNAL(valueChanged(double,double)), myPlot_left_hip  , SLOT(DrawShadowline(double,double)));
    connect(myPlot_left_hip  , SIGNAL(valueChanged(double,double)), myPlot_right_hip , SLOT(DrawShadowline(double,double)));
    connect(myPlot_left_hip  , SIGNAL(valueChanged(double,double)), myPlot_left_knee , SLOT(DrawShadowline(double,double)));
    connect(myPlot_left_hip  , SIGNAL(valueChanged(double,double)), myPlot_right_knee, SLOT(DrawShadowline(double,double)));

    connect(myPlot_right_hip , SIGNAL(valueChanged(double,double)), myPlot_left_hip  , SLOT(DrawShadowline(double,double)));
    connect(myPlot_right_hip , SIGNAL(valueChanged(double,double)), myPlot_right_hip , SLOT(DrawShadowline(double,double)));
    connect(myPlot_right_hip , SIGNAL(valueChanged(double,double)), myPlot_left_knee , SLOT(DrawShadowline(double,double)));
    connect(myPlot_right_hip , SIGNAL(valueChanged(double,double)), myPlot_right_knee, SLOT(DrawShadowline(double,double)));

    connect(myPlot_left_knee , SIGNAL(valueChanged(double,double)), myPlot_left_hip  , SLOT(DrawShadowline(double,double)));
    connect(myPlot_left_knee , SIGNAL(valueChanged(double,double)), myPlot_right_hip , SLOT(DrawShadowline(double,double)));
    connect(myPlot_left_knee , SIGNAL(valueChanged(double,double)), myPlot_left_knee , SLOT(DrawShadowline(double,double)));
    connect(myPlot_left_knee , SIGNAL(valueChanged(double,double)), myPlot_right_knee, SLOT(DrawShadowline(double,double)));

    connect(myPlot_right_knee, SIGNAL(valueChanged(double,double)), myPlot_left_hip  , SLOT(DrawShadowline(double,double)));
    connect(myPlot_right_knee, SIGNAL(valueChanged(double,double)), myPlot_right_hip , SLOT(DrawShadowline(double,double)));
    connect(myPlot_right_knee, SIGNAL(valueChanged(double,double)), myPlot_left_knee , SLOT(DrawShadowline(double,double)));
    connect(myPlot_right_knee, SIGNAL(valueChanged(double,double)), myPlot_right_knee, SLOT(DrawShadowline(double,double)));

    //    connect(picker, SIGNAL(selected(const QPointF&)),SLOT(selectedFun(const QPointF&)));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_read_file_clicked()
{
    //1.Read File.
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"), "_TEST", tr("(*.txt)"));
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;


    //2.Clear vector and prevent errors.
    v_left_hip.clear();
    v_right_hip.clear();
    v_left_knee.clear();
    v_right_knee.clear();


    //4.Get file data.
    while (!file.atEnd()) {
        QString line = file.readLine();
        process_line(line);
    }

    myPlot_left_hip  ->setSamples(1, v_left_hip.data(), (int)v_left_hip.size());
    myPlot_right_hip ->setSamples(1, v_right_hip.data(), (int)v_right_hip.size());
    myPlot_left_knee ->setSamples(1, v_left_knee.data(), (int)v_left_knee.size());
    myPlot_right_knee->setSamples(1, v_right_hip.data(), (int)v_right_hip.size());

}
void MainWindow::process_line(QString line)
{
    QStringList qs_list = line.split(',');
    v_left_hip.push_back(qs_list.at(0).toDouble());
    v_right_hip.push_back(qs_list.at(1).toDouble());
    v_left_knee.push_back(qs_list.at(2).toDouble());
    v_right_knee.push_back(qs_list.at(3).toDouble());
}

void MainWindow::on_radioButton_max_clicked()
{

    myPlot_left_hip->setMaxline(true);
    myPlot_right_hip->setMaxline(true);
    myPlot_left_knee->setMaxline(true);
    myPlot_right_knee->setMaxline(true);
}

void MainWindow::on_radioButton_min_clicked()
{

    myPlot_left_hip->setMaxline(false);
    myPlot_right_hip->setMaxline(false);
    myPlot_left_knee->setMaxline(false);
    myPlot_right_knee->setMaxline(false);
}

void MainWindow::on_pushButton_generate_clicked()
{
    qDebug()<<"Max = "<<myPlot_left_hip->getMax();
    qDebug()<<"Min = "<<myPlot_left_hip->getMin();
}
