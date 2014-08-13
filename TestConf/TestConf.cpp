// TestConf.cpp : Defines the entry point for the console application.
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
  char szVersion[100];
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

  // (1) Retrieve the machine ID
  size_t nLen = 100;
  memset(szVersion,0x00, nLen);
  nRet = SFLUC_MACHINEID( szVersion, &nLen);
  if( nRet >= NDK_SUCCESS)
  {
    std::cout << "Machine Id:" << szVersion << std::endl;

    // (2) Retrieve the effective License key
    nLen = 100;
    memset(szVersion,0x00, nLen);
    nRet = SFLUC_LICENSE_KEY(szVersion, &nLen);
    if( nRet >= NDK_SUCCESS)
    {
      std::cout << "License Key:" << szVersion << std::endl;

      // (3) Retrieve the activation code
      nLen = 100;
      memset(szVersion,0x00, nLen);
      nRet = SFLUC_ACTIVATION_CODE(szVersion, &nLen);
      if( nRet >= NDK_SUCCESS)
      {
        std::cout << "Activation Code:" << szVersion << std::endl;

      }
      else
      {
        std::cout << "Error in retrieving the Activation code: <Error>" << std::endl;
      }

    }
    else
    {
      std::cout << "Error in retrieving the License key: <Error>" << std::endl;
    }
  }
  else
  {
    std::cout << "Error in retrieving the machine Id: <Error>" << std::endl;
  }


	return 0;
}

