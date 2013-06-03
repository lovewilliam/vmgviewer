/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2010 lovewilliam <lovewilliam@gmail.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

*/

#include "vmgviewer.h"

#include <QFile>
#include <QTextStream>
#include <QTextCodec>
#include <QDebug>

#include <QVBoxLayout>
#include <QMessageBox>
#include <QFileDialog>


#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QAction>
#include <QIcon>


#include "vmsg.h"

vmgviewer::vmgviewer ( QString *filename )
{
        //TODO : reallocate icon
        setWindowIcon ( QIcon ( "/usr/share/Wtk/icons/Mail-icon32.png" ) );

        setWindowTitle ( tr ( "Nokia VMG File Reader" ) );

        QMenuBar *bar = new QMenuBar ( this );

        QMenu *menu;

        menu = bar->addMenu ( tr ( "&File" ) );
        QAction* openAction = new QAction ( this );
        openAction->setText ( tr ( "&Open..." ) );
        connect ( openAction,SIGNAL ( triggered() ),this,SLOT ( slotOpen() ) );
        menu->addAction ( openAction );

        QAction* saveAction = new QAction ( this );
        saveAction->setText ( tr ( "&Save as txt..." ) );
        connect ( saveAction,SIGNAL ( triggered() ),this,SLOT ( slotSaveas() ) );
        menu->addAction ( saveAction );

        QAction* exitAction = new QAction ( this );
        exitAction->setText ( tr ( "&Exit" ) );
        connect ( exitAction,SIGNAL ( triggered() ),this,SLOT ( slotExit() ) );
        menu->addSeparator();
        menu->addAction ( exitAction );

        menu = bar->addMenu ( tr ( "&Help" ) );
        QAction *about = new QAction ( this );
        about->setText ( tr ( "&About" ) );
        connect ( about,SIGNAL ( triggered() ),this,SLOT ( slotAbout() ) );
        menu->addAction ( about );



        msg = new vmsg();
        //praseVmgFile(QString("test.vmg"));
        if ( !filename->isEmpty() ) {
                praseVmgFile ( filename );
        }
        mylayout  = new QVBoxLayout();
        mylayout->addWidget ( bar );
        layEggs();
        setLayout ( mylayout );
        //printAll();
}

vmgviewer::~vmgviewer()
{
        delete msg;
}

void vmgviewer::printAll()
{
        qDebug() <<"~~~TRACE~~~~~~"<<endl;
        qDebug() <<"BOX      : "<<msg->getBox() <<endl;
        qDebug() <<"STATUS : "<<msg->getStatus() <<endl;
        qDebug() <<"Type      : "<<msg->getType() <<endl;
        qDebug() <<"NOKDT : "<<msg->getNokdt() <<endl;
        qDebug() <<"Name   : "<<msg->getN() <<endl;
        qDebug() <<"Telepho : "<<msg->getTel() <<endl;
        qDebug() <<"Date     : "<<msg->getDate() <<endl;
        qDebug() <<"Msg      : "<<msg->getMsg() <<endl;
        qDebug() <<"~~~END~~~~~~~"<<endl;
}

void vmgviewer::layEggs()
{
//   qDebug()<<"Laying Eggs !"<<endl;


        QHBoxLayout *x1 = new QHBoxLayout();
        QLabel *xbox1 = new QLabel ( tr ( "Box : " ) );
        xbox = new QLabel ( msg->getBox() );
        x1->addWidget ( xbox1 );
        x1->addWidget ( xbox );
        mylayout->addItem ( x1 );

        QHBoxLayout *x2 = new QHBoxLayout();
        QLabel *xstatus = new QLabel ( tr ( "Status : " ) );
        status = new QLabel ( msg->getStatus() );
        x2->addWidget ( xstatus );
        x2->addWidget ( status );
        mylayout->addItem ( x2 );


        QHBoxLayout *x3 = new QHBoxLayout();
        QLabel *xType = new QLabel ( tr ( "Type : " ) );
        Type = new QLabel ( msg->getType() );
        x3->addWidget ( xType );
        x3->addWidget ( Type );
        mylayout->addItem ( x3 );


        QHBoxLayout *b1 = new QHBoxLayout();
        QLabel *n1 = new QLabel ( tr ( "Name : " ) );
        name = new QLabel ( msg->getN() );
        b1->addWidget ( n1 );
        b1->addWidget ( name );
        mylayout->addItem ( b1 );

        QHBoxLayout *b2 = new QHBoxLayout();
        QLabel *t1 = new QLabel ( tr ( "Telephone : " ) );
        tel = new QLabel ( msg->getTel() );
        b2->addWidget ( t1 );
        b2->addWidget ( tel );
        mylayout->addItem ( b2 );

        QHBoxLayout *b3 = new QHBoxLayout();
        QLabel *t2 = new QLabel ( tr ( "Date : " ) );
        time = new QLabel ( msg->getDate() );
        b3->addWidget ( t2 );
        b3->addWidget ( time );
        mylayout->addItem ( b3 );

        msgV = new QTextEdit ( msg->getMsg() );
        mylayout->addWidget ( msgV );

//   qDebug()<<"Laid!"<<endl;
}

