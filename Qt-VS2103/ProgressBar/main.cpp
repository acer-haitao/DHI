#include "progress.h"
#include <QApplication>


int main( int argc, char **argv )
{
   	
    QApplication a( argc, argv );
    QTranslator translator(0);//translate():�û��ɼ��ı��ػ��ַ���
    translator.load("progress_zh",".");
    a.installTranslator(&translator);    
    
    Progress *progress = new Progress();
    progress->show();
    return a.exec();
}
