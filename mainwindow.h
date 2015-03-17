#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDir>

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

#include <QFileSystemModel>
#include <QTreeView>

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

private:
    Ui::MainWindow *ui;
    std::vector<double> v_left_hip, v_right_hip, v_left_knee, v_right_knee;
    MyQwtPlot *myPlot_left_hip, *myPlot_right_hip, *myPlot_left_knee, *myPlot_right_knee;
    QString fileName, file_dir;
    int out_filename_num = 0;
    MyQwtPlot *test;
    void process_line(QString line);
    QFileSystemModel model;
    QTreeView tree;

};

#endif // MAINWINDOW_H
