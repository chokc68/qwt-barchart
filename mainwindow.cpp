#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>
#include <QToolButton>
#include <QComboBox>

#include "BarChart.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialize()
{
    BarChart* chart = new BarChart();
    setCentralWidget( chart );

    QToolBar* toolBar = new QToolBar();

    QComboBox* typeBox = new QComboBox( toolBar );
    typeBox->addItem( "Grouped" );
    typeBox->addItem( "Stacked" );
    typeBox->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Fixed );

    QComboBox* orientationBox = new QComboBox( toolBar );
    orientationBox->addItem( "Vertical" );
    orientationBox->addItem( "Horizontal" );
    orientationBox->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Fixed );

    QToolButton* btnExport = new QToolButton( toolBar );
    btnExport->setText( "Export" );
    btnExport->setToolButtonStyle( Qt::ToolButtonTextUnderIcon );
    connect( btnExport, SIGNAL(clicked()), chart, SLOT(exportChart()) );

    toolBar->addWidget( typeBox );
    toolBar->addWidget( orientationBox );
    toolBar->addWidget( btnExport );
    addToolBar( toolBar );

    chart->setMode( typeBox->currentIndex() );
    connect( typeBox, SIGNAL(currentIndexChanged(int)),
        chart, SLOT(setMode(int)) );

    chart->setOrientation( orientationBox->currentIndex() );
    connect( orientationBox, SIGNAL(currentIndexChanged(int)),
        chart, SLOT(setOrientation(int)) );
}
