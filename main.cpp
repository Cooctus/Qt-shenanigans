#include <QApplication>
#include <header.h>
int main(int argc, char** argv){

    QApplication app (argc, argv);
   // shows all the things we did in header class
    header head;
    head.show();
    //the event loop
    return app.exec();
}
