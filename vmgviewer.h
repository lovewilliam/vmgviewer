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

#ifndef vmgviewer_H
#define vmgviewer_H

#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLayout>

#include <QtGui/QMainWindow>
#include <QtGui/QLabel>
#include <QTextEdit>
#include <QWidget>
#include "vmsg.h"


class vmgviewer : public QWidget//public QMainWindow
{
        Q_OBJECT
public:
        vmgviewer ( QString *filename );
        virtual ~vmgviewer();


private:

        vmsg *msg;
        QVBoxLayout *mylayout;

        QLabel *xbox;
        QLabel *status;
        QLabel *Type;
        QLabel *name;
        QLabel *tel;
        QLabel *time;
        QTextEdit *msgV;



        void praseVmgFile ( QString *fileLocation );
        void layEggs();
        void printAll();
        void updateForm();

private slots:
        void slotOpen();
        void slotSaveas();
        void slotAbout();
        void slotExit();
//     void slotAboutQT();

};

#endif // vmgviewer_H
// kate: indent-mode cstyle; space-indent on; indent-width 8; 
