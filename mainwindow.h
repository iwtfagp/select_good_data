#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
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



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void process_line(QString line);

private slots:
    void on_pushButton_read_file_clicked();
    void function(QPoint actualMousePosition);
    void selected(const QPointF& pos);


private:
    Ui::MainWindow *ui;
    std::vector<double> v_left_hip, v_right_hip, v_left_knee, v_right_knee;
    QwtPlotCurve *curve1 = new QwtPlotCurve("Curve 1");
    QwtPlotCurve *curve2 = new QwtPlotCurve("Curve 2");
    QwtPlotCurve *curve3 = new QwtPlotCurve("Curve 3");
    QwtPlotCurve *curve4 = new QwtPlotCurve("Curve 4");
    QwtPlotMarker *d_marker1, *qwt_marker_max, *qwt_marker_min;
};

#endif // MAINWINDOW_H
