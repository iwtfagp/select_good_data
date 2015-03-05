#ifndef MYQWTPLOT_H
#define MYQWTPLOT_H

#include <qwt_plot_curve.h>
#include <QDebug>
#include <qwt_plot_picker.h>
#include <qwt_picker_machine.h>
#include <qwt_plot_marker.h>

#include <qwt_plot_shapeitem.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_canvas.h>
#include <qwt_legend.h>
#include <qwt_plot_renderer.h>

#include <QString>

class MyQwtPlot
{
public:
    MyQwtPlot();
    ~MyQwtPlot();
private:
    QString* title;
    QwtPlot* qwtplot;

};

#endif // MYQWTPLOT_H
