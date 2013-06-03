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

#ifndef VCARD_H
#define VCARD_H

#include <QString>

class vcard
{

public:
        vcard();
        ~vcard();
        void setN ( QString n );
        void setTel ( QString tel );
        QString getN();
        QString getTel();

        static const float	 VERSION=3.0;								//Version default is 3.0

        //TODO fillup vcard
private:
        QString _n;										//Who is the tel number belonged to
        QString _tel;										//Telephone Number
};

#endif // VCARD_H
// kate: indent-mode cstyle; space-indent on; indent-width 8; 
