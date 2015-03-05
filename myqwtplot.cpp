#include "myqwtplot.h"
#include "qwt_plot.h"


MyQwtPlot::MyQwtPlot(const QString &title, QwtPlot *qwtplot)
{

    qwt_myQwtplot = qwtplot;
    qwt_myQwtplot->setTitle(title);
    qwt_myQwtplot->replot();


    b_max_selected = false;
    d_marker_max = 0;
    d_marker_min = 0;

    qwt_curve = new QwtPlotCurve();

    qwt_marker_max = new QwtPlotMarker();
    qwt_marker_min = new QwtPlotMarker();

    qwt_item = new QwtPlotShapeItem();

    QwtPlotPicker *picker = new QwtPlotPicker(qwt_myQwtplot->xBottom, qwt_myQwtplot->yLeft,
                                              QwtPicker::VLineRubberBand, QwtPicker::AlwaysOn,
                                              qwt_myQwtplot->canvas());
    QwtPickerMachine* pickerMachine = new QwtPickerClickPointMachine();
    picker->setStateMachine(pickerMachine);

    connect(picker, SIGNAL(selected(const QPointF&)),SLOT(selectedFun(const QPointF&)));




}

MyQwtPlot::~MyQwtPlot()
{

}

void MyQwtPlot::setSamples(int time_tick, const double *data, const int size)
{
    qwt_curve->detach();
    std::vector<double> time;
    for(int i = 0; i<size; i++)
    {
        time.push_back(double(i*time_tick));
    }

    qwt_curve->setSamples(time.data(), data, size);
    qwt_curve->attach(qwt_myQwtplot);
    qwt_myQwtplot->replot();
}

void MyQwtPlot::setMaxline(bool select)
{
    b_max_selected = select;
    //    qDebug()<<"_max_selected = "<<_max_selected;
}
void MyQwtPlot::selectedFun(const QPointF& pos)
{

    if(b_max_selected)
        d_marker_max = pos.x();
    else
        d_marker_min = pos.x();

    if(d_marker_max < d_marker_min){
        double temp = d_marker_min;
        d_marker_min = d_marker_max;
        d_marker_max = temp;
    }

//    qDebug()<<"marker_max = "<<d_marker_max;
//    qDebug()<<"marker_min = "<<d_marker_min;

    qDebug()<<"b_max_selected = "<<b_max_selected;


    DrawShadowline(d_marker_max,d_marker_min);
    emit valueChanged(d_marker_max, d_marker_min);

}

void MyQwtPlot::DrawShadowline(double max, double min)
{
    qwt_marker_max->setLineStyle(QwtPlotMarker::VLine);
    qwt_marker_max->setLinePen( Qt::red, 0, Qt::DashDotLine );
    qwt_marker_max->setXValue(max);
    qwt_marker_max->attach(qwt_myQwtplot);

    qwt_marker_min->setLineStyle(QwtPlotMarker::VLine);
    qwt_marker_min->setLinePen( Qt::blue, 0, Qt::DashDotLine );
    qwt_marker_min->setXValue(min);
    qwt_marker_min->attach(qwt_myQwtplot);


    QRectF rect;
    rect.setLeft(min);
    rect.setRight(max);
    rect.setTop(qwt_myQwtplot->axisScaleDiv(QwtPlot::yLeft).lowerBound());
    rect.setBottom(qwt_myQwtplot->axisScaleDiv(QwtPlot::yLeft).upperBound());

    QPainterPath path;

    path.addRect( rect );
    qwt_item->setShape(path);

    QColor fillColor = QColor(200, 200, 255);
    QPen pen( fillColor, 3 );
    qwt_item->setPen( pen );
    qwt_item->setBrush( fillColor );
    qwt_item->attach( qwt_myQwtplot );

    qwt_myQwtplot->replot();


}
double MyQwtPlot::getMax()
{
    return d_marker_max;
//    return 20.2;
}
double MyQwtPlot::getMin()
{
    return d_marker_min;
}
