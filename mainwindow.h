#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDir>
#include <QFileSystemModel>
#include <QTreeView>
#include <QDebug>
#include "MyQwtplot.h"


#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_symbol.h>
#include <qwt_legend.h>

#include <numeric>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void normalization(std::vector<double> *data, const int total_size = 10000);


private slots:

    void on_radioButton_max_clicked();
    void on_radioButton_min_clicked();
    void on_pushButton_generate_clicked();

    void on_pushButton_open_dir_clicked();

    void on_treeView_clicked(const QModelIndex &index);

    void on_pushButton_calibration_clicked();

    void on_pushButton_calibration_zero_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<double> v_left_hip, v_right_hip, v_left_knee, v_right_knee, v_back;
    MyQwtPlot *myPlot_left_hip, *myPlot_right_hip, *myPlot_left_knee, *myPlot_right_knee, *myPlot_back;
    QString fileName, file_dir;
    int out_filename_num = 0;

    QwtPlotCurve *curve_left_hip, *curve_right_hip, *curve_left_knee, *curve_right_knee, *curve_back;

    void process_line(QString line);
    QFileSystemModel model;
    QTreeView tree;
    double calibration_left_hip, calibration_right_hip, calibration_left_knee, calibration_right_knee, calibration_back;

};

#endif // MAINWINDOW_H
