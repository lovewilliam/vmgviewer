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

#include "vmsg.h"

vmsg::vmsg()
                :vcard(),venv()
{

}

vmsg::~vmsg()
{
}

void vmsg::setBox ( QString box )
{
        X_IRMC_BOX = box;
}

void vmsg::setStatus ( QString status )
{
        X_IRMC_STATUS = status;
}

void vmsg::setNokdt ( QString dt )
{
        X_NOK_DT = dt;
}

void vmsg::setType ( QString type )
{
        X_MESSAGE_TYPE = type;
}

QString vmsg::getBox()
{
        return X_IRMC_BOX;
}

QString vmsg::getStatus()
{
        return X_IRMC_STATUS;
}

QString vmsg::getNokdt()
{
        return X_NOK_DT;
}

QString vmsg::getType()
{
        return X_MESSAGE_TYPE;
}
// kate: indent-mode cstyle; space-indent on; indent-width 8; 
