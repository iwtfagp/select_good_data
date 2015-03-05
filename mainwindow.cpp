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
    QString old_fileName = fileName;
    fileName = QFileDialog::getOpenFileName(this,
                                            tr("Open Image"), "_TEST", tr("(*.txt)"));
    if(fileName.isEmpty())
        fileName = old_fileName;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    out_filename_num = 0;

    //2.Clear vector and prevent errors.
    v_left_hip.clear();
    v_right_hip.clear();
    v_left_knee.clear();
    v_right_knee.clear();


    //3.Get file data.
    while (!file.atEnd()) {
        QString line = file.readLine();
        process_line(line);
    }

    myPlot_left_hip  ->setSamples(1, v_left_hip.data(), (int)v_left_hip.size());
    myPlot_right_hip ->setSamples(1, v_right_hip.data(), (int)v_right_hip.size());
    myPlot_left_knee ->setSamples(1, v_left_knee.data(), (int)v_left_knee.size());
    myPlot_right_knee->setSamples(1, v_right_knee.data(), (int)v_right_knee.size());

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

//        qDebug()<<"Max = "<<myPlot_left_hip->getMax();
//        qDebug()<<"Min = "<<myPlot_left_hip->getMin();
    QString qs_user, qs_date, qs_time;
    if(fileName.isEmpty())
        return;
    QStringList list = fileName.split('/');
    list = list.at(list.size()-1).split('.');
    list = list.at(0).split('_');
    if(!list.isEmpty())
    {
        qs_user = list.at(0);
        qs_date = list.at(1);
        qs_time = list.at(2);
    }
    else
    {
        qs_user = "NoUser";
        qs_date = "NoDate";
        qs_time = "NoTime";
    }
    out_filename_num++;
    QString output_filename = "after/" + qs_user + "_" + qs_date + "_" + qs_time +
            "_" + QString::number(out_filename_num) + ".txt";

    QFile *out_file = new QFile(output_filename);

    if (!out_file->open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(out_file);

    for(int i = myPlot_left_hip->getMin(); i < myPlot_left_hip->getMax(); i++)
    {
        out<<QString::number(v_left_hip.at(i))<<","<<QString::number(v_right_hip.at(i))<<","<<
            QString::number(v_left_knee.at(i))<<","<<QString::number(v_right_knee.at(i))<<endl;



    }


    out_file->close();


}
