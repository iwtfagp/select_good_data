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


    //3.get the selected range.
    qwt_marker_max = new QwtPlotMarker();
    qwt_marker_min = new QwtPlotMarker();

    QwtPlotPicker *picker = new QwtPlotPicker(ui->qwtPlot_left_hip->xBottom, ui->qwtPlot_left_hip->yLeft,
                                              QwtPicker::VLineRubberBand, QwtPicker::AlwaysOn,
                                              ui->qwtPlot_left_hip->canvas());

    QwtPickerMachine* pickerMachine = new QwtPickerClickPointMachine();
    picker->setStateMachine(pickerMachine);


    connect(picker, SIGNAL(selected(const QPointF&)),SLOT(selected(const QPointF&)));



    //4.Get file data.
    while (!file.atEnd()) {
        QString line = file.readLine();
        process_line(line);
    }


    //5.new a x axis
    std::vector<double> time;
    for(int i = 0; i<v_left_hip.size(); i++)
    {
        time.push_back(double(i*20));
    }

    //6.set title.
    ui->qwtPlot_left_hip->setTitle(QString("left_hip"));
    ui->qwtPlot_right_hip->setTitle(QString("right_hip"));
    ui->qwtPlot_left_knee->setTitle(QString("left_knee"));
    ui->qwtPlot_right_knee->setTitle(QString("right_knee"));

    //7. input data into curve and attach to the plot
    curve1->setSamples(time.data(), v_left_hip.data(), (int) v_left_hip.size() );
    curve1->attach(ui->qwtPlot_left_hip);
    curve2->setSamples(time.data(), v_right_hip.data(), (int) v_right_hip.size() );
    curve2->attach(ui->qwtPlot_right_hip);
    curve3->setSamples(time.data(), v_left_knee.data(), (int) v_left_knee.size() );
    curve3->attach(ui->qwtPlot_left_knee);
    curve4->setSamples(time.data(), v_right_knee.data(), (int) v_right_knee.size() );
    curve4->attach(ui->qwtPlot_right_knee);

    //8.replot the plot and display on the screen.
    ui->qwtPlot_left_hip->replot();
    ui->qwtPlot_right_hip->replot();
    ui->qwtPlot_left_knee->replot();
    ui->qwtPlot_right_knee->replot();
}

void MainWindow::selected(const QPointF& pos)
{
    if(ui->radioButton_max->isChecked()){
        marker_max = pos.x();}
    if(ui->radioButton_min->isChecked()){
        marker_min = pos.x();}
    if(marker_max < marker_min){
        double temp = marker_min;
        marker_min = marker_max;
        marker_max = temp;
    }
    qwt_marker_max->setLineStyle(QwtPlotMarker::VLine);
    qwt_marker_max->setLinePen( Qt::red, 0, Qt::DashDotLine );
    qwt_marker_max->attach(ui->qwtPlot_left_hip);
    qwt_marker_max->setXValue(marker_max);

    qwt_marker_min->setLineStyle(QwtPlotMarker::VLine);
    qwt_marker_min->setLinePen( Qt::blue, 0, Qt::DashDotLine );
    qwt_marker_min->attach(ui->qwtPlot_left_hip);
    qwt_marker_min->setXValue(marker_min);

    if(!marker_min && !marker_max && abs(marker_min-marker_max)< 0.001)
            qDebug() << "Draw bg";

    QRectF rect;
    rect.setLeft(marker_min);
    rect.setRight(marker_max);
    rect.setTop(ui->qwtPlot_left_hip->axisScaleDiv(QwtPlot::yLeft).lowerBound());
    rect.setBottom(ui->qwtPlot_left_hip->axisScaleDiv(QwtPlot::yLeft).upperBound());



    QPainterPath path;

    path.addRect( rect );
    item->setShape(path);

    QColor fillColor = QColor(200, 200, 255);
    QPen pen( fillColor, 3 );
    item->setPen( pen );
    item->setBrush( fillColor );
    item->attach( ui->qwtPlot_left_hip );

    ui->qwtPlot_left_hip->replot();
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
