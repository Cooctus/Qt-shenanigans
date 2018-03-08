#include "header.h"
#include <QPushButton>
#include <QApplication>
#include <string>
using namespace mu;
/*

  The only one that actually does anything is the calculator button the others are just me fucking around

*/
header::header(QWidget *parent) : QWidget(parent)
{

    setFixedSize(1360,768);
    //makes a new button the button is defined in the header file sets its text to calculate and its parent to *parent
    button = new QPushButton("Calculate",this);
            //you can subsititue this for parent and it wont make a difference
//sets the shape and size of the button i used qrect cause i like my buttons to be shaped like *lenny face*
button->setGeometry(QRect(500,200,100,50));

//this is what Im using to take the input
edit = new QLineEdit("",this);
// setting the geometry againt this part of guis are gonna be the bane of my existance
edit->setGeometry(400,500,100,100);

//bar is me fucking around
bar = new QProgressBar(this);

bar->setGeometry(200,100,200,100);

bar->setValue(0);

bar->setRange(0,100);
// as is nyan
nyan = new QRadioButton("hello",this);


nyan->setGeometry(1000,300,20,20);
// as is slid
QSlider * slider = new QSlider(this);

slider->setValue(0);

slider->setRange(0,100);


slider->setGeometry(100,300,50,50);
/*
 this is where shit gets interesting
you give it a QObject if any kind and with signal you can use any method that responds to anything happening with that object
you can also make your own signals that would be definied in header.h
translated to english this says
when button  is clicked  do print()
 the second one translates
 to when the counter is reached in parent do quit
 for example
 lets declare an integer x with a value of 5; and whenever I click a button it will add 1 to x
 i can use a Slot in a connect() to do this we shall use print() as out example since its there
 i can use the syntax if(x == 10){emit counterReached()} which will execute the second connect statement
which will exit the program
*/
connect(button  , SIGNAL (clicked()),this, SLOT (print()));

connect(this , SIGNAL(counterReached()),QApplication::instance(), SLOT (quit()));


}
void header::print(){
//yes im using a parser lib GOT A PROBLEM
    Parser p;
//its able to evaluate strings which is kinda why im using this
    p.SetExpr(edit->text().toStdString());
try{
    //for some fucked up reason i cant set the text to an std::string so im using a const char * instead
    const char * a = std::to_string(p.Eval()).c_str();
    edit->setText(a);
}
    //catch any parser errors it might have
    catch(ParserError e){

    edit->setText("not valid please try again");
}


}

