#pragma execution_character_set("utf-8")
#include "messagebox.h"

#include <QtGui>

MessageBox1::MessageBox1(QWidget *parent) : QDialog(parent)
{
    setWindowTitle(tr("Message Box Example"));
    
    label = new QLabel;//���尴�������label
    
    QPushButton *btn1 = new QPushButton("����");//�����������
    QPushButton *btn2 = new QPushButton("��Ϣ");
    QPushButton *btn3 = new QPushButton("Warning");
    QPushButton *btn4 = new QPushButton("Critical");
    QPushButton *btn5 = new QPushButton("About");
    QPushButton *btn6 = new QPushButton("About Qt");
    QPushButton *btn7 = new QPushButton("Custom");
    
    QGridLayout *grid = new QGridLayout;//�Ը����������в���(��Grid�ķ�ʽ)
    grid->addWidget(btn1,0,0);
    grid->addWidget(btn2,0,1);
    grid->addWidget(btn3,1,0);
    grid->addWidget(btn4,1,1);
    grid->addWidget(btn5,2,0);
    grid->addWidget(btn6,2,1);
    grid->addWidget(btn7,3,0);
    
    QVBoxLayout *mainLayout = new QVBoxLayout;//��ֱ�ķ�ʽ���ò���
    mainLayout->setMargin(10);//���ñ�Ե��϶
    mainLayout->setSpacing(20);
    mainLayout->addWidget(label);//���Ӱ��������label��addWidget��
    mainLayout->addLayout(grid);//���Ӳ���
    setLayout(mainLayout);//������������������Ե���label��������
    
    connect(btn1,SIGNAL(clicked()),this,SLOT(slotQuestion()));
    connect(btn2,SIGNAL(clicked()),this,SLOT(slotInformation()));
    connect(btn3,SIGNAL(clicked()),this,SLOT(slotWarning()));
    connect(btn4,SIGNAL(clicked()),this,SLOT(slotCritical()));
    connect(btn5,SIGNAL(clicked()),this,SLOT(slotAbout()));
    connect(btn6,SIGNAL(clicked()),this,SLOT(slotAboutQt()));
    connect(btn7,SIGNAL(clicked()),this,SLOT(slotCustom()));
}
//���¸�������Ϊ�����۵Ķ��壻
//
void MessageBox1::slotQuestion()
{
    switch(QMessageBox::question(this,"Question",tr("It's end of document,search from begin?"),
    		QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok))
    {
    case QMessageBox::Ok:
    	label->setText(" Question button / Ok ");
    	break;
    case QMessageBox::Cancel:
    	label->setText(" Question button / Cancel ");
    	break;
    default:
    	break;
    }
    return;
}

void MessageBox1::slotInformation()
{
    QMessageBox::information(this,"Information",tr("anything you want tell user"));
    return;
}

void MessageBox1::slotWarning()
{
    switch(QMessageBox::warning(this,"Warning",tr("Save changes to document?"),
    		QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel,QMessageBox::Save))
    {
    case QMessageBox::Save:
    	label->setText(" Warning button / Save ");
    	break;
    case QMessageBox::Discard:
    	label->setText(" Warning button / Discard ");
    	break;
    case QMessageBox::Cancel:
    	label->setText(" Warning button / Cancel ");
    	break;
    default:
    	break;
    }
    return;
    
}

void MessageBox1::slotCritical()
{
    QMessageBox::critical(this,"Critical",tr("tell user a critical error"));
    label->setText(" Critical MessageBox ");
    return;
}

void MessageBox1::slotAbout()
{
    QMessageBox::about(this,"About",tr("Message box example!"));
    label->setText(" About MessageBox ");
    return;
}

void MessageBox1::slotAboutQt()
{
    QMessageBox::aboutQt(this,"About Qt");
    label->setText(" About Qt MessageBox ");
    return;
}

void MessageBox1::slotCustom()
{
    QMessageBox customMsgBox;
    customMsgBox.setWindowTitle("Custom message box");
    QPushButton *lockButton = customMsgBox.addButton(tr("Lock"),QMessageBox::ActionRole);
    QPushButton *unlockButton = customMsgBox.addButton(tr("Unlock"),QMessageBox::ActionRole);
    QPushButton *cancelButton = customMsgBox.addButton(QMessageBox::Cancel);
    customMsgBox.setIconPixmap(QPixmap(":/images/linuxredhat.png"));
    customMsgBox.setText(tr("This is a custom message box"));
    customMsgBox.exec();
    //û�ж��岼���ѵ��ǰ���Ĭ�Ϸ�ʽ�����µ��ϣ�������
    if(customMsgBox.clickedButton() == lockButton)
    	label->setText(" Custom MessageBox / Lock ");
    if(customMsgBox.clickedButton() == unlockButton)
    	label->setText(" Custom MessageBox / Unlock ");
    if(customMsgBox.clickedButton() == cancelButton)
    	label->setText(" Custom MessageBox / Cancel ");

    return;
}