#include "myqwtplot.h"
#include "qwt_plot.h"


MyQwtPlot::MyQwtPlot(const QString &title, QwtPlot *qwtplot)
{

    qwt_myQwtplot = qwtplot;
    qwt_myQwtplot->setTitle(title);
    qwt_myQwtplot->replot();


    b_max_selected = false;


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
    qwt_myQwtplot->setAxisScale(QwtPlot::yLeft,-100,100);

//    for ( int axis = 0; axis < QwtPlot::axisCnt; axis++ )
//            qwt_myQwtplot->setAxisAutoScale(axis);

//        qwt_myQwtplot->updateAxes();

    qwt_myQwtplot->replot();




    background_rect_lower_bound = qwt_myQwtplot->axisScaleDiv(QwtPlot::yLeft).lowerBound();
    background_rect_upper_bound = qwt_myQwtplot->axisScaleDiv(QwtPlot::yLeft).upperBound();
//    qDebug()<<"background_rect_lower_bound = "<<background_rect_lower_bound;
//    qDebug()<<"background_rect_upper_bound = "<<background_rect_upper_bound;
    i_marker_max = 0;
    i_marker_min = 0;
    DrawShadowline(i_marker_max,i_marker_min);
    emit valueChanged(i_marker_max, i_marker_min);
}

void MyQwtPlot::setMaxline(bool select)
{
    b_max_selected = select;
    //    qDebug()<<"_max_selected = "<<_max_selected;
}
void MyQwtPlot::selectedFun(const QPointF& pos)
{


    if(b_max_selected)
        i_marker_max = int(pos.x());
    else
        i_marker_min = int(pos.x());

    if(i_marker_max < i_marker_min){
        double temp = i_marker_min;
        i_marker_min = i_marker_max;
        i_marker_max = temp;
    }

//    qDebug()<<"marker_max = "<<i_marker_max;
//    qDebug()<<"marker_min = "<<i_marker_min;

//    qDebug()<<"b_max_selected = "<<b_max_selected;





    DrawShadowline(i_marker_max,i_marker_min);
    emit valueChanged(i_marker_max, i_marker_min);

}

void MyQwtPlot::DrawShadowline(double max, double min)
{
    i_marker_max = max;
    i_marker_min = min;

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
    rect.setTop(background_rect_upper_bound);
    rect.setBottom(background_rect_lower_bound);


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
int MyQwtPlot::getMax()
{
    return i_marker_max;
}
int MyQwtPlot::getMin()
{
    return i_marker_min;
}
