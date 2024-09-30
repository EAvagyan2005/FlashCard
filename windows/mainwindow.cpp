#include "mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    generateMainLayout();
}
void MainWindow::generateMainLayout(){
    QLayout *currLayout = centralWidget->layout();
    if (currLayout) delete currLayout;
    mainLayout = new QVBoxLayout(this);
    QPushButton* openFlashButton = new QPushButton("Open flashcard");
    QPushButton* openDataManagerButton = new QPushButton("Open datamanager");
    mainLayout->addWidget(openFlashButton);
    connect(openFlashButton, &QPushButton::clicked, this, &MainWindow::generateFlashcardLayout);
    mainLayout->addWidget(openDataManagerButton);
    connect(openDataManagerButton, &QPushButton::clicked, this, &MainWindow::generateDataManagerLayout);
    centralWidget->setLayout(mainLayout);

}

void MainWindow::generateDataManagerLayout(){
    QLayout *currLayout = centralWidget->layout();
    if (currLayout) delete currLayout;
    dataManagerLayout = new QVBoxLayout(this);

    QPushButton* openFlashButton = new QPushButton("Open flashcard");
    QPushButton* openMainButton = new QPushButton("Open main");
    dataManagerLayout->addWidget(openFlashButton);
    connect(openFlashButton, &QPushButton::clicked, this, &MainWindow::generateFlashcardLayout);
    dataManagerLayout->addWidget(openMainButton);
    connect(openMainButton, &QPushButton::clicked, this, &MainWindow::generateMainLayout);
    centralWidget->setLayout(dataManagerLayout);
}

void MainWindow::generateFlashcardLayout(){
    QLayout *currLayout = centralWidget->layout();
    if (currLayout) delete currLayout;
    flashcardLayout = new QVBoxLayout(this);

    QPushButton* openDataManagerButton = new QPushButton("Open datamanager");
    QPushButton* openMainButton = new QPushButton("Open main");
    flashcardLayout->addWidget(openDataManagerButton);
    connect(openDataManagerButton, &QPushButton::clicked, this, &MainWindow::generateDataManagerLayout);
    flashcardLayout->addWidget(openMainButton);
    connect(openMainButton, &QPushButton::clicked, this, &MainWindow::generateMainLayout);
    centralWidget->setLayout(dataManagerLayout);
}