void vmgviewer::updateForm()
{
        xbox->setText ( msg->getBox() );
        status->setText ( msg->getStatus() );
        Type->setText ( msg->getType() );
        name->setText ( msg->getN() );
        tel->setText ( msg->getTel() );
        time->setText ( msg->getDate() );
        msgV->setText ( msg->getMsg() );

}


void vmgviewer::praseVmgFile ( QString *fileLocation )
{
	qDebug()<<"File Location:"<<*fileLocation<<endl;
        qDebug() <<"File Open!"<<endl;
        QFile * vmgFile = new QFile ( *fileLocation );
        if ( !vmgFile->open ( QIODevice::ReadOnly | QIODevice::Text ) ) {
                QMessageBox::warning ( this, tr ( "Can not open file" ),
                                       tr ( "Can not open file ! " ),
                                       QMessageBox::Ok );
                qDebug() <<"A error occured while opening file!"<<endl;
        } else {
                qDebug() <<"Opened!"<<endl;
//   vmgFile->open(QIODevice::ReadOnly);
                QTextStream *tstream = new QTextStream ( vmgFile );
                tstream->setCodec ( "UTF-16" );
                QString temp;
                int i =0;
                while ( !tstream->atEnd() ) {
//     qDebug()<<"Phase 1 "<<endl;
                        temp = tstream->readLine();
                        if ( temp.startsWith ( "BEGIN:VMSG" ) ) {
                                while ( ( !tstream->atEnd() ) &&i<5 ) {
                                        //NOTE:tags in VMSG
//      qDebug()<<"Phase 2 +"<<i<<endl;
                                        temp = tstream->readLine();
                                        i++;
                                        if ( temp.startsWith ( "VERSION" ) ) {
                                        } else if ( temp.startsWith ( "X-IRMC-STATUS" ) ) {
                                                temp = temp.right ( temp.length()-1-temp.indexOf ( ':' ) );
                                                msg->setStatus ( temp );
//        qDebug()<<temp<<endl;
//        qDebug()<<temp.length()<<endl;
//        qDebug()<<temp.indexOf(':')<<endl;
                                        } else if ( temp.startsWith ( "X-IRMC-BOX" ) ) {
                                                temp = temp.right ( temp.length()-1-temp.indexOf ( ':' ) );
                                                msg->setBox ( temp );
                                        } else if ( temp.startsWith ( "X-NOK-DT" ) ) {
                                                temp = temp.right ( temp.length()-1-temp.indexOf ( ':' ) );
                                                msg->setNokdt ( temp );
                                        } else if ( temp.startsWith ( "X-MESSAGE-TYPE" ) ) {
                                                temp = temp.right ( temp.length()-1-temp.indexOf ( ':' ) );
                                                msg->setType ( temp );
                                        }
                                }
                                i = 0;
                        } else if ( temp.startsWith ( "BEGIN:VCARD" ) ) {
                                while ( !tstream->atEnd() &&!temp.startsWith ( "END:VCARD" ) ) {
                                        //NOTE:tags in Vcard
//      qDebug()<<"Phase 3 "<<endl;
                                        temp = tstream->readLine();
                                        if ( temp.startsWith ( "VERSION" ) ) {
                                        } else if ( temp.startsWith ( "N" ) ) {
                                                temp = temp.right ( temp.length()-1-temp.indexOf ( ':' ) );
                                                msg->setN ( temp );
                                        } else if ( temp.startsWith ( "TEL" ) ) {
                                                temp = temp.right ( temp.length()-1-temp.indexOf ( ':' ) );
                                                msg->setTel ( temp );
                                        }
                                }
                        } else if ( temp.startsWith ( "BEGIN:VENV" ) ) {
                                bool msgIsSet = false;
                                while ( !tstream->atEnd() &&!temp.startsWith ( "END:VENV" ) ) {
                                        //NOTE:tags in VENV
//      qDebug()<<"Phase 4 "<<endl;
                                        temp = tstream->readLine();
                                        if ( temp.startsWith ( "BEGIN:VBODY" ) ) {
                                                while ( !tstream->atEnd() &&!temp.startsWith ( "END:VBODY" ) ) {
                                                        //NOTE:tags in VBODY
//            qDebug()<<"Phase 5 "<<endl;
                                                        temp = tstream->readLine();
                                                        if ( temp.startsWith ( "VERSION" ) ) {
                                                        } else if ( temp.startsWith ( "Date" ) ) {
                                                                temp = temp.right ( temp.length()-1-temp.indexOf ( ':' ) );
                                                                msg->setDate ( temp );
                                                        } else if ( !temp.startsWith ( "END:VBODY" ) ) {
                                                                if ( msgIsSet )
                                                                        msg->appendMsg ( "\n"+temp );
                                                                else
                                                                        msg->appendMsg ( temp );
                                                        }
                                                }
                                        }
                                }
                        }
                }
                vmgFile->close();
                qDebug() <<"File Closed!"<<endl;
        }
}




