#pragma once
#include <QTimer>
#include <QElapsedTimer>
#include "qwt_plot.h"

class QwtPlotMultiBarChart;

class BarChart : public QwtPlot
{
    Q_OBJECT

  public:
    BarChart( QWidget* = NULL );
    virtual ~BarChart();

  public slots:
    void setMode( int );
    void setOrientation( int );
    void exportChart();
    void generate();

  private:
    void populate();

    QwtPlotMultiBarChart* m_barChartItem;

    QVector< QVector< double > > m_series;
    QTimer m_timer;
//    QElapsedTimer m_elapsed;
    int numBars;
};
