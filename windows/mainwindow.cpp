#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
    auto stackedLayout = new QStackedWidget;
    auto mainWidget = new QWidget;
    auto flashcardWidget = new QWidget;
    auto dataManagerWidget = new QWidget;

    auto setMainLayoutButton = new QPushButton("Set Main Layout");
    auto setFlashcardLayoutButton = new QPushButton("Set Flashcard Layout");
    auto setDataManagerLayoutButton = new QPushButton("Set Data Manager Layout");

    auto mainLayout = new QVBoxLayout;
    auto flashcardLayout = new QVBoxLayout;
    auto dataManagerLayout = new QVBoxLayout;

    auto mainLabel = new QLabel("Main Layout");
    auto flashcardLabel = new QLabel("Flashcard Layout");
    auto dataManagerLabel = new QLabel("Data Manager Layout");

    mainLayout->addWidget(mainLabel);
    mainLayout->addWidget(setFlashcardLayoutButton);
    mainLayout->addWidget(setDataManagerLayoutButton);
    flashcardLayout->addWidget(flashcardLabel);
    flashcardLayout->addWidget(setMainLayoutButton);
    flashcardLayout->addWidget(setDataManagerLayoutButton);
    dataManagerLayout->addWidget(dataManagerLabel);
    dataManagerLayout->addWidget(setMainLayoutButton);
    dataManagerLayout->addWidget(setFlashcardLayoutButton);

    mainWidget->setLayout(mainLayout);
    flashcardWidget->setLayout(flashcardLayout);
    dataManagerWidget->setLayout(dataManagerLayout);

    stackedLayout->addWidget(mainWidget);
    stackedLayout->addWidget(flashcardWidget);
    stackedLayout->addWidget(dataManagerWidget);
    connect(setMainLayoutButton, &QPushButton::clicked, [=]() {
        stackedLayout->setCurrentIndex(0);
    });
    connect(setFlashcardLayoutButton, &QPushButton::clicked, [=]() {
        stackedLayout->setCurrentIndex(1);
    });
    connect(setDataManagerLayoutButton, &QPushButton::clicked, [=]() {
        stackedLayout->setCurrentIndex(2);
    });
    stackedLayout->setCurrentIndex(0);

    setCentralWidget(stackedLayout);
}
MainWindow::~MainWindow() {
    delete centralWidget;
}
