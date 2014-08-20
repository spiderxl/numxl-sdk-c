// LicenseKey.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SFLogger.h"
#include "SFMacros.h"
#include "SFLUC.h"
#include "SFDBM.h"
#include "SFSDK.h"


int _tmain(int argc, _TCHAR* argv[])
{
// Let's get the library version number
  int nRet=-1;

  std::cout  << "(c) 2009-2014 Spider Financial Corp." << std::endl;
  std::cout  << "All rights reserved." << std::endl;
  std::cout  <<  std::endl;
  std::cout  <<  "Phone:    (312) 324-0366" << std::endl;
  std::cout  <<  "E-Mail:   support@numxl.com" << std::endl;
  std::cout  <<  "Website:  www.numxl.com" << std::endl;
  std::cout  <<  std::endl;
  std::cout << "*******************************************************" << std::endl;

  std::string szAppName("TestApp");

  nRet = SFLUC_Init(szAppName.c_str(), NULL, NULL);
  if( nRet >= NDK_SUCCESS)
  {
    size_t nLen =100;
    char szBuffer[100];
    memset(szBuffer, 0x00, 100*sizeof(char));
    
    std::string szLicense;
    nRet = SFLUC_LICENSE_KEY(&szBuffer[0],        ///< [out]  The buffer that will receive the License key
                                    &nLen         ///< [inout] maximum number of characters to copy to the buffer.
                                    );
    if( nRet >= NDK_SUCCESS)
    {
      szLicense = &szBuffer[0];
      std::cout << "License Key is: " << szLicense.c_str() << std::endl;
    }
    else
    {
      std::cout << "Error: SFLUC_LICENSE_KEY API failed" << std::endl;
    }

    nRet = SFLUC_Shutdown();
  }
  else
  {
    std::cout << "Error:: NDK_INIT failed" << std::endl;
  }
	return 0;
}

