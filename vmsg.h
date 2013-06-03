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

#ifndef VMSG_H
#define VMSG_H

#include "vcard.h"
#include "venv.h"

class vmsg : public vcard , public venv
{
public:
        ~vmsg();
        vmsg();
        void setBox ( QString box );
        void setStatus ( QString status );
        void setNokdt ( QString dt );
        void setType ( QString type );

        QString getBox();
        QString getStatus();
        QString getNokdt();
        QString getType();

private:
        static const float	 VERSION = 1.1;							//Version default is 1.1
        QString X_IRMC_STATUS;								//READ or UNREAD
        QString X_IRMC_BOX;									//Where the msg is located |INBOX|OUTBOX
        QString X_NOK_DT;									//T means Date ; Z means time. Example : 20100103T031124Z
        QString X_MESSAGE_TYPE;								//DELIVER|SUBMIT




};

#endif // VMSG_H
// kate: indent-mode cstyle; space-indent on; indent-width 8; 
