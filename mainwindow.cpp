#include "mainwindow.h"
#include "ui_mainwindow.h"


double marker_min, marker_max;
QwtPlotShapeItem *item = new QwtPlotShapeItem();
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_read_file_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"), "_TEST", tr("(*.txt)"));
    qDebug()<<fileName;
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    v_left_hip.clear();
    v_right_hip.clear();
    v_left_knee.clear();
    v_right_knee.clear();

    d_marker1 = new QwtPlotMarker();
    qwt_marker_max = new QwtPlotMarker();
    qwt_marker_min = new QwtPlotMarker();

    while (!file.atEnd()) {
        QString line = file.readLine();
        process_line(line);
    }




    std::vector<double> time;
    for(int i = 0; i<v_left_hip.size(); i++)
    {
        time.push_back(double(i*20));
    }

    curve1->setSamples(time.data(), v_left_hip.data(), (int) v_left_hip.size() );
    curve1->attach(ui->qwtPlot);
    curve2->setSamples(time.data(), v_right_hip.data(), (int) v_right_hip.size() );
    curve2->attach(ui->qwtPlot_2);
    curve3->setSamples(time.data(), v_left_knee.data(), (int) v_left_knee.size() );
    curve3->attach(ui->qwtPlot_3);
    curve4->setSamples(time.data(), v_right_knee.data(), (int) v_right_knee.size() );
    curve4->attach(ui->qwtPlot_4);



    QwtPlotPicker *picker = new QwtPlotPicker(ui->qwtPlot->xBottom, ui->qwtPlot->yLeft,
                                              QwtPicker::VLineRubberBand, QwtPicker::AlwaysOn,
                                              ui->qwtPlot->canvas());

    QwtPickerMachine* pickerMachine = new QwtPickerClickPointMachine();
    picker->setStateMachine(pickerMachine);

    connect(picker,SIGNAL(moved(QPoint)),this,SLOT(function(QPoint)));
    connect(picker, SIGNAL(selected(const QPointF&)),SLOT(selected(const QPointF&)));





//    ui->qwtPlot->setAxisScale(QwtPlot::xTop,10,20);
//    ui->qwtPlot->setAxisScale(QwtPlot::yLeft,-180,180);


//    qDebug()<<"ui->qwtPlot->axisMaxMajor() = "<<ui->qwtPlot->axisScaleDiv;
    ui->qwtPlot->replot();
    qDebug()<<"ui->qwtPlot->xBottom = "<<ui->qwtPlot->axisScaleDiv(QwtPlot::yLeft).lowerBound();

    //    curve1->Lines
    ui->qwtPlot->replot();
    ui->qwtPlot_2->replot();
    ui->qwtPlot_3->replot();
    ui->qwtPlot_4->replot();




}
void MainWindow::function(QPoint actualMousePosition)
{
    int x = curve1->closestPoint(actualMousePosition,NULL);
    QPointF Position = curve1->sample(x);
    QwtPlotMarker *Marker = new QwtPlotMarker;
    Marker->setValue(Position);



    qDebug()<<Position;


}
void MainWindow::selected(const QPointF& pos)
{
    if(ui->radioButton_max->isChecked())
    {
        marker_max = pos.x();
    }
    if(ui->radioButton_min->isChecked())
    {
        marker_min = pos.x();
    }
    if(marker_max < marker_min)
    {
        double temp = marker_min;
        marker_min = marker_max;
        marker_max = temp;
    }
    qwt_marker_max->setLineStyle(QwtPlotMarker::VLine);
    qwt_marker_max->setLinePen( Qt::red, 0, Qt::DashDotLine );
    qwt_marker_max->attach(ui->qwtPlot);
    qwt_marker_max->setXValue(marker_max);

    qwt_marker_min->setLineStyle(QwtPlotMarker::VLine);
    qwt_marker_min->setLinePen( Qt::blue, 0, Qt::DashDotLine );
    qwt_marker_min->attach(ui->qwtPlot);
    qwt_marker_min->setXValue(marker_min);




    if(!marker_min && !marker_max && abs(marker_min-marker_max)< 0.001)
            qDebug() << "Draw bg";


//    QRectF rect;
//    rect.setWidth(50);
//    rect.setHeight(60);

    QRectF rect;
//    rect.setSize( QSizeF( 5000.0, 100.0 ) );
//    rect.moveCenter( QPointF( 10000.0, -70.0 ) );
    rect.setLeft(marker_min);
    rect.setRight(marker_max);
    rect.setTop(ui->qwtPlot->axisScaleDiv(QwtPlot::yLeft).lowerBound());
    rect.setBottom(ui->qwtPlot->axisScaleDiv(QwtPlot::yLeft).upperBound());



    QPainterPath path;
    path.addRect( rect );



    item->setShape(path);

    QColor fillColor = QColor(200, 200, 255);
//    QPen pen( fillColor, 3 );
//    pen.setJoinStyle( Qt::MiterJoin );
//    item->setPen( pen );
    item->setBrush( fillColor );

    item->attach( ui->qwtPlot );



//    ui->qwtPlot->setAttribute(Qt::WA_TranslucentBackground);
//    ui->qwtPlot->setCanvasBackground(QBrush(QColor(200, 200, 255)));
    ui->qwtPlot->replot();
    qDebug() << pos;


}
void MainWindow::process_line(QString line)
{
    //    qDebug()<<line;
    QStringList qs_list = line.split(',');
    //    foreach (const QString &str, qs_list)
    //    {
    //        qDebug()<<str<<"\n";
    //    }
    v_left_hip.push_back(qs_list.at(0).toDouble());

    v_right_hip.push_back(qs_list.at(1).toDouble());
    v_left_knee.push_back(qs_list.at(2).toDouble());
    v_right_knee.push_back(qs_list.at(3).toDouble());

    //    qDebug()<<v_left_hip;

}
