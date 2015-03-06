#include "mainwindow.h"
#include "ui_mainwindow.h"


double marker_min, marker_max;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myPlot_left_hip     = new MyQwtPlot(QString("left_hip"),    ui->qwtPlot_left_hip    );
    myPlot_right_hip    = new MyQwtPlot(QString("right_hip"),   ui->qwtPlot_right_hip   );
    myPlot_left_knee    = new MyQwtPlot(QString("left_knee"),   ui->qwtPlot_left_knee   );
    myPlot_right_knee   = new MyQwtPlot(QString("right_knee"),  ui->qwtPlot_right_knee  );



    test = new MyQwtPlot(QString("wqeqweqw"),ui->qwtPlot_left);

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


    this->setWindowTitle(fileName);



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
    std::vector<double> v_after_left_hip  ;
    std::vector<double> v_after_right_hip ;
    std::vector<double> v_after_left_knee ;
    std::vector<double> v_after_right_knee;

    for(int i = myPlot_left_hip->getMin(); i < myPlot_left_hip->getMax(); i++)
    {
        v_after_left_hip .push_back(v_left_hip .at(i));
        v_after_right_hip.push_back(v_right_hip.at(i));
        v_after_left_knee.push_back(v_left_knee.at(i));
        v_after_right_knee.push_back(v_right_knee.at(i));
    }




    const int total_point_number = 10000;
    normalization(&v_after_left_hip, total_point_number);
    normalization(&v_after_right_hip, total_point_number);
    normalization(&v_after_left_knee, total_point_number);
    normalization(&v_after_right_knee, total_point_number);


    for(unsigned int i = 0; i < total_point_number; i++)
    {
        out<<QString::number(v_after_left_hip.at(i))<<",";
        out<<QString::number(v_after_right_hip.at(i))<<",";
        out<<QString::number(v_after_left_knee.at(i))<<",";
        out<<QString::number(v_after_right_knee.at(i))<<endl;
    }

    //    qDebug()<<"v_after_left_hip = "<< v_after_left_hip.size();

    test->setSamples(1, v_after_left_hip.data(), (int)v_after_left_hip.size());

    out_file->close();


}
void MainWindow::normalization(std::vector<double>* data, const int total_size)
{
    std::vector<double> src;
    src = *data;
    int data_size = src.size();
    double fraction = double(data_size-1)/(total_size-1.0);


    //src 0~63 64資料
    //out 0~99 100筆資料

    //    0--1--2-------62----63
    //    0-1-------------98--99


    //    qDebug()<<"fraction"<<fraction;
    data->clear();


    double index = 0;
    double weight = 0;
    for(int i = 0; i<total_size-1; i++)
    {
        int index_front = floor(index);
        int index_back = index_front+1;
        weight = index - index_front;
        double ans = src.at(index_front)*(1-weight)+
                src.at(index_back)*weight;
        //        qDebug()<<"index = "<<index;
        data->push_back(ans);
        //因為間隔是1，所以就不用除分母了。


        //        qDebug()<<i<<" floor(index)"<<floor(index);



        index += fraction;



    }
    data->push_back(src.at(src.size()-1));

    //    qDebug()<<"data size"<<data_size;
    //    qDebug()<<"data size after"<<data->size();

    //    data->clear();



    //    std::vector<double> *temp;
    //    temp = data;

    //    for(int i = 0; i<1000; i++)
    //    {
    //        temp->push_back(i*.203);
    //    }


}
