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

#include "vbody.h"

#include <QTextCodec>

#include <QDebug>

vbody::vbody()
{
//   _vdate = "abc";
//   _vmsg = "cde";
//   qDebug()<<_vdate<<endl;
//   qDebug()<<_vmsg<<endl;
// _vdate = new QString();
        //_vmsg = new QString();
}

vbody::~vbody()
{
}


void vbody::setDate ( QString date )
{
//  qDebug()<<date<<endl;
        _vdate = date;
}

void vbody::setMsg ( QString msg )
{
//    qDebug()<<msg<<endl;
        _vmsg = msg;
}

void vbody::appendMsg ( QString msg )
{
//    qDebug()<<msg<<endl;
        _vmsg.append ( msg );
}

QString vbody::getDate()
{
        return _vdate;
}

QString vbody::getMsg()
{
        return _vmsg;
}

QString * vbody::toGB()
{
        QTextCodec *codec = QTextCodec::codecForName ( "GB18030-0" );
        QByteArray encodedString = codec->fromUnicode ( _vmsg );
        return &QString ( encodedString );
}

// kate: indent-mode cstyle; space-indent on; indent-width 8; 
