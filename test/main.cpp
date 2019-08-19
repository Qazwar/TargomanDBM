/******************************************************************************
 * TargomanDBM: Authentication, Authorization, Accounting framework           *
 *                                                                            *
 * Copyright 2014-2019 by Targoman Intelligent Processing <http://tip.co.ir>  *
 *                                                                            *
 * TargomanDBM is free software: you can redistribute it and/or modify        *
 * it under the terms of the GNU Lesser General Public License as published   *
 * by the Free Software Foundation, either version 3 of the License, or       *
 * (at your option) any later version.                                        *
 *                                                                            *
 * TargomanDBM is distributed in the hope that it will be useful,             *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU Lesser General Public License for more details.                        *
 * You should have received a copy of the GNU Lesser General Public License   *
 * along with Targoman. If not, see <http://www.gnu.org/licenses/>.           *
 *                                                                            *
 ******************************************************************************/
/**
 * @author S. Mohammad M. Ziabary <ziabary@targoman.com>
 */


#include <iostream>
#include <unistd.h>
#include "libTargomanDBM/clsDAC.h"
#include "libTargomanCommon/CmdIO.h"


using namespace Targoman::DBManager;
int main(int argc, char *argv[])
{
    Q_UNUSED(argc); Q_UNUSED(argv);
    try{
        clsDAC::addDBEngine (enuDBEngines::MySQL);
        clsDAC::setConnectionString ("HOST=172.17.0.1;PORT=3316;USER=test;PASSWORD=1;SCHEMA=AAA");

        clsDAC DAC;
        DAC.execQuery("", "SELECT * FROM tblRoles");

    }catch(std::exception &e){
        TargomanError(e.what());
        return 1;
    }

    return 0;
}

