#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

#include <QDebug>

#include <qwt_plot_curve.h>
#include <qwt_plot_picker.h>
#include <qwt_picker_machine.h>
#include <qwt_plot_marker.h>
#include <qwt_plot_shapeitem.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_canvas.h>
#include <qwt_legend.h>
#include <qwt_plot_renderer.h>

#include "MyQwtplot.h"

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
//    void selected(const QPointF& pos);

    void on_radioButton_max_clicked();
    void on_radioButton_min_clicked();

    void on_pushButton_generate_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<double> v_left_hip, v_right_hip, v_left_knee, v_right_knee;
    MyQwtPlot *myPlot_left_hip, *myPlot_right_hip, *myPlot_left_knee, *myPlot_right_knee;
};

#endif // MAINWINDOW_H
