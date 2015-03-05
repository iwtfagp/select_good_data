#include "myqwtplot.h"

MyQwtPlot::MyQwtPlot()
{

}

MyQwtPlot::MyQwtPlot(QString* _title, QwtPlot* _qwtplot)
{
    title = _title;
    qwtplot = _qwtplot;
}

MyQwtPlot::~MyQwtPlot()
{

}

