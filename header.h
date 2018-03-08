#ifndef HEADER_H
#define HEADER_H
#include <QRadioButton>
#include <iostream>
#include <QWidget>
#include <QPushButton>
#include <QProgressBar>
#include <QLineEdit>
#include <QSlider>
#include <muParser.h>
//have all my include statements in here cause it looks pretty
// declare a class header that inherits from QWidget
class header : public QWidget
{
    //this is a macro all it does is tell our compiler this is a gui
    Q_OBJECT
public:
    //giving out constructor a pointer by the name of parent which is set to null
  // until papa header.cpp changes
    header(QWidget *parent = nullptr);

private:
    //declaring all the variables I used
QPushButton *button;
QProgressBar * bar;
QLineEdit * edit;
QRadioButton * nyan;

//this is where you declare your signals and slots
signals:
 void counterReached();
public slots:

 void print();

};

#endif // HEADER_H
