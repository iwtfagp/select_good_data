#ifndef MYQWTPLOT_H
#define MYQWTPLOT_H

#include <qwt_plot_curve.h>
#include <qwt_plot_picker.h>
#include <qwt_picker_machine.h>
#include <qwt_plot_marker.h>
#include <qwt_plot_shapeitem.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_canvas.h>
#include <qwt_legend.h>
#include <qwt_plot_renderer.h>
#include "qwt_plot_rescaler.h"

#include <QObject>
#include <QString>

class MyQwtPlot : public QObject
{
    Q_OBJECT
public:

    MyQwtPlot(const QString & title, QwtPlot* qwtplot);
    ~MyQwtPlot();
    void setSamples(int time_tick, const double* data, const int size);
    void setMaxline(bool select);
    int getMax();
    int getMin();
    QwtPlotCurve *qwt_curve;



public slots:
    void selectedFun(const QPointF& pos);
    void DrawShadowline(double max, double min);

signals:
     void valueChanged(double, double);

private:
    QwtPlot *qwt_myQwtplot;
    bool b_max_selected;
    int i_marker_min, i_marker_max;
    QwtPlotMarker *qwt_marker_max, *qwt_marker_min;

    QwtPlotShapeItem *qwt_item;
    int background_rect_upper_bound, background_rect_lower_bound;



};

#endif // MYQWTPLOT_H