void vmgviewer::slotOpen()
{

        QString filename = QFileDialog::getOpenFileName ( this,tr ( "Open File" ),
                           "~/",
                           tr ( "Nokia Text Message File (*.vmg)" ) );

        qDebug() <<filename<<endl;

        if ( !filename.isNull() ) {
                delete msg;
                msg = new vmsg();
                praseVmgFile ( &filename );
//   printAll();
                updateForm();
        }
}

void vmgviewer::slotSaveas()
{
        QString filename = QFileDialog::getSaveFileName ( this, tr ( "Save File" ),
                           "~/unnamed.txt",
                           tr ( "Text File (*.txt)" ) );


        qDebug() <<filename<<endl;
        if ( !filename.isNull() ) {
                bool confirm = true;
                if ( !filename.isEmpty() ) {
                        QFile *qsave = new QFile ( filename );
                        if ( qsave->exists() ) {
                                QMessageBox *qmb = new  QMessageBox ( this );
                                qmb->setText ( "The document has been modified." );
                                qmb->setInformativeText ( "Do you want to save your changes?" );
                                qmb->setStandardButtons ( QMessageBox::Yes | QMessageBox::No );
                                qmb->setDefaultButton ( QMessageBox::No );
                                switch ( qmb->exec() ) {
                                case QMessageBox::Yes:
                                        confirm = true;
                                        break;
                                case QMessageBox::No:
                                        confirm = false;
                                        break;
                                default:
                                        break;
                                }
                        }
                        if ( !qsave->open ( QFile::WriteOnly ) ) {
                                QMessageBox::warning ( this, tr ( "Can not save file" ),
                                                       tr ( "Can not save file ! " ),
                                                       QMessageBox::Ok );
                                qDebug() <<"A error occured while saving file!"<<endl;
                        } else if ( confirm ) {

                                QTextStream out ( qsave );
                                out<<tr ( "Box\t:" ) <<msg->getBox() <<endl;
                                out<<tr ( "Type\t:" ) <<msg->getType() <<endl;
                                out<<tr ( "Name\t:" ) <<msg->getN() <<endl;
                                out<<tr ( "Telephone\t:" ) <<msg->getTel() <<endl;
                                out<<tr ( "Date\t:" ) <<msg->getDate() <<endl<<endl;
                                out<<msg->getMsg() <<endl;
                        }
                }
        }
}

void vmgviewer::slotAbout()
{
        //TODO : show about here
        QString titleText = tr ( "Nokia VMG File Reader" );
        QString aboutText = tr ( "Distributed under GNU General Public License Version 2\n"
                                 "Author : lovewilliam<lovewilliam@gmail.com>\n"
                                 "Thanks : Tracy <my love> :-) " );
        QMessageBox::about ( this,titleText,aboutText );
}

void vmgviewer::slotExit()
{
        exit ( 0 );
}

#include "vmgviewer.moc"
// kate: indent-mode cstyle; space-indent on; indent-width 8; 
